#include "mainwindow.h"
#include "Database.h"
#include "CollegeTour.h"
#include "Maintenance.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->MainPageWidget->setCurrentIndex(0);
    populateMenu();
}
/*! Default Destructor
 * \brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/*!
 * \brief MainWindow::on_CustomTripButton_clicked
 */
void MainWindow::on_CustomTripButton_clicked()
{
    ui->MainPageWidget->setCurrentIndex(1);
}
/*!
 * \brief MainWindow::initialCollegeSelected
 */
void MainWindow::initialCollegeSelected()
{
    // Get the QPushButton object that was clicked
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());

    // get all college information associated with the button that was clicked
    // (Each button's objectName is assigned the collegeID of college it represents!)
    College collegeClicked = Database::getInstance()->getCollegeByID(clickedButton->objectName().toInt());

    // Create and show the CollegeTour
    CollegeTour* collegeTour = new CollegeTour(collegeClicked, false);

    collegeTour->show();
    collegeTour->getTripLength();
}

/*!
 * \brief MainWindow::populateMenu
 * Fills menu up with database colleges to allow user to choose
 * which college they wish to start their custom trip at.
 */
void MainWindow::populateMenu()
{
    QVector<College> colleges = Database::getInstance()->getColleges();

    qDebug() << "Colleges size: " << colleges.size();

    int row = 0;
    int col = 0;

    //For each college in database, construct a CollegeButton (subclassed QPushButton) and associate it with said college
    for (int index=0; index < colleges.size(); index++)
    {
        // Click event is handled within the CollegeButton class (CollegeButton.cpp/.h)
        QPushButton* collegeName = new QPushButton(colleges[index].name + "\nDistance to Saddleback: " + QString::number(colleges[index].distanceToSaddleback) + " miles", this);


        collegeName->setObjectName(QString::number(colleges[index].id));

        connect(collegeName, SIGNAL(clicked()), this, SLOT(initialCollegeSelected()));

        if(col == 2)
        {
            row++;
            col=0;
            ui->gridLayout->addWidget(collegeName,row,col);
        }
        else
        {
            ui->gridLayout->addWidget(collegeName,row,col);
        }
        col++;
    }
}

void MainWindow::on_ShortestTripButton_clicked()
{
    College uci = Database::getInstance()->getCollegeByID(6);
    CollegeTour* collegeView = new CollegeTour(uci, false);

    collegeView->show();
    collegeView->getTripLength();
}
void MainWindow::on_SaddlebackTripButton_clicked()
{
    College saddleback = Database::getInstance()->getCollegeByID(11);
    CollegeTour* collegeView = new CollegeTour(saddleback, false);

    collegeView->show();
    collegeView->getTripLength();
}

/*!
 * \brief MainWindow::on_ASU_trip_button_clicked
 */
void MainWindow::on_ASUTripButton_clicked()
{
    CollegeTour* collegeTour = new CollegeTour(Database::getInstance()->getCollegeByID(1), true);

    collegeTour->show();
}
/*!
 * \brief MainWindow::on_admin_push_button_clicked
 */
void MainWindow::on_AdminPageButton_clicked()
{
    ui->MainPageWidget->setCurrentIndex(2);
}
/*!
 * \brief MainWindow::on_login_button_clicked
 * check login credentials for validity
 * and if not will prompt user
 */
void MainWindow::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_UserName->text();
    QString password = ui->lineEdit_Password->text();
    if(username == "admin" && password == "admin")
    {
        QMessageBox::information(this, "Login", "Username and password is correct");
        ui->MainPageWidget->setCurrentIndex(3);
        populateAdminMenu();
        ui->lineEdit_UserName->clear();
        ui->lineEdit_Password->clear();
    }
    else
    {
        QMessageBox::warning(this, "Login", "Username and password is not correct");
        ui->lineEdit_UserName->clear();
        ui->lineEdit_Password->clear();
    }
}
/*!
 * \brief MainWindow::populateAdminMenu
 * Populates admin menu with souvenir lists from which
 * the user can select an item to change or delete
 */
void MainWindow::populateAdminMenu()
{
    ui->DisplaySouvenirWidget->clear();
    QVector<College> colleges = Database::getInstance()->getColleges();
    for (int index=0; index < colleges.size(); index++)
    {
        QVector<souvenirItem> souvenirItems = colleges[index].souvenirItems;

        QListWidgetItem* collegeLabel = new QListWidgetItem("Souvenir items for college: " + colleges[index].name);
        collegeLabel->setBackground(Qt::darkGreen);
        collegeLabel->setFlags(collegeLabel->flags() & ~Qt::ItemIsSelectable);
        ui->DisplaySouvenirWidget->addItem(collegeLabel);
        for (int i=0; i < souvenirItems.size(); i++)
        {
            QListWidgetItem* newItem = new QListWidgetItem(" °  " + souvenirItems[i].name + " - " + QString::number(souvenirItems[i].price, 'f', 2));
            newItem->setData(Qt::UserRole, souvenirItems[i].id);
            newItem->setData(128, colleges[index].id);
            ui->DisplaySouvenirWidget->addItem(newItem);
        }
    }
}
/*!
 * \brief MainWindow::on_add_souvenir_button_clicked
 */
void MainWindow::on_AddSouvenirButton_clicked()
{
    Maintenance* addSouvenir = new Maintenance(false, this, souvenirItem(), College());
    addSouvenir->show();
}
/*!
 * \brief MainWindow::on_DisplaySouvenirWidget_widget_clicked
 * \param index
 */
/*!
 * \brief MainWindow::on_souvenir_list_widget_clicked
 * \param index
 */
void MainWindow::on_DisplaySouvenirWidget_clicked(const QModelIndex &index)
{
    selectedRow = index.row();
}

/*!
 * \brief MainWindow::on_DisplaySouvenirWidget_doubleClicked
 * \param index - An integer argument
 */
void MainWindow::on_DisplaySouvenirWidget_doubleClicked(const QModelIndex &index)
{
    int souvenirItemID = ui->DisplaySouvenirWidget->item(index.row())->data(Qt::UserRole).toInt();
    souvenirItem itemClicked = Database::getInstance()->getSouvenirByID(souvenirItemID);

    QInputDialog inputOperation;
    QStringList operations;
    operations << "Modify Item" << "Delete Item";
    inputOperation.setComboBoxItems(operations);

    inputOperation.setWindowTitle("Select an operation to perform on the item: " + itemClicked.name);
    if (inputOperation.exec())
    {
        if (inputOperation.textValue() == "Delete Item")
        {
            Database::getInstance()->deleteSouvenirItem(itemClicked);
            populateAdminMenu();

        } else if (inputOperation.textValue() == "Modify Item")
        {
            int collegeID = ui->DisplaySouvenirWidget->item(index.row())->data(128).toInt();

            College forCollege = Database::getInstance()->getCollegeByID(collegeID);

            Maintenance* newOperation = new Maintenance(true, this, itemClicked, forCollege);
            newOperation->show();
        }
    }
}
/*!
 * \brief MainWindow::on_upload_college_button_clicked
 * Reads from a file to add a college into the database
 */
void MainWindow::on_UploadCollegeButton_clicked()
{

    Database::getInstance()->addCollegesTable();
    Database::getInstance()->addDistancesTable();
    Database::getInstance()->addSouvenirsTable();
    populateMenu();
}
/*!
 * \brief MainWindow::on_BackTMainButton_clicked
 */
void MainWindow::on_BackTMainButton_clicked()
{
    ui->MainPageWidget->setCurrentIndex(0);
}

/*!
 * \brief MainWindow::on_admin_push_button_3_clicked
 */
void MainWindow::on_AdminPageButton_3_clicked()
{
    ui->MainPageWidget->setCurrentIndex(2);
}
/*!
 * \brief MainWindow::on_admin_push_button_3_clicked
 */
void MainWindow::on_AdminPageButton_2_clicked()
{
    ui->MainPageWidget->setCurrentIndex(2);
}
/*!
 * \brief MainWindow::on_BackTMainButton_clicked
 */
void MainWindow::on_BackTMainButton_3_clicked()
{
    ui->MainPageWidget->setCurrentIndex(0);
}
/*!
 * \brief MainWindow::on_BackTMainButton_clicked
 */
void MainWindow::on_BackTMainButton_2_clicked()
{
    ui->MainPageWidget->setCurrentIndex(0);
}


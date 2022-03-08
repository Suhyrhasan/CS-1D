#include "Maintenance.h"
#include "ui_Maintenance.h"
/*! Constructor
 * \brief maintenance::maintenance
 * \param modifying - bool if modifiying item
 * \param mainWindow - pointer to mainwindow for updates
 * \param souvenir - A struct argument
 * \param college - a struct argument
 * \param parent
 */
Maintenance::Maintenance(bool modifying, MainWindow *mainWindow, souvenirItem souvenir, College college, QWidget *parent):
    QWidget(parent),
    ui(new Ui::Maintenance)
{
    ui->setupUi(this);
    ui->MaintenanceWidget->setCurrentIndex(1);
    this->mainWindow = mainWindow;
    if(modifying)
    {
        ui->EditPriceSpinBox->setDecimals(2);
        ui->EditPriceSpinBox->setSingleStep(0.01);
        ui->EditCollegeName->setText(college.name);
        ui->EditSouvenirNameLine->setText(souvenir.name);
        ui->EditPriceSpinBox->setValue(souvenir.price);
        this->itemToModify= souvenir;
    }
    else
    {
        // We are adding a new item instead of modifying an existing one
        ui->MaintenanceWidget->setCurrentIndex(0);
        QVector<College> colleges = Database::getInstance()->getColleges();
        for (int index=0; index < colleges.size(); index++)
        {
            ui->AddCollegeNameComboBox->addItem(colleges[index].name, colleges[index].id);
        }
    }
}
/*! Default Destructor
 * \brief maintenance::~maintenance
 */
Maintenance::~Maintenance()
{
    delete ui;
}
/*!
 * \brief maintenance::on_add_button_clicked
 * Processes new item addition
 */
void Maintenance::on_AddSouvenirButton_clicked()
{
    this->newSouvenir.name = ui->AddSouvenirNameLine->text();
    this->newSouvenir.price = ui->AddPriceSpinBox->value();

    if (newSouvenir.name.isEmpty())
    {
        QMessageBox errorMsg;
        errorMsg.setText("Item name cannot be empty!");
        errorMsg.exec();
    } else
    {
        QMessageBox::StandardButton confirm;
        confirm = QMessageBox::question(this, "Confirm Changes", "Are you sure you want to add this new Traditional Souvenir?",
                                        QMessageBox::Yes|QMessageBox::No);
        if (confirm == QMessageBox::Yes)
        {
            College collegeToAddItemTo = Database::getInstance()->getCollegeByID(selectedCollegeID);
            qDebug() << "New souvenir item: " << newSouvenir.name;
            qDebug() << "Adding to college: " << collegeToAddItemTo.name;
            Database::getInstance()->addSouvenirItem(newSouvenir, collegeToAddItemTo);
            mainWindow->populateAdminMenu();
        }
        this->close();
    }
}
/*!
 * \brief maintenance::on_college_combo_box_currentIndexChanged
 * \param index - An integer argument
 */
void Maintenance::on_AddCollegeNameComboBox_currentIndexChanged(int index)
{
    this->selectedCollegeID = ui->AddCollegeNameComboBox->itemData(index, Qt::UserRole).toInt();
}
/*!
 * \brief maintenance::on_modify_name_edit_textChanged
 * \param newName - A QString argument
 */
void Maintenance::on_EditSouvenirNameLine_textChanged(const QString &newSouvenirName)
{
    this->itemToModify.name = newSouvenirName;
}
/*!
 * \brief maintenance::on_modify_price_valueChanged
 * \param newPrice - A double argument
 */
void Maintenance::on_EditPriceSpinBox_valueChanged(double newCost)
{
    this->itemToModify.price = newCost;
}

/*!
 * \brief maintenance::on_save_button_clicked
 * Confrims item to database
 */
void Maintenance::on_EditSouvenirButton_clicked()
{
    QMessageBox::StandardButton confirm;
    confirm = QMessageBox::question(this, "Confirm Changes", "Are you sure you want to edit this Traditional Souvenir?",
                                    QMessageBox::Yes|QMessageBox::No);
    if (confirm == QMessageBox::Yes) {
        Database::getInstance()->modifySouvenirItem(itemToModify);
        mainWindow->populateAdminMenu();
    }
    this->close();
}
/*!
 * \brief maintenance::on_cancel_button_clicked
 */
void Maintenance::on_AddCancelButton_clicked()
{
    this->close();
}
/*!
 * \brief maintenance::on_cancel_button_clicked
 */
void Maintenance::on_EditCancelButton_clicked()
{
    this->close();
}

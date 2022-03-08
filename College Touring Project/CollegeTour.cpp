#include "CollegeTour.h"
#include "ui_CollegeTour.h"

/*! The College User-Interface
 * \brief CollegeModel::CollegeModel
 * \param collegeClicked - A struct argument
 * \param asuTrip       - bool for starting point
 * \param parent
 */
CollegeTour::CollegeTour(College collegeClicked, bool asuTrip, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CollegeTour)
{
    ui->setupUi(this);
    ui->CollegeTourStackedWidget->setCurrentIndex(0);

    if (asuTrip)
    {
        ui->TripDistancelabel->setText("Total Trip Distance: " + QString::number(collegeClicked.distanceToSaddleback, 'f', 2) + " miles");
        totalCollegesToVisit = Database::getInstance()->getTotalColleges();
    }
    else
    {
        totalDistance = 0;
    }
    QVector<Distance> distances = Database::getInstance()->getDistancesFrom(collegeClicked.id);
    College nextClosest = Database::getInstance()->getCollegeByID(distances[0].destinationCollege_ID);
    ui->NextCollegeButton->setText("Next Closest College\n(" + nextClosest.name + ")");

    this->collegeClicked = collegeClicked;
    populateSouvenirMenu(collegeClicked.id);

    QListWidgetItem* newLabel = new QListWidgetItem(collegeClicked.name);
    ui->ShoppingCartList->addItem(newLabel);
}
/*! Default Constructor
 * \brief CollegeModel::~CollegeModel
 */
CollegeTour::~CollegeTour()
{
    delete ui;
}
/*!
 * \brief CollegeModel::clearWidgets
 * \param layout - Widget to be cleared argument
 */
void CollegeTour::clearWidgets(QLayout * layout)
{
    if (!layout)
        return;
    while (auto item = layout->takeAt(0)) {
        delete item->widget();
        clearWidgets(item->layout());
    }
}
/*!
 * \brief CollegeModel::getTripLength
 * prompts user for trip length based on total colleges in database
 */
void CollegeTour::getTripLength()
{
    bool ok;
    // get user input as soon as the CollegeModel is instantiated from mainmenu.cpp button click event
    int numOfCollegesInput = QInputDialog::getInt(this, tr("Number of Colleges you want to Visit"),
                                                  tr("Enter the total number of colleges you want to visit:"), 1, 0, Database::getInstance()->getTotalColleges(), 1, &ok);
    if (ok) // save the user's input for later use
    {
        this->totalCollegesToVisit = numOfCollegesInput;
        if (this->totalCollegesToVisit == 1)
        {
            ui->NextCollegeButton->setText("End Trip (Checkout)");
        }
    } else {
        // The user did not specify a number of colleges to visit, so close the restuarant view window.
        this->close();
    }
}
/*!
 * \brief CollegeModel::populateSouvenirMenu
 * populates layout with souvenir buttons representing the
 * databases souvenir items for current college that the
 * student can interact with to add souvenirs to their cart
 * \param id - A struct argument
 */
void CollegeTour::populateSouvenirMenu(int id)
{
    clearWidgets(ui->gridLayout);
    College currentCollege = Database::getInstance()->getCollegeByID(id);
    QVector<souvenirItem> souvenirs = currentCollege.souvenirItems;

    // Set up labels
    ui->TripDistancelabel->setText("Distance to Saddleback: " + QString::number(currentCollege.distanceToSaddleback) + " miles");
    ui->CollegeNamelabel->setText(currentCollege.name);
    this->setWindowTitle("Viewing Colleges: " + currentCollege.name);

    // Populates the menu item buttons on Layout
    if (souvenirs.size() > 0)
    {
        int row = 0;
        for (int index=0; index < souvenirs.size(); index++)
        {
            QPushButton* SouvenirButton = new QPushButton(souvenirs[index].name + "\n$ " + QString::number(souvenirs[index].price));
            SouvenirButton->setMaximumHeight(100);

            SouvenirButton->setObjectName(QString::number(souvenirs[index].id));

            connect(SouvenirButton, SIGNAL(clicked()), this, SLOT(souvenirButtonPressed()));
            ui->gridLayout->addWidget(SouvenirButton, row, 0);
            row++;
        }
    }
    this->collegeClicked = currentCollege;
}
/*!
 * \brief CollegeModel::confirmPurchase
 * Confirms if the user wants to purchase the item they have
 * selected for reassurance.
 * \param souvenir - A struct argument
 */
void CollegeTour::confirmPurchase(souvenirItem souvenir)
{
    bool ok;
    int souvenirAmountInput = QInputDialog::getInt(this, tr("Souvenir Amount"),
                                                   tr("How many of this item would you like:"), 1, 0, 99, 1, &ok);
    if(souvenirAmountInput != 0 && ok)
    {
        for(int i = 0; i < souvenirAmountInput; i++)
        {
            cart.addTransaction(collegeClicked, souvenir);
            updateCart(souvenir);
        }

    }
}
/*!
 * \brief CollegeModel::vectorContains
 * Scans vector of colleges if a specified college argument is present
 * \param colleges - A QVector of structs
 * \param searchRest - A struct argument
 * \return bool of if searched college was found
 */
bool CollegeTour::vectorContains(QVector<College> colleges, College searchRest)
{
    for (int index=0; index < colleges.size(); index++)
    {
        if (colleges.at(index).id == searchRest.id)
        {
            return true;
        }
    }
    // if it doesn't hit return true statement, the vector does not contain the given college.
    return false;
}

/*!
 * \brief CollegeModel::recursivePathPlanner
 * Recursively travels from each college to the next based upon the shortest
 * distance between each of the colleges, thens stores the traversal order
 * into a QVector of colleges to be used for the student's trip.
 * \param currentCollege - A struct argument
 * \param mostEfficientList - A QVector of structs
 */
void CollegeTour::recursivePathPlanner(College currentCollege, QVector<College>& mostEfficientList)
{
    mostEfficientList.push_back(currentCollege);

    // cut off the algorithm once we have calculated only the number of colleges the user wants to visit, nothing more
    if (mostEfficientList.size() == this->totalCollegesToVisit)
    {
        return;
    }
    else
    {
        QVector<Distance> distances = Database::getInstance()->getDistancesFrom(currentCollege.id);

        College nextClosest = Database::getInstance()->getCollegeByID(distances.at(0).destinationCollege_ID);

        int index = 1;
        if (vectorContains(mostEfficientList, nextClosest))
        {
            while(vectorContains(mostEfficientList, nextClosest))
            {
                nextClosest = Database::getInstance()->getCollegeByID(distances.at(index).destinationCollege_ID);
                index++;
            }
            totalDistance += distances.at(index-1).distanceTo;

        }
        else
        {
            totalDistance += distances.at(0).distanceTo;

        }
        totalDistancesIndexed.push_back(totalDistance);

        recursivePathPlanner(nextClosest, mostEfficientList);
    }
}
/*!
 * \brief CollegeModel::souvenirButtonPressed
 * Function to use data from the souvenir buttons
 * to add item from database into their transactions
 */
void CollegeTour::souvenirButtonPressed()
{
    // Get the QPushButton object that was clicked
    QPushButton *clickedSouvenirButton = qobject_cast<QPushButton*>(sender());
    // get the ID of menuItem clicked
    int clickedSouvenirID = clickedSouvenirButton->objectName().toInt();

    // Get menu item data from database using the ID
    souvenirItem clickedSouvenir = Database::getInstance()->getSouvenirByID(clickedSouvenirID);

    // Prompt the user to confirm their purchase
    confirmPurchase(clickedSouvenir);
}
/*!
 * \brief CollegeModel::on_next_college_button_clicked
 * Iterates to the next college and processes new menus
 */
void CollegeTour::on_NextCollegeButton_clicked()
{
    if(totalCollegesToVisit == 1)
    {
        this->close();
    }
    else if(mostEfficientTrip.size() == 0)
    {
        QVector<Distance> distances = Database::getInstance()->getDistancesFrom(collegeClicked.id);
        College nextClosest = Database::getInstance()->getCollegeByID(distances.at(0).destinationCollege_ID);

        if(totalCollegesToVisit == 2)
        {

            populateSouvenirMenu(distances.at(0).destinationCollege_ID);
            totalDistance += distances.at(0).distanceTo;

            this->mostEfficientTrip.push_back(collegeClicked);
            this->mostEfficientTrip.push_back(nextClosest);

            ui->TripDistancelabel->setText("Total Trip Distance: " + QString::number((totalDistance), 'f', 2) + " miles");
            ui->NextCollegeButton->setText("End Trip (Checkout)");

            tripIterator = (mostEfficientTrip.end() - 1);

            QListWidgetItem* newLabel = new QListWidgetItem(nextClosest.name);
            ui->ShoppingCartList->addItem(newLabel);

            return;
        }

        this->mostEfficientTrip.push_back(collegeClicked);

        totalDistance += distances.at(0).distanceTo;
        totalDistancesIndexed.push_back(totalDistance);
        recursivePathPlanner(nextClosest, this->mostEfficientTrip);

        this->tripIterator = this->mostEfficientTrip.begin() + 1;

        populateSouvenirMenu(tripIterator->id);
        ui->TripDistancelabel->setText("Total Trip Distance: " + QString::number((totalDistancesIndexed.front())) + " miles");

        // Display the name of the next closest college in UI button
        ui->NextCollegeButton->setText("Next Closest College:\n(" + (tripIterator + 1)->name + ")");
        totalDistancesIndexed.pop_front();
        collegeClicked = *tripIterator;

        QListWidgetItem* newLabel = new QListWidgetItem(collegeClicked.name);
        ui->ShoppingCartList->addItem(newLabel);
    }
    else if(tripIterator != mostEfficientTrip.end() -1)
    {
        tripIterator++;
        populateSouvenirMenu(tripIterator->id);

        // update total distance
        ui->TripDistancelabel->setText("Total Trip Distance: " + QString::number((totalDistancesIndexed.front())) + " miles");
        totalDistancesIndexed.pop_front();
        collegeClicked = *tripIterator;

        QListWidgetItem* newLabel = new QListWidgetItem(collegeClicked.name);
        ui->ShoppingCartList->addItem(newLabel);

        if (tripIterator == mostEfficientTrip.end() -1)
        {
            ui->NextCollegeButton->setText("End Trip (Checkout)");
        }
        else
        {
            // Display the name of the next closest college in UI button
            ui->NextCollegeButton->setText("Next Closest College:\n(" + (tripIterator + 1)->name + ")");
        }
    }
    else //trip end
    {
        this->close();
    }
}
/*!
 * \brief CollegeModel::on_cartList_clicked
 * \param index - representation of item clicked
 */
void CollegeTour::on_ShoppingCartList_clicked(const QModelIndex &index)
{
    this->selectedRow = index.row();
}
/*!
 * \brief CollegeModel::on_removeCartItemButton_clicked
 * Processes removal of item selected by user from the purchases
 * data vector in transactions
 */
void CollegeTour::on_DeleteItemButton_clicked()
{
    if (this->cart.size() > 0 && selectedRow != -2 && ui->ShoppingCartList->item(selectedRow))
    {
        if (ui->ShoppingCartList->item(selectedRow)->data(Qt::UserRole).toInt() == 0)
        {
            QMessageBox errorMsg;
            errorMsg.setText("You can't remove the college name from your cart.");
            errorMsg.exec();
            return;
        }

        QMessageBox::StandardButton confirm;
        confirm = QMessageBox::question(this, "Confirm Deletion", "Are you sure you want to remove the selected item from your cart?",
                                        QMessageBox::Yes|QMessageBox::No);

        if (confirm == QMessageBox::Yes)
        {
            QListWidgetItem* itemToDelete = ui->ShoppingCartList->item(selectedRow);
            souvenirItem deletedItem = Database::getInstance()->getSouvenirByID(itemToDelete->data(Qt::UserRole).toInt());

            College collegePurchasedFrom = Database::getInstance()->getCollegeByID(itemToDelete->data(128).toInt());
            cart.deleteTransaction(Transaction(collegePurchasedFrom, deletedItem));

            // Delete the actual item from memory
            delete itemToDelete;

            // Forces the user to re-select an item if they want to delete contiguous items from the cart
            // Prevents accidental deletions
            selectedRow=-2;

        }
    }
    else
    {
        QMessageBox errorMsg;
        errorMsg.setText("Make sure to select an item from the cart to remove one!");
        errorMsg.exec();
    }
}
/*!
 * \brief CollegeModel::updateCart
 * Updates student's cart to ensure it is accurate and
 * all items are proper
 * \param item - A struct argument
 */
void CollegeTour::updateCart(souvenirItem item)
{
    QListWidgetItem* newItem = new QListWidgetItem;
    newItem->setData(Qt::UserRole, item.id);
    newItem->setData(128, collegeClicked.id);
    newItem->setText(" °  " + item.name + " - $" + QString::number(item.price));

    ui->ShoppingCartList->addItem(newItem);
    ui->TotalPricelabel->setText("Total: $" + QString::number(cart.getTotal(), 'f', 2));
}

/*!
 * \brief CollegeModel::on_totals_button_clicked
 * Creates instance of totalssheet class to view
 * a layout detailing trip expenses.
 */
void CollegeTour::on_ViewCheckoutButton_clicked()
{
    if (cart.size() > 0)
    {
        TotalPage* totalsWindow = new TotalPage(cart, this);
        totalsWindow->show();
    }
}

void CollegeTour::on_BackTMainButton_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    hide();
}

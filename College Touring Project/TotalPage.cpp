#include "TotalPage.h"
#include "ui_TotalPage.h"
/*! Constructor
 * \brief totalPage::totalPage
 * \param cartInfo - A class argument
 * \param parent
 */
TotalPage::TotalPage(Cart cartInfo, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TotalPage)
{
    ui->setupUi(this);

    this->cart = cartInfo;
    cart.printCart();
    QVector<Transaction> purchases = cart.getPurchases();

    College currentCollege = purchases.front().college;
    QListWidgetItem *newLabel = new QListWidgetItem("Cart for college: " + currentCollege.name);


    newLabel->setBackground(Qt::darkGreen);
    ui->TotalPagelist->addItem(newLabel);
    double collegeTotal = 0;
    for (int index = 0; index < cart.size(); index++)
    {
        if (purchases[index].college.id != currentCollege.id)
        {
            ui->TotalPagelist->addItem("Total: $" + QString::number(collegeTotal, 'f', 2) + "\n");
            collegeTotal = 0;
            currentCollege = purchases[index].college;
            QListWidgetItem* newLabel = new QListWidgetItem("Shopping cart for college: " + currentCollege.name);
            newLabel->setBackground(Qt::darkGreen);
            ui->TotalPagelist->addItem(newLabel);
        }
        souvenirItem itemPurchased = purchases[index].itemPurchased;
        collegeTotal += itemPurchased.price;
        ui->TotalPagelist->addItem("  °  " + itemPurchased.name + " - $" + QString::number(itemPurchased.price, 'f', 2));

    }
    ui->TotalPagelist->addItem("Subtotal: $" + QString::number(collegeTotal, 'f', 2) + "\n");
    ui->TotalPagelist->addItem("Total: $" + QString::number(cart.getTotal(), 'f', 2));
}
/*! Destructor
 * \brief totalsSheet::~totalsSheet
 */
TotalPage::~TotalPage()
{
    delete ui;
}

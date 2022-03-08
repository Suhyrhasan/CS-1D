#ifndef TOTALPAGE_H
#define TOTALPAGE_H

#include <QDialog>
#include "Cart.h"
/*! TotalPage Class
 * \brief The TotalPage class
 * UI to display the expenses and invoice
 * from the trip at the time it was invoked
 */
namespace Ui {
class TotalPage;
}

class TotalPage : public QDialog
{
    Q_OBJECT

public:
    //! Constructor
    explicit TotalPage(Cart cartInfo, QWidget *parent = 0);
    //! Default Destructor
    ~TotalPage();

private:
    Ui::TotalPage *ui;   //! UI that displays information from trip
     Cart cart;         //! Cart class of information to be displayed
};

#endif // TOTALPAGE_H

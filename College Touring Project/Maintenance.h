#ifndef MAINTENANCE_H
#define MAINTENANCE_H

#include <QWidget>
#include "Database.h"
#include "mainwindow.h"

namespace Ui {
class Maintenance;
}
/*! Maintenance Operations
 * \brief The maintenance class
 * This class will handle basic operations of
 * User-Interface and altering database records
 * used in the program
 */
class Maintenance : public QWidget
{
    Q_OBJECT

public:
    explicit Maintenance(bool modifying = true, MainWindow *listWidget = 0, souvenirItem souvenir = souvenirItem(),
                         College college = College(), QWidget *parent = 0);
    ~Maintenance();

private slots:
    void on_AddSouvenirButton_clicked();  //! Begins process of souvenir addition to database

    void on_AddCollegeNameComboBox_currentIndexChanged(int index); //! Chooses college from database

    void on_EditSouvenirNameLine_textChanged(const QString &newSouvenirName); //! Stores name for new souvenir

    void on_EditPriceSpinBox_valueChanged(double cost); //! Stores price for new item

    void on_EditSouvenirButton_clicked(); //! Updates souvenir in database

    void on_AddCancelButton_clicked();    //! Returns to main page

    void on_EditCancelButton_clicked();   //! Returns to main page

private:
    Ui::Maintenance *ui;
    MainWindow* mainWindow;     //! Pointer to main window to update UI after database alterations
    souvenirItem itemToModify;  //! Struct to modify souvenir data
    int selectedCollegeID;      //! Struct for college additions to data
    souvenirItem newSouvenir;   //! Struct for souvenir additions to data
};

#endif // MAINTENANCE_H

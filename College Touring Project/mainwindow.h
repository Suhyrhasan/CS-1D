#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QVector>
#include <QMessageBox>
#include <fstream>
#include <QFileDialog>
#include <QFile>
#include <QInputDialog>

/*! Souvenir Item Struct
 * \brief The souvenirItem struct
 * Will replicate details of a souvenir and will be
 * composed into colleges to represent their souvenirs.
 */
struct souvenirItem {
    int id;                            //!< The integer ID for each items
    QString name;                      //!< A QString for the name of items
    double price;                      //!< A double to store each item's price
    int    quantity;                   //!< An integer to store quantity purchased
};

/*! College Struct
 * \brief The College struct
 * Stores colleges with their relevant data as well as
 * operations to compare to other college structs.
 */
struct College {
    int id;                                    //!< The integer ID of each college
    QString name;                              //!< A QString for the name of college
    double distanceToSaddleback;               //!< Double for each colleges's distance to Saddleback
    QVector<souvenirItem> souvenirItems;       //!< QVector of souvenir items that has each colleges' souvenirs

    /*! Operator < Overload
     * \brief operator <
     * Overloaded to compare distances of colleges to each other
     * to find which is the closest.
     * \param otherCollege - A struct argument
     * \return A boolean if one college's distance is less than the others
     */
    bool operator<(const College& otherCollege) const
    {
        return this->distanceToSaddleback < otherCollege.distanceToSaddleback;
    }

    College() {} //! Default Constructor

    /*! Constructor
     * \brief College
     * Constructs college with preset data
     * \param id - An integer argument
     * \param name - A QString argument
     * \param distanceToSaddleback - A double argument
     * \param items - A QVector argument
     */
    explicit College(int id, QString name,  double distanceToSaddleback, QVector<souvenirItem> items)
    {
        this->id = id;
        this->name = name;
        this->distanceToSaddleback = distanceToSaddleback;
        this->souvenirItems = items;
    }
};

/*! Distance Struct
 * \brief The Distance struct
 * Stores distances between two colleges
 */
struct Distance
{
    int destinationCollege_ID;      //!< An integer of the destination's ID
    double distanceTo;              //!< A double of the distance to the destination
};
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void populateMenu();        //! Populates main menu with colleges to start at
    void populateAdminMenu();   //! Populates admin menu with souvenirs from each college

    ~MainWindow();
signals:
    void collegeClickedSignal(College);

private slots:
    void on_CustomTripButton_clicked();   //! Starts custom trip

    void initialCollegeSelected();       //! Sends signal with initial college information

    void on_ShortestTripButton_clicked(); //! Inititaes preset trip from UCI

    void on_ASUTripButton_clicked();       //! Initiates preset trip from ASU

    void on_AdminPageButton_clicked();     //! Changes to admin login page

    void on_pushButton_Login_clicked();    //! Authenticates credentials

    void on_AddSouvenirButton_clicked();   //! Begins souvenir addition process

    void on_DisplaySouvenirWidget_clicked(const QModelIndex &index); //! Selects souvenir index

    void on_DisplaySouvenirWidget_doubleClicked(const QModelIndex &index);   //! Prompts modification or deletion

    void on_UploadCollegeButton_clicked(); //! Begins process to upload college from file

    void on_BackTMainButton_clicked();     //! Returns to home page

    void on_AdminPageButton_3_clicked();  //! Authenticates credentials

    void on_AdminPageButton_2_clicked();   //! Authenticates credentials

    void on_BackTMainButton_3_clicked();   //! Returns to home page

    void on_BackTMainButton_2_clicked();    //! Returns to home page

    void on_SaddlebackTripButton_clicked();

private:
    Ui::MainWindow *ui;
    int selectedRow;    //! Integer from row selected
};
#endif // MAINWINDOW_H

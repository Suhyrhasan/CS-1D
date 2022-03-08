#ifndef DATABASE_H
#define DATABASE_H

#include "mainwindow.h"
/*! The Database
 * \brief The Database class
 * Class to handle all functionality of a SQLite database.
 * Allows only a single instance to be created and uses
 * that instance throughout execution. All data will be
 * represented in QVectors and queries.
 */
class Database
{
public:
    void initializeDB();    //! Initializes instance of database
    void closeDatabase();   //! Closes connection upon termination
    static Database* getInstance();    //! Receives pointer to database for access
    int getTotalColleges();         //! Receives number of colleges in database
    QVector<College> getColleges(); //! Function to get every college in database
    QVector<souvenirItem> getSouvenirsByCollegeID(int collegeID);   //! Searches database for souvenir by college ID
    College getCollegeByID(int college_ID);              //! Searches for college by college ID
    souvenirItem getSouvenirByID(int souvenirItem_ID);  //! Searches for souvenir by college ID
    QVector<Distance> getDistancesFrom(int sourceCollege_ID);   //! Checks distances between colleges
    void addCollegesTable();//! Adds college to colllege table in the database
    void addDistancesTable();//! Adds distances to distances table in the database
    void addSouvenirsTable();//! Adds souvenirs to souvenirs table int the database
    void addSouvenirItem(souvenirItem newSouvenir, College toAddTo); //! Adds souvenir item to database

    void modifySouvenirItem(souvenirItem newSouvenir);  //! Modifies information of specific souvenir item in database

    void deleteSouvenirItem(souvenirItem deletedItem);  //! Deletes souvenir from database records
private:
    Database();                   //! Private Constructor for single instance
    QSqlDatabase database;       //! SQLite Database manager
    static Database *instance;  //! Pointer to the actual database

};

#endif // DATABASE_H

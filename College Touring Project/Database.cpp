#include "Database.h"
#include <iostream>
#include <string>
#include <fstream>
#include <QFileDialog>
#include <QFile>
#include <QInputDialog>


Database* Database::instance = nullptr;
/*!
 * \brief Database::Database
 * Sets up single connection to database
 */
Database::Database()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("ScrumDogs.db");

    if(!database.open())
    {
        qDebug() << ("Database Connection Failed");
    }
    else
    {
        qDebug() << ("Database Connected");
        database.open();
    }
}
/*! To access database
 * \brief Database::getInstance
 * Used for everytime database access is needed
 * \return pointer to database
 */
Database* Database::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Database();
    }
    return instance;
}
/*! Closes connection
 * \brief Database::closeDatabase
 * removes connection to database
 */
void Database::closeDatabase()
{
    database.close();
    database.removeDatabase(QSqlDatabase::defaultConnection);
}
/*!
 * \brief dbManager::initializeDB
 * Initializes data if not present
 */
void Database::initializeDB()
{
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS colleges (ID INTEGER PRIMARY KEY, collegeName varchar(50), DistanceToSaddleback REAL)");
    query.exec("CREATE TABLE IF NOT EXISTS souvenirs (ID INTEGER PRIMARY KEY, collegeID INTEGER, traditionalSouvenir varchar(90), cost REAL)");
    query.exec("CREATE TABLE IF NOT EXISTS distances (startingCollegeID INTEGER, endingCollegeID INTEGER, distanceBetween REAL)");
}
/*!
 * \brief dbManager::getTotalColleges
 * \return size of college records
 */
int Database::getTotalColleges()
{
    // simply returns an integer representing the total number of the colleges in the database
    QSqlQuery query;
    query.exec("SELECT collegeName FROM colleges");
    int totalColleges = 0;
    if (query.exec())
    {
        if(query.first())
        {
            while (query.isValid())
            {
                totalColleges++;
                query.next();
            }
        }
    }
    return totalColleges;
}

/*! Function to get all colleges in database
 * \brief Database::getColleges
 * \return QVector of colleges
 */
QVector<College> Database::getColleges()
{
    QSqlQuery query;
    if(query.prepare("SELECT id, collegeName, DistanceToSaddleback FROM colleges"))
    {
        qDebug() << "success";
    }

    else{
        qDebug() << "fail";
    }
    QVector<College> colleges;

    if (query.exec())
    {
        while (query.next())
        {
            College newCollege;
            newCollege.id = query.value(0).toInt();
            newCollege.name = query.value(1).toString();
            newCollege.distanceToSaddleback = query.value(2).toDouble();

            QVector<souvenirItem> souvenirItems = this->getSouvenirsByCollegeID(newCollege.id);

            newCollege.souvenirItems = souvenirItems;

            colleges.push_back(newCollege);
        }

    }
    else
    {
        qDebug() << "Failed to execute query\n";
    }
    return colleges;
}

/*! To find souvenirs of a college
 * \brief Database::getSouvenirsByCollegeID
 * \param collegeID - An integer argument
 * \return QVector of souvenirs that college has associated with it
 */
QVector<souvenirItem> Database::getSouvenirsByCollegeID(int collegeID)
{
    QVector<souvenirItem> souvenirItems;
    QSqlQuery query;

    query.prepare("SELECT traditionalSouvenir, cost, id FROM souvenirs WHERE collegeID=:collegeID");
    query.bindValue(":collegeID", collegeID);

    if (query.exec())
    {
        if (query.first())
        {
            while(query.isValid())
            {
                souvenirItem tempItems;
                tempItems.name = query.value(0).toString();
                tempItems.price = query.value(1).toDouble();
                tempItems.id = query.value(2).toInt();
                souvenirItems.push_back(tempItems);
                query.next();
            }
        }
    }
    return souvenirItems;
}

/*! To find college by associated ID
 * \brief dbManager::getCollegeByID
 * \param college_ID - An integer argument
 * \return
 */
College Database::getCollegeByID(int collegeID)
{
    QSqlQuery query;
    query.prepare("SELECT id, collegeName, DistanceToSaddleback FROM colleges WHERE id=:collegeID");
    query.bindValue(":collegeID", collegeID);

    if(query.exec())
    {
        if (query.first())
        {
            College returnCollege;
            returnCollege.id = query.value(0).toInt();
            returnCollege.name = query.value(1).toString();
            returnCollege.souvenirItems = getSouvenirsByCollegeID(returnCollege.id);
            returnCollege.distanceToSaddleback = query.value(2).toDouble();

            return returnCollege;
        }
    }
}

/*! To find souvenir by ID
 * \brief dbManager::getSouvenirByID
 * Searches database by specific souvenir ID
 * \param souvenirItem_ID - An integer argument
 * \return
 */
souvenirItem Database::getSouvenirByID(int souvenirItemID)
{
    QSqlQuery query;
    query.prepare("SELECT id, traditionalSouvenir, Cost FROM souvenirs WHERE id=:souvenirItemID");
    query.bindValue(":souvenirItemID", souvenirItemID);

    if(query.exec())
    {
        if (query.first()) {
            souvenirItem returnItem;
            returnItem.id = query.value(0).toInt();
            returnItem.name = query.value(1).toString();
            returnItem.price = query.value(2).toDouble();

            return returnItem;
        }
    }

}

//! To get the colleges to other colleges
/*!
 * \brief getDistancesFrom Will take in the colleges ID
 * and match it with is corresponding distances list and return
 * it for use.
 * \param sourceCollege_ID - An integer argument
 * \return A QVector of the distances of that college
 */
QVector<Distance> Database::getDistancesFrom(int startingCollegeID)
{
    QSqlQuery query;
    QVector<Distance> distances;
    query.prepare("SELECT endingCollegeID, DistanceBetween FROM distances WHERE startingCollegeID=:startingCollegeID ORDER BY distanceBetween ASC");
    query.bindValue(":startingCollegeID", startingCollegeID);

    if (query.exec())
    {
        if (query.first())
        {
            while (query.isValid())
            {
                Distance tempDistance;
                tempDistance.destinationCollege_ID = query.value(0).toInt();
                tempDistance.distanceTo = query.value(1).toDouble();

                distances.push_back(tempDistance);
                query.next();
            }
        }
    }
    return distances;
}

/*! To add a new college to database
 * \brief dbManager::addCollege
 * Will use input college information to add it to databse
 * \param college - A struct argument
 * \param distances - A QVector argument
 */\
void Database::addCollegesTable()
{
    std::string collegeName;
    float DistanceToSaddleback;
    std::ifstream inFile;
    inFile.open("newCampus_Colleges.txt");
    if(!inFile)
    {
        QMessageBox errorMsg;
        errorMsg.setText("There was a problem attempting to upload the file. Please try again. ");
        errorMsg.exec();
        return;
    }else{
        while(inFile) {
            // Read college name
            getline(inFile, collegeName);
            inFile >> DistanceToSaddleback;
            inFile.ignore(10000,'\n');
            QString college_name = QString::fromStdString(collegeName);
            QSqlQuery collegesQuery;
            // Adds the college name, ID, and distanceToSaddleback to colleges table in database
            collegesQuery.prepare("INSERT INTO colleges (ID, collegeName, DistanceToSaddleback) VALUES(:name, :distanceToSaddleback)");
            collegesQuery.bindValue(":name", college_name);
            collegesQuery.bindValue(":distanceToSaddleback", DistanceToSaddleback);
            qDebug() << "Inserting college " << college_name << " to saddleback: " << DistanceToSaddleback;
            collegesQuery.exec();
        }
        inFile.close();
    }
}
/*! To add a new college to database
 * \brief dbManager::addCollege
 * Will use input college information to add it to databse
 * \param college - A struct argument
 * \param distances - A QVector argument
 */\
void Database::addDistancesTable()
{
    int startingCollegeID;
    int endingCollegeID;
    float distanceBetween;
    std::ifstream inFile;
    inFile.open("newCampus_Distances.txt");
    if(!inFile)
    {
        QMessageBox errorMsg;
        errorMsg.setText("There was a problem attempting to upload the file. Please try again. ");
        errorMsg.exec();
        return;
    }else{
        while(inFile) {
            // Read college name
            inFile >> startingCollegeID;
            inFile >> endingCollegeID;
            inFile >> distanceBetween;
            QSqlQuery distancesQuery;
            // Adds the college name, ID, and distanceToSaddleback to colleges table in database
            distancesQuery.prepare("INSERT INTO distances (startingCollegeID, endingCollegeID, distanceBetween)"
                                   "VALUES(:startingCollegeID, :endingCollegeID, :distanceBetween)");
            distancesQuery.bindValue(":startingCollegeID",startingCollegeID);
            distancesQuery.bindValue(":endingCollegeID", endingCollegeID);
            distancesQuery.bindValue(":distanceBetween", distanceBetween);
            qDebug() << "Inserting distance from " << startingCollegeID  << " to: " <<  endingCollegeID << " is " << distanceBetween;
            distancesQuery.exec();
        }
        inFile.close();

    }
}
/*! To add a new college to database
 * \brief dbManager::addCollege
 * Will use input college information to add it to databse
 * \param college - A struct argument
 * \param distances - A QVector argument
 */\
void Database::addSouvenirsTable()
{
    int collegeID;
    std::string traditionalSouvenir;
    float cost;
    std::ifstream inFile;
    inFile.open("newCampus_Souvenirs.txt");
    if(!inFile)
    {
        QMessageBox errorMsg;
        errorMsg.setText("There was a problem attempting to upload the file. Please try again. ");
        errorMsg.exec();
        return;
    }else{
        while(inFile) {
            // Read college name
            inFile >> collegeID;
            getline(inFile, traditionalSouvenir);
            inFile >> cost;
            inFile.ignore(10000,'\n');
            QString traditional_souvenir = QString::fromStdString(traditionalSouvenir);
            QSqlQuery souvenirQuery;
            // Adds the college name, ID, and distanceToSaddleback to colleges table in database
            souvenirQuery.prepare("INSERT INTO souvenirs (id, collegeID, traditionalSouvenir, cost) VALUES(collegeID, traditional_souvenir, :cost)");
            souvenirQuery.bindValue(":collegeID", collegeID);
            souvenirQuery.bindValue(":traditional_souvenir", traditional_souvenir);
            souvenirQuery.bindValue(":cost", cost);
            qDebug() << "Inserting souvenir from " << collegeID << " names " << traditional_souvenir << "that costs $" << cost;
            souvenirQuery.exec();
        }
        inFile.close();

    }
}
/*! To add souvenir item to database
 * \brief dbManager::addSouvenirItem
 * Adds souvenir item to records based on input
 * information
 * \param newSouvenir - A struct argument
 * \param toAddTo - A struct argument
 */
void Database::addSouvenirItem(souvenirItem newSouvenir, College collegeAddingTo)
{
    QSqlQuery souvenirItemQuery;
    souvenirItemQuery.prepare("INSERT INTO souvenirs ( id, collegeId, traditionalSouvenir, cost) VALUES(collegeId, :name, :cost)");
    souvenirItemQuery.bindValue(":name", newSouvenir.name);
    souvenirItemQuery.bindValue(":price", newSouvenir.price);
    souvenirItemQuery.bindValue(":collegeID", collegeAddingTo.id);
    souvenirItemQuery.exec();
}

/*! To modify souvenir information
 * \brief dbManager::modifySouvenirItem
 * Changes record data fro given souvenir item
 * \param newSouvenirItem - A struct argument
 */
void Database::modifySouvenirItem(souvenirItem newSouvenirItem)
{
    QSqlQuery query;
    query.prepare("UPDATE souvenirs SET traditionalSouvenir=:name, Cost=:price WHERE id=:oldID");
    query.bindValue(":name", newSouvenirItem.name);
    query.bindValue(":price", newSouvenirItem.price);
    query.bindValue(":oldID", newSouvenirItem.id);
    query.exec();
}

/*! Deletes souvenir from database
 * \brief dbManager::deleteSouvenirItem
 * Will take item and delete it from database records
 * \param deletedItem
 */
void Database::deleteSouvenirItem(souvenirItem deletedItem)
{
    QSqlQuery query;
    query.prepare("DELETE FROM souvenirs WHERE id=:ID");
    query.bindValue(":ID", deletedItem.id);
    query.exec();
}

#ifndef COURSEMANAGER_H
#define COURSEMANAGER_H
#include <limits>
#include "Registration.h"
class CourseManager{ 
  public:
    CourseManager(int num);//create a hashtable with the input number of buckets
    ~CourseManager(); //default destructor
    HashTable<Course>* getData();//return the address hashtable for course
    void printCosMenu();// print the menu
    void insertCosRecord();//add a course
    void modifyCosRecord();//modify a course
    void deleteCosRecord(Registration * rgs); //delete a course
    void queryCosRecord(); //qeury course record

  private:
    
    HashTable<Course> cosTable;// the hashtable storing all course info
};
  
#endif
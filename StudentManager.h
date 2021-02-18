#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H
#include <limits>
#include "Registration.h"
class StudentManager{ 
  public:
    StudentManager(int num);   // create a hashtable with the input number of buckets
    ~StudentManager(); //default destructor
    HashTable<Student>* getData();//return the address hashtable for student
    void printStuMenu();// print the menu
    void insertStuRecord();//add a student
    void modifyStuRecord();//modify a student
    void deleteStuRecord(Registration* rgs);//delete a student
    void queryStuRecord();//qeury student record
    
  private:
    
    HashTable<Student> stuTable;;// the hashtable storing all student info
};
  
#endif
#ifndef REGISTRATION_H
#define REGISTRATION_H
#include <limits>
#include "Course.h"
#include "Student.h"
#include "CourseSelection.h"
#include "HashTable.h"
#include "Index.h"
#include <fstream>
#include <assert.h>

class Registration{ 
  
  friend class StudentManager;
  friend class CourseManager;
  friend class HTML;
  
public:
    Registration(HashTable<Student> * ,HashTable<Course> * ); //constructor reading student hashtable and the course table for interal modification
    ~Registration();//default destructor
    void printRgsMenu();//print the registration menu
    void printIOMenu();//print the file save & load file
    void registerCourse();//register a studnet to a course
    void dropCourse();//drop a student to a course
    void modifyMark();//modify the exam mark of a student to a course
    void queryRegistration();//query the registration data
    void saveData();//save student, course and register data and output
    void loadData();//load a data base with student, course and register data and output
    void removeAllStu(string ID);//remove all registration record of the given id
    node<Index>* findStuIdx(string ID);//return the address of the first index node with given id
    node<Index>* findCosIdx(string code);//return the address of the first index node with given code
    HashTable<Course>* getCosData() const; //get the course hashtable
    HashTable<Student>* getStuData() const;//get the student hash table

private:
    static void inputID(string& ID); //read ID until valid input
    static void inputSname(string& Name);//read student name until valid input
    static void inputYear(string& Year);//read year until valid input
    static void inputGender(string& Gender);//read gender until valid input
    static void inputCode(string& Code); //read code until valid input
    static void inputCname(string& Name); //read name until valid input
    static void inputCredits(string& Credits); // read credits until valid input
    static void inputMark(string& Mark);
    //p = false for user input, true for file input
    static bool validID(const string& input, bool p = false);//determine if the input is valid
    static bool validSname(const string& input, bool p = false);//determine if the input is valid
    static bool validYear(const string& input, bool p = false);//determine if the input is valid
    static bool validGender(const string& input, bool p = false);//determine if the input is valid                 
    static bool validCode(const string& input, bool p = false);//determine if the input is valid
    static bool validCname(const string& input, bool p = false);//determine if the input is valid
    static bool validCredits(const string& input, bool p = false);//determine if the input is valid  
    static bool validMark(const string& input, bool p = false);
    /* above all refer to the student and course manager, they are for checking valid a input and read it */
    HashTable<Course>* courseData; //pointer to course hashtable
    HashTable<Student>* studentData; //pointer to student hashtable
    HashTable<Index> cosIndex;//course index hash table
    HashTable<Index> stuIndex;//student index hash table
    DoublyLinkedList<CourseSelection> registration;//doubly linked list for registration records
};
  
#endif 

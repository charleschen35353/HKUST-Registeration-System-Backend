#ifndef HTML_H
#define HTML_H
#include <iostream>
#include <fstream>
#include <assert.h>
#include <string.h>
#include <string>
#include "CourseManager.h"
#include "StudentManager.h"

using namespace std;

class HTML{
  public:
    HTML(Registration* Data); //load registration data
    void printRptMenu(); //print report menu
    void outputStu(); //output student html
    void outputCos();//output course html
    void outputCosOfStu();//output courses of a student html
    void outputStuOfCos();//output students of a course html
    
  private:
    DoublyLinkedList<Student>& getStuTable(int index);//get the indexth list in the student table
    DoublyLinkedList<Course>& getCosTable(int index);//get the indexth list in the course table
    Student& getStudentInfo(string ID); //get the student object of the input ID
    Course& getCourseInfo(string code);//get the course object of the input code
    Registration * DataBase;  //pointer to register data base
 
};

#endif
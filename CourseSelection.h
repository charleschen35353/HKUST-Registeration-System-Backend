#ifndef COURSESELECTION_H
#define COURSESELECTION_H
#include <iostream>
#include <string>
#include<math.h>
using namespace std;

class CourseSelection{ 
  public:
    CourseSelection();//empty ID and code, mark = -1 meaning N/A
    ~CourseSelection();//default destructor
    CourseSelection(string stu, string code, string mark= "-1"); // registration data with ID, code and a default mark N/A
    CourseSelection(const CourseSelection& c); //copy constructor
    CourseSelection& operator=(const CourseSelection& c); //copy all data from input
    bool operator==(const CourseSelection& c); //check if the ID and code is same
    bool operator!=(const CourseSelection& c);
    bool operator<(const CourseSelection& c); //find the order of a data of course selection
    string getKey() const; //return key
    string getSubkey() const; 
    int getMark() const;  //retrun mark  	
    int& getMark();
    void getMark(string Mark); // assign input into the mark
    friend ostream& operator<<(ostream &os, const CourseSelection& c); // print out the data

  private:
    string stuID;
    string cosCode; 
    int mark; 
};
  
#endif 

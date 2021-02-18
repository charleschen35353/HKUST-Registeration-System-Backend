#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include <string>
#include <ctype.h>
using namespace std;

class Student{ 
  public:
    Student();//default constructor with ID, name = empty string and year = 0, gender = male;
    ~Student();//default destructor
    Student(string id, string name, string year, string gender); //read the ID, name year, and gender and create a new course data
    Student(const Student& s);//copy constructor
    Student& operator=(const Student& s);// memberwise copy
    bool operator==(const Student& s);// check if two students have the same ID
    bool operator!=(const Student& s);// ID not the same
    bool operator<(const Student& s);// check if the ID is smaller than the input's
				     // use the value of the ID to determine the bigger one
    string getKey() const; //return ID
    string getName() const; //return Name
    string& getName();
    int getYear() const; //return year	
    int& getYear();
    void getYear(string year); //modify year with valid input string year
    char getGender() const;     //return gender
    char& getGender();
    void getGender(string gender); //modify year with valid input string gender
    friend ostream& operator<<(ostream &os, const Student& s); //print student info

  private:
    string ID;
    string Name;// anything
    int Year; // 1 to 3
    char Gender; //M or F
};
  
#endif
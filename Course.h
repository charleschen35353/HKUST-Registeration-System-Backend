#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>
using namespace std;

class Course{ 
  public:
    Course();//default constructor with code, name = empty string and credits = 0;
    ~Course();//default destructor
    Course(string code, string name, string credits); //read the code, name and credit and create a new course data
    Course(const Course& c);//copy constructor
    Course& operator=(const Course& c); // memberwise copy
    bool operator==(const Course& c); // check if two courses have the same code
    bool operator!=(const Course& c); // codes not the same
    bool operator<(const Course& c); // check if the code is smaller than the input's
				     // use the corresponding ascii code number to represent the vlaue
    string getKey() const; // return code
    string getName() const; //return name
    string& getName();
    int getCredits() const; // return credits
    int& getCredits();
    void getCredits(string credits);//modify credits with a string type credits input
    friend ostream& operator<<(ostream &os, const Course& c); //print course info

  private:
    string Code;
    string Name; 
    int Credits; 
};
  
#endif
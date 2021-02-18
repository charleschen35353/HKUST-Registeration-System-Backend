#ifndef MAINMANAGER_H
#define MAINMANAGER_H
#include<iostream>
using namespace std;

class MainManager{ 
  public:
    MainManager();//constructor with choice = 0
    ~MainManager();//default destructor
    void printMainMenu();// print out main menu
    void update();//print from the very top of konsole
    void inputChoice(string input,int num); //keep geting choice while the input choice is in the given number range
    int getChoice()const; //return choice
private:
    bool validchoice(int range,string input); //check whether the chioce is valid
					      //first parameter is the maximum choice, seconde be the input of choice
    int choice; //user choice
};
  
#endif
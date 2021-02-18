#include"CourseManager.h"

CourseManager::CourseManager(int num):cosTable(num){}; 

CourseManager::~CourseManager(){}; 

HashTable<Course>* CourseManager::getData(){
    return &cosTable;
}

void CourseManager::printCosMenu(){
    cout<<"HKUST Course Registration System (Course Menu)"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<endl;
    cout<<"1. Insert Course Record"<<endl;
    cout<<"2. Modify Course Record"<<endl;
    cout<<"3. Delete Course Record"<<endl;
    cout<<"4. Query Course Record"<<endl;
    cout<<"5. Go back to main menu"<<endl;
    cout<<endl;
    cout<<"Enter your choice (1-5): ";
}

void CourseManager::insertCosRecord(){
 
    string code,name,credits;
    cout<<"Enter the course code: ";
    Registration::inputCode(code); //get string code till the valid input
    
    if (cosTable.search(code) == cosTable.originPoint()){ //if the course not found in the hash table    
      cout<<"Enter the course name: ";
      Registration::inputCname(name); //get string name till the valid input
      cout<<"Enter the course credits [0-5]: ";
      Registration::inputCredits(credits); //get string credits till the valid input
      
      cosTable.insertItem(Course(code, name ,credits)); //insert a object into the table
      cout<<"Creation of course record successful"<<endl<<endl; 
    }
    
    else {
      cout<< "course already exist"<<endl;
    }
    cout<<"Hit ENTER to continue..."<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  //pause
}

void CourseManager::modifyCosRecord(){
  string code,name,credits;
  node<Course>* ptr; //used to store the course-to-find
  cout<<"Enter the course code: ";
  Registration::inputCode(code); //get string code till the valid input
  if ((ptr = cosTable.search(code)) != cosTable.originPoint()){ // if the course is found
    cout<<"Enter the course name ["<<ptr->data.getName()<<"]: ";
    Registration::inputCname(name);ptr->data.getName() = name; //get name and modify the name
    cout<<"Enter the course credits [0-5]: ";
    Registration::inputCredits(credits);ptr->data.getCredits(credits); // get credits and modify it
    cout<<"Modification of course record successful"<<endl<<endl;
  }
  else{
     cout<<"Course not exist"<<endl<<endl;
  }
  
  cout<<"Hit ENTER to continue..."<<endl;
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //pause
}

void CourseManager::deleteCosRecord(Registration* rgs){ //pass the registration record for detemining if any student is enrolling the course
  string code;
  node<Course>* ptr;//used to store the course-to-find
  cout<<"Enter the course code: ";
  Registration::inputCode(code);
  if ((ptr = cosTable.search(code)) != cosTable.originPoint()){// if the course is found
    if(rgs->findCosIdx(code) != NULL){ //if any student enrolled
      cout<<"Some students already registered in this course, deletion fail"<<endl<<endl;
    }
    else{ //no student enrolled
      cosTable.deleteItem(ptr->data); //kill the data
      cout<<"Deletion of Course record successful"<<endl<<endl; 
    }
  }
  else{
     cout<<"Course not exist"<<endl<<endl;
  }
  cout<<"Hit ENTER to continue..."<<endl;
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //pause 
}

void CourseManager::queryCosRecord(){
  string code;
  node<Course>* ptr;//used to store the course-to-find
  cout<<"Enter the course code: ";
  Registration::inputCode(code); //get valid code
  if ((ptr = cosTable.search(code)) != cosTable.originPoint()){ //if the course is found
   cout<<ptr->data<<endl; //print the course
  }
  else{
     cout<<"Course not exist"<<endl<<endl;
  }
  cout<<"Hit ENTER to continue..."<<endl;
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //pause 
}
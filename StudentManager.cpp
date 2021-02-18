#include"StudentManager.h"

StudentManager::StudentManager(int num):stuTable(num){}

StudentManager::~StudentManager(){}

HashTable<Student>* StudentManager::getData(){
    return &stuTable;
}

void StudentManager::printStuMenu(){
    cout<<"HKUST Course Registration System (Student Menu)"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<endl;
    cout<<"1. Insert Student Record"<<endl;
    cout<<"2. Modify Student Record"<<endl;
    cout<<"3. Delete Student Record"<<endl;
    cout<<"4. Query Student Record"<<endl;
    cout<<"5. Go back to main menu"<<endl;
    cout<<endl;
    cout<<"Enter your choice (1-5): ";
}

void StudentManager::insertStuRecord(){
    string ID,name,year,gdr;
    cout<<"Enter the student ID: ";
    Registration::inputID(ID); //get string ID till the valid input
    
    if (stuTable.search(ID) == stuTable.originPoint()){//not found  
      cout<<"Enter the student name: ";
      Registration::inputSname(name);//get string name till the valid input
      cout<<"Enter the student year[1-3]: ";
      Registration::inputYear(year);//get string year till the valid input
      cout<<"Enter the student gender[M,F]: ";
      Registration::inputGender(gdr);//get string gender till the valid input
      stuTable.insertItem(Student(ID,name,year,gdr)); //insert a object into the table

      cout<<"Creation of student record successful"<<endl<<endl;
    }
    else {
      cout<< "Student already exist"<<endl<<endl;
    }
    cout<<"Hit ENTER to continue..."<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //pause
}
void StudentManager::modifyStuRecord(){
  string ID,name,year,gdr;
  node<Student>* ptr;//used to store the student-to-find
  cout<<"Enter the student ID: ";
  Registration::inputID(ID);
  if ((ptr = stuTable.search(ID)) != stuTable.originPoint()){ // if the student is found in the table
    cout<<"Enter the student name ["<<ptr->data.getName()<<"]: ";
    Registration::inputSname(name);ptr->data.getName() = name;//get name and modify it
    cout<<"Enter the student year[1-3]: ";
    Registration::inputYear(year);ptr->data.getYear(year); // get year and modify it
    cout<<"Enter the student gender[M,F]: ";
    Registration::inputGender(gdr);ptr->data.getGender(gdr); // get gender and modify it
    cout<<"Modification of student record successful"<<endl<<endl;
  }
  else{
     cout<<"Student not exist"<<endl<<endl;
  }
  
  cout<<"Hit ENTER to continue..."<<endl;
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //pause
}

void StudentManager::deleteStuRecord(Registration* rgs){  //pass the registration record for killing registration regarding to the given ID
  string ID;
  node<Student>* ptr;//used to store the student-to-find
  cout<<"Enter the student ID: ";
  Registration::inputID(ID);
  if ((ptr = stuTable.search(ID)) != stuTable.originPoint()){ //if the student is found in the table
   rgs->removeAllStu(ID); //remove all student enrolling data of given ID
   stuTable.deleteItem(ptr->data);//delete the student 
   cout<<"Deletion of student record successful"<<endl<<endl;
  }
  else{
     cout<<"Student not exist"<<endl<<endl;
  }
  cout<<"Hit ENTER to continue..."<<endl;
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //pause
}

void StudentManager::queryStuRecord(){
  string ID;
  node<Student>* ptr;//used to store the student-to-find
  cout<<"Enter the student ID: ";
  Registration::inputID(ID);
  if ((ptr = stuTable.search(ID)) != stuTable.originPoint()){ //if student found
   cout<<ptr->data<<endl;
  }
  else{
     cout<<"Student not exist"<<endl<<endl;
  }
  cout<<"Hit ENTER to continue..."<<endl;
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //pause
}
#include"Student.h"

Student::Student():ID(""),Name(""),Year(0),Gender('M'){}

Student::Student(string id, string name, string year,string gender):ID(id),Name(name),Year(year[0]-'0'),Gender(toupper(gender[0])){}

Student::~Student(){}

Student& Student::operator=(const Student& s){
  ID = s.ID;
  Name = s.Name;
  Year = s.Year;
  Gender = s.Gender;
  
  return *this;
}

Student::Student(const Student& s){
  ID = s.ID;
  Name = s.Name;
  Year = s.Year;
  Gender = s.Gender;
}

bool Student::operator==(const Student& s){
  return (ID == s.ID);  
}
bool Student::operator!=(const Student& s){
  return !operator==(s);  
}
bool Student::operator<(const Student& s){ //comapre ID with the number it represents
  bool isSmaller = false;
  for(int i = 0 ; i < ID.length(); i ++){
    if(ID[i]==s.ID[i]) continue; //move onto the next digit
    if(ID[i] < s.ID[i]){isSmaller = true;break;} 
    else break;
  }
  return isSmaller; 
}
string Student::getKey() const{
  return ID;
}
string Student::getName() const{
  return Name;
}
string& Student::getName(){
  return Name;
}
int Student::getYear() const{
  return Year;
}
int& Student::getYear(){
  return Year;
}
void Student::getYear(string year){//modify year with a valid string type input
   Year = year[0]-'0'; //transfer char into int
}
char Student::getGender() const{
  return Gender;
}
char& Student::getGender() {
  return Gender;
}
void Student::getGender(string gender){//modify gender with a valid string type input
  Gender = gender[0];
}

ostream& operator<<(ostream &os, const Student& s){ //print student info
  os<<endl;
  os<<"ID:\t"<<s.ID<<endl;
  os<<"Name:\t"<<s.Name<<endl;
  os<<"Year:\t"<<s.Year<<endl;
  os<<"Gender: ";
  if(s.Gender == 'M')os<<"Male"<<endl;
  else os<<"Female"<<endl;
  os<<endl;
}
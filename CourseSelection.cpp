#include"CourseSelection.h"

CourseSelection::CourseSelection():stuID(""),cosCode(""),mark(-1){};

CourseSelection::CourseSelection(string s, string c, string m ):stuID(s),cosCode(c){
  getMark(m); //read mark
}
CourseSelection::~CourseSelection(){};

CourseSelection& CourseSelection::operator=(const CourseSelection& c){
  stuID = c.stuID;
  cosCode = c.cosCode;
  mark = c.mark;
  
  return *this;
}

CourseSelection::CourseSelection(const CourseSelection& c){
  stuID = c.stuID;
  cosCode = c.cosCode;
  mark = c.mark;
}

bool CourseSelection::operator==(const CourseSelection& c){
  return (stuID == c.stuID && cosCode == c.cosCode);  //check if the ID and code is same
}
bool CourseSelection::operator!=(const CourseSelection& c){
  return !operator==(c);  
}
bool CourseSelection::operator<(const CourseSelection& c){
  bool isSmaller = false;
  string key1 = stuID + cosCode;
  string key2 = c.stuID+c.cosCode;

  if(key1.length() > key2.length()) key2 += "/";    //balance the length
  else if(key1.length() < key2.length()) key1 +="/";
 
  for(int i = 0 ; i < key1.length(); i ++){//find the order of a data of course selection
    if(key1[i]==key2[i]) continue;
    if(key1[i] < key2[i]) isSmaller = true;
    else break;
  }
  
  return isSmaller;
}
string CourseSelection::getKey() const{
  return stuID;
}
string CourseSelection::getSubkey() const{
  return cosCode;
} 
int CourseSelection::getMark() const{
  return mark;
}    	
int& CourseSelection::getMark(){
  return mark;
}
void CourseSelection::getMark(string m){
  
  int sum = 0;
  for(int i = 0 ; i < m.length() ; i ++){ //stoi
	sum += (m[ m.length() - (i +1) ]-'0')*(int)(pow(10,i));
   }
  (m=="-1")?(mark = -1 ):(mark = sum); //if no mark provided, assign -1*/
}
ostream& operator<<(ostream &os, const CourseSelection& c){
  os<<endl;
  os<<"Student ID: "<<c.stuID<<endl;
  os<<"Course Code: "<<c.cosCode<<endl;
  os<<"Mark: ";
  if(c.mark >= 0)os<<c.mark<<endl; 
  else os<<"N/A"<<endl; // no mark given
}
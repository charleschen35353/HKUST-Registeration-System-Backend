#include"Course.h"

Course::Course():Code(""),Name(""),Credits(0){};

Course::Course(string code, string name, string credits):Code(code),Name(name),Credits(credits[0]-'0'){}

Course::~Course(){}; 

Course& Course::operator=(const Course& c){
  Code = c.Code;
  Name = c.Name;
  Credits = c.Credits;
  
  return *this;
}

Course::Course(const Course& c){
  Code = c.Code;
  Name = c.Name;
  Credits = c.Credits;
}

bool Course::operator==(const Course& c){
  return (Code == c.Code);  
}
bool Course::operator!=(const Course& c){
  return !operator==(c);  
}
bool Course::operator<(const Course& c){
  bool isSmaller = false;
  string k1 = Code;
  string k2 = c.Code;
  
  if(k1>k2){ //the following makes two key the same length 
    k1 +=" ";
  }
  else if (k1<k2){
    k2 += " ";
  }
  
  for(int i = 0 ; i < 8; i ++){ // compare the code with the ascii code order
    if(k1[i]==k2[i]) continue; //find next element
    if(k1[i] < k2[i]){isSmaller = true;break;}
    else break; //larger
  }
  return isSmaller;
}
string Course::getKey() const{
  return Code;
}
string Course::getName() const{
  return Name;
}   
string& Course::getName(){
  return Name;
}
int Course::getCredits() const{
  return Credits;
}    	
int& Course::getCredits(){
  return Credits;
}
void Course::getCredits(string credits){//modify credits with a string type credits input
    Credits = credits[0]-'0';
}
ostream& operator<<(ostream &os, const Course& c){ //print course info

  os<<endl;
  os<<"Code:\t"<<c.Code<<endl;
  os<<"Name:\t"<<c.Name<<endl;
  os<<"Credits:"<<c.Credits<<endl;
  os<<endl;
}
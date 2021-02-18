#include"MainManager.h"

MainManager::MainManager():choice(0){}

MainManager::~MainManager(){}

void MainManager::printMainMenu(){
  cout<<"HKUST Course Registration System"<<endl;
  cout<<"--------------------------------"<<endl;
  cout<<endl;
  cout<<"1. Student Management"<<endl;
  cout<<"2. Course Management"<<endl;
  cout<<"3. Course Registration"<<endl;
  cout<<"4. Report Management"<<endl;
  cout<<"5. File Management"<<endl;
  cout<<"6. Exit"<<endl;
  cout<<endl;
  cout<<"Enter your choice (1-6): ";
}

void MainManager::update(){
  cout<<"\033[2J\033[1;1H";// print out main menu
}

bool MainManager::validchoice(int range, string input){//check whether the chioce is valid
  bool isValid= true;
  
  if(input.length()!=1){
    cout<<"invalid input, re-enter again(1-"<<range<<"): ";
    isValid = false;
  }
  else{
    if(!(input[0]-'0'<=range && input[0]-'0' > 0)){
      cout<<"invalid input, re-enter again(1-"<<range<<"): ";
      isValid = false;
    }
  }
  
  if(isValid == true) choice = input[0]-'0';
  return isValid;
}

void MainManager::inputChoice(string input,int num){//keep geting choice while the input choice is in the given number range
  do{getline(cin,input);}while(!validchoice(num,input));
}
int MainManager::getChoice() const{
 return choice; 
} 
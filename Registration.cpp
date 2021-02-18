#include"Registration.h"

Registration::Registration(HashTable<Student>* s,HashTable<Course>* c):studentData(s),courseData(c),cosIndex(17),stuIndex(29){};

Registration::~Registration(){};

void Registration::printRgsMenu(){
    cout<<"HKUST Course Registration System (Registration Menu)"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<endl;
    cout<<"1. Add Course"<<endl;
    cout<<"2. Drop Course"<<endl;
    cout<<"3. Modify Exam Mark"<<endl;
    cout<<"4. Query Registration"<<endl;
    cout<<"5. Go back to main menu"<<endl;
    cout<<endl;
    cout<<"Enter your choice (1-5): ";
}

void Registration::printIOMenu(){
    cout<<"HKUST Course Registration System (File Menu)"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<endl;
    cout<<"1. Save Database"<<endl;
    cout<<"2. Load Database"<<endl;
    cout<<"3. Go back to main menu"<<endl;
    cout<<endl;
    cout<<"Enter your choice (1-3): ";
}

void Registration::registerCourse(){
    Index si, ci;
    string code,ID;
    cout<<"Enter the student ID: ";
    inputID(ID); //get string ID till the valid input
    
    if (studentData->search(ID)!= studentData->originPoint()){//if student is found
      cout<<"Enter the course code: ";
      inputCode(code);//get string code till the valid input
      if(courseData->search(code)!=courseData->originPoint()){ //if course is found
	if(stuIndex.search(ID, code) == stuIndex.originPoint()){//if not such registration data exists
	  registration.insert(CourseSelection(ID, code));//insert the record
	  si.getKey() = ID;
	  si.getDataAdr() = registration.find(ID,code);//to the newly created record
	  ci.getKey() = code;
	  ci.getDataAdr() = registration.find(ID,code);//to the newly created record
	  stuIndex.insertItem(si);//insert a index
	  cosIndex.insertItem(ci);//insert a index
	  cout<<"Add course successful"<<endl<<endl;
	}
	else
	  cout<<"The student already registered the course"<<endl<<endl;
      }
      else
	cout<< "course not exist"<<endl<<endl;
    }
    else 
      cout<< "student not exist"<<endl<<endl;
    
    cout<<"Hit ENTER to continue..."<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //pause
}

void Registration::dropCourse(){
    string code,ID;
    node<Index>* ptr;
    cout<<"Enter the student ID: ";
    inputID(ID); //get string ID till the valid input
    
    if (studentData->search(ID)!= studentData->originPoint()){  //if student is found  
      cout<<"Enter the course code: ";
      inputCode(code);//get string code till the valid input
      if(courseData->search(code) != courseData->originPoint()){ //if course is found
	if((ptr=stuIndex.search(ID, code))!= stuIndex.originPoint()){ //if the registration is found
	  node<CourseSelection>* tmp = ptr->data.getDataAdr();
	  stuIndex.deleteItem(stuIndex.search(ID, code)->data);//delete the index
	  cosIndex.deleteItem(cosIndex.search(code, ID)->data);//delete the index
	  registration.remove(tmp);//drop it
	  cout<<"Drop course successful"<<endl<<endl;
	}
	else
	  cout<<"The registration record not exist"<<endl<<endl;
      }
      else
	cout<< "course not exist"<<endl<<endl;
    }
    else 
      cout<< "student not exist"<<endl<<endl;
    
    cout<<"Hit ENTER to continue..."<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //pause
}

void Registration::modifyMark(){
    string code,ID,mark;
    node<Index>* ptr;
    cout<<"Enter the student ID: ";
    inputID(ID); //get string ID till the valid input
    
    if (studentData->search(ID)!= studentData->originPoint()){//if student is found  
      cout<<"Enter the course code: ";
      inputCode(code);//get string code till the valid input
      if(courseData->search(code)!= courseData->originPoint()){//if course is found
	if((ptr = stuIndex.search(ID, code)) != stuIndex.originPoint()){//if the registration is found
	  cout<<"Enter the exam mark [";
	  (ptr->data.getDataAdr()->data.getMark()==-1)?(cout<<"N/A]: "):(cout<<ptr->data.getDataAdr()->data.getMark()<<"]: ");
	  inputMark(mark);ptr->data.getDataAdr()->data.getMark(mark);//modify exam mark
	  cout<<"Modification of exam mark successful"<<endl<<endl;
	}
	else
	  cout<<"The registration record not exist"<<endl<<endl;
      }
      else
	cout<< "course not exist"<<endl<<endl;
    }
    else 
      cout<< "student not exist"<<endl<<endl;
    
    cout<<"Hit ENTER to continue..."<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //pause
}

void Registration::queryRegistration(){
    string code,ID;
    node<Index>* ptr;
    cout<<"Enter the student ID: ";
    inputID(ID); //get string ID till the valid input
    
    if (studentData->search(ID)!= studentData->originPoint()){//if student is found   
      cout<<"Enter the course code: ";
      inputCode(code);//get string code till the valid input
      if(courseData->search(code)!= courseData->originPoint()){//if course is found
	if((ptr = stuIndex.search(ID, code)) != stuIndex.originPoint()){//if the registration is found
	  cout<<ptr->data.getDataAdr()->data<<endl;//print it
	}
	else
	  cout<<"The registration record not exist"<<endl<<endl;
      }
      else
	cout<< "course not exist"<<endl<<endl;
    }
    else 
      cout<< "student not exist"<<endl<<endl;
    
    cout<<"Hit ENTER to continue..."<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');//pause
}

void Registration::saveData(){

    string fname;
    cout<<"Enter the filename: ";
    getline(cin, fname);
    const char* FILE = fname.c_str();//string to char literate
    ofstream fout(FILE); //file output
    assert(fout.is_open());
    
    fout<<studentData->getEleNum()<<endl;//output numbers of student 
    if (studentData->getEleNum()!=0){ //output any existing data
      for(int i = 0 ; i < 29; i++){
	node<Student>* ptr = studentData->getListn(i).getOrigin()->next;
	while(ptr != studentData->getListn(i).getOrigin()){
	  fout<<ptr->data.getKey()<<endl;
	  fout<<ptr->data.getName()<<endl;
	  fout<<ptr->data.getYear()<<endl;
	  fout<<ptr->data.getGender()<<endl;
	  ptr = ptr->next;
	}
      }
    }
    
    fout<<courseData->getEleNum()<<endl;//output numbers of course 
    if (courseData->getEleNum()!=0){//output any existing data
      for(int i = 0 ; i < 17; i++){
	node<Course>* ptr = courseData->getListn(i).getOrigin()->next;
	while(ptr != courseData->getListn(i).getOrigin()){
	  fout<<ptr->data.getKey()<<endl;
	  fout<<ptr->data.getName()<<endl;
	  fout<<ptr->data.getCredits()<<endl;
	  ptr = ptr->next;
	}
      }
    }
    
    node<CourseSelection>* ptr = registration.getOrigin()->next;
    fout<<registration.getSize()<<endl;//output numbers of registration
    while(ptr != registration.getOrigin()){//output any existing data
      fout<<ptr->data.getKey()<<endl;;
      fout<<ptr->data.getSubkey()<<endl;
      fout<<ptr->data.getMark();
      if(ptr->next != registration.getOrigin())fout<<endl;
      ptr = ptr->next;
    }
    
    cout<<"Saving Successful"<<endl<<endl;
    cout<<"Hit ENTER to continue..."<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');//pause
}
void Registration::loadData(){
  
    string fname;
    cout<<"Enter the filename: ";
    getline(cin, fname);
    const char* FILE = fname.c_str();//string to char literate
    const char* TEST = fname.c_str();//string to char literate
    ifstream fin(TEST); //input file
    bool validfile = true;
    /*determine if the input is valid*/
    if(fin.is_open()){ 
      string tmp="";
      int num = 0;
      
      if(validfile){
	getline(fin,tmp);//read numbers of student
	for(int i = 0; i < tmp.length() ; i++){
	  num += (tmp[tmp.length()-(i+1)]-'0')*pow(10,i);//string to interger
	}
      }
      
      for(int i = 0 ; i < num && validfile; i++){//input any existing data
	string id, name, year, gender;
	getline(fin,id); validfile = (validfile && validID(id,true));
	getline(fin,name);validfile = (validfile && validSname(name,true));
	getline(fin,year);validfile = (validfile && validYear(year,true));
	getline(fin,gender);validfile = (validfile && validGender(gender,true));
      }
      
      num = 0;tmp="";
      if(validfile){
	getline(fin,tmp);//read numbers of student
	for(int i = 0; i < tmp.length() ; i++){
	  num += (tmp[tmp.length()-(i+1)]-'0')*pow(10,i);//string to interger
	}
      }
     
      for(int i = 0 ; i <  num && validfile; i++){//input any existing data
	string code, name, credits;
	getline(fin,code);validfile = (validfile && validCode(code,true));
	getline(fin,name);validfile = (validfile && validCname(name,true));
	getline(fin,credits);validfile = (validfile && validCredits(credits,true));
       }
     
      num = 0;tmp="";
      if(validfile){
	getline(fin,tmp);//read numbers of student
	for(int i = 0; i < tmp.length() ; i++){
	  num += (tmp[tmp.length()-(i+1)]-'0')*pow(10,i);//string to interger
	}
      }
     
      for(int i = 0 ; i <  num && validfile; i++){//input any existing data
	Index si, ci;
	string id, code, mark;
        getline(fin,id);validfile = (validfile && validID(id,true));
	getline(fin,code);validfile = (validfile && validCode(code,true));
	getline(fin,mark);validfile = (validfile && validMark(mark,true));
      }
      fin.close();
      
      if(!validfile){;
	cout<<"Error: Load File Error (File not exist / File Corrupted / Incorrect Format)"<<endl<<endl;
	cout<<"Hit ENTER to continue..."<<endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');//pause
	return;
      }
    }
    else{
       fin.close();
	cout<<"Error: Load File Error (File not exist / File Corrupted / Incorrect Format)"<<endl<<endl;
	cout<<"Hit ENTER to continue..."<<endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');//pause
	return;
    }
    /*read all the info*/
    ifstream fin2(FILE);
    if(fin2.is_open()){ 
      stuIndex.clear();//clean table data 
      cosIndex.clear();//clean table data 
      courseData->clear();//clean table data 
      studentData->clear();//clean table data 
      registration.initialize();//clean list data
      
      string tmp="";
      int num = 0;
      
      if(validfile){
	getline(fin2,tmp);//read numbers of student
	for(int i = 0; i < tmp.length() ; i++){
	  num += (tmp[tmp.length()-(i+1)]-'0')*pow(10,i);//string to interger
	}
      }
      
      for(int i = 0 ; i < num && validfile; i++){//input any existing data
	string id, name, year, gender;
	getline(fin2,id); 
	getline(fin2,name);
	getline(fin2,year);
	getline(fin2,gender);
	studentData->insertItem(Student(id,name,year,gender));//
      }
      
      num = 0;tmp="";
      if(validfile){
	getline(fin2,tmp);//read numbers of student
	for(int i = 0; i < tmp.length() ; i++){
	  num += (tmp[tmp.length()-(i+1)]-'0')*pow(10,i);//string to interger
	}
      }
     
      for(int i = 0 ; i <  num && validfile; i++){//input any existing data
	string code, name, credits;
	getline(fin2,code);
	getline(fin2,name);
	getline(fin2,credits);
	courseData->insertItem(Course(code,name,credits));//
       }
     
      num = 0;tmp="";
      if(validfile){
	getline(fin2,tmp);//read numbers of student
	for(int i = 0; i < tmp.length() ; i++){
	  num += (tmp[tmp.length()-(i+1)]-'0')*pow(10,i);//string to interger
	}
      }
     
      for(int i = 0 ; i <  num && validfile; i++){//input any existing data
	Index si, ci;
	string id, code, mark;
        getline(fin2,id);
	getline(fin2,code);
	getline(fin2,mark);
	if(mark == "-1") registration.insert(CourseSelection(id,code)); //mark = N/A//
	else registration.insert(CourseSelection(id,code,mark)); //insert data//
	
	si.getKey() = id;
	si.getDataAdr() = registration.find(id,code);//to the newly created record//
	ci.getKey() = code;
	ci.getDataAdr() = registration.find(id,code);//to the newly created record//
	stuIndex.insertItem(si); //insert index//
	cosIndex.insertItem(ci);//insert index//
	}
	cout<<"Loading Successful"<<endl<<endl;
      }
  
    fin.close();
    cout<<"Hit ENTER to continue..."<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');//pause
}

node<Index>* Registration::findStuIdx(string ID){//return the address of the first index node with given id
    node<Index>* ptr = stuIndex.search(ID);
    return (ptr == stuIndex.originPoint())?NULL:ptr;//NULL for not found
}

node<Index>* Registration::findCosIdx(string code){//return the address of the first index node with given code
    node<Index>* ptr = cosIndex.search(code); 
    return (ptr == cosIndex.originPoint())?NULL:ptr;//NULL for not found
}
void Registration::removeAllStu(string ID){//remove all registration record of the given id
    node<Index>* si = findStuIdx(ID);//find the fist index with the same ID
    if( si != NULL){//found
      while(si->data.getKey() == ID){ //keep removing untill the ID is not the same
	node<CourseSelection>* toDel = si->data.getDataAdr();
	node<Index>* tmp = si->next;
	stuIndex.deleteItem(si->data);//delete in student index table
	cosIndex.deleteItem(cosIndex.search(si->data.getSubkey(),ID)->data);//delete in course index table
	registration.remove(toDel);//remove the registration data
	si = tmp;
      }
    }
}

void Registration::inputID(string& ID){
    do{getline(cin,ID);}while(!validID(ID));
}
void Registration::inputSname(string& Name){
    do{getline(cin,Name);}while(!validSname(Name));
}
void Registration::inputYear(string& Year){
    do{getline(cin,Year);}while(!validYear(Year));
}
void Registration::inputGender(string& Gender){
    do{getline(cin,Gender);}while(!validGender(Gender));
}
void Registration::inputCode(string& Code){
    do{getline(cin,Code);}while(!validCode(Code)); //keep reading until the input is valid
}
void Registration::inputCname(string& Name){
    do{getline(cin,Name);}while(!validCname(Name));
}
void Registration::inputCredits(string& Credits){
    do{getline(cin,Credits);}while(!validCredits(Credits));
}
void Registration::inputMark(string& Mark){//refer to manager classes
    do{getline(cin,Mark);}while(!validMark(Mark));
}

bool Registration::validID(const string& input, bool p){
  bool isValid= true;
  
  if(input.length()!= 8)isValid = false; //check if the length if input ID is 8
  else
    for(int i = 0 ; i < 8 && isValid==true; i++)
      if(!((input[i]-'0') < 10 && (input[i]-'0') >= 0)) isValid = false; //check whether they are all numeric
  
  if(!isValid && !p) cout<<"invalid input, re-enter again [student ID]: ";
  return isValid;
}
bool Registration::validSname(const string& input, bool p ){
  if(input.length()<=32 && input.length()>0)return true; // check if the input name's size is inbetween 1 and 32
  else{
    if(!p) cout<<"invalid input, re-enter again [student name]: ";
    return false;
  }
}
bool Registration::validYear(const string& input, bool p ){
  bool isValid= true;
    
  if(input.length()!= 1)isValid = false; //check if the length is valid
  else
    if(!((input[0]-'0') < 4 && (input[0]-'0') >= 1))isValid = false; //check if the year is inbetween 1 and 3
    
  if(!isValid &&!p) cout<<"invalid input, re-enter again [student year]: ";
  return isValid;
}

bool Registration::validGender(const string& input, bool p ){
    
  bool isValid= true;
  
  if(input.length()!= 1)isValid = false; //check if the length is valid
  else
    if(!(input[0] == 70 || input[0] == 77 || input[0] == 109 ||input[0] == 102))isValid = false;
    //check if the input is 'M' 'F' 'f' 'm' accordiing to the sample provided
  if(!isValid&& !p)cout<<"invalid input, re-enter again [student gender]: ";
  return isValid;
}


bool Registration::validCode(const string& input, bool p ){
    bool isValid= true;
    if(!(input.length()== 7 || input.length()== 8)){ // check if the length is valid
      isValid = false;
    }
    else{
	for(int i = 0 ; i < 4 ; i++) // the first for char of a course code must be char
	  if(!(input[i]>='A' && input[i]<='Z'))isValid = false;
	
	for(int i =4 ; i < input.length() ; i++)
	  if(!( (input[i]>='A' && input[i]<='Z') || (input[i]>='0' && input[i]<='9') ))isValid = false; //the rest must be char or num
    }
    
    if(!isValid&& !p) cout<<"invalid input, re-enter again [course code]: ";
    return isValid;
}
bool Registration::validCname(const string& input, bool p){
    if(input.length()<= 50 && input.length()>=1)return true; //size must be inbetween 1 and 50
    else{
      if(!p) cout<<"invalid input, re-enter again [course name]: ";
      return false;
    }
}
bool Registration::validCredits(const string& input, bool p){
    bool isValid= true;
    
    if(input.length()!= 1) isValid = false;
    else
	if(!((input[0]-'0') <= 5 && (input[0]-'0') >= 0))isValid = false; //credits must be inbetween 0 and 5
   
    if(!isValid&& !p) cout<<"invalid input, re-enter again [course credits]: ";
    return isValid;
}


bool Registration::validMark(const string& input, bool p ){//refer to manager classes
    bool isValid= true;                                    //p = false for user input, true for file input
    int sum = 0;
   
    for(int i = 0 ; i < input.length() && isValid ; i ++){
      if(input[ input.length() - (i +1) ]<='9' && input[ input.length() - (i +1) ]>='0')
	sum += (input[ input.length() - (i +1) ]-'0')*(long int)(pow(10,i));
      else
	isValid = false;
    }
    
    /*
    if(!(input.length()== 1 ||input.length()== 2||input.length()== 3))isValid = false;
    else
	for(int i = 0 ; i < input.length() ; i ++){
	  if(!(input[i]>='0' && input[i]<='9')) isValid = false;
	  if(input.length()==3) 
	    if(!(input[0]=='1' && input[1]=='0' && input[2]=='0')) isValid = false;
	}
  */
    if(!(sum <=100 && sum >=0)) isValid = false;
    if(p) if(input == "-1") isValid = true;
    
    if(!isValid && !p) cout<<"invalid input, re-enter again [exam mark]: ";
    return isValid;
}


HashTable<Course>* Registration::getCosData() const{
    return courseData;
}
HashTable<Student>* Registration::getStuData() const{
    return studentData;
}
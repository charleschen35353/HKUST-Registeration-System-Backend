#include"HTML.h"

HTML::HTML(Registration * rgs):DataBase(rgs){}

void HTML::printRptMenu(){
    cout<<"HKUST Course Registration System (Course Menu)"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<endl;
    cout<<"1. List all student information"<<endl;
    cout<<"2. List all course information"<<endl;
    cout<<"3. List all courses of a student"<<endl;
    cout<<"4. List all students of a course"<<endl;
    cout<<"5. Go back to main menu"<<endl;
    cout<<endl;
    cout<<"Enter your choice (1-5): ";
}

void HTML::outputStu(){
    DoublyLinkedList<Student> toPrint; //list for student output, since data in the hash table is somehow random
    ofstream fout("Students.html");
    assert (fout.is_open());
    fout<<"<HTML>"<<endl;
    fout<<"<HEAD>"<<endl;
    fout<<"<HEAD>"<<endl;
    fout<<"<TITLE>All Students List</TITLE>"<<endl;
    fout<<"</HEAD>"<<endl;
    fout<<"<BODY bgColor=#ffffcc>"<<endl;
    fout<<"<H1><FONT color=#6600ff>HKUST Course Registration System</FONT></H1>"<<endl;
    fout<<"<H2>All Students List</H2>"<<endl;
    fout<<"<P>"<<endl;
      
    for(int i = 0 ; i < 29; i++){ //put all student data into the list
      node<Student>* ptr = getStuTable(i).getOrigin()->next;
      while(ptr != getStuTable(i).getOrigin()){
	toPrint.insert(ptr->data);
	ptr = ptr->next;
      }
    }
    
    if(toPrint.getSize()!= 0){ //if the list is not empty
      
      node<Student>* ptr = toPrint.getOrigin()->next;
      
      fout<<"<TABLE cellSpacing=1 cellPadding=1 border=1>"<<endl;
      fout<<endl;
      fout<<"<TR>"<<endl; //table output
      fout<<"<TD>Student ID</TD>"<<endl;
      fout<<"<TD>Student Name</TD>"<<endl;
      fout<<"<TD>Year</TD>"<<endl;
      fout<<"<TD>Gender</TD>"<<endl;
      fout<<"</TR>"<<endl;
      
      for(;ptr!=toPrint.getOrigin();ptr = ptr->next){ //output all students data
	fout<<endl;
	fout<<"<TR>"<<endl;
	fout<<"<TD>"<<ptr->data.getKey()<<"</TD>"<<endl;
	fout<<"<TD>"<<ptr->data.getName()<<"</TD>"<<endl;
	fout<<"<TD>"<<ptr->data.getYear()<<"</TD>"<<endl;
	if(ptr->data.getGender()=='M') fout<<"<TD>Male</TD>"<<endl;
	else fout<<"<TD>Female</TD>"<<endl;
	fout<<"</TR>"<<endl;
	fout<<endl;
      }
       fout<<"</TABLE>"<<endl;
    }
    else
      fout<<"No student found"<<endl;
    
    fout<<"</P>"<<endl;
    fout<<"</BODY>"<<endl;
    fout<<"</HTML>"<<endl;
    fout.close(); //close oupt
  
    cout<<"Output Successful"<<endl<<endl;
    cout<<"Hit ENTER to continue..."<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
}

void HTML::outputCos(){
    DoublyLinkedList<Course> toPrint;
    ofstream fout("Courses.html");
    assert (fout.is_open());
    fout<<"<HTML>"<<endl;
    fout<<"<HEAD>"<<endl;
    fout<<"<HEAD>"<<endl;
    fout<<"<TITLE>All Course List</TITLE>"<<endl;
    fout<<"</HEAD>"<<endl;
    fout<<"<BODY bgColor=#ffffcc>"<<endl;
    fout<<"<H1><FONT color=#6600ff>HKUST Course Registration System</FONT></H1>"<<endl;
    fout<<"<H2>All Course List</H2>"<<endl;
    fout<<"<P>"<<endl;
    
    
   
    for(int i = 0 ; i < 17; i++){//put all course data into the list
      node<Course>* ptr = getCosTable(i).getOrigin()->next;
      while(ptr != getCosTable(i).getOrigin()){
	toPrint.insert(ptr->data);
	ptr = ptr->next;
      }
    }
    if(toPrint.getSize() != 0){
      
      node<Course>* ptr = toPrint.getOrigin()->next;
      
      fout<<"<TABLE cellSpacing=1 cellPadding=1 border=1>"<<endl;
      fout<<endl;
      fout<<"<TR>"<<endl; //table output
      fout<<"<TD>Course Code</TD>"<<endl;
      fout<<"<TD>COurse Name</TD>"<<endl;
      fout<<"<TD>Credit</TD>"<<endl;
      fout<<"</TR>"<<endl;
      
      for(;ptr!=toPrint.getOrigin();ptr = ptr->next){//output all course data
	fout<<endl;
	fout<<"<TR>"<<endl;
	fout<<"<TD>"<<ptr->data.getKey()<<"</TD>"<<endl;
	fout<<"<TD>"<<ptr->data.getName()<<"</TD>"<<endl;
	fout<<"<TD>"<<ptr->data.getCredits()<<"</TD>"<<endl;
	fout<<"</TR>"<<endl;
	fout<<endl;
      }
       fout<<"</TABLE>"<<endl;
    }
    else
      fout<<"No course found"<<endl;
    
  
    fout<<"</P>"<<endl;
    fout<<"</BODY>"<<endl;
    fout<<"</HTML>"<<endl;
    fout.close();//close output
  
    cout<<"Output Successful"<<endl<<endl;
    cout<<"Hit ENTER to continue..."<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
}


void HTML::outputCosOfStu(){
    node<Index>* ptr = NULL;
    string ID;
    cout<<"Enter the student ID: ";
    Registration::inputID(ID);
    if(DataBase->getStuData()->search(ID) != DataBase->getStuData()->originPoint()){//if the student exists
      string tmp = ID + ".html";
      const char* OUTPUTFILE = tmp.c_str();
      ofstream fout(OUTPUTFILE);
  
      assert (fout.is_open());
   
      fout<<"<HTML>"<<endl;
      fout<<"<HEAD>"<<endl;
      fout<<"<HEAD>"<<endl;
      fout<<"<TITLE>Course Records for Student "<<ID <<"</TITLE>"<<endl;
      fout<<"</HEAD>"<<endl;
      fout<<"<BODY bgColor=#ffffcc>"<<endl;
      fout<<"<H1><FONT color=#6600ff>HKUST Course Registration System</FONT></H1>"<<endl;
      fout<<"<H2>Course Records for Student "<<getStudentInfo(ID).getName() <<" ("<< ID <<")</H2>"<<endl;
      fout<<"<P>"<<endl;
      
      if((ptr = DataBase->findStuIdx(ID))!= NULL){ //if the student has enrolled any class
	fout<<"<TABLE cellSpacing=1 cellPadding=1 border=1>"<<endl;
	fout<<endl;
	fout<<"<TR>"<<endl;
	fout<<"<TD>Course Code</TD>"<<endl;
	fout<<"<TD>Course Name</TD>"<<endl;
	fout<<"<TD>Credit</TD>"<<endl;
	fout<<"<TD>Exam Mark</TD>"<<endl;
	fout<<"</TR>"<<endl;
	
	while(ptr->data.getKey() == ID){ //print out all classes that the student has enrolled
	  CourseSelection record = ptr->data.getDataAdr()->data;
	  fout<<endl;
	  fout<<"<TR>"<<endl;
	  fout<<"<TD>"<<record.getSubkey()<<"</TD>"<<endl;
	  fout<<"<TD>"<<getCourseInfo(record.getSubkey()).getName()<<"</TD>"<<endl;
	  fout<<"<TD>"<<getCourseInfo(record.getSubkey()).getCredits()<<"</TD>"<<endl;
	  if(record.getMark()==-1)fout<<"<TD>N/A</TD>"<<endl;
	  else fout<<"<TD>"<<record.getMark()<<"</TD>"<<endl;
	  fout<<"</TR>"<<endl;
	  fout<<endl;
	  ptr = ptr->next;
	}
      fout<<"</TABLE>"<<endl;
      }
      else{
	fout<<"No course taken"<<endl;
      }
      
      fout<<"</P>"<<endl;
      fout<<"</BODY>"<<endl;
      fout<<"</HTML>"<<endl;
      fout.close();//close file
     
      cout<<"Output Successful"<<endl<<endl;
    }
    else
      cout<<"student not exist"<<endl<<endl;
    cout<<"Hit ENTER to continue..."<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
}

void HTML::outputStuOfCos(){
    node<Index>* ptr = NULL;
    string code;
    cout<<"Enter the course code: ";
    Registration::inputCode(code);
    if(DataBase->getCosData()->search(code) != DataBase->getCosData()->originPoint()){ //if the course exists
      string tmp = code + ".html";
      const char* OUTPUTFILE = tmp.c_str();
      ofstream fout(OUTPUTFILE);
      assert (fout.is_open());
    
      fout<<"<HTML>"<<endl;
      fout<<"<HEAD>"<<endl;
      fout<<"<HEAD>"<<endl;
      fout<<"<TITLE>Student Records for Course "<<code<<endl;
      fout<<"</TITLE>"<<endl;
      fout<<"</HEAD>"<<endl;
      fout<<"<BODY bgColor=#ffffcc>"<<endl;
      fout<<"<H1><FONT color=#6600ff>HKUST Course Registration System</FONT></H1>"<<endl;
      fout<<"<H2>Student Records for Course: ";
      fout<< getCourseInfo(code).getName()<<" ("<< code <<")</H2>"<<endl;
      fout<<"<P>"<<endl;
      
      if((ptr = DataBase->findCosIdx(code))!= NULL){ // if the course is taken by any student
	fout<<"<TABLE cellSpacing=1 cellPadding=1 border=1>"<<endl;
	fout<<endl;
	fout<<"<TR>"<<endl; //print table
	fout<<"<TD>Student ID</TD>"<<endl;
	fout<<"<TD>Student Name</TD>"<<endl;
	fout<<"<TD>Year</TD>"<<endl;
	fout<<"<TD>Gender</TD>"<<endl;
	fout<<"<TD>Exam Mark</TD>"<<endl;
	fout<<"</TR>"<<endl;
	
	while(ptr->data.getKey() == code){ //print out all students taking the course
	  CourseSelection record = ptr->data.getDataAdr()->data;
	  fout<<endl;
	  fout<<"<TR>"<<endl;
	  fout<<"<TD>"<<record.getKey()<<"</TD>"<<endl;
	  fout<<"<TD>"<<getStudentInfo(record.getKey()).getName()<<"</TD>"<<endl;
	  fout<<"<TD>"<<getStudentInfo(record.getKey()).getYear()<<"</TD>"<<endl;
	  
	  if(getStudentInfo(record.getKey()).getGender() == 'M')fout<<"<TD>Male</TD>"<<endl;
	  else fout<<"<TD>Female</TD>"<<endl;
	  
	  if(record.getMark()==-1)fout<<"<TD>N/A</TD>"<<endl;
	  else fout<<"<TD>"<<record.getMark()<<"</TD>"<<endl;
	  
	  fout<<"</TR>"<<endl;
	  fout<<endl;
	  ptr = ptr->next;
	}
  
	fout<<"</TABLE>"<<endl;
      }
      else
	fout<<"No student takes this course"<<endl;
      
      
      
      fout<<"</P>"<<endl;
      fout<<"</BODY>"<<endl;
      fout<<"</HTML>"<<endl;
      fout.close();    //close file
    
      cout<<"Output Successful"<<endl<<endl;
    }
    else
      cout<<"course not exist"<<endl<<endl;
    cout<<"Hit ENTER to continue..."<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
}

Student& HTML::getStudentInfo(string ID){//get the student object of the input ID
  return DataBase->getStuData()->search(ID)->data;
}

Course& HTML::getCourseInfo(string code) {//get the course object of the input code
  return DataBase->getCosData()->search(code)->data;
}
DoublyLinkedList<Student>& HTML::getStuTable(int i){//get the indexth list in the student table
  return DataBase->getStuData()->getListn(i);
}
DoublyLinkedList<Course>& HTML::getCosTable(int i){//get the indexth list in the course table
  return DataBase->getCosData()->getListn(i);
  
}
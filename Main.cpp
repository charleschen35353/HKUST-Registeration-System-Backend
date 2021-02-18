#include "Student.h"
#include "Course.h"
#include "MainManager.h"
#include "StudentManager.h"
#include "CourseManager.h"
#include "Registration.h"
#include "HTML.h"

int main(int argc, char **argv){
  
  string choice;//user choice
  MainManager mm;// print the menu and get the choice
  StudentManager stdm(29);//managing student data
  CourseManager cosm(17);//managing course data
  Registration rgs(stdm.getData(),cosm.getData());//managing registration data, studant and course hashtable is also modificable here
  HTML html(&rgs);//html output
  
  do{
    mm.update();
    mm.printMainMenu();
    mm.inputChoice(choice,6);
    mm.update();
   
    switch(mm.getChoice()){ //get choice 
    
      case 1:
	stdm.printStuMenu();
	mm.inputChoice(choice,5);
	switch(mm.getChoice()){
	  case 1: stdm.insertStuRecord();break;
	  case 2: stdm.modifyStuRecord();break;
	  case 3: stdm.deleteStuRecord(&rgs);break;
	  case 4: stdm.queryStuRecord();break;
	  case 5: break;
	}
       break;

      case 2:
	cosm.printCosMenu();
	mm.inputChoice(choice,5);
	switch(mm.getChoice()){
	  case 1: cosm.insertCosRecord();break;
	  case 2: cosm.modifyCosRecord();break;
	  case 3: cosm.deleteCosRecord(&rgs);break;
	  case 4: cosm.queryCosRecord();break;
	  case 5: break;
	}
	break;
	
      case 3:
	rgs.printRgsMenu();
	mm.inputChoice(choice,5);
	switch(mm.getChoice()){
	  case 1: rgs.registerCourse();break;
	  case 2: rgs.dropCourse();break;
	  case 3: rgs.modifyMark();break;
	  case 4: rgs.queryRegistration();break;
	  case 5: break;
	}
	break;
      
      case 4:
	html.printRptMenu();
	mm.inputChoice(choice,5);
	switch(mm.getChoice()){
	  case 1: html.outputStu();break;
	  case 2: html.outputCos();break;
	  case 3: html.outputCosOfStu();break;
	  case 4: html.outputStuOfCos();break;
	  case 5: break;
	}
	break;
      
      case 5:
	rgs.printIOMenu();
	mm.inputChoice(choice,3);
	switch(mm.getChoice()){
	  case 1: rgs.saveData();break;
	  case 2: rgs.loadData();break;
	  case 3: break;
	}
	break;
    }
    
  }while(mm.getChoice() != 6);
  
  return 0;
}
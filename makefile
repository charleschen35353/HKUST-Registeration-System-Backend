all: Register
Register: Main.o Course.o CourseSelection.o CourseManager.o  MainManager.o  Registration.o   StudentManager.o Student.o HTML.o Index.o HashTable.h DoublyLinkedList.h
	c++ -o Register  Main.o Course.o CourseSelection.o CourseManager.o  MainManager.o  Registration.o   StudentManager.o  Student.o HTML.o Index.o
CourseManager.o: CourseManager.cpp CourseManager.h
	c++ -c CourseManager.cpp
Course.o: Course.cpp Course.h
	c++ -c Course.cpp
CourseSelection.o: CourseSelection.cpp CourseSelection.h
	c++ -c CourseSelection.cpp
Registration.o: Registration.cpp Registration.h
	c++ -c Registration.cpp
MainManager.o: MainManager.cpp MainManager.h
	c++ -c MainManager.cpp
StudentManager.o: StudentManager.cpp StudentManager.h
	c++ -c StudentManager.cpp
Student.o: Student.cpp Student.h
	c++ -c Student.cpp
HTML.o: HTML.cpp HTML.h
	c++ -c HTML.cpp
Index.o: Index.cpp Index.h
	c++ -c Index.cpp
clean:
	rm *.o

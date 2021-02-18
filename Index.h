#ifndef INDEX_H
#define INDEX_H
#include"CourseSelection.h"
#include"HashTable.h"

class Index{
  public:
    Index();//constructor to make the key empty and pointer to nothing
    ~Index();//default destructor
    Index(string, node<CourseSelection>*); //store ID and data address by creating a new index node
    string& getKey(); // return key
    string getSubkey(bool p = false); //get the complementary key of the index
				      //if the key is ID, then subkey is code, vice versa.
				      //parameter p: false means get code(for stuIndex), true means get ID(for codeIndex)
    node<CourseSelection>*& getDataAdr(); //get the registeration data address its pointer pointing to
    bool operator<(const Index& i);//ordered with the ID and code the index pointing to
    bool operator==(const Index& i);//check whether the ID and the code of the pointed data is the same 
    bool operator!=(const Index& i); //ID and code not equal
    bool operator=(const Index& i);// do shallow copy
  private:
    string key;//ID or code regarding its index
    node<CourseSelection>* pointer;// a pointer to the registeration record
}; 
#endif
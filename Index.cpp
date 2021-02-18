#include "Index.h"

Index::Index():key(""), pointer(NULL){}

Index::~Index(){}

Index::Index(string k, node<CourseSelection>* p):key(), pointer(p){}//store ID and data address by creating a new index node

string& Index::getKey(){ return key; }

string Index::getSubkey(bool p){ 
  return (p)?(pointer->data.getKey()):(pointer->data.getSubkey()); //true then get Id false then get code
}

node<CourseSelection>*& Index::getDataAdr(){ return pointer; }//get the registeration data address its pointer pointing to

bool Index::operator<(const Index& i){//ordered with the ID and code the index pointing to
    return pointer->data < i.pointer->data;
}

bool Index::operator==(const Index& i){//check whether the ID and the code of the pointed data is the same 
  return pointer->data== i.pointer->data;
}

bool Index::operator!=(const Index& i){
  return !operator=(i);
}

bool Index::operator=(const Index& i){
  key = i.key;
  pointer = i.pointer;
}

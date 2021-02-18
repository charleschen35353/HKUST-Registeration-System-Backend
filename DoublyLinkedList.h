#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include<iostream>
using namespace std;
template<typename T> //define a node for all data management
struct node{
  T data;
  node* next;
  node* prev;
};

template<typename T>
class DoublyLinkedList{
  public:  
    DoublyLinkedList();//create a circular doubly linked list with only a dummy node
    ~DoublyLinkedList();//destructor to delete all stored data
    node<T>* find(const T& obj); // return the node address which stores the exact data of the input
    node<T>* find(const string& key);// return the node address which stores the exact data of the input key
    node<T>* find(const string& pk,const string& sk); // return the node address which stores the exact data of the input primary and sub key
    node<T>* getOrigin() const; //get the dummy node address
				//for find() functions, if not found it will return the address of this point 
    void initialize();//kill all input data excpet the dummy node, literally initializing
    void insert(const T& obj); //insert a object into list
    void remove(const T& obj); //remove a given object if it exists in the list
    void remove(node<T>* obj); //remove a object by providing the address of the exact node storing the exact object data
    int getSize();//get the number of stored node in the list
  private:
    node<T>* dummy;
    int size; //list size
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList():dummy(new node<T>),size(0){
  dummy->data = T(); //empty data
  dummy->next = dummy; //dummy next to itself
  dummy->prev = dummy; //dummy previous to itself
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
  initialize(); //delete storing data
  delete dummy;
}

template <typename T>
void DoublyLinkedList<T>::initialize(){ 
  while(dummy->next != dummy){ //delete storing data while non-dummy nodes still exist
    node<T>* del = dummy->next; //delete the first one
    dummy->next = del->next; //relink
    del->next->prev = del->prev; //relink
    delete del;
  }
  size = 0; //initialize the size
}
template<typename T>
void DoublyLinkedList<T>::insert(const T& obj){
  node<T>* newdata = new node<T>; //create new node 
  newdata->data=obj;  //store data
  node<T>* ptr = dummy->next;  //find the correct position of the new data

  while(ptr!= dummy &&  ptr->data < obj){ptr = ptr->next;} // keep move the pointer untill it finds the one bigger than it or dummy
  newdata->next = ptr; //insert the new data before the dummy or the first node whose data is bigger than the new data
  newdata->prev = ptr->prev; //relink
  ptr->prev->next = newdata; //relink
  ptr->prev = newdata; //relink
  
  size++; 
}

template<typename T>
void DoublyLinkedList<T>::remove(const T& obj){
  node<T>* ptr = find(obj); //find the position of the node with given data
  if(ptr != dummy){ //kill it
    ptr->prev->next = ptr->next;//relink
    ptr->next->prev = ptr->prev; //relink
    delete ptr;
    size--;
  }
}
template<typename T>
void DoublyLinkedList<T>::remove(node<T>* ptr){
  if(ptr != dummy){  //kill it
    ptr->prev->next = ptr->next;//relink
    ptr->next->prev = ptr->prev;//relink
    delete ptr;
    size--;
  }
}
template<typename T>
node<T>* DoublyLinkedList<T>::find(const T& obj){ //find the node with the same data as the input
  node<T> *ptr = dummy->next;
  bool isFound = false;
  while(ptr != dummy && isFound == false){ //searching when not found or not achieving the dummy
    if(ptr->data == obj) isFound = true; //data is the same, found
    else ptr = ptr->next; //still not found, move to next
  }
  return ptr;
}

template<typename T>
node<T>* DoublyLinkedList<T>::find(const string& key){//find the node with the same key as the input
  node<T> *ptr = dummy->next;
  bool isFound = false;
  while(ptr != dummy && isFound == false){//searching when not found or not achieving the dummy
    if(ptr->data.getKey() == key) isFound = true;//data is the same, found
    else ptr = ptr->next;//still not found, move to next
  }
  return ptr;
}
template<typename T>
node<T>* DoublyLinkedList<T>::find(const string& pk,const string& sk){//find the node with the same two keys as the input
  node<T> *ptr = dummy->next;
  bool isFound = false;
  while(ptr != dummy && isFound == false){//searching when not found or not achieving the dummy
    if(ptr->data.getKey() == pk && ptr->data.getSubkey() == sk) isFound = true; //same, found
    else ptr = ptr->next;//still not found, move to next
  }
  return ptr;
}
template<typename T>
node<T>* DoublyLinkedList<T>::getOrigin()const{
  return dummy;
}

template<typename T>
int DoublyLinkedList<T>::getSize(){
  return size;
}
#endif
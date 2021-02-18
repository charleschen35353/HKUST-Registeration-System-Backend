#ifndef HASHTABLE_H
#define HASHTABLE_H
#include<math.h>
#include"DoublyLinkedList.h"
#include<iostream>
using namespace std;
template<typename T>
class HashTable{
  public:
    HashTable(int size); //create a hashtable with input number of buckets, but empty
    ~HashTable(); //delete all data in the hash table
    void clear(); //initialize all the data in the table
    void insertItem(T item); //insert the given item
    void deleteItem(T item); //remove the given item
    int Hash(string key, int bucket, int base); //hash function
    int getEleNum(); //get the number of elements stored in the list
    node<T>* search(string key); //search for the data with the key provided
    node<T>* search(string k1, string k2);//search for the data with keys provided
    node<T>* originPoint(); //get the dummy node point of the first linked list.
			    //search() functions returns the address of this point when not found
    DoublyLinkedList<T>& operator[](int num);//get the doublylinked list in the nth bucket
    DoublyLinkedList<T>& getListn(int num);//get the doublylinked list in the nth bucket
  private:
    DoublyLinkedList<T>* list;//a doublylinked list array
    int size;//buckets of the doublylinked array
    int count;//total elements count
};

template<typename T>
HashTable<T>::HashTable(int s):size(s),count(0){
    list = new DoublyLinkedList<T>[size]; //dynamic allocate a bucket for hashtable
}
template<typename T>
HashTable<T>::~HashTable(){ //delete all the data
    for(int i = 0 ; i < size ; i++)list[i].~DoublyLinkedList();
}
template<typename T>
void HashTable<T>::clear(){ //initialize the table
  for(int i = 0 ; i < size ; i++)list[i].initialize();
  count = 0;
}
template<typename T>
int HashTable<T>::Hash(string key, int bucket, int base){
  int size = key.length();
  long int sum = 0; //long in case of overflow
  for(int i = 0 ; i < size ; i ++){//if the ith char of key is numeric, use the number; otherwise use the char order + 10 
    ('0'<= key[i] && key[i] <='9')?( sum += (key[i]-'0')*(long int)(pow(base,i))% bucket ):( sum += (key[i]-'A'+11)*(long int)(pow(base,i))% bucket );
  }
  int index = 0;
  index += (sum % bucket);
  return index;
}

template<typename T>
node<T>* HashTable<T>::search(string key){
  node<T>* tmp = originPoint(); //starting point, return this if not found
  int base = ((size == 29)?(size-19):(size+19)); //if bucket is 29, base = 10 (for student). Bucket is 17, base is 36 (for course)
  if(list[Hash(key,size,base)].find(key) != list[Hash(key,size,base)].getOrigin()) // if the key is found
    tmp = list[Hash(key,size,base)].find(key); //found the data with input key
  
  return tmp;
}

template<typename T>
node<T>* HashTable<T>::search(string pk, string sk){//specially desgin for index
  node<T>* tmp = originPoint(); //starting point, return this if not found
  bool p = false;//false for student index true for course indx, used for find the exact data with the given primary key and sub keys
		 //student index: pk = ID, sk = code
		 //course index:pk = code, sk = ID
  int base = ((size == 29)?(size-19):(size+19));//if bucket is 29, base = 10 (for student). Bucket is 17, base is 36 (for course)
  
  if(list[Hash(pk,size,base)].find(pk) != list[Hash(pk,size,base)].getOrigin()){ //if the data with primary key is found 
    tmp = list[Hash(pk,size,base)].find(pk);
    
    (size == 29)?(p=false):(p=true);
    
    while(tmp->data.getSubkey(p)!= sk && tmp->next->data.getKey()== pk) tmp = tmp->next; //found the data whose code is the same as subkey 
    if(!(tmp->data.getKey() == pk && tmp->data.getSubkey(p) == sk)) tmp = originPoint();
 
  }
  return tmp;
}
template<typename T>
void HashTable<T>::insertItem(T item){
  int base = ((size == 29)?(size-19):(size+19));//if bucket is 29, base = 10 (for student). Bucket is 17, base is 36 (for course)
  list[Hash(item.getKey(),size,base)].insert(item);
  count++;
}

template<typename T>
void HashTable<T>::deleteItem(T item){
  int base = ((size == 29)?(size-19):(size+19));//if bucket is 29, base = 10 (for student). Bucket is 17, base is 36 (for course)
  list[Hash(item.getKey(),size,base)].remove(item);
  count--;
}

template<typename T>
node<T>* HashTable<T>::originPoint(){
  return (list[0].getOrigin());
}

template<typename T>
DoublyLinkedList<T>& HashTable<T>::operator[](int num){
  return list[num];
}
template<typename T>
DoublyLinkedList<T>& HashTable<T>::getListn(int num){
  return list[num];
}

template<typename T>
int HashTable<T>::getEleNum(){
  int sum = 0;
  for(int i = 0 ; i < size ; i ++){ //double check if the count in this class is equal to the sum of all lists'. (should be)
    sum += list[i].getSize();
  }
  if(sum != count){
    cout<<"Error: Numbers of elements not synchronized due to unknown reasons..."<<endl;
    cout<<"Please restart the programme..."<<endl;
    return -999;
  }
  return count;
}

#endif
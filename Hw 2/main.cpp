/*
* Student Name: Behlül Gülmez
* Student ID : 150140113
* Date: 22.4.2017
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#include"classes.h"

using namespace std;

int main() {
    
  AdderRemover *myList[4];

  myList[0] = new FAFR();
  myList[1] = new LALR();
  myList[2] = new FALR();
  myList[3] = new LAFR();
  
  for(int j=0; j<4; j++) {
    for(int i=0; i<5; i++) 
      myList[j]->add(i);
  }
  
  for(int j=0; j<4; j++){
    myList[j]->remove();
    myList[j]->display();
    myList[j]->removeAll();
    myList[j]->display();
  } 
  
  cout << endl << "Test case for ARTraverser"<< endl;
  for(int j=0; j<4; j++) {
    for(int i=0; i<5; i++) 
      myList[j]->add(i);
    myList[j]->remove();
  }
  
  for(int j=0; j<4; j++){
    myList[j]->setTraverser();
    myList[j]->traverse();
  }
  
  return 0;
}

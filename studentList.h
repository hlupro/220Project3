#ifndef STUDENTLINKEDLIST_H
#define STUDENTLINKEDLIST_H

#include "studentNode.h"

template <typename T>
class StudentList
{
private:
  StudentNode<T> *head;
  StudentNode<T> *end;
public:
  StudentList()
  {
    head = NULL;
    end = NULL;
  }
  void insertStudent(T value);
  void removeStudent(T value);
  void displayList();
  int getListSize();
  void sortList();
};
template <typename T>
void StudentList<T>::insertStudent(T value)
{
  StudentNode<T> *nodePtr;
  StudentNode<T> *newNode;
  newNode = new StudentNode<T>(value);
  std::cout << newNode->student.get_fullname() << std::endl;
  if(!head)
  {
    head = newNode;
    end = newNode;
  }
  else
  {
    nodePtr = head;
    while(nodePtr != NULL && nodePtr->student < value)
    {
      nodePtr = nodePtr->next;
    }
    if(nodePtr == head)
    {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
    else if(nodePtr)
    {
      newNode->prev = nodePtr->prev;
      newNode->prev->next = newNode;
      newNode->next = nodePtr;
      nodePtr->prev = newNode;
    }
    else
    {
      newNode->prev = end;
      newNode->next = NULL;
      end->next = newNode;
      end = newNode;
    }
  }
}

template <typename T>
void StudentList<T>::displayList()
{
  using namespace std;
  StudentNode<T> *nodePtr;
  nodePtr = head;
  while (nodePtr != NULL)
  {
    std::cout << "test" << std::endl;
    cout << nodePtr->student.get_fullname() << endl;
    cout << nodePtr->student.get_id() << endl;
    cout << nodePtr->student.get_gpa() << endl;
    cout << nodePtr->student.get_credits() << endl;
    cout << nodePtr->student.get_years() << endl;
  }
  cout << "" << endl;
}


#endif

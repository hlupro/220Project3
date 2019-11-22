#ifndef STUDENTLINKEDLIST_H
#define STUDENTLINKEDLIST_H

#include "studentNode.h"

template <typename T>
class StudentList
{
private:
  StudentList<T> *head;
  StudentList<T> *end;
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
};
template <typename T>
void StudentList<T>::insertStudent(T value)
{
  StudentNode<T> *nodePtr;
  StudentNode<T> *newNode;
  newNode = new StudentNode<T>(value);


}

#endif

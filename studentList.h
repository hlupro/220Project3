#ifndef STUDENTLINKEDLIST_H
#define STUDENTLINKEDLIST_H

#include "studentNode.h"
#include <iostream>

template <typename T>
class studentList
{
private:
  studentList<T> *head;
  studentList<T> *end;
public:
  studentList()
  {
    head = NULL;
    end = NULL;
  }
  void insertStudent(T value);
  void removeStudent(T value);
  void displayList();
  int getListSize();
};

#endif

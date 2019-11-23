#ifndef STUDENTNODE_H
#define STUDENTNODE_H

#include "student.h" //name is subject to change

template <typename T>
class StudentNode
{
public:
  StudentNode<T> *next; //Node pointer that points to the next node in the list
  StudentNode<T> *prev; //Node pointer that points to the prev node in the list
  T student;            //student will hold an object of type T, which in this case should be a student object.

  StudentNode()  //defualt constructor
  {
    next = NULL;
    prev = NULL;
    Student();
  }
  StudentNode(T value)
  {
    next = NULL;
    prev = NULL;
    student = Student(value);
  }                  //non-default constructor will take in two pointers
                     //order to insert a new node between them
                     //May have to include the list as a parameter Will need to test
};

#endif

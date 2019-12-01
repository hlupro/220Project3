// Kutter Aaron & Hunter Lupro
// studentNode.h
// Doubly linked node class


#ifndef STUDENTNODE_H
#define STUDENTNODE_H

#include "student.h" 

template <typename T>
class StudentNode
{
public:
	StudentNode<T>* next; //Node pointer that points to the next node in the list
	StudentNode<T>* prev; //Node pointer that points to the prev node in the list
	T student;            //student will hold an object of type T, which in this case should be a student object.

	StudentNode()  //default constructor
	{
		next = NULL;
		prev = NULL;
		Student();
	}
	StudentNode(T value) //constructor
	{
		next = NULL;
		prev = NULL;
		student = Student(value);
	}                  
};

#endif
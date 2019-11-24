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
  void searchStudent(string name);
  void swapNodes(StudentNode<T> *next , StudentNode<T> *current);
};
template <typename T>
void StudentList<T>::insertStudent(T value)
{
  StudentNode<T> *nodePtr;
  StudentNode<T> *newNode;
  newNode = new StudentNode<T>(value);
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
  cout << "==============================" << endl;
  cout << "Student Information Database" << endl;
  cout << "==============================" << endl;
  cout << "There are " << getListSize() << " Student(s) in the data base.\n" << endl;
  while (nodePtr != NULL)
  {
    nodePtr->student.display_info();
    cout << "" << endl;
    nodePtr = nodePtr->next;
  }
  std::cout << "The end of the list is " << end->student.get_fullname() << std::endl;
}

template <typename T>
void StudentList<T> :: swapNodes(StudentNode<T> *next, StudentNode<T> *current)
{
  if(current == head)
  {
    current->next = next->next;
    current->next->prev = current;
    next->prev = NULL;
    current->prev = next;
    next->next = current;
    head = next;
  }
  else if(next == end)
  {
    current->next = NULL;
    next->next = current;
    next->prev = current->prev;
    next->prev->next = next;
    current->prev = next;
    end = current;
  }
  else
  {
    next->prev = current->prev;
    next->prev->next = next;
    current->prev = next;
    current->next = next->next;
    current->next->prev = current;
    next->next = current;
  }
}

template <typename T>
int StudentList<T>:: getListSize()
{
  int size = 0;
  StudentNode<T> *nodePtr;
  nodePtr = head;
  while (nodePtr != NULL)
  {
    size++;
    nodePtr = nodePtr->next;
  }
  return size;
}

template <typename T>
void StudentList<T>:: searchStudent(string name)
{
  StudentNode<T> *nodePtr;
  bool found = false;
  nodePtr = head;
  while (nodePtr != NULL)
  {
    if (nodePtr->student.get_fullname() == name)
    {
      found = true;
      std::cout << "\nAccessing " << name << "'s profile and information." << std::endl;
      nodePtr->student.display_info();
      nodePtr->student.checkAcademic();
      std::cout << "" << std::endl;
    }
    nodePtr = nodePtr->next;
  }
  if (found == false)
  {
    std::cout << "\n" << name << " is not in the database." << std::endl;
    std::cout << "Going back to main menu...\n" << std::endl;
  }
}

template <typename T>
void StudentList<T> :: sortList()
{
  StudentNode<T> *nodePtr;
  StudentNode<T> *swapPtr;
  int order;
  string s1;
  string s2;
  std::cout << "Would you like to sort by first name or last name? (1 or 2)" << std::endl;
  cin >> order;
  if (order == 1)
  {
    std::cout << "Sort by first name selected!\n" << "Beginning Sort..." << std::endl;
    bool swap = false;
    do
    {
      nodePtr = head;
      swap = false;
      while(nodePtr->next != NULL)
      {
        if(nodePtr->next->student < nodePtr->student)
        {
          swapNodes(nodePtr->next, nodePtr);
          swap = true;
        }
        else
        {
          nodePtr = nodePtr->next;
        }
      }
    } while(swap == true);
  }
  if (order == 2)
  {
    std::cout << "Sort by last name selected!\n" << "Beginning Sort..." << std::endl;
    bool swap = false;
    do
    {
      nodePtr = head;
      swap = false;
      while(nodePtr->next != NULL)
      {
        if(nodePtr->next->student.get_lastname().compare(nodePtr->student.get_lastname()) < 0)
        {
          swapNodes(nodePtr->next, nodePtr);
          swap = true;
        }
        else
        {
        nodePtr = nodePtr->next;
        }
      }
    } while(swap == true);
  }
}

#endif

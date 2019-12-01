// Kutter Aaron & Hunter Lupro
// studentList.h
// Doubly linked class for student


#ifndef STUDENTLINKEDLIST_H
#define STUDENTLINKEDLIST_H

#include "studentNode.h"
#include <fstream>

template <typename T>
class StudentList
{
private:
	StudentNode<T>* head; //head of the list
	StudentNode<T>* end; //end of the list
public:
	StudentList() //default constructor
	{
		head = NULL;
		end = NULL;
	}
	void appendFront(T value); //appending front function
	void appendBack(T value); //appending back function
	void insertStudent(T value); //insert student function
	void removeStudent(string value); //remove student function
	void displayList(); //display list of students function
	int getListSize(); //get list size function
	void sortList(); //sort list function, choosing between 3 options
	void searchStudent(string name); //search for a specific student function
	void swapNodes(StudentNode<T>* next, StudentNode<T>* current); //swapping nodes (students) function
	void exportList(); //exports the list to a file 
};

template <typename T>
void StudentList<T>::appendFront(T value)   //appending front function definition
{
	StudentNode<T>* newNode;
	newNode = new StudentNode<T>;
	newNode->prev = NULL;
	newNode->student = value;

	if (head != NULL)
	{
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
	else
	{
		newNode->next = NULL;
		head = newNode;
		end = newNode;
	}
}

template <typename T>
void StudentList<T>::appendBack(T value) //appending back function definition
{
	StudentNode<T>* newNode;
	StudentNode<T>* nodePtr;

	newNode = new StudentNode<T>(value);

	if (!head)
	{
		std::cout << "TEST" << endl;
		head = newNode;
		head->prev = NULL;
		head->next = NULL;
		end = head;
	}
	else
	{
		nodePtr = head;
		while (nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}
		nodePtr->next = newNode;
		newNode->next = NULL;
		newNode->prev = nodePtr;
		end = newNode;
	}
}

template <typename T>
void StudentList<T>::removeStudent(string value) //remove student function definition
{
	StudentNode<T>* delNode;
	StudentNode<T>* nodePtr;
	if (!head)
	{
		return;
	}
	if (head == end && head->student.get_fullname().compare(value) == 0)
	{
		delete head;
		head = NULL;
		end = NULL;
		cout << "Database updated. " << value << " has been removed.\nGoing back to menu.\n" << endl;
	}
	else if (head->student.get_fullname().compare(value) == 0)
	{
		delNode = head;
		head = head->next;
		head->prev = NULL;
		delete delNode;
		cout << "Database updated. " << value << " has been removed.\nGoing back to menu.\n" << endl;
	}
	else if (end->student.get_fullname().compare(value) == 0)
	{
		delNode = end;
		end = end->prev;
		end->next = NULL;
		delete delNode;
		cout << "Database updated. " << value << " has been removed.\nGoing back to menu.\n" << endl;
	}
	else
	{
		nodePtr = head;
		while (nodePtr != NULL)
		{
			if (nodePtr->student.get_fullname().compare(value) == 0)
			{
				delNode = nodePtr;
				nodePtr->prev->next = nodePtr->next;
				nodePtr->next->prev = nodePtr->prev;
				nodePtr = nodePtr->next;
				delete delNode;
				cout << "Database updated. " << value << " has been removed.\nGoing back to menu.\n" << endl;
				return;
			}
			else
			{
				nodePtr = nodePtr->next;
			}
		}
		std::cout << value << " was not in the list and thus could not be deleted.\nGoing back to menu.\n" << std::endl;
	}
}

template <typename T>
void StudentList<T>::insertStudent(T value) //insert student function definition
{
	StudentNode<T>* nodePtr;
	StudentNode<T>* newNode;
	newNode = new StudentNode<T>(value);
	if (!head)
	{
		head = newNode;
		end = newNode;
	}
	else
	{
		nodePtr = head;
		while (nodePtr != NULL && nodePtr->student < value)
		{
			nodePtr = nodePtr->next;
		}
		if (nodePtr == head)
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		else if (nodePtr)
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
void StudentList<T>::displayList() //display list of students function definition
{
	using namespace std;
	StudentNode<T>* nodePtr;
	if (!head)
	{
		cout << "There is currnetly no Students in the Database." << endl;
	}
	else
	{
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
	}
}
template <typename T>
void StudentList<T>::swapNodes(StudentNode<T>* next, StudentNode<T>* current) //swapping nodes (students) function definition
{
	if (current == head)
	{
		current->next = next->next;
		current->next->prev = current;
		next->prev = NULL;
		current->prev = next;
		next->next = current;
		head = next;
	}
	else if (next == end)
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
int StudentList<T>::getListSize() //get list size function definition
{
	int size = 0;
	StudentNode<T>* nodePtr;
	if (!head)
	{
		return 0;
	}
	else
	{
		nodePtr = head;
		while (nodePtr != NULL)
		{
			size++;
			nodePtr = nodePtr->next;
		}
		return size;
	}
}
template <typename T>
void StudentList<T>::searchStudent(string name)  //search for a specific student function definition
{
	StudentNode<T>* nodePtr;
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
void StudentList<T> ::sortList() //sort list function, choosing between 3 options, definition
{
	StudentNode<T>* nodePtr;
	StudentNode<T>* swapPtr;
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
			while (nodePtr->next != NULL)
			{
				if (nodePtr->next->student < nodePtr->student)
				{
					swapNodes(nodePtr->next, nodePtr);
					swap = true;
				}
				else
				{
					nodePtr = nodePtr->next;
				}
			}
		} while (swap == true);
	}
	if (order == 2)
	{
		std::cout << "Sort by last name selected!\n" << "Beginning Sort..." << std::endl;
		bool swap = false;
		do
		{
			nodePtr = head;
			swap = false;
			while (nodePtr->next != NULL)
			{
				if (nodePtr->next->student.get_lastname().compare(nodePtr->student.get_lastname()) < 0)
				{
					swapNodes(nodePtr->next, nodePtr);
					swap = true;
				}
				else
				{
					nodePtr = nodePtr->next;
				}
			}
		} while (swap == true);
	}
}

template <typename T>
void StudentList<T>::exportList() //export list function definition
{
	using namespace std;
	StudentNode<T>* nodePtr;
	ofstream outFile;
	outFile.open("output.txt", ios::out);
	if (outFile.fail())
	{
		cout << "File could not be created." << endl;
		return;
	}
	if (!head)
	{
		cout << "There are no students in the database to export." << endl;
		return;
	}
	else
	{
		nodePtr = head;
		while (nodePtr)
		{
			outFile << "Name: " << nodePtr->student.get_fullname() << endl;
			outFile << "ID: " << nodePtr->student.get_id() << endl;
			outFile << "Credits: " << nodePtr->student.get_credits() << endl;
			outFile << "Years in school: " << nodePtr->student.get_years() << endl;
			outFile << "GPA: " << nodePtr->student.get_gpa() << "\n" << endl;
			nodePtr = nodePtr->next;
		}
		cout << "Export complete.\nGoing back to menu.\n" << endl;
		outFile.close();
	}
}
#endif
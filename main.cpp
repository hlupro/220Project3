// Kutter Aaron & Hunter Lupro
// main.cpp
// Main program

#include "studentList.h"
#include <fstream>

void displayMenu();
StudentList<Student> readFile(StudentList<Student> list);

int main()
{
	string first, last;
	int id, credits, years, num;
	float gpa;
	char quit = 'z';

	std::cout << "\nWelcome to Kutter and Hunter's Student Information Database!" << std::endl;
	std::cout << "Now uploading student profiles from a file." << std::endl;
	StudentList<Student> list;
	list = readFile(list);
	list.displayList(); //displays list
	while (quit != 'Q')
	{
		using namespace std;
		cout << "Please choose an option from the menu." << endl;
		displayMenu(); //displays menu
		cin >> quit;

		switch (quit)
		{
		case 'V': //If chosen, displays the entire database
			cout << "\nAccessing Student Information Database." << endl;
			list.displayList();
			break;
		case 'F': //If chosen, allows you to look up a student
		{
			cout << "\nPlease enter the fullname of the student you would like to look up." << std::endl;
			cin.ignore();
			string name;
			getline(cin, name);
			list.searchStudent(name);
			break;
		}
		case 'S': //If chosen, sorts the database
			list.sortList();
			break;
		case 'A': //If chosen, allows the user to create information for a student
		{
			cout << "\nEnter the first name of the student." << endl;
			cin >> first;
			cout << "Enter the last name of the Student." << endl;
			cin >> last;
			cout << "Enter the student's ID number." << endl;
			cin >> id;
			cout << "Enter number of years the student has been in school." << endl;
			cin >> years;
			cout << "Enter the number of credits the student has." << endl;
			cin >> credits;
			cout << "Enter the student's GPA." << endl;
			cin >> gpa;
			Student newStudent(first, last, id, credits, years, gpa);
			cout << "Which way do you want the student inserted into the list?" << endl;
			cout << "(1. At the front. 2. At the back. 3. In order)" << endl;
			cin >> num;
			if (num == 1)
			{
				list.appendFront(newStudent);
				cout << "Student Successfully inserted.\nGoing back to menu.\n" << endl;
			}
			else if (num == 2)
			{
				list.appendBack(newStudent);
				cout << "Student Successfully inserted.\nGoing back to menu.\n" << endl;
			}
			else if (num == 3)
			{
				cout << "Making sure the database is sorted before insertion..." << endl;
				list.sortList();
				list.insertStudent(newStudent);
				cout << "Student Successfully inserted.\nGoing back to menu.\n" << endl;
			}
			else
			{
				cout << "Did not specify which way to insert correctly.\nGoing back to menu.\n" << endl;
			}
			break;
		}
		case 'D': //If chosen, allows the user to delete a student based on their full name
		{
			cout << "\nEnter the name of the student you want to delete." << std::endl;
			cin.ignore();
			string delName;
			getline(cin, delName);
			list.removeStudent(delName);
			break;
		}
		case 'E': //If chosen, exports the data to a new file for the user to keep
			cout << "Exporting database to a new file..." << endl;
			list.exportList();
			break;
		case 'Q': //If chosen, the program will quit
			cout << "\nYou are now quiting the program." << endl;
			break;
		default: //Only appears when nothing above is chosen
			cout << "\nError, no useable input given!" << endl;
			break;
		}
	}
};

void displayMenu() //displays the selection menu
{
	using namespace std;
	cout << "=================================" << endl;
	cout << "Student Information Database Menu" << endl;
	cout << "=================================" << endl;
	cout << "V - View Student Information Database" << endl;
	cout << "F - Find Student Information by Student" << endl;
	cout << "S - Sort Student" << endl;
	cout << "A - Add a Student" << endl;
	cout << "D - Delete a Student" << endl;
	cout << "E - Export list to new file." << endl;
	cout << "Q - Quit the Program" << endl;
	cout << "=================================" << endl;
}

StudentList<Student> readFile(StudentList<Student> list) //reads data from the database.txt file
{
	int yr;
	string first;
	string last;
	int num = 0;
	float points = 0;
	int cred = 0;
	ifstream inputFile;
	std::cout << "Now reading from file..." << std::endl;
	inputFile.open("database.txt");
	while (inputFile >> first >> last >> num >> cred >> yr >> points)
	{
		Student newStudent(first, last, num, cred, yr, points);
		list.insertStudent(newStudent);
	}
	std::cout << "All students uploaded, now closing file...\n" << std::endl;
	inputFile.close();
	return list;
}
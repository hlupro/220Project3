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
	list.displayList();
	while (quit != 'Q')
	{
		using namespace std;
		cout << "Please choose an option from the menu." << endl;
		displayMenu();
		cin >> quit;

		switch (quit)
		{
		case 'V':
			cout << "\nAccessing Student Information Database." << endl;
			list.displayList();
			break;
		case 'F':
		{
			cout << "\nPlease enter the fullname of the student you would like to look up." << std::endl;
			cin.ignore();
			string name;
			getline(cin, name);
			list.searchStudent(name);
			break;
		}
		case 'S':
			list.sortList();
			break;
		case 'A':
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
			if(num == 1)
			{
				list.appendFront(newStudent);
				cout << "Student Successfully inserted.\nGoing back to menu.\n" << endl;
			}
			else if(num == 2)
			{
				list.appendBack(newStudent);
				cout << "Student Successfully inserted.\nGoing back to menu.\n" << endl;
			}
			else if(num == 3)
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
		case 'D':
		{
			cout << "\nEnter the name of the student you want to delete." << std::endl;
			cin.ignore();
			string delName;
			getline(cin, delName);
			list.removeStudent(delName);
			break;
		}
		case 'E':
			cout << "Exporting database to a new file..." << endl;
			list.exportList();
			break;
		case 'Q':
			cout << "\nYou are now quiting the program." << endl;
			break;
		default:
			cout << "\nError, no useable input given!" << endl;
			break;
		}
	}
};

void displayMenu()
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

StudentList<Student> readFile(StudentList<Student> list)
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

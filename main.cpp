#include "studentList.h"
#include <fstream>

void displayMenu();
StudentList<Student> readFile(StudentList<Student> list);

int main()
{
	char quit = 'z';
	std::cout << "Welcome to Kutter and Hunter's Student Information Database!" << std::endl;
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
			cout << "Please enter the fullname of the student you would like to look up." << std::endl;
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
			cout << "You are now adding a student" << endl;
			// Use insert node function
			break;
		case 'D':
		{
			cout << "You are now deleting a student." << endl;
			cout << "Enter the name of the student you want to delete." << std::endl;
			cin.ignore();
			string delName;
			getline(cin, delName);
			list.removeStudent(delName);
			break;
		}
		case 'Q':
			cout << "You are now quiting the program." << endl;
			break;
		default:
			cout << "Error, no useable input given!" << endl;
			break;
		}
	}
};

void displayMenu()
{
	using namespace std;
	cout << "==============================" << endl;
	cout << "Student Information Database Menu" << endl;
	cout << "==============================" << endl;
	cout << "V - View Student Information Database" << endl;
	cout << "F - Find Student Information by Student" << endl;
	cout << "S - Sort Student" << endl;
	cout << "A - Add a Student" << endl;
	cout << "D - Delete a Student" << endl;
	cout << "Q - Quit the Program" << endl;
	cout << "==============================" << endl;
}

StudentList<Student> readFile(StudentList<Student> list)
{
	int yr;
	string first;
	string last;
	int num = 0;
	float points = 0;
	int cred = 0;
	fstream inputFile;
	std::cout << "Now reading from file..." << std::endl;
	inputFile.open("database.txt", ios::in);
	while (inputFile >> first >> last >> num >> cred >> yr >> points)
	{
		Student newStudent(first, last, num, cred, yr, points);
		list.insertStudent(newStudent);
	}
	std::cout << "All students uploaded, now closing file...\n" << std::endl;
	inputFile.close();
	return list;
}
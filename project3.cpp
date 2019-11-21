#include <iostream>
#include "student.h"
using namespace std;

int main()
{
  cout << "------------------------------" << endl;
  cout << "------------------------------" << endl;
  cout << "Student Information Database Menu" << endl;
  cout << "------------------------------" << endl;
  cout << "------------------------------" << endl;
  cout << "V - View Student Information Database" << endl;
  cout << "F - Find Student Information by Student" << endl;
  cout << "S - Sort Student" << endl;
  cout << "A - Add a Student" << endl;
  cout << "D - Delete a Student" << endl;
  cout << "Q - Quit the Program" << endl;
  cout << "------------------------------" << endl;
  cout << "------------------------------" << endl;

  char keyChoice;

  cout << "Enter a key: ";
  cin >> keyChoice;
  switch(keyChoice)
    {
    case 'V':
      cout << "You are now viewing the student information database." << endl;
      // Display the database
      break;
    case 'F':
      cout << "You are now finding student information by student." << endl;
      // Use search node function
      break;
    case 'S':
      cout << "You are now sorting the students." << endl;
      // Use sort node function 
      break;
    case 'A':
      cout << "You are now adding a student" << endl;
      // Use insert node function
      break;
    case 'D':
      cout << "You are now deleting a student." << endl;
      // Use delete node function
      break;
    case 'Q':
      cout << "You are now quiting the program." << endl;
      break;
    default:
      cout << "Error, no useable input given!" << endl;
      break;
     }


}

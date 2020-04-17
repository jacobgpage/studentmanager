#include <stdio.h>
#include <map>
#include <algorithm>
#include "student.h"

using namespace std;

bool compareSudents ( pair< string, Student > s1, pair< string, Student > s2 ) {
	
	if ( s1.second.getLastName() > s2.second.getLastName() ) {
		
		return true;
	
	} else {
		
		return false;
		
	}
	
}

int main() {
	
	bool continueLoop = true;
	
	string firstNames[10] = { "Jacob", "Ethan", "Phillip", "Sarah", "Diann", "Alexis", "Daniel", "Landon", "Josh", "Maddie" };
	string lastNames[10] = { "Smith", "Boyd", "Lee", "Ward", "Bradbury", "Wong", "Ying", "Harris", "Gilbert", "Grace" };
	string studentIds[10] = { "jsmith", "eboyd", "plee", "sward", "dbradbury", "awong", "dying", "lharris", "jgilbert", "mgrace" };
	
	double GPA[10] = { 4.0, 2.6, 3.7, 1.3, 0.1, 3.4, 2.5, 4.0, 1.4, 2.3 };
	
	map< string, Student, DescendingOrder > studentsMap;
	map< string, Student >::iterator studentIt;
	
	for ( int i = 0; i < 10; i++ ) { //Reads data into the map
		
		Student student;
		
		student.setFirstName( firstNames[ i ] );
		student.setLastName( lastNames[ i ] );
		student.setGPA( GPA[ i ] );
		
		studentsMap.insert( { studentIds[ i ], student } );
		
	}
	
	cout << "Hello!" << endl << endl;
	
	map< string, Student >::iterator end = studentsMap.end();
	
	pair< string, Student > minName = *min_element( studentsMap.begin(), studentsMap.end(), compareSudents ); 
	
	cout << "Student with Min Lastname" << endl;
	cout << "ID: " << minName.first << endl;
	cout << "First: " << minName.second.getFirstName() << endl;
	cout << "Last: " << minName.second.getLastName() << endl;
	cout << "GPA: " << minName.second.getGPA() << endl;
	cout << endl;
	
	studentIt = studentsMap.begin();
	end = studentsMap.end();
	
	while ( studentIt != end ) { //Prints out the user ID's in order
		
		cout << studentIt->first << endl;
		
		++studentIt;
	
	}
	
	cout << endl;
	string input = "";
	
	while ( continueLoop ) { //Searches for IDs until the user inputs a 0
		
		cout << "Input a student ID to find a user otherwise type 0 to end: ";
		cin >> input;
		
		cout << endl;
		
		if ( input != "0" ) {
			
			studentIt = studentsMap.find( input );

			if ( studentIt == studentsMap.end() ) {
				
				cout << "There is no student with that ID!" << endl;
				cout << endl;
				
			} else {
				
				cout << "Student Id: " << studentIt->first << endl;
				cout << "First Name: " << studentIt->second.getFirstName() << endl;
				cout << "Last Name: " << studentIt->second.getLastName() << endl;
				cout << "GPA: " << studentIt->second.getGPA() << endl;
				
			}
			
		} else {
			
			continueLoop = false;
			
		}
		
	}
	
	cout << "Goodbye and thank you for using our software!" << endl;
	
	return (0);
	
}

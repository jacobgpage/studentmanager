#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string.h>

using namespace std;

class Student {

	private:	
		string firstName;
		string lastName;
		
		double GPA;
	
	public:
		Student();
		Student( const Student& );
		
		//Accessor functions
		string getFirstName() const { return firstName; }
		string getLastName() const { return lastName; }
		int getGPA() const { return GPA; }
		
		//Mutator functions
		void setFirstName( string s ) { firstName = s; }
		void setLastName( string s ) { lastName = s; }
		void setGPA( int i ) { GPA = i; }
	
		friend class DescendingOrder;
		
};

Student::Student() {
	
	setFirstName( "" );
	setLastName( "" );
	setGPA( 0 );
	
}

Student::Student( const Student& s ) {
	
	firstName = s.firstName;
	lastName = s.lastName;
	GPA = s.GPA;
	
}

class DescendingOrder {
	
	public:
		bool operator() ( string s1, string s2 ) { return s1 < s2; }
	
};

#endif
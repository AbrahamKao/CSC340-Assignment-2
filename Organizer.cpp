// TO DO: #include needed standard libraries and your own libraries here
#include <iostream>
#include <string>
#include "Organizer.h"

using std::cout;
using std::endl;

// TO DO: function implementations
void Orgainizer::displayProfile() const{
	cout<< "Username: " << username << endl
	<<"Email: " << email << endl
	<<"Bio: " << bio << endl
	<<"Profile Picture: "<< profilePicture << endl

}

bool Organizer :: changePassword () const{
	if(newPW.empty()) return false;
	password = newPw;
	return true
}

// Operator == overloading implementation
bool Organizer::operator==(const Organizer& otherOrganizer) const {
	return (Organizer::username == otherOrganizer.username) && (Organizer::email == otherOrganizer.email);
}

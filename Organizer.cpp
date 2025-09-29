// TO DO: #include needed standard libraries and your own libraries here

// TO DO: function implementations

// Operator == overloading implementation
bool Organizer::operator==(const Organizer& otherOrganizer) const {
	return (Organizer::username == otherOrganizer.username) && (Organizer::email == otherOrganizer.email);
}

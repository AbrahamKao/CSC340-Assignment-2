// TO DO: #include all the standard libraries and your own libraries here
#include "Event.h"
#include <iostream>
// TO DO: function implementations

// Constructor implementations, when the object is created, the constructor is alled, intialzing data members
Event::Event(const std::string& name, 
	         const std::string& description, 
			 int rating)
		:name(name), 
		description(description), 
		rating(rating)
		soldTicketsCount(0) {} 

		//getters/accessor methods that provide read access
std::string Event::getName() const 
{return name;}
std::string Event::getDescription() const 
{return description;}
int Event::getRating() const
{return rating;}
int Event::getSoldTicketsCount() const
{return soldTicketsCount;}

  //prints the event details to the console
void Event::display() const {
	std::cout << "Event Name: " << name << std::endl;
	std::cout << "Description: " << description << std::endl;
	std::cout << "Rating: " << rating << std::endl;
	std::cout << "Tickets Sold: " << soldTicketsCount << std::endl;
}
// ------------------------------------------------------------------------------
// Operator overloading implementation
bool Event::operator==(const Event& otherEvent) const {
	return Event::name == otherEvent.name;
}





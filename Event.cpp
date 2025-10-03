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
		rating(rating),
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

// Modify method implementation
bool Event::modify(const std::string& newName, const std::string& newDescription) {
    name = newName;
    description = newDescription;
    return true;
}

// ------------------------------------------------------------------------------
// Operator overloading implementation
bool Event::operator==(const Event& otherEvent) const {
	return Event::name == otherEvent.name;
}

// VirtualEvent constructor
VirtualEvent::VirtualEvent(const std::string& name,
                           const std::string& description,
                           int rating,
                           const std::string& streamLink,
                           const std::string& audience)
    : Event(name, description, rating), streamLink(streamLink), audience(audience) {}

// VirtualEvent display method
void VirtualEvent::display() const {
    Event::display();
    std::cout << "Stream Link: " << streamLink << std::endl;
    std::cout << "Audience: " << audience << std::endl;
}

// VirtualEvent sell method
bool VirtualEvent::sell(int quantity) {
    if (quantity > 0) {
        soldTicketsCount += quantity;
        return true;
    }
    return false;
}

// VenueEvent constructor
VenueEvent::VenueEvent(const std::string& name,
                       const std::string& description,
                       int rating,
                       const std::string& venue,
                       const std::string& dateTime,
                       int capacity)
    : Event(name, description, rating), venue(venue), dateTime(dateTime), capacity(capacity) {}

// VenueEvent display method
void VenueEvent::display() const {
    Event::display();
    std::cout << "Venue: " << venue << std::endl;
    std::cout << "Date/Time: " << dateTime << std::endl;
    std::cout << "Capacity: " << capacity << std::endl;
}

// VenueEvent sell method
bool VenueEvent::sell(int quantity) {
    if (quantity > 0 && (soldTicketsCount + quantity) <= capacity) {
        soldTicketsCount += quantity;
        return true;
    }
    return false;
}





#include "Event.h"
#include <iostream>
Event::Event(const std::string& name, 
	         const std::string& description, 
			 int rating)
		:name(name), 
		description(description), 
		rating(rating),
		soldTicketsCount(0) {} 

std::string Event::getName() const 
{return name;}
std::string Event::getDescription() const 
{return description;}
int Event::getRating() const
{return rating;}
int Event::getSoldTicketsCount() const
{return soldTicketsCount;}

void Event::display() const {
	std::cout << "Event Name: " << name << std::endl;
	std::cout << "Description: " << description << std::endl;
	std::cout << "Rating: " << rating << std::endl;
	std::cout << "Tickets Sold: " << soldTicketsCount << std::endl;
}

bool Event::modify(const std::string& newName, const std::string& newDescription) {
    name = newName;
    description = newDescription;
    return true;
}

bool Event::operator==(const Event& otherEvent) const {
	return Event::name == otherEvent.name;
}

VirtualEvent::VirtualEvent(const std::string& name,
                           const std::string& description,
                           int rating,
                           const std::string& streamLink,
                           const std::string& audience)
    : Event(name, description, rating), streamLink(streamLink), audience(audience) {}

void VirtualEvent::display() const {
    Event::display();
    std::cout << "Stream Link: " << streamLink << std::endl;
    std::cout << "Audience: " << audience << std::endl;
}

bool VirtualEvent::sell(int quantity) {
    if (quantity > 0) {
        soldTicketsCount += quantity;
        return true;
    }
    return false;
}

VenueEvent::VenueEvent(const std::string& name,
                       const std::string& description,
                       int rating,
                       const std::string& venue,
                       const std::string& dateTime,
                       int capacity)
    : Event(name, description, rating), venue(venue), dateTime(dateTime), capacity(capacity) {}

void VenueEvent::display() const {
    Event::display();
    std::cout << "Venue: " << venue << std::endl;
    std::cout << "Date/Time: " << dateTime << std::endl;
    std::cout << "Capacity: " << capacity << std::endl;
}

bool VenueEvent::sell(int quantity) {
    if (quantity > 0 && (soldTicketsCount + quantity) <= capacity) {
        soldTicketsCount += quantity;
        return true;
    }
    return false;
}





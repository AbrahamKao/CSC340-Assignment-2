#include "Event.h"
#include <iostream>
#include <iomanip>

// Constructor implementations, when the object is created, the constructor is called, initializing data members
Event::Event(const std::string& name, 
             const std::string& description, 
             int rating)
    : name(name), 
      description(description), 
      rating(rating),
      soldTicketsCount(0) {} 

// Getters/accessor methods that provide read access
std::string Event::getName() const {
    return name;
}

std::string Event::getDescription() const {
    return description;
}

int Event::getRating() const {
    return rating;
}

int Event::getSoldTicketsCount() const {
    return soldTicketsCount;
}

// Prints the event details to the console
void Event::display() const {
    std::cout << "Event Name: " << name << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Rating: " << rating << std::endl;
    std::cout << "Tickets Sold: " << soldTicketsCount << std::endl;
}

// Modify event details
bool Event::modify(const std::string& newName, const std::string& newDescription) {
    if (newName.empty() && newDescription.empty()) {
        return false;
    }
    
    if (!newName.empty()) {
        name = newName;
    }
    
    if (!newDescription.empty()) {
        description = newDescription;
    }
    
    return true;
}

// Operator overloading implementation
bool Event::operator==(const Event& otherEvent) const {
    return name == otherEvent.name;
}

// VirtualEvent constructor
VirtualEvent::VirtualEvent(const std::string& name,
                           const std::string& description,
                           int rating,
                           const std::string& streamLink,
                           const std::string& audience)
    : Event(name, description, rating), streamLink(streamLink), audience(audience) {}

// VirtualEvent display implementation
void VirtualEvent::display() const {
    Event::display(); // Call base class display
    std::cout << "Stream Link: " << streamLink << std::endl;
    std::cout << "Audience: " << audience << std::endl;
}

// VirtualEvent sell implementation
bool VirtualEvent::sell(int quantity) {
    if (quantity <= 0) {
        return false;
    }
    soldTicketsCount += quantity;
    return true;
}

// VenueEvent constructor
VenueEvent::VenueEvent(const std::string& name,
                       const std::string& description,
                       int rating,
                       const std::string& venue,
                       const std::string& dateTime,
                       int capacity)
    : Event(name, description, rating), venue(venue), dateTime(dateTime), capacity(capacity) {}

// VenueEvent display implementation
void VenueEvent::display() const {
    Event::display(); // Call base class display
    std::cout << "Venue: " << venue << std::endl;
    std::cout << "Date/Time: " << dateTime << std::endl;
    std::cout << "Capacity: " << capacity << std::endl;
}

// VenueEvent sell implementation
bool VenueEvent::sell(int quantity) {
    if (quantity <= 0 || (soldTicketsCount + quantity) > capacity) {
        return false;
    }
    soldTicketsCount += quantity;
    return true;
}





#include "EventTicket340.h"
#include <iostream>
#include <string>

// Default constructor
EventTicket340::EventTicket340() {}

// Destructor
EventTicket340::~EventTicket340() {}

// Create organizer method implementation
void EventTicket340::createOrganizer(const std::string& username, 
                                     const std::string& email, 
                                     const std::string& password, 
                                     const std::string& bio, 
                                     const std::string& profilePicture) {
    organizer = Organizer(username, email, password, bio, profilePicture);
}

// Get organizer method implementation
Organizer EventTicket340::getOrganizer() const {
    return organizer;
}
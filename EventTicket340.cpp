#include "EventTicket340.h"
#include <iostream>
#include <string>

EventTicket340::EventTicket340() {}

EventTicket340::~EventTicket340() {}

void EventTicket340::createOrganizer(const std::string& username, 
                                     const std::string& email, 
                                     const std::string& password, 
                                     const std::string& bio, 
                                     const std::string& profilePicture) {
    organizer = Organizer(username, email, password, bio, profilePicture);
}

Organizer EventTicket340::getOrganizer() const {
    return organizer;
}
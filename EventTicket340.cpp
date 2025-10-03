// TO DO: Implementation of EventTicket340 functions
#include <iostream>
#include <string>
#include "EventTicket340.h"

EventTicket340::EventTicket340() = default;
EventTicket340::~EventTicket340() = default;

void EventTicket340::createOrganizer(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture){
    organizer = Organizer(username, email, password, bio, profilePicture);
}

Organizer EventTicket340::getOrganizer() const{
    return organizer;
}
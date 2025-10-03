#ifndef EVENTTICKET340_H
#define EVENTTICKET340_H

#include <string>
#include "Organizer.h"

class EventTicket340 {
private:
    Organizer organizer;

public:
    EventTicket340();
    ~EventTicket340();

    void createOrganizer(const std::string& username,
                         const std::string& email,
                         const std::string& password,
                         const std::string& bio,
                         const std::string& profilePicture);

    Organizer getOrganizer() const; 
};

#endif
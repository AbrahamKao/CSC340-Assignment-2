#ifndef ORGANIZER_H
#define ORGANIZER_H

#include <string>
#include "LinkedBagDS/LinkedBag.h"
#include "Event.h"
#include <memory>

class Organizer {
private:
    std::string username;
    std::string email;
    std::string password;
    std::string bio;
    std::string profilePicture;
    LinkedBag<std::shared_ptr<Event>> events; 

public:
    Organizer() = default;
    
    Organizer(const std::string& username,
              const std::string& email,
              const std::string& password,
              const std::string& bio,
              const std::string& profilePicture);
    
    
    void displayProfile() const;
    bool modifyPassword(const std::string& newPassword);
    bool createEvent(const std::shared_ptr<Event>& event);
    void displayAllEvents() const;
    std::shared_ptr<Event> modifyEvent(int k);
    bool sellTicket(int k, int quantity);
    bool deleteEvent(int k);
    
    std::string getUsername() const;
    std::string getEmail() const;
    std::string getBio() const;
    std::string getProfilePicture() const;
    
    int getEventCount() const;
    
    bool operator==(const Organizer& otherOrganizer) const;
    
    ~Organizer();
};

#endif
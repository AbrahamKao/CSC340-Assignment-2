#include "LinkedBagDS/LinkedBag.h"
#include <string>
#include "Organizer.h"
// TO DO include necessary libraries

 

// This class only contains a single organizer
class EventTicket340 {
private:
    Organizer organizer;

public:
    EventTicket340() = default;
    ~EventTicket340() = default;

    void createOrganizer(const std::string& username,
                         const std::string& email,
                         const std::string& password,
                         const std::string& bio,
                         const std::string& profilePicture) {
        organizer = Organizer(username, email, password, bio, profilePicture);
    }

    Organizer getOrganizer() const { return organizer; }
};
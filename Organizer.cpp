#include "Organizer.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;

// Parameterized constructor implementation
Organizer::Organizer(const std::string& username,
                     const std::string& email,
                     const std::string& password,
                     const std::string& bio,
                     const std::string& profilePicture)
    : username(username), email(email), password(password), 
      bio(bio), profilePicture(profilePicture) {}

// Destructor to clean up dynamically allocated events
Organizer::~Organizer() {
    std::vector<Event*> eventList = events.toVector();
    for (Event* event : eventList) {
        delete event;
    }
}

// Accessor methods (getters)
std::string Organizer::getUsername() const {
    return username;
}

std::string Organizer::getEmail() const {
    return email;
}

std::string Organizer::getBio() const {
    return bio;
}

std::string Organizer::getProfilePicture() const {
    return profilePicture;
}

// Display profile method implementation (as per UML)
void Organizer::displayProfile() const {
    cout << "Username: " << username << endl
         << "Email: " << email << endl
         << "Bio: " << bio << endl
         << "Profile Picture: " << profilePicture << endl;
}

// Modify password method implementation (as per UML)
bool Organizer::modifyPassword(const std::string& newPassword) {
    if (newPassword.empty()) {
        return false;
    }
    password = newPassword;
    return true;
}

// Create event method implementation (as per UML)
bool Organizer::createEvent(Event* event) {
    if (event == nullptr) {
        return false;
    }
    return events.add(event);
}

// Display all events method implementation (as per UML)
void Organizer::displayAllEvents() const {
    if (events.isEmpty()) {
        cout << "No events found." << endl;
        return;
    }
    
    std::vector<Event*> eventList = events.toVector();
    cout << "Total events: " << eventList.size() << endl;
    
    for (size_t i = 0; i < eventList.size(); ++i) {
        cout << "\n--- Event " << (i + 1) << " ---" << endl;
        if (eventList[i] != nullptr) {
            eventList[i]->display();
        }
    }
}

// Modify event method implementation (as per UML)
Event* Organizer::modifyEvent(int k) {
    Node<Event*>* node = events.findKthItem(k);
    if (node != nullptr) {
        return node->getItem();
    }
    return nullptr;
}

// Sell ticket method implementation (as per UML)
bool Organizer::sellTicket(int k, int quantity) {
    Node<Event*>* node = events.findKthItem(k);
    if (node != nullptr && node->getItem() != nullptr) {
        return node->getItem()->sell(quantity);
    }
    return false;
}

// Delete event method implementation (as per UML)
bool Organizer::deleteEvent(int k) {
    Node<Event*>* node = events.findKthItem(k);
    if (node != nullptr && node->getItem() != nullptr) {
        Event* eventToDelete = node->getItem();
        bool removed = events.remove(eventToDelete);
        if (removed) {
            delete eventToDelete; // Clean up memory
        }
        return removed;
    }
    return false;
}

// Get event count helper method
int Organizer::getEventCount() const {
    return events.getCurrentSize();
}

// Operator == overloading implementation
bool Organizer::operator==(const Organizer& otherOrganizer) const {
    return (username == otherOrganizer.username) && (email == otherOrganizer.email);
}

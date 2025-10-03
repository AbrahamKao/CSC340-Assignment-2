#include "Organizer.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;

Organizer::Organizer(const std::string& username,
                     const std::string& email,
                     const std::string& password,
                     const std::string& bio,
                     const std::string& profilePicture)
    : username(username), email(email), password(password), 
      bio(bio), profilePicture(profilePicture) {}

Organizer::~Organizer() {
    std::vector<Event*> eventList = events.toVector();
    for (Event* event : eventList) {
        delete event;
    }
}

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

void Organizer::displayProfile() const {
    cout << "Username: " << username << endl
         << "Email: " << email << endl
         << "Bio: " << bio << endl
         << "Profile Picture: " << profilePicture << endl;
}

bool Organizer::modifyPassword(const std::string& newPassword) {
    if (newPassword.empty()) {
        return false;
    }
    password = newPassword;
    return true;
}

bool Organizer::createEvent(Event* event) {
    if (event == nullptr) {
        return false;
    }
    return events.add(event);
}

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

Event* Organizer::modifyEvent(int k) {
    Node<Event*>* node = events.findKthItem(k);
    if (node != nullptr) {
        return node->getItem();
    }
    return nullptr;
}

bool Organizer::sellTicket(int k, int quantity) {
    Node<Event*>* node = events.findKthItem(k);
    if (node != nullptr && node->getItem() != nullptr) {
        return node->getItem()->sell(quantity);
    }
    return false;
}

bool Organizer::deleteEvent(int k) {
    Node<Event*>* node = events.findKthItem(k);
    if (node != nullptr && node->getItem() != nullptr) {
        Event* eventToDelete = node->getItem();
        bool removed = events.remove(eventToDelete);
        if (removed) {
            delete eventToDelete;
        }
        return removed;
    }
    return false;
}

int Organizer::getEventCount() const {
    return events.getCurrentSize();
}

bool Organizer::operator==(const Organizer& otherOrganizer) const {
    return (username == otherOrganizer.username) && (email == otherOrganizer.email);
}

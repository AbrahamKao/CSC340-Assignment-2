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

bool Organizer::createEvent(const std::shared_ptr<Event>& event) {
    if (!event)return false;
    return events.add(event);
}

void Organizer::displayAllEvents() const {
    if (events.isEmpty()) {
        cout << "No events found." << endl;
        return;
    }
    
    auto vec = events.toVector();
    cout << "Total events: " << vec.size() << endl;
    
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << "\n--- Event " << (i + 1) << " ---" << endl;
        if (vec[i]) vec[i]->display();
    }
}

std::shared_ptr<Event> Organizer::modifyEvent(int k) {
    auto node = events.findKthItem(k);
    return node ? node->getItem() : std::shared_ptr<Event>();
}

bool Organizer::sellTicket(int k, int quantity) {
    auto node = events.findKthItem(k);
    return (node && node->getItem()) ? node-> getItem()->sell(quantity) : false;
}

bool Organizer::deleteEvent(int k) {
    auto node = events.findKthItem(k);
    if (node && node->getItem()) {
        auto e = node->getItem();
        return events.remove(e);
    }
    return false;
}

int Organizer::getEventCount() const {
    return events.getCurrentSize();
}

bool Organizer::operator==(const Organizer& otherOrganizer) const {
    return (username == otherOrganizer.username) && (email == otherOrganizer.email);
}

std::ostream& operator<<(std::ostream& out, const Organizer& o){
    out << "Username: "  << o.username << '\n'
        << "Email: " << o.email << '\n'
        << "Bio: " << o.bio << '\n'
        << "Profile Picture: " << o.profilePicture << '\n';
    return out;
}

static void newLine(std::istream& in){
    if (in.peek() == '\n') 
        in.get();
}

std::istream& operator>>(std::istream& in, Organizer& o){
    std::string username, email, password, bio, profilePicture;
    
    std::getline(in, username);
    std::getline(in, email);
    std::getline(in, password);
    std::getline(in, bio);
    std::getline(in, profilePicture);
    
    o = Organizer(username, email, password, bio, profilePicture);
    return in;
}

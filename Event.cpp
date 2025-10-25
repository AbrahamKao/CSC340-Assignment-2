#include "Event.h"
#include <iostream>
Event::Event(const std::string& name, 
	         const std::string& description, 
			 int rating)
		:name(name), 
		description(description), 
		rating(rating),
		soldTicketsCount(0) {} 

std::string Event::getName() const 
{return name;}
std::string Event::getDescription() const 
{return description;}
int Event::getRating() const
{return rating;}
int Event::getSoldTicketsCount() const
{return soldTicketsCount;}

void Event::print(std::ostream& os) const {
	os << "Event Name: " << name << '\n'
	   << "Description: " << description << '\n'
	   << "Rating: " << rating << '\n'
	   << "Tickets Sold: " << soldTicketsCount << '\n';
}

void Event::display() const {
    print(std::cout);
} 

bool Event::modify(const std::string& newName, const std::string& newDescription) {
    name = newName;
    description = newDescription;
    return true;
}

bool Event::operator==(const Event& otherEvent) const {
	return Event::name == otherEvent.name;
}

VirtualEvent::VirtualEvent(const std::string& name,
                           const std::string& description,
                           int rating,
                           const std::string& streamLink,
                           const std::string& audience)
    : Event(name, description, rating), streamLink(streamLink), audience(audience) {}

void VirtualEvent::print(std::ostream& os) const {
    Event::print(os);
    os << "Stream Link: " << streamLink << '\n'
       << "Audience: " << audience << '\n';
}

void VirtualEvent::display() const{
    print(std::cout);
}

bool VirtualEvent::sell(int quantity) {
    if (quantity <=0) return false;
    soldTicketsCount += quantity;
    return true;
}

static void newLine(std::istream& in) {
    if (in.peek() == '\n') 
        in.get();
}  

std::istream& operator>>(std::istream& in, VirtualEvent& v) {
    std::string name, description, link, audience;
    int rating = 0;
    
    newLine(in);
    std::getline(in, name);
    std::getline(in, description);
    in >> rating;
    newLine(in);
    std::getline(in, link);
    std::getline(in, audience);

    v = VirtualEvent(name, description, rating, link, audience);
    return in;

}

VenueEvent::VenueEvent(const std::string& name,
                       const std::string& description,
                       int rating,
                       const std::string& venue,
                       const std::string& dateTime,
                       int capacity)
    : Event(name, description, rating), venue(venue), dateTime(dateTime), capacity(capacity) {}

void VenueEvent::print(std::ostream& os) const {
    Event::print(os);
    os << "Venue: " << venue << '\n'
       << "Date/Time: " << dateTime << '\n'
       << "Capacity: " << capacity << '\n';
}

void VenueEvent::display() const {
    print(std::cout);
}

bool VenueEvent::sell(int quantity) {
    if (quantity <= 0) return false;
    if (soldTicketsCount + quantity > capacity) return false;
    soldTicketsCount += quantity;
    return true;
}

std::istream& operator>>(std::istream& in, VenueEvent& v) {
    std::string name, desc, ven, dt;
    int rating = 0, cap = 0;

    newLine(in);
    std::getline(in, name);
    std::getline(in, desc);
    in >> rating;
    newLine(in);
    std::getline(in, ven);
    std::getline(in, dt);
    in >> cap;
    newLine(in);

    v = VenueEvent(name, desc, rating, ven, dt, cap);
    return in;
}




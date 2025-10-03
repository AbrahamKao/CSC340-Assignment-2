#ifndef EVENT_H
#define EVENT_H

#include <string>

// This is a function that allows you to compare two events based on their name. 
// You may directly include it in your class definition. 
// You don't need to modify it but will have to put it inside your class. 
// Operator overloading function prototype:
class Event {
protected:
    std::string name;               // data members, protected so derived classes can access directly
    std::string description;        // will be used by primarily, display, modify and sell functions
    int rating{0};
    int soldTicketsCount{0}; 
    
public:
    Event() = default;                 // default constructor, generates a empty event
    Event(const std::string& name,     // parameterized constructor, creation of customized objects rather than default variables
          const std::string& description,
          int rating);
        
    // accessor methods, encapsulation, retrieves values without being able to modify
    std::string getName() const;
    std::string getDescription() const;
    int getRating() const;
    int getSoldTicketsCount() const;

    // TO DO: need to implement operation for display, modify, and sell methods
    virtual void display() const;
    virtual bool modify(const std::string& newName, 
                const std::string& newDescription);
    virtual bool sell(int quantity) = 0;

    bool operator==(const Event& otherEvent) const; 

    virtual ~Event() = default; // virtual destructor
};

class VirtualEvent : public Event {
private:
    std::string streamLink;
    std::string audience;

public:
    VirtualEvent(const std::string& name,
                 const std::string& description,
                 int rating,
                 const std::string& streamLink,
                 const std::string& audience);

    void display() const override;
    bool sell(int quantity) override;
};

class VenueEvent : public Event {
private:
    std::string venue;
    std::string dateTime;
    int capacity{0};

public:
    VenueEvent(const std::string& name,
               const std::string& description,
               int rating,
               const std::string& venue,
               const std::string& dateTime,
               int capacity);

    void display() const override;
    bool sell(int quantity) override;
};

#endif
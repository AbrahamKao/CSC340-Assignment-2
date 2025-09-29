// TO DO: #include all the standard libraries and your own libraries here
#include <string>
// To DO: define the class Event with the necessary functions' prototypes and data fields
#ifndef EVENT_H
#define EVENT_H
// This is a function that allows you to compare two events based on their name. 
// You may directly include it in your class definition. 
// You don't need to modify it but will have to put it inside your class. 
// Operator overloading function prototype:
class Event {

    protected:
        std::string name;               //data members, protected so derived classes can access directly
        std::string description;        //will be used by primarily, display, modify and sell functions
        int rating{0};
        int soldTicketsCount{0}; 
    
    public:
        Event() = default;                 //default constructor, generates a empty event
        Event(const std::string& name,     //parameterized constructor, creation of customied objects rather than default variables
              const std::string& description
              int rating);
        
              //accessor methods, encapsulation, retrieves values without being able to modify
        std::string getName() const;
        std::string getDescription() const;
        int getRating() const;
        int getSoldTicketsCount() const;

        //TO DO: need to implement operation for display, modify, and sell methods
        //TO DO: Implement 2 derived classes, for VirtualEevent and VenueEvent
}

bool operator==(const Event& otherEvent) const; 


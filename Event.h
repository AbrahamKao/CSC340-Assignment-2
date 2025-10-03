#ifndef EVENT_H
#define EVENT_H

#include <string>

class Event {
protected:
    std::string name;
    std::string description;
    int rating{0};
    int soldTicketsCount{0}; 
    
public:
    Event() = default;
    Event(const std::string& name,
          const std::string& description,
          int rating);
        
    std::string getName() const;
    std::string getDescription() const;
    int getRating() const;
    int getSoldTicketsCount() const;

    virtual void display() const;
    virtual bool modify(const std::string& newName, 
                const std::string& newDescription);
    virtual bool sell(int quantity) = 0;

    bool operator==(const Event& otherEvent) const; 

    virtual ~Event() = default;
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
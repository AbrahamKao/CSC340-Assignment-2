#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>

class Event {
protected:
    std::string name;
    std::string description;
    int rating{0};
    int soldTicketsCount{0}; 

    virtual void print(std::ostream& os) const;
    
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

    friend std::ostream& operator<<(std::ostream& os, const Event& event) {
        event.print(os);
        return os;
    }
};

class VirtualEvent : public Event {
private:
    std::string streamLink;
    std::string audience;

protected:
    void print(std::ostream& os) const override;

public:
    VirtualEvent(const std::string& name,
                 const std::string& description,
                 int rating,
                 const std::string& streamLink,
                 const std::string& audience);

    void display() const override;
    bool sell(int quantity) override;

    friend std::istream& operator>>(std::istream& in, VirtualEvent& v);
};

class VenueEvent : public Event {
private:
    std::string venue;
    std::string dateTime;
    int capacity{0};

protected:
    void print(std::ostream& os) const override;

public:
    VenueEvent(const std::string& name,
               const std::string& description,
               int rating,
               const std::string& venue,
               const std::string& dateTime,
               int capacity);

    void display() const override;
    bool sell(int quantity) override;

    friend std::istream& operator>>(std::istream& in, VenueEvent& v);
};

#endif
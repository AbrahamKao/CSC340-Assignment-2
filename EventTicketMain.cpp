#include <iostream> 
#include <string>
#include <memory>
#include <limits>

#include "EventTicket340.h"
#include "Organizer.h"
#include "Event.h"
using std::cout;
using std::cin;
using std::string;
using std::shared_ptr;
using std::make_shared;
using std::getline;
using std::endl;

void displayOrganizerMenu(Organizer& organizer){
	int organizerChoice = 0;
	do {
		cout << "\n Hi, "<< organizer.getUsername() <<", what would you like to do:\n"
		<< "1. Display Profile\n"
		<< "2. Modify Password\n"
		<< "3. Create Event\n"
		<< "4. Display All Events\n"
		<< "5. Display Kth Event\n"
		<< "6. Modify Event\n"
		<< "7. Sell Tickets\n"
		<< "8. Delete Event\n"
		<< "0. Logout\n"
		<< "Choice: ";
		cin >> organizerChoice;

		switch (organizerChoice) {
			case 1:{
				organizer.displayProfile();
				break;
			}
			case 2: {
				string newPassword;
				cout << "Enter new password: ";
				cin.ignore();
				getline(cin, newPassword);
				
				if (organizer.modifyPassword(newPassword)) {
					cout << "Password updated successfully!" << endl;
				} else {
					cout << "Failed to update password. Password cannot be empty." << endl;
				}
				break;
			}
			case 3: {
				int eventType;
				cout << "Choose event type:\n1. Virtual Event\n2. Venue Event\nChoice: ";
				cin >> eventType;
				
				string name, description, extraField1, extraField2;
				int rating;
				
				cout << "Enter event name: ";
				cin.ignore();
				getline(cin, name);
				cout << "Enter event description: ";
				getline(cin, description);
				cout << "Enter event rating (0-5): ";
				cin >> rating;
				
				shared_ptr<Event> newEvent;
				
				if (eventType == 1) {
					cout << "Enter stream link: ";
					cin.ignore();
					getline(cin, extraField1);
					cout << "Enter audience type: ";
					getline(cin, extraField2);
					newEvent = make_shared<VirtualEvent>(name, description, rating, extraField1, extraField2);
				} else if (eventType == 2) {
					int capacity;
					cout << "Enter venue: ";
					cin.ignore();
					getline(cin, extraField1);
					cout << "Enter date/time: ";
					getline(cin, extraField2);
					cout << "Enter capacity: ";
					cin >> capacity;
					newEvent = make_shared<VenueEvent>(name, description, rating, extraField1, extraField2, capacity);
				} else {
					cout << "Invalid event type." << endl;
					break;
				}
				
				if (organizer.createEvent(newEvent)) {
					cout << "Event created successfully!" << endl;
				} else {
					cout << "Failed to create event." << endl;
					
				}
				break;
			}
			case 4:{
				// Display all organizer's events
				organizer.displayAllEvents();
				break;
			}
			case 5: {
				int k;
				cout << "Enter the event number (k): ";
				cin >> k;
				
				auto event = organizer.modifyEvent(k);
				if (event != nullptr) {
					cout << "\n--- Event " << k << " ---" << endl;
					event->display();
				} else {
					cout << "Event not found. Total events: " << organizer.getEventCount() << endl;
				}
				break;
			}
			case 6: {
				int k;
				cout << "Enter the event number to modify: ";
				cin >> k;
				
				auto event = organizer.modifyEvent(k);
				if (event != nullptr) {
					string newName, newDescription;
					cout << "Enter new event name (or press Enter to keep current): ";
					cin.ignore();
					getline(cin, newName);
					cout << "Enter new event description (or press Enter to keep current): ";
					getline(cin, newDescription);
					
					if (event->modify(newName, newDescription)) {
						cout << "Event modified successfully!" << endl;
					} else {
						cout << "Failed to modify event." << endl;
					}
				} else {
					cout << "Event not found. Total events: " << organizer.getEventCount() << endl;
				}
				break;
			}
			case 7: {
				int k, quantity;
				cout << "Enter the event number to sell tickets for: ";
				cin >> k;
				cout << "Enter number of tickets to sell: ";
				cin >> quantity;
				
				if (organizer.sellTicket(k, quantity)) {
					cout << "Tickets sold successfully!" << endl;
				} else {
					cout << "Failed to sell tickets. Check event exists, capacity, or quantity." << endl;
				}
				break;
			}
			case 8:{
				// Ask the organizer for the index of the event they want to delete
				int k;
				cout << "Enter the event number to delete: ";
				cin >> k;
				
				if (organizer.deleteEvent(k)) {
					cout << "Event deleted successfully!" << endl;
				} else {
					cout << "Failed to delete event. Event not found. Total events: " << organizer.getEventCount() << endl;
				}
				break;
			}
			case 0: {
				cout << "Logging you out." << endl;
				break;
			}
			default:
				cout << "Invalid choice. Please try again." << endl;
		}

	} while (organizerChoice != 0);
}


int main(){
	EventTicket340 eventTicket340; 

	cout << "\n Welcome to EventTicket340:" << endl;
	
	std::string username, email, password, bio, profilePicture;
	
	cout << "Enter your username: ";
	getline(cin, username);
	cout << "Enter your email: ";
	getline(cin, email);
	cout << "Enter your password: ";
	getline(cin, password);
	cout << "Enter your bio: ";
	getline(cin, bio);
	cout << "Enter your profile picture URL: ";
	getline(cin, profilePicture);
	
	eventTicket340.createOrganizer(username, email, password, bio, profilePicture);	// Retrieve the organizer 
	Organizer currentOrganizer = eventTicket340.getOrganizer();

	// Display the main menu
	displayOrganizerMenu(currentOrganizer);
				
	return 0;
}
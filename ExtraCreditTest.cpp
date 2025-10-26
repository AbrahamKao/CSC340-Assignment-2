#include "LinkedBagDS/LinkedBag.h"
#include "Event.h"
#include <iostream>
#include <memory>
using namespace std;

int main() {
    LinkedBag<shared_ptr<Event>> events;
    
    auto event1 = make_shared<VirtualEvent>("Concert 1", "First test concert", 5, "youtube.com/concert1", "Everyone");
    auto event2 = make_shared<VirtualEvent>("Concert 2", "Second test concert", 4, "youtube.com/concert2", "18+");
    auto event3 = make_shared<VirtualEvent>("Concert 3", "Third test concert", 3, "youtube.com/concert3", "All ages");
    
    cout << "Testing my extra credit implementation:\n\n";
    
    cout << "First test - adding event1:\n";
    events.reverseAppendK(event1, 1);
    auto vec = events.toVector();
    vec[0]->display();
    
    cout << "\nSecond test - adding event2:\n";
    events.reverseAppendK(event2, 1);
    vec = events.toVector();
    for (int i = 0; i < vec.size(); i++) {
        vec[i]->display();
        cout << "\n";
    }
    
    cout << "Third test - adding event3 at position 2:\n";
    events.reverseAppendK(event3, 2);
    vec = events.toVector();
    for (int i = 0; i < vec.size(); i++) {
        vec[i]->display();
        cout << "\n";
    }
    
    cout << "Now testing findKthItem function:\n";
    
    cout << "\nLet's find first item:\n";
    auto node = events.findKthItem(1);
    if (node) {
        node->getItem()->display();
    }
    
    cout << "\nLet's find second item:\n";
    node = events.findKthItem(2);
    if (node) {
        node->getItem()->display();
    }
    
    cout << "\nTrying invalid position (should fail):\n";
    node = events.findKthItem(4);
    if (!node) {
        cout << "Cool, it returned nullptr like it should\n";
    }
    
    return 0;
}
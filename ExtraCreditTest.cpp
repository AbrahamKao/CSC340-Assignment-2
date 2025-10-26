#include "LinkedBagDS/LinkedBag.h"
#include "Event.h"
#include <iostream>
#include <memory>
using namespace std;

int main() {
    LinkedBag<shared_ptr<Event>> myBag;
    
    // making some test events
    auto e1 = make_shared<VirtualEvent>("My Concert", "testing", 5, "twitch.tv/myconcert", "anyone");
    auto e2 = make_shared<VirtualEvent>("Another Show", "more testing", 4, "youtube.com/show", "18+");
    auto e3 = make_shared<VirtualEvent>("Last Event", "final test", 3, "mixer.com/event", "21+");
    
    cout << "trying reverseAppendK first:\n";
    
    // test 1 - empty bag
    cout << "putting first event in empty bag\n";
    myBag.reverseAppendK(e1, 1);
    auto v = myBag.toVector();
    v[0]->display();
    
    // test 2 - adding to front
    cout << "\nputting second event at front\n";
    myBag.reverseAppendK(e2, 1);
    v = myBag.toVector();
    for (int i = 0; i < v.size(); i++) {
        v[i]->display();
        cout << endl;
    }
    
    // test 3 - middle insert
    cout << "adding third event in middle\n";
    myBag.reverseAppendK(e3, 2);
    v = myBag.toVector();
    for (int i = 0; i < v.size(); i++) {
        v[i]->display();
        cout << endl;
    }
    
    cout << "testing findKthItem now:\n";
    
    // checking first item
    cout << "getting first item\n";
    auto n = myBag.findKthItem(1);
    if (n) {
        n->getItem()->display();
    }
    
    // second item
    cout << "getting second item\n";
    n = myBag.findKthItem(2);
    if (n) {
        n->getItem()->display();
    }
    
    // trying bad input
    cout << "trying bad position\n";
    n = myBag.findKthItem(4);
    if (!n) {
        cout << "got nullptr - good\n";
    }
    
    return 0;
}
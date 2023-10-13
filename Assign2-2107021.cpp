


/*
**Problem Description:**
The task at hand involves the management of waste collection in various neighborhoods. Each neighborhood possesses a distinct name and a specific quantity of waste in 
kilograms designated for collection. The objective is to develop a program that efficiently oversees and executes operations pertaining to these neighborhoods. These 
operations encompass tasks like adding new neighborhoods, identifying the neighborhood with the highest waste quantity, removing particular neighborhoods, and more.

**Solution (Code Description):**
The provided C++ code presents a solution to the waste collection management challenge by employing object-oriented programming principles and leveraging the C++ 
Standard Library. The following outlines how the code tackles the problem:

**Neighborhood Class:**
- Represents individual neighborhoods, featuring attributes such as a name and the quantity of waste to be collected (measured in kilograms).
- Offers methods for displaying neighborhood information and retrieving its attributes.

**NeighborhoodList Class:**
- Manages a collection of neighborhoods utilizing a singly linked list structure (utilizing forward_list from the C++ Standard Library).
- Provides an assortment of methods for executing diverse operations on the neighborhood collection. These operations encompass functions for adding, eliminating, 
displaying, and manipulating neighborhood data.

**Main Function:**
- Demonstrates the utilization of the NeighborhoodList class to address the waste collection management problem.
- Initializes a roster of neighborhoods, complete with names and associated waste quantities.
- Displays the initial plan for waste collection.
- Identifies and showcases the neighborhood that possesses the highest quantity of waste.
- Showcases various functions, including the removal of specific neighborhoods, verification of whether the list is devoid of entries, assignment of new neighborhoods, 
removal of the neighborhood at the front of the list, insertion of a new neighborhood at the front, ensuring neighborhood uniqueness, reversing the order of 
neighborhoods, resizing the list, and determining the maximum size of the list.
- Ultimately, the code eradicates all neighborhoods and confirms whether the list is now empty.

**In summary, the code offers a practical solution for the efficient administration of waste collection plans across multiple neighborhoods. It facilitates operations 
such as addition, removal, and manipulation of neighborhood data, thereby streamlining waste management tasks.**
//some test cases
6
RokeyaHall 100
Bblock 250
EEEBuilding 350
CivilBuilding 180
URPBuilding 150
MechanicalBuilding 200
    
*/

/*
1.push_front()
2.remove_if()
3.clear()
4.empty()
5.front();
6.assign()
7.pop_front()
8.insert()
9.end()
10.size()
*/
#include <iostream>
#include <list>
#include <string>

using namespace std;

class Neighborhood {
    string name;
    int wasteInKgs;

public:
    Neighborhood(string n, int w) : name(n), wasteInKgs(w) {}

    void display() const {
        cout << "Neighborhood: " << name << endl;
        cout << "Waste to collect: " << wasteInKgs << " kgs" << endl;
    }

    string getname() const {
        return name;
    }

    int getWasteInKgs() const {
        return wasteInKgs;
    }
};

class NeighborhoodList {
    list<Neighborhood> neighborhoods;

public:
    void addNeighborhood(const Neighborhood& n) {
        neighborhoods.push_front(n);
    }

    void displayNeighborhoods() {
        for (const Neighborhood& n : neighborhoods)
            n.display();
    }

    Neighborhood findMaxWasteNeighborhood() {
        int maxWaste = 0;
        Neighborhood maxWasteNeighborhood("", 0);

        for (const Neighborhood& n : neighborhoods) {
            if (n.getWasteInKgs() > maxWaste) {
                maxWaste = n.getWasteInKgs();
                maxWasteNeighborhood = n;
            }
        }

        return maxWasteNeighborhood;
    }

    void removeNeighborhood(const string& name) {
        neighborhoods.remove_if([name](const Neighborhood& n) {
            return n.getname() == name;
        });
    }

    void removeAllNeighborhoods() {
        neighborhoods.clear();
    }

    bool isEmpty() const {
        return neighborhoods.empty();
    }

    Neighborhood frontNeighborhood() {
        return neighborhoods.front();
    }

    void assign(int count, const Neighborhood& n) {
        neighborhoods.assign(count, n);
    }

    void pop_front() {
        neighborhoods.pop_front();
    }

    void emplace_front(const Neighborhood& n) {
        neighborhoods.emplace_front(n);
    }

    void insert_after(list<Neighborhood>::iterator pos, const Neighborhood& n) {
        neighborhoods.insert(++pos, n);
    }

    list<Neighborhood>::iterator end() {
        return neighborhoods.end();
    }

    size_t maxsizeNeighborhoods() const {
        // There is no direct equivalent in list, so returning a reasonable size
        return neighborhoods.size();
    }
};

int main() {
    system("CLS");
    NeighborhoodList neighborhoodList;
    int test;
    cin>>test;
    while(test--)
    {
        string name;
        int waste;
        cin>>name;
        cin>>waste;
        neighborhoodList.addNeighborhood(Neighborhood(name,waste));
    }
    cout << "Initial waste collection plan:" << endl;
    neighborhoodList.displayNeighborhoods();

    Neighborhood maxWasteNeighborhood = neighborhoodList.findMaxWasteNeighborhood();
    cout << "----------------------" << endl;
    cout << "Neighborhood with the maximum waste:" << endl;
    maxWasteNeighborhood.display();

    // Demonstrating functions
    cout << "----------------------" << endl;
    cout << "Front Neighborhood:" << endl;
    neighborhoodList.frontNeighborhood().display();

    cout << "----------------------" << endl;
    cout << "Removing 'B block' Neighborhood:" << endl;
    neighborhoodList.removeNeighborhood("B block");
    neighborhoodList.displayNeighborhoods();

    cout << "----------------------" << endl;
    cout << "Is the list empty? " << (neighborhoodList.isEmpty() ? "Yes" : "No") << endl;

    cout << "----------------------" << endl;
    cout << "Assigning 3 new neighborhoods:" << endl;
    Neighborhood newNeighborhood("New Neighborhood", 300);
    neighborhoodList.assign(3, newNeighborhood);
    neighborhoodList.displayNeighborhoods();

    cout << "----------------------" << endl;
    cout << "Popping front neighborhood:" << endl;
    neighborhoodList.pop_front();
    neighborhoodList.displayNeighborhoods();

    cout << "----------------------" << endl;
    cout << "Emplacing front neighborhood:" << endl;
    neighborhoodList.emplace_front(Neighborhood("Front Neighborhood", 400));
    neighborhoodList.displayNeighborhoods();

    cout << "----------------------" << endl;
    cout << "Is the list empty? " << (neighborhoodList.isEmpty() ? "Yes" : "No") << endl;

    cout << "----------------------" << endl;
    cout << "Max Size of Neighborhoods: " << neighborhoodList.maxsizeNeighborhoods() << endl;

    cout << "----------------------" << endl;
    cout << "Removing all neighborhoods:" << endl;
    neighborhoodList.removeAllNeighborhoods();
    cout << "Is the list empty? " << (neighborhoodList.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}

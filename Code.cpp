#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    string model;            // Model name of the car
    bool available;          // Availability status

    // Default constructor - initializes car as available with no model
    Car() : model(""), available(true) {}

    // Parameterized constructor to initialize car with model
    Car(string model) : model(model), available(true) {}

    void print() {
        cout << model;
        if (available) {
            cout << " available " << endl;
        } else {
            cout << " not available" << endl;
        }
    }
};

// Global array of Car objects
Car cars[10];

// Global array of Car Models
string carModels[10] = { "BMW", "Audi", "Mercedes", "Porsche", "Toyota", "Lexus",  "Honda", "Chevrolet", "Opel", "McLaren" };

void display() {
    cout << "Current list of cars:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << i + 1 << ". ";
        cars[i].print();
    }
}

void rent(string carModel) {
    int size = 10;
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (cars[i].model == carModel && cars[i].available) {
            cars[i].available = false;
            cout << "Car '" << carModel << "' rented successfully" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Car '" << carModel << "' is not available right now or does not exist. " << endl;
        char choice;
        cout << "Do you want to see the available cars (y/n)?: ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            display();
            string newCar;
            cout << "Enter car model to rent again: ";
            cin >> newCar;
            rent(newCar);
        }
    }
}

void reserve(string carModel) {
    int size = 10;
    bool found = false;

    for (int i = 0; i < size; ++i) {
        if (cars[i].model == carModel && cars[i].available) {
            found = true;
            cout << "How many days do you need the car?: ";
            int time;
            cin >> time;
            cout << "Car reserved successfully!" << endl;
            cars[i].available = false;
            break;
        }
    }
    if (!found) {
        cout << "This car is not available right now or does not exist." << endl;
        char choice;
        cout << "Do you want to see the available cars (y/n)?: ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            display();
            string newCar;
            cout << "Enter car model to rent again: ";
            cin >> newCar;
            reserve(newCar);
        }
    }
}

void searchCar(string car) {
    int size = 10;
    bool isfound = false;
    cout << "Enter the car you want to search for: " << endl;
    cin >> car;
    for (int i = 0; i < size; i++) {
        if (cars[i].model == car) {
            isfound = true;
            cars[i].print();
        }
    }

    if (!isfound) {
        cout << "Car not available!" << endl;
    }
}

void repair() {
    string carModel;
    int issueType;
    string issueDescription;

    cout << "\n--- Car Repair Service ---" << endl;
    cout << "Enter your car model: ";
    cin >> carModel;

    cout << "Choose the type of issue:" << endl;
    cout << "1. Engine" << endl;
    cout << "2. Tires" << endl;
    cout << "3. Brakes" << endl;
    cout << "4. Others" << endl;
    cout << "Enter your choice: ";
    cin >> issueType;

    cout << "Please describe the issue briefly: ";
    cin.ignore(); // To clear the input buffer
    getline(cin, issueDescription);

    cout << "\nThank you for providing the details!" << endl;
    cout << "Car Model: " << carModel << endl;
    cout << "Issue Type: ";
    switch (issueType) {
    case 1:
        cout << "Engine";
        break;
    case 2:
        cout << "Tires";
        break;
    case 3:
        cout << "Brakes";
        break;
    case 4:
        cout << "Others";
        break;
    default:
        cout << "Unknown";
        break;
    }
    cout << "\nIssue Description: " << issueDescription << endl;
    cout << "Our team will contact you shortly for further assistance.\n" << endl;
}

struct Customer {
    string name;
    string phone;
    string email;
    string licenceNumber;
};

// Node class for the linked list
class Node {
public:
    Customer data;
    Node* next;

    Node(Customer customer) {
        data = customer;
        next = nullptr;
    }
};

class CustomerList {
private:
    Node* head;

public:
    CustomerList() {
        head = nullptr;
    }

    void addCustomer(const Customer& customer) {
        Node* newNode = new Node(customer);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Customer added successfully!\n";
    }

    void displayCustomers() {
        if (head == nullptr) {
            cout << "No customers in the list.\n";
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << "Name: " << temp->data.name << "\n";
            cout << "Phone: " << temp->data.phone << "\n";
            cout << "Email: " << temp->data.email << "\n";
            cout << "License Number: " << temp->data.licenceNumber << "\n";
            cout << "--------------------------\n";
            temp = temp->next;
        }
    }
};

void collectFeedback() {
    string serviceFeedback;
    string carFeedback;
    string costFeedback;
    string problems;

    cout << "Welcome to the feedback system!\n";

    // Question 1
    cout << "How do you find our services: ";
    cin.ignore();
    getline(cin, serviceFeedback);

    // Question 2
    cout << "Did you like our cars? If not, feel free to inform us: ";
    getline(cin, carFeedback);

    // Question 3
    cout << "Did you find the cost adequate to the services? ";
    getline(cin, costFeedback);

    // Question 4
    cout << "If you have any problems with the cars or the services, please let us know: ";
    getline(cin, problems);

    // Display feedback as a report
    cout << "\n--- Customer Feedback Report ---\n";
    cout << "Service Feedback: " << serviceFeedback << "\n";
    cout << "Car Feedback: " << carFeedback << "\n";
    cout << "Cost Feedback: " << costFeedback << "\n";
    cout << "Problems: " << problems << "\n";
    cout << "-----------------------------------------\n";
}

int main() {
    int service;
    CustomerList customerList;
    int choice;
    cout << "Welcome to our car service center!" << endl;

    // Initialize the cars array
    for (int i = 0; i < 10; ++i) {
        cars[i] = Car(carModels[i]);
    }

    do {
        cout << "1. Add Customer\n";
        cout << "2. Display Customers\n";
        cout << "3. Choose a service\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Customer customer;
            cin.ignore();
            cout << "Enter customer name: ";
            getline(cin, customer.name);
            cout << "Enter phone number: ";
            getline(cin, customer.phone);
            cout << "Enter email: ";
            getline(cin, customer.email);
            cout << "Enter license number: ";
            getline(cin, customer.licenceNumber);

            customerList.addCustomer(customer);
        } else if (choice == 2) {
            customerList.displayCustomers();
        } else if (choice != 3) {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    do {
        cout << "Please choose the service you need:" << endl;
        cout << "1. Rental" << endl;
        cout << "2. Repair" << endl;
        cout << "3. Reserve" << endl;
        cout << "4. Search for a car" << endl;
        cout << "5. Give feedback" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> service;

        if (service == 1) {
            display();
            cout << "Choose the car you want to rent: ";
            string carModel;
            cin >> carModel;
            rent(carModel);
        } else if (service == 2) {
            repair();
        } else if (service == 3) {
            display();
            cout << "Enter the car you want to reserve: ";
            string carModel;
            cin >> carModel;
            reserve(carModel);
        } else if (service == 4) {
            string carModel;
            searchCar(carModel);
        } else if (service == 5) {
            collectFeedback();
        } else if (service == 6) {
            cout << "Thank you for using our services. Have a good day :)" << endl;
        } else {
            cout << "Invalid input. Please try again." << endl;
        }
    } while (service != 6);

    return 0;
}
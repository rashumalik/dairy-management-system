// Dairy Management System in C++
// Simple Mini Project for Students
// Features:
// 1. Add Customer
// 2. Display Customers
// 3. Search Customer
// 4. Update Milk Quantity
// 5. Delete Customer

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Dairy {
public:
    int customerID;
    string name;
    float milkQuantity;
    float pricePerLiter;

    void addRecord() {
        cout << "\nEnter Customer ID: ";
        cin >> customerID;
        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Milk Quantity (Liters): ";
        cin >> milkQuantity;

        cout << "Enter Price Per Liter: ";
        cin >> pricePerLiter;

        ofstream file("dairy.txt", ios::app);
        file << customerID << " "
             << name << " "
             << milkQuantity << " "
             << pricePerLiter << endl;
        file.close();

        cout << "\nRecord Added Successfully!\n";
    }

    void displayRecords() {
        ifstream file("dairy.txt");
        if (!file) {
            cout << "\nNo Records Found!\n";
            return;
        }

        cout << "\n--- Dairy Customer Records ---\n";
        while (file >> customerID >> name >> milkQuantity >> pricePerLiter) {
            cout << "\nCustomer ID: " << customerID;
            cout << "\nName: " << name;
            cout << "\nMilk Quantity: " << milkQuantity << " Liters";
            cout << "\nPrice Per Liter: Rs. " << pricePerLiter;
            cout << "\nTotal Bill: Rs. " << milkQuantity * pricePerLiter;
            cout << "\n-----------------------------\n";
        }
        file.close();
    }

    void searchRecord() {
        int id;
        bool found = false;

        cout << "\nEnter Customer ID to Search: ";
        cin >> id;

        ifstream file("dairy.txt");

        while (file >> customerID >> name >> milkQuantity >> pricePerLiter) {
            if (customerID == id) {
                cout << "\nRecord Found!\n";
                cout << "Customer ID: " << customerID << endl;
                cout << "Name: " << name << endl;
                cout << "Milk Quantity: " << milkQuantity << " Liters" << endl;
                cout << "Price Per Liter: Rs. " << pricePerLiter << endl;
                cout << "Total Bill: Rs. " << milkQuantity * pricePerLiter << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "\nRecord Not Found!\n";
        }

        file.close();
    }

    void deleteRecord() {
        int id;
        bool found = false;

        cout << "\nEnter Customer ID to Delete: ";
        cin >> id;

        ifstream file("dairy.txt");
        ofstream temp("temp.txt");

        while (file >> customerID >> name >> milkQuantity >> pricePerLiter) {
            if (customerID != id) {
                temp << customerID << " "
                     << name << " "
                     << milkQuantity << " "
                     << pricePerLiter << endl;
            } else {
                found = true;
            }
        }

        file.close();
        temp.close();

        remove("dairy.txt");
        rename("temp.txt", "dairy.txt");

        if (found)
            cout << "\nRecord Deleted Successfully!\n";
        else
            cout << "\nRecord Not Found!\n";
    }
};

int main() {
    Dairy d;
    int choice;

    do {
        cout << "\n====== Dairy Management System ======\n";
        cout << "1. Add Customer Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Search Customer Record\n";
        cout << "4. Delete Customer Record\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            d.addRecord();
            break;
        case 2:
            d.displayRecords();
            break;
        case 3:
            d.searchRecord();
            break;
        case 4:
            d.deleteRecord();
            break;
        case 5:
            cout << "\nExiting Program...\n";
            break;
        default:
            cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 5);

    return 0;
}
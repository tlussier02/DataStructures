/*
Full name: Trevor Lussier
Student ID: 2445730
Chapman email: tlussier@chapman.edu
Course number and section: CPSC 350 04
Assignment or exercise number: 4 (Blockchain Ledger)
*/

#include "Blockchain.h"
#include <iostream>
#include <string>

using namespace std;

/*
  Simple console-based interface:
    1) Add a New Block
    2) Display the Blockchain
    3) Validate the Blockchain
    4) Save Blockchain to File
    5) Load Blockchain from File
    6) Exit
*/

int main() {
    Blockchain ledger;
    bool done = false;

    while (!done) {
        cout << "\n=== BLOCKCHAIN MENU ===\n";
        cout << "1) Add a New Block\n";
        cout << "2) Display the Blockchain\n";
        cout << "3) Validate the Blockchain\n";
        cout << "4) Save Blockchain to File\n";
        cout << "5) Load Blockchain from File\n";
        cout << "6) Exit\n";
        cout << "Choose an option: ";
        int choice;
        cin >> choice;
        cin.ignore(1000, '\n'); // flush newline

        switch (choice) {
        case 1: {
            cout << "Enter block data: ";
            string data;
            getline(cin, data);
            ledger.addBlock(data);
            cout << "Block added.\n";
            break;
        }
        case 2: {
            ledger.displayChain();
            break;
        }
        case 3: {
            bool valid = ledger.validateChain();
            if (valid) {
                cout << "Blockchain is valid!\n";
            } else {
                cout << "Blockchain is invalid!\n";
            }
            break;
        }
        case 4: {
            cout << "Enter output file name: ";
            string outFile;
            getline(cin, outFile);
            ledger.saveToFile(outFile);
            break;
        }
        case 5: {
            cout << "Enter input file name: ";
            string inFile;
            getline(cin, inFile);
            ledger.loadFromFile(inFile);
            break;
        }
        case 6: {
            done = true;
            break;
        }
        default: {
            cout << "Invalid choice. Try again.\n";
            break;
        }
        }
    }

    cout << "Exiting...\n";
    return 0;
}

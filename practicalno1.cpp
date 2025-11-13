#include <iostream>
using namespace std;

class training {
    int rollno[5];
public:
    void linearsearch();
    void binarysearch();
};

void training::linearsearch() {
    int rno;
    bool found = false;

    cout << "Enter 5 roll numbers: " << endl;
    for (int i = 0; i < 5; i++) {
        cin >> rollno[i];
    }

    cout << "Enter the roll number to search: ";
    cin >> rno;

    for (int i = 0; i < 5; i++) {
        if (rollno[i] == rno) {
            cout << "Roll number " << rno << " has attended the training program." << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Roll number " << rno << " has NOT attended the program." << endl;
    }
}

void training::binarysearch() {
    int rno;
    bool found = false;
    int low = 0, high = 4, mid;

    cout << "Enter 5 roll numbers in sorted order: " << endl;
    for (int i = 0; i < 5; i++) {
        cin >> rollno[i];
    }

    cout << "Enter the roll number to search: ";
    cin >> rno;

    while (low <= high) {
        mid = (low + high) / 2;

        if (rollno[mid] == rno) {
            found = true;
            break;
        } else if (rollno[mid] < rno) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (found)
        cout << "Roll number " << rno << " has attended the program." << endl;
    else
        cout << "Roll number " << rno << " has NOT attended the program." << endl;
}

int main() {
    training tr;
    int choice;

    do {
        cout << "\nSearch Menu:\n";
        cout << "1. Linear Search\n";
        cout << "2. Binary Search\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tr.linearsearch();
                break;
            case 2:
                tr.binarysearch();
                break;
            case 3:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

#include<iostream>
using namespace std;

int tabsize = 10;
long long ht[10];

int hashfunction(long long mbno)
{
    return mbno % 10;
}

void insert(long long mbno)
{
    int pos = hashfunction(mbno);
    for(int i = 0; i < tabsize; i++)
    {
        if(ht[pos] == -1)
        {
            ht[pos] = mbno;
            cout << "Mobile number " << mbno << " inserted at position " << pos << "." << endl;
            return;
        }
        else
        {
            cout << "Collision occurred at position " << pos << endl;
            pos = (pos + 1) % 10;
        }
    }
  
  cout << "Hash table is full. " << mbno << "." << endl;
}


void display()
{
    cout << "Hash Table: " << endl;
    for(int i = 0; i < tabsize; i++)
    {
        if(ht[i] != -1)
            cout << "Position " << i << ": " << ht[i] << endl;
        else
            cout << "Position " << i << ": -1 " << endl;
    }
}

void search(long long mbno)
{
    int pos = hashfunction(mbno);
    for(int i = 0; i < tabsize; i++)
    {
        if(ht[pos] == mbno)
        {
            cout << "Mobile number " << mbno << " found at position " << pos << endl;
            return;
        }
        else if(ht[pos] == -1)
        {
            cout << "Mobile number " << mbno << " not found in hash table" << endl;
            return;
        }
        else
        {
            pos = (pos + 1) % 10;
        }
    }
    cout << "Mobile number " << mbno << " not found in hash table." << endl;
}

int main()
{
    for (int i = 0; i < tabsize; i++)
    {
        ht[i] = -1;
    }

    int choice;
    long long mbno;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Insert Mobile Number\n";
        cout << "2. Display Hash Table\n";
        cout << "3. Search Mobile Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter Mobile Number to insert: ";
                cin >> mbno;
                insert(mbno);
                break;

            case 2:
                display();
                break;

            case 3:
                cout << "Enter Mobile Number to search: ";
                cin >> mbno;
                search(mbno);
                break;

            case 4:
                cout << "Exit program." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != 4);

    return 0;
}
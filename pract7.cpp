#include <iostream>
using namespace std;

#define SIZE 5

class PizzaParlor
{
    int queue[SIZE];
    int f, r;

 public:
    PizzaParlor() 
    {
        f = -1;
        r = -1;
    }

    void orderPizza(int no)
    {
        if ((r + 1) % SIZE == f) 
        {
            cout << "Can't take further orders. Queue is full.\n";
        } else if (f == -1 && r == -1) 
        {
            f = r = 0;
            queue[r] = no;
            cout << "Order placed: " << no;
        } else 
        {
            r = (r + 1) % SIZE;
            queue[r] = no;
            cout << "Order placed: " << no;
        }
    }

    void makePayment()
    {
        if (f == -1 && r == -1) 
        {
            cout << "No orders to process. Queue is empty.\n";
        } else if (f == r)
        {
            cout << "Order served and paid: " << queue[f];
            f = r = -1;
        } else 
        {
            cout << "Order served and paid: " << queue[f];
            f = (f + 1) % SIZE;
        }
    }

    void display() 
    {
        if (f == -1 && r == -1) 
        {
            cout << "No current orders.\n";
            return;
        }
        cout << "Current orders in queue: ";
        int i = f;
        while (true) 
        {
            cout << queue[i] << " ";
            if (i == r)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() 
{
    PizzaParlor p;
    int choice, orderNo;

    do {
        cout << "\n--- Pizza Parlor Menu ---\n";
        cout << "1. Place Order\n";
        cout << "2. Make Payment (Serve Order)\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout<<"1.veg pizza,2.onion pizza,3.butter pizza,4.silicon pizza";
                cout << "Enter order number to place: ";
                cin >> orderNo;
                p.orderPizza(orderNo);
                break;

            case 2:
                p.makePayment();
                break;

            case 3:
                p.display();
                break;

            case 4:
                cout << "Exiting Pizza Parlor system \n";
                break;

            default:
                cout << "Invalid choice! Please select a valid option.\n";
        }

    } while (choice != 4);

    return 0;
}
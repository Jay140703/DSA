#include <iostream>
using namespace std;
struct seats
{
    int seatno ;
    bool booked ;
    seats*prev,*next;
};
class row 
{
    public:
    seats*head;
    row()
    {
        head=nullptr;
    }
    void createRow(int seat)
    {
        for (int i=1 ;i<=seat;i++)
        {
            seats*newseat=new seats();
            newseat-> seatno=i;
            newseat->booked=false;
            newseat->prev=nullptr;
            newseat->next=nullptr;
            if (head==nullptr)
            {
                head=newseat;
            }
            else
            {
                seats*temp=head;
                while(temp->next!=nullptr)
                {
                    temp=temp->next;
                }
                 temp->next=newseat;
                  newseat->prev=temp;

            }
        }
    }
    void displayrow()
    {
        seats*temp=head;
        while(temp!=nullptr)
        {
            if (temp->booked!=true)
            {
                cout<<temp->seatno<<" \t ";
            }
        
            temp=temp->next;
            
        }
        cout<<endl;
    }
    void booking(int seatnumber) 
    {
        seats* temp = head;
        while (temp != nullptr) 
        {
            if (temp->seatno == seatnumber) 
            {
                if (temp->booked == true) 
                {
                   cout << "Seat already booked.\n";
                } else 
                {
                    temp->booked = true;
                    cout << "Seat is booked\n";
                    return;
                }
               
            }
            temp = temp->next;
        }
        cout << "Invalid seat number.\n";
    }
    void Cancelseat(int seatnumber)
    {
        seats* temp = head;
       while (temp != nullptr) 
        {
            if (temp->seatno == seatnumber) 
            {
               if (temp->booked == false) 
                {
                   cout << "Seat is not booked.\n";
                } else 
                {
                    temp->booked = false;
                    cout << "Seat is cancelled \n";
                    return;
                }
            }
            temp = temp->next;
        }
        cout << "Invalid seat number.\n";
        
    }
};
int main ()
{
    int choice ;
    const int Row=10,seatno=7;
    int rownumber , seatnumber;
    row cinema[Row];
    for (int i=0;i<Row ;i++)
    {
        cinema[i].createRow(seatno);
    }
    do{
    cout<<"Enter the choice "<<"\n";
    cout<<"1.for display "<<"\n";
    cout<<"2.for booking  "<<"\n";
    cout<<"3.Cancel the seat"<<"\n";
    cout<<"4.EXIT "<<"\n";
    cin>>choice;
    switch (choice)
    {
    case 1:
        for (int i=0;i<Row ;i++)
        {
            cout<<"Row" << i+1 << "  :\t ";
            cinema[i].displayrow();
        }       
       break;
    case 2:
      
            cout << "Enter row number (1 to 10) : ";
            cin >> rownumber;
            cout << "Enter seat number (1 to 7) : ";
            cin >> seatnumber;
                if (rownumber >= 1 && rownumber <= 10)
            {
                cinema[rownumber - 1].booking(seatnumber);
            }
            else 
            {
                cout << "Invalid row number.\n";
            }
            break;
    case 3:
            cout<<"Enter the row and  number you want to cancel booking"<<"\n";
            cin>>rownumber;
            cin>>seatnumber;
              if (rownumber >= 1 && rownumber <= 10)
            {
                cinema[rownumber - 1].Cancelseat(seatnumber);
            }
            else 
            {
                cout << "Invalid row number.\n";
            }

            break;


           break;
    case 4:
            cout<<"EXIT ";            
            break;
    default:
        cout<<"invalid choice";

        break;
    }
}while(choice=4);

     
}
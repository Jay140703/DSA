#include<iostream>
using namespace std;
struct node 
{
    int PRN;
    string name ;
    node*next;
};
class pinnacleclub 
{
    public:
    node*president = nullptr,*secretory=nullptr,*temp=nullptr;
    node*addmember(int prn ,string name )
    {
        node*newmember=new node();
        newmember->PRN=prn;
        newmember->name=name;
        newmember->next =nullptr ;
        if(president==nullptr)
        {
            president = newmember;
            secretory = newmember;
        }
        else
        {
            secretory->next=newmember;
            secretory =newmember;
        }
        return president ;
    
    }
    void display(int prn, string name )
    {
        temp =president;
        while(temp!=nullptr)
        {
            cout<<temp->PRN<<"\n";
            cout<<temp->name<<"\n";
            temp=temp->next;
        }
    }
    void countmember()
    {
        int count = 0;
        temp = president ;
        while(temp!=nullptr)
        {
            count++;
            temp=temp->next;
        }
        cout<<"total members of club: "<<count <<"\n";

    }
    node*deletepresident()
    {
        if(president==nullptr)
        {
            cout<<"empty";
        }        
        else{
            temp=president;
            president=temp->next;
            temp=nullptr;
            delete(temp);
        }
        return president ;
    }
    node*deletesecretory()
    {
        if(secretory==nullptr)
        {
            cout<<"list is not present ";
        }        
        else{
            temp=president;
           node* temp1 =president;
           while(temp->next!=nullptr)
           {
            temp1=temp;
            temp=temp->next;
           }
           temp1->next=nullptr;
            delete(temp);
        }
        return president ;
    }
    node*posdelete(int pos )
    {
    
        node*prev=president;
        node*current =president;
         if(president == nullptr)
         {
            cout<<"empty";
         }
         else if(pos==1 )
         {
          
            president=president->next;
            free(temp);
         }
         else
         {
            while(pos!=1)
            {
                prev=current;
                current=current->next;
                pos--;
            }
            prev->next=current->next;
            free(current);
            
         }
         current=nullptr;
        
    }
   void  concatenation(pinnacleclub & pc1)
   {
    if(president==nullptr)
    {
        president= pc1.president ;

    }
    else 
    {
        secretory->next= pc1.president ;
    }
   }

};

int main()
{
    int choice , prn,pos,total;
    string name ;
    pinnacleclub pc;
     pinnacleclub pc1;
    do
    {
    
        cout<<"1. add members "<<"\n";
        cout<<"2.display members "<<"\n";
        cout<<"3.count member "<<"\n";
        cout<<"4.delete president "<<"\n";
        cout<<"5.delete secretory "<<"\n";
        cout<<"6.delete member"<<"\n";
        cout<<"7.concatenation"<<"\n";
        cout<<"8.Exit"<<"\n";
        

        cout<<"Enter you choice";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"enter prn no: "<<"\n";
                cin>>prn;
                cout<<"Enter name :  "<<"\n";
                cin>>name;
                pc.addmember(prn,name);
                break;
            case 2:
                pc.display(prn,name); 
                break;
            case 3:
                pc.countmember();
                break;
            case 4:
                pc.deletepresident();
                break;
            case 5:
                pc.deletesecretory();
                break;
            case 6:
                cout<<"give position of member you want to delete";
                cin>>pos;
                pc.posdelete(pos );
                break;
            case 7:
               cout<<"Enter the number of the members of div B";
               cin>>total ;
               for (int i=0;1<total;i++)
               {
                cout <<"prn and name for div A"<<i+1;
                cin>>prn;
                cin>>name;
                pc1.addmember(prn,name);
               }
               cout<<"Enter the number of the memberof div B"<<"\n";
               cin>>total;
               for (int i=0;i<total;i++)
               {
                cout<<"prn an dname for Div A"<<i+1;
                cin>>prn;
                cin>>name ;
                pc1.addmember(prn,name );
               }
               cout <<"member of Div A: \n";
               pc.display(prn,name); 
               cout <<"Member of Div B: \n";
               pc1.display(prn,name); 


               pc.concatenation(pc1);
               cout <<"Member of div B: \n";
               pc1.display(prn,name); 
               break;
             case 8:
               cout<<"Exit";
               break;
        }
    } while (choice!=8);
    return 0;    
}
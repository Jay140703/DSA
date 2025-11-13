#include <iostream>
using namespace std;
void bubblesort(int arr[],int n)
{
int temp;
for(int i=0;i<n-1;i++)
{
for(int j=0;j<n-i-1;j++)
{
if (arr[j]>arr[j+1])
{
int temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}
cout<<"array after sorting \n";
for(int i=0;i<n;i++)
{
cout<<arr[i] << "\n";
}
cout<< "\n";
cout<<"top 5 score \n";
int count=0;
for(int i=n-1;i>0;i--)
{
if(count<=5)
count++;
cout<< arr[i];
cout<<"\n";
}
}
void selectionsort(int arr[],int n)
{
for(int i=0;i<=n-1;i++)
{
int minindex=i;
for(int j=i+1;j<=n-1;j++)
{
if(arr[j]<arr[minindex])
{
minindex=j;
}
}
if(minindex!=i)
{
int temp=arr[i];
arr[i]=arr[minindex];
arr[minindex]=temp;
}
}
cout<<"array after sorting \n";
for(int i=0;i<n;i++)
{
cout<<arr[i]<<"\n";
}
cout<< "\n";
cout<<"top 5 score \n";
int count=0;
for(int i=n-1;i>0;i--)
{
if(count<=5)
count++;
cout<< arr[i];
cout<<"\n";
}
}
int main()
{
int n,i;
cout<<"enter the total no of student in your class";
cin>>n;
int arr[n];
cout<<"enter the marks";
for(int i=0;i<n;i++)
{
cin>>arr[i];
}
cout<<"array before storing"<<"\n";
for(int i=0;i<n;i++)
{
cout<<arr[i]<<"\n";
}
bubblesort (arr,n);
int choice;
do
{
cout<<"enter your choice \n";
cin>> choice;
cout<<"1.bubblesort \n";
cout<<"2.selection sort \n";
cout<<"3.exit \n";
cout<<"4.default\n";
switch(choice)
{
case 1:
bubblesort(arr,n);
break;
case 2:
selectionsort(arr,n);
break;
case 3:
cout<<"exit \n";
break;
case 4:
cout<<"enter valid choice";
}
} while(choice !=4);
return 0;
}
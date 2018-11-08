#include <iostream>

using namespace std;

int main()
{
    int *p;
    int arr[7];
    int i;
    for(i=0;i<7;i++)
        arr[i]=i;
    for(i=0;i<7;i++)
        cout<<arr[i]<<" ";
        cout<<"\n";
    for(i=0;i<7;i++)
        {
        cout<<&arr[i]<<" ";
        cout<<"\n";
        }
    for(i=0;i<7;i++)
        cout<<*(arr+i)<<" ";
        cout<<"\n";
        p=arr;  // p=&arr[0]
    for(i=0;i<7;i++)
    {
        cout<<*p<<" ";
        p++;
        }
    cout<<"\n";
}

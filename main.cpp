#include <iostream>
using namespace std;
// this function simply swaps the content
void myswap(int *a,int *b)
{
    int temp=*a; // store in temporary variable
    *a=*b;
    *b=temp;
}
int divide(int *a,int p,int q) // partitions the array and returns pivot point through the variable 'i'
{
    int i=p,x=a[p];
    for(int j=p+1;j<=q;j++)
    {
        if(a[j]<=x)
        {
            i=i+1;
            myswap(&a[i],&a[j]);            // swaping the content
        }
    }
    myswap(&a[p],&a[i]);                    // swaping the pivot to correct position
    return i;                               // returning the index of pivot element
}

void quicksort(int *a, int p, int q)
{
    if(p<q)
    {
    int k = divide(a,p,q);                     // partition the array about pivot element
    quicksort(a,p,k-1);                       //  recursive call to the left part of the array
    quicksort(a,k+1,q);                       //  recursive call to the right part of the array
    }
}
int main()
{
    int n;
    cout<<"enter the size of array :  ";
    cin>>n;                                     // n is used for size
    cout<<endl;
    int i,a[n];
    for(i=0;i<n;i++)                            // taking in the array input
        cin>>a[i];
        cout<<endl;
        cout<<"THE FINAL SORTED ARRAY IS AS FOLLOWS:"<<endl;
    quicksort(a,0,n-1);                         // call to the quicksort function
    for(i=0;i<n;i++)                            // loop for printing the sorted array
        cout<<a[i]<<"  ";
    return 0;
}

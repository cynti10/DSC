#include<iostream>
using namespace std;
int part(int arr[],int l,int h)
{
    int pivot=arr[l];
    int count=0;
    for(int i=l+1;i<=h;i++)
    {
        if(arr[i]<pivot)
            count++;
    }
    int temp=0;
    int pi=l+count;
    temp=arr[l];
    arr[l]=arr[pi];
    arr[pi]=temp;
    int i=l;
    int j=h;
    while(i<pi&&j>pi)
    {
        while(arr[i]<arr[pi])
            i++;
        while(arr[j]>arr[pi])
            j--;
        if(i<pi&&j>pi)
        {
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
            i++;
            j--;
        }
    }
    return pi;
}
void qs(int arr[],int l,int h)
{
    if(l>=h)
        return;
    int p=part(arr,l,h);
    qs(arr,l,p-1);
    qs(arr,p+1,h);
}
int main()
{
    int n;
    cout<<"enter no. of elements"<<endl;
    cin>>n;
    int *arr=new int[n];
    cout<<"enter elements:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Before sort: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\nAfter sort: ";
    qs(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    delete[] arr;
    return 0;
}
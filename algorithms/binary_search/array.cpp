/* Given an array of integers which is initially increasing and then decreasing, 
find the maximum value in the array. */

#include<bits/stdc++.h>
using namespace std;

int find( int arr[], int low, int high)
{
    if(low == high)
        return arr[low];

    if( (low+1 == high) && arr[low] >= arr[high])
        return arr[low];
    if((low+1 == high) && arr[low] < arr[high])
        return arr[high];

    int mid = (low+high)/2;

    if((arr[mid+1] < arr[mid]) && (arr[mid] < arr[mid-1]))
        return find(arr,low,mid-1);
    else
    {
        return find(arr, mid+1, high);
    }
    


}

int main()
{
    
    int n;
    cout << "Enter the number of elements in array : ";
    cin >> n;
    int arr[n];

    cout << "Enter the elements of the array : ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    cout << "The largest element in the array is : " << find(arr,0, n-1) << endl;
    
    return 0;


}
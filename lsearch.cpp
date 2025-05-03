#include<iostream>
using namespace std;
int main()
{
    int n, i, key;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the element to be searched: ";
    cin >> key;
    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            cout << "Element found at position " << i + 1;
            break;
        }
    }
    if(i == n)
    {
        cout << "Element not found";
    }
    return 0;concat.c
    
}   
#include<iostream>
using namespace std;
void bubble(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main()
{
    int a[]={5,4,3,2,1};
    int n=sizeof(a)/sizeof(a[0]);
    bubble(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
 #include<iostream>
 using namespace std;
int bsearch(int a[],int n,int key)
{
    int l=0,h=n-1;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(a[mid]==key)
            return mid;
        else if(a[mid]>key)
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;
}
int main()
{
    int a[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(a)/sizeof(a[0]);
    int key=5;
    int index=bsearch(a,n,key);
    if(index==-1)
        cout<<"Element not found";
    else
        cout<<"Element found at index "<<index;
    return 0;
}
   
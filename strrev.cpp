#include<iostream>
using namespace std;
void strrev(char* s){
    int l=0,h=0;
    while(s[h]!='\0')
        h++;
    h--;
    while(l<h){
        char temp=s[l];
        s[l]=s[h];
        s[h]=temp;
        l++;
        h--;
    }
}
int main()
{
    char s[100];
    cout<<"Enter a string: ";
    cin>>s;
    strrev(s);
    cout<<"Reversed string: "<<s;
    return 0;
}
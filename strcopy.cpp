#include<iostream>
using namespace std;
void strcopy(char *s1,char *s2){
    while(*s1!='\0'){
        *s2=*s1;
        s1++;
        s2++;
    }
    *s2='\0';
}
int main()
{
    char s1[100],s2[100];
    cout<<"Enter a string: ";
    cin>>s1;
    strcopy(s1,s2);
    cout<<"Copied string: "<<s2;
    return 0;
}
 #include<stdio.h>
 #include<stdlib.h>

 struct node{
    int data;
    struct node* next;
 };
    struct node* head=NULL;
    void insert(int data){
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->next=head;
        head=newnode;
}
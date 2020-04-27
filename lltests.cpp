#include<iostream>
using namespace std;

struct node{
int data;
node * next;
};

node * head=NULL;
node * tail=NULL;

void display(){
        node * temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

void add_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
int main(){
    add_node(5);
    add_node(10);
    display();

    return 0;
}
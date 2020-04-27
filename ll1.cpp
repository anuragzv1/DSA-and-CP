#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;
Node *tail = NULL;
void insertIntoLL(int ele)
{
    Node *temp = new Node;
    temp->data = ele;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void displayLL()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    cout<<"Enter no of elements to be inserted";
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        insertIntoLL(x);
    }
    displayLL();
    return 0;
}
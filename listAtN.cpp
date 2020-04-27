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

void insertAtN(int n, int ele)
{
    if(n<1) cout<<"Cannot insert at this position";
    Node *counter = head;
    Node *counter2 = head;
    int count = 0;
    while (counter != NULL)
    {
        count++;
        counter = counter->next;
    }
    while (counter2->next != NULL)
    {
        counter2 = counter2->next;
    }
    Node *temp = new Node;
    temp->data = ele;
    temp->next = NULL;
    if (head == NULL)
    {
        cout << "Linked list is empty inserting at head\n";
        head = temp;
        tail = temp;
    }
    else if (n > count)
    {
        cout << "N is greater than list length inserting at the end\n";
        counter2->next = temp;
        tail = temp;
    }
    else if(n>1 && n<=count)
    {
        counter = head;
        for (int i = 0; i < n-2; i++)
        {
            counter=counter->next;
        }
        temp->next=counter->next;
        counter->next=temp;
    }
    else if(n==1){
        temp->next=head;
        head=temp;
    }
}

int main()
{
    cout << "Enter no of elements to be inserted\n";
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insertIntoLL(x);
    }
    insertAtN(1, 1111);
    displayLL();
    return 0;
}
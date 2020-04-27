#include<iostream>
using namespace std;

template<typename T>
class Node{
    public:
    T data;
    Node * next;

    Node(T data){
        this->data = data;
    }
};



Node <int> *  createList (int n){
    Node<int> * head = NULL , *tail =NULL;
    for(int i = 0;i<n;i++){
        int data;
        cin>>data;
        Node<int>* newNode = new Node<int>(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail =newNode;
        }
    }
    return head;
}



bool palin = true;
Node<int> * globalHead;
bool palindromeCheck(Node<int> * node){
    if(node==NULL){
        return true;
    }
    bool small = palindromeCheck(node->next);
    if(small==false)return false;

    if(node->data!=globalHead->data){
        return false;
    }
    else {
        globalHead=globalHead->next;
        return true;
    }

}

int main(){
    int n;
    cin>>n;
    Node<int>* head = createList(n);
    globalHead  = head;
    if(palindromeCheck(head))cout<<"Palindrome";
    else cout<<"Not palindrome";
    return 0;
}



#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &head, int d){
    Node* nodeL = new Node(d);
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = nodeL;
}

void deleteNode(Node*&head, int position){
    Node* temp = head;
    if(position == 1){
        head = head -> next;
        delete temp;
        return;
    }
    int count = 2;
    while(count != position){
        temp = temp->next;
        count++;
    }
    Node* deletedNode = temp -> next;
    temp-> next = temp -> next -> next;
    delete deletedNode;
}

void insertInBetween(Node* &head, int d, int index){
    if(index == 0){
        insertAtHead(head, d);
        return;
    }
    Node* node = new Node(d);
    Node* temp = head;
    int count = 1;
    while(count!=index){
        if(temp == NULL){
            return;
        }
        temp = temp-> next;
        count++;
    }
    node -> next = temp-> next;
    temp -> next = node;

    
}
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp-> data <<endl;
        temp = temp-> next;
    }
}
int main(){
    Node* head = new Node(10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtTail(head, 50);
    insertInBetween(head, 60, 3);
    insertInBetween(head, 70, 5);
    deleteNode(head, 6);
    print(head);
    return 0;
}
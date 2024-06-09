#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d){
        this-> data = d;
        this-> prev = NULL;
        this-> next = NULL;
    }
};

void print(Node* &head){
    Node* temp = head;

    while(temp!=NULL){
        cout << temp->data<< " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtHead(Node* &head, int data){
    Node* temp = head;
    Node* node = new Node(data);
    node->next = head;
    head-> prev = node;
    head = node;
}

void insertAtTail(Node* &head, int data){
    Node* node = new Node(data);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp-> next;
    }
    temp -> next = node;
    node -> prev = temp;

}

int getLength(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp!=NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

void deleteNode(Node* &head, int position){
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp -> next = NULL;
        head -> prev = NULL;
        delete temp;
        return;
    }

    Node* temp = head;
    int count = 2;
    while(count != position){
        count++;
        temp = temp-> next;
    }
    Node* deleted = temp -> next;
    temp-> next = temp-> next-> next;
    deleted -> next -> prev = deleted -> next -> prev -> prev;
    deleted -> next = NULL;
    deleted -> prev = NULL;
    delete deleted;
    return;

}

int printReverse(Node* head){
    Node* temp = head;
    while(temp -> next !=NULL){
        temp = temp->next;
    }
    while(temp != NULL){
        cout<< temp-> data<<" ";
        temp = temp -> prev;
    }
}

void insertAtPosition(Node* &head, int data, int position){
    if(position == 1){
        insertAtHead(head, data);
        return;
    }
    int count = 2;
    Node* temp = head;

    while(count != position){
        count++;
        temp = temp -> next;

    }
    Node* node = new Node(data);
    node -> next = temp -> next;
    temp -> next = node;
    node -> prev = temp;
    node -> next -> prev = node;
    return;
}
int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    print(head);
    cout << getLength(head) << endl;
    insertAtHead(head, 20);
    insertAtTail(head, 30);
    insertAtPosition(head, 40, 2);
    deleteNode(head, 3);
     print(head);
    printReverse(head);

}
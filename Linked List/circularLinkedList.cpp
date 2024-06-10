#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int value = this-> data;
        if(next != NULL){
            delete next;
        }
        next = NULL;
    }
};

void print(Node* tail){
    Node* temp = tail;
    cout << tail->data << " ";

    do{
        cout << tail -> data << " ";
        tail = tail -> next;
    }while(tail != temp);

    cout << " ";
}

void deleteNode(Node* &tail, int value){
    if(tail == NULL){
        cout << "List is empty, please check again"<<endl;
        return;
    }
    else{
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr-> data != value){
            prev = curr;
            curr = curr -> next;   
        }
        prev -> next = curr -> next;
        if(tail == curr){
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}

void insertNode(Node* &tail, int element, int data){
    if(tail == NULL){
        Node* tail = new Node(data);
        tail -> next = tail;
        return;
    }
    else{
        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }
        Node* temp = new Node(data);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}
int main(){
    Node* tail = NULL;
    insertNode(tail, 5 , 3);
    return 0;
}
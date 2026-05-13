#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next ;
    Node *prev ;
};

Node* head = NULL;

void insertFirst(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL ;

    head = newNode ;
}
void insertLast(int val){

    Node *newNode = new Node() ;

    newNode->data = val ;

    Node *temp = head  ;

    while(temp->next!=NULL){
        temp= temp->next ;
    }
    newNode->prev=temp;
    newNode->next=NULL;
    temp->next=newNode ;
}
void inset_anywhere(int val , int pos){


    Node *newNode = new Node();
    newNode->data = val ;

    Node *temp = head ;

    int cnt = 1;

    while(cnt!=pos){
        temp = temp->next ;
        cnt++ ;
    }

    newNode->prev = temp ;
    newNode->next = temp->next ;

    temp->next = newNode ;

}
void deleteFirst(){

    head = head->next ;
}
void deleteLast(){

    Node *temp = head ;

    while(temp->next!= NULL){
        temp= temp->next ;
    }

    temp->prev->next = NULL ;

}
void deleteAny(int val){

    Node *temp = head ;

    while(temp->data!=val){
        temp= temp->next;
    }

    temp->prev->next = temp->next ;
    temp->next->prev = temp->prev ;




}
void printList() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main() {
    insertFirst(3);
    insertFirst(2);
    insertFirst(1);
    insertLast(1500);
    insertLast(1000) ;
    insertLast(600) ;
    inset_anywhere(900,3);

    deleteFirst();
    deleteLast() ;

    //deleteAny(900);

    printList() ;




    return 0;
}


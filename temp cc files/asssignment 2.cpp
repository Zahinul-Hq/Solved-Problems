#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next ;
    node *prev ;
};

Node* head = NULL;

void insertFirst(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL ;

    head = newNode ;
}

void insertLast(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void insertAnywhere(int value, int position) {
    if (position < 0) {
        cout << "Invalid position" << endl;
        return;
    }

    if (position == 0) {
        insertFirst(value);
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    Node* temp = head;
    int count = 0;
    while (count < position - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (temp->next == head && count != position - 1) {
        cout << "Invalid position" << endl;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFirst() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    if (head->next == head) {
        head = NULL;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        head = temp->next;
    }
}

void deleteLast() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    if (head->next == head) {
        head = NULL;
    } else {
        Node* temp = head;
        Node* prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
    }
}

void deleteAnywhere(int position) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    if (position < 0) {
        cout << "Invalid position." << endl;
        return;
    }

    if (position == 0) {
        deleteFirst();
        return;
    }

    Node* temp = head;
    Node* prev = NULL;
    int count = 0;
    while (count < position && temp->next != head) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp->next == head && count != position) {
        cout << "Invalid position" << endl;
        return;
    }

    prev->next = temp->next;
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

int getSize() {
    if (head == NULL) {
        return 0;
    }

    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

bool search(int value) {
    if (head == NULL) {
        return false;
    }

    Node* temp = head;
    do {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    } while (temp != head);
    return false;
}

int main() {
    insertFirst(3);
    insertFirst(2);
    insertFirst(1);
    insertLast(4);
    insertAnywhere(5, 2);

    printList();
    cout << "Size: " << getSize() << endl;

    deleteFirst();
    deleteLast();
    deleteAnywhere(1);

    cout<<"Printing after deletation"<<endl;
    printList();

    cout << "Size after deletation: " << getSize() << endl;

    cout << "Search 3: " << (search(3) ? "Found" : "Not found") << endl;
    cout << "Search 5: " << (search(5) ? "Found" : "Not found") << endl;

    return 0;
}

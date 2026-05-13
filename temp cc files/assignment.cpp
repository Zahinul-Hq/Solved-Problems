#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
    node *prev ;
};

node *a, *b, *c, *d;

void searching(int val) {
    node *curr_node = a;
    while (curr_node != NULL) {
        if (curr_node->data == val) {
            cout << "found" << endl;
            return;
        }
        curr_node = curr_node->next;
    }
    cout << "not found" << endl;
}

void l_size() {
    node *curr_node = a;
    int sz = 0;
    while (curr_node != NULL) {
        sz++;
        curr_node = curr_node->next;
    }
    cout << "size = " << sz << endl;
}

void print() {
    node *curr_node = a;
    while (curr_node != NULL) {
        cout << curr_node->data << endl;
        curr_node = curr_node->next;
    }
}

void insert_first(int val) {
    node *new_node = new node();
    new_node->data = val;
    new_node->next = a;
    a= new_node ;
}

void insert_last(int val) {
    node *new_node = new node();
    new_node->data = val;
    new_node->next = NULL;

    if (a == NULL) {
        a = new_node;
        return;
    }

    node *last_node = a;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }

    last_node->next = new_node;
}

void insert_anywhere(int val, int pos) {
    node *new_node = new node();
    new_node->data = val;

    node *prev_node = a;
    int current_pos = 1;

    while (prev_node != NULL && current_pos < pos ){
        prev_node = prev_node->next;
        current_pos++;
    }

    new_node->next = prev_node->next;
    prev_node->next = new_node;
}
void deleteFirst() {
    node* first_node = a;
    a = a->next;
}
void deleteLast() {
    node* last_node = a;
    node* prev_node = NULL;

    while (last_node->next != NULL) {
        prev_node = last_node;
        last_node = last_node->next;
    }

    prev_node->next = NULL;
}
void deleteAnywhere(int value) {
        node* current = a;
        node* prev = NULL;

        while (current != NULL) {
            if (current->data == value) {
                // If the node to be deleted is the head node
                if (prev == NULL) {
                    current = current->next;
                } else {
                    prev->next = current->next;
                }
                return;
            }
            prev = current;
            current = current->next;
        }
}


int main() {
    a = new node();
    b = new node();
    c = new node();
    d = new node();

    a->data = 10;
    a->next = c;
    b->data = 30;
    b->next = NULL;
    c->data = 30;
    c->next = d;
    d->data = 20;
    d->next = b;

    print();
    int val = 30;
    searching(val);
    l_size();

    int x ;

    cin>>x ;



    insert_first(5);
    insert_last(40);
    insert_anywhere(25, 1);
    insert_first(x) ;

    cout << "After insertion:" << endl;
    print();
    l_size();
    deleteFirst();
    deleteLast();
    deleteAnywhere(25);
    cout<<"After deletation"<<endl;
    print();
    l_size();
    return 0;
}

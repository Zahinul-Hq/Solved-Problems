#include<bits/stdc++.h>
using namespace std ;
struct node{

    int data ;

    node *next ;

};
node *A ,*B , *C ,*D , *root=NULL ;
void print(){

    node *currnode = A;

    while(currnode->next!=NULL){



        currnode=currnode->next ;
    }
    cout<<currnode->data<<endl;
}
void search(int val) {  

    node *curr_node = A;

    while (curr_node != NULL) {       

            if (curr_node->data == val) {  

                cout << "found" << endl;   

                return;         
            }       

    curr_node = curr_node->next;     
    }     

    cout << "not found" << endl; 
}
void delete_first(){

    if(root!=NULL)
        root=root->next ;
    else
        cout<<"ar hbena bacha"<<endl;
}
void delete_last(){

    node* last_node = A;

    node* prev_node = NULL;

    while (last_node->next != NULL) {    

        prev_node = last_node;         
        last_node = last_node->next;     
    }     

    prev_node->next = NULL; 
    
}
void deleteAnywhere(int value) {  

    node* current = A;         
    node* prev = NULL;         
    while (current != NULL) {  

        if (current->data == value) {                
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
void insert_first(int val){

    node *temp ;

    temp = new node () ;
    temp->data = val ;
    temp->next = NULL;

    if(root == NULL){
        root =temp ;
    }else{

        temp->next=root ;
        root = temp ;
    }

}
void insert_last(int val){

    node *temp ;

    temp = new node () ;
    temp->data = val ;
    temp->next = NULL;

    if(root == NULL){
        root =temp ;
    }else{

        node *cn= root ;
        while(cn->next!=NULL){
                cn=cn->next ;
            
        }
        cn->next = temp ;
    }

}
void insert_anywhere(int val, int pos) {   

    node *new_node = new node(); 

    new_node->data = val;     
    node *prev_node = A;  

    int current_pos = 0;   

    while (prev_node != NULL && current_pos < pos - 1) {
        prev_node = prev_node->next;         
        current_pos++;     
    }  

    new_node->next = prev_node->next;

    prev_node->next = new_node; 
}
void siz(){

    node *curr= A;     
    int s = 0;     
    while (curr!= NULL) {  
            s++;         
    curr = curr->next;     
    }     
    cout << "size = " << s << endl; 
} 
int main(){

    A = new node();     
    B = new node();     
    C = new node();     
    D = new node();     
    A->data = 100;     
    A->next = C;     
    B->data = 300;     
    B->next = NULL;     
    C->data = 50;     
    C->next = D;     
    D->data = 400;     
    D->next = B;     
    print();     
    int val = 30;     
    search(val);     
    siz();     
    insert_first(5);        
    insert_last(40);             
    insert_anywhere(25, 1);     
    cout << "After insert" << endl;     
    print();    
    siz();


    delete_first();     
    delete_last();     
    deleteAnywhere(25);     
    cout<<"After delete"<<endl;     
    print();     
    siz();     
    return 0; 
}

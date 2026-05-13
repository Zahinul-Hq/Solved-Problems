
#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

void inout()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}

struct node{

    int data ;
    node *next ;
    node *prev ;
};

node *root=NULL ;

void inff(int val){

    node *temp  ;

    temp = new node() ;

    temp->data =val ;

    temp->next = NULL ;
    temp->prev = NULL;

    if(root==NULL){
        root =temp ;
    }else{

        temp->next=root ;

        root->prev = temp ;

        root = temp ;

    }
}
void inll(int val){

    node *temp  ;

    temp = new node() ;

    temp->data =val ;

    temp->next = NULL ;
    temp->prev = NULL;

    if(root==NULL){
        root =temp ;
    }else{

        node *temp2;
        temp2 =new node() ;

        temp2 =root ;

        while(temp2->next!=NULL){
            temp2 = temp2->next ;
        }
        temp->prev= temp2 ;
        temp2->next = temp ;
    }
}

void inany(int val, int pos){

    int i = 0 ;

    node *temp , *temp2;

    temp = new node() ;

    temp->data= val ;
    temp->next =NULL ;
    temp->prev = NULL ;

    temp2= root ;

    while(++i){

            if(pos==i){
                temp2->prev =
            }

    }






}


void prnnnt(){

    node *temp ;

    temp = new node() ;
    temp = root ;

    while(1){

        cout<<temp->data<<" ";

        if(temp->next==NULL)
            break;

        temp=temp->next ;
    }
    cout<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;

	int n,x ;

	cin>>n ;

	while(n--){

        cin>>x ;

        in_last(x) ;
	}

	cin>>x>>n ;

	del_first() ;
	del_last() ;

	delany(n-1) ;
	prnnnt() ;

    return 0 ;
}

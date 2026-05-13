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

const int N = 1e5 + 7;
struct node_val{
	int zero_xor;
	int one_xor;
};

node_val t[4*N];
bool lazy[4*N];
int arr[N];
string str;

void push(int node, int start, int end){

	if(lazy[node] == 0){
		return;
	}

	swap(t[node].zero_xor, t[node].one_xor);

	if(start != end){

		lazy[node * 2] ^= 1 ;
		lazy[node * 2 + 1] ^= 1 ;

	}

	lazy[node] = 0;
}


node_val combine(node_val l_node, node_val r_node){

	node_val res = {0, 0};
	res.zero_xor = l_node.zero_xor ^ r_node.zero_xor;
	res.one_xor = l_node.one_xor ^ r_node.one_xor;

	return res;
}

void build(int node, int start, int end){
	lazy[node] = 0;

	if(start == end){
		if(str[start] == '1'){
			t[node].one_xor = arr[start];
			t[node].zero_xor = 0;
		}else{
			t[node].zero_xor = arr[start];
			t[node].one_xor = 0;
		}
		return ;
	}

	int mid = (start + end) / 2;

	build(node * 2, start, mid);
	build(node * 2 + 1, mid + 1, end);

	t[node] = combine(t[node * 2], t[(node * 2) + 1]);
}
void update(int node, int start, int end, int i, int j){

	push(node, start, end);

	if(start > j || end < i)
		return;

	if(start >= i && j >= end){
		lazy[node] = 1;
		push(node, start, end);
		return;
	}

	int mid = (start + end) / 2;

	update(node * 2, start, mid, i, j);
	update(node * 2 + 1, mid + 1, end, i, j);

	t[node] = combine(t[node * 2], t[(node * 2) + 1]);
}
node_val query(int node, int start, int end, int i, int j){

	push(node, start, end);

	if(start > j || end < i)
		return {0,0};

	if(i <= start && end <= j){
		return t[node];
	}

	int mid = (start + end) / 2;

	return combine(query(node * 2, start, mid, i, j),
				query(node * 2 + 1, mid + 1, end, i, j));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int tc;
    cin >> tc;

    while(tc--){

    	int n, q;
    	cin >> n;
    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    	}
    	cin >> str;
    	cin >> q;
    	build(1, 0, n - 1);
    	
    	while(q--){
    		int l , r, type, val;

    		cin >> type;
    		if(type == 1){
    			cin >> l >> r;
    			update(1, 0, n - 1, l - 1, r - 1);
    		}else{
    			cin >> val;
    			node_val aa = query(1,0, n -  1, 0, n - 1);
    			if(val == 0){
    				cout << aa.zero_xor << " ";
    			}else{
    				cout << aa.one_xor << " ";
    			}
    		}
    	}

    	cout << endl;
    }

    
    
    return 0 ;
}

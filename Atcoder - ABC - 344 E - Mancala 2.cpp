#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
//typedef __int128 lll;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

 
void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}
const int N = 2e5 + 7;


ll t[4*N];
ll lazy[4*N];
ll arr[N];

void push(int node, int start, int end){

	if(lazy[node] == 0){
		return;
	}
	t[node] += lazy[node];
	if(start != end){

		lazy[node * 2] += lazy[node] ;
		lazy[node * 2 + 1] += lazy[node] ;

	}
	lazy[node] = 0;
}

ll combine(ll l_node, ll r_node){
	ll res = max(l_node, r_node);
	return res;
}

void build(int node, int start, int end){
	lazy[node] = 0;

	if(start == end){
		t[node] = arr[start];
		return ;
	}

	int mid = (start + end) / 2;

	build(node * 2, start, mid);
	build(node * 2 + 1, mid + 1, end);

	t[node] = combine(t[node * 2], t[(node * 2) + 1]);
}
void update(int node, int start, int end, int i, int j, ll value){

	push(node, start, end);

	if(start > j || end < i)
		return;

	if(start >= i && j >= end){
		lazy[node] += value;
		push(node, start, end);
		return;
	}

	int mid = (start + end) / 2;

	update(node * 2, start, mid, i, j, value);
	update(node * 2 + 1, mid + 1, end, i, j, value);

	t[node] = combine(t[node * 2], t[(node * 2) + 1]);
}
ll query(int node, int start, int end, int i, int j){

	push(node, start, end);

	if(start > j || end < i)
		return 0;

	if(i <= start && end <= j){
		return t[node];
	}

	int mid = (start + end) / 2;

	return combine(query(node * 2, start, mid, i, j),
				query(node * 2 + 1, mid + 1, end, i, j));
}
//modify combine, node_val, lazy

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    ll n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
    build(1, 0, n - 1);


    while(q--){
    	ll c = 0, b;
    	cin >> b;

    	ll val = query(1, 0, n - 1, b, b);
    	
    	update(1, 0, n - 1, b, b, - val);
    	
    	ll d = val / n;
    	ll m = val % n;
    	if(d)
    		update(1, 0, n - 1, 0, n - 1, d);
    	if(m){
    		int no_upd = n - m;
    		int pos = b % n;

    		int lf =   m - (n - 1 - pos) ;

    		update(1, 0 , n - 1, pos + 1 % n , min(pos + m, n - 1), 1);

    		if(lf)
    			update(1, 0, n - 1, 0, lf - 1, 1);

    	}

    	

    }
    for(int i = 0; i < n; i++){
    		cout << query(1, 0, n - 1, i, i) << " ";
    	}
    	cout << endl;
    return 0 ;
}

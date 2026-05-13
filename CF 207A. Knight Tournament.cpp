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

 
#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
const int N = 3e5 + 7;

ll t[4*N];
int lazy[4*N];
int arr[N];

struct Q{
	int l, r, x;
};

ll combine(ll a, ll b){

	if(a != -1)
		return a;

	return b;

}

void push(int node, int start, int end){

	if(lazy[node] == 0){
		return;
	}
	t[node] = lazy[node];
	if(start != end){

		lazy[node * 2] = lazy[node] ;
		lazy[node * 2 + 1] = lazy[node] ;

	}
	lazy[node] = 0;
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

	//t[node] = combine(t[node * 2], t[(node * 2) + 1]);
}
void update(int node, int start, int end, int i, int j, int value){

	push(node, start, end);

	if(start > j || end < i)
		return;

	if(start >= i && j >= end){
		lazy[node] = value;
		push(node, start, end);
		return;
	}

	int mid = (start + end) / 2;

	update(node * 2, start, mid, i, j, value);
	update(node * 2 + 1, mid + 1, end, i, j, value);

	//t[node] = combine(t[node * 2], t[(node * 2) + 1]);
}
ll query(int node, int start, int end, int i, int j){

	push(node, start, end);

	if(start > j || end < i)
		return -1;

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
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int n, m, l ,r, x;
    cin >> n >> m;

    build(1, 0, n);

    vector<Q>qr;


    for(int i = 0; i < m; i++){
    	cin >> l >> r >> x;
    	qr.push_back({l, r, x});
    }

    for(int i = m - 1; i >= 0; i--){
    	if(qr[i].l == qr[i].x){
    		update(1, 0, n, qr[i].l + 1, qr[i].r, qr[i].x);
    	}else if(qr[i].r == qr[i].x){
    		update(1, 0, n, qr[i].l, qr[i].r - 1, qr[i].x);
    	}else{
    		update(1, 0, n, qr[i].l, qr[i].x - 1, qr[i].x);
    		update(1, 0, n, qr[i].x + 1, qr[i].r, qr[i].x);

    	}
    }

    for(int j = 1; j <= n; j++){
    	cout << query(1, 0, n, j, j) << " ";
    }
    cout << endl;

    

    return 0 ;
}

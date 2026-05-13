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

ll t[4*N], lazy[4*N];
int arr[N];

void push(int node, int start, int end){

	if(lazy[node] == 0){
		return;
	}

	t[node] = max(t[node] ,lazy[node]);

	if(start != end){

		lazy[node * 2] = max(lazy[node * 2],lazy[node]) ;
		lazy[node * 2 + 1] = max(lazy[node * 2], lazy[node]) ;

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

	build(node*2, start, mid);
	build(node*2 + 1, mid + 1, end);

	t[node] = max(t[node * 2] , t[node*2 + 1]);

}
void update(int node, int start, int end, int i, int j, ll value){

	push(node, start, end);

	if(start > j || end < i)
		return;

	if(start >= i && j >= end){
		lazy[node] = max(lazy[node],value);
		push(node, start, end);
		return;
	}

	int mid = (start + end) / 2;

	update(node*2, start, mid, i, j, value );
	update(node*2 + 1, mid + 1, end, i, j, value);

	t[node] = max(t[node * 2] , t[node*2 + 1]);
}
ll query(int node, int start, int end, int i, int j){

	push(node, start, end);

	if(start > j || end < i)
		return 0;

	if(i <= start && end <= j){
		return t[node];
	}

	int mid = (start + end) / 2;

	return max(query(node*2, start, mid, i, j),
				query(node*2 + 1, mid + 1, end, i, j));

	
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int n, m, p;


    cin >> n >> m;

    build(1, 0, n - 1);

    while(m-- ){

    	cin >> p;

    	int l, r, val;

	    if(p == 1){

	    	int l, r, val;

	    	cin >> l >> r >> val;

	    	update(1, 0, n - 1 , l, --r, val);

	    }else if (p == 2){

	    	int pos;

	    	cin >> pos;

	    	ll ans = query(1, 0, n - 1, pos, pos);

	    	cout << ans << endl;
	    }
    }
    return 0 ;
}

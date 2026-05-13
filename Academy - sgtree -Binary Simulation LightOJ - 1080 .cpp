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

const int N = 4e5 + 7;

int t[N], lazy[N];
string arr;

void push(int node, int start, int end){

	if(lazy[node] == 0){
		return;
	}

	t[node] = t[node] ^ 1;

	if(start != end){

		lazy[node * 2] ^= 1 ;
		lazy[node * 2 + 1] ^= 1 ;

	}

	lazy[node] = 0;
}

void build(int node, int start, int end){

	lazy[node] = 0;

	if(start == end){
		t[node] = arr[start] - '0';
		return ;
	}

	int mid = (start + end) / 2;

	build(node*2, start, mid);
	build(node*2 + 1, mid + 1, end);

}
void update(int node, int start, int end, int i, int j, ll value){

	push(node, start, end);

	if(start > j || end < i)
		return;

	if(start >= i && j >= end){
		lazy[node] = 1 ;
		push(node, start, end);
		return;
	}

	int mid = (start + end) / 2;

	update(node*2, start, mid, i, j, value );
	update(node*2 + 1, mid + 1, end, i, j, value);

}
ll query(int node, int start, int end, int i, int j){

	push(node, start, end);

	if(start > j || end < i)
		return 0;

	if(i <= start && end <= j){
		return t[node];
	}

	int mid = (start + end) / 2;

	if(i <= mid)
		return query(node*2, start, mid, i, j);
	else
		return query(node*2 + 1, mid + 1, end, i, j);
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int tr , cs = 1;

    cin >> tr;

    while(tr--){

    	int n, m;

    	char p;

    	memset(t, 0, sizeof t);
    	//memset(lazy, 0, sizeof lazy);

	    cin >> arr >> m;

	    n = arr.size();



	    build(1, 0, n - 1);

	    cout << "Case " << cs++ << ": " << endl; 

	    while(m-- ){

	    	cin >> p;

	    	int l, r, val;

		    if(p == 'I'){

		    	int l, r;

		    	cin >> l >> r ;

		    	update(1, 0, n - 1 , --l, --r, 1);

		    }else {

		    	int pos;

		    	cin >> pos;

		    	--pos;

		    	ll ans = query(1, 0, n - 1, pos, pos);

		    	cout << ans << endl;
		    }
	    }


	    

    }
    return 0 ;
}

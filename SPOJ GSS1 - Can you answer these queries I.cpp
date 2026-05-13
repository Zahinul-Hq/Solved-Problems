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

int arr[N];

struct node{
	ll sum, pref, suff, mx_val;
};

node tree[4*N];

node merge(node l , node r){

	node p;

	p.sum = l.sum + r.sum;

	p.pref = max(l.pref, l.sum + r.pref);
	p.suff = max(r.suff, r.sum + l.suff);

	p.mx_val = max({l.mx_val, r.mx_val, l.suff + r.pref});

	return p;
}

void build(int v, int start, int end){

	if(start == end){
		tree[v].sum = tree[v].pref = tree[v].suff = tree[v].mx_val = arr[start];
		return;
	}

	int mid = (start + end) / 2;

	build(v * 2 , start, mid);
	build(v * 2 + 1, mid + 1, end);

	tree[v] = merge(tree[2 * v ] , tree[2 * v + 1]);

}

node query(int v, int lf, int rt, int start, int end){

	if(start > rt || end < lf)
		return {-100000,-100000,-100000,-100000};

	if(start >= lf && end <= rt)
		return tree[v];


	int mid = (start + end) / 2;


	return merge(query(v * 2, lf, rt, start, mid), query(v * 2 + 1, lf, rt, mid + 1, end));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
    build(1, 0, n -  1);
    int m ; cin >> m;

    while(m--){
    	int i , j;

    	cin >> i >> j;

    	node ans = query(1, i - 1, j - 1, 0, n -  1);

    	cout << ans.mx_val << endl;
    }
    return 0 ;
}

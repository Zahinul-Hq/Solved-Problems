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

const int N = 1e5 + 7, B = 20;

struct val{
	int on_bit[B], off_bit[B];
};
val t[4*N];

int lazy[4*N];
int arr[N];

val add(val l, val r){

	val ans ;

	for(int k = 0; k < B; k++){
		ans.on_bit[k] = l.on_bit[k] + r.on_bit[k];
		ans.off_bit[k] = l.off_bit[k] + r.off_bit[k];
	}

	return ans ;
}




void push(int node, int start, int end){

	if(lazy[node] == 0 ){
		return;
	}

	for(int k = 0; k < B; k++){
		if(lazy[node] >> k & 1)
			swap(t[node].off_bit[k], t[node].on_bit[k]);
	}

	if(start != end){

		lazy[node * 2] ^= lazy[node]  ;
		lazy[node * 2 + 1] ^=  lazy[node] ;
		
	}

	lazy[node] = 0;
}

void build(int node, int start, int end){

	lazy[node] = 0;

	if(start == end){
		
		for(int k = 0; k < B; k++){

			if(arr[start] >> k & 1){
				t[node].on_bit[k] = 1;
				t[node].off_bit[k] = 0;

			}else{
				t[node].on_bit[k] = 0;
				t[node].off_bit[k] = 1;
			}
		}
		return ;
			
	}

	int mid = (start + end) / 2;

	build(node*2, start, mid);
	build(node*2 + 1, mid + 1, end);

	t[node] = add(t[node * 2] , t[node*2 + 1]) ;

}
void update(int node, int start, int end, int i, int j, ll value){

	push(node, start, end);

	if(start > j || end < i)
		return;

	if(start >= i && j >= end){
		lazy[node] = value ;
		push(node, start, end);
		return;
	}

	int mid = (start + end) / 2;

	update(node*2, start, mid, i, j, value );
	update(node*2 + 1, mid + 1, end, i, j, value);

	t[node] = add(t[node * 2] , t[node*2 + 1]) ;
}
val query(int node, int start, int end, int i, int j){

	push(node, start, end);

	if(start > j || end < i){
		val zero;

		memset(zero.off_bit, 0, sizeof zero.off_bit);
		memset(zero.on_bit, 0, sizeof zero.on_bit);

		return zero;

	}
		

	if(i <= start && end <= j){
		return t[node];
	}

	int mid = (start + end) / 2;

	return add(query(node*2, start, mid, i, j) ,
				query(node*2 + 1, mid + 1, end, i, j)) ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int n, m, p;


    cin >> n ;

    for(int i = 1; i <= n ; i++){
    	cin >> arr[i];
    }

    build(1, 1, n);

    cin >> m;


    while(m-- ){

    	cin >> p;

    	

	    if(p == 2){

	    	int l, r, val;

	    	cin >> l >> r >> val;

	    	update(1, 1, n , l, r, val);

	    }else{

	    	int l, r;

	    	cin >> l >> r ;

	    	val ans = query(1, 1, n, l, r);

	    	ll sum = 0;

	    	for(int k = 0; k < B; k++){

	    		sum += (1LL * ans.on_bit[k] * (1 << k));

	    	}

	    	cout << sum  << endl;
	    }
    }

    return 0 ;
}

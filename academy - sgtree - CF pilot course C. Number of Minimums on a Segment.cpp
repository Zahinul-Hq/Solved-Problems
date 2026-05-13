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
const int N = 1e5+7 ;
pair<int,int> t[4*N] ;

pair<int, int>combine(pair<int, int>a, pair<int,int>b){

	if(a.first == b.first)
		return {a.first, a.second + b.second};

	return min(a,b);

}

void build(int a[], int v, int tleft, int tright){
 
	if(tleft == tright){
		t[v] = {a[tleft], 1} ;
	}else{
 
		int tmid = (tleft + tright) / 2 ;

		build(a, v*2, tleft , tmid) ;
		build(a, v*2 + 1, tmid+1 , tright) ;

		t[v] = combine(t[v*2], t[v*2+1]);
	}
}
 
pair<int,int> query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return {INT_MAX, 0};

    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;

    return combine(query(v*2, tl, tm, l, min(r, tm)), 
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
   	
}
void update(int v , int tl , int tr , int pos , int val){
 
	if(tl == tr){
		t[v]= {val, 1};
	}
	else{
 
		int tm = (tl+tr)/2 ; 
 
		if(pos <= tm){
			update(v*2 , tl ,tm , pos , val ) ;
		} else {
			update(v*2+1, tm+1 , tr , pos ,val ) ;
		}

		t[v] = combine(t[v*2], t[v*2+1]);

	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;
 
    int n, m;
    cin >> n >> m  ;
 
    int arr[n+1] ;
 
 
    for(int i = 0; i < n; i++){
 
    	cin >> arr[i] ;
    }
 
    build(arr, 1, 0 , n-1 ) ;
 
    int p , indx1 , indx2 ;
 
    while(m--){
 
    	cin >> p >> indx1 >> indx2 ;
 
    	if(p == 1){
 
    		update(1, 0, n - 1, indx1, indx2) ;
    	}else{
 
    		pair<int, int> x = query(1, 0, n - 1, indx1, indx2 - 1) ;
 
    		cout << x.first << " " << x.second << endl; 
    	}
 
    }
    
   
    return 0 ;
}
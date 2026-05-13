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
const int N = 2e5+7 ;

int arr[N] ;
ll t[4*N] ;

void build( int v, int tleft, int tright, int lvl){
 
	if(tleft == tright){
		t[v] = arr[tleft] ;
	}else{
 
		int tmid = (tleft + tright) / 2 ;

		build( v*2, tleft , tmid , lvl - 1 ) ;
		build( v*2 + 1, tmid+1 , tright, lvl - 1) ;


		if((int)log2(tright - tleft + 1) % 2 == 0)
			t[v] = (t[v*2] ^ t[v*2+1]);
		else
			t[v] = t[v*2] | t[v*2+1] ;
	}
}
/* 
ll query(int v, int tl, int tr, int l, int r, int lvl) {
    if (l > r) 
        return 0 ;

    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;


    if((int)log(tr - tl + 1) % 2 == 0)
    	return (query(v*2, tl, tm, l, min(r, tm), lvl - 1) ^
                   query(v*2+1, tm+1, tr, max(l, tm+1), r, lvl - 1));
    else
    	return (query(v*2, tl, tm, l, min(r, tm), lvl - 1) |
                   query(v*2+1, tm+1, tr, max(l, tm+1), r, lvl - 1));

   	
}*/
void update(int v , int tl , int tr , int pos , int val, int lvl ){
 
	if(tl == tr){
		t[v]= val;
	}
	else{
 
		int tm = (tl+tr)/2 ; 
 
		if(pos <= tm){
			update(v*2 , tl ,tm , pos , val, lvl - 1 ) ;
		} else {
			update(v*2+1, tm+1 , tr , pos ,val, lvl - 1 ) ;
		}

		if((int)log2(tr - tl + 1) % 2 == 0)
			t[v] = (t[v*2] ^ t[v*2+1]);
		else
			t[v] = t[v*2] | t[v*2+1] ;

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

    n = 1 << n;

 
    for(int i = 1; i <= n; i++){
 
    	cin >> arr[i] ;
    }
 
    build( 1, 1 , n, n) ;
 
    int pos, val, indx1 , indx2 ;
	
	
    while(m--){
 
    	cin >> pos >> val ;

    	
    	update(1, 1, n , pos, val, n );


    	cout << t[1] << endl;
 
    }
    
   
    return 0 ;
}
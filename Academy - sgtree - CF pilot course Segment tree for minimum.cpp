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
pair<int ,int> t[4*N] ;

pair<int,int>combine(pair<int,int>a , pair<int , int>b){

	if(a.first<b.first)
		return a ;
	if(b.first<a.first)
		return b ;

	return make_pair(a.first , a.second+b.second) ;
}

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_pair(a[tl], 1);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}
pair<ll, ll> get_min(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return make_pair(inf, 0);
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(get_min(v*2, tl, tm, l, min(r, tm)), 
                   get_min(v*2+1, tm+1, tr, max(l, tm+1), r));
}
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = make_pair(new_val, 1);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

       int n ,m  ;
    cin>>n>>m  ;

    int arr[n+1] ;


    for(int i=0 ; i<n ; i++){

    	cin>>arr[i] ;
    }

    build(arr, 1, 0 , n-1 ) ;

    int p , indx1 , indx2 ;

    while(m--){

    	cin>>p>>indx1>>indx2 ;

    	if(p==1){

    		update(1, 0 , n-1 ,  indx1 , indx2) ;
    	}else{

    		pair<int, int>x = get_min(1 , 0 , n-1 , indx1 , indx2 -1) ;

    		cout<<x.first<<endl; 
    	}


    }
    
   
    return 0 ;
}

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
const int N = 1e5+9 ;


struct node{

	int first_element, last_element,
	first_element_freq, last_element_freq,
	mx_segement_size;
};
node t[4*N] ;

node merge(node l, node r){

	if(l.first_element == -1)
		return r;
	if(r.first_element == -1)
		return l;

	node ans;
	ans.first_element = l.first_element; 
	ans.last_element =  r.last_element;
	ans.first_element_freq = l.first_element_freq;
	ans.last_element_freq = r.last_element_freq;
	

	if(l.first_element == r.first_element)
		ans.first_element_freq += r.first_element_freq;

	if(l.last_element == r.last_element)
		ans.last_element_freq += r.last_element_freq;


	ans.mx_segement_size = max(l.mx_segement_size, r.mx_segement_size);

	if(l.last_element == r.first_element)
		ans.mx_segement_size = max(ans.mx_segement_size, l.last_element_freq + r.first_element_freq);


	return ans;


}

void build(int a[], int v, int tl, int tr){
 
	if(tl == tr){
		t[v].first_element = t[v].last_element = a[tl];
		t[v].first_element_freq = t[v].last_element_freq = 1;
		t[v].mx_segement_size = 1;
	}else{
 
		int tmid = (tl + tr) / 2 ;

		build(a, v*2, tl , tmid) ;
		build(a, v*2 + 1, tmid+1 , tr) ;

		t[v] = merge(t[v*2], t[v*2+1]);
	}
}
 
node query(int v, int tl, int tr, int l, int r) {
    if ( tr < l or tl > r ) 
        return {-1, -1, -1, -1, -1};

    if (l <= tl && r >= tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;

    return merge(query(v*2, tl, tm, l, r), 
                   query(v*2+1, tm+1, tr, l, r));
   	
}
/*void update(int v , int tl , int tr , int pos , int val){
 
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
}*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;
 
   int t, x = 1;

    cin >> t;

    while(t--){

    	int n, m, c  ;

	    cin >> n >> c >> m  ;
	 
	    int arr[n + 1] ;
	 
	    for(int i = 1; i <= n; i++){
	    	cin >> arr[i] ;
	    }
	 
	    build(arr, 1, 1, n) ;
	 
	   int i, j;

	    cout << "Case " << x++ << ":" << endl;
	 
	    while(m--){

	    	cin >> i >> j;

	    	i, j;

	    	node ans = query(1, 1 , n, i, j);

	    	cout << ans.mx_segement_size << endl;

	 
	    }

    }
    
   
    return 0 ;
}
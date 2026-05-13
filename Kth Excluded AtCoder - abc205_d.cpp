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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    ll n, q, k;
    cin >> n >> q;
    vector<ll>arr(n), lw(n);
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
    	lw[i] = arr[i] - (i + 1);
    }
    while(q--){
    	
    	cin >> k;

    	int p = lower_bound(lw.begin(), lw.end(), k) - lw.begin();
    	if(p == n){
    		cout << arr[n - 1] + k - lw[n - 1] << endl;
    	}else{
    		cout << arr[p] + k - lw[p] - 1 << endl;
    	}
    }
    return 0 ;
}

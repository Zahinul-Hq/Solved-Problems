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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int n, k;
    cin >> n >> k;
    vector<int>a(n), b(n), ans(n);

    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int i = 0; i < n; i++){
    	cin >> b[i];
    }

    for(int i = n - 1; i >= 0; i--){
    	if(k <= 0)
    		break;
    	ans[i] = min(a[i] / b[i], k);

    	k -= ans[i];
    }
    if(k != 0){
    	for(int i = 0; i < n; i++){
	    	cout << 0 << " ";
	    }

	    cout << endl;

	    return 0;

    }

    for(int i = 0; i < n; i++){
    	cout << ans[i] << " ";
    }

    cout << endl;



    return 0 ;
}

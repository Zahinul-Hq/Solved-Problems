#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
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

    int n, k;

    cin >> n >> k;

    vector<ll>arr(n + 1), check(n + 1);

    for(int i = 1; i <= n; i++){
    	cin >> arr[i];
    }
    for(int i = 1; i <= n; i++){
    	cin >> check[i];
    }
    ll dp_pref[n + 1], dp_suff[n + 2], pref[n + 1];
    dp_pref[0] = dp_suff[n + 1] = pref[0] =0;

    for(int i = 1; i <= n; i++){
    	if(check[i])
    		dp_pref[i] = dp_pref[i - 1] + arr[i];
    	else
    		dp_pref[i] = dp_pref[i - 1];

    	pref[i] = pref[i - 1] + arr[i];
    }

    for(int i = n ; i >= 1; i--){
    	if(check[i])
    		dp_suff[i] = dp_suff[i + 1] + arr[i];
    	else
    		dp_suff[i] = dp_suff[i + 1];
    }

    ll ans = 0;

    for(int i = 1; i <= n - k + 1; i++){

    	ll tot = dp_pref[i - 1] + pref[i + k - 1] - pref[i - 1] + dp_suff[i + k ];
    	ans = max(ans, tot);
    }

    cout << ans << endl;

    return 0 ;
}

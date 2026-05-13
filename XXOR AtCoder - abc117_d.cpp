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
ll dp[50][2];
ll solve(int i, int n , ll k, bool t, ll sum, vector<int>&g, vector<ll>&val){
	ll ans = 0;
	if(i == g.size())
		return ans;
	if(dp[i][t] != -1)
		return dp[i][t];
	if(t){
		if((sum + (1 << g[i]) < k) )
			ans =max(ans ,(val[i]) * (1 << g[i]) + solve(i + 1, n, k, true, sum + (1 << g[i]), g, val));

		if((sum + (1 << g[i])) == k){
			ans =max(ans ,(val[i]) * (1 << g[i]) + solve(i + 1, n, k, false, sum + (1 << g[i]), g, val));

		}
	}

	

	ans = max(ans, solve(i + 1, n, k, t, sum, g, val));

	return dp[i][t] = ans;



}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    ll n, k;
    cin >> n >> k;
    vector<ll>arr(n, 0), vals(50, 0);

    memset(dp, -1, sizeof dp);

    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }

    for(int i = 0; i <= 40; i++){
    	for(int j = 0; j < n; j++){
    		if((arr[j] & (1 << i)) == 0){
    			vals[i]++;
    		}
    	}
    }
    vector<int>g;
    for(int i = 0; i <= 40; i++){
    	if(vals[i] > (n / 2)){
    		g.push_back(i);
    		
    	}
    }
    cout << solve(0, n, k, true, 0, g, vals) << endl;

    
    return 0 ;
}

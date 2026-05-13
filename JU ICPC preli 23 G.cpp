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
const int N = 8;

vector<int>a(N, 0), b(N, 0);
ll dp[N][N];
int n;
ll rec(int i, int j){
	if(i > n || j > n)
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];
	ll ans = rec(i + 1, j);

	if(a[i] == b[j]){
		ans = max(ans, rec(i + 1, j + 1) + 1);
	}

	return dp[i][j] = ans;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases, cs = 0 ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	cin >> n;

    	for(int i = 1; i <= n; i++){
    		cin >> a[i];
    	}

    	for(int i = 1; i <= n; i++){
    		cin >> b[i];
    	}

    	for(int i = 0; i <= n + 1; i++){
    		for(int j = 0; j <= n + 1; j++){
    			dp[i][j] = -1;
    		}
    	}

    	ll mx = 0;

    	for(int j = 1; j <= n; j++){
    		mx = max(mx, rec(1, j));
    	}
    	bool st = 1;
    	ll pref = max(dp[1][1], 0LL), suff = 0;

    	if(dp[1][1] != n){
    		for(int i = 1; i <= n; i++){
	    		if(dp[1][i] == n - i + 1){
	    			suff = dp[1][i];
	    		}
    		}

    	}


    	debug(dp);

    	cout << n - max(mx, pref + suff) << endl;
    }
    return 0 ;
}


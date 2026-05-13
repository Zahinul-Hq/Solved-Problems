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
map<ll, ll>dp;
map<ll, vector<ll>>mp;
ll solve(ll arr_size){

	if(dp[arr_size] != 0)
		return dp[arr_size];

	ll ans = 0;

	for(ll val : mp[arr_size]){
		ans = max(ans, val - 1 + solve(arr_size - 1 + val));
	}

	return dp[arr_size] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        ll n, x;
        cin >> n;
        mp.clear();
        dp.clear();

        for(int i = 1; i <= n; i++){
        	cin >> x;
        	if(i != 1)
        		mp[x + i - 1].push_back(i);
        }

        cout << solve(n) + n << endl;
    }
    return 0 ;
}

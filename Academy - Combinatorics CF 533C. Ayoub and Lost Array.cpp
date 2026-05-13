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
const int N = 2e5 + 9, mod = 1e9 + 7;
int n, l, r;

int count(int n , int k){
	if(k == 0)
		return n / 3;
	else if(k == 1)
		return n / 3  + ((n % 3) >= 1);  
	else
		return n / 3 + (n % 3 >= 2);
}
ll dp[N][3];
ll solve(int i, int sum){
	if(i == n + 1){
		return sum % 3 == 0;
	}

	if(dp[i][sum] != -1)
		return dp[i][sum];

	ll ans = 0;

	for(int k = 0; k < 3; k++){

		ans += solve(i + 1, (sum + k) % 3) * (count(r, k) - count(l - 1, k))  ;
		ans %= mod;
	}

	return dp[i][sum] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

	memset(dp, -1, sizeof dp);

	cin >> n >> l >> r;

	cout << solve(1, 0) << endl;

      
    
    return 0 ;
}

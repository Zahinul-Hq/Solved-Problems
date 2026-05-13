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
const int N = 5e5 + 7;
int n, D;
int dp[N], arr[N];
int solve(int i){

	if(i == n)
		return 0;

	if(dp[i] != -1)
		return dp[i];

	int ans = solve(i + 1);
	if(i + 1 < n && abs(arr[i + 1] - arr[i]) <= D){
		ans = max(ans, solve(i + 1) + 1);
	}
	return dp[i] = ans;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

	cin >> n >> D;

	memset(dp, -1, sizeof dp);

	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << solve(0) << endl;
	for(int i = 0; i < n; i++){
		cout << dp[i] << endl;
	}



    
    return 0 ;
}

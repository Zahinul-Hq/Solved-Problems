#include<bits/stdc++.h>
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
const int N = 2009;
ll dp[N][N];
ll arr[N];

int n ;

ll solve(int i , int j){

	if(i > j)
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	ll ans = 0;
	ll day = (i + (n - j));
	//for(int k = i; k < j; kk++){

		ll temp = (day * arr[i]) + solve(i + 1, j);
		ll temp2 = (day * arr[j]) + solve(i, j - 1);
	ans = max(temp2, temp);
	

	return dp[i][j] = ans;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    cin >> n;

    for(int i = 1; i <= n; i++){
    	cin >> arr[i];
    }

    memset(dp, -1, sizeof dp);

    ll ans = solve( 1, n);

    cout << ans << endl;
    return 0 ;
}

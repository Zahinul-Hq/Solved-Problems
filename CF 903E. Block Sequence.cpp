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
const int N = 2e5 +7;
vector<int>arr(N, 0);
int n, x;
int dp[N];
ll solve(int i){
	if(i == n )
		return 0;
	if(dp[i] != -1)
		return dp[i];

	ll ans = inf;

	if(i + arr[i] + 1 <= n)
		ans = solve(i + arr[i] + 1);
	ans = min(ans, solve(i + 1) + 1);

	return dp[i] = ans;

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
        arr.clear();

        cin >> n;
        for(int i = 0; i < n; i++){
        	cin >> arr[i] ;
        }
        for(int i = 0; i <= n + 5; i++){
        	dp[i] = INT_MAX;
        }

        //cout << solve(0) << endl;

        dp[0] = 0;

        for(int i = 0; i < n; i++){

        	dp[i + 1] =  min(dp[i + 1], dp[i] + 1);
        	if(i + arr[i] + 1 <= n)
        		dp[i + arr[i] + 1] = min(dp[i + arr[i] + 1], dp[i]);
        }

        cout << dp[n] << endl;
    }
    return 0 ;
}

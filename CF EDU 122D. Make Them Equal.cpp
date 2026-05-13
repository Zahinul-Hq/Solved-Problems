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
const int N = 1e3 + 7;
vector<int>pwr(N, 0), coin(N, 0);
ll dp[N], dpp[N][12 * N];
int n ,k;

ll solve(int i, int left){
	if(i == n)
		return 0;

	if(dpp[i][left] != -1)
		return dpp[i][left];

	ll ans = solve(i + 1, left);
	if(left - pwr[i] >= 0)
		ans = max(ans, solve(i + 1, left - pwr[i]) + coin[i]);

	return dpp[i][left] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases ;
    cin >> test_cases ;

    for(int i = 0; i < N; i++){
    	dp[i] = N;
    }
    dp[1] = 0;

    for(int i = 1; i < N; i++){
    	for(int j = 1; j <= i; j++){
    		int val = i + (i / j);
    		if(val < N)
    			dp[val] = min(dp[val], dp[i] + 1);
    	}
    }
     
    
    while (test_cases--)
    {
        int x;
        cin >> n >> k;

        

        int sum = 0;
        for(int i = 0; i < n; i++){
        	cin >> x;
        	pwr[i] = dp[x];
        	sum += dp[x];
        }

        for(int i = 0; i <= n; i++){
        	for(int j = 0; j <= min(k, sum ); j++){
        		dpp[i][j] = -1;
        	}
        }
        for(int i = 0; i < n; i++){
        	cin >> coin[i];
        }
        cout << solve(0, min(k, sum)) << endl;
    }
    return 0 ;
}

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
const int N = 16, M = (1 << 16) + 7;
int grid[N][N];
ll dp[N][M];
int n;
ll solve(int i, int mask){
	if(i == n){
		return 0;
	}
	if(dp[i][mask] != -1)
		return dp[i][mask];
	ll ans = 0;
	for(int j = n - 1; j >= 0; j--){
		if((mask & (1 << j)) == 0){
			ans = max(ans, solve(i + 1, (mask | (1 << j))) + grid[i][j]);
		}
	}

	return dp[i][mask] = ans;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases , cs = 1;
    cin >> test_cases ;
    
    while (test_cases--)
    {

        cin >> n;
        for(int i = 0; i < n; i++){
        	for(int j = 0; j < n; j++){
        		cin >> grid[i][j];
        	}
        }
        memset(dp, -1, sizeof dp);


        cout <<"Case " << cs++ << ": " << solve(0, 0) << endl;

    }
    return 0 ;
}

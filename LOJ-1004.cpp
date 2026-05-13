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
const int N = 205;
ll dp[N][N];
int grid[N][N];
int n;
ll solve(int i, int j){

	if(i > 2 * n)
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	ll ans  = 0;

	if(grid[i + 1][j] != -1)
		ans = max(ans, solve(i + 1, j) + grid[i][j]);
	if(grid[i + 1][j + 1] != -1)
		ans = max(ans, solve(i + 1, j + 1) + grid[i][j]);


	return dp[i][j] = ans;
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

        cin >> n;

        memset(dp, -1, sizeof dp);
        memset(grid, -1, sizeof grid);

        for(int i = 1; i <= n; i++){
        	for(int j = 1; j <= i; j++){
        		cin >> grid[i][j];
        	}
        }
        int pos = 2;
        for(int i = n + 1; i <= 2*n - 1; i++){
        	for(int j = pos ; j <= n  ; j++){
        		cin >> grid[i][j];
        	}
        	pos++;
        }
        

        cout << solve(1,1) + grid[2 *n  - 1][n] << endl;
    }
    return 0 ;
}

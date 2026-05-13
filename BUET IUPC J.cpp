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

const int N = 1e3 + 7; 
int n, m;

int dis(int x,int y, int xx, int yy){
	int distance = abs(xx - x) + abs(yy - y);
	return distance;
}

ll grid[N][N], dp[N][N];

ll rec(int i, int j){
	if(i > n || j > m){
		return 0;
	}

	if(dp[i][j] != -1)
		return dp[i][j];

	ll  ans = low;

	ans = max(ans, rec(i + 1, j));
	ans = max(ans, rec(i, j + 1));

	if(i  <= n)
		ans = max(ans, rec(i + 1, j) + grid[i][j] - 1);
	if(j  <= m)
		ans = max(ans, rec(i, j + 1) + grid[i][j] - 1);

	dp[i][j] = ans;
	return ans ;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	
    	cin >> n >> m;

    	

    	for(int i = 1; i <= n; i++){
    		for(int j = 1; j <= m; j++){
    			cin >> grid[i][j];
    		}
    	}
    	memset(dp, -1, sizeof dp);
    	

    	cout << rec(1, 1) + 1 << endl;
    	debug(dp);


    }
    return 0 ;
}

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
//typedef __int128 lll;
#define pb push_back
#define inf   INT_MAX
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
int dis[N][N], vis[N][N];
string grid[N];
int n, m;
bool check(int i , int j){
	if(i < 0 || i >= n || j < 0 || j >= m)
		return false;

	return true;
}
string dir = "URLD";
vector<pair<int,int>>movement = {{1, 0} ,{ 0, 1}, {0, -1}, {-1, 0}};

int dfs(int i, int j){

	for(int l = 0; l < 4; l++){
		if(vis[i][j])
			return dis[i][j];

		if(dir[l] == grid[i][j] || grid[i][j] == '?'){
			pair<int,int> p = movement[l];
			if(!check(i + p.F, j + p.S))
				return inf;
			dis[i][j] = min(dis[i][j], dfs(i + movement[l].first , j + movement[l].second));
		}
	}

	return dis[i][j];
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


    	for(int i = 0; i <= n; i++){
    		for(int j = 0; j <= m; j++){
    			vis[i][j] = 0;
    			dis[i][j] = inf;
    		}
    	}

    	for(int i = 0; i < n; i++){
    		cin >> grid[i];
    	}

    	for(int i = 0; i < n; i++){
    		for(int j = 0; j < m ; j++){
    			if(!vis[i][j]){
    				if(grid[i][j] == '?'){
    					if(i == 0 || i == n - 1 || j == 0 || j == m - 1){
    						dis[i][j] = dfs(i, j);
    					}
    				}else{
    					dis[i][j] = dfs(i, j);
    				}
    				
    			}
    		}
    	}

    	int ans = 0;
    	//debug(grid);
    	for(int i = 0; i < n; i++){
    		for(int j = 0; j < m; j++){
    			if(dis[i][j] == 1){
    				ans++;
    			}
    		}

    	}

    	cout << ans << endl;


    }
    return 0 ;
}

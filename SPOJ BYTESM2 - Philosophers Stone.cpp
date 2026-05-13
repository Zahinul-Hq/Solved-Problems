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
const int N = 102;
int grid[N][N];

int H, W;

int solve(int i, int j){

	if(i > H || j == 0 || j > W )
		return 0;

	int ans = solve(i + 1, j) + grid[i][j];

	ans = max(ans, solve(i + 1, j + 1) + grid[i][j]);

	ans = max(ans, solve(i + 1, j - 1) + grid[i][j]);

	return ans;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;



    int t ;
    cin >> t ;
    
    while (t--)
    {
        cin >> H >> W;

        for(int i = 1; i <= H; i++){
        	for(int j = 1; j <= W; j++){
        		cin >> grid[i][j];
        	}
        }
        for(int i = 2; i <= H; i++){
        	for(int j = 1; j <= W; j++){

        		int mx = 0;

        		if(j == 1)
        			mx = max(grid[i - 1][j], grid[i -  1][j + 1]);
        		else if(j == W)
        			mx = max(grid[i - 1][j], grid[i -  1][j - 1]);
        		else
        			mx = max({grid[i - 1][j - 1],grid[i - 1][j], grid[i -  1][j + 1]});

        		grid[i][j] += mx;
        		
        	}
        }

        int ans = 0;

        for(int i = 1; i <= W; i++){
        	ans = max(ans , grid[H][i]);
        }

        cout << ans << endl;
    }
    return 0 ;
}

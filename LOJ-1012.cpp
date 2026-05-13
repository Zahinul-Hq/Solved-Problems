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
const int N = 25;
char grid[N][N];
bool vis[N][N];
int w , h;
void solve(int i, int j){
	if(j > w && i > h){
		return;
	}
	vis[i][j] = 1;

	if(i + 1 <= h && grid[i + 1][j] == '.'  && !vis[i + 1][j]){
		solve(i + 1, j);
	}
	if(i - 1 > 0 && grid[i - 1][j] == '.' && !vis[i - 1][j]){
		solve(i - 1, j);
	}
	if(j + 1 <= w && grid[i][j + 1] == '.' && !vis[i][j + 1]){
		solve(i, j + 1);
	}
	if(j - 1 <= w && grid[i][j - 1] == '.' && !vis[i][j - 1]){
		solve(i, j - 1);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases, cs =1 ;
    cin >> test_cases ;
    
    while (test_cases--)
    {

    	memset(vis, 0, sizeof vis);
        cin >> w >> h;

        int x, y ;

        for(int i = 1; i <= h; i++){
        	for(int j = 1; j <= w; j++){
        		cin >> grid[i][j];
        		if(grid[i][j] == '@'){
        			x = i, y = j;
        		}
        	}
        }
        int ans = 0;
        solve(x, y);
        for(int i = 1; i <= h; i++){
        	for(int j = 1; j <= w; j++){
        		ans += vis[i][j];
        	}
        }

        cout << "Case " << cs++ << ": " << ans << endl;
    }
    return 0 ;
}

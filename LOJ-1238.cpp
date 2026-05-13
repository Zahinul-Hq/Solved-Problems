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

string grid[22];
int n , m;
queue<pair<int,int>>Q;
vector<pair<int,int>> movement{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool vis[22][22];
int dis[22][22];
bool valid(int x, int y){
	if(!vis[x][y] && grid[x][y] != 'm' && grid[x][y] != '#')
		return true;
	return false;
}
void bfs(pair<int,int> src){
	Q.push(src);
	vis[src.F][src.S] = true;
	while(!Q.empty()){
		pair<int,int> v = Q.front();
		Q.pop();
		for(auto i : movement){
			int x = v.F + i.F;
			int y = v.S + i.S;
			if(valid(x, y)){
				Q.push({x, y});
				vis[x][y] = true;
				dis[x][y] = dis[v.F][v.S] + 1;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases, cs = 1;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	cin >> n >> m;
    	for(int i = 0; i < n; i++){
    		cin >> grid[i];
    	}
    	pair<int,int> c, a, b, h;
    	for(int i = 0; i < n; i++){
    		for(int j = 0; j < m; j++){
    			if(grid[i][j] == 'c')
    				c = {i, j};
    			if(grid[i][j] == 'a')
    				a = {i, j};
    			if(grid[i][j] == 'b')
    				b = {i, j};
    			if(grid[i][j] == 'h')
    				h = {i, j};
    		}
    	}
    	memset(vis,0, sizeof vis);
    	memset(dis,0, sizeof dis);
    	bfs(a);
    	int da = dis[h.F][h.S];
    	memset(vis, 0, sizeof vis);
    	memset(dis, 0, sizeof dis);
    	bfs(b);
    	int db = dis[h.F][h.S];
    	memset(vis, 0, sizeof vis);
    	memset(dis, 0, sizeof dis);
    	bfs(c);
    	int dc = dis[h.F][h.S];

    	cout << "Case " << cs++ << ": " << max({da, db, dc}) << endl;





        
    }
    return 0 ;
}

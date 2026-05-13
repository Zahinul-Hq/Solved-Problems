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
const int N = 55;
string grid[N];
int H, W;
int vis[N][N];

int dx[] = {1 , 1, 1, -1, -1, -1, 0, 0};
int dy[] = {1 , 0, -1, 1, 0, -1, 1, -1};

bool valid(int cx, int cy, int px, int py){

	if(cx >= 0 && cx < H && cy >= 0 && cy < W ){
		if(grid[px][py] + 1 == grid[cx][cy] && !vis[cx][cy])
			return true;
	}

	return false;
}

int bfs(pair<int, int> src){

	memset(vis, 0, sizeof vis);

	queue<pair<int, int>>Q;
	Q.push(src);

	char c = 'A';
	int dis = 1;

	int x = src.first; 
	int y = src.second;

	vis[x][y] = 1;

	while(!Q.empty()){

		pair<int,int> p = Q.front();
		x = p.first; 
		y = p.second;
		Q.pop();

		for(int i = 0; i < 8; i++){

			int xx = x + dx[i];
			int yy = y + dy[i];

			if(valid(xx, yy, x, y)){
				Q.push({xx, yy});

				vis[xx][yy] = vis[x][y] + 1;
				dis = max(dis, vis[xx][yy]);
			}
		}
	}

	return dis;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int cs = 1;
    while (1)
    {
        cin >> H >> W;

        if(H == 0 && W == 0)
        	break;

        for(int i = 0; i < H; i++){
        	cin >> grid[i];
        }
        vector<pair<int,int>> soruces;

        for(int i = 0; i < H; i++){
        	for(int j = 0; j < W; j++){
        		if(grid[i][j] == 'A'){
        			soruces.push_back({i, j});
        		}
        	}
        }
        int ans = 0;

        for(int i = 0; i < soruces.size(); i++){
        	ans = max(ans, bfs(soruces[i]));

        }

        cout << "Case "<< cs++ << ": "<< ans << endl;
    }
    return 0 ;
}

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

const int N = 190, INF = 10000;
int n, m;
int dis[N][N];

vector<pair<int,int>>movements = 
{
	{1, 0}, {-1, 0},
	{0, 1}, {0, -1}
};
bool valid_move(int i, int j){

	if(i > 0 && i <= n && j > 0 && j <= m)
		return true;

	return false;
}

void bfs(pair<int,int> src){

	queue<pair<int,int>>Q;
	Q.push(src);
	dis[src.first][src.second] = 0;

	while(!Q.empty()){

		pair<int,int> v = Q.front();
		Q.pop();

		for(auto [i, j] : movements){

			int x = v.first + i;
			int y = v.second + j;

			if(valid_move(x,y) && (dis[x][y] > dis[v.first][v.second] + 1)){

				Q.push({x,y});
				dis[x][y] = dis[v.first][v.second] + 1;
			}
		}
	}
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

        cin >> n >> m;

        vector<pair<int,int>> sources;

        for(int i = 1; i <= n; i++){
        	for(int j = 1; j <= m; j++){

        		char ch ; cin >> ch;

        		dis[i][j] = INF;

        		if(ch == '1'){
        			sources.push_back({i,j});
        		}
        	}
        }

        for(int i = 0; i < sources.size(); i++){
        	bfs(sources[i]);
        }

        for(int i = 1; i <= n; i++){
        	for(int j = 1; j <= m; j++){

        		cout << dis[i][j] <<" ";
        	}

        	cout << endl;
        }


    }
    return 0 ;
}

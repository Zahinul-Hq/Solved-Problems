#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second 

void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}
const int N = 1e6;
vector<int>adj[N];
vector<ll>dis(N,0);


vector<bool> visited(N, false);

void dfs(int v) {

    visited[v] = true;

    for (int u : adj[v]) {
        if (!visited[u]){
            dis[u] = dis[v] + 1;
            dfs(u);
        }
    } 
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

	int n ;

	cin >> n;

	for(int i = 1; i <= n - 1; i++){

		int x , y;

		cin >> x >> y;

		adj[x].push_back(y);
		adj[y].push_back(x);

	}

	ll ans = 0;

	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			dfs(i);
		}
	}
	int st = -1, mx_dis = -1;
	for(int i = 1; i <= n; i++){



		if(mx_dis < dis[i]){
			st = i;
			mx_dis = dis[i];
		}
	}

	visited.assign(N, false);
	dis.assign(N,0);



	dfs(st);

	for(int i = 1; i <= n; i++){
		ans = max(ans, dis[i]);
	}

	cout << ans << endl;

	
    return 0 ;
}

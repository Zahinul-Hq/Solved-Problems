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
vector<int>graph[10005];
vector<bool>vis(10005,false);
vector<int>par(10005, -1);

bool ans = true;
void dfs(int v){

	vis[v] = true;

	for(auto u : graph[v]){
		if(!vis[u]){

			par[u] = v;
			dfs(u);
		}
		if(par[u] != v)
			ans = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int n, m;

    cin >> n >> m;

    while(m--){

    	int u, v;

    	cin >> u >> v;

    	if(u != v)
    		graph[u].push_back(v);
    	//graph[v].push_back(u);
    }

    dfs(1);

    for(int i = 1; i <= n; i++){
    	if(!vis[i]){
    		
    		cout << "NO" << endl;
    		return 0;
    	}

    }

    

    if(ans && n != m -1)
    	cout << "YES" << endl;
    else
    	cout << "NO" << endl;


    return 0 ;
}

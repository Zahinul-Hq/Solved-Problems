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
const int N =2005;

vector<int>graph[N];
vector<int>col(N,0),vis(N,0);

bool homo = false;

void dfs(int v){

	vis[v] = 1;

	for(auto u : graph[v]){

		if(!vis[u]){

			col[u] = col[v] ^ 1;
			dfs(u);

		}else if(col[u] == col[v]){
			homo = true;
		}
	}


	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

	int t, c = 1;

	cin >> t;

	while(t--){

		int n , m;

		cin >> n >> m;

		while(m--){
			int u, v;

			cin >> u >> v;

			graph[u].push_back(v);
			graph[v].push_back(u);
			
		}


		for(int i = 1; i <= n; i++){
			if(!vis[i]){
				dfs(i);
			}
		}

		
		cout << "Scenario #" << c++ << ":" << endl;

		if(homo){

			cout << "Suspicious bugs found!" << endl;

		}else{

			cout << "No suspicious bugs found!" << endl;
		}

		col.assign(N,0);
		vis.assign(N,0);

		for(int i = 1; i <=n ; i++){
			graph[i].clear();
		}
		homo = false;
	}
    return 0 ;
}

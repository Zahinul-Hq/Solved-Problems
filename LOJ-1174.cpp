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
const int N = 101;
vector<int> adj[N]; 
vector<int>leaf_nodes; // adjacency list representation
int n, ss, dd; // number of nodes
void bfs(int s, vector<int>&d){
	queue<int> q;
	vector<bool> used(n);
	

	q.push(s);
	used[s] = true;

	while (!q.empty()) {
	    int v = q.front();
	    q.pop();
	    for (int u : adj[v]) {
	        if (!used[u]) {
	            used[u] = true;
	            q.push(u);
	            d[u] = d[v] + 1;
	          
	        }
	    }
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases, cs = 1 ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	int  m, u, v;
    	cin >> n >> m;
    	leaf_nodes.clear();
    	vector<int> ds(n), des(n) ;



    	for(int i = 0; i < m; i++){
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin >> ss >> dd;

    	bfs(ss, ds);
    	bfs(dd, des);

    	int ans = 0;
    	for(int i = 0 ; i < n; i++){
    		ans = max(ans, ds[i] + des[i]);
    	}

    	cout << "Case " << cs++ << ": " << ans << endl;
    	for(int i = 0; i < n; i++){
    		adj[i].clear();
    	}
    }
    return 0 ;
}

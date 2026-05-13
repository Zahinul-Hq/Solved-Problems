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
 
#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
const auto start_time = std::chrono::high_resolution_clock::now();
void runtime()
{
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,milli> diff = end_time-start_time;
    cerr<<"Time: "<<roundl(diff.count())<<"ms\n";
}
const int N = 10;
int n;
vector<int> adj[N];
vector<bool> visited;
vector<int> parent;
int cycle_start, cycle_end;
map<pair<int,int>, int>edges;

bool dfs(int v, int par) {
    visited[v] = true;
    for (int u : adj[v]) {
        if(u == par) continue; 
        if (visited[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs(u, parent[u]))
            return true;
    }
    return false;
}

void find_cycle() {
    visited.assign(n, false);
    parent.assign(n, -1);

    bool cyc = 0;

    for (int v = 0; v < n; v++) {
        if (!visited[v]){
        	cycle_start = -1;
        	cyc = dfs(v, parent[v]);

        	vector<int>cycle;
        	
        	if (cycle_start != -1 && cyc) {
        
		        vector<int> cycle;
		        int child = cycle_start;

		        for (int par = cycle_end; par != cycle_start; par = parent[par]){
		            if(child < par){
		            	swap(child, par);
		            }
		            if(edges.count({par, child})){
		            	edges.erase({par, child});
		            }

		            debug(par, child, v);
		        }

		        if(cycle_start > cycle_end){
		           	swap(cycle_start, cycle_end);
		        }
		        if(edges.count({cycle_start, cycle_end})){
		           	edges.erase({cycle_start, cycle_end});
		        }
    		}
        }       
    }
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
    	cin.ignore();
    	cin >> n;

    	for(int i = 0; i <= n; i++){
    		adj[i].clear();
    	}

    	for(int i = 0; i < n; i++){
    		int m, u, v; char c, d;
    		cin >> u >> c >> m >> d;

    		for(int j = 0; j < m; j++){
    			cin >> v;
    			adj[u].push_back(v);
    			if(u < v){
    				edges[{u,v}] = 1;
    			}
    		}
    	}
    	debug(adj, edges);
    	find_cycle();

    	cout << edges.size() << endl;

    	for(auto i : edges){
    		cout << i.first.first << " " << i.first.second << endl;
    	}

    }
    return 0 ;

    runtime();

}

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
const int N = 2e5 + 7;
vector<int>graph[N], sz(N, 0);
void dfs(int v, int p){
	sz[v] = 1;
	for(auto u : graph[v]){
		if(u != p){
			dfs(u, v);
			sz[v] += sz[u];
		}
	}
}
int n;
int dfs2(int v, int p){
	int mx = 0, node = 0;
	for(auto u : graph[v]){
		if(u != p){
			if(sz[u] > mx){
				mx = sz[u];
				node = u;
			}
		}
	}
	if(mx <= (n / 2))
		return v;
	return dfs2(node, v);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

    int u, v;
    cin >> n;

    for(int i = 1; i < n; i++){
    	cin >> u >> v;
    	graph[u].push_back(v);
    	graph[v].push_back(u);
    }
    dfs(1, 0);

    cout << dfs2(1, 0) << endl;







    runtime();
    return 0 ;

    

}

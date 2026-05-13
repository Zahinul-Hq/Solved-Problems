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
const int N = 30007;
vector<pair<int,int>>graph[N];
vector<int>dis(N , 0),vis(N ,0), par(N, -1);
void dfs(int u){
	vis[u] = 1;

	for(auto ch : graph[u]){
		if(!vis[ch.first]){
			dis[ch.first] = dis[u] + ch.second;
			par[ch.first] = u;
			dfs(ch.first);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int test_cases, cs = 1;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        int n;
        cin >> n;
        vector<int>w(n, 0);
       
        for(int i = 1; i < n; i++){
        	int u, v; cin >> u >> v >> w[i];
        	graph[u].push_back({v,w[i]});
        	graph[v].push_back({u,w[i]});
        }
        dfs(0);
        int mx = 0, root = 0, des = 0;
        for(int i = 0; i < n; i++){
        	if(mx < dis[i]){
        		mx = dis[i];
        		root = i;
        	}
        	vis[i] = dis[i] = 0;
        }
        int tot = mx;
        mx = 0;
        dfs(root);
        int root_dis[n + 1], des_dis[n + 1];
        for(int i = 0; i < n; i++){
        	if(mx < dis[i]){
        		mx = dis[i];
        		des = i;
        	}
        	root_dis[i] = dis[i];
        	vis[i] = dis[i] = 0;
        }
        dfs(des);
        for(int i = 0; i < n; i++){
        	des_dis[i] = max(root_dis[i], dis[i]);
        }


        cout << "Case " << cs++ << ": " << endl ;
       	for(int i = 0; i < n; i++){
       		cout << des_dis[i] << endl;
       	}
        for(int i = 0; i < n; i++){
        	graph[i].clear();
        	vis[i] = 0;
        	dis[i] = 0;
        }
        
    }
    return 0 ;
}


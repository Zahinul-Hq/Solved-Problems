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
const int N = 5e5 + 7;
vector<ll>mx_lvl(N, 0), cnt(N, 0), lvl_cnt(N, 0), graph[N];
void dfs(int u, int p, int lvl){
	mx_lvl[u] = lvl;

	for(auto v : graph[u]){
		if(v != p){
			dfs(v, u, lvl + 1);
			mx_lvl[u] = max(mx_lvl[u], mx_lvl[v]); 
		}
	}

	lvl_cnt[lvl]++;
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
    	int n;
    	cin >> n;

    	for(int i = 1; i < n; i++){
    		int u, v; cin >> u >> v;

    		graph[u].push_back(v);
    		graph[v].push_back(u);
    	}

    	dfs(1, 1, 0);

    	for(int i = 1; i <= n; i++){
    		cnt[mx_lvl[i]]++;
    	}

    	vector<ll>prf(n + 1, 0);

    	for(int i = 1; i <= n; i++){
    		prf[i] = prf[i - 1] + cnt[i];
    		
    	}
    	for(int i = n; i >= 1; i--){
    		lvl_cnt[i] += lvl_cnt[i + 1];
    	}

    	ll ans = inf;

    	for(int i = 1; i <= n; i++){
    		ans = min(ans, prf[i - 1] + lvl_cnt[i + 1]);
    	}

    	cout << ans << endl;
    	for(int i = 0; i <= n; i++){
    		graph[i].clear();
    		cnt[i] = 0;
    		mx_lvl[i] = 0;
    		lvl_cnt[i] = 0;
    	}

    }
    return 0 ;

    runtime();

}

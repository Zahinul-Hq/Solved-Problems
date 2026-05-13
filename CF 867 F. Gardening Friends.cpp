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
vector<int>graph[N], dis(N, 0);
void dfs(int v, int p){

	for(auto u : graph[v]){
		if(u != p){
			dis[u] = dis[v] + 1;
			dfs(u, v);
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
    	ll n, k, c, u , v;
    	cin >> n >> k >> c;

    	for(int i = 0; i <= n; i++){
    		graph[i].clear();
    		dis[i] = 0;
    	}


    	for(int i = 1; i < n; i++){
    		cin >> u >> v;
    		graph[u].push_back(v);
    		graph[v].push_back(u);
    	}

    	dfs(1, -1);
    	int newroot = 1, d = 0;
    	vector<int> newdis(n + 1);
    	for(int i = 1; i <= n; i++){
    		if(d < dis[i]){
    			newroot = i;
    			d = dis[i];
    		}
    		newdis[i] = dis[i];
    	}

    	if(k <= c){
    		cout << (ll) k * d << endl;
    		continue;
    	}
    	for(int i = 1; i <= n; i++){
    		dis[i] = 0;
    	}
    	//debug(newroot);
    	dfs(newroot, -1);
    	
    	ll profit = 0;
    	for(int i = 1; i <= n; i++){

    		profit = max(profit, (k * dis[i]) - ((newdis[i]) * c));
    	}
    	debug( dis, newdis );

    	cout <<  profit << endl; 



    	




    }
    return 0 ;

    runtime();

}

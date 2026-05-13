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
const int N = 1000;
vector<pair<int,int>>graph[N];

int n, m, q, x, l, r, c;
int  visnode[N];
int bfs(int s){

	vector<int> d(n + 1, INT_MAX);
	d[s] = 0;
	deque<int> q;
	q.push_front(s);
	while (!q.empty()) {
	    int v = q.front();
	    q.pop_front();
	    for (auto edge : graph[v]) {
	        int u = edge.first;
	        int w = edge.second;
	        if (d[v] + w < d[u]) {
	            d[u] = d[v] + w;
	            if (w == 1)
	                q.push_back(u);
	            else
	                q.push_front(u);
	        }
	    }
	}

	if(d[n] != INT_MAX){
		return d[n];
	}else{
		return -1;
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

    cin >> n >> m >> q;

    for(int i = 0; i < m; i++){
    	cin >> x >> l >> r;
    	for(int j = l; j <= r; j++){
    		graph[x].push_back({j, 0});
    	}
    	
    	visnode[x] = 1;
    }
    for(int i = 1; i <= n; i++){
	    	for(int j = 1; j <= 6 && i + j <= n; j++){
	    		if(visnode[i] == 0)
	    			graph[i].push_back({i + j, 1});
	    }
    }

    while(q--){
    	cin >> c;
    	
    	cout << bfs(c) << endl;

    }

    

    return 0 ;

    runtime();

}

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
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 7;
vector<int> adj[MAXN];
int color[MAXN];

bool dfs(int node, int c, ll &cnt0, ll &cnt1) {
    color[node] = c;

    if (c == 0) cnt0++;
    else cnt1++;

    bool b = true;

    for (int neighbor : adj[node]) {
        if (color[neighbor] == -1) {
            if (!dfs(neighbor, 1 - c, cnt0, cnt1)) b = false;
                
        } else if (color[neighbor] == c) {
           	b = false;
        }
    }
    return b;
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
    	int n, m;
	    cin >> n >> m;

	    for (int i = 1; i <= n; i++) {
	        color[i] = -1;
	       	adj[i].clear();
	    }

	    for (int i = 0; i < m; i++) {
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	        adj[v].push_back(u);
	    }

	    ll totalMax = 0;

	    for (int i = 1; i <= n; i++) {
	        if (color[i] == -1) {
	            ll cnt0 = 0, cnt1 = 0;

	            if (dfs(i, 0, cnt0, cnt1)) {
	            	totalMax += max(cnt0, cnt1); 
	            }  
	        }
	    }

	    cout << totalMax << endl;
	}
    return 0 ;

    runtime();

}

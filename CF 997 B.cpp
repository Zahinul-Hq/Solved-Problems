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
const int N = 1005;
set<int> graph[N];
int vis[N];
vector<int> ans;
void dfs(int v) {
   vis[v] = 1;
   for(auto u : graph[v]) {
     if(!vis[u])
     	dfs(u);
   }
   ans.push_back(v);
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

    	ans.clear();

    	string s[n + 1];

    	for(int i = 1; i <= n; i++){
    		cin >> s[i];
    		graph[i].clear();
    		vis[i] = 0;
    		s[i] = '#' + s[i];
    	}
    	for(int i = 1; i <= n; i++){
    		for(int j = 1; j <= n; j++){
    			if(s[i][j] == '1'){
    				graph[min(i,j)].insert(max(i, j));
    			}
    		}
    	}

    	for(int i  = 1; i <= n; i++){
    		if(!vis[i])
    			dfs(i);
    	}

    	reverse(ans.begin(), ans.end());

    	for(int i = 0; i < n; i++){
    		cout << ans[i] << " ";
    	}

    	cout << endl;

    }
    return 0 ;

    runtime();

}

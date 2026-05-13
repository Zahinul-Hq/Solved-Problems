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
const int N = 3e5 + 7;
vector<int>graph[N], dp(N, 0), child(N, 0);
void dfs(int u, int p){

	child[u] = 1, dp[u] = 0;
	int saved = 0;

	for(auto ch : graph[u]){
		if(ch != p){
			dfs(ch, u);
			child[u] += child[ch];
			saved += dp[ch];
		}
	}

	for(auto ch : graph[u]){
		if(ch != p){
			dp[u] = max(dp[u], saved - dp[ch] + child[ch] - 1);
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	

        int n, u, v;
        cin >> n;
        
        for(int i = 1; i < n; i++){
        	cin >> u >> v;
        	graph[u].push_back(v);
        	graph[v].push_back(u);
        }

        dfs(1, 0);

        cout << dp[1] << endl;

        for(int i = 0; i <= n; i++){
        	graph[i].clear();
        	child[i] = dp[i] = 0;
        }

    }
    return 0 ;
}

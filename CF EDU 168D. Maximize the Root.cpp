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
const int N = 2e5 + 7;
vector<ll>graph[N], vis(N, 0), arr(N, 0), dp(N, INT_MAX);
int n, x;
void dfs(int node, int par){

	for(auto ch : graph[node]){
		if(ch != par){
			dfs(ch, node);
		}
	}

	ll mn = INT_MAX;
	for(auto ch : graph[node]){
		if(ch != par){
			mn = min(arr[ch], mn);
		}
	}
	if(arr[node] < mn && mn != INT_MAX){
		arr[node] = (arr[node] + mn) / 2;
	}else if(mn != INT_MAX){
		arr[node] = mn;
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
        cin >> n;
        for(int i = 1; i <= n; i++){
        	cin >> arr[i];
        }
        for(int i = 2; i <= n; i++){
        	cin >> x;
        	graph[i].push_back(x);
        	graph[x].push_back(i);
        }

        ll ans = arr[1], mn = INT_MAX;

        dfs(1, 0);

        for(auto ch : graph[1]){
        	mn = min(arr[ch], mn);
        }
        cout << ans + mn << endl;

        for(int i = 0; i <= n; i++){
        	vis[i] = 0;
        	graph[i].clear();
        	dp[i] = INT_MAX;
        }

    }
    return 0 ;
}

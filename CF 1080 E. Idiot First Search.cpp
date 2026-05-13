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
const int mod = 1e9 + 7, N = 3e5 + 7;
vector<int>graph[N];
vector<ll>dp(N, 0);
void dfs(int i, bool f){

	for(auto ch : graph[i]){

			if(f)
				dp[ch] = (dp[ch] + (dp[i] + 1)) % mod;
			dfs(ch, f);
			if(!f)
				dp[i] = (dp[i] + (dp[ch] + 2)) % mod;
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
    	int n, l , r;

    	cin >> n;

    	for(int i = 1; i <= n; i++){
    		graph[i].clear();
    		dp[i] = 0;
    	}

    	for(int i = 1; i <= n; i++){
    		cin >> l >> r;

    		if(r == 0)
    			continue;

    		graph[i].push_back(l);
    		graph[i].push_back(r);
    	}

    	 dfs(1, 0);
    	 dfs(1, 1);

    	 for(int i = 1; i <= n; i++){
    	 	cout << (dp[i] + 1) % mod << " ";
    	 }
    	 cout << endl;
    }
    return 0 ;

    runtime();

}

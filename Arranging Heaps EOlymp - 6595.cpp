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
ll dp[N][N];
vector<ll>W(N, 0), X(N, 0);
int n, k;

ll rec(int i, int heap){
	if(i == n){
		if(heap == k)
			return 0;
		return inf;
	}

	if(dp[i][heap] != -1)
		return dp[i][heap];

	ll ans = inf;

	ans = min(ans, rec(i + 1, heap));
	ans = min(ans, rec(i + 1, heap - 1) + W[i - 1] * (X[i] - X[i - 1]));

	return dp[i][heap] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
    
    while (cin >> n >> k)
    {

    	for(int i = 0; i < n; i++){
    		cin >> X[i] >> W[i];
    	}
    	memset(dp, -1, sizeof dp);


    	cout << rec(1, n) << endl;
    }
    return 0 ;

    runtime();

}

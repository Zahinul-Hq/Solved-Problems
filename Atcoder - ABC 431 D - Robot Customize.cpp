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
const int N = 501;
int n, total_wt;

vector<int>a(N), b(N), w(N);
ll dp[N][N*N];

ll rec(int i, int w_body){
	if(i == n){
		return 0;
	}

	if(dp[i][w_body] != -1)
		return dp[i][w_body];

	ll ans = 0;
	ans = max(ans, rec(i + 1, w_body) + b[i]);

	if(w_body + w[i] <= (total_wt / 2)){
		ans = max(ans, rec(i + 1, w_body + w[i]) + a[i]);
	}
	

	return dp[i][w_body] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	
    cin >> n;

    for(int i = 0; i < n; i++){
    	cin >> w[i] >> a[i] >> b[i];
    	total_wt += w[i];
    }

    memset(dp, -1, sizeof dp);

    cout << rec(0,  0) << endl;



    return 0 ;

    runtime();

}

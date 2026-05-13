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
ll dp[90][2];
int n;
ll rec(int level, bool is_branched){
	if(level == n - 1)
		return 1;

	if(dp[level][is_branched] != -1)
		return dp[level][is_branched];

	ll ans = 0;
	ans += rec(level + 1, true);
	if(is_branched)
		ans += rec(level + 1, false);

	return dp[level][is_branched] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

    while (cin >> n && n > 0)
    {
    	memset(dp, -1, sizeof dp);

    	if(n == 1){
    		cout << 1 << endl;
    		continue;
    	}
    	cout << rec(1, 1) << endl;
    }
    
    return 0 ;

    runtime();

}

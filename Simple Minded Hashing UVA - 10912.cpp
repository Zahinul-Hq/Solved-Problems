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
ll dp[27][27][400];
ll l, s;
ll rec(int len, int last_char, int sum){
	if(len == l){
		if(sum == s)
			return 1;
		return 0;
	}
	if(dp[len][last_char][sum] != -1)
		return dp[len][last_char][sum];
	ll ans = 0;
	for(int ch = last_char + 1; ch < 27; ch++){
		ans += rec(len + 1, ch, sum + ch);
	}
	return dp[len][last_char][sum] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int cs = 0;
    while (1)
    {
    	cin >> l >> s;
    	if(l == 0 && s == 0)
    		break;

    	memset(dp, 0, sizeof dp);
    	dp[0][0][0] = 1;
    	if(l > 26 || s > 351){
    		cout << "Case " << ++cs << ": " << 0 << endl;
    		continue;
    	}

    	cout << "Case " << ++cs << ": " << rec(0, 0, 0) << endl;
    }
    return 0 ;

    runtime();

}

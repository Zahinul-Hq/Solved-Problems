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
string s;
ll dp[65][65];
ll solve(int i, int j){
	if(i >= j){
		return i == j;
	}

	if(dp[i][j] != -1)
		return dp[i][j];

	ll ans = 0;

	if(s[i] == s[j]){
		ans++;
	}else{
		ans -= solve(i + 1, j - 1);
	}
	ans += solve(i + 1, j) + solve(i , j - 1);
	
	return dp[i][j] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases, cs = 1 ;
    cin >> test_cases ;
    
    while (test_cases--)
    {

    	cin >> s;

    	memset(dp, -1, sizeof dp);

    	int n = s.size() - 1;

    	cout << "Case " << cs++ << ": " << solve(0, n) << endl;
    }
    return 0 ;

    runtime();

}

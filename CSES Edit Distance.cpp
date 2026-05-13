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
string s1, s2;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


	cin >> s1 >> s2;

	s1 = "#" + s1;
	s2 = "#" + s2;

	int n = s1.size(), m = s2.size();

	vector<vector<int>>dp(n, vector<int>(m));

	for(int i = 1; i < n; i++){
		dp[i][0] = i;
	}
	for(int i = 1; i < m; i++){
		dp[0][i] = i;
	}

	dp[0][0] = 0;

	for(int i = 1; i < n; i++){
		for(int j = 1; j < m; j++){
			if(s1[i] == s2[j]){
				dp[i][j] = dp[i - 1][j - 1];
			}else{
				dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});
			}
		}
	}



	cout << dp[n - 1][m - 1] << endl;

    
    return 0 ;

    runtime();

}

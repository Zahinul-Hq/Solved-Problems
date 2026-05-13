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
string s;
int dp[105][105];
ll solve(int i, int j){
	if(i > j)
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	ll ans = inf;

	if(s[i] == s[j]){
		ans = min(ans, solve(i + 1, j - 1));
	}else{
		ans = min({ans, solve(i + 1, j) + 1, solve(i , j - 1) + 1});
	}
	return dp[i][j] = ans;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases, cs = 1 ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        cin >> s;
        memset(dp, -1, sizeof dp);
        int  n = s.size(), i = 0, ans = 0, j = n - 1;

        cout << "Case " << cs++ << ": " << solve(0, n - 1) << endl;
    }
    return 0 ;
}

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
#endif

const int N = 3e5 + 7;
vector<ll>a(N, 0), b(N, 0);
map<pair<int,int>, ll> dp;
int n, m;
ll solve(int i, int j){
	if(j > n)
		return 0;
	if(i > m)
		return inf;

	if(dp.count({i, j}))
		return dp[{i, j}];

	ll ans = solve(i + 1, j);
	int pos = upper_bound(a.begin(), a.begin() + n + 1, a[j - 1] + b[i]) - a.begin();
	//cout << i << " " << pos << endl;
	ans = min(ans, solve(i + 1, pos) + m - i);
	if(pos > j)
		ans = min(ans, solve(i, pos) + m - i);

	return dp[{i, j}] = ans;

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

    	dp.clear();
        cin >> n >> m;


        for(int i = 1; i <= n; i++){
        	cin >> a[i];
        	a[i] =  a[i - 1] + a[i];
        }

        a[n + 1] = a[n];

        for(int i = 1; i <= m; i++){
        	cin >> b[i];
        }

        ll ans = solve(1, 1);

        if(ans == inf)
        	cout << -1 << endl;
        else
        	cout << ans << endl;
    }
    return 0 ;
}

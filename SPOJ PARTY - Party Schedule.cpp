#include<bits/stdc++.h>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
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
int budget, fee[105], fun[105], n;
int dp[105][505];

int solve(int i, int total_fee){

	if(i == 0)
		return 0;

	if(dp[i][total_fee] != -1)
		return dp[i][total_fee];


	int ans = solve(i - 1, total_fee);

	if(total_fee - fee[i] >= 0){
		ans = max(ans, solve(i - 1, total_fee - fee[i]) + fun[i]);
	}


	return dp[i][total_fee] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;



    while (cin >> budget >> n && budget)
    {

        for(int i = 1; i <= n; i++){
        	cin >> fee[i] >> fun[i];
        }

       	int mx_fun = 0;
       	int mn_fee = INT_MAX;

       	for(int i = 0; i <= n; i++){
       		for(int j = 0; j <= budget; j++){
       			if( i == 0 || j == 0){
       			 dp[i][j] = 0;
       			 continue;
       			}

       			if(j - fee[i] >= 0){
       				dp[i][j] = max({dp[i - 1][j - fee[i]] + fun[i], dp[i - 1][j]});
       			}else{
       				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
       			}
       		}
       	}

       	int mn_budget = budget;

       	while(dp[n][budget] == dp[n][mn_budget]){
       		mn_budget--;
       	}


       	cout << mn_budget + 1 << " " << dp[n][budget] << endl;


    }
    return 0 ;
}

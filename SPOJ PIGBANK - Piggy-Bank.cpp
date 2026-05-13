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
const int N = 1e4 + 7, M = 505;
int coin_value[M], weight[N], total_weight;
ll dp[M][N];

ll solve(int i, int weight_left){

	if(i == 0 ){
		if(weight_left <= 0)
			return 0;
		return inf;
	}

	if(dp[i][weight_left] != -1)
		return dp[i][weight_left];

	ll ans  = inf ;
	ans = min( ans, solve(i - 1, weight_left));

	if(weight_left - weight[i] >= 0){
		ans = min(ans, solve(i , weight_left - weight[i]) + coin_value[i]);
	}

	return dp[i][weight_left] = ans;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int t ;
    cin >> t ;
    
    while (t--)
    {
    	memset(dp, -1, sizeof dp);

        int e, f, n ;

        cin >> e >> f >> n ;

        total_weight = f - e;

        for(int i = 1; i <= n; i++){
        	cin >> coin_value[i] >> weight[i] ;
        }

        ll ans = solve(n, total_weight);

        if(ans != inf){
        	cout << "The minimum amount of money in the piggy-bank is " << ans << "." << endl;
        }else{
        	cout << "This is impossible." << endl;
        }
    }
    return 0 ;
}

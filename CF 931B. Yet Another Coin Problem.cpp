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
vector<int>coins = {1, 3, 6, 10, 15};
int dp[35];
int min_coins(int sum){
	if(sum == 0)
		return 0;

	if(dp[sum] != -1)
		return dp[sum];
	int total_coins = 500;

	for(int i = 0; i < 5; i++){
		if(sum - coins[i] >= 0)
			total_coins = min(total_coins, min_coins(sum - coins[i]) + 1);
	}

	return dp[sum] = total_coins;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int t ;
    cin >> t ;
    memset(dp, -1, sizeof dp);
    int total = min_coins(29);
    
    while (t--)
    {
        int n;
        cin >> n;
        int ans  = n / 15;
        if(n % 15 == 0)
        	cout << ans << endl;
        else{
        	
        	
        	int rs = (n % 15);
        	if(n > 15){
        		rs += 15;
        		ans--;
        	}
        	cout << ans +  dp[rs] << endl;

        }
    }
    return 0 ;
}

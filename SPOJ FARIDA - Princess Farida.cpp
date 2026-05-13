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

const int N = 1e4 + 5;

ll dp[N][N],n;
ll arr[N + 1];


ll solve(int indx, int last_taken){

	if(indx >= n + 1)
		return 0;


	if(dp[indx][last_taken] != -1)
		return dp[indx][last_taken];


	ll ans = solve(indx + 1, last_taken);

	if((indx - 1 != last_taken ) || (last_taken == 0) ){
		ans = max(ans, solve(indx + 1, indx) + arr[indx]);
	}



	return dp[indx][last_taken] = ans;



}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int t , x = 1;
    cin >> t ;
    
    while (t--)
    {

        cin >> n;

        //memset(dp, -1, sizeof dp);

        for(int i = 1 ; i <= n; i++){
        	cin >> arr[i];
        }

        ll s = 0;

        vector<ll>DP(n + 1,0);

        for(int i = 1; i <= n; i++){

        	ll mx_val = 0;

        	if(i - 2 >= 1)
        		mx_val = max(mx_val, DP[i - 2]);
        	if(i - 3 >= 1)
        		mx_val = max(mx_val, DP[i - 3]);

        	DP[i] = arr[i] + mx_val;

        	s = max(s, DP[i]);
        }

        cout << "Case " << x++ << ": " << s << endl;
    }
    return 0 ;
}

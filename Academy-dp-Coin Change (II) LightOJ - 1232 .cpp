#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second 

void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}
const int N = 1e4 + 7, mod = 100000007;
int a[105], dp[105][N] ;

int possible_ways(int i, int sum){

	if(sum == 0){
		return 1;
	}

	if( i == 0 || sum < 0)
		return 0 ;

	if(dp[i][sum] != -1)
		return dp[i][sum];

	int ans = possible_ways(i - 1, sum);

	ans += possible_ways(i , sum - a[i]);

	ans %= mod;

	return dp[i][sum] = ans  ;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t , c = 1;
    cin>>t ;
    
    while (t--)
    {
        int n, k ;

        cin >> n >> k;

       	//memset(dp, -1, sizeof dp);

        for(int i = 1; i <= n; i++){
        	cin >> a[i];
        }


        for(int i = n + 1; i >= 1; i--){
        	for(int sum = 0; sum <= k; sum++){
        		int ans = dp[i][sum];

        		if( i == n + 1){
        			ans = (sum == 0);
        		}else{

        			ans = dp[i + 1][sum];

        			if(sum >= a[i])
        				ans += dp[i][sum - a[i]];

        			ans %= mod;

        			


        		}
        		dp[i][sum] = ans;
        	}

        	
        }

        cout <<"Case " << c++ << ": " << dp[1][k]<< endl;
    }
    return 0 ;
}

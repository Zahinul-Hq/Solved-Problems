#include<bits/stdc++.h>
using namespace std ;
 
typedef long long ll ;
#define endl  "\n"
 
 
void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}
const int N = 1e6 + 7;
int mod = 1e9 + 7 , n;
int dp[N], k;
 
int coin_value[105];
 
int coin_combinations(int sum){

	if(sum == 0)
		return 1;

	if(dp[sum] != -1){
		return dp[sum];
	}

	int ans = 0;

	for(int i = 1; i <= n; i++){

		if(sum - coin_value[i] >= 0){
			ans += coin_combinations(sum - coin_value[i]) ;
			ans %= mod;
		}

	}

	return dp[sum] = ans ;
	
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;
 
    memset(dp, -1, sizeof dp);
 
    cin >> n >> k;
 
    for(int i = 1; i <= n; i++){
       	cin >> coin_value[i];
    }

    cout << coin_combinations(k) << '\n';
    
 
    return 0 ;
}
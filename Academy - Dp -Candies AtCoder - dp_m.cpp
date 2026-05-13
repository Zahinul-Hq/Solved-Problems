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
const int N = 1e5 + 7 , mod = 1e9 + 7;
int candies[105], n, k;
ll dp[105][N];
ll candy_combinations(int indx, int total_candies){

	if(indx == 0)
		return total_candies == 0;

	if(dp[indx][total_candies] != -1)
		return dp[indx][total_candies];

	ll ans = 0;

	for(int i = 0; i <= candies[indx]; i++){

		if(total_candies - i >= 0)
			ans += candy_combinations(indx + 1, total_candies - i) % mod;

	}

	return dp[indx][total_candies] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    cin >> n >> k;

    memset(dp, -1, sizeof dp);

    for(int i = 1; i <= n; i++){
    	cin >> candies[i];
    }

    cout << candy_combinations(1, k) % mod << endl;
    return 0 ;
}

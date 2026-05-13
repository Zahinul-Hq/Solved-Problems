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

const int N = 105;

int coins[N], dp[N][100005];
set<int>coin_sum;
int total_coins(int i, int sum){


	if( i == 0)
		return 0;

	if(dp[i][sum] != -1)
		return dp[i][sum];

	int ans = total_coins(i - 1, sum);

	ans = total_coins(i - 1, sum + coins[i] ) + coins[i]; 


	if(sum != 0)
		coin_sum.insert(sum);
	if(ans != 0)
		coin_sum.insert(ans);



	return dp[i][sum] = ans;


}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;


	int n; 

	cin >> n;

	memset(dp, -1, sizeof dp);

	for(int i = 1; i <= n; i++){
		cin >> coins[i];
	}
	int x = total_coins(n, 0);

	cout << coin_sum.size() << endl;

	for(auto i : coin_sum){

		cout << i << " ";

	}

	cout << endl;
    return 0 ;
}

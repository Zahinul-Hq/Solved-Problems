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

const int N = 1e6+7 ;

const int mod = 1e9 + 7;

vector<ll> dp(N , -1) ;
ll combo(int n){

	if(n == 0)
		return 1;
	if(n < 0)
		return 0 ;
	if(dp[n] != -1){
		return dp[n] ;
	}

	ll ans = 0;

	for(int i = 1; i <= 6; i++){
		ans += combo(n - i) % mod;
	}


	return dp[n] = ans % mod ;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

	int x ;

	cin >> x ;

	cout << combo(x) << endl;

    
    return 0 ;
}

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
const int N = 1e5+50 ;
ll dp[N], h[N], n;

ll total_cost(int i){

	if( i == n)
		return 0;


	if(dp[i] != -1)
		return dp[i];



	ll cost = inf;

	cost = total_cost(i+1)+abs(h[i] - h[i+1]) ;

	if( i + 2 <= n)
		cost = min(cost, total_cost(i+2)+abs(h[i] - h[i+2]));

	return dp[i] = cost ;



}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

	memset(dp, -1, sizeof dp) ;

	cin >> n ; 

	for(int i = 1; i <= n; i++)
		cin >> h[i];

	cout << total_cost(1) << endl ;

    return 0 ;
}

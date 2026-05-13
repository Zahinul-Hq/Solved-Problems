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
string a, b;
int n, m;
ll dp[5005][5005];
ll total_cost(int i, int j){


	if(i == n){
		if(j == m)
			return 0;

		return m - j;
	}

	if( j == m){

		return n - i;
	}

	if(dp[i][j] != -1)
		return dp[i][j];


	ll ans = inf;
	if(a[i] == b[j]){
		ans = min(ans, total_cost(i + 1, j + 1));
	}

	ans = min(ans , 1 + total_cost(i + 1, j + 1));
	ans = min(ans , 1 + total_cost(i + 1, j ));
	ans = min(ans , 1 + total_cost(i , j + 1));
	

	return dp[i][j] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

	memset(dp, -1, sizeof dp);

    cin >> a >> b;

    n = a.size();
    m = b.size();

    cout << total_cost(0,0) <<endl;

    return 0 ;
}

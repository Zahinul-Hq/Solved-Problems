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

const int N = 5e5 + 7; 

int a[N];

ll dp[N]

int possible_ways(int i, int j){

	if( i > j)
		return 0;

	if(pref[i] == (pref[n] - pref[j - 1]) && pref[i] == (pref[j] - pref[i - 1]))
		return 1;

	if(dp[i][j] != -1)
		return dp[i][j];


	ll ans = possible_ways(i + 1, j);
	ans += possible_ways(i, j - 1);
	ans += possible_ways(i + 1, j - 1);


	return dp[i][j] = ans;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t ;
    cin>>t ;
    
    while (t--)
    {
        
    }
    return 0 ;
}

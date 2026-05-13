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
const int N=22 ;
int dp[N][4] , n , cost[N][4] ;
int rec(int i, int last){

	if(i==n+1)
		return 0 ;

	if(dp[i][last]!=-1)
		return dp[i][last] ;

	int ans = 1e9;

	for(int col= 0 ; col<3 ; col++){
		
		if(col!=last)
			ans = min(ans, cost[i][col]+rec(i+1, col)) ;
	}

	return dp[i][last]=ans ;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t  , cs=1;
    cin>>t ;
    
    while (t--)
    {
        cin>>n ; 

        for(int i=1 ; i<=n ; i++){
        	cin>>cost[i][0]>>cost[i][1]>>cost[i][2];
        }

        memset(dp , -1 , sizeof dp) ;

        cout<<"Case "<<cs++<<": "<<rec(1,3)<<endl;
    }
    return 0 ;
}

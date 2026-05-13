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

int wt[105] , p[105] ;

ll dp[105][1000005] ; 

ll knapsack(int i , int wt_left){

	if(i<0 || wt_left==0)
		return 0 ;

	if(dp[i][wt_left]!=-1)
		return dp[i][wt_left];

	ll ans  = knapsack(i-1 , wt_left);

	if(wt_left-wt[i]>=0)	
		ans = max(ans ,knapsack(i-1 , wt_left-wt[i])+ p[i]) ;

	return dp[i][wt_left]=ans ;


}
int main()
{

	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    ll t , n ;
    cin>>t>>n ;

    int a[t] ;

    for(int i=0 ; i<t ; i++){
    	cin>>wt[i]>>p[i] ;
    }

    int ans=knapsack(t-1, n);

    cout<<ans<<endl;
    return 0 ;
}

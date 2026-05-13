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
ll dp[100] ;
ll rec(int n ){

	if(n==1)
		return 1;
	if(n==2)
		return 2 ;
	if(n==3)
		return 2 ;

	if(dp[n]!=-1)
		return dp[n];

	return dp[n]=rec(n-2)+rec(n-3) ;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t ;
    
    while (cin>>t)
    {
        memset(dp ,-1,sizeof dp) ;

        cout<<rec(t)<<endl;
    }
    return 0 ;
}

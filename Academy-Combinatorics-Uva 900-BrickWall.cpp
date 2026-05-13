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
ll fib(int n){

	if(n==1)
		return 2 ;
	if(n==0)
		return 1 ;

	if(dp[n]!=-1)
		return dp[n];


	return dp[n]= fib(n-1)+fib(n-2) ;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t , i=1;
    cin>>t ;

    while (t--)
    {
    	int n ;
    	cin>>n ;

    	if(n==0)
    		break;

        memset(dp , -1 ,sizeof dp);
        cout<<"Scenario #"<<i++<<":"<<endl<<fib(n)<<endl<<endl;
    }
    return 0 ;
}

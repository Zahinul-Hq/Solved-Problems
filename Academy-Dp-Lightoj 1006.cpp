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
int  a, b, c, d, e, f;
const int mod = 10000007;
ll dp[100009] ;
int fn(int n) {


	

    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;

    if(dp[n]!=-1)
    	return dp[n] ;
    
   	dp[n]=(fn(n-1)+fn(n-2))%mod ;

   	for(int i=2 ; i<=6 ; i++){
   		dp[n]= (dp[n]+fn(n-i))%mod ;

   	}

   	return dp[n] ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t , i =1 ;
    cin>>t ;
    
    while (t--)
    {

    	memset(dp , -1 , sizeof(dp) ) ;
    	int n ;
        cin>>a>>b>>c>>d>>e>>f>>n ;

        cout<<"Case "<<i++<<": "<<fn(n)<<endl;

        
    }
    return 0 ;
}

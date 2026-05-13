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
const int N = 55 , K = 1005 , mod=100000007 ;
int n , a[N] , c[N] , req_value ,dp[N][K];
int rec(int i , int curr_value){

	if(curr_value>req_value)
		return 0;
	if(i==n+1){
		if(curr_value==req_value)
			return 1 ;

		return 0;
	}

	if(dp[i][curr_value]!=-1)
		return dp[i][curr_value];
	int ans=0 ;

	for(int cnt=0 ; cnt<=c[i] ;cnt++){
		ans+=rec(i+1 , curr_value+(a[i]*cnt));
		ans = ans%mod ;
	}

	return dp[i][curr_value]=ans ;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t , cs=0;
    cin>>t ;
    
    while (t--)
    {
        cin>>n>>req_value ;

        for(int i=1 ;i<=n;i++){
        	cin>>a[i];
        }
        for(int i=1 ; i<=n ; i++){
        	cin>>c[i] ;
        }
        memset(dp , -1 , sizeof dp ) ;

        cout<<"Case "<<++cs<<": "<<rec(1,0)<<endl;
    }
    return 0 ;
}

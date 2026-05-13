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

const int N = 105 ;

ll w[N] , n, v[N],W ; ;

ll rec(ll i , ll weight){

	if(i==n+1)
		return 0 ;
	if(dp[i][weight]!=-1)
		return dp[i][weight];

	ll ans =rec(i+1,weight);

	if(weight+w[i]<=W){
		ans=max(ans, rec(i+1 ,weight+w[i])+v[i]);
	}
	

	return dp[i][weight]=ans ;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

   	cin>>n>>W ;

   	for(int i=1 ; i<=n ;i++){
   		cin>>w[i]>>v[i] ;
   	}

   	cout<<rec(1,0)<<endl;

    return 0 ;
}

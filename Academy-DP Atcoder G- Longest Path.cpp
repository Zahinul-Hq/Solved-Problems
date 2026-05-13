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
const int N = 1e5+9 ;
vector<int>graph[N] ;
int dp[N] ;
ll dfs(int v){


	if(dp[v] != -1)
		return dp[v];

	ll ans = 0;

	for(auto u : graph[v]){
		ans = max(ans , 1 + dfs(u));
	}


	return dp[v] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

   memset(dp , -1 ,sizeof dp );
   int n,m ;
   cin>>n>>m ;

   for(int i=1 ; i<=m ; i++){

   		int u , v ;
   		cin>>u>>v ;
   		graph[u].pb(v);
   }

   ll ans=0 ;

   for(int i=1 ; i<=n ; i++)
   		ans=max(ans , dfs(i)) ;

   	cout<<ans<<endl;

    return 0 ;
}

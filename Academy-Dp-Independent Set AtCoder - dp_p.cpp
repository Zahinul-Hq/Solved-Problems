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
int mod = 1e9 + 7;

vector<int>graph[N] ;
ll dp[N][2] ;

void dfs(int node, int parent){


	dp[node][0] = 1;
	dp[node][1] = 1;


	for(auto child : graph[node]){

		if(child != parent){

			dfs(child, node);

			dp[node][0] = (dp[node][0] *(dp[child][1] + dp[child][0])) % mod;

			dp[node][1] = (dp[node][1]*(dp[child][0])) % mod;

		}
	}

	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

   memset(dp , -1 ,sizeof dp );

   int n;

   cin >> n;

   for(int i = 1 ; i <= n - 1; i++){

   		int u , v ;

   		cin >> u >> v ;

   		graph[u].pb(v);
   		graph[v].pb(u);
   }

    (dfs(1, 0)) ;

  


   cout << (dp[1][0] + dp[1][1]) % mod << endl;

    return 0 ;
}

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
        ll n,u,v ;

        cin>>n ;

        vector<ll>graph[n+1] ;

        for(int i=1; i<=n-1 ; i++){
        	cin>>u>>v ;
        	graph[u].pb(v) ;
        	graph[v].pb(u);
        }

        ll cnt=0 ;

        for(int i=1; i<=n ; i++){
        	if(graph[i].size()==1)
        		cnt++ ;

        }

        

        cout<<ceil(1.00*cnt/2.0)<<endl;
    }
    return 0 ;
}

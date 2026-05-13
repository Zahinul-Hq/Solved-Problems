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
const int N= 1e5 + 9 ;
vector<pair<int,int>>adj[N] ;
vector<int> ans(N);
int cnt=1;
void dfs(int u , int p , int cur){

    for(auto [v,i] : adj[u]){

        if(v!=p){
            ans[i]=cur ;
            dfs(v, u , 5-cur) ;
        }
    }


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
        int n, u,v ;

        cin>>n ;

        for(int i=1; i<=n-1 ;i++){

        	cin>>u>>v ;

        	adj[u].pb({v,i});
        	adj[v].pb({u,i});

        }

        bool flag=0 ;

        int start=1 ;

        for(int i=1 ; i<=n ; i++){

            if(adj[i].size()>2){
                flag=1 ;
            }

            if(adj[i].size()==1)
                start=i;
        }

        if(flag){
            cout<<-1<<endl;
            //continue;
        }else{

            dfs(start,0,2);

            for(int i=1 ; i<n ; i++ ){
                cout<<ans[i]<<" ";
            }

            cout<<endl;

            
        }

        for(int i=1 ; i<=n ; i++ ){
                adj[i].clear() ;
                ans[i]=0;
            }

        


    }
    return 0 ;
}

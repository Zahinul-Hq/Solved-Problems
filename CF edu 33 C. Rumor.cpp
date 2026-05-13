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
const int N = 1e5+7 ;
bool vis[N]  ;
vector<ll>graph[N];
vector<pair<int,int>>lvl;
void bfs(int src){

	vis[src]=true ;
    queue<int> q;
    q.push(src);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int u : graph[v]) {
            if (!vis[u]) {
                vis[u]=true ;
                q.push(u);

            }
        }

        
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    ll n , m , indx, mn=1e18;
    cin>>n>>m ;

    for(int i=1; i<=n ;i++){
        
        cin>>mn ;

        lvl.pb({mn ,i});
    }
    
    while (m--)
    {
        int u , v ;

        cin>>u>>v ;

        graph[u].pb(v) ;
        graph[v].pb(u) ;

    }

    sort(lvl.begin() , lvl.end()) ;
    ll ans=0; 

    for(int i=0 ; i<n ;i++ ){

        int x= lvl[i].second ;

        if(!vis[x]){

            bfs(x);

            ans+=lvl[i].first ;
            
        }

    	
    }

      

    cout<<ans<<endl;

    return 0 ;
}

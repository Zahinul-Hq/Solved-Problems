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
vector<int>graph[N] , lvl(N,0);
ll s1=0,s2=0, cnt=0;

vector<int>part1,part2 ;
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

                cnt++ ;

                lvl[u]=lvl[v]+1 ;

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

    int t ;
    cin>>t ;

    int n=t;
    
    while (t--)
    {
        int u , v ;

        cin>>u>>v ;

        graph[u].pb(v) ;
        graph[v].pb(u) ;

    }

    bfs(1);

    for(int i=1 ; i<=n ;i++ ){

    	if(lvl[i]%2!=0)
    		s1++;
    	else
    		s2++;
    }

    ll ans = (s1*s2) - cnt;    

    cout<<ans<<endl;

    return 0 ;
}

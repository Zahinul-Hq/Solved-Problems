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
const int N =2e5+7 ;
vector<int>graph[N] ;
ll cnt[N] ;
bool vis[N] ;
void dfs(int parent){

	vis[parent]=true ;

	if(graph[parent].size()==1 && parent!=1){
		cnt[parent]=1 ;
	}else{

		for(int child : graph[parent]){
			if(!vis[child]){
				dfs(child ) ;
				cnt[parent]+=cnt[child] ;
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
    
    while (t--)
    {
        int n , u , v ,q;

        cin>>n;

        for(int i=0 ; i<n-1 ; i++){

        	cin>>u>>v ;
        	graph[u].push_back(v) ;
        	graph[v].push_back(u); 
        }

        memset(vis , 0, sizeof vis) ;
        memset(cnt , 0 , sizeof cnt) ;

        dfs(1) ;

        cin>>q ;

        while(q--){

        	int x , y ;

        	cin>>x>>y ;


        	ll res= cnt[x]*cnt[y] ;

        	cout<<res<<endl; 

        }

        for(int i=0; i<=n ; i++)
        	graph[i].clear() ;


    }
    return 0 ;
}

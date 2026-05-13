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
map<ll,int>mp ;
const int N=1e5+7 ;
vector<ll>a , b[N];
int vis[10][N+N],x ;

void dfs(int l, int v ){
    vis[l][v]=1;
    for(int i=0 ; i<a.size() ;i++){
        int u= a[i] ;
        if(vis[l][v+u]==0 && mp[v+u]<1 && v+u<=x){
            dfs(l,v+u) ;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL) ;
    inout() ;

    ll n ,m, val;
    
    cin>>n ;
    for(int i=0 ; i<n ; i++){
        cin>>val ;
        a.pb(val) ;
    }
    cin>>m ;
    for(int i=0 ; i<m ; i++){
        cin>>val ;
        mp[val]++ ;
    }


    cin>>x ;
    bool flag=0 ;

    for(int i=0 ; i<a.size() ; i++){


        if(mp[a[i]]<1)
            dfs(i,a[i]) ;

        if(vis[i][x])
            flag=1 ;


    }

    if(flag)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;






    return 0 ;
}

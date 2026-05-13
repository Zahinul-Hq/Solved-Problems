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
const int N= 2e5+7 ;
vector<int>adj[N] ;
vector<bool> used(N);
vector<int> d(N);
int cnt=1 ;
void dfs(int src){

	used[src]=true ;

	for(auto ch : adj[src]){

		if(!used[ch]){
			cnt++ ;
			dfs(ch) ;
		}
	}

	d[src]=cnt ;

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
        int n,x ;

        cin>>n ;


        for(int i=1 ; i<=n ;i++){

        	cin>>x ;
        	adj[i].pb(x);
        }

        for(int i=1 ; i<=n ; i++){

        	if(!used[i]){
        		cnt=1;
        		dfs(i) ;
        	}
        }
        for(int i=1 ; i<=n ; i++){

        	cout<<d[i]<<" ";
        }
        cout<<endl;

        for(int i=1 ; i<=n ; i++){

        	adj[i].clear();
        	used[i]=0;
        	d[i]=0 ;
        }


    }
    return 0 ;
}

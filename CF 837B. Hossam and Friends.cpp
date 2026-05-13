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
        ll n , m , x, y; 

        cin>>n>>m ;

        if(m==0){
        	cout<<(n*(n+1))/2<<endl;
        	continue;
        }

        vector<ll>mark(n+1,0);



        while(m--){
        	cin>>x>>y ;

        	if(x>y)
        		swap(x,y) ;

        	mark[y]=max(x,mark[y]) ;
        }

        ll last=0 ; 


        for(int i=1 ; i<=n ; i++){
        	if(last<mark[i]){
        		last = mark[i] ;
        	}
        	mark[i]=last ;


        }
        ll ans = 0 ;
        last=0 ;  

        for(int i = 1 ; i<=n ; i++){

        	last = max(last, mark[i]) ;

        	ans+=(i-last);
        }

        

        cout<<ans<<endl;

    }
    return 0 ;
}

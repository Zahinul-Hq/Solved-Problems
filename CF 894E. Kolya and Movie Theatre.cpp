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
        ll n  , m , d;

        cin>>n>>m>>d ;

        vector<int>v(n,0);

        for(int i=0 ; i<n ; i++){
        	cin>>v[i] ;
        }

        ll ans=0; 
        ll sum =0 ;

        priority_queue<int , vector<int> , greater<int>>pq ;

        for(int i=0 ; i<n ; i++){

        	if(v[i]>0){
        		sum+=v[i] ;
        		pq.push(v[i]) ;
        	}
        	if(pq.size()>m){
        		sum-=pq.top() ;
        		pq.pop() ;
        	}


        	ans=max(ans , sum-  1LL*d*(i+1)) ;
        }

        cout<<ans<<endl;
    }
    return 0 ;
}

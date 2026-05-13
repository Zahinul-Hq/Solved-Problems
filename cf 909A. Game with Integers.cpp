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
        int n ;

        cin>>n ;

        vector<ll>a(n+1,0) , psum(n+1,0) ;

        ll mx = low  , mn = inf , ans = 0 , suml=0 , sumf=0; 

        for(int i=1 ; i<=n ; i++){
        	cin>>a[i] ;
        }
        for(int i=1 ; i<=n ; i++){

        	psum[i]=psum[i-1]+a[i] ;
        }


        for(int k=1 ; k<=n ;k++){
        	int prev =0 ;
        	mx = low , mn = inf ;

        	if(n%k!=0){
        		continue ;
        	}
        	for(int i=k ; i<=n ; i+=k){

        		mx=max(mx, psum[i]-psum[prev]) ;
        		mn= min(mn , psum[i]-psum[prev]) ;

        		prev = i  ;

        	}
        	ans= max(ans, abs(mx-mn)) ;
        }

        cout<<ans<<endl;


        
    }
    return 0 ;
}

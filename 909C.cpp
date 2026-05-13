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

        vector<ll>a(n+1,0) , psum(n+1,0), indx ;

        ll mx = low  , mn = inf , ans = low , suml=0 , sumf=0; 

        for(int i=1 ; i<=n ; i++){
        	cin>>a[i] ;
        }

        if(n==1){
        	cout<<a[n]<<endl;
        	continue ;
        }

        for(int i=1 ; i<=n ; i++){

        	psum[i]=psum[i-1]+a[i] ;

        	//cout<<psum[i]<<" " ;
        }
        for(int i=1 ; i<=n-1 ; i++){
        	if(abs(a[i]%2)==0 && abs(a[i+1]%2)==0){
        		indx.pb(i);
        	}
        	else if(abs(a[i]%2)==1 && abs(a[i+1]%2)==1){
        		indx.pb(i);
        	}
        }

        indx.pb(n) ;

        int prev = 0;

        for(int i= 0 ; i<indx.size() ; i++)
        	cout<<indx[i]<<" ";

        

        for(int k=0 ; k<indx.size() ;k++){
        	mx = low ;

        	for(int i=prev; i<=indx[k] ; i++){

        		cout<<psum[i]<<" "<<psum[indx[k]]<<endl;

        		mx=max(mx, psum[indx[k]]-psum[i]) ;

        	}
        	ans= max(ans, mx) ;

        	prev= indx[k];
        }

        cout<<ans<<endl;


        
    }
    return 0 ;
}

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
        int n , k ;

        cin>>n>>k;


        vector<ll>a(n,0) ,b ; 

        for(int i=0 ; i<n ; i++){
        	cin>>a[i] ;
        }

        sort(a.begin() ,a.end());

        if(k>=3){
        	cout<<0<<endl;
        	continue ;
        }

        for(int i=0 ; i<n ; i++){
        	for(int j=0 ; j<n ; j++){
        		if(i!=j)
        			b.pb(abs(a[i]-a[j]));
        	}
        }

        ll ans = inf ;

        for(int i=0 ; i<b.size() ; i++){
        	ans = min(ans , b[i]) ;
        }

        if(k==1){
        	cout<<min(a[0],ans)<<endl;
        	continue;
        }

        

        for(int i=0 ; i<b.size() ; i++){

        	int dw = lower_bound(a.begin(),a.end(),b[i]) - a.begin();

        	ll val = inf ;

        	val = min(val , abs(b[i]- a[dw])) ;

        	dw-- ;

        	val = min(val , abs(b[i]- a[dw])) ;

        	ans = min(ans , val) ;


        }

        cout<<ans<<endl;
    }
    return 0 ;
}

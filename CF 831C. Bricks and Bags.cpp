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

        vector<ll>a(n,0);

        for(int i=0 ; i<n ;i++ ){
        	cin>>a[i];
        }

        sort(a.begin() ,a.end()) ;



        ll ans = abs(a[0]-a[n-1])+abs(a[0]-a[1]) ;

        ans = max(ans ,abs(a[n-2]-a[n-1])+abs(a[0]-a[n-1])) ;

        for(int i=2 ; i<n ; i++){

        	ll x = abs(a[0]-a[i]);
        	ll y = abs(a[i]-a[i-1]);

        	ans = max(ans , x+y) ;

        }

        for(int i=0 ; i+2<n ; i++){

        	ll x = abs(a[n-1]-a[i]);
        	ll y = abs(a[i]-a[i+1]);

        	ans = max(ans , x+y) ;

        }

        cout<<ans<<endl;
    }
    return 0 ;
}

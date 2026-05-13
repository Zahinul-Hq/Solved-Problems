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
        int n,x ;

        cin>>n ;

        vector<pair<ll,int>>a;

        vector<ll>ans(n,-1) , pref(n,0);

        for(int i=0 ; i<n ; i++){
        	cin>>x;
        	a.pb({x,i}) ;
        }

        sort(a.begin() ,a.end());

        for(int i=0 ; i<n ; i++){
        	if(i==0){
        		pref[i]=a[i].F ;
        		continue;
        	}
        	pref[i]=pref[i-1]+a[i].F ;
        }

        for(int i=0 ; i<n-1 ; i++){

        	ll sum = pref[i+1]-pref[i];

        	if(pref[i]<sum){
        		ans[a[i].S]=i;
        	}
        }

        ans[a[n-1].S]=n-1 ;


        for(int i=n-2 ; i>=0 ; i-- ){
        	if(ans[a[i].S]==-1){
        		ans[a[i].S]=ans[a[i+1].S] ;
        	}

        }

        for(int i=0 ; i<n ; i++){
        	cout<<ans[i]<<" " ;
        }

        cout<<endl;
    }
    return 0 ;
}

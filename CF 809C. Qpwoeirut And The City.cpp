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

        bool odd =(n%2) ;

        vector<ll>a(n,0);

        for(int i=0 ; i<n ; i++){
        	cin>>a[i];
        }

        ll ans= 0 ;

        if(odd){

        	for(int i=1 ; i<n-1 ; i+=2){

        		if((a[i]>a[i-1]) && (a[i]>a[i+1]))
        			continue ;
        		ans+=abs(a[i]-max(a[i-1],a[i+1]))+1 ;
        	}

        	cout<<ans<<endl;
        	continue ;
        }

        vector<ll>pref(n+3,0) , suff(n+3,0);


        for(int i=1  ; i<n-1; i+=2 ){

            ll val  = max(0LL , max(a[i-1],a[i+1])-a[i]+1);

            if(i==1){
                pref[i]=val;
            }else{
                pref[i]=pref[i-2]+val;
            }
        }
        for(int i=n-2  ; i>=1; i-=2 ){

            ll val  = max(0LL , max(a[i-1],a[i+1])-a[i]+1);

            if(i==n-2){
                suff[i]=val;
            }else{
                suff[i]=suff[i+2]+val;
            }
        }
        ll ans0 = suff[2] ;

        for(int i=1 ; i<n-1 ; i+=2){

            ll lf = pref[i] ;

            ll rt = suff[i+3] ;

            ans0 = min(ans0 , lf+rt);
        }

        cout<<ans0<<endl;





    }
    return 0 ;
}

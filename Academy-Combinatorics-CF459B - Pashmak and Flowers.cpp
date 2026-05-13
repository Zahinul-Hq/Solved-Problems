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


        ll n ;
        cin>>n ;

        vector<ll>a(n,0) ;

        for(int  i=0 ; i<n ; i++){
        	cin>>a[i];
        }

        ll mx=*max_element(a.begin() ,a.end()) ;
        ll mn=*min_element(a.begin() ,a.end()) ;

        ll x=0 , y=0;

        for(int  i=0 ; i<n ; i++){

            if(mx==a[i])
                x++ ;
            if(mn==a[i])
                y++ ;
        }

        ll sum=x*y ;


        if(mx!=mn)
            cout<<mx-mn<<" "<<sum<<endl;
        else{
            sum= 1ll*n*(n-1)/2 ;
            cout<<0<<" "<<sum<<endl;
        }



    
    return 0 ;
}

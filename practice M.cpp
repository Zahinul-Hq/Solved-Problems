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

    ll n , k ;

    cin>>n>>k; 

    vector<ll>a(n,0);


    ll mx = 0 ;


    for(int i=0 ; i<n ; i++){
    	cin>>a[i];

    	mx+=a[i];
    }


    ll Xor = a[0] ;


    for(int i=1 ; i<n ; i++){

    	Xor^=a[i] ;

    }

    if(k==0){
    	cout<<mx<<endl;
    	return 0 ;
    }
    
   	for(ll j = 1 ;; j=(j*2)){

   		if(j>k){
   			break;
   		}

   		ll ans =0 ;

   		for(int i=0 ; i<n ; i++){

   			ll x = j^

    		ans+=(a[i]^j);
   		}



   		mx = max(mx , ans) ;
   	} 

   	mx = max(mx , mx^Xor) ;

    cout<<(15^8)<<endl;

    return 0 ;
}

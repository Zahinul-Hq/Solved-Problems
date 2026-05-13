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

    cin>>n>>k ;

    vector<ll>safe(k,0) ;

    for(int i=0 ; i<k ; i++){
    	cin>>safe[i];
    }

    int j =0 ;

    ll ans = 0;

    for(int i=1 ; i<=n ; i++){

    	if(j>=k)
    		break ;

    	if(j<=k-1 && safe[j]==i){
    		ans+= n - safe[j]+1 ; 
    		j++ ;

    	}else{

    		ans+= n-safe[j]+1;
    	}


    }

    cout<<ans<<endl;


    return 0 ;
}

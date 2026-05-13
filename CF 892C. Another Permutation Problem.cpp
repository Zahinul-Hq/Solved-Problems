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
ll calc(int n , int val){

    vector<ll>vec ;

    for(int i=1 ; i<=n ; i++){
        vec.push_back(i) ;
    }

    reverse(vec.begin()+val,vec.end()); 

    ll ans=0 ,mx=-1 ;

    for(int i=0; i<n ; i++){

        ans+=(vec[i]*(i+1)) ;
        mx= max(mx , (vec[i]*(i+1))) ;
    }

    ans-=mx ;

    return ans ;
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

        if(n==2){
            cout<<2<<endl;
            continue ;
        }

        ll ans=0 ;

        for(ll i=0 ; i<n; i++){

        	ans=max(ans, calc(n , i+1)) ;
        }

        cout<<ans<<endl;



    }
    return 0 ;
}

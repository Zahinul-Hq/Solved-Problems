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
const int N = 2e5+7 ;
ll arr[N] ,n ;
ll c ;
bool func(ll x){

	ll sum =0 ;


	for(int i=0 ; i<n ; i++){

		sum = arr[i]*x;

		if()
	}


	return true ;

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
        cin>>n>>c ;

        memset(arr , 0, sizeof arr) ;

        for(int i=0 ; i<n ; i++){
        	cin>>arr[i] ;
        }



        ll hi = INT_MAX , lo = 0 ;

        while(hi-lo>1){

        	ll mid = (hi+lo)/2 ;

        	if(func(mid))
        		lo = mid+1;
        	else
        		hi = mid ;
        }

        ll ans = lo/2ll ;


        cout<<ans<<endl;

    }
    return 0 ;
}

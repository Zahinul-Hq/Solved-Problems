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
const int N = 2e5 + 7 ;
vector<ll>vec(N,0) ;

ll pred(ll x , int n){

	ll sum = 0 ;

	for(int i=0 ; i<n ; i++){
		if(vec[i]<x) 
			sum+=(x-vec[i]) ;
	}

	return sum ;
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
        int n , k; 

        cin>>n>>k ;

        

        for(int i=0 ; i<n ; i++){
        	cin>>vec[i] ;
        }

        ll tot =INT_MAX;

       	ll hi =INT_MAX, lo= 1 ;

       	while(hi>=lo){

       		ll mid= (hi+lo)/2 ;

       		ll ans = pred(mid , n) ;

       		if(ans<=k){

       			tot = mid ;
       			lo=mid+1 ;
       		}
       		else
       			hi=mid-1;
       	}


       	cout<<tot<<endl;



       


    }
    return 0 ;
}

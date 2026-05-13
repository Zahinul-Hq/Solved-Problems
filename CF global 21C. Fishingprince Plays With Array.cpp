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
vector<pair<ll,ll>>res(vector<ll>a , int m ){

	int n = a.size() ;

	vector<pair<ll,ll>>ans ;

	for(int i=0 ; i<n ; i++){

		ll x=a[i], y=1 ; 

		while(x%m==0){ 
			x=x/m ;
			y*=m ;
		}

		if(!ans.empty() && x==ans.back().F){
			ans.back().S+=y ;
		}else{
			ans.pb({x,y});
		}
	}

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
        int n , m , k;

        cin>>n>>m ;

        vector<ll>a(n,0);

        for(int i=0 ; i<n ; i++){
        	cin>>a[i];
        }

        cin>>k ;
        vector<ll>b(k,0);

        for(int i=0 ; i<k; i++){
        	cin>>b[i];        
        }

        auto p = res(a,m);
        auto q = res(b,m);

        cout<<(p == q ? "Yes\n" : "No\n") ;


    }
    return 0 ;
}

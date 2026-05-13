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

map<int,vector<int>>x , y;
ll sum(){

	ll ans = 0 ;

	for(auto [i , j] : x){
		sort(j.begin() ,j.end()) ; 
		ll s=0 , c=0 ;
		for(auto p : j){
			ans+=p*c-s ;
			c++ ;
			s+=p ;
		}
	}

	for(auto [i , j] : y){
		sort(j.begin() ,j.end()) ; 
		ll s=0 , c=0 ;

		for(auto p : j){
			ans+=p*c-s ;
			c++ ;
			s+=p ;
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


        int n , m ,z;

        cin>>n>>m ;

        for(int i=0 ; i<n ;i++){
        	for(int j=0 ; j<m ; j++){
        		cin>>z ;
        		x[z].pb(i);
        		y[z].pb(j);
        	}
        }

        ll ans = sum() ;

        cout<<ans<<endl;

        x.clear();
        y.clear();


    
    return 0 ;
}

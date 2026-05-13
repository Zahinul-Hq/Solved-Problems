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
int main() {


	inout() ;


	ll n , m , k , r  , sum=0  , p ,q, a ,b;
	map<ll,ll>mp ;

	cin>>n>>m>>k>>r ;

	while(m--){

		cin>>a>>b;

		mp[b]=a ;
		sum+=a ;
	}

	ll need = n-sum ;

	if(need<=0){
		cout<<0<<endl;
		return 0 ;
	}




	for(auto i : mp){

		
	}

	
	return 0;
}

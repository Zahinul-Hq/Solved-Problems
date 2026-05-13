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

	cin>>n>>m>>k>>r ;

	vector<pair<ll,ll>>v;

	while(m--){
		cin>>a>>b;

		v.pb({b,k}) ;
		sum+=a ;
	}

	ll need = n-sum ;


	sort(v.begin() , v.end()) ;

	if(need<=0){
		cout<<0<<endl;
		return 0 ;
	}

	ll gsum=0 ;

	for(auto it : v){

		if(it.S<need){
			need-=it.S ;
			gsum+=(it.S*it.F) ;
			continue ;
		}

		gsum+= (need*it.F) ;

		if(gsum>r)
			break;

		cout<<gsum<<endl;
		return 0 ;
	}


	cout<<-1<<endl;



	
	return 0;
}

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

    int t ;
    cin>>t ;
    
    while (t--)
    {
       	ll n , a, b, k ,x,y;


       	cin>>n>>k>>a>>b ;

       	vector<pair<ll,ll>>p ;

       	pair<ll,ll>aa,bb ;

       	for(int i=1; i<=n ; i++){

       		cin>>x>>y ;
       		p.pb({x,y}) ;

       		if(i==a)
       			aa={x,y};
       		if(i==b)
       			bb={x,y};

       	}

       	if(a<=k && b<=k){
       		cout<<0<<endl;
       		continue; 
       	}
       	ll ans =abs(aa.F-bb.F)+abs(aa.S-bb.S) , acost=inf , bcost=inf ;

       	for(int i=0 ; i<k ; i++){

       		if(a>k){
       			acost=min(acost ,(abs(p[i].F-aa.F)+abs(p[i].S-aa.S)));
       		}else acost=0 ;
       		if(b>k){
       			bcost = min(bcost , (abs(p[i].F-bb.F)+abs(p[i].S-bb.S))) ;
       		}else bcost=0 ;

       	}



       	cout<<min(acost+bcost , ans )<<endl;
    }
    return 0 ;
}

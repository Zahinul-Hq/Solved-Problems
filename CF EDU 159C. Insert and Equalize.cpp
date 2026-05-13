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
       	ll n , mx=low , mn= inf;

       	cin>>n ;

       	vector<ll>a(n,0);
       	map<ll,bool>mp ;

       	for(int i =0 ; i<n ; i++){
       		cin>>a[i];
       		mx=max(mx , a[i]);
       		mn = min(mn , a[i]) ;
       		mp[a[i]]=1;
      	}

      	ll gcd = mx-mn+(mx==mn);

      	//cout<<gcd<<endl;

      	for(int i=0 ; i<n ; i++){


      		if(mx!=a[i])
      			gcd= __gcd(gcd,mx-a[i]);
      	}

      	ll op=0 , cnt=1;

      	//cout<<gcd<<endl;

      	for(int i=0 ; i<n ; i++){
      		op+=((mx-a[i])/gcd);
      	}

      	while(mp[mx-gcd]){
      		mx-=gcd;
      		cnt++ ;
      	}

      	//cout<<op<<" "<<cnt<<endl;

      	cout<<min(op+cnt , op+n+1)<<endl;


    }
    return 0 ;
}

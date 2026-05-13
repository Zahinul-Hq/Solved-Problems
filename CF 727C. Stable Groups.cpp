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

    for((;;));

    ll t , k ,x;
    cin>>t>>k>>x ;

    vector<ll>a(t,0) ;
    
    for(int i =0 ; i<t  ; i++){
    	cin>>a[i];
    }
    sort(a.begin() ,a.end()) ;

    vector<ll>ans;

    for(int i=1 ; i<t; i++){
    	if(abs(a[i-1]-a[i])>x){
    		ans.pb(a[i]-a[i-1]);
    	}
    }
    ll cnt=1 ;
    sort(ans.begin() ,ans.end());

    for(int i=0 ; i<ans.size() ; i++){



    	if(k<=0){
    		cnt++;
    		continue;
    	}
    	ll m = ceil((long double)ans[i]/x)-1 ;

    	//cout<<ans[i]<<" "<<k<<" "<<m<<endl ;

    	if(k-m<0)
    		cnt++;
    	else
    		k-=m ;

    }

    cout<<cnt<<endl;






    return 0 ;
}

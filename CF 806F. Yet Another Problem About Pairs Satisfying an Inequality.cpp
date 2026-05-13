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

    	int n ,x;

    	cin>>n ;

    	vector<pair<int,int>>a ;



    	for(int i=1 ; i<=n ;i++){
    		cin>>x ;

    		if(x<i)
    			a.pb({x,i}) ;
    	}



    	n = a.size()-1;

    	//cout<<n<<endl;

    	ll ans = 0 ;

    	sort(a.begin() ,a.end()) ;

    	vector<int>v(a.size(), 0) ;

    	for(int i=0 ; i<a.size() ; i++){
			v[i]=a[i].F ;
    	}
    	for(int i=0 ; i<n ; i++){

    		int hi=n, lo=i+1 , ss=0;

    		//cout<<i<<endl;

    		int x = a[i].S ;

    		int  up = upper_bound(v.begin()+i , v.end() ,x)- v.begin();

    		//cout<<up<<" "<<i<<endl;

    		ans+=(n-up+1);
    	}

    	cout<<ans<<endl;




    }
    return 0 ;
}

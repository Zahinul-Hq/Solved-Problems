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
        int n ; 

        cin>>n ;

        vector<ll>a(n,0);

        for(int i=0 ; i<n ; i++){

        	cin>>a[i];

        }

        ll mn = inf ,ans=0;

        vector<ll>s1,s2 ;

        s1.pb(mn);
        s2.pb(mn) ;


        for(int i= n-1 ; i>=0  ; i--){

        	if(s1.back()<s2.back()){

                int temp = s1.back();
        		s1.pb(s2.back());
        		s2.pb(temp);
        	}

        	if(a[i]>=s1.back())
        		s1.pb(a[i]);
        	else if(a[i]>=s2.back())
        		s2.pb(a[i]);
        	else{
        		ans++ ;
        		s1.pb(a[i]);
        	}
        }

        cout<<ans<<endl;
    }
    return 0 ;
}

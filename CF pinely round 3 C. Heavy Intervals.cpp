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

    	int n ; ll  x;

    	cin>>n ;
        multiset<ll>r ;

        vector<ll>l(n,0) , c(n,0);

        for(int i=0 ; i<n ; i++){
        	cin>>l[i];
        }
        for(int i=0 ; i<n ; i++){
        	cin>>x ;
        	r.insert(x) ;

        }
        
        for(int i=0 ; i<n ; i++){
        	cin>>c[i];
        }

        sort(l.rbegin() , l.rend());
        sort(c.begin() ,c.end());

        vector<ll>diff ;


        for(int i=0 ; i<n ; i++){

        	int pos = *(r.lower_bound(l[i]));

        	auto it =(r.lower_bound(l[i]));

        	r.erase(it);

        	//cout<<pos<<endl;

        	diff.pb(pos-l[i]);

        }


        sort(diff.rbegin() , diff.rend());

        ll ans = 0 ;


        for(int i=0 ; i<diff.size() ; i++){
        	ans+=(diff[i]*c[i]) ;
        }

        cout<<ans<<endl;


    }
    return 0 ;
}

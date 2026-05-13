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
        ll n ,x, y , m;

        cin>>n>>x>>y ;

        vector<ll>a ,fx ,fy ;

        map<ll , ll>mpx, mpy ;

        for(int i=0 ; i<n ; i++){
        	cin>>m ;

        	a.pb(m);
        	fx.pb(m%x);
        	fy.pb(m%y) ;
        	mpx[m%x]++;
        	mpy[(m%y)]++;
        }

        int ans=0 ;

        for(int i=0 ; i<n ; i++){
        	if(mpx[x-fx[i]]>0 && mpy[y-fy[i]]>0){

        		cout<<i<<" "<<fx[i]<<" "<<fy[i]<<endl;
        		ans++ ;
        	}
        }

        

        cout<<ans-mpx[0]-mpy[0]<<endl;
    }
    return 0 ;
}

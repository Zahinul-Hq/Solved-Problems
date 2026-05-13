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
        int n , k,x , mxx= 0, mnn= INT_MAX;

        cin>>n>>k ;

        vector<pair<int,int>>vp ;

        vector<int>mn(n+2,0),mx(n+2,0) ;

        for(int i=1; i<=n ; i++){
        	cin>>x ;
        	vp.pb({x,i});
        }
        sort(vp.begin(),vp.end()) ;


        for(int i= vp.size()-1 ; i>=0 ; i--){

        	mxx = max(mxx, vp[i].S);

        	mx[i] = mxx ;

        	mnn=min(mnn , vp[i].S) ;

        	mn[i]=mnn ;

        }

        map<int,int>mp ; 

        for(int i=0 ; i<vp.size(); i++){

        	int p = mx[i]-mn[i]+1;

        	int val = vp[i].first ;

        	mp[val]=max(mp[val] , p*2) ;

        }

        for(int i=1; i<=k ; i++){

        	cout<<mp[i]<<" ";

        }

        cout<<endl;


    }
    return 0 ;
}

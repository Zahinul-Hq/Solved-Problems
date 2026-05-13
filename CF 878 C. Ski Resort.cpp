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
        int n , k , q , cnt=0 ,x;

        cin>>n>>k>>q ;

        vector<int>vec ;
        for(int i=0 ; i<n ; i++){
        	cin>>x;

        	if(x>q){
        		vec.pb(cnt-k+1);
        		cnt=0 ;
        	}else
        		cnt++;

        }

        vec.pb(cnt-k+1) ;

        ll ans = 0 ; 


        if(vec.size()>=1){
        	for(int i=0 ; i<vec.size() ; i++){
        		//cout<<vec[i]<<" " ;
        		if(vec[i]>0){
	        		ll sum =(1ll*vec[i]*(vec[i]+1))/2ll ;
	        		ans+=sum;
        		}
        	}
   		}

   		cout<<ans<<endl;
    }

    return 0 ;
}

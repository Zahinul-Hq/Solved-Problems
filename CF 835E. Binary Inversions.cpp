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
ll cnt(vector<int>&a , int n){

	ll ans=0 ,z=0;
	for(int i=n ; i>=1; i--){
        	if(a[i]==0)
        		z++;
        	else{
        		ans+=z ;
        	}
        }

    return ans;
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

        vector<int>a(n+1, 0), pref(n+1,0) ;

        int pos0=-1, pos1=-1 , cnt1=0 ,cnt0=0 ,z=0;

        for(int i=1 ; i<=n ; i++){
        	cin>>a[i] ;
        }
        ll ans=cnt(a,n) ;
        for(int i=1 ; i<=n ; i++){
        	if(a[i]==0){
        		a[i]=1;
        		ans=max(ans , cnt(a , n));
        		a[i]=0;
        		break;
        	}
        }
        for(int i=n; i>=1 ; i--){
        	if(a[i]==1){
        		a[i]=0;
        		ans=max(ans , cnt(a , n));
        		a[i]=1;
        		break;
        	}
        }
        cout<<ans<<endl;

        


    }
    return 0 ;
}

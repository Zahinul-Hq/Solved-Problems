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
        int n, k ;

        cin>>n>>k ;

        vector<pair<ll,ll>>a;

        vector<ll>b(n,0) , c(n,0);

        for(int i = 0 ; i<n ; i++){
        	cin>>b[i];
        }
        for(int i = 0 ; i<n ; i++){
        	cin>>c[i];
        }
        /*ll lo=0 , hi=min(k-1,n-1), ans=b[0] + (c[0]*(k-1));

        while(hi>lo){
        	int mid = (hi+lo)/2;
        	ll sum=0 , mx=c[0] ;

        	for(int i=0 ; i<=mid ; i++ ){
        		sum+=b[i] ;
        		mx=max(c[i] , mx);

        	}

        	sum+=(mx*(k-mid-1));

        	cout<<sum<<" "<<mid<<endl;

        	if(ans<=sum){
        		hi=mid;
        		ans=sum ;
        	}else{
        		lo = mid ;
        	}
        }*/


        for(int i=0 ; i<(min(n,k)); i++){

            if(ap[i])
        }

        cout<<ans<<endl;

    }
    return 0 ;
}

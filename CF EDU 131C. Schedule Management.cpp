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
        int n , m,x ;

        cin>>n>>m ;

        vector<int>a(n+1,0) ;

        for(int i=0 ; i<m ; i++){
        	cin>>x ;
        	a[x]++ ;
        }


        int l = 1  , r = 4e5+5  ,ans=0;

        while(l<=r){

        	int mid = (l+r)/2 ;

        	ll time= 0 , worker=0 ;
        	for(int i=1 ; i<=n ; i++){

        		time+= max(0 , a[i]-mid) ;
        		worker+=max(0, mid-a[i])/2 ;

        	}

        	if(time<=worker){
        		ans=mid ;
        		r = mid-1 ;

        	}else{
        		l = mid+1; 
        	}
        }


        cout<<ans<<endl;
    }
    return 0 ;
}

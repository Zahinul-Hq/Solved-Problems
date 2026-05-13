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

        vector<ll>given ;
        vector<ll>arr ;

        for(int i=0 ; i<n-1 ;i++){
        	ll x ;
        	cin>>x ;
        	given.pb(x) ;
        }

        ll sum= 0 ;
        for(int i=1 ; i<=n ;i++){
        	sum+=i ;
        	arr.pb(sum) ;
        }

        if(arr[n-1]<given[n-2]){
        	cout<<"No"<<endl;
        	continue ;
       	}

       	int cnt=0 ;


       	for(int i=0 ; i<n ; i++){



       		int lo=0 , hi=n-2;

       		while(hi>=lo){

       			int mid = (hi+lo)/2 ;

       			if(given[mid]==arr[i]){
       				cnt++ ;
       				break;
       			}else if(given[mid]<arr[i]){

       				lo = mid+1 ;
       			}else{

       				hi = mid-1 ;
       			}
       		}


       	}

       	if(cnt==n-1)
       			cout<<"Yes"<<endl;
       		else
       			cout<<"No"<<endl;



    }
    return 0 ;
        
}

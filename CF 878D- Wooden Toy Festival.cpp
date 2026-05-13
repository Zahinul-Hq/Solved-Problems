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
const int d = 1e9+7 ;

bool check(ll mid, vector<ll>arr){

	int cur = -d;
	int used = 0;

	for(int i= 0 ; i<arr.size() ; i++){

		if(abs(arr[i]-cur)>mid){
			cur = arr[i]+mid ;
			used++ ;


		}
	}

	return used<=3 ;
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

    	vector<ll>arr(n,0) ;

        for(int i = 0 ; i <n  ; i++){

        	cin>>arr[i] ;

        	
        }

        sort(arr.begin() , arr.end()) ;

        ll hi=2e9  , lo = 0 ; 

        while(hi>lo){

        	ll mid = (hi+lo)/2 ;

        	if(check(mid, arr))
        		hi = mid ; 
        	else
        		lo = mid+1 ;
        }

        cout<<lo<<endl;
    }
    return 0 ;
}

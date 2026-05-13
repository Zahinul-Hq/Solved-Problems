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
        int n  ; 

        cin>>n ; 

        int arr[n] ;

        int mn = INT_MAX ;
        int mx = -1 ;

        for(int i =0 ; i<n ; i++){
        	cin>>arr[i] ;
        	mn = min(mn , arr[i]) ;
        	mx = max(mx , arr[i]) ;
        }

        int minind = min_element(arr, arr+n) - arr;

        if(mn==mx){
        	cout<<0<<endl;
        	continue ;
        }
        if(mn==1){
        	cout<<-1<<endl ;
        	continue ; 
        }

        vector<pair<int,int>>v ;

        bool ok = false ;

        for(int i=0 ; i<35 ; i++){
        	for(int j= 0 ; j<n ; j++){

        		if(mn<arr[j]){
        			arr[j] = ceil(arr[j]/(1.0*mn)) ;
        			v.pb({j+1 , minind+1}) ;

        		}else{

        			mn=arr[j] ;
        			minind = j ;
        		}
        	}

        }

        cout<<v.size()<<endl ;


        for(int i = 0 ; i<v.size() ; i++){

        	cout<<v[i].first<<" "<<v[i].second<<endl;
        }

    }
    return 0 ;
}

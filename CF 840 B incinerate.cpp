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

    	int n,k  ;

    	cin>>n>>k ;

    	vector<int>health(n) ;
    	//vector<int>power(n) ;

    	vector<pair<int,int>>hp ;

    	for(int i=0 ; i<n ; i++)
    		cin>>health[i] ;

    	for(int i= 0 ; i<n ; i++){
    		int x ;
    		cin>>x ;
    		hp.pb({x,health[i]}) ;
    	}

    	sort(hp.begin() , hp.end()) ;


    	int mx = *max_element(health.begin() , health.end()) ;

    	bool flag=0 ;
    	ll sum=0;

   		for(int i= 0 ; i<n ; i++){

   			if(health[i]>=sum){
   				sum= 0; 
	   			sum = ceil(health[i]*1.0/k) ;
	   			sum = sum*hp[i].first ;
	   			k=k-sum ;
   			}

   			if(k<0)
   				break;

   			if(sum>=mx){
   				flag=1;
   				break ;
   			}

   		}

   		if(flag)
   			cout<<"Yes"<<endl;
   		else
   			cout<<"No"<<endl;
        
    }
    return 0 ;
}

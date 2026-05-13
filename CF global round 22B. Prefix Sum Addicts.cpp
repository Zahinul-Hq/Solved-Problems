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

    	ll n , k;

    	cin>>n>>k ;

    	vector<ll>vec(k,0), diff(k-1,0) ;

    	for(int i=0 ; i<k ; i++){
    		cin>>vec[i] ;
    	}

    	if(k==1){
    		cout<<"Yes"<<endl;
    		continue;
    	}

    	

    	for(int i=0 ; i<k-1 ; i++){
    		
    		diff[i]=vec[i+1]-vec[i];
    	}
    	ll temp = (n-k+1)*diff[0];




    	if(is_sorted(diff.begin() ,diff.end()) && temp>=vec[0] ){
    		cout<<"Yes"<<endl;

    	}else
    		cout<<"No"<<endl;



        
    }
    return 0 ;
}

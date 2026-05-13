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

        vector<int>vec(n,0) ;

        for(int i=0 ; i<n ; i++){
        	cin>>vec[i] ;
        }

        vector<pair<int,int>>vp ;

        int flag=-1 ;

        for(int i=0 ; i<n ; i++){

        	if(vec[0]!=vec[i]){

        		flag=i ;
        		vp.pb({1 , i+1}) ;
        	}
        }

        if(flag==-1){

        	cout<<"No"<<endl;
        	continue ;

        }

        cout<<"Yes"<<endl;

        for(int i=1 ; i<n ; i++){

        	if(vec[0]==vec[i]){
        		vp.pb({flag+1 ,i+1}) ;
        	}
        }


        for(auto [x,y]:vp)
        	cout<<x<<" "<<y<<endl;




    }
    return 0 ;
        
}

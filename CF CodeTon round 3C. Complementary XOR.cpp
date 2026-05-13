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

       	string a,b ;

      	cin>>n>>a>>b ;

      	bool eq = 0 , neq=1;
      	bool flag = a[0]-'0';

	    vector<pair<int,int>>ans;

	    int i=1 , j=n ;
	    bool s = 1 ;

       	if(a==b){
       		eq=1 ;
       	}else{

       		for(int i=0 ; i<n ;i++){
       			neq&=(a[i]!=b[i]);
       		}
       	}
	    if(eq==0 && neq==0){
		    cout<<"No"<<endl;
		    continue;
	    }

	    a='*'+a;
	    b='*'+b;

	    for(int i= 1; i<=n ; i++){

	    	if(a[i]=='1')
	    		ans.pb({i,i}) ;
	    }

	    if(a[1]^b[1]^((ans.size())&1)){
	    	ans.pb({1,n}) ;
	    	ans.pb({1,1});
	    	ans.pb({2,n});
	    }


	    cout<<"Yes"<<endl;

	    cout<<ans.size()<<endl;

	    for(auto k : ans){
	    	cout<<k.F<<" "<<k.S<<endl;
	    }
       
    }
    return 0 ;
}

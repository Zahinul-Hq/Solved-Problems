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

        ll sum = 0 ,x=0 ;

        priority_queue<ll>given , need ;

        bool ok = 1 ;


        for(int i=0 ; i<n ; i++){
        	cin>>x ;
        	given.push(x);
        	sum+=x ;
        }
        need.push(sum) ;

        while(!given.empty()){

        	ll gt = given.top() ;
        	ll nt = need.top() ;

        	if(gt==nt){
        		given.pop();
        		need.pop();
        		continue ;
        		
        	}

	        	ll lf = (nt+1)/2 ;
	        	ll rt = nt/2 ;

        		need.pop();

        		if(lf>0)
        			need.push(lf);
        		if(rt>0)
        			need.push(rt);

        	if(gt>nt){
        		ok=0 ;
        		break;
        	}        	

        }

        if(!ok || !need.empty()){
        	cout<<"No"<<endl;
        }else{
        	cout<<"Yes"<<endl;
        }

    }
    return 0 ;
}

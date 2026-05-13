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

    ll n, x,sum=0 ;

    cin>>n ;

    x=n ;

    map<int,int>mp ;

    while(x>0){
    		int z= x%10 ;

    		mp[z%3]++ ;
    		sum+=z ;
    		x=x/10 ;
    }

    int res = sum%3 ;


    if(sum<3){
    	cout<<-1<<endl;
    }else if(res==0){
    	cout<<0<<endl;
    }
    else {

    	if(res==2 && mp[2]==0 && mp[1]>=2){
    		cout<<2<<endl;
    	}else if(res==1 && mp[1]==0){
    		cout<<-1<<endl;
    	}else if(res==2 && mp[1]<2 && mp[2]==0){
    		cout<<-1<<endl;
    	}else{
    		cout<<1<<endl;
    	}


    }



    

    	
    
    return 0 ;
}

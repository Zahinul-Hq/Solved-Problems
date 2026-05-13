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
map<int,ll>mp;
vector<ll>bin ; 
void binary(int n) 
{ 
    while (n > 0) {  
        bin.pb(n%2);
        n = n / 2; 
    }      
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
    	int typ , val ;
    	cin>>typ>>val ;

    	vector<int>v; 

    	if(typ==1){
    		mp[val]++ ;
    		v.pb(val);
    	}else{

    		bin.clear();
    		binary(val);

    		map<int,ll>temp=mp ;

    		vector<ll>vsb=bin;

    		bool f=0 ;
    		for(int i = bin.size()-1 ; i>=0  ; i--){

    			if(vsb[i]>=1){
    				if(temp[i]>=vsb[i]){
    					temp[i]-=vsb[i];
    				}else{

    					vsb[i]-=temp[i] ;

    					if(i>0){
    						vsb[i-1]=(2*vsb[i]+(vsb[i-1]==1));
    					}
    					else{

    						f=1;
    						break;
    					}
    				}

    			}

    		}

    		if(f)
    			cout<<"NO"<<endl;
    		else
    			cout<<"YES"<<endl;


    	}



    }
    return 0 ;
}

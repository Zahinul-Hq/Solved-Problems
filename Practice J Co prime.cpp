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

const int n = 1e6 +5 ;
map<int,int>mp ;

void seive(){
	vector<bool> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; i++) {
	    if (is_prime[i]) {
	    	mp[i]=1 ;
	        for (int j = i * i; j <= n; j += i)
	            is_prime[j] = false;
	    }
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


    seive() ;
    
    int arr[t] , stwise=0 ;

    for(int i=0 ; i<t ; i++){
    	cin>>arr[i];
    }
    for(int i=1 ; i<t ; i++){
    	stwise = __gcd(arr[i],arr[i-1]);	
    }


    int f = 0;

    for(auto it : mp){

    	f = 0;

    	for(int i=0 ; i<t ; i++){

    		if((arr[i]%it.F)==0){
    			f++ ;
    		}
    	}

    	if(f>=2)
    		break ;

    }

    if(f>=2){

    	if(stwise>1){
    		cout<<"not coprime"<<endl;
    	}else{
    		cout<<"setwise coprime"<<endl;
    	}
    }else{
    	cout<<"pairwise coprime"<<endl;
    }




    return 0 ;
}

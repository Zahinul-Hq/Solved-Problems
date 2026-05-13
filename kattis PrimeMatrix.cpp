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

int prime(int sum){

	vector<bool>is_prime(1300 , true) ;


	for(int i=2; i<1300 ; i++){
		if(is_prime[i]){

			if(i>=sum)
				return i;

			for(int j=i*i; j<1300; j+=i){
				is_prime[j]=false ;
			}
		}
	}
	return 0 ;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int n , k ;

    cin>>n>>k ;

    int sum = (n*(n+1))/2 ;

    int res = prime(sum) ;

    int ex = res-sum ;
    int rem = ex%n ;

    vector<int>val(n+1, 0);

    for(int i=0 ; i<n ; i++ ){
    	val[i]=i+1 ;
    	val[i]+= (ex/n) ;
    }

    for(int i = n- rem ; i<n ; i++){
    	val[i]++ ;
    }

    if(val[n-1]<=k){

    	for(int i=0 ; i<n ; i++){

    		for(int j=i ; j<n ; j++){
    			cout<<val[j]<<" ";
    		}
    		for(int j=0; j<i ; j++){
    			cout<<val[j]<<" ";
    		}

    		cout<<endl;

    	}
    }else{
    	cout<<"impossible"<<endl;
    }


    return 0 ;
}

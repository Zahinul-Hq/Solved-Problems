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
ll ds(int x){

	ll sum = 0 ;

	while(x){

		sum+=(x%10) ;
		x=x/10 ;
	}

	return sum ;
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

        if(n%2==0){
        	cout<<n/2<<" "<<n/2<<endl;
        	continue ;
        }

        int hi=n-1 , lo =0, ans=0  ;

        while(hi>=lo){

        	int mid = (hi+lo)/2 ;

        	if(abs(ds(mid)-ds(n-mid))<=1){
        		cout<<mid<<" "<<n-mid<<endl;
        		break ;
        	}else if (ds(mid)<ds(n-mid))
        		lo = mid+1;
        	else
        		hi= mid-1 ;
        }

        //cout<<ans<<" "<<n-ans<<endl;
    }
    return 0 ;
}

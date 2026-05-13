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
        ll n , p , l , tt ;

        ll ans=0 , rem=0 , day = 0 , task= 0  ;

        cin>>n>>p>>l>>tt ;

        long double on=1.0 ;

        task = ceil((on*n)/7.0);

        if(task%2==0){

        	task=task/2 ;

        	day= ceil((on*p)/((tt*2LL)+l)) ;

        	if(day>task){
        		rem = p-(task*((tt*2LL)+l));

        		ans = n - (task+ceil((on*rem)/l));
        		cout<<max(ans,0LL)<<endl;
        	}else{
        		cout<<max((n-day),0LL)<<endl;
        	}


        }else{

        	task=task/2 ;

        	day= ceil((on*p)/((tt*2LL)+l)) ;

        	

        	if(day>task){
        		rem = p-(task*((tt*2LL)+l));

        		if((rem<=(l+tt))){
        			cout<<max(0LL,(n-1-task))<<endl;
        		}else{

        			rem = rem-(l+tt) ;
        			ans = n - (task+ceil((on*rem)/l));
        			cout<<max(0LL,(ans+1))<<endl;
        		}
        	}else{
        		cout<<max(0LL,(n-day))<<endl;
        	}
        }
    }
    return 0 ;
}

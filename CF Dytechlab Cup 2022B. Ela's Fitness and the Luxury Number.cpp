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
ll bs_sqrt(ll x) {
  ll left = 0, right = 2000000125;
  while (right > left) {
      ll mid = (left + right) / 2;
      
      if (mid * mid > x) right = mid;
      else left = mid + 1;
  }
  return left - 1;
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
        ll l , r , ans=0;

        cin>>l>>r ; 


        ll sql = bs_sqrt(l) , sqr=bs_sqrt(r) ;

        if(sql==sqr){

        	for(int i=0 ; i<3 ; i++){

        		if (l <= sql * (sql + i) && sql * (sql + i) <= r) 
        			ans++;
        	}
        }else{

        	ans = (sqr-sql-1)*3 ;

        	for(int i=0 ; i<3 ; i++){

        		if (l <= sql * (sql + i) && sql * (sql + i) <= r) 
        			ans++;
        		if (l <= sqr * (sqr + i) && sqr * (sqr + i) <= r) 
        			ans++;
        	}


        }

        cout<<ans<<endl;
    }
    return 0 ;
}

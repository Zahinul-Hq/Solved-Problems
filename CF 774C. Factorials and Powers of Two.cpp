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
const ll N = (ll)1e12+10 ;
vector<ll>ex,val ;

int subsetsum( ll n){


	int ans = __builtin_popcountll(n);
	for (int mask = 0; mask < (1 << (int)val.size()); mask++) {
		int res = 0;
		ll cur = n;
		for (int i = 0; i < (int)val.size(); i++) {
			if (((mask >> i) & 1) == 0) continue;
			res++;
			cur -= val[i];
		}
		if (cur < 0) continue;
		res += __builtin_popcountll(cur);
		ans = min(ans, res);
	}
	return ans;


}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;
    ll t , i=0  ;
    cin>>t ;

    ll sm = 1 ;

    for(i=2 ;; i++){

    	sm*=i ;

    	if(sm>N)
    		break;

    	if(sm!=2)
    		val.pb(sm) ;

    }
    //sort(va.begin() , val.end()) ;


    while (t--)
    {

        ll n , sum;

        cin>>n ;

        cout<<subsetsum(n)<<endl;




    }
    return 0 ;
}

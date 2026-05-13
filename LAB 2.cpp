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
const int n=1e7;
vector<bool> is_prime(n+1, true);
vector<ll>ans;

void sieve(){

    is_prime[0] = is_prime[1] = 0;

    for (ll i = 3; i*i<= n; i+=2) {
        if (is_prime[i]) {
            for (ll j = i*i; j <= n; j += 2*i){
                is_prime[j]=false ;
                

            }
        }
    }

    ans.pb(2);

    for(int i=3; i<=n; i+=2){

        if(is_prime[i]){

            //cout<<i<<endl;
            ans.pb(i) ;
        }
    }
    
}

/*bool chk(int val){

    int cnt=0 ;


    for(int i=0 ; ans[i]<=val && i<ans.size() ; i++){

        if(val%ans[i]==0){
            cnt++ ;
            val=val/ans[i] ;

            if(cnt>=3)
                return true;
        }
    }

    return false;
}*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL) ;
    inout() ;

    sieve();


    /*for(int i=30 ; aa.size()<=1000 ; i++){

        if(mp[i]>=3)
            aa.pb(i);
    }*/

    //cout<<aa[0]<<aa[1]<<endl;

   // cout<<ans[0]<<endl;


    int t ;

    cin>>t ;

    //cout<<ans.size()<<endl;

    while(t--){
        ll x ;

        cin>>x ;

        for(int i=0 ; ans[i]*ans[i]<x ; i++){
            
        }
    }

    return 0 ;

}

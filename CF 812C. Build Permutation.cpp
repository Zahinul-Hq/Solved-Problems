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
    //inout() ;

    int t ;
    cin>>t ;

    vector<ll>vec(1003 , 0)  ;

    for(ll i=0 ; i<=1000 ;i++){
        vec[i]=(i*i) ;
    }

    while (t--)
    {
        int n ,pos=0 ;

        cin>>n ;

        if(n==3){
            cout<<1<<" "<<0<<" "<<2<<endl;
            continue;
        }
        if(n==2){
            cout<<1<<" "<<0<<endl;
            continue;
        }
        if(n==1){
            cout<<0<<endl;
            continue;
        }

        while(vec[pos]<(2*(n-1)))
            pos++ ;

        pos--;

        //cout<<pos<<endl;

       // cout<<vec[pos]<<endl;

        int val = n-1 ;

        vector<int>ans ;

        bool flag=1 ;


       for(int i=n-1;i>=0; i--){

            ans.pb(vec[pos]-i);

            //cout<<vec[pos]<<" "<<i<<" "<<val<<endl;

            if(vec[pos]-i==val && i>0){
                pos = sqrt(2.0*(i-1));
                val=i-1 ;
            }

        }

        for(int i=n-1 ; i>=0 ;i--){
            cout<<ans[i]<<" ";
        }
        cout<<endl;




    }
    return 0 ;
}

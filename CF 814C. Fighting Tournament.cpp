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
        int n ,x,q;

        cin>>n>>q ;

        deque<pair<int,int>>dp ;
        pair<int,int>mx ;

        vector<int>a ;

        for(int i=1; i<=n ; i++){
        	cin>>x;
        	dp.push_back({x,i}) ;

            if(x==n)
                mx={x,i};
        }
        auto f = dp.front() ;
        
        while(1){

            dp.pop_front();
            auto s = dp.front() ;

            if((f.F==mx.F) ||(s.F==mx.F))
                break;

            if(f.F>s.F){
                a.pb(f.S);
            }else{
                a.pb(s.S);
                f=s;
            }
        }

        int id ,round ;

        while(q--){

            cin>>id>>round ;

            int sz = a.size();

            if(id==mx.S){
                cout<<max(0 , (round-sz))<<endl;
                continue;
            }

            round = min(round ,sz);


            int ps = upper_bound(a.begin(), a.begin()+round , id) - lower_bound(a.begin(), a.begin()+round , id);

            cout<<ps<<endl;


            



        }


    }
    return 0 ;
}

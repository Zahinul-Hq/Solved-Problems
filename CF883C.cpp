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
        long double n , base , h;

        cin>>n>>base>>h;



        vector<long double>heights(n,0);
        vector<long double>less ;

        

        for(int i=0 ; i<n ; i++){
        	cin>>heights[i] ;
        }

        sort(heights.begin() ,heights.end()) ;

        long double eq = 0 , l=0 ;

        for(int i=0 ; i<n-1 ; i++){

        	if(heights[i]==heights[i+1])
        		eq++ ;
        	int x = heights[i+1]-heights[i];

        	if(x<h){
        		l++ ;
        		less.pb(x);
        	}

        }

         long double ans = base*0.500000*(n-eq-l)*h ;

         long double ans2=0.0;


        for(int i =0 ;i<less.size() ;i++){

        	ans2+= ((base+(less[i]*2.0))/2.0)*h ;

        }

        ans=ans+ans2;

        cout<<fixed<<ans<<setprecision(6)<<endl;



    }
    return 0 ;
}

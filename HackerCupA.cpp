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

    int t , i=0 ;
    cin>>t ;
    
    while (t!=i++)
    {
        int n;

        cin>>n ;

        map<long double, int>mp ;
        vector<long double>a ;

        for(int i=0 ; i<n ; i++){

        	long double x ;
        	cin>>x ;
        	mp[x]++ ;
        }

        for(auto i : mp){
        	a.pb(i.F) ;
        }


        long double x =  (a[a.size()-1]+a[a.size()-2])/2.0 - ((a[0]+a[1])/2.0) ;

        if(a.size()==1)
        	cout<<"Case #"<<i<<": "<<setprecision(6)<<0<<endl;
        else if(a.size()==2)
        	cout<<"Case #"<<i<<": "<<setprecision(6)<<a[1]-a[0]<<endl;
        else if(a.size()==3){

        	if(a[1]-a[0]>a[2]-a[1])
        		cout<<"Case #"<<i<<": "<<fixed<<setprecision(6)<<(a[2]+a[1])/2.0 - a[0]<<endl;
        	else
        		cout<<"Case #"<<i<<": "<<fixed<<setprecision(6)<<a[2] - (a[0]+a[1])/2.0<<endl;
        }else{

        	long double x =  (a[a.size()-1]+a[a.size()-2])/2.0 - ((a[0]+a[1])/2.0) ;

        	cout<<"Case #"<<i<<": "<<fixed<<setprecision(6)<<a[2] - (a[0]+a[1])/2.0<<endl;



        }


        	
    }
    return 0 ;
}

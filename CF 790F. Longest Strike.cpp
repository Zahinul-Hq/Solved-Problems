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
        int n ,x,k; 

        cin>>n>>k ;

        map<int,int>mp ;

        for(int i=0 ; i<n ; i++){
        	cin>>x ;
        	mp[x]++ ;
        }

        vector<int>a ;

       
        bool f=1,flag=0;

        for(auto i : mp)
        	if(i.S>=k)
        		a.pb(i.F) ;


        if(a.empty()){
        	cout<<-1<<endl;
        	continue ;
        }

        int l=a[0], r=0, diff=-1 , el=a[0],  al=0 , ar=0;


        for(int i=0 ; i<a.size() ;i++){


        	if(a[i]==el){

        		r=a[i] ;

        	}else{

        		if(diff<=(r-l)){
        			al=l , ar=r ;

        			diff=r-l ;
        		}

        		l=a[i] ;
        		r=a[i] ;
        		el =a[i];

        		
        	}
        	
        	el++ ;
        }

        if(diff<=(r-l)){
        	al=l , ar=r ;
        }

        cout<<al<<" "<<ar<<endl;
    }
    return 0 ;
}

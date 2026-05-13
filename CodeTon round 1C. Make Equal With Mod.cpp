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
	    int n , flag=0;

	    cin>>n ;

	    vector<int>a(n,0) ;

       	for(int i=0 ; i<n ; i++){

       		cin>>a[i] ;
       		if(a[i]==1)
       			flag=1 ;
       	} 

	    if(!flag){

	    	cout<<"Yes"<<endl;
	    	continue ;
	    }

	    sort(a.begin() , a.end()) ;

	    for(int i=1 ; i<n ; i++){

	    	if(a[i]-a[i-1]==1){
	    		flag=2;
	    		break ;
	    	}

	    }

	    if(flag==2)
	    	cout<<"No"<<endl;
	    else
	    	cout<<"Yes"<<endl;



    }
    return 0 ;
}

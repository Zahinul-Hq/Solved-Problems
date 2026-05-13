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

    	int n ;
    	cin>>n ;

    	int arr[n] ;

    	for(int i=0 ; i<n ; i++)
    		cin>>arr[i] ;

    	int mx = *max_element(arr, arr+n) ;
    	int mn = *min_element(arr, arr+n) ;

    	int l=0 , r=n-1  ; 

    	while(1){

    		bool flag = 0 ;



	    	while(arr[l]==mx || arr[l]==mn){

	    		if(arr[l]==mx)
	    			mx-- ;
	    		if(arr[l]==mn)
	    			mn++ ;
	    		l++ ;

	    		flag=1 ;

	    	}

	    	while(arr[r]==mx || arr[r]==mn){

	    		if(arr[r]==mx)
	    			mx-- ;
	    		if(arr[r]==mn)
	    			mn++ ;
	    		r-- ;
	    		flag=1 ;
	    	}

	    	if(flag==0 || l>=r)
	    		break ;
	    }

    	if(l<r)
    		cout<<++l<<" "<<++r<<endl;
    	else
    		cout<<-1<<endl;


        
    }
    return 0 ;
}

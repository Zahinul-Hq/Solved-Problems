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

        for(int i=0 ; i<n ; i++){
        	cin>>arr[i]; 
        }


        bool flag= 0 ; 
        for(int i=0 ; i<=n ; i++){
        	int tru= 0 ;



        	for(int j=0 ; j<n ; j++){

        		if(i>=arr[j])
        			tru++ ;
        	}

        	int fal = n- tru ;
        	
        	if(fal==i){
        		flag= 1 ;
        		cout<<fal<<endl;
        		break ;
        	}
        }

        if(!flag)
        	cout<<-1<<endl; 
    }
    return 0 ;
}

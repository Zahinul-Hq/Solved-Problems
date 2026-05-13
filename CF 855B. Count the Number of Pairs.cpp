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
        int n  , k ;
        string s ;

        cin>>n>>k>>s ;


        vector<int>freq(130 ,0 ) ;

        //vector<int>sum ;

        for(int i=0 ; i<n ; i++){
        	freq[s[i]]++; 
        }

        int sum = 0 , pair=0;
        for(char ch = 'a' ; ch<='z' ;ch++){

        	pair+=min(freq[ch] , freq[ch-32]) ;

        	int x = abs(freq[ch]-freq[ch-32]); 

        	sum+= (x/2) ;
        	
        }

        pair+=min(k, sum) ;

        cout<<pair<<endl;




    }
    return 0 ;
}

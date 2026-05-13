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

    	int n , k ;

    	cin>>n>>k ;

        string s  , ans;

        cin>>s ;

       	vector<int>freq(130 ,0);
        for(int i=0 ; i<s.size(); i++){
        	freq[s[i]]++ ;

        }


        int j ;
        for(int i=1; i<=k ; i++)
        	
	        for(char ch='a' ,j=1 ; ch<='z'  ; ch++ , j++){
	        	if(!freq[ch]){
	        		ans+=ch ;
	        		break ;
	        	}

	        	if(j==(n/k+1)){
	        		ans+=ch;
	        		break;
	        	}
	        	freq[ch]-- ;

	        }

	    cout<<ans<<endl;



    }
    return 0 ;
}

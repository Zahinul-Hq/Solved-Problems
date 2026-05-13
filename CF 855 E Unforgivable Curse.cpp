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
        string s , t ;
        int n , k ;

        cin>>n>>k ;

        cin>>s>>t ;

        if(s==t){
        	cout<<"Yes"<<endl;
        	continue ;
        }

        vector<int>v(140) ;

        for(int i=0 ; i<n ;i++){

        	v[s[i]]++ ;

        	v[t[i]]-- ;

        }
        bool flag=0 ;
        for(int i=0 ; i<140 ;i++){

        	if(v[i]!=0)
        		flag=1 ;

        }

        

        for(int i=0 ; i<n ; i++){

        	if(s[i]!=t[i]&&max(i , n-i-1)<k){
        		flag=1 ;
        		break;
        	}
        }

        if(flag)
        	cout<<"No"<<endl;
        else
        	cout<<"Yes"<<endl;


    }
    return 0 ;
}

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
        string s1, s2 ;

        cin>>s1>>s2 ;

        int n= s1.size() ;

        if(s1==s2){
        	cout<<"YES"<<endl;
        	continue ;
        }

        if(s1[0]!=s2[0] || (s1[n-1]!=s2[n-1])){
        	cout<<"NO"<<endl;
        	continue ;
        }

        bool flag=0;

        int x=10 ;

        while(x--){
        	int j=1 ;

	        for(int i=1 ; i<n-1 ; i++){

	        	if(s1[i]!=s2[i]){
	        		flag=1 ;
	        		j=i+1;
	        		while(flag && j!=n){

	        			if(s1[i-1]==s1[j] && s1[j]==s2[j]){
	        				flag=0 ;
	        				break;
	        			}

	        			if(s2[i-1]==s2[j] && s1[j]==s2[j]){
	        				flag=0 ;
	        				break;
	        			}

	        			j++ ;


	        		}

	        		i=j ;
	        	}

	        }
        }

        if(!flag)
        	cout<<"YES"<<endl;
        else
        	cout<<"NO"<<endl;
    }
    return 0 ;
}

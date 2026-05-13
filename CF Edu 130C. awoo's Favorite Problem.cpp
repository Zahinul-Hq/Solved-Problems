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


        string s , s1 ;
        cin>>n>>s>>s1 ; 

        if(count(s.begin(), s.end() ,'b')!=count(s1.begin() ,s1.end(),'b')){
        	cout<<"No"<<endl;
        	continue;
        }

        int j=0 ;

        bool flag=0 ;

        for(int i=0 ; i<n ; i++){

        	if(s[i]=='b')
        		continue ;

        	while(s1[j]=='b'){
        			j++ ;
        		
        	}

        	if(s[i]!=s1[j] ||(s[i]=='a' && i>j ) || (s[i]=='c' && i<j))
        			flag=1;
        	j++;
        }

        if(flag)
        	cout<<"No"<<endl;
        else
        	cout<<"Yes"<<endl;


    }
    return 0 ;
}

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
        string s ,s1="()" ;

        cin>>s ;

        if(s==s1){
        	cout<<"No"<<endl;
        	continue ;
        }

        bool flag=0 ;

        for(int i=0 ; i<s.size()-1 ; i++){

        	if(s[i]=='(' && s[i+1]=='(')
        		flag=1 ;
        	if(s[i]==')' && s[i+1]==')')
        		flag=1;

        }

        cout<<"Yes"<<endl;

        if(flag){


        	for(int i=0 ; i<s.size() ; i++)
        		cout<<"()" ;
        }else{
f
        	for(int i=0 ; i<s.size() ;i++)
        		cout<<"(" ;
        	for(int i=0 ; i<s.size() ;i++)
        		cout<<")" ;
        }

        cout<<endl;
    }
    return 0 ;
}

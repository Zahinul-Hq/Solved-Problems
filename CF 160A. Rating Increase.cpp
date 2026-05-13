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
       string s , tm="" , ts="";

       cin>>s ;

       tm+=s[0] ;



       for(int i=1 ; i<s.size() ; i++){

       		if(s[i]!='0'){
       			for(int j=i ; j<s.size() ; j++){
       				ts+=s[j];
       			}
       			break;
       		}
       		tm+=s[i];

       }

       if(ts==""){
       	ts="-1" ;
       }

       int l = stoi(tm) , r = stoi(ts); 

       if(l>=r)
       		cout<<-1<<endl;
       else
       		cout<<tm<<" "<<ts<<endl;
    }
    return 0 ;
}

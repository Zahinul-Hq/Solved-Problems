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

        string s1 ,s2;

        cin>>n>>s1>>s2 ;

        int fr=0 ,rev=0 ;

        for(int i=0 ;i<n ; i++){
        	if(s1[i]!=s2[i])
        		fr++ ;
        	if(s1[i]!=s2[n-i-1])
        		rev++;
        }

        int mn = min(rev , fr) ;

        if(s1==s2){
        	cout<<0<<endl;
        	continue ;
        }

        if(rev<fr){

        	if(!rev)
        		rev++ ;

        	if(rev%2==0 )
        		cout<<2*rev-1<<endl;
        	else
        		cout<<2*rev<<endl;

        }else if(fr<rev){

        	if(fr%2==0)
        		cout<<fr*2<<endl;
        	else
        		cout<<2*fr-1<<endl;
        }else
        	cout<<2*mn-1<<endl;




        


    }
    return 0 ;
        
}

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
map<char,char>mp , mp1 ;

bool chck(char ch1 , char ch2){
    char ch ;

    while(mp[ch1]!=ch){
        ch1=mp[ch1];
        if(ch1==ch2)
            return false ;
    }

    return true ;
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
        string s , str="abcdefghijklmnopqrstuvwxyz" ,ans="";

        cin>>n>>s;

        for(int i=0 ; i<n ; i++){
            char ch = s[i] ;

            if(mp[ch]!=0){
                ans+=mp[ch];
                continue ;
            }

            bool flag=1 ;

            for(char c = 'a' ; c<='z' ;c++){



                if(c!=ch && mp1[c]==0 && chck(c ,ch)){
                    mp1[c]= ch ;
                    mp[ch] = c ;
                    ans+=c ;
                    flag=0;
                    break;
                }
            }

            if(flag){

                for(char c='a' ;c<='z' ;c++){

                    if(mp1[c]==0){
                        mp[ch]=c ;
                        ans+=c;
                        break;
                    }
                }
            }
        }

        cout<<ans<<endl;

        mp1.clear();
        mp.clear() ;

    }
    return 0 ;
}

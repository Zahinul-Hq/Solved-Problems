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


int main ()
{

    int t ;

    cin>>t ;

    while(t--)
    {
        string s1 ,s2 ;

        cin>>s1>>s2 ;

        int a=0 , stl1 , stl2;


        for(int i=0 ; i<s2.size() ;i++)
        {
            if(s2[i]=='a')
                a++ ;
        }

        stl1= s1.size() ;
        stl2 = s2.size() ;

        int ans=0 ;

        if(a==1)
        {
            if(a==stl2)
                ans= 1  ;

            else if(a<stl2)
                ans = -1 ;

        }
        else if(a==0)
            {
                ans = 2*stl1 ;
            }

        else
            ans=-1 ;

        cout<<ans<<endl ;


    }

    return 0 ;
}


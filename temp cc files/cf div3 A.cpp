#include<bits/stdc++.h>

using namespace std ;

int main ()
{
    int t ;

    cin>>t ;

    while (t--)
    {
        int n ,i ;
        cin>>n ;

        int a[n] ;

        for(i=0 ; i<n ;i++)
            cin>>a[i] ;

        string s ;

        cin>>s ;

        int c ,d ;
        vector<int> x ;

        for(i=0 ; i<n ; i++)
        {
            c=0 ;
            for(int l=i ;l<n ;l++)
            {
                if(a[i]==a[l] && a[i]!=0)
                {
                    c++ ;
                    a[l]== 0 ;
                }
            }

            x.push_back(c) ;
        }

        vector<int>y ;

         for(i=0 ; i<n ; i++)
        {
            c=0 ;
            for(int l=i ;l<n ;l++)
            {
                if(s[i]==s[l] && s[i]!=0)
                {
                    c++ ;
                    s[l]== 0 ;
                }
            }

            y.push_back(c) ;
        }

        sort(x.begin() ,x.end()) ;
        sort(y.begin() ,y.end()) ;

        if(x[x.size()-1]>=y[y.size()-1] &&x.size()>=y.size())
            cout<<"Yes"<<endl ;
        else
            cout<<"No"<<endl ;

    }
}

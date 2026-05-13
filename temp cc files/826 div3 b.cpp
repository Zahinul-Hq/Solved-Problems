#include<bits/stdc++.h>
using namespace std ;

int main ()
{
    int t ;

    cin>>t ;

    while(t--)
    {
        int x ;

        cin>>x ;

        if(x%2==0 )
        {
            for(int i=x ; i>0 ;i--)
                cout<<i<<" " ;
            cout<<endl ;
        }
        else if(x%2!=0 && x!=3)
        {
            int y = x/2 + 1;



            for(int i=x ; i>y ;i--)
                cout<<i<<" " ;
            for(int i=1 ; i<=y ;i++)
                cout<<i<<" " ;

            cout<<endl ;
        }
        else
            cout<<"-1"<<endl ;
    }

    return  0 ;
}

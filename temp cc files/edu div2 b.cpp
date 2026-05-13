#include<bits/stdc++.h>
using namespace std ;

int main ()
{
    int t ;

    cin>>t ;

    while(t--)
    {
        int n ;

        cin>>n ;

        int a[n] ;

        int p=0 , q=n-1 ;

        for(int i=1 ; i<=n ;i++)
        {
            if(p>q)
                break ;

            if(i%2==0)
            {
                a[p]=i ;
                p++ ;
            }
            else
            {
                a[q]=i ;
                q-- ;
            }
        }

        for(int i=0 ;i<n ;i++)
            cout<<a[i]<<" " ;

        cout<<endl ;

    }

    return 0 ;
}

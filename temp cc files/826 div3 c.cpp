#include<bits/stdc++>
using namespace std ;
int main ()
{
    int t ;
    cin>>t ;

    while(t--)
    {
        int x ;
        cin>> x ;

        int a[x] ;

        for(int i=0 ; i<x ;i++)
            cin>>a[i] ;



        int i , j  , mx ;

        vector<int>b ;

        mx= *max_element(a , a+x) ;

        for(i=0 ;i<n ;i++)
        {
            for(j=0 ; j<n ;j++)
            {
                int sum = sum+a[j] ;
                if(sum==mx)
                    b.push_back(j+1) ;
                else if(sum>mx)
                    break ;

            }
        }


    }
}

#include<iostream>
#include<algorithm>
using namespace std ;
int main ()
{
        int a , b=0, c=0 , d , t  ,l;
        int x[21] , j ;

        cin>>t ;

        for(int i =0 ; i<t;i++)
        {
                c=0 ;
                cin>>a ;

                for(l=0 ; l<a;l++)
                {
                        cin>>x[l];
                }

                for(l=0;l<a;l++)
                {
                        if(x[c]<=x[l])
                        {
                                c=l ;
                        }
                }
                cout<<c+1<<endl ;
        }

        return 0 ;
}

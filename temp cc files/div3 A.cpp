#include<iostream>

using namespace std ;
int main ()
{
        long long int a , b, c, t , x=0, y , i;


        cin>> t ;

        for(i=1 ; i<=t ; i++)
        {
                cin>>a>>b>>c ;


                if(b<c &&b>1)
                        x=((c-b)*2) +(b-1) ;
                else if(b<c &&b==1)
                        x=((c-b)*2 ) ;
                else if(c<b)
                        x=b-1 ;

                if(a-1<x)
                        cout<<"1"<<endl ;
                else if(a-1>x)
                        cout<<"2"<<endl ;
                else if(a-1==x)
                        cout<<"3"<<endl ;

                x=0 ;

        }

        return 0 ;
}

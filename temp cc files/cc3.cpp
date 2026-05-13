#include<iostream>
using namespace std ;
int main ()
{
        int a , b, c , i , j , k , l ;
        cin>>l ;

        for(i=1;i<=l;i++)
        {
                cin>>a>>b;
                if(a>b)
                {
                        if((a/b)>b)
                                cout<<"YES"<<endl ;
                        else
                                cout<<"NO"<<endl ;
                }
                else if(a==1&&b==1)
                        cout<<"YES"<<endl ;

                else
                        cout<<"NO"<<endl ;

        }

        return 0 ;
}

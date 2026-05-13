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

	int n ;

	cin>>n ;

	vector<int>arr(n,0);

	vector<pair<int,int>>b ;


	int flag=0;


	vector<int>zero , s ;


	for(int i=0 ;i<n ; i++){
		cin>>arr[i];


		if(arr[i]>0)
			flag=1;

		if(arr[i]%10==0){
			zero.pb(arr[i]);

			}else{

				if(arr[i]>=0 && arr[i]<=9){
					s.pb(arr[i]) ;
				}else
					b.pb({arr[i]/10 , arr[i]%10}) ;
			}

		}
	

	if(!flag){
		cout<<0<<endl;
		return 0 ;
	}

	sort(zero.begin() ,zero.end());


	for(int i=1 ; i<zero.size() ;i++){

		if(zero[i]>0){
			b.pb({zero[i]/10 , 0}) ;

		}else{
			s.pb(0);
		}
	}


	sort(s.rbegin(), s.rend());
	sort(b.rbegin() , b.rend()) ;


	int i=0 , j =0 ;


	while(1){






		if(b.size()==0 ||i<s.size()&&s[i]>b[j].F ){
			cout<<s[i];
			i++ ;
		}else if(i<s.size()&&(s[i]==b[j].F && s[i]>=b[j].S)){
			cout<<s[i];
			i++ ;

		}
		else{
			cout<<b[j].F<<b[j].S;
			j++;
		}

		if(i>=s.size() && j>=b.size())
			break;
	}

	if(zero.size()!=0)
		cout<<zero[0]<<endl;





    return 0 ;
}

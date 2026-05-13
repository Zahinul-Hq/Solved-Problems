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
const int N = 1000 ;

map<int,int>d ;
vector<int>a(N+1,0);

bool cmp(int a , int b){

	if(d[a] != d[b]){
		return d[a] < d[b] ;
	}else{
		return a > b ;
	}
}
void sieve(){

	for(int i = 1; i <= N; i++){
		for(int j = i; j<=N ; j+=i){
			d[j]++ ;
		}
	}
}

void sort(){

	for(int i = 1; i <= N; i++){
		a[i] = i;
	}
	sort(a.begin(), a.end(), cmp) ;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

	sieve() ;
	sort() ;

    int t , c = 1 ;
    cin>>t ;
    
    while (t--)
    {

    	int x;

    	cin >> x;

        cout <<"Case "<< c++ << ": " << a[x] << endl;
    }
    return 0 ;
}

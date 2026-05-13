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

    int t ;
    cin>>t ;
    
    while (t--)
    {
        int n, flag = 0;

        cin >> n;

        vector<int> arr(n + 1, 0), diff;

        for(int i = 1; i <= n; i++){
        	cin >> arr[i];

        	if(arr[i] != arr[1])
        		flag  = 1;
        }

        if(!flag){
        	cout << -1 << endl;
        	continue;
        }
        //diff.pb(0);

        int dis_st = INT_MAX, dis_end = INT_MAX, dis = INT_MAX;

        for(int i = 1; i <= n; i++){
        	if(arr[1] != arr[i])
        		dis = min(dis,(i - 1));
        	

        }



        for(int  i = n; i >= 1; i-- ){
        	if(arr[1] != arr[i])
        		dis = min(dis,(n - i));
        	

        }


        for(int i = 1; i <= n; i++){
        	if(arr[1] != arr[i])
        		diff.pb(i);
        }
        //diff.pb(n);

        if(diff.size() > 1){

        	for(int i = diff.size() - 1; i > 0 ; i--){
        		dis = min(dis, (diff[i] - diff[i - 1]) - 1);

        	}
        }

        cout << dis << endl;

        
    }
    return 0 ;
}

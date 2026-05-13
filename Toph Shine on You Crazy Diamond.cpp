#include<bits/stdc++.h>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

 
void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}
const int N = 1e6 + 7;
vector<int> mark(N,0);
vector<int>arr(N, 0);

vector<pair<int,int>>ans;
int n ,x;
void seive(){

	for(int i = 2; i <= N; i++){
		if(mark[i] != 0 ){

			int cnt = 0;
			for(int j = i; j <= N; j += i){

				cnt += mark[j];
				mark[j] = 0;
			}


			ans.push_back({cnt, i});
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;


    cin >> n ;

   
    for(int i = 1; i <= n; i++){
    	cin >> arr[i];
    	mark[arr[i]]++;
    }

    seive();

    if(ans.size() == 0){
    	cout << n << endl;

    	cout << 2 << " " << 4 << endl;

    	return 0;
    }
    if(ans.size() == 1){
    	
    	cout << n - ans[0].F << endl;

    	cout << ans[0].S << " " << 4 << endl;

    	return 0;
    }

    sort(ans.rbegin(), ans.rend());


    ll answer = ans[0].F + ans[1].F;

    cout << n - answer << endl;

    cout << ans[0].S << " " << ans[1].S << endl;





    return 0 ;
}

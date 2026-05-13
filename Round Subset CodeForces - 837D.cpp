#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
//typedef __int128 lll;
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
const int N = 205;
vector<int> T, F, arr(N , 0);
ll n, k;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

	cin >> n >> k;

	for(int i = 0; i < n; i++){
		cin >> arr[i];

		int t = 0, f = 0;

		while(arr[i] % 2 == 0){
			t++;
			arr[i] /= 2;
		}
		T.push_back(t);
		while(arr[i] % 5 == 0){
			f++;
			arr[i] /= 5;
		}
		F.push_back(f);
	}
	
    return 0 ;
}

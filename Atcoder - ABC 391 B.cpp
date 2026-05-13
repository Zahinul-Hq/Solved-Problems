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

 
#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
const auto start_time = std::chrono::high_resolution_clock::now();
void runtime()
{
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,milli> diff = end_time-start_time;
    cerr<<"Time: "<<roundl(diff.count())<<"ms\n";
}
const int N = 55;
int n, m;
string grid1[N], grid2[N];

bool check(int i , int j){

	if(i + m - 1 >= n || j + m - 1  >= n)
		return false;

	debug(i, j );

	

	for(int k = 0; k < m; k++){
		int t = j;
		for(int l = 0; l < m; l++){
			if(grid1[i][t++] != grid2[k][l]){
				return false;

			}
			debug(i, j, k, l );
			//j++;
		}
		i++;
	}
	return true;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

	cin >> n >> m;


	for(int i = 0; i < n; i++){
		cin >> grid1[i];
	}
	for(int i = 0; i < m; i++){
		cin >> grid2[i];
	}

	for(int a = 0; a < n; a++){
		for(int b = 0; b < n; b++){
			if(check(a, b)){
				cout << a + 1 << " " << b + 1 << endl;
				return 0;
			}
			

		}
	}

    return 0 ;

    runtime();

}

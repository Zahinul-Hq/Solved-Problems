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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int t;
    cin >> t;

    while(t--){

        int n, x;

        cin >> n >> x;

        vector<ll>arr(n + 1);

        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }

        vector<vector<int>>pref(33, vector<int>(n + 1, 0));

        for(ll j = 32; j >= 0; j--){
        	for(int i = 1; i <= n; i++){
                if(arr[i] & (1LL << j))
                	pref[j][i] = pref[j][i - 1] + 1;
                else
                	pref[j][i] = pref[j][i - 1];
            }
        }
        for(int i = 1; i < n; i++){
            for(ll j = 32; j >= 0; j--){
                if(arr[i] & (1LL << j)  && x){
                    int pos = upper_bound(pref[j].begin(), pref[j].end(), pref[j][i]) - pref[j].begin();

                    if(pos > n){
                        pos = n;
                    }

                    debug(i, j, pos);

                    arr[i] ^= (1LL << j);
                    arr[pos] ^= (1LL << j);
                    x--;
                }
            }
        }


        if(n == 2 && x % 2 == 1){
        	arr[n - 1] ^= 1;
        	arr[n ] ^= 1;
        }



        for(int i = 1; i <= n; i++){
        	if(i != n)
            	cout << arr[i] << " ";
            else
            	cout << arr[i] << endl;
        }
        

    }

    return 0 ;

    runtime();

}

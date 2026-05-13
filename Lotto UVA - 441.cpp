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


    int n, cnt = 0;
    
    while (cin >> n && n)
    {
    	cnt++;
    	if(cnt > 1){
    		cout << endl;
    	}

    	vector<int>arr(n);
    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    	}
    	vector<vector<int>>ans;
    	for(int i = 0; i < n - 5; i++){
    		vector<int>temp(n, arr[i]);
    		for(int j = i + 1; j < n - 4; j++){
    			temp[1] = arr[j];
    			for(int k = j + 1; k < n - 3; k++){
    				temp[2] = arr[k];
    				for(int l = k + 1; l < n - 2; l++){
    					temp[3] = arr[l];
    					for(int m = l + 1; m < n - 1; m++){
    						temp[4] = arr[m];
    						for(int p = m + 1; p < n; p++){
    							temp[5] = arr[p];

    							ans.push_back(temp);
    							
    						}
    					}
    				}
    			}
    		}
    	}

    	for(int i = 0; i < ans.size(); i++){
    		for(int j = 0; j < 6; j++){
    			cout << ans[i][j];
    			if(j != 5){
    				cout << " ";
    			}
    		}
    		cout << endl;
    	}
    }
    return 0 ;

    runtime();

}

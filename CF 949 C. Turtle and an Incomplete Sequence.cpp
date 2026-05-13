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

bool check(vector<int>&arr){

	for(int i = 1; i < (int)arr.size(); i++){
		if(arr[i] != (arr[i + 1] / 2) && arr[i + 1] != (arr[i] / 2)){
			return false;
		}
	}
	return true;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	int n;
    	cin >> n;

    	vector<int>arr(n + 1), ex;

    	for(int i = 1; i <= n; i++){
    		cin >> arr[i];
    		if(arr[i] > 0)
    			ex.push_back(i);
    	}

    	if(ex.size() == 0){
    		if(check(arr)){
    			for(int i = 1; i <= n; i++){
    				cout << arr[i] << " ";
    			}
    			cout << endl;
    		}else{
    			cout << -1 << endl;
    		}
    	}

    	for(int i = 0; i < ex.size() - 1; i++){
    		int l = ex[i];
    		int r = ex[i + 1];

    		while(l <= r){
    			if(arr[l] > arr[r]){
    				arr[++l] = 
    			}
    		}
    	}
    }
    return 0 ;

    runtime();

}

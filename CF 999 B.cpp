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


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	int n;
    	cin >> n;
    	vector<int>arr(n);
    	map<int,int>mp;

    	bool ok = 0;

    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    		mp[arr[i]]++;

    		ok |= (mp[arr[i]] >= 2);
    	}

    	if(!ok){
    		cout << -1 << endl;
    		continue;
    	}

    	sort(arr.begin(), arr.end());
    	bool f = 0;

    	//cout << arr[i] << " " << arr[i + 1] << " " << arr[i + 2] << " " << arr[pos - 1] << endl;
    	

    		if(arr[0] == arr[1]){
    			for(int j = 2; j < n; j++){
    				int k = upper_bound(arr.begin(), arr.end(), arr[0] + arr[1] + arr[j] ) - arr.begin();
    				if(k > j + 1 && arr[0] + arr[1] + arr[j] > arr[k - 1] && !f){
    					cout << arr[0] << " " << arr[1] << " " << arr[j] << " " << arr[k - 1] << endl;
    					f = 1;
    					break;

    				}
    			}
    		}
    		if(arr[1] == arr[2]){
    			for(int j = 0; j < n; j++){
    				if(j == 1 || j == 2)
    					continue;
    				int k = upper_bound(arr.begin(), arr.end(), arr[1] + arr[2] + arr[j] ) - arr.begin();
    				if(k > j + 1 && k != 3 && arr[1] + arr[2] + arr[j] > arr[k - 1] && !f){
    					cout << arr[2] << " " << arr[1] << " " << arr[j] << " " << arr[k - 1] << endl;
    					f = 1;
    					break;

    				}
    			}
    			

    			
    		}
    	for(int i = 2; i < n - 1; i++){
    		if(arr[i] == arr[i + 1] && !f){
    			f = 1;
    			cout << arr[i] << " " << arr[i + 1] << " " << arr[0] << " " << arr[1] << endl;
    			break;

    		}

    	}

    	if(!f){
    		cout << -1 << endl;
    	}




    }
    return 0 ;

    runtime();

}

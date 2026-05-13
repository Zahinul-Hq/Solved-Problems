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

    
    while (0)
    {
    	int n;
    	cin >> n;

    	vector<int>arr(n + 1, 0), narr;

    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    	}

    	for(int i = 0; i < n;){
    		narr.push_back(arr[i]);

    		int j = i + 1;

    		while(arr[i] == arr[j]  && j < n ){
    			j++;
    		}

    		i = j;
    	}

    	sort(narr.begin(), narr.end());

    	if(narr.size() == 1){
    		cout << 0 << endl;
    	}else if(narr.size() == 2){
    		cout << narr[1] - narr[0] << endl;
    	}else if(narr.size() == 3){
    		int diff1 = abs(narr[2] - narr[1]);
	        int diff2 = abs(narr[1] - narr[0]);
	        int diff3 = abs(narr[2] - narr[0]);

	        int minDiff = min({diff1, diff2, diff3});

	        cout << minDiff << endl;
    	}else{
    		int x = narr.size();
    		cout << min((narr[x - 2] - narr[0]) , narr[x - 1] - narr[1]) << endl;
    	}



    }
    return 0 ;

    runtime();

}

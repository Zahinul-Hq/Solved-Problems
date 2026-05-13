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

bool cmp(pair<int,int> l , pair<int,int> r){
	if(l.first == r.first)return l.second > r.second;

	return l.first < r.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


	int n, x, y;
	cin >> n;

	vector<pair<int,int>>a;

	for(int i = 0; i < n; i++){
		cin >> x >> y;
		a.push_back({x, y});
	}
	vector<int>arr;

	sort(a.begin(), a.end(), cmp);

	for(auto i : a)arr.push_back(i.second);
	vector<int>temp;
    int lastIndex = n - 1;
    vector<int> dp(n , 1), lis;
    map<int,int>prev, ID;
    for(int i = 0; i < n; i++){
        int pos = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
        ID[arr[i]] = i;

        if(pos >= temp.size() - 1)
            lastIndex = i;

        if(pos == temp.size()){
            temp.push_back(arr[i]);
            
        }else{
            temp[pos] = arr[i];
        }
        
        prev[i] = pos ? ID[temp[pos - 1]] : -1;

    }

    while(lastIndex != -1){
        lis.push_back(arr[lastIndex]);
        lastIndex = prev[lastIndex];
    }

    cout << lis.size() << endl;
    return 0 ;

    runtime();

}

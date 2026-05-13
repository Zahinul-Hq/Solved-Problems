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
bool check(int indx, vector<int>arr){

	vector<int>gcd;

	for(int i = 1; i < arr.size(); i++){	
		if(i == indx)
			continue;

		if(i - 1 == indx){
			if(i - 1 < 0)
				continue;
			gcd.push_back(__gcd(arr[i], arr[i - 2]));
		}else{
			gcd.push_back(__gcd(arr[i], arr[i - 1]));
		}


	}

	// for(auto i : gcd){
	// 	cout << i << " ";
	// }
	// cout << endl;

	return is_sorted(gcd.begin(), gcd.end());
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int t ;
    cin >> t ;
    
    while (t--)
    {
        int n;
        cin >> n;

        vector<int>arr(n), gcd;
        for(int i = 0; i < n; i++){
        	cin >> arr[i];
        	if(i)
        		gcd.push_back(__gcd(arr[i], arr[i - 1]));
        }

        int indx = -1;
        for(int i = 1; i < gcd.size() - 1; i++){
        	if(gcd[i] > gcd[i + 1]){
        		indx = i;
        		break;
        	}
        }

        if(indx == -1){
        	cout << "YES" << endl;
        	continue;
        }

        if(check(indx, arr) || check(indx + 1, arr) || check(indx + 2, arr)){
        	cout << "YES" << endl;
        }else{
        	cout << "NO" << endl;
        }

    }
    return 0 ;
}

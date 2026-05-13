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

const int N = 2e5 + 7;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        int n ;
        cin >> n;
		int p1[n], p2[n];
		map<int,int>mp;
		for(int i = 0; i < n; i++){
			cin >> p1[i];

		}
		for(int i = 0; i < n; i++){
			cin >> p2[i];
		}
		int ans = INT_MAX, pos = 0, neg = 0, sum1 = 0, sum2 = 0 ;
		for(int i = 0; i < n; i++){
			if(p1[i] == p2[i] && p1[i] == -1){
				neg++;
			}
			else if(p1[i] == p2[i] && p1[i] == 1){
				pos++;
			}else{
				if(p1[i] >= p2[i]){
					sum1 += p1[i];
				}else{
					sum2 += p2[i];
				}

			}
		}
		while(pos--){
			if(sum1 <= sum2)
				sum1++;
			else
				sum2++;
		}
		while(neg--){
			if(sum1 <= sum2)
				sum2--;
			else
				sum1--;
		}
		
		ans = min(sum1, sum2);

		cout << ans << endl;
    }
    return 0 ;
}

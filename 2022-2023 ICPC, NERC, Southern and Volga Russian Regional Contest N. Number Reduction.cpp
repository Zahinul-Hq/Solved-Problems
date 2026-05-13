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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int t ;
    cin >> t ;
    
    while (t--)
    {
        int k ; string s;

        cin >> s >> k;

        int n = s.size();
        vector<vector<int>> pq(10);

        for(int i = 0; i < n; i++){
        	pq[s[i] - '0'].push_back(i);
        }
        for(int i = 0; i < 10; i++){
            reverse(pq[i].begin(), pq[i].end());
            
        }

        vector<int>ans;
        int last_pos = 0;
        int dig = n - k;

        while(dig){
        	for(int j = 1 - (dig != n - k); j < 10; j++){
                while(!pq[j].empty() && pq[j].back() < last_pos){
                    pq[j].pop_back();
                }

                if(!pq[j].empty() && pq[j].back() - last_pos <= k){
                    ans.push_back(j);

                    k -= pq[j].back() - last_pos;
                    last_pos = pq[j].back() + 1;

                    dig--;
                    break;
                }
        	}
        }

        for(auto i : ans)
        	cout << i ;


        cout << endl;
    }
    return 0 ;
}

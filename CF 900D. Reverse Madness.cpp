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

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> l(k + 1, 0), r(k + 1, 0), cnt(n + 1, 0);
        for(int i = 0; i < k; i++){
            cin >> l[i];
            l[i]--;
        }
        for(int i = 0; i < k; i++){
            cin >> r[i];
            r[i]--;
        }
        int q; cin >> q;
        for(int i = 0; i < q; i++){
            int x; cin >> x;
            cnt[x - 1]++;
        }
        string ans = "";

        for(int i = 0 ; i < k; i++){
            int lf = l[i];
            int rt = r[i];
            int sum = 0;
            string ss = s.substr(lf , rt - lf + 1);
            for(int j = lf; j <= (rt + lf) / 2; j++){
                sum += (cnt[j] + cnt[rt - j + lf]);
                if(sum & 1)
                    swap(ss[j - lf], ss[rt - j]);
            }
            ans += ss;
        }
        cout << ans << endl;
    }
    return 0 ;
}

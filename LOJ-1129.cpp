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

struct Node {
    bool endmark;
    Node* next[10];

    Node() {
        endmark = false;
        for (int i = 0; i < 10; i++) {
            next[i] = nullptr;
        }
    }
};

struct Trie {
    Node* root;

    Trie() {
        root = new Node();
    }

    bool insert(const string& str) {
        Node* curr = root;
        for (char ch : str) {
            int id = ch - '0';
            if (curr->next[id] == nullptr) {
                curr->next[id] = new Node();
            }
            if(curr->endmark){
                return false;
            }
            curr = curr->next[id];
        }
        if(curr->endmark){
                return false;
        }
        curr->endmark = true;
        return true;
    }

    bool search(const string& str) {
        Node* curr = root;
        for (char ch : str) {
            int id = ch - '0';
            if (curr->next[id] == nullptr) {
                return false;
            }
            curr = curr->next[id];
        }
        return curr->endmark;
    }

    void del(Node* cur) {
        for (int i = 0; i < 10; i++) {
            if (cur->next[i]) {
                del(cur->next[i]);
            }
        }
        delete cur;
    }

    ~Trie() {
        del(root);
    }
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases,cs = 1 ;
    cin >> test_cases ;

    while (test_cases--)
    {
        
        int q;
        cin >> q;

        ll val;
        Trie trie;

        bool ok = 1;
        vector<ll> qry;

        for(int i = 0; i < q; i++){
            cin >> val;
            qry.push_back(val);
        }

        sort(qry.begin(), qry.end());

        for(int i = 0; i < q; i++){
            string s = to_string(qry[i]);
            //debug(s);
            ok &= trie.insert(s);
        }

        debug(cs, qry);
        
        cout << "Case " << cs++ << ": " << (ok ? "YES" : "NO") << endl;

    }
    return 0 ;

    runtime();

}

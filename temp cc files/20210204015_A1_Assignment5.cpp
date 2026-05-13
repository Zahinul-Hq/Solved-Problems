#include <bits/stdc++.h>
using namespace std;

string s;
int pos;

bool parseExp();
bool parseTerm();
bool parseFactor();

bool parseExp() {
    int save = pos;
    if (!parseTerm()) {
        pos = save;
        return false;
    }
    if (pos < s.size() && (s[pos] == '+' || s[pos] == '-')) {
        pos++;
        if (!parseTerm()) { pos = save; return false; }
    }
    return true;
}

bool parseTerm() {
    int save = pos;
    if (!parseFactor()) {
        pos = save;
        return false;
    }
    if (pos < s.size() && (s[pos] == '*' || s[pos] == '/')) {
        pos++;
        if (!parseFactor()) {
            pos = save;
            return false;
        }
    }
    return true;
}

bool parseFactor() {
    int save = pos;
    if (pos < s.size() && s[pos] == '(') {
        pos++;
        if (!parseExp()) {
            pos = save;
            return false;
        }
        if (pos < s.size() && s[pos] == ')') {
            pos++;
            return true;
        } else { pos = save; return false; }
    }

    if (pos < s.size() && s[pos] >= 'a' && s[pos] <= 'e') {
        pos++;
        return true;
    }
    if (pos < s.size() && isdigit(s[pos])) {
        pos++;
        return true;
    }
    pos = save;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        string line;

        getline(cin, line);
        string original = line;

        s.clear();
        for (char c : line)
            if (!isspace(c))
                s.push_back(c);

        pos = 0;
        bool ok = false;
        if (!s.empty()) {
            ok = parseExp() && pos == s.size();
        } else {
            ok = false;
        }

        cout << original << " -> " << (ok ? "Accepted" : "Rejected") << '\n';





    return 0;
}


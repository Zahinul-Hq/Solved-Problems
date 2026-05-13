#include<bits/stdc++.h>
using namespace std;

struct Symbol {
    string name;
    string id_type;
    string data_type;
    string scope;
    string value;
};

vector<Symbol> table;

int find(const string& name) {
    for (int i = 0; i < table.size(); ++i) {
        if (table[i].name == name) {
            return i;
        }
    }
    return -1;
}

int add(const string& name) {
    int i = find(name);
    if (i == -1) {
        Symbol s;
        s.name = name;
        table.push_back(s);
        return table.size() - 1;
    }
    return i;
}

void set_val(const string& name, const string& id_type, const string& data_type, const string& scope, const string& value) {
    int i = add(name);
    table[i].id_type = id_type;
    table[i].data_type = data_type;
    table[i].scope = scope;
    table[i].value = value;
}

void read_ids(const string& filename) {
    ifstream f(filename);
    if (!f) {
        cout << "Cannot open file.\n";
        exit(1);
    }

    string tok;
    while (f >> tok) {
        if (tok.rfind("[id ", 0) == 0) {
            string name = tok.substr(4, tok.size() - 5); // remove [id and ]
            add(name);
        }
    }
    f.close();
}

void show() {
    cout << "\nNo    Name       IdType     DataType   Scope      Value\n";
    cout << "--------------------------------------------------------\n";
    for (int i = 0; i < table.size(); ++i) {
        const Symbol& s = table[i];
        cout << i + 1 << "\t"
             << s.name << "\t"
             << s.id_type << "\t"
             << s.data_type << "\t"
             << s.scope << "\t"
             << s.value << "\n";
    }
}

void modify_stream(const string& filename) {
    ifstream f(filename);
    if (!f) {
        cout << "Cannot open file.\n";
        exit(1);
    }

    string tok;
    int zcount = 0;
    cout << "\nModified Token Stream:\n";
    while (f >> tok) {
        if (tok.rfind("[id ", 0) == 0) {
            string name = tok.substr(4, tok.size() - 5);  // extract between [id and ]
            if (name == "z") {
                zcount++;
                if (zcount > 3) name = "z_main";
            }
            int i = find(name);
            if (i != -1) {
                cout << "[id " << i + 1 << "] ";
            } else {
                cout << "[id ?] ";
            }
        } else {
            cout << tok << " ";
        }
    }
    f.close();
}

int main() {
    read_ids("input.c");

    set_val("x1", "var", "float", "global", "3.125");
    set_val("f1", "func", "double", "global", "");
    set_val("x", "var", "int", "f1", "");
    set_val("z", "var", "double", "f1", "0.01");
    set_val("main", "func", "int", "global", "");
    set_val("n1", "var", "int", "main", "25");
    add("z_main");
    set_val("z_main", "var", "double", "main", "");

    show();
    modify_stream("input.c");

    return 0;
}

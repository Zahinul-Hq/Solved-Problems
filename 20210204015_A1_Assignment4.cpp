#include <bits/stdc++.h>
using namespace std;

vector<pair<int,string>> errors;
int cnt = 1;
struct symbol
{
    int st_no;
    string name, id_type, data_type, scope, value;
};

vector<symbol> table;
bool match(symbol x, symbol y)
{

    return (x.name == y.name | y.name == "" | x.name == "") and (x.data_type == y.data_type | y.data_type == "" | x.data_type == "") and (x.scope == y.scope | y.scope == "" | x.scope == "") and (x.id_type == y.id_type | y.id_type == "" | x.id_type == "");
}

void insert_val(string name, string id_type, string data_type, string scope, string value = "")
{
    symbol x;
    x.st_no = cnt++;
    x.name = name;
    x.id_type = id_type;
    x.data_type = data_type;
    x.scope = scope;
    x.value = value;
    table.push_back(x);
}

void set_attribute(symbol x, string name = "", string id_type= "", string data_type = "", string scope = "", string value = "")
{

    for(int i = 0; i < table.size(); i++)
    {
        if(match(x, table[i]))
        {
            if(name != "")table[i].name = name;
            if(id_type != "")table[i].id_type = id_type;
            if(data_type != "")table[i].data_type = data_type;
            if(scope != "")table[i].scope = scope;
            if(value != "")table[i].value = value;
        }
    }
}
symbol look_up(string name, bool f)
{
    for(int i = 0; i < table.size(); i++)
    {
        if(f) {
            if(table[i].scope != "main" and table[i].scope != "global") {
                continue;
            }
            else if((table[i].scope == "main" or table[i].scope == "global") and table[i].name == name) return table[i];
        }
        else if(table[i].name == name) return table[i];
    }

    return table[0];
}

void free()
{
    table.clear();
}

void display()
{
    for(int i = 0; i < table.size(); i++)
    {
        cout << table[i].st_no << "     ";
        cout << table[i].name << "     ";
        cout << table[i].id_type << "     ";
        cout << table[i].data_type << "     ";
        cout << table[i].scope << "     ";
        cout << table[i].value << "     ";
        cout << '\n';
    }
}

int valid = 0;

bool check_keyword(string &s)
{
    set<string> keys =
    {
        "int", "float", "long", "double", "char", "#include<stdio.h>",
        "return", "if", "else", "void", "for", "while"
    };
    return keys.count(s);
}

bool check_operator(string &s)
{
    set<string> ops =
    {
        "=", "-", "+", "/", "*", "%", "++", "--", "<=", "==", ">=",
        "&", "^", "|", "&=", "|=", "^=", "+=", "-=", "*=", "/="
    };
    return ops.count(s);
}

bool check_valid_id(const string &s)
{
    if (s.empty()) return false;
    enum State { START, BODY, INVALID };
    State state = START;

    for (int i = 0; i < (int)s.size(); i++)
    {
        char c = s[i];
        switch (state)
        {
        case START:
            if (isalpha(c) || c == '_') state = BODY;
            else return false;
            break;
        case BODY:
            if (isalnum(c) || c == '_') state = BODY;
            else return false;
            break;
        default:
            return false;
        }
    }

    if (check_keyword(const_cast<string&>(s))) return false;
    return state == BODY;
}

bool check_valid_num(const string &s)
{
    if (s.empty()) return false;

    enum State { START, SIGN, INT_PART, DOT, FRAC_PART, INVALID };
    State state = START;

    for (int i = 0; i < (int)s.size(); i++)
    {
        char c = s[i];
        switch(state)
        {
        case START:
            if (c == '+' || c == '-') state = SIGN;
            else if (isdigit(c)) state = INT_PART;
            else if (c == '.') state = DOT;
            else return false;
            break;
        case SIGN:
            if (isdigit(c)) state = INT_PART;
            else if (c == '.') state = DOT;
            else return false;
            break;
        case INT_PART:
            if (isdigit(c)) state = INT_PART;
            else if (c == '.') state = DOT;
            else return false;
            break;
        case DOT:
            if (isdigit(c)) state = FRAC_PART;
            else return false;
            break;
        case FRAC_PART:
            if (isdigit(c)) state = FRAC_PART;
            else return false;
            break;
        default:
            return false;
        }
    }


    return (state == INT_PART || state == FRAC_PART);
}

bool check_bracket(char &s)
{
    set<char> brackets = {')', '(', '}', '{', ']', '['};
    return brackets.count(s);
}

int main()
{
    string inFile = "input.c";
    string outFile = "output.txt";

    ifstream in(inFile);
    ofstream out(outFile);

    // if (!in || !out)
    // {
    //     cerr << "File error!" << endl;
    //     return 1;
    // }


    string code = "";
    char ch;
    while (in.get(ch))
    {
        code += ch;
    }

    // Remove comments
    int line = 1;
    string noCom = "";
    noCom += to_string(line) + ". ";
    bool sl = false, ml = false;
    for (int i = 0; i < (int)code.size(); i++)
    {
        if (code[i] == '\n') {
            line++;
            noCom += to_string(line) + ". ";
        }
        if (sl)
        {
            if (code[i] == '\n')
            {
                sl = false;
                noCom += code[i];
            }
        }
        else if (ml)
        {
            if (code[i] == '*' && i + 1 < (int)code.size() && code[i + 1] == '/')
            {
                ml = false;
                i++;
            }
        }
        else
        {
            if (code[i] == '/' && i + 1 < (int)code.size() && code[i + 1] == '/')
            {
                sl = true;
                i++;
            }
            else if (code[i] == '/' && i + 1 < (int)code.size() && code[i + 1] == '*')
            {
                ml = true;
                i++;
            }
            else
            {
                noCom += code[i];
            }
        }
    }



    // Characters that should have spacing
    set<char> all_operators = {'+', '-', '*', '/', '%', '=', '<', '>', '!', '&', '|', '^'};
    set<char> brackets = {'(', ')', '{', '}', '[', ']'};
    set<string> brackets_in_string = {"(", ")", "{", "}", "[", "]"};
    set<char> separators = {',', ';', '\''};
    set<string> data_types = {"int", "float", "double", "char", "bool", "long", "unsigned"};

    string res = "";
    bool inStr = false;
    bool spc = false;

    for (int i = 0; i < (int)noCom.size(); )
    {
        char c = noCom[i];
        if(c >= '0' and c <= '9' ) {
            string ln = "";
            ln += c;
            int k = i + 1;
            while(noCom[k] >= '0' and noCom[k] <= '9') {
                ln += noCom[k];
                k++;
            }
            if(noCom[k] == '.' and noCom[k + 1] == ' ') {
                ln += ".";
                //cout << ln << '\n';
                res += "Ln" + ln;
                i = k + 2;
                res += ' ';
                continue;
            }

        }
        if (c == '"')
        {
            inStr = !inStr;
            res += c;
            i++;
            continue;
        }

        if (inStr)
        {
            res += c;
            i++;
            continue;
        }

        if (isspace(c))
        {
            spc = true;
            i++;
            continue;
        }

        // Try two-char operator
        if (i + 1 < (int)noCom.size())
        {
            string two = "";
            two += c;
            two += noCom[i + 1];
            if (check_operator(two))
            {
                // Add space only around the whole two-char operator
                res += " " + two + " ";
                i += 2;  // Skip both characters
                spc = false;
                continue;
            }
        }

        // Handle single-char operators, but only if not part of two-char op above
        if (all_operators.count(c))
        {
            res += " ";
            res += c;
            res += " ";
            i++;
            spc = false;
            continue;
        }

        // Handle brackets and separators
        if (brackets.count(c) || separators.count(c))
        {
            res += " ";
            res += c;
            res += " ";
            i++;
            spc = false;
            continue;
        }

        // Insert space if previous char was space and last char in res is not space
        if (spc && !res.empty() && res.back() != ' ')
        {
            res += ' ';
        }

        res += c;
        spc = false;
        i++;
    }

    res += ' ';
    out << res;
    in.close();
    out.close();



    cout << "\nInput:\n" << res << endl;


    // Clean up extra spacing and prepare for tokenization
    string res2 = "";
    for (auto it : res)
    {
        if (it == ';' || it == ',')
        {
            if (!res2.empty() && res2.back() != ' ') res2 += ' ';
            res2 += it;
            res2 += ' ';
            continue;
        }
        if (it == ' ')
        {
            if (!res2.empty() && res2.back() != ' ') res2 += it;
            continue;
        }
        else res2 += it;
    }

    cout << "\nOutput1:\n" << res2 << endl << '\n';


    vector<pair<char, pair<string, pair<string, char>>>> fragmentation; // [ , key , value , ]
    cout << "\nOutput2:\n";
    string chk = "";
    for (auto it : res2)
    {
        if (it == ';' || it == ',' || it == '\'')
        {
            if (!chk.empty())
            {
                if (check_keyword(chk)) cout << "[kw " << chk << "] ", fragmentation.push_back({'[', {"kw", {chk, ']'} }});
                else if (check_operator(chk)) cout << "[op " << chk << "] ", fragmentation.push_back({'[', {"op", {chk, ']'} }});
                else if (check_valid_num(chk)) cout << "[num " << chk << "] ", fragmentation.push_back({'[', {"num", {chk, ']'} }});
                else if (check_valid_id(chk)) cout << "[id " << chk << "] ",fragmentation.push_back({'[', {"id", {chk, ']'} }});
                else cout << "[unkn " << chk << "] ", fragmentation.push_back({'[', {"unkn", {chk, ']'} }});
                chk = "";
            }
            chk += it;
            cout << "[sep " << it << "] ",fragmentation.push_back({'[', {"sep", {chk, ']'} }});
            chk = "";
        }
        else if (it != ' ' && !check_bracket(it))
        {
            chk += it;
        }
        else if (it == ' ' || check_bracket(it))
        {
            if (!chk.empty())
            {
                if (check_keyword(chk)) cout << "[kw " << chk << "] ", fragmentation.push_back({'[', {"kw", {chk, ']'} }});
                else if (check_operator(chk)) cout << "[op " << chk << "] ", fragmentation.push_back({'[', {"op", {chk, ']'} }});
                else if (check_valid_num(chk)) cout << "[num " << chk << "] ", fragmentation.push_back({'[', {"num", {chk, ']'} }});
                else if (check_valid_id(chk)) cout << "[id " << chk << "] ", fragmentation.push_back({'[', {"id", {chk, ']'} }});
                else cout << "[unkn " << chk << "] ", fragmentation.push_back({'[', {"unkn", {chk, ']'} }});
                chk = "";
            }
            chk += it;
            if (check_bracket(it)) cout << "[par " << it << "] ", fragmentation.push_back({'[', {"par", {chk, ']'} }});
            chk = "";
        }
    }

    map<string, int> check_repeat;
    bool main_found = 0;
    bool function_start = 0;
    set<string> data_names = {"float", "double", "int", "long", "bool", "char"};

    cout << '\n';
    cout << '\n';
    cout << "step 1" << '\n';
    string func_name = "";
    map<pair<string, string> ,int> mp;
    map<string, string> undec;
    string ln_no;
    stack<pair<string, string>> prcheck;
    stack<pair<string, string>> if_else_check;
    for(int i = 0; i < fragmentation.size(); i++)
    {
        if(fragmentation[i].second.second.first.find("Ln") != EOF and fragmentation[i].second.first == "unkn") {
            ln_no = "";
            for(auto it : fragmentation[i].second.second.first) {
                if(it >= '0' and it <= '9') ln_no += it;
            }
        }

        /// par matching korbo
        if(brackets_in_string.count(fragmentation[i].second.second.first)) {
           if(fragmentation[i].second.second.first == ")") {
             if(!prcheck.empty() and prcheck.top().first == "(") {
                prcheck.pop();
             }
             else errors.push_back({stoi(ln_no) ,"Missing Starting parenthesis for " + fragmentation[i].second.second.first + " on line " + ln_no});
           }
           else if(fragmentation[i].second.second.first == "}") {
             if(!prcheck.empty() and prcheck.top().first == "{") {
                prcheck.pop();
             }
             else errors.push_back({stoi(ln_no) ,"Missing Starting parenthesis for " + fragmentation[i].second.second.first + " on line " + ln_no});
           }
           else if(fragmentation[i].second.second.first == "]") {
              if(!prcheck.empty() and prcheck.top().first == "[") {
                prcheck.pop();
             }
            else errors.push_back({stoi(ln_no) ,"Missing Starting parenthesis for " + fragmentation[i].second.second.first + " on line " + ln_no});
           }
           else prcheck.push({fragmentation[i].second.second.first, ln_no});
        }

        ///if - else count match korbo
        if(fragmentation[i].second.second.first == "if" and i > 0 and fragmentation[i - 1].second.second.first != "else") {
            if_else_check.push({"if", ln_no});
        }
        if(i + 1 < fragmentation.size() and fragmentation[i].second.second.first == "else" and fragmentation[i + 1].second.second.first == "if") {
           if(!if_else_check.empty() and (if_else_check.top().first == "if" or if_else_check.top().first == "elif")) {
              if_else_check.push({"elif", ln_no});
           }
           else errors.push_back({stoi(ln_no), "Missing If condition before Else if on line " + ln_no});
        }
        else if(fragmentation[i].second.second.first == "else") {
           if(!if_else_check.empty() and (if_else_check.top().first == "if" or if_else_check.top().first == "elif")) {
              if_else_check.push({"else", ln_no});
           }
           else errors.push_back({stoi(ln_no), "Missing If condition before Else on line " + ln_no});
        }

        /// duita data type eksathe likha kina
        if(data_types.count(fragmentation[i].second.second.first)) {
            if(i + 1 < fragmentation.size() and data_types.count(fragmentation[i + 1].second.second.first)) {
                if(fragmentation[i].second.second.first == "long" and fragmentation[i + 1].second.second.first == "long")i++;
                if(fragmentation[i].second.second.first == "long" and fragmentation[i + 1].second.second.first == "double")i++;
                else if(data_types.count(fragmentation[i + 1].second.second.first)){
                    errors.push_back({stoi(ln_no), "Two specifiers declared together on line " + ln_no});
                }
            }
        }


        if(fragmentation[i].second.second.first == "(") function_start = 1;
        if(fragmentation[i].second.second.first == "}") function_start = 0, func_name = "";
        if(function_start and func_name == "") func_name = fragmentation[i - 1].second.second.first;
        if(fragmentation[i].second.second.first == "main") main_found = 1;
        if(fragmentation[i].second.first != "id")fragmentation[i].second.first = "";
        cout << fragmentation[i].first << fragmentation[i].second.first;
        if(fragmentation[i].second.first != "") cout << ' ';
        cout<< fragmentation[i].second.second.first << fragmentation[i].second.second.second << ' ';
        symbol x;
        if(fragmentation[i].second.first == "id")
        {
            x.name = fragmentation[i].second.second.first;
            check_repeat[fragmentation[i].second.second.first]++;

            //check korbo data type
            if(i > 0)
            {
                if(data_names.count(fragmentation[i - 1].second.second.first))
                {
                    x.data_type = fragmentation[i - 1].second.second.first;
                }
            }


            // check korbo id type
            if(i < fragmentation.size() - 1)
            {
                if(fragmentation[i + 1].second.second.first == "(")
                {
                    x.id_type = "func";
                }
                else x.id_type = "var";
            }
            else
            {
                x.id_type = "var";
            }


            //check korbo scope
            if(main_found and fragmentation[i].second.second.first != "main")
            {
                x.scope = "main";
            }
            else
            {
                if(function_start)
                {
                    x.scope = func_name;
                }
                else x.scope = "global";
            }


            //check korbo value
            if(i + 2 < fragmentation.size())
            {
                if(fragmentation[i + 1].second.second.first == "=")
                {
                    if(fragmentation[i + 2].second.first == "id")
                    {
                        symbol p = look_up(fragmentation[i + 2].second.second.first, 0);
                        x.value = p.value;
                    }
                    else x.value = fragmentation[i + 2].second.second.first;
                }

            }

            if(fragmentation[i].second.second.first == "void") continue;
            if(check_repeat[fragmentation[i].second.second.first] == 1 or data_names.count(fragmentation[i - 1].second.second.first))
            {
                insert_val(x.name != ""? x.name : "", x.id_type != ""? x.id_type : "", x.data_type != ""? x.data_type : "", x.scope != ""? x.scope : "", x.value != ""? x.value : "");
                mp[{x.name, x.scope}]++;
                if(mp[make_pair(x.name, x.scope)] > 1) {
                    errors.push_back({stoi(ln_no), "Redeclaration with different data type of " + x.name + " on line " + ln_no});
                }

                if(x.data_type == "" and undec[x.name] == "" and x.id_type == "var")undec[x.name] = ln_no;
            }
            else {
                if(undec[x.name] != "" and x.data_type != "" and x.id_type == "var") undec[x.name] = "";
                set_attribute(x, x.name != ""? x.name : "", x.id_type != ""? x.id_type : "", x.data_type != ""? x.data_type : "", x.scope != ""? x.scope : "", x.value != ""? x.value : "");
            }
        }
    }

    while(!prcheck.empty()) {
        errors.push_back({stoi(prcheck.top().second),"Missing Ending parenthesis for " + prcheck.top().first + " on line " + prcheck.top().second});
        prcheck.pop();
    }

    cout << '\n';
    cout << '\n';
    cout << "step 2" << '\n';
    display();

    cout << '\n';
    cout << '\n';
    cout << "step 3" << '\n';
    main_found = 0;
    for(int i = 0; i < fragmentation.size(); i++) {
         if(fragmentation[i].second.second.first == "main") main_found = 1;
         if(fragmentation[i].second.first == "id") {
            symbol x = look_up(fragmentation[i].second.second.first, main_found);
            fragmentation[i].second.second.first = to_string(x.st_no);

         }

        cout << fragmentation[i].first << fragmentation[i].second.first;
        if(fragmentation[i].second.first != "") cout << ' ';
        cout<< fragmentation[i].second.second.first << fragmentation[i].second.second.second << ' ';
    }

    cout << "\n\n";

    for(auto it : undec) {
        if(it.second != "") {
            errors.push_back({stoi(it.second), "Undeclared variable " + it.first + " on line " + it.second});
        }
    }
    sort(errors.begin(), errors.end());
    cout << "All the errors :" << "\n\n";
    for(auto it : errors) cout << "Line " << it.first << ": " << it.second << '\n';
    return 0;
}

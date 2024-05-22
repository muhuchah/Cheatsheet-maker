vector<string> split(string s, char ch = ' ') {
    int n = s.size();
    vector<string> sp;
    string tmp = "";
    for (int i = 0; i < n; i++) {
        if (s[i] != ch) tmp += s[i];
        else if (tmp != "") {
            sp.push_back(tmp);
            tmp = "";
        }
    }
    if (tmp != "") sp.push_back(tmp);
    return sp;
}

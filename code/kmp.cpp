#include <bits/stdc++.h>
using namespace std;

vector<int> lps(const string &p) {
    vector<int> l(p.size());
    for (int i = 1, j = 0; i < (int)p.size(); ++i) {
        while (j > 0 && p[i] != p[j]) j = l[j - 1];
        if (p[i] == p[j]) ++j;
        l[i] = j;
    }
    return l;
}

void kmp(const string &t, const string &p) {
    auto l = lps(p);
    for (int i = 0, j = 0; i < (int)t.size(); ++i) {
        while (j > 0 && t[i] != p[j]) j = l[j - 1];
        if (t[i] == p[j]) ++j;
        if (j == (int)p.size()) {
            cout << "Pattern found at " << i - j + 1 << '\n';
            j = l[j - 1];
        }
    }
}

int main() {
    string text = "abxabcabcaby";
    string pattern = "abcaby";
    cout << "Text: " << text << '\n';
    cout << "Pattern: " << pattern << '\n';
    kmp(text, pattern);
    return 0;
}

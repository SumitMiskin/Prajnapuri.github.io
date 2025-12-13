// Trie (simple stub) + KMP example
#include <bits/stdc++.h>
using namespace std;

// KMP functions
vector<int> computeLPS(string pattern) {
    int m = pattern.length(); vector<int> lps(m,0);
    for (int i =1,len=0;i<m;i++){
        while(len>0 && pattern[i]!=pattern[len]) len = lps[len-1];
        if (pattern[i]==pattern[len]) len++; lps[i]=len;
    }
    return lps;
}

void KMPSearch(string text,string pattern){ int n=text.length(), m=pattern.length(); vector<int> lps=computeLPS(pattern); int i=0,j=0;
    while(i<n){ if(text[i]==pattern[j]){ i++; j++; } if(j==m){ cout<<"Pattern found at index "<<i-j<<endl; j=lps[j-1]; }
        else if(i<n && text[i]!=pattern[j]){ if(j!=0) j=lps[j-1]; else i++; }
    }
}

int main(){ string feedback = "poor lighting reported near station. poor lighting and no cctv observed."; string pattern = "poor lighting"; KMPSearch(feedback, pattern); return 0; }

#include <cstdio>
#include <bitset>
#include <string>
#include <iostream>
using namespace std;
#define mod 26561473
bitset<mod> lib;
inline void add(int hash_1, int hash_2) {
    lib[hash_1] = 1;
    lib[hash_2] = 1;
    return;
}
inline bool find(int hash_1, int hash_2) {
    return lib[hash_1] && lib[hash_2];
}
unsigned int gethash(string& s, int mode) {
    register  unsigned int value = 0;
    if (mode ^ 1)
        for (int i = 0; i < s.length(); i++) {
            value = (value * 127 + s[i]) % mod;
        }
    else
        for (int i = 0; i < s.length(); i++) {
            value = ((value << 7) + s[i]) % mod;
        }
    return value;
}
int n;
int main(){
    cin >> n;
    string s;
    for (int i = 0; i < n; i++){
        cin >> s;
        if (s.length() ^ 4){
            getline(cin, s);
            add(gethash(s, 0), gethash(s, 1));
        }
        else {
            getline(cin, s);
            if (find(gethash(s, 0), gethash(s, 1))) printf("yes\n");
            else (printf("no\n"));
        }
    }
    return 0;
}
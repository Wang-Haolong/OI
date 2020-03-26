#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
#define ull unsigned long long int
string s;
ull mods[1200], hash_v[1200][2];
inline ull readhash(int a, int b) {
    if (a <= b){
        if (a ^ 0) {
            return hash_v[b][0] - hash_v[a - 1][0] * mods[b - a + 1];
        }
        else return hash_v[b][0];
    }
    else{
        if (b ^ s.length()) {
            return hash_v[b][1] - hash_v[a + 1][1] * mods[a - b + 1];
        }
        else return hash_v[a][1];
    }
}
int main() {
    getline(cin, s);
    for (int i = 0, x = 1; i < s.length(); i++, x *= 127) {
        mods[i] = x;
    }
    ull v = 0;
    for (int i = 0; i < s.length(); i++) {
        hash_v[i][0] = v = v * 127 + s[i];
    }
    v = 0;
    for (int i = s.length(); i >= 0; i--) {
        hash_v[i][1] = v = v * 127 + s[i];
    }
    for (int i = 2; i <= s.length(); i++) {
        for (int j = 0; j + i <= s.length(); j++) {
            if(!(readhash(j, j + ((i + 1) >> 1) - 1) ^ readhash(j + i - 1, j + (i >> 1)))) {
                for (int k = 0; k < i; k++) {
                    putchar(s[j + k]);
                }
                putchar('\n');
            }
        }
    }
    return 0;
}
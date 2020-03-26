#include <bitset>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#define ull unsigned long long int
using namespace std;
ull hash_v[1000005], mul[1000005];
ull gethash(int a, int b) {
    if (a) return  hash_v[b] - hash_v[a - 1] * mul[b - a + 1];
    return hash_v[b];
}
int main(){
    for (ull i = 0, v = 1; i < 1000005; i++, v *= 127) {
        mul[i] = v;
    }
    string s;
    for (cin >> s; s != "."; cin >> s) {
        memset(hash_v, 0, sizeof(hash_v));
        for (ull i = 0, v = 0; i < s.length(); i++) {
            hash_v[i] = v = v * 127 + s[i];
        }
        bool finished = 0;
        for (int i = 1; i <= s.length(); i++){
            if (!(s.length() % i)) {
                bool flag = 0;
                for (int j = 0; ((j + i) <= s.length()) && !flag; j += i) {
                    if (gethash(0, i - 1) ^ gethash(j, j + i - 1))
                        flag = 1;
                }
                if (!flag) {
                    printf("%d\n", s.length() / i);
                    finished = 1;
                }
            }
            if (finished) break;
        }
    }
    return 0;
}
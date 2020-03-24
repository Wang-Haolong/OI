#include <cstdio>
#include <cstring>
using namespace std;
inline int read() {
    char ch = getchar();
    int x = 0;
    while (ch > '9' || ch < '0') ch = getchar();
    while (ch <= '9' && ch >= '0') {
        x = (x << 1) + (x << 3) + (ch - 48);
        ch = getchar();
    }
    return x;
}
inline int max(int a, int b) { return a > b? a : b; }
int n = 0, queue[105][3], maxn = 0;
int main() {
    n = read();
    memset(queue, 0, sizeof(queue));
    for (register int i = 0; i < n; i++) {
        queue[i][0] = read();
    }
    for (register int i = 0; i < n; i++) {
        for (register int j = 0; j < i; j++) {
            if (queue[j][0] < queue[i][0] && queue[j][1] >= queue[i][1]) 
                queue[i][1] = queue[j][1] + 1;
        }
    }
    for (register int i = n - 1; i >= 0; i--) {
        for (register int j = n - 1; j > i; j--) {
            if (queue[j][0] < queue[i][0] && queue[j][2] >= queue[i][2]) 
                queue[i][2] = queue[j][2] + 1;
        }
    }
    for (register int i = 0; i < n; i++) {
        maxn = max(maxn, queue[i][1] + queue[i][2]);
    }
    printf("%d", n - maxn - 1);
    return 0;
}
#include<cstdio>
#include<vector>
using namespace std;
inline int read(){
    char ch = getchar();
    int x = 0, f = 1;
    while(ch > '9' || ch < '0') {
        ch = getchar();
        if (!(ch ^ '-')) f = -1;
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch - 48);
        ch = getchar();
    }
    return f * x;
}
int n = 0;
vector<int>nums;
long long int sum = 0;
int main(){
    n = read();
    for (int i = 0; i < n; i++) {
        int l = 0, r = i;
        int x = read();
        while(l ^ r){
            int m = (l + r) >> 1;
            if (x >= nums[m]) l = m + 1;
            else r = m;
        }
        nums.insert(nums.begin() + r, x);
        sum += i - r;
    }
    printf("%d", sum);
    return 0;
}
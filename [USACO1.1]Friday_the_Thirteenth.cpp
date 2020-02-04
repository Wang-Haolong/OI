#include<cstdio>
#include<cctype>
#include<cstring>
using namespace std;
inline int read() {
    register int x = 0; register char ch = getchar();
    while(!isdigit(ch)) ch = getchar();
    while(isdigit(ch)) {
        x = (x << 1) + (x << 3) + (ch - 48);
        ch = getchar();
    }
    return x;
}
class Count{
private:
    int days[7];
    bool isleap(const int& year) {
        if (year & 3) return false;
        else {
            if (year % 100) return true;
            else {
                if ((year >> 2) % 100) return false;
                else {
                    if (year & 31) return true;
                    else {
                        if ((year >> 5) % 100) return false;
                    }
                }
            }
        }
    }
    int getday(const int& month, const int& year){
        if (month & 1) {
            if (month ^ 9 && month ^ 11) return 31;
            else return 30;
        }
        else {
            if (month ^ 2){
                if (month ^ 4 && month ^ 6)return 31;
                else return 30;
            }
            else return isleap(year)? 29 : 28;
        }
    }
    int each_year(int day_13, const int& year) {
        for (int month = 1; month <= 12; month++) {
            days[day_13]++;
            day_13 = (day_13 + getday(month, year)) % 7;
        }
        return day_13;
    }
public:
    Count() {
        memset(days, 0, 28);
    }
    Count* start_count(int n) {
        register int year = 1900, jan_13 = 0, end_year = 1900 + n;
        while (year < end_year) {
            jan_13 = each_year(jan_13, year);
            year++;
        }
        return this;
    }
    Count* output(){
        for(int i = 0; i < 7; i++)printf("%d ", days[i]);
        return this;
    }
}ans;
int main(){
    ans.start_count(read())->output();
    return 0;
}
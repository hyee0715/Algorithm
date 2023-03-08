#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    
    int months[] = {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string days[] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    
    int day = 0;
    
    for (int i = 1; i < a; i++) {
        day += months[i];
    }
    
    day += b;
    
    answer = days[day % 7];
    
    return answer;
}
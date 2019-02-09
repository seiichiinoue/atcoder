#include <bits/stdc++.h>
using namespace std;
int main()
{
    float deg, dis;
    string str[17] =
    {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", 
    "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW", "N"};
    float dis_table[14] =
    {0.2, 1.5, 3.3, 5.4, 7.9, 10.7, 13.8, 
    17.1, 20.7, 24.4, 28.4, 32.6, 200.0};
    int dis_ans;
    cin >> deg >> dis;
    
    deg /= 10;
    dis /= 60;
    dis = round(dis * 10) / 10;
    for (int i = 0; i < 13; i++){
        if (dis <= dis_table[i]){
            dis_ans = i;
            break;
        }
    }
    
    double current = 11.25;
    int index;
    if (dis_ans == 0){
        cout << "C" << " " << 0 << endl;
        return 0;
    }
    else {
        for (int i = 0; i < 17; i++){
            if (deg < current){
                index = i;
                break;
            }
        current += 22.5;
        }
    }
    cout << str[index] << " " << dis_ans << endl;
}
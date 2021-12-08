#include <iostream>
#include <iomanip>
using namespace std;

int WaveCount(double prices[], int N, int start, double R) {
    int i, id = start + 1;
    double max_price = prices[start + 1], rate = (prices[start + 1] / prices[start]) - 1.0;
    for (i = start + 1 ; i < N ; i++){
        if (prices[i] < prices[start])  return -1;
        if (rate <= R){
            if (prices[i] >= max_price){
                max_price = prices[i];
                rate = (prices[i] / prices[start]) - 1.0;
                id = i;
            }
        }
        else{
            if (prices[i] >= max_price){
                max_price = prices[i];
                rate = (prices[i] / prices[start]) - 1.0;
                id = i;
            }
            else
                break;
        }
    }
    if (rate > R)
        return id;
    else
        return -1;
}

int main() {
    double R; // 漲幅比率值
    int N = 0; // 股價資料數量
    int dates[365] = {};  // 股價資料的日期
    double prices[365];
    cin >> R;
    cin >> N;

    for (int i=0; i<N; i+=1) {
        cin >> dates[i] >> prices[i];
    }

    int start = 0;
    int end = 0;
    int wave_num = 0; // 波段的數量
    double real_rate;
    while (start < N-2) {
        end = WaveCount(prices, N, start, R);

        if (end != -1) {
            real_rate = (prices[end] / prices[start] - 1.0) * 100.0;
            real_rate =  (float)((int)(real_rate * 10 + 0.5)) / 10.0;

            cout << dates[start] << " " << prices[start] << " " << dates[end] << " " << prices[end] << " " << real_rate << "%" <<endl;
            start = end + 1;
            wave_num += 1;
        }
        else {
            start += 1;
        }
    }

    int percent = R * 100;
    if (wave_num > 0) {
        cout << "本支股票從 " << dates[0] << " 到 " << dates[N-1] << " 間超過" << percent << "%漲幅共" << wave_num << "次" << endl;
    }
    else { // 無任何波段
        cout << "本支股票從 " << dates[0] << " 到 " << dates[N-1] << " 無所設定" << percent << "%之漲幅" << endl;
    }
    return 0;
}

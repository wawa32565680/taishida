#include <iostream>
using namespace std;
/*
P �o�����X
W �Y�����X
N �o���i��
M �����`���B 
*/
int WinPrize (char W[], char P[]) {
	int i;
	const int money[9] = {0, 0, 0, 200, 1000, 4000, 10000, 40000, 200000};
    for (i = 0 ; i < 8 ; i++){
    	if (P[7 - i] != W[7 - i])
    		break;
	}
	return money[i];
}

int main() {
    char W[9] = {}; // ????
    char P[9] = {}; // ????
    int N = 0; // ????
    int M = 0; // ?????

    cin >> W;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> P;
        M += WinPrize(W, P);
    }

    cout << M << endl;
    return 0;
}

#include <iostream>
#include <math.h>
using namespace std;

int Ball(int S[]) {
    int x = 1, score;
    while (x - 1 < 7){
    	int j = x;
    	x = x * 2 + S[x - 1];
    	S[j - 1] = !S[j - 1];
    }
    score = S[x - 1];
	return score;
}

int main() {
    int N = 0; // ????
    cin >> N; // ??????

    int S[15] = {0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 1, 1, 2, 3, 1}; // ?????????
    //7~14 ¤À¼Æ 0~6 ¹hªù 
	for (int i=0; i<7; i+=1) {
        cin >> S[i]; // ????????
    }

    int score = 0; // ??

    for (int i=0; i<N; i+=1) {
        score += Ball(S);
    }
    cout << score << endl; // ????
    return 0;
}

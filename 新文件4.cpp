#include <iostream>
using namespace std;

int *MusicOrder(int chapter_len, int M, int *X_sorted, int *X_sorted_id, int *music_list) {
	int i, times = chapter_len, id = -1;
	for (i = 0 ; i < M ; i++){
		if (X_sorted[i] < 0)
			continue;
		if (times - X_sorted[i] >= 0){
			times -= X_sorted[i];
			music_list[++id] = X_sorted_id[i] + 1;
			X_sorted[i] = -1;
		}
	}
	return music_list;
}

int main() {
    int M = 0; // ???????M
    cin >> M; // ??????????M

    int X[M]; // ??????
    int X_sorted[M]; // ??????????
    int X_sorted_id[M]; // ??????????
    int rounds = 4; // ???
    int chapter_len = 780; // ???????

    // ????????
    for(int i=0; i<M; i+=1) {
        cin >> X[i];
    }

    // ????(????)
    int j = 0;
    double key = 0;
    X_sorted[0] = X[0];
    X_sorted_id[0] = 0;
    for (int i=1; i<M; i+=1) {
        key = X[i];
        j = i - 1;
        while (j>=0 && X_sorted[j]<=key) {
            X_sorted[j+1] = X_sorted[j];
            X_sorted_id[j+1] = X_sorted_id[j];
            j -= 1;
        }
        X_sorted[j+1] = key;
        X_sorted_id[j+1] = i;
    }

    // ?????????
    for (int i=0; i<rounds; i+=1) {
      int remain = chapter_len;
      int music[100] = {0};
      int *music_list = MusicOrder(chapter_len, M, X_sorted, X_sorted_id, music);

      int j = 0;
      while (music_list[j] != 0) {
          cout << music_list[j] << " ";
          remain -= X[music_list[j]-1];
          j += 1;
      }
      cout << remain << endl;
    }

    return 0;
}

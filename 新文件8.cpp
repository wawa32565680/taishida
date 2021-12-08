#include<iostream>
using namespace std;

int start_id = 0; // ?????????????

int WhoOut(int students[], int N, char color, int point)  {
    int i, j, lr;
    if (color == 'R')
    	lr = 1;
    else if (color == 'B')
    	lr = -1;
    i = start_id;
    point--;
    for (; point > 0 ; point--){
    	do{
    		i += lr;
	    	if (i >= N)
	    		i = 0;
	    	else if (i < 0)
	    		i = N - 1;
		} while (students[i] == 1);
	}
	start_id = i;
	do{
		start_id += lr;
		if (start_id >= N)
	    	start_id = 0;
	    else if (start_id < 0)
	    	start_id = N - 1;
	} while (students[start_id] == 1);
	return i + 1;
}

int main() {
    int N = 0; // ????
    int M = 0; // ??????
    int students[100] = {}; // ??????
    int outList[100] = {}; // ?????????

    cin >> N >> M;

    if (M > N) {
        printf("error occur");
    }
    else {
        char color; // ??
        int point = 0; // ??
        for (int i=0; i<M; i++) {
            cin >> color >> point;
            outList[i] = WhoOut(students, N, color, point);
            students[outList[i]-1] = 1; // ?????????/??
        }
        for (int i=0; i<M; i++) {
            printf("%d\n", outList[i]);
        }
    }
    return 0;
}

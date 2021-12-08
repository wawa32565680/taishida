#include <iostream>
using namespace std;

int *ContainerOrder(int map[][10], int container_no) { 
    int *p = new int[70]{0};
    int stack[70] = {0};
    const int LorR[2] = {-1, 1};
    int x, y, top = -1;
    for (x = 0 ; x < 7 ; x++){
    	for (y = 0 ; y < 10 ; y++)
    		if (map[x][y] == container_no)
    			break;
    	if (y < 10)
    		break;
    }
    for (int i = x ; i >= 0 ; i--){
    	for (int j = y ; (j >= 0 && j <= 9) ; j += LorR[y >= 5]){
    		if (map[i][j] == container_no)
    			continue;
    		stack[++top] = map[i][j];
		}
	}
	for (int i = 0 ; top >= 0 ; top--, i++){
		p[i] = stack[top];
	}
	return p;
}

int main() {
    int container_no = 0; // ????????
    cin >> container_no;

    int map[7][10] = {{1, 40, 65, 22, 35, 55, 14, 53, 64, 42},
        {17, 28, 44, 10, 43, 3, 27, 34, 54, 19},
        {41, 18, 62, 45, 39, 21, 8, 70, 13, 63},
        {31, 49, 5, 25, 61, 36, 2, 56, 59, 4},
        {23, 58, 11, 15, 9, 52, 67, 24, 46, 26},
        {7, 48, 30, 57, 32, 29, 16, 51, 69, 38},
        {33, 66, 6, 37, 60, 47, 12, 68, 20, 50}}; // ??????

    int *container_list = ContainerOrder(map, container_no);

    // ???????
    int i = 0;
    int move_time = 3; // ??????????
    int move_num = 0; // ??????
    while(container_list[i] != 0) {
        i += 1;
        move_num += 1;
    }
    cout << move_num * move_time << endl;

    // ????????
    i = 0;
    while(container_list[i] != 0) {
        cout << container_list[i] << " ";
        i += 1;
    }
    cout << endl;

    return 0;
}

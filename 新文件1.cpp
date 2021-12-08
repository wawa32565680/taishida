#include <iostream>
#include <fstream>
using namespace std;

int map[12][12] = {-1}; 
int visit[12][12] = {0}; 

int BugFinder(int x, int y) {
	int count = 0, top = -1;
	int stack_x[20], stack_y[20];
	int x_move[4] = {-1,0,1,0};
	int y_move[4] = {0,1,0,-1};
	if (map[x][y] == 1){
		top++;
		stack_x[top] = x;
		stack_y[top] = y;
	}
	while (top >= 0){
		int _x = stack_x[top], _y = stack_y[top];
		top--;
		count++;
		visit[_x][_y] = 1;
		for (int i = 0 ; i < 4 ; i++){
			if (map[_x + x_move[i]][_y + y_move[i]] == 1 && visit[_x + x_move[i]][_y + y_move[i]] == 0){
				top++;
				stack_x[top] = _x + x_move[i];
				stack_y[top] = _y + y_move[i];
				visit[_x + x_move[i]][_y + y_move[i]] = 1;
			}
		}
	
	}
	return count;
}

int main() {
    int M = 0; 
    int N = 0; 
    cin >> M;
    cin >> N;

    for (int i=1; i<M+1; i+=1) {
        for (int j=1; j<N+1; j+=1) {
            cin >> map[i][j];
        }
    }

    int x = 0;
    int y = 0;
    cin >> x;
    cin >> y;

    int area = 0;
    area = BugFinder(x+1, y+1);
    cout << area << "\n";

    return 0;
}

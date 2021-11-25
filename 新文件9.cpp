#include<iostream>
#include<algorithm>

using namespace std;

struct course { // 課程
    int day;
    char name;
    int start;
    int end;
};
typedef struct course Course;

void SelectCourse(Course results[], int *rs, bool selected[], Course candidates[], int cs)   {
    int day[8] = {0};
    const char code[12] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'};
    int i, j, k;
    for (i = 0 ; i < cs ; i++){
    	//if (selected[candidates[0].name - 'A'] == true)	continue;
    	int end_min;
    	int id;
    	for (j = 0 ; j < cs ; j++){
    		for (k = candidates[j].start - 1 ; k < candidates[j].end ; k++)
    			if (day[k] == 1)	break;
    		
    		if (selected[candidates[j].name - 'A'] == false && k == candidates[j].end){
    			end_min = candidates[j].end;
    			id = j;
    			break;
			}
		}
    	for (j = 0 ; j < cs ; j++){
    		if (selected[candidates[j].name - 'A'] == true)	continue;
    		for (k = candidates[j].start - 1 ; k < candidates[j].end ; k++)
    			if (day[k] == 1)	break;
    		if (k < candidates[j].end)
    			continue;
    		if (candidates[j].end < end_min ){
    			id = j;
    			end_min = candidates[j].end;
			}
			else if (candidates[j].end == end_min && candidates[j].name < candidates[id].name )
				id = j;
		}
		for (k = candidates[id].start - 1 ; k < candidates[id].end ; k++)
			if (day[k] == 1)
				break;
		if (k == candidates[id].end){
			for (k = candidates[id].start - 1 ; k < candidates[id].end ; k++)
				day[k] = 1;
			selected[candidates[id].name - 'A'] = true;
			results[*rs] = candidates[id];
			*rs += 1;
		}
	}
}

int main() {
    Course allcourse[36] = {0}, results[36] = {0}; // 所有課程、選課結果
    int n = 0; // 所有課程數量
    int rs = 0; // 選課結果數量（results）
    bool selected[12] = {false}; // 紀錄可程是否被選過

    cin >> n;
    for (int i=0; i<n; i+=1) { // 輸入課程
        cin >> allcourse[i].day >> allcourse[i].name >> allcourse[i].start >> allcourse[i].end;
    }

    for (int days = 1; days <= 3; days+=1) {
         Course candidates[12] = {0}; // 每日可選課程
         int cs = 0; // 每日可選課程數量（candidates）
         for (int i = 0; i < n; i+=1) {
             if (allcourse[i].day == days) {
                 candidates[cs] = allcourse[i];
                 cs += 1;
             }
         }

         SelectCourse(results, &rs, selected, candidates, cs);
    }

    for(int i = 0; i < rs; ++i) {
        cout << results[i].day << " " << results[i].name << " " << results[i].start << " " << results[i].end << endl;
    }
    return 0;
}

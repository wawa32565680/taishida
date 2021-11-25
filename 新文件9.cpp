#include<iostream>
#include<algorithm>

using namespace std;

struct course { // �ҵ{
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
    Course allcourse[36] = {0}, results[36] = {0}; // �Ҧ��ҵ{�B��ҵ��G
    int n = 0; // �Ҧ��ҵ{�ƶq
    int rs = 0; // ��ҵ��G�ƶq�]results�^
    bool selected[12] = {false}; // �����i�{�O�_�Q��L

    cin >> n;
    for (int i=0; i<n; i+=1) { // ��J�ҵ{
        cin >> allcourse[i].day >> allcourse[i].name >> allcourse[i].start >> allcourse[i].end;
    }

    for (int days = 1; days <= 3; days+=1) {
         Course candidates[12] = {0}; // �C��i��ҵ{
         int cs = 0; // �C��i��ҵ{�ƶq�]candidates�^
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

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int *Frequency(char *MD5) { 
    int *p = new int[16]{0};
    const char ch[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    for (int i = 0 ; i < strlen(MD5) ; i++){
    	for (int j = 0 ; j < 16 ; j++){
    		if (*(MD5 + i) == *(ch + j)){
    			*(p + j) += 1;
    			break;
			}
		}
	}
    return p;
}

int main() {
    char MD5[35];
    cin >> MD5;

    // ??MD5???????
    int *count = Frequency(MD5);

    // ????
    int max_count = 0;
    for(int i=0; i<16; i+=1) {
        max_count = *max_element(count, count+16); // ???????
        if (max_count <= 1) { // ??????1
            break;
        }
        for(int j=0; j<16; j+=1) {
            if (count[j] == max_count) {
                if (j <= 9) { // ?????
                    cout << j;
                }
                else { // ?????
                    cout << char(j + 'A' - 10);
                }
                count[j] = 1;
            }
        }
    }
    cout << endl;

    return 0;
}

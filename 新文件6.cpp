#include <iostream>
#include <cstring>
using namespace std;

bool Message(bool flg) { // ????,?????(0?1)
    if (flg == 0) {
        cout << "Fail" << endl;
    }
    else {
        cout << "Pass" << endl;
    }
    return flg;
}

bool CheckPwdLength(char password[]) { // r1:??????8???
    int len = strlen(password);
    return len >= 8;
}

bool CheckPwdLetter(char password[]) { // r2:???????????????
    bool upper = false, lower = false;
    int len = strlen(password);
    for(int i = 0; i < len; i++) {
        if(password[i] >= 'a' && password[i] <= 'z') {
            lower = true;
        }
        else if(password[i] >= 'A' && password[i] <= 'Z') {
            upper = true;
        }
    }
    return lower&&upper;
}
bool CheckPwdWithDigit(char password[]) { // r3:??????????0-9
    int len = strlen(password);
    for(int i = 0; i < len; i++) {
        if(password[i] >= '0' && password[i] <= '9') {
            return true;
        }
    }
    return false;
}

bool CheckPwdPattern(char password[]) { // r4:????????????(???????)
    char drowssap[105] = {'\0'};
	for (int i = strlen(password) - 1, j = 0 ; i >= 0 ; i--){
    	drowssap[j++] = password[i];
	}
	if (strcmp(drowssap,password) == 0)
		return false;
	else
		return true;
}

int main() {
    char pwdStr[105] = {};
    int score = 0;

    cin >> pwdStr;

    score += Message(CheckPwdLength(pwdStr)); // Call r1
    score += Message(CheckPwdLetter(pwdStr)); // Call r2
    score += Message(CheckPwdWithDigit(pwdStr)); // Call r3
    score += Message(CheckPwdPattern(pwdStr)); // Call r4

    cout << score << endl; // ??????????
    return 0;
}

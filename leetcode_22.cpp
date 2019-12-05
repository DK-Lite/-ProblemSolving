#include <iostream>
#include <vector>
#include <string>
using namespace std;

int g_n;
vector<string> res;

void back(string s, int left, int right, int step) {
	if (step == g_n*2) {
		vector<char> stack;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(')
				stack.push_back(s[i]);
			else if (!stack.empty()) {
				stack.pop_back();
			}
			else {
				return;
			}
		}
		string res_str = "";
		for (int i = 0; i < g_n*2; i++) res_str += s[i];
		res.push_back(res_str);
		return;
	}

	if(left < g_n) back(s + "(", left+1, right, step + 1);
	if(right < g_n) back(s + ")", left, right+1, step + 1);
}

vector<string> generateParenthesis(int n) {
	g_n = n;
	back("", 0, 0, 0);
	return res;
}
//int main() {
//
//
//	generateParenthesis(3);
//
//	for (int i = 0; i < res.size(); i++) {
//		cout << res[i] << endl;
//	}
//	int stop;
//	cin >> stop;
//	
//	
//
//	return 0;
//}
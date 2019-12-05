#include <iostream>
#include <vector>
#include <string>
using namespace std;

int strStr(string haystack, string needle) {

	if (haystack == needle) return 0;
	if (haystack.size() < needle.size()) return -1;
	
	long findkey = 0;
	long hashkey = 0;
	int two = 1;
	for (int i = 0; i < needle.size(); i++) {
		findkey += (needle[i]-'a') * two;
		findkey %= 32312323411;
		hashkey += (haystack[i] - 'a') * two;
		hashkey %= 32312323411;
		two *= 2;
	}
	two /= 2;
	for (int i = 0; i < haystack.size()-needle.size()+1; i++) {
		if (findkey == hashkey) return i;
		hashkey -= haystack[i] - 'a';
		hashkey /= 2;
		hashkey += (haystack[i + needle.size()] - 'a') * two;
		hashkey %= 32312323411;
	}
	return -1;
}
int main() {
	cout << strStr("abbbbbaabbaabaabbbaaaaabbabbbabbbbbaababaabbaabbbbbababaababbbbaaabbbbabaabaaaabbbbabbbaabbbaabbaaabaabaaaaaaaa","abbbaababbbabbbabbbbbabaaaaaaabaabaabbbbaabab") << endl;
	return 0;
}
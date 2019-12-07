//Two strings are considered ¡°almost equivalent¡± if they have the same length AND for each lowercase letter
//
//, the number of occurrences of in the two strings differs by no more than 3. You are given two string arrays, and
//
//
//pair of strings.They are of equal length and consist of lowercase English letters.For each pair of strings, determine if they are almost equivalent.





#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
* Complete the 'areAlmostEquivalent' function below.
*
* The function is expected to return a STRING_ARRAY.
* The function accepts following parameters:
*  1. STRING_ARRAY s
*  2. STRING_ARRAY t
*/

vector<string> areAlmostEquivalent(vector<string> s, vector<string> t) {

	vector<string> result;

	for (int strIdx = 0; strIdx < s.size(); strIdx++) {
		int countAlpa_s[27] = { 0, };
		int countAlpa_t[27] = { 0, };

		for (int charIdx = 0; charIdx < s[strIdx].size(); charIdx++)
			countAlpa_s[s[strIdx][charIdx] - 'a']++;

		for (int charIdx = 0; charIdx < t[strIdx].size(); charIdx++)
			countAlpa_t[t[strIdx][charIdx] - 'a']++;

		int alpaIdx = 0;
		for (; alpaIdx< 26; alpaIdx++)
			if (abs(countAlpa_s[alpaIdx] - countAlpa_t[alpaIdx]) > 3) break;

		alpaIdx == 26 ? result.push_back("YES") : result.push_back("NO");
	}
	return result;

}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string s_count_temp;
	getline(cin, s_count_temp);

	int s_count = stoi(ltrim(rtrim(s_count_temp)));

	vector<string> s(s_count);

	for (int i = 0; i < s_count; i++) {
		string s_item;
		getline(cin, s_item);

		s[i] = s_item;
	}

	string t_count_temp;
	getline(cin, t_count_temp);

	int t_count = stoi(ltrim(rtrim(t_count_temp)));

	vector<string> t(t_count);

	for (int i = 0; i < t_count; i++) {
		string t_item;
		getline(cin, t_item);

		t[i] = t_item;
	}

	vector<string> result = areAlmostEquivalent(s, t);

	for (int i = 0; i < result.size(); i++) {
		fout << result[i];

		if (i != result.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";

	fout.close();

	return 0;
}

string ltrim(const string &str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string &str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}
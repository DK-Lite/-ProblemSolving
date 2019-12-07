//
//수요가 급증하는 동안 전기 회사는 수요를 충족시키기 위해 발전기를 활성화했습니다.이제 수요가 지나갔으므로 발전기의 절반 이상을 차단해야합니다.특정 모델의 모든 발전기는 유사하며 단일 장치로 제어 할 수 있습니다.발전기의 절반 이상을 비활성화하는 데 필요한 최소 모델 수를 찾으십시오.
//
//n 개의 생성기가있는 경우 n / 2 생성기의 천장을 비활성화해야합니다(부동 소수점 값이 다음으로 높은 정수로 반올림되면 천장이 표시됩니다(예 : ceiling(3 / 2) = ceiling(1.5) = 2)). .
//


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
* Complete the 'reduceCapacity' function below.
*
* The function is expected to return an INTEGER.
* The function accepts INTEGER_ARRAY model as parameter.
*/

int reduceCapacity(vector<int> model) {

	priority_queue<int, vector<int>, less<int> > maxHip;

	int deactNum = (model.size() + 1) / 2;

	int countGen[1000001] = { 0, };
	for (int i = 0; i< model.size(); i++) countGen[model[i]]++;

	for (int i = 0; i< 1000001; i++)
		if (countGen[i]>0) maxHip.push(countGen[i]);

	int result = 0;
	while (deactNum > 0) {
		deactNum -= maxHip.top();
		maxHip.pop();
		result++;
	}

	return result;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string model_count_temp;
	getline(cin, model_count_temp);

	int model_count = stoi(ltrim(rtrim(model_count_temp)));

	vector<int> model(model_count);

	for (int i = 0; i < model_count; i++) {
		string model_item_temp;
		getline(cin, model_item_temp);

		int model_item = stoi(ltrim(rtrim(model_item_temp)));

		model[i] = model_item;
	}

	int result = reduceCapacity(model);

	fout << result << "\n";

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

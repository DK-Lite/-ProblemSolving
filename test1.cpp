//
//���䰡 �����ϴ� ���� ���� ȸ��� ���並 ������Ű�� ���� �����⸦ Ȱ��ȭ�߽��ϴ�.���� ���䰡 ���������Ƿ� �������� ���� �̻��� �����ؾ��մϴ�.Ư�� ���� ��� ������� �����ϸ� ���� ��ġ�� ���� �� �� �ֽ��ϴ�.�������� ���� �̻��� ��Ȱ��ȭ�ϴ� �� �ʿ��� �ּ� �� ���� ã���ʽÿ�.
//
//n ���� �����Ⱑ�ִ� ��� n / 2 �������� õ���� ��Ȱ��ȭ�ؾ��մϴ�(�ε� �Ҽ��� ���� �������� ���� ������ �ݿø��Ǹ� õ���� ǥ�õ˴ϴ�(�� : ceiling(3 / 2) = ceiling(1.5) = 2)). .
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

#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> tmp;


void tostring(vector<int> numbers)
{
	tmp.resize(numbers.size());
	for(size_t i = 0 ; i < numbers.size(); ++i)
		tmp[i] = to_string(numbers[i]);
}

bool comp(string a, string b)
{
	return (a + b > b + a);
}

void sorting()
{
	sort(tmp.begin(), tmp.end(), comp);
}

string solution(vector<int> numbers)
{
	string answer = "";

	tostring(numbers);
	sorting();
	for(auto& i : tmp)
		answer += i;
	if (answer[0] == '0')
		return "0";
	return answer;
}
//3, 30, 34, 5, 9
int main()
{
	vector<int> numbers;
	numbers.push_back(110);
	numbers.push_back(0);
	numbers.push_back(0);
	numbers.push_back(0);
	numbers.push_back(1);

	std::cout << solution(numbers);
}

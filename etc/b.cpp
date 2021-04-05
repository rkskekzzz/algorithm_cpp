#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <vector>

std::vector<int> result;
std::vector<int> visited;
std::regex upper_case_expression{ "[A-Z]" };
std::regex lower_case_expression{ "[a-z]" };
std::regex number_expression{ "[0-9]" };
std::regex special_char_expression{ "[~!@#$%^&*]" };
int upper_case, lower_case, number_case, special_char;
int low_cnt, upp_cnt, num_cnt, spe_cnt, cnt, same_cnt;
char save;

std::vector<int> solution(std::string password);

int main()
{
	std::string str = "AaTa+!12-3";
	std::string str2 = "aaaaZZZZ)";
	std::string str3 = "CaCbCgCdC888834A";
	std::string str4 = "UUUUU";
	std::string str5 = "ZzZz9Z824";


	solution(str);
	std::cout << "1 result : ";
	std::sort(result.begin(), result.end());
	for (auto &i : result)
		std::cout << i << " ";
	std::cout << std::endl;
	result.clear();
	solution(str2);
	std::cout << "2 result : ";
	std::sort(result.begin(), result.end());
	for (auto &i : result)
		std::cout << i << " ";
	result.clear();
	std::cout << std::endl;
	solution(str3);
	std::cout << "3 result : ";
	std::sort(result.begin(), result.end());
	for (auto &i : result)
		std::cout << i << " ";
	result.clear();
	std::cout << std::endl;
	solution(str4);
	std::cout << "4 result : ";
	std::sort(result.begin(), result.end());
	for (auto &i : result)
		std::cout << i << " ";
	result.clear();
	std::cout << std::endl;
	solution(str5);
	std::cout << "5 result : ";
	std::sort(result.begin(), result.end()]\


	for (auto &i : result)
		std::cout << i << " ";
}

std::vector<int> solution(std::string password)
{
	visited = std::vector(6, 0);
	if (password.size() < 8 || password.size() > 15)
		result.push_back(1);
	int sum;
	upp_cnt = 0 ; low_cnt = 0; num_cnt = 0; spe_cnt = 0;
	for (size_t i = 0; i < password.size(); ++i)
	{
		sum = 0; same_cnt = 0;
		std::string reg_test(1, password[i]);
		upper_case = std::regex_search(reg_test, upper_case_expression);
		lower_case = std::regex_search(reg_test, lower_case_expression);
		number_case = std::regex_search(reg_test, number_expression);
		special_char = std::regex_search(reg_test, special_char_expression);
		sum = upper_case + lower_case + number_case + special_char;
		upp_cnt += upper_case; low_cnt += lower_case; num_cnt += number_case; spe_cnt += special_char;
		if (sum == 0 && !visited[2])
		{
			result.push_back(2);
			visited[2] = 1;
		}
		if (i > 1 && password[i] == password[i - 1])
			++cnt;
		else
			cnt = 0;
		if (cnt >= 3)
			result.push_back(4);
		for (size_t j = 0; j < password.size(); ++j)
			if (password[i] == password[j])
				++same_cnt;

		if (same_cnt >= 5 && !visited[5])
		{
			result.push_back(5);
			visited[5] = 1;
		}
	}
	if (((upp_cnt > 0) + (low_cnt > 0) + (num_cnt > 0) + (spe_cnt > 0)) < 3)
		result.push_back(3);
	if(result.size() == 0)
		result.push_back(0);
	return (result);
}

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<int> sum_result;
std::vector<std::string> job_result;
std::vector<std::vector<std::string>> parsed_table;
int max;

std::string solution(std::vector<std::string> table,
					 std::vector<std::string> languages,
					 std::vector<int> preference);
void split(std::vector<std::string> table);
void output();

int main()
{

	std::vector<std::string> str = { "SI JAVA JAVASCRIPT SQL PYTHON C#",
									 "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++",
									 "HARDWARE C C++ PYTHON JAVA JAVASCRIPT",
									 "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP",
									 "GAME C++ C# JAVASCRIPT C JAVA" };
	std::vector<std::string> languages = {"JAVA", "JAVASCRIPT"};
	std::vector<int> preference = {7, 5};
	std::cout << "문자열" << solution(str, languages, preference) << std::endl;
	return 0;
}

bool comp(std::string s1, std::string s2){
	return s1 < s2;
}

std::string solution(std::vector<std::string> table,
					 std::vector<std::string> languages,
					 std::vector<int> preference)
{
	parsed_table.resize(5);
	sum_result.resize(5);
	split(table);

	for (int k = 0 ; k < 5 ; ++k)
	{
		for (int i = 0; i < 5; ++i)
		{
			for (size_t j = 0 ; j < languages.size(); ++j)
			{
				if (parsed_table[k][i + 1] == languages[j])
				{
					std::cout << "l ; " << languages[j] << ", p : " << preference[j] << ", i : "<< 5 - i << std::endl;
					sum_result[k] += (5 - i) * preference[j];
				}
			}
		}
	}
	std::cout << "sum_result : ";
	for (auto& i : sum_result)
		std::cout << i << " ";
	std::cout << std::endl;
	for (size_t i = 0 ; i < sum_result.size() ; ++i)
	{
		if (max < sum_result[i])
			max = sum_result[i];
	}
	for (size_t i = 0 ; i < sum_result.size() ; ++i)
	{
		if (max == sum_result[i])
			job_result.push_back(parsed_table[i][0]);
	}
	std::sort(job_result.begin(), job_result.end(), comp);
	return (job_result[0]);
}

void split(std::vector<std::string> table)
{
	int idx = 0;

	for (auto &str : table)
	{
		std::istringstream ss(str);
		std::string stringBuffer;

		parsed_table[idx].clear();
		while (getline(ss, stringBuffer, ' '))
			parsed_table[idx].push_back(stringBuffer);

		std::cout << "문자열 : ";
		for (size_t i = 0; i < parsed_table[idx].size(); i++)
			std::cout << parsed_table[idx][i] << " ";
		std::cout << std::endl;
		++idx;
	}
}

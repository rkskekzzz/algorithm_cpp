#include <deque>
#include <iostream>
#include <string>
#include <vector>

std::string str;
std::string res;
std::deque<char> deq;
void output()
{
	std::cout << res;
}

void solution()
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (str[i] == '<')
		{
			while (str[i] != '>')
			{
				res += str[i];
				++i;
			}
			res += str[i];
		}
		else
		{
			while (str[i] != '<' && str[i] != ' ' && i < str.size())
			{
				deq.push_front(str[i]);
				++i;
			}
			while (!deq.empty())
			{
				res += deq.front();
				deq.pop_front();
			}
			if (str[i] == ' ')
				res += str[i];
			if (str[i] == '<')
				--i;
		}
		deq.clear();
	}
	while (!deq.empty())
	{
		res += deq.front();
		deq.pop_front();
	}
}

void input()
{
	getline(std::cin, str);
	res = "";
}

void preset()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

int main()
{
	preset();
	input();
	solution();
	output();
}

#include <iostream>
#include <stack>

std::string str;
std::stack<char> res;
std::stack<char> tmp;

int N;

void output()
{
	if (res.empty())
		return;
	char c = res.top();
	res.pop();
	output();
	std::cout << c;
}

void solution()
{
	char c;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> c;
		if (c == 'P')
		{
			std::cin >> c;
			res.push(c);
		}
		else if (c == 'B' && !res.empty())
		{
			res.pop();
		}
		else if (c == 'L' && !res.empty())
		{
			tmp.push(res.top());
			res.pop();
		}
		else if (c == 'D' && !tmp.empty())
		{
			res.push(tmp.top());
			tmp.pop();
		}
	}
	while (!tmp.empty())
	{
		res.push(tmp.top());
		tmp.pop();
	}
}

void input()
{
	std::cin >> str;
	std::cin >> N;
	for (size_t i = 0; i < str.size(); ++i)
		res.push(str[i]);
}

void preset()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int main()
{
	preset();
	input();
	solution();
	output();
}

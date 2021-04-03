#include <iostream>
#include <stack>
#include <vector>

std::vector<int> arr;
std::stack<int> stk;
std::string out;
int N;

void output()
{
	if (!stk.empty())
		std::cout << "NO";
	else
	{
		for (size_t i = 0; i < out.size(); ++i)
			std::cout << out[i] << '\n';
	}
}

void solution()
{
	int idx = 0;

	for (int i = 1; i <= N; ++i)
	{
		stk.push(i);
		out += "+";
		while (!stk.empty())
		{
			if (stk.top() == arr[idx])
			{
				stk.pop();
				out += "-";
				++idx;
			}
			else
				break;
		}
	}
}

void input()
{
	std::cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; ++i)
		std::cin >> arr[i];
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

#include <iostream>
#include <vector>
#include <algorithm>

int N, M, result, max;
std::vector<int> money;

void output()
{
	std::cout << result;
}

void solution()
{
	auto left = *std::max_element(money.begin(), money.end()), right = max;

	while (left <= right)
	{
		auto mid = (left + right) / 2;
		auto sum = 0, cnt = 1;

		// std::cout << "mid : " << mid << std::endl;
		for(auto& i : money)
		{
			if(sum  + i > mid)
			{
				sum = 0;
				++cnt;
			}
			sum += i;
		}
		if (cnt <= M)
			right = mid - 1;
		else
			left = mid + 1;
	}
	result = left;
}

void input()
{
	std::cin >> N >> M;
	money.resize(N);
	for(auto& i : money)
	{
		std::cin >> i;
		max += i;
	}
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

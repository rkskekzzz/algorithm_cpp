#include <iostream>
#include <vector>

int N, M, result;
std::vector<int> money;

void output()
{
	std::cout << result;
}

void solution()
{
	int left = 0, right = *std::max_element(money.begin(), money.end());
	int sum = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;


	}
}

void input()
{
	std::cin >> N >> M;
	money.resize(N);
	for(auto& i : money)
		std::cin >> i;
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

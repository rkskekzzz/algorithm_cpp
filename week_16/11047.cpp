#include <iostream>
#include <vector>

int N, K, result;
std::vector<int> arr;

void output()
{
	std::cout << result;
}

void solution()
{
	for(int i = N - 1 ; i >= 0 ; --i)
	{
		if(arr[i] > K)
			continue;
		int cnt = K / arr[i];
		K = K - cnt * arr[i];
		result += cnt;
	}
}

void input()
{
	int money;

	std::cin >> N >> K;
	for(int i = 0 ; i < N ; ++i)
	{
		std::cin >> money;
		arr.push_back(money);
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

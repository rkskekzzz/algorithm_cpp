
#include <iostream>
#include <vector>
#include <algorithm>

int N, M, result;
std::vector<int> arr;

void output()
{
	std::cout << result;
}

void solution()
{
	int start = 0, end = 0, sum = 0;

	for(;;)
	{
		if (sum >= M)
		{
			sum -= arr[start];
			++start;
		}
		else if (end == N)
			break;
		else
		{
			sum += arr[end];
			++end;
		}

		if (sum == M)
			++result;
	}
}

void input()
{
	std::cin >> N >> M;
	arr.resize(N);
	for(auto& i : arr)
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

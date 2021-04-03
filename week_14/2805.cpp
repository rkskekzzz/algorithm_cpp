#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> arr;
std::string out;
int N, M;
long long sum;
int result;

void output()
{
	std::cout << result;
}

void solution()
{
	long long left = 0;
	long long mid;
	long long right = *std::max_element(arr.begin(), arr.end());

	while (left <= right)
	{
		sum = 0;
		mid = (left + right) >> 1;
		for (auto& i : arr)
			if (i > mid)
				sum += i - mid;
		if (sum < M)
			right = mid - 1;
		else if (sum >= M)
			left = mid + 1;
	}
	result = right;
}

void input()
{
	std::cin >> N >> M;
	arr.resize(N);
	for (auto& i : arr)
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

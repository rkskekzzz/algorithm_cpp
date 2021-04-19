#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> city;
int money, N, max;



void solution()
{
	int left = 0, right = max;


	while(left <= right)
	{
		int sum = 0;
		int mid = (left + right) / 2;

		for(int i = 0 ; i < N ; ++i)
		{
			sum += std::min(city[i], mid);
		}
		if (sum > money)
			right = mid - 1;
		else
			left = mid + 1;
	}
	std::cout << right;
}

void input()
{
	int n;

	std::cin >> N;
	for(int i = 0 ; i < N ; ++i)
	{
		std::cin >> n;
		city.push_back(n);
		max = std::max(max, n);
	}
	std::cin >> money;
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
}

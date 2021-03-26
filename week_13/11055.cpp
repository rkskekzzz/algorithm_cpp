// 11055 번

#include <algorithm>
#include <iostream>
#include <vector>


int N;
std::vector<int> arr;
std::vector<int> dp;

void output()
{
	std::cout << *std::max_element(dp.begin(), dp.end());
}

void solution()
{
	for(int i = 1 ; i < N ; i++)
		for(int j = 0; j < i ; j++)
			if (arr[j] < arr[i])
				if(dp[i] < dp[j] + arr[i])
					dp[i] = dp[j] + arr[i];
}

void input()
{
	std::cin >> N;
	arr.resize(N);
	dp.resize(N);
	for(auto& i : arr)
		std::cin >> i;
	dp = arr;
}

void preset()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int main(void)
{
	preset();
	input();
	solution();
	output();
}
/*

1 100 2 50 60 3 5  6 7 8
1 101 101 101 113 113 113 113 113

*/

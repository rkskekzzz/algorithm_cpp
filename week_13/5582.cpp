// 5582 번

#include <algorithm>
#include <iostream>
#include <vector>

int max;
std::string a;
std::string b;
std::vector<std::vector<int> > dp;

void output()
{
	std::cout << max;
}

void solution()
{
	for (size_t i = 1 ; i < a.size() ; i++)
	{
		for(size_t j = 1 ; j < b.size() ; j++)
		{
			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
		}
		if (max < *std::max_element(dp[i].begin(), dp[i].end()))
			max = *std::max_element(dp[i].begin(), dp[i].end());
	}
}

void input()
{
	std::cin >> a >> b;
	a = "0" + a;
	b = "0" + b;
	dp = std::vector(a.size(), std::vector(b.size(), 0));
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

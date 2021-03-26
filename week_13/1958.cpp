// 9251 번

#include <algorithm>
#include <iostream>
#include <vector>

int max;
std::string str0;
std::string str1;
std::string str2;
std::vector<std::vector<std::vector<int>>> dp;

void output()
{
	std::cout << dp[str2.size()][str1.size()][str0.size()] << '\n';
}

void solution()

{
	for (size_t k = 1; k <= str2.size() ; k++)
	{
		for (size_t i = 1; i <= str1.size() ; i++)
		{
			for (size_t j = 1; j <= str0.size() ; j++)
			{
				if ( str2[k - 1] == str1[i - 1] && str1[i - 1] == str0[j - 1])
					dp[k][i][j] = dp[k - 1][i - 1][j - 1] + 1;
				else
					dp[k][i][j] = std::max({dp[k - 1][i][j], dp[k][i - 1][j], dp[k][i][j - 1]});
			}
		}
	}
}

void input()
{
	std::cin >> str0;
	std::cin >> str1;
	std::cin >> str2;
	dp = std::vector(str2.size() + 1,
					 std::vector(str1.size() + 1, std::vector(str0.size() + 1, 0)));
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

// 9251 번

#include <iostream>
#include <vector>
#include <algorithm>

int max;
std::string org;
std::string cmp;
std::vector<std::vector<int> > dp;

void output()
{
	std::cout << dp[cmp.size()][org.size()] << '\n';
}

void dfs(int x, int y)
{
	if (x <= 0 || y <= 0 || dp[x][y] == 0)
		return ;
	if (dp[x][y] == dp[x][y - 1])
		dfs(x, y - 1);
	else if (dp[x][y] == dp[x - 1][y])
		dfs(x - 1, y);
	else
	{
		dfs(x - 1, y - 1);
		// std::cout << "x : " << x << '\n';
		// std::cout << "y : " << y << '\n';
		std::cout << cmp[x - 1];
	}
}

void solution()
{
	for(size_t i = 1 ; i <= cmp.size() ; i++)
	{
		for (size_t j = 1 ; j <= org.size() ; j++)
		{
			if(cmp[i - 1] == org[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	// 	std::cout << "for test\n";
	// for(size_t i = 0 ; i <= cmp.size() ; i++)
	// {
	// 	for (size_t j = 0 ; j <= org.size() ; j++)
	// 	{
	// 		std::cout << dp[i][j] <<" ";
	// 	}
	// 	std::cout << "\n";
	// }
}

void input()
{
	std::cin >> org;
	std::cin >> cmp;
	dp = std::vector(cmp.size() + 1, std::vector(org.size() + 1, 0));
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
	dfs(cmp.size(), org.size());
}

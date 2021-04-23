#include <iostream>
#include <vector>

int N, K, result;
std::vector<std::vector<int> > dp;

void output()
{
	// for(auto& i : dp)
	// {
	// 	for(auto& j : i)
	// 		std::cout << j << " ";
	// 	std::cout << std::endl;
	// }
	std::cout << dp[N][K];
}

// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// 1 5 10 10 5 1
void solution()
{
	for(int i = 2 ; i <= N ; ++i)
	{
		for(int j = 1 ; j < i ; ++j)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
		}
	}
}

void input()
{
	std::cin >> N >> K;
	dp = std::vector(N + 1, std::vector(N + 1, 1));
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

#include <iostream>
#include <vector>

std::vector<std::vector<int> > dp;
int N;

void output()
{
	std::cout << dp[N - 1][9];
}

void solution()
{
	for(int i = 0 ; i < N ; ++i)
		for(int j = 1 ; j < 10 ; ++j)
			dp[i][j] = ((i == 0 ? 1 : dp[i -1][j]) + dp[i][j - 1]) % 10007;
}

void input()
{
	std::cin >> N;
	dp = std::vector(N, std::vector(10, 1));
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

#include <iostream>

int N;
int dp[1002][11];
int ans;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> N;
}

int logic(int index, int value)
{
	if (dp[index][value])
		return (dp[index][value]);
	int cnt = 0;
	if (index == N - 1) // last
		return (10 - value);
	for (int i = 9 ; i >= value ; i--)
	{
		 cnt += logic(index + 1, i);
		 if (cnt >= 10007)
			 cnt %= 10007;
		 dp[index][i] = cnt; // dp 업데이트
	}
	return (cnt);
}

void solve()
{
	ans = logic(0, 0) % 10007;
}

void print_val()
{
	std::cout << ans;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

#include <iostream>

int N, M;
bool A[51][51];
bool B[51][51];
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
	std::string tmp;
	std::cin >> N >> M;
	for (int i = 1 ; i <= N ; i++)
	{
		std::cin >> tmp;
		for (int j = 1 ; j <= tmp.size(); j++)
			A[i][j] = tmp[j - 1] - '0';
	}
	for (int i = 1 ; i <= N ; i++)
	{
		std::cin >> tmp;
		for (int j = 1 ; j <= tmp.size(); j++)
			B[i][j] = tmp[j - 1] - '0';
	}
	ans = 0;
}

bool is_equal()
{
	for (int i = 1 ; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (A[i][j] != B[i][j])
				return (0);
	return (1);
}

void flip(int i, int j)
{
	for (int x = 0 ; x < 3 ; x++)
	{
		for (int y = 0 ; y < 3 ; y++)
		{
			if (A[i + x][j + y])
				A[i + x][j + y] = 0;
			else
				A[i + x][j + y] = 1;
		}
	}
}

void solve()
{
	for (int i = 1 ; i <= N ; i++)
	{
		for (int j = 1 ; j <= M ; j++)
		{
			if (i + 2 > N || j + 2 > M)
				break;
			if (A[i][j] != B[i][j])
			{
				flip(i, j);
				ans++;
			}
		}
	}
	if (!is_equal())
		ans = -1;
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

#include <iostream>
#include <queue>
#include <vector>
#include <string>

std::vector<std::vector<int> > arr;
std::vector<std::vector<int> > result;
std::string dx, dy, rdx, rdy;


int N, M, R;

void output()
{
	for (auto& i : result)
	{
		for (auto& j : i)
			std::cout << j << " ";
		std::cout << '\n';
	}
}

void rotate(int x, int y, int n, int m, int r)
{
	if (n < 2 || m < 2)
		return;
	int _x = x, _y = y;
	int _rx, _ry;
	int size = (n + m - 2) * 2;
	int mv, rmv;
	for (int i = 0 ; i < size ; ++i)
	{
		_rx = _x;
		_ry = _y;
		for (int _r = 0 ; _r < (r % size) ; ++_r)
		{
			int j = (size - (i - _r)) % size;
			rmv = ((j % (n + m - 2) > (n - 2)) + 2 * (j / (n + m - 2)));
			_rx += rdx[rmv] - '1';
			_ry += rdy[rmv] - '1';
		}
		result[_rx][_ry] = arr[_x][_y];
		mv = ((i % (n + m - 2) > (m - 2)) + 2 * (i / (n + m - 2)));
		_x += dx[mv] - '1';
		_y += dy[mv] - '1';
	}
	rotate(x + 1, y + 1, n - 2, m - 2, r);

}

void solution()
{
	rotate(0, 0, N, M, R);
}

void input()
{
	std::cin >> N >> M >> R;
	arr.resize(N);
	for(auto& i : arr)
		i.resize(M);
	result.resize(N);
	for(auto& i : result)
		i.resize(M);
	for (auto& i : arr)
		for (auto& j : i)
			std::cin >> j;
	dx = "1210";
	dy = "2101";
	rdx = "2101";
	rdy = "1210";
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


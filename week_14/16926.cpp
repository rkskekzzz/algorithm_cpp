#include <iostream>
#include <queue>
#include <vector>
#include <string>

std::vector<std::vector<int> > arr;
std::string dx;
std::string dy;

int N, M, R;

void output()
{
	for (auto& i : arr)
	{
		for (auto& j : i)
			std::cout << j << " ";
		std::cout << '\n';
	}
}

void rotate(int x, int y, int n, int m, int r)
{
	std::vector<int> tmp;
	if (n < 2 || m < 2)
		return;
	int _x = x, _y = y;
	int size = (n + m - 2) * 2;
	int mv;
	for (int i = 0 ; i < size ; ++i)
	{
		tmp.push_back(arr[_x][_y]);
		mv = ((i % (n + m - 2) > (m - 2)) + 2 * (i / (n + m - 2)));
		_x += dx[mv] - '1';
		_y += dy[mv] - '1';
	}
	_x = x, _y = y;
	for(int i = 0 ; i < size ; ++i)
	{
		arr[_x][_y] = tmp[(i + r) % size];
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
	for (auto& i : arr)
		for (auto& j : i)
			std::cin >> j;
	dx = "1210";
	dy = "2101";
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



// void solution()
// {
// 	int ndx = 0;
// 	int mdx = 0;
// 	int ndx_r = N - 1;
// 	int mdx_r = M - 1;

// 	for (int i = 0 ; i < R ; ++i)
// 	{
// 		while (mdx < mdx_r && ndx < ndx_r)
// 		{
// 			int left_top = arr[ndx][mdx];
// 			int right_down = arr[ndx_r][mdx_r];
// 			std::cout << "lt : " << left_top << ", rd : " << right_down << std::endl;

// 			++ndx; ++mdx;
// 			--ndx_r; --mdx_r;
// 		}
// 	}
// }

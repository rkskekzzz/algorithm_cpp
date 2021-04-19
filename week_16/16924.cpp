#include <iostream>
#include <vector>

std::string s;
std::vector<std::string> map;
int N, M;

void input()
{
	std::cin >> N >>  M;
	map.resize(N);
	for(int i = 0 ; i < N ; ++i)
	{
		std::cin >> s;
		map.push_back(s);
	}
	//for(auto i : map)
	//	std::cout << i << std::endl;
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
}

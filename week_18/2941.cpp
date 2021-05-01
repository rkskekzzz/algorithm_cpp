#include <iostream>
#include <string>
#include <vector>
#include <cstring>

std::string str;
int result;

void output()
{
	std::cout << result;
}

void solution()
{
	size_t isize = str.size();
	std::vector<std::string> com = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

	for(size_t i = 0 ; i < isize ;++i)
	{
		for(size_t j = 0 ; j < com.size() ; ++j)
		{
			size_t jsize = com[j].size();
			if(i + jsize <= isize && str.substr(i, jsize) == com[j])
			{
				i += jsize - 1;
				break;
			}
		}
		++result;
	}
}

void input()
{
	std::cin >> str;
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

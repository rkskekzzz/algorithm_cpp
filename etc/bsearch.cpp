#include <iostream>
#include <vector>

// std::vector<int> arr;

int bsearch(std::vector<int> arr, int val)
{
	int left = 0;
	int right = arr.size();

	while (left <= right)
	{
		int mid = (left + right) >> 1;

		if (arr[mid] == val)
			return (true);
		if (mid < val)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (false);
}

int main()
{
	std::cout << bsearch({1,2,3,6,7,8}, 1) << std::endl;
	std::cout << bsearch({1,2,3,6,7,8}, 2) << std::endl;
	std::cout << bsearch({1,2,3,6,7,8}, 4) << std::endl;
	std::cout << bsearch({1,2,3,6,7,8}, 5) << std::endl;
	std::cout << bsearch({1,2,3,6,7,8}, 6) << std::endl;
}

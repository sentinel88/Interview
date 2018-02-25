#include <iostream>
#include <unordered_set>
#include <cmath>

using intPair = std::pair<int, int>;

void
findPair (int arr[], int size, intPair &Pair, int sum)
{
	std::unordered_set<int> HashTable;

	for (int i = 0; i < size; i++)
	{
		if (HashTable.find(arr[i]) == HashTable.end())
		{
			HashTable.insert(arr[i]);
		}
		if (HashTable.find(abs(sum - arr[i])) != HashTable.end())
		{
			Pair.first = arr[i];
			Pair.second = abs(sum - arr[i]);
			break;
		}
	}
}

int
main (int argc, char *argv[])
{
	int arr[] = {1, 10, 2, 9, 3, 8, 4, 7, 5, 6};
	int sum;
	intPair Pair(0, 0);
	int size = sizeof(arr) / sizeof(arr[0]);

	std::cout << "\nEnter the sum for which you want to search a pair in the array\n" << std::endl;
	std::cin >>sum;
	findPair(arr, size, Pair, sum);
	std::cout << "\nThe pairs are: " << Pair.first << ", " << Pair.second << std::endl;

	return 0;
}

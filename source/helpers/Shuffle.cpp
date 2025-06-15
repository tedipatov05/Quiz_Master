#include "../../headers/helpers/Shuffle.h"

void shuffle(Vector<int>& numbers)
{
	int n = (int)numbers.size();
	for (int i = n - 1; i > 0; --i) {
		int j = rand() % (i + 1);
		std::swap(numbers[i], numbers[j]);
	}
}
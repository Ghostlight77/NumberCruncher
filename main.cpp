#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

void display_int(int num){
	cout << num << ' ';
}

int main()
{
	cout << "The Number Cruncher Program\n\n";

	vector<int> numbers;
	numbers.reserve(11);

	srand(time(nullptr));

	for (int i = 0; i < numbers.capacity(); i++)
	{
		int number = rand() % 30;
		numbers.push_back(number);
	}

	cout << numbers.size() << " Random Numbers: ";
	for_each(numbers.begin(), numbers.end(), display_int);
	cout << endl;

	sort(numbers.begin(), numbers.end());
	cout << numbers.size() << " Sorted Numbers: ";
	for_each(numbers.begin(), numbers.end(), display_int);
	cout << endl;

	int sum = accumulate(numbers.begin(), numbers.end(), 0);
	cout << "Sum = " << sum << " | ";

        int avg = sum / numbers.size();
        cout << "Average = " << avg << " | ";


	auto maxIter = max_element(numbers.begin(), numbers.end());
	cout << "Max = " << *maxIter << " | ";


        auto minIter = min_element(numbers.begin(), numbers.end());
        cout << "Min = " << *minIter;

        int num = 10;
        bool numExists = binary_search(numbers.begin(), numbers.end(), num);

        if (numExists)
        {
		int c = count(numbers.begin(), numbers.end(), num);
		cout << "\n\nThe number " << num << " occurs " << c << " time(s).\n";
        }
        else
        {
		cout << "\n\nThese numbers do NOT include " << num << ".\n\n";
        }
}

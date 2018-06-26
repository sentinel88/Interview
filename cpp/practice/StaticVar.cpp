#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Test
{
	public:
		static int count;
		Test();
	private:
		T val;
};

template <typename T>
Test<T>::Test()
{
	count++;
}

template <typename T>
int Test<T>::count = 0;

int
main (int argc, char *argv[])
{
	Test<int> a;
	Test<int> b;
	Test<double> c;
		
	cout <<"Number of integers is " << Test<int>::count <<endl;
	cout <<"Number of double values are " << Test<double>::count <<endl;

	return 0;
}

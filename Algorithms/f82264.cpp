//EXAM 2 - STOYAN LUPOV F82264
#include <iostream>
#include<iomanip>
#include <cmath>
using namespace std;

// Only integer types allowed for this class
template <typename T>
class Triangle
{
public:
	Triangle()
	{
		arr = new T[3];
	}

	~Triangle()
	{
		cout << "Destructor called!" << endl;
		delete arr;
	}

	//Copy constructor
	Triangle(const Triangle<T>& b)
	{
		cout << "Copy constructor!" << endl;
		copy(b);
	}

	double getArea()
	{
		double p = getPerimeter() / 2;
		return sqrt(p * (p - arr[0]) * (p - arr[1]) * (p - arr[2]));
	}

	double getPerimeter()
	{
		return arr[0] + arr[1] + arr[2];
	}

	void copy(const Triangle<T>& t);
	void print(ostream& out) const;

	Triangle& operator++(int dummy);
	Triangle& operator--(int dummy);
	Triangle<T>& operator=(const Triangle<T>& q);

	T& operator[](int subscript);
	T operator[](int subscript) const;

	bool canBuild();
private:
	T* arr;
};

template <typename T>
void Triangle<T>::copy(const Triangle<T>& t)
{
	arr = new T[3];

	for (int i = 0; i < 3; ++i)
	{
		arr[i] = t.arr[i];
	}
}

template <typename T>
void Triangle<T>::print(ostream& out) const
{
	for (int i = 0; i < 3; ++i)
	{
		out << arr[i] << " ";
	}
}

template <typename T>
Triangle<T>& Triangle<T>::operator++(int dummy)
{
	for (int i = 0; i < 3; ++i)
	{
		++arr[i];
	}

	return *this;
}

template <typename T>
Triangle<T>& Triangle<T>::operator--(int dummy)
{
	for (int i = 0; i < 3; ++i)
	{
		--arr[i];
	}

	return *this;
}

template <typename T>
Triangle<T>& Triangle<T>::operator=(const Triangle<T>& t)
{
	copy(t);
	return *this;
}


//return modifiable value
template <typename T>
T& Triangle<T>::operator[](int subscript)
{
	if (subscript < 0 || subscript >= 3)
		throw out_of_range("Subscript out of range");
	return arr[subscript];
}

//overloaded subscript operator for const Arrays
//const reference return creates an rvalue
template <typename T>
T Triangle<T>::operator[](int subscript) const
{
	if (subscript < 0 || subscript >= 3)
		throw out_of_range("Subscript out of range");
	return arr[subscript]; //returns copy of the element
}

template <typename T>
bool Triangle<T>::canBuild()
{
	//check if there are negative sides in input
	for (int i = 0; i < 3; ++i)
	{
		if (arr[i] < 0)
		{
			return false;
		}
	}

	T a = arr[0];
	T b = arr[1];
	T c = arr[2];

	if (a + b > c && a + c > b && b + c > a)
	{
		return true;
	}

	for (int i = 0; i < 3; ++i)
	{
		arr[i] = 1;
	}
	return false;
}

template <typename T>
ostream& operator<<(ostream& out, const Triangle<T>& t)
{
	t.print(out);
	return out;
}

template <typename T>
istream& operator>>(istream& in, Triangle<T>& t)
{
	for (int i = 0; i < 3; ++i)
	{
		in >> t[i];
	}

	if (!t.canBuild())
	{
		cout << "No such triangle exists. Constructing equilateral triangle with all sides equal to 1" << endl;
	}
	return in;
}

template <typename T>
bool operator||(Triangle<T>& a, Triangle<T>& b)
{
	for (int i = 0; i < 3; ++i)
	{
		if (a[i] == b[i])
		{
			return false;
		}
	}

	return true;
}

template <typename T>
bool operator==(Triangle<T>& a, Triangle<T>& b)
{
	double ratio = a[0] / a[1];

	for (int i = 1; i < 3; ++i)
	{
		if (a[i] / b[i] != ratio)
		{
			return false;
		}
	}

	return true;
}

//can be class function
template <typename T>
bool operator<(Triangle<T>& a, Triangle<T>& b)
{
	if (a.getArea() < b.getArea())
	{
		return true;
	}

	return false;
}

template <typename T>
bool operator>(Triangle<T>& a, Triangle<T>& b)
{
	if (a.getArea() > b.getArea())
	{
		return true;
	}

	return false;
}

template <typename T>
Triangle<T>& operator*(Triangle<T>& a, T x)
{
	Triangle<T> newT = a;

	for (int i = 0; i < 3; ++i)
	{
		newT[i] = newT[i] * x;
	}

	return newT;
}

int main()
{
	Triangle<int> a;
	cin >> a;
	cout << "First element a[0]: " << a[1] << endl << endl;

	Triangle<int> copy;
	copy = a;
	copy[0] = 10;

	cout << "Original: " << a << endl;
	cout << "Copy: " << copy << endl << endl;

	cout << "a || copy -> " << boolalpha << (a || copy) << endl;
	cout << "a == copy -> SIMILAR -> " << (a == copy) << endl;
	cout << "a > copy " << (a > copy) << endl;
	cout << "a < copy " << (a < copy) << endl;

	Triangle<int> copyConstructed(a);
	cout << "Copy Constructed: " << copyConstructed << endl << endl;

	
	return 0;
}

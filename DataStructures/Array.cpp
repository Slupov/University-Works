#include <iostream>
using namespace std;

#pragma region Solution
template <typename T>
class ArrayIterator;

template <typename T>
class Array
{
private:
	size_t arrSize; //ptr-based array arrSize
	T* ptr;
public:
	typedef ArrayIterator<T> iterator;
	friend class ArrayIterator<T>;

	Array(const int& arraySize = 0); //set all members of array with arraySize to NULL
	Array(const Array& other);
	~Array(); //destructor
	int size() const; //return size

	const Array& operator=(const Array& other);
	bool operator==(const Array& other) const;
	bool operator!=(const Array& other) const;
	T& operator[](int); //returns modifiable lvalue
	T operator[](int) const; //returns non-modifiable rvalue

	void print(ostream& out);
	void input(istream& in);

	iterator begin();
	iterator end();
};

#pragma region Array
//default constructor for class Array
template <typename T>
Array<T>::Array(const int& arraySize) :
	arrSize(arraySize > 0 ? arraySize : throw invalid_argument("Array arrSize must be greater than 0")), ptr(new T[arrSize])
{
	for (size_t i = 0; i < arrSize; ++i)
		ptr[i] = NULL; //undefined value
}

template <typename T>
Array<T>::Array(const Array<T>& arrayToCopy) : arrSize(arrayToCopy.arrSize), ptr(new T[arrSize])
{
	for (size_t i = 0; i < arrSize; ++i)
		//copy each member of arrayToCopy into object
		ptr[i] = arrayToCopy.ptr[i];
}

template <typename T>
Array<T>::~Array<T>()
{
	delete[] ptr;
}

//return number of elements of array
template <typename T>
int Array<T>::size() const
{
	return arrSize;
}

template <typename T>
const Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (other != this) //avoid self-assignment
	{
		//for arrays of different arrSizes, deallocate original
		//left-side Array, then allocate new left-arrSize Array
		if (arrSize != other.arrSize)
		{
			delete[] ptr;
			arrSize = other.arrSize;
			ptr = new T[arrSize];
		}
		for (size_t i = 0; i < arrSize; ++i)
			ptr[i] = other.ptr[i];
	}

	return *this;
}


//determine if two Arrays are equal and return true, otherwise return false
template <typename T>
bool Array<T>::operator==(const Array<T>& other) const
{
	if (arrSize != other.arrSize)
		return false;
	for (size_t i = 0; i < arrSize; i++)
		if (ptr[i] != other.ptr[i])
			return false; //Array contents not equal
	return true; //Array contents are equal
}

//determine if two Arrays are not equal, and return true, otherwise return false
template <typename T>
bool Array<T>::operator!=(const Array<T>& other) const
{
	return !(this == other);
}

//return modifiable lvalue
template <typename T>
T& Array<T>::operator[](int subscript)
{
	//check for out-of-range error
	if (subscript < 0 || subscript >= arrSize)
		throw out_of_range("Subscript out of range");
	return ptr[subscript];
}

//overloaded subscript operator for const Arrays
//const reference return creates an rvalue
template <typename T>
T Array<T>::operator[](int subscript) const
{
	if (subscript < 0 || subscript >= arrSize)
		throw out_of_range("Subscript out of range");
	return ptr[subscript]; //returns copy of the element
}

template <typename T>
void Array<T>::print(ostream& out)
{
	//output private ptr-based array
	for (size_t i = 0; i < arrSize; i++)
	{
		if (i != 0)
		{
			out << " " << ptr[i];
		}
		else
		{
			out << ptr[i];
		}
	}
}

template <typename T>
void Array<T>::input(istream& in)
{
	//output private ptr-based array
	for (size_t i = 0; i < arrSize; i++)
		in >> ptr[i];
}

template <typename T>
typename Array<T>::iterator Array<T>::begin()
{
	//ptr is int !! should be iterator
	ArrayIterator<T> iter(ptr);
	return iter;
}

template <typename T>
typename Array<T>::iterator Array<T>::end()
{
	ArrayIterator<T> iter(ptr + arrSize);
	return iter;
}
#pragma endregion

template <typename T>
class ArrayIterator
{
private:
	T* pointer;
public:
	ArrayIterator(T* address)
	{
		pointer = address;
	}

	friend class Array<T>;
	bool operator==(const ArrayIterator<T>& other) const;
	bool operator!=(const ArrayIterator<T>& other) const;
	T& operator*() const;
	ArrayIterator<T>& operator++();
};

template <typename T>
bool ArrayIterator<T>::operator==(const ArrayIterator<T>& other) const
{
	return this->pointer == other.pointer;
}

template <typename T>
bool ArrayIterator<T>::operator!=(const ArrayIterator<T>& other) const
{
	return !(*this == other);
}

template <typename T>
T& ArrayIterator<T>::operator*() const
{
	return *pointer;
}

template <typename T>
ArrayIterator<T>& ArrayIterator<T>::operator++()
{
	ArrayIterator<T> i = *this;
	++pointer;
	return i;
}

template <typename T>
ostream &operator<<(ostream &out, Array<T> &arr)
{
	arr.print(out);
	return out;
}

template <typename T>
istream &operator>>(istream &in, Array<T> &arr)
{
	arr.input(in);
	return in;
}
#pragma endregion

//code here
template <typename T>
void print2(Array<T> array)
{
	for (int i = 0; i < array.size(); ++i)
	{
		array[i] *= array[i];
	}
	cout << "2: " << array << endl;
}

int main()
{
	int n;
	cin >> n;
	Array<int> arr(n);

//	for (int i = 0; i < n; i++)
//		cin >> arr[i];

	cin >> arr;

	cout << "arr: " << arr << endl;

	Array<int> copy = arr;

	for (Array<int>::iterator it = copy.begin(); it != copy.end(); ++it)
	{
		*it = *it + 1000;
	}

	cout << "copy: " << copy << endl;

	print2(arr);

	cout << "arr: " << arr << endl;

	return 0;
}
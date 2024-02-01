#include<vector>
#include<numeric>

template <typename T>
T largest_element(std::vector<T> vect)
{
	T max_element = std::numeric_limits<T>::min();
	for (auto v : vect)
	{
		if (v >= max_element)
			max_element = v;
	}
	return max_element;
}

template <typename T>
T is_sorted(std::vector<T> vect)
{

	for (int i{ 0 }; i < vect.size() - 1; ++i)
	{
		if (vect[i] > vect[i + 1])
			return false;
	}
	return true;
}

// linear search
template <typename T>
int find(std::vector<T> vect, T key)
{
	for (int i{ 0 }; i < vect.size(); ++i)
	{
		if (key == vect[i])
		{
			return i;
		}
	}
	return std::numeric_limits<int>::max();
}

//left rotate an array by one place
template <typename T>
void left_rotate(std::vector<T>& vect)
{
	T temp = vect[0];
	for (int i{ 0 }; i < vect.size() - 1; ++i)
	{
		vect[i] = vect[i + 1];
	}

	vect[vect.size() - 1] = temp;
}

template <typename T>
int largest_run(std::vector<T>& vect, int key)
{
	int count{ 0 }; int max_count{ 0 };
	for (int i{ 0 }; i < vect.size()-1; ++i)
	{
		if (vect[i + 1] == vect[i] && vect[i] == 1)
			++count;
		else
			count = 0;

		if (count >= max_count)
			max_count = count;
	}

	return max_count;
}

template <typename T>
void move_zeroes_to_end(std::vector<T>& A)
{
	if (A.size() == 1)
		return;

	for (int j{ 0 }; j < A.size(); ++j)
	{

		if (A[j] == 0)
			continue;

		int key = A[j];
		int k{};
		for (k = j - 1; k >= 0; --k)
		{
			if (A[k] != 0)
				break;
		}

		//Swap key with A[k+1]
		A[j] = A[k + 1];
		A[k + 1] = key;
	}
}

//Rotate k places to the right
template <typename T>
void rotate(std::vector<T>& A, int k) {
	std::vector<T> B{ A };
	for (int i = 0; i < A.size(); ++i)
	{
		B[(i + k) % A.size()] = A[i];
	}
	A = B;
}

//Print the array
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vect)
{
	for (auto v : vect)
	{
		out << v;
	}
	return out;
}
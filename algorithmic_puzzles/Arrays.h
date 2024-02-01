#include<vector>
#include<numeric>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

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

/*
* https://leetcode.com/problems/remove-duplicates-from-sorted-array/
* 
* Given an integer array nums sorted in non - decreasing order, remove 
the duplicates in - place such that each unique element appears only once.
The relative order of the elements should be kept the same.
Then return the number of unique elements in nums.
*/
int removeDuplicates(std::vector<int>& nums)
{
	std::set<int> s{};
	for (int v : nums)
	{
		s.insert(s.end(), v);
	}

	nums = {};
	int count{ 0 };
	for(int element: s)
	{ 
		nums.push_back(element);
		++count;
	}
	return count;
}

/*
* https://leetcode.com/problems/missing-number/
* 
* Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array. 
*/

int missingNumber(std::vector<int>& nums) {
	int n{ static_cast<int>(nums.size()) };

	for (int i{ 0 }; i <= n; ++i)
	{
		if (std::find(nums.begin(), nums.end(), i) == nums.end())
		{
			return i;
		}
	}
	return -1;
}

/*
* https://leetcode.com/problems/single-number/
*/
int singleNumber(std::vector<int>& nums) {
	std::map <int, int> numsCount{};
	for (auto v : nums)
	{
		++numsCount[v];
	}

	for (auto& v : numsCount)
	{
		if (v.second == 1)
			return v.first;
	}
	return -1;
}

/*https://leetcode.com/problems/two-sum/description/
*/

std::vector<int> twoSum(std::vector<int>& nums, int target) {
	int i{}, j{};
	std::vector<int> result{};
	for (i = 0; i < nums.size(); ++i)
	{
		for (j = 0; j < i; ++j)
		{
			//cout << "i : " << i << ", j:" << j << "\n";
			if (nums[i] + nums[j] == target)
			{

				result.push_back(i);
				result.push_back(j);
				return result;
			}
		}
	}

	return result;
}

/* Subsequences of an array.
* 
https://leetcode.com/problems/distinct-subsequences/description/

*/

void f1(int i, vector<int> ds, vector<int>& arr, vector<vector<int>>& results)
{
	if (i >= arr.size())
	{
		results.push_back(ds);
		return;
	}

	ds.push_back(arr[i]);
	f1(i + 1, ds, arr, results);
	ds.pop_back();
	f1(i + 1, ds, arr, results);
}

void all_subsequences(vector<int>& arr, vector<vector<int>>& results)
{
	vector<int> ds{};
	f1(0, ds, arr, results);
}

/* All subsequences that sum to k
*/

void f2(int i, vector<int> ds, vector<int> arr, vector<vector<int>>& results, int target, int sum)
{
	if (i >= arr.size())
	{
		if (sum == target)
		{
			results.push_back(ds);
		}
		return;
	}

	sum += arr[i];
	ds.push_back(arr[i]);
	f2(i + 1, ds, arr, results, target, sum);
	sum -= arr[i];
	ds.pop_back();
	f2(i + 1, ds, arr, results, target, sum);
}
void subsequences_sum_to_k(vector<int>& arr, vector<vector<int>>& results, int target)
{
	vector<int> ds{}; int sum{ 0 };
	f2(0, ds, arr, results, target, sum);
}

void merge(vector<int>& A, int p, int mid, int q)
{
	//Merge two sorted lists.
	int i{ p }, j{ mid + 1 };
	vector<int> result;

	while (i <= mid && j <= q)
	{
		if (A[i] < A[j])
		{
			result.push_back(A[i]);
			++i;
		}
		else
		{
			result.push_back(A[j]);
			++j;
		}
	}

	while (i <= mid)
	{
		result.push_back(A[i]);
		++i;
	}

	while (j <= q)
	{
		result.push_back(A[j]);
		++j;
	}

	for (int k{ p }, l{ 0 }; k <= q; ++k, ++l)
	{
		A[k] = result[l];
	}
}

void mergeSort(vector<int>& A, int p, int q)
{
	if (p >= q)
		return;

	int mid = (p + q) / 2;

	mergeSort(A, p, mid);
	mergeSort(A, mid + 1, q);
	merge(A, p, mid, q);
}

int func(vector<int>& A, int low, int high)
{
	int pivot{A[low]}, j{low}, k{high};

	while (j < k)
	{
		while (j <= high - 1 && A[j] <= pivot)
			j++;

		while (k >= low + 1 && A[k] > pivot )
			k--;

		if (j < k)
		{
			int temp = A[j];
			A[j] = A[k];
			A[k] = temp;
		}
		
		
	}

	//Swap pivot with A[j]
	int temp = A[low];
	A[low] = A[j];
	A[j] = temp;

	return j;
}

void qs(vector<int>& A, int low, int high) {
	if (low < high)
	{
		int pIndex = func(A, low, high);
		qs(A, low, pIndex - 1);
		qs(A, pIndex + 1, high);
	}
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
// Data structure
// Comparing between time complexity between using linear search and binary search for insertion sort



#include <iostream>
#include <cstdio> 
#include <ctime>

using namespace std;

void insertionSort_original(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) 
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

//Binary search function to find the right position of insertion
//recursive function
int binarySearch(int arr[], int key, int first, int last)
{
	if (last <= first)
		if ( key > arr[first]) return (first + 1);
		else return first;

	int mid = (first + last) / 2;

	if (key == arr[mid])
		return mid + 1;

	if (key > arr[mid])
		return binarySearch(arr, key, mid + 1, last);
	return binarySearch(arr, key, first, mid - 1);
}

void insertionSort(int arr[], int n)
{
	int i, location, j, k, selected;

	for (i = 1; i < n; ++i)
	{
		j = i - 1;
		selected = arr[i];

		// find location where selected sould be inseretd 
		location = binarySearch(arr, selected, 0, j);

		// Move all elements after location to create space 
		while (j >= location)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = selected;
	}
}

void printArr (int arr[], int n)
{
	cout<<"Sorted array: \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl << endl;
}


int main()
{
	const clock_t begin_time_linear = clock();

	///Insertion sort using linear search 
	int arr1[] = { 12, 11, 10, 100, 34, 13, 5, 90, 55, 6 };
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	
	insertionSort_original(arr1, n1);
	
	cout << "Original Insertion Sort: \n";
	printArr(arr1, n1);

	float time_linear = float(clock() - begin_time_linear) / CLOCKS_PER_SEC;
	cout << "\nTime consumed using linear search: " << time_linear << endl;


	
	const clock_t begin_time_binary = clock();

	///Insertion sort using binary search
	int arr2[] = { 37, 22, 73, 92, 12, 172, 321,
		56, 101, 80, 23 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	
	insertionSort(arr2, n2);
	
	cout << "Binary Insertion Sort: \n";
	printArr(arr2, n2);


	float time_binary = float(clock() - begin_time_binary)/ CLOCKS_PER_SEC ; 
	cout << "\nTime consumed using Binary search: " << time_binary<< endl;


	return 0;

}

#include <iostream>

using namespace std;




class Algo {
    public:
		static void mergeSort(int arr[], const int length)
		{
			if (length>2) {
				mergeSort(arr, 0, length-1);
			}
		}

		static void mergeSort(float arr[], const int length)
		{
			if (length > 2) {
				mergeSort(arr, 0, length-1);
			}
		}

		static void mergeSort(unsigned int arr[], const int length)
		{
			if (length > 2) {
				mergeSort(arr, 0, length-1);
			}
		}

		static void mergeSort(double arr[], const int length)
		{
			if (length > 2) {
				mergeSort(arr, 0, length-1);
			}
		}

		static void mergeSort(long arr[], const int length)
		{
			if (length > 2) {
				mergeSort(arr, 0, length-1);
			}
		}

		static void mergeSort(long long arr[], const int length)
		{
			if (length > 2) {
				mergeSort(arr, 0, length-1);
			}
		}

		template<typename T>
        static void mergeSort(T arr[], const int start, const int end)
	    {
		    if (start < end) {
			    int mid = start + (end - start) / 2;

			    mergeSort(arr, start, mid);
			    mergeSort(arr, mid + 1, end);

			    merge(arr, start, mid, end);
		    }
	    }

		template<typename T>
		static void printArray(T arr[],unsigned int arrLength) {
			for (unsigned int i = 0; i < arrLength; i++) {
				cout << arr[i] << endl;
			}
		}

    private:
		template<typename T>
        static void merge(T arr[], const int start, const int mid, const int end)
	    {
		    int i, j, k;
		    int leftSize = mid - start + 1;
		    int rightSize = end - mid;

            int* L = new int[leftSize];
            int* R = new int[rightSize];

		    // split array into 2 subarrays L and R
		    for (i = 0; i < leftSize; i++)
			    L[i] = arr[start + i];
		    for (j = 0; j < rightSize; j++)
			    R[j] = arr[mid + 1 + j];

		    i = 0; // initial index of left subarray
		    j = 0; // initial index of right subarray
		    k = start; // initial index of merged subarray

		    while (i < leftSize && j < rightSize) {
			    if (L[i] <= R[j]) {
				    arr[k] = L[i];
				    i++;
			    }
			    else {
				    arr[k] = R[j];
				    j++;
			    }
			    k++;
		    }
		
		    // copy the rest of the elements if there are any
		    while (i < leftSize) {
			    arr[k] = L[i];
			    i++;
			    k++;
		    }
		    while (j < rightSize) {
			    arr[k] = R[j];
			    j++;
			    k++;
		    }
            delete[] L, R;
	    }

		
};

int* randomIntArr(unsigned int length) {
	int* arr = new int[length];
	for (unsigned int i = 0; i < length; i++) {
		arr[i] = rand();
	}
	return arr;
}

int main()
{
	unsigned int arrLength;

	cout << "how long should your array be?" << endl;

	while (!(cin >> arrLength)) {
		if (cin.eof()) {
			cout << "user terminated input." << endl;
			return 0;
		}
		cout << "please enter a valid integer" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
	}

	cout << "created array with " << arrLength << " items" << endl << endl;

	// create array with n(arrLength) random items
    int* arr = randomIntArr(arrLength);
	Algo::printArray(arr, arrLength);


    Algo::mergeSort(arr, arrLength);
    cout << endl << endl << "sorted array" << endl;
	Algo::printArray(arr, arrLength);


    return 0;
}
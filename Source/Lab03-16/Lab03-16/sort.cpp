#include"sort.h"
#include"dataGenerator.h"
using namespace std;

void selectionSort(int* a, int n, long long& count_comp)
{
	count_comp = 0;
	for (int i = 0; ++count_comp && i < n - 1; i++)
	{

		int min = i;
		for (int j = i + 1; ++count_comp && j < n; j++)
		{
			if (++count_comp && a[j] < a[min])
				min = j;
		}
		HoanVi(a[i], a[min]);
	}
}

void insertionSort(int* a, int n, long long& count_comp)
{
	count_comp = 0;
	int hole, value;
	for (int i = 1; ++count_comp && i < n; i++)
	{
		value = a[i];
		hole = i;
		while (count_comp && hole > 0 && a[hole - 1] > value)
		{
			a[hole] = a[hole - 1];
			hole = hole - 1;
		}
		a[hole] = value;
	}
}

void bubbleSort(int* a, int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				HoanVi(a[j], a[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}

void shakerSort(int* a, int n)
{
	int left = 0;
	int right = n - 1;
	int k = 0;
	while (left < right)
	{
		for (int i = left; i < right; i++)
		{
			if (a[i] > a[i + 1])
			{
				HoanVi(a[i], a[i + 1]);
				k = i;
			}
		}
		right = k;
		for (int i = right; i > left; i--)
		{
			if (a[i] < a[i - 1])
			{
				HoanVi(a[i], a[i - 1]);
				k = i;
			}
		}
		left = k;
	}
}

void shellSort(int* a, int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i += 1)
		{
			int temp = a[i];
			int j;
			for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
				a[j] = a[j - gap];
			a[j] = temp;
		}
	}
}

void heapify(int* a, int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	//if left child is larger than root
	if (left < n && a[left]>a[largest])
		largest = left;

	if (right<n && a[right]>a[largest])
		largest = right;

	if (largest != i)
	{
		HoanVi(a[i], a[largest]);
		heapify(a, n, largest);
	}
}

void heapSort(int* a, int n)
{
	//Build heap
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);

	for (int i = n - 1; i > 0; i--)
	{
		HoanVi(a[0], a[i]);
		heapify(a, i, 0);
	}
}

void merge(int a[], int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0; i < n1; i++)
		L[i] = a[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = a[mid + 1 + j];

	int i = 0;
	int j = 0;
	int k = left;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		a[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int* a, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);

		merge(a, left, mid, right);
	}
}

int partition(int* a, int low, int high)
{
	int pivot = a[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++)
	{
		if (a[j] < pivot)
		{
			i++;
			HoanVi(a[i], a[j]);
		}
	}
	HoanVi(a[i + 1], a[high]);
	return i + 1;
}

void quickSort(int* a, int low, int high)
{
	if (low < high)
	{
		int pIndex = partition(a, low, high);
		quickSort(a, low, pIndex - 1);
		quickSort(a, pIndex + 1, high);
	}
}

void countingSort(int* a, int n)
{
	int* output = new int[n];
	int* count = new int[n + 1];
	int max = a[0];

	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}

	for (int i = 0; i <= max; i++)
		count[i] = 0;

	for (int i = 0; i < n; i++)
		count[a[i]]++;

	for (int i = 1; i <= max; i++)
		count[i] += count[i - 1];

	for (int i = n - 1; i >= 0; i--)
	{
		output[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}

	for (int i = 0; i < n; i++)
		a[i] = output[i];

}

int getMax(int* a, int n)
{
	int max = a[0];
	for (int i = 0; i < n; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}

void countSort(int* a, int n, int exp)
{
	int* output = new int[n];
	int i, count[10] = { 0 };

	for (i = 0; i < n; i++)
		count[(a[i] / exp) % 10]++;


	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(a[i] / exp) % 10] - 1] = a[i];
		count[(a[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		a[i] = output[i];
}

void radixSort(int* a, int n)
{
	int m = getMax(a, n);
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(a, n, exp);
}

void flashSort(int* a, int n)
{
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; i < m; i++)
		l[i] = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < minVal)
			minVal = a[i];
		if (a[i] > a[max])
			max = i;
	}
	if (a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; i < m; i++)
		l[i] += l[i - 1];
	HoanVi(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (nmove < n - 1)
	{
		while (j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (k < 0) break;
		while (j != l[k])
		{
			k = int(c1 * (flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	insertionSort(a, n);
}


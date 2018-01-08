int binarySearch(int a[], int item, int low, int high)
{
	if (high <= low)
		return (item > a[low]) ? (low + 1) : low;

	int mid = (low + high) / 2;

	if (item == a[mid])
		return mid + 1;

	if (item > a[mid])
		return binarySearch(a, item, mid + 1, high);
	return binarySearch(a, item, low, mid - 1);
}

void insertionSort(int a[], int n)
{
	int loc, j, k, selected;

	for (int i = 1; i < n; ++i)
	{
		j = i - 1;
		selected = a[i];

		// find location where selected should be insertеd
		loc = binarySearch(a, selected, 0, j);

		// Shift right all elements after location
		while (j >= loc)
		{
			a[j + 1] = a[j];
			j--;
		}

		a[j + 1] = selected;
	}
}

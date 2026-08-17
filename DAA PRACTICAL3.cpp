#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

// Max Heapify
void maxHeapify(vector<int>& a, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i)
    {
        swap(a[i], a[largest]);
        maxHeapify(a, n, largest);
    }
}

// Max Heap Sort
void maxHeapSort(vector<int>& a)
{
    int n = a.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(a, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        maxHeapify(a, i, 0);
    }
}

// Min Heapify
void minHeapify(vector<int>& a, int n, int i)
{
    int small = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] < a[small])
        small = l;

    if (r < n && a[r] < a[small])
        small = r;

    if (small != i)
    {
        swap(a[i], a[small]);
        minHeapify(a, n, small);
    }
}

// Min Heap Sort
void minHeapSort(vector<int>& a)
{
    int n = a.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(a, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        minHeapify(a, i, 0);
    }

    reverse(a.begin(), a.end());
}

// Print Array
void print(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";

    cout << endl;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> maxArray = a;
    vector<int> minArray = a;

    cout << "\nOriginal Array: ";
    print(a);

    // Max Heap Sort
    auto start1 = high_resolution_clock::now();

    maxHeapSort(maxArray);

    auto end1 = high_resolution_clock::now();

    // Min Heap Sort
    auto start2 = high_resolution_clock::now();

    minHeapSort(minArray);

    auto end2 = high_resolution_clock::now();

    cout << "\nMax Heap Sort:";
    cout << "\nSorted Array: ";
    print(maxArray);

    auto time1 = duration_cast<nanoseconds>(end1 - start1);

    cout << "Time: " << time1.count() << " ns";

    cout << "\n\nMin Heap Sort:";
    cout << "\nSorted Array: ";
    print(minArray);

    auto time2 = duration_cast<nanoseconds>(end2 - start2);

    cout << "Time: " << time2.count() << " ns";

    return 0;
}

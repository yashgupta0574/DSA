for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
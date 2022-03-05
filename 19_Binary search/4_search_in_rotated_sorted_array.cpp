#include <bits/stdc++.h>
using namespace std;

int search_in_rotated_and_sorted_array(int arr[], int key, int left, int right)
{
    if (left > right)
    {
        return -1;
    }
    int mid = (left + right) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }
    if (arr[left] < arr[mid])
    {
        if (key >= arr[left] && key < arr[mid])
        {
            return search_in_rotated_and_sorted_array(arr, key, left, mid - 1);
        }
        return search_in_rotated_and_sorted_array(arr, key, mid + 1, right);
    }
    else
    {
        if (key > arr[mid] && key <= arr[right])
        {
            return search_in_rotated_and_sorted_array(arr, key, mid + 1, right);
        }
        return search_in_rotated_and_sorted_array(arr, key, left, mid - 1);
    }
}

int main()
{
    int arr[] = {5, 7, 9, 11, 15, 20, 25, 2, 4};
    cout << search_in_rotated_and_sorted_array(arr, 5, 0, 8) << endl;
    cout << search_in_rotated_and_sorted_array(arr, 7, 0, 8) << endl;
    cout << search_in_rotated_and_sorted_array(arr, 9, 0, 8) << endl;
    cout << search_in_rotated_and_sorted_array(arr, 11, 0, 8) << endl;
    cout << search_in_rotated_and_sorted_array(arr, 15, 0, 8) << endl;
    cout << search_in_rotated_and_sorted_array(arr, 20, 0, 8) << endl;
    cout << search_in_rotated_and_sorted_array(arr, 25, 0, 8) << endl;
    cout << search_in_rotated_and_sorted_array(arr, 2, 0, 8) << endl;
    cout << search_in_rotated_and_sorted_array(arr, 4, 0, 8) << endl;

    return 0;
}
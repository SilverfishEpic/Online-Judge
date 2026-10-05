#include <iostream>
#include <vector>
using namespace std;

long long merge_count(vector<int>& a, vector<int>& tmp,
                      int left, int right)
{
    if (right - left <= 1)
        return 0;

    int mid = (left + right) / 2;

    long long count = 0;

    count += merge_count(a, tmp, left, mid);
    count += merge_count(a, tmp, mid, right);

    int i = left;
    int j = mid;
    int k = left;

    while (i < mid && j < right)
    {
        if (a[i] <= a[j])
        {
            tmp[k++] = a[i++];
        }
        else
        {
            tmp[k++] = a[j++];

            count += mid - i;
        }
    }

    while (i < mid)
        tmp[k++] = a[i++];

    while (j < right)
        tmp[k++] = a[j++];

    for (int p = left; p < right; ++p)
        a[p] = tmp[p];

    return count;
}

int main()
{
    int N;
    cin >> N;

    while (N--)
    {
        int L;
        cin >> L;

        vector<int> train(L);
        for (auto& x : train)
            cin >> x;

        vector<int> tmp(L);

        long long swaps =
            merge_count(train, tmp, 0, L);

        cout << "Optimal train swapping takes "
             << swaps
             << " swaps.\n";
    }
}
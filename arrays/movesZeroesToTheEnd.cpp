#include <bits/stdc++.h>
using namespace std;

void moveZeroesToTheEnd(vector<int> &nums)
{
    int fill_index = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            nums[fill_index] = nums[i];
            fill_index++;
        }
    }

    while (fill_index < n)
    {
        nums[fill_index] = 0;
        fill_index++;
    }
}

int main()
{
    vector<int> nums = {1, 4, 5, 2};
    int n = nums.size();
    moveZeroesToTheEnd(nums);

    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";

    return 0;
}
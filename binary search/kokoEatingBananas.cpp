// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

// Example 1:

// Input: piles = [3,6,7,11], h = 8
// Output: 4
// Example 2:

// Input: piles = [30,11,23,4,20], h = 5
// Output: 30
// Example 3:

// Input: piles = [30,11,23,4,20], h = 6
// Output: 23


// Constraints:

// 1 <= piles.length <= 104
// piles.length <= h <= 109
// 1 <= piles[i] <= 109

#include<bits/stdc++.h>

using namespace std;

int calcHours(vector<int> &piles, int speed) {
    int ans = 0, remaining = 0;

    for(int i = 0; i < piles.size(); i++) {
        if(remaining + piles[i] <= speed) {
            ans++;
        }

        else {
            remaining += (piles[i] - speed);
            ans++;
        }
    }

    while(remaining) {
        ans++;
        remaining -= speed;
    }

    return ans;
}

int eatingSpeed(vector<int> &piles, int h) {
    int high = *max_element(piles.begin(), piles.end());
    int low = 1;
    int mid = 0;
    
    while(low < high) {
        mid = (low + high) / 2;

        int hours = calcHours(piles, mid);

        if(hours == h) return mid;

        if(hours < h) {
            // speed is slow
            low = mid + 1;
        }

        else high = mid - 1;
    }

    return mid;
}

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
}
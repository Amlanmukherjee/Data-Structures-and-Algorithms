#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int>& nums) {
        int maxi = 0, jump = 0, halt = 0;
        if(nums.size() == 1) {
            return 0;
        }
        if(nums[0] == 0 && nums.size() > 1) {
            return -1;
        }
        for(int i=0; i < nums.size()-1; i++) {
            maxi = max(maxi, i+nums[i]);
            // Checking if my max reachable index is greater than or equal to last index or not
            if(maxi >= nums.size()-1) {
                jump++;
                return jump;
            }
            // if we reach halt ... update halt with max reachable index (maxi)
            if(i == halt) {
                halt = maxi;
                jump++;
            }
        }
        if(halt >= nums.size()-1) {
            return jump;
        }
        return -1;
    }

int main() {
    int num, n;
    vector<int> nums;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for(int i=0; i<n; i++) {
        cin >> num;
        nums.push_back(num);
    }
    cout << jump(nums);
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        for (int i = 0; i < asteroids.size(); i++) {            
           if (asteroids[i] <= 0) {
                if(ans.size()==0||ans.back()<0)
                    ans.push_back(asteroids[i]); 
                else {
                    int pre = ans.back();
                    int cur = asteroids[i];
                    if (pre + cur == 0)ans.pop_back();
                    else if (pre + cur > 0)continue;
                    else {
                        ans.back() = cur;
                        while (!check(ans))helper(ans);
                    }
                }
            }
            else {
                ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }
    bool check(vector<int>ans) {
        if (ans.size()<=1)return true;
        if (ans[ans.size() - 1] < 0 && ans[ans.size() - 2] >= 0)return false;
        return true;
    }
    void helper(vector<int>& ans) {
        int pre = ans[ans.size() - 2];
        int cur = ans[ans.size() - 1];
        ans.pop_back();
        if (pre + cur > 0)return;
        else if (pre + cur == 0) { ans.pop_back(); return; }
        else ans.back() = cur;
    }
};

int main() {
    Solution sol;
    vector<int>nums = { 0,5,100,4,-15,0,-5 };
    vector<int>ans = sol.asteroidCollision(nums);
    for (int i : ans)cout << i << "  ";

    return 0;
}
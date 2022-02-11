class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        int XOR = 0;
        for(int &num : nums) XOR ^= num;
        int cnt =0;
        while(XOR){
            if(XOR & 1) break;
            cnt++;
            XOR = XOR>>1;
        }
        
        int XOR1 = 0;
        int XOR2 = 0;
        for(int &num : nums){
            if(num & 1<<cnt) XOR1^=num;
            else XOR2^=num;
        }
        
        ans.push_back(XOR1);
        ans.push_back(XOR2);
        
        return ans;
    }
};

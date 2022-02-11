class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        int ab = a | b;
        int diff = ab ^ c;
        for(int i =0 ; i< 31; i++){
            int mask = 1<<i;
            if(diff & mask)
                ans += (a&mask) == (b&mask) && (c&mask) == 0 ? 2 : 1;
        }
        
        return ans;
    }
};

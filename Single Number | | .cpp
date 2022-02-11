class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
};

//First time number appear -> save it in "ones"

//Second time -> clear "ones" but save it in "twos" for later check

//Third time -> try to save in "ones" but value saved in "twos" clear it.


//int singleNumber(vector<int>& nums) {
 //       int ones = 0, twos = 0;
  //      for(int i = 0; i < nums.size(); i++){
  //          ones = (ones ^ nums[i]) & ~twos;
  //          twos = (twos ^ nums[i]) & ~ones;
  //          cout<<ones<<" "<<twos<<'\n';
  //      }
  //  return ones;
 //   }
//Input : [2,2,2,3]
//Stdout:

//2 0 // 2 is stored in ones
//0 2 // 2 is cleared from ones and stored in twos
//0 0 // third time 2 appears it is erased from both ones and twos
//3 0

// The above solution is not definitely an intuitive approach you need to know this solution 


// The another approaches are obviously sorting and using hash map 

// Another method using bit manipulation is 
// Counting the set bits

class Solution {
public:
    int singleNumber(int arr[], int n) {
        // Initialize result
    int result = 0;
 
    int x, sum;
 
    // Iterate through every bit
    for (int i = 0; i < 32; i++)
    {
      // Find sum of set bits at ith position in all
      // array elements
      sum = 0;
      x = (1 << i);
      for (int j=0; j< n; j++ )
      {
          if (arr[j] & x)
            sum++;
      }
 
 
      // If any element apperas thrice so obviously it will result to 3 set bits or 3 ones and one extra 1 or 0 of the unique element 
      // Now if we have multiple of 3 set bits then obviosly at that bit position our unique element doesnt have any set bit 
      // But if not then definitely our unique element will have set bit at that particular bit position 
      // The bits with sum not multiple of 3, are the
      // bits of element with single occurrence.
      if (sum % 3)
        // This line exactly means that at bit position of result where there are not multiple of 3 set bits are present set a bit in the result
        result |= x;
    }
 
    return result;
    }
};

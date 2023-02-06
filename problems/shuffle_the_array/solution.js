/**
 * @param {number[]} nums
 * @param {number} n
 * @return {number[]}
 */
var shuffle =(nums, n) => (
    nums.map((val,i) => {
        if(i%2){
         return nums[n+(i-1)/2];
        }
        return nums[i/2];
    })
);
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
    var l=0,ans=0;
    while(l<=ans){
       ans=Math.max(ans,l+nums[l]);
       if(ans>=nums.length-1)
       return 1;

       l++;
    }
    return 0;
};
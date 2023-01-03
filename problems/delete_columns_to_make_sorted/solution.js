/**
 * @param {string[]} strs
 * @return {number}
 */
var minDeletionSize = function(strs) {
    var cnt=0;
    const len=strs[0].length

    for(let i=0;i<len;i++) {
        for(let j=0;j<strs.length-1;j++) {
            if(strs[j][i]>strs[j+1][i]) {
               cnt++;
               break;
            }
        }
    }
    return cnt;
};
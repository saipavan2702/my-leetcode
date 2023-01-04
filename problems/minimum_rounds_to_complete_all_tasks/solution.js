/**
 * @param {number[]} tasks
 * @return {number}
 */
var minimumRounds = function(tasks) {
    const hash={};
    for(const t of tasks) {
        hash[t]=hash[t]+1 || 1;
    }
    
    var cnt=0;
    for(let x in hash) {
        if(hash[x]==1)
        return -1;

        cnt+=Math.ceil(hash[x]/3);
    }
    return cnt;
};
/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
    if(n==0)
    return 1;

    if(n<0)
    {
        n=-n;
        x=1/x;
    }
    if(!(n&1))
    return myPow(x*x,n/2);
    else
    return x*myPow(x,n-1);
};
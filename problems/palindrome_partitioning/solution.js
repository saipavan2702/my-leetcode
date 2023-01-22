/**
 * @param {string} s
 * @return {string[][]}
 */
var partition = function(s) {
   let ans=[];
   const n=s.length;
   function recur(x,p) {
       if(x==n){
           ans.push(p);
           return;
       }
       
       for(var i=x;i<n;i++){
           if(check(s,x,i)){
               recur(i+1,[...p,s.slice(x,i+1)]);
            //    p.pop();
           }
       }
       function check(s,l,r){
           while(l<=r){
               if(s[l]!=s[r])
               return 0;

               l++;
               r--;
           }
           return 1;
       }
   }
   recur(0,[]);
   return ans;
};
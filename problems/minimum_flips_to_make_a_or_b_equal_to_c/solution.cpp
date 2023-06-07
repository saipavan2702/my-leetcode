class Solution {
public:
    int minFlips(int a, int b, int c) {
        bitset<32>f(a);
        bitset<32>se(b);
        bitset<32>th(c);

        int cnt=0;
        for(int i=0;i<31;i++){
            if((f[i]|se[i])!=th[i]){

                cout<<f[i]<<se[i]<<th[i]<<endl;

                if(th[i]==0){
                    if(f[i]==1 && se[i]==1)
                    cnt+=2;
                    else 
                    cnt++;
                }
                else
                cnt++;
            }
        }
        return cnt;
    }
};
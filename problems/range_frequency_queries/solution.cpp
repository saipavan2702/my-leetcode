class RangeFreqQuery {
public:
    int n;
    using vu=vector<unordered_map<int,int>>;
    vu seg;

    void build(vector<int>&A, int L, int R, int ind){
        if(L==R){
            seg[ind][A[L]]++;
            return;
        }
        int u=(L+R)/2;
        build(A,L,u,2*ind+1);
        build(A,u+1,R,2*ind+2);

        for(auto &x:seg[2*ind+1]){
            seg[ind][x.first]+=seg[2*ind+1][x.first];
        }

        for(auto &x:seg[2*ind+2]){
            seg[ind][x.first]+=seg[2*ind+2][x.first];
        }

    }

    RangeFreqQuery(vector<int>& A) {
        n=size(A);

        seg.resize(4*n);
        build(A,0,n-1,0);
    }
    
    int query(int left, int right, int value) {
        return Que(0,0,n-1,left,right,value);
    }

    int Que(int ind, int L, int R, int l, int r, int key){
        if(L>=l && R<=r)
        return seg[ind][key];

        if(L>r or R<l)
        return 0;

        int u=(L+R)/2;
        int left=Que(2*ind+1,L,u,l,r,key);
        int right=Que(2*ind+2,u+1,R,l,r,key);

        return left+right;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
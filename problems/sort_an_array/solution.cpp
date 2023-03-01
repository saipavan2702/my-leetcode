class Solution {
public:
    void done(vector<int>&a, int lo, int u, int hi){
        vector<int>T(hi-lo+1);;
        int i(lo),j(u+1);
        int k=0;

        while(i<=u && j<=hi) {

            if(a[i]<=a[j])
            T[k++]=a[i++];
            else
            T[k++]=a[j++];
        }
        while(i<=u)
        T[k++]=a[i++];

        while(j<=hi)
        T[k++]=a[j++];

        for(int l=0;l<k;l++)
        a[lo+l]=T[l];

        
    }
    void Sort(vector<int>&a, int lo, int hi){
        if(lo>=hi)
        return;

        int u=(lo+hi)/2;
        Sort(a,lo,u);
        Sort(a,u+1,hi);
        done(a,lo,u,hi);

    }
    vector<int> sortArray(vector<int>& a) {
        int n=size(a);
        Sort(a,0,n-1);
        return a;
    }
};
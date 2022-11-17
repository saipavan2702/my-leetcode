class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int l1=(abs(ax1-ax2));
        int b1=(abs(ay1-ay2));
        
        int l2=(abs(bx1-bx2));
        int b2=(abs(by1-by2));
        
        if (ax1>=bx2 || ax2<=bx1 || ay2<=by1 || ay1>=by2)
        return l1*b1+l2*b2; 
            
        int l3=abs(min(ax2,bx2)-max(ax1,bx1));
        int b3=abs(min(ay2,by2)-max(ay1,by1));
        
        return l1*b1+l2*b2-(l3*b3);
    }
};
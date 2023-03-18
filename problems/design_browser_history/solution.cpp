class BrowserHistory {
public:
    using vs=vector<string>;
    vs Q;
    int h;

    BrowserHistory(string home) {
        Q.push_back(home);
        h=0;
    }
    
    void visit(string url) {
        cout<<Q[0]<<endl;
        Q.resize(h+1);
        Q.push_back(url);
        h++;
    }
    
    string back(int steps) {
        h=max(0,h-steps);
        return Q[h];
    }
    
    string forward(int steps) {
        int n=size(Q);
        h=min(h+steps,n-1);
        return Q[h];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
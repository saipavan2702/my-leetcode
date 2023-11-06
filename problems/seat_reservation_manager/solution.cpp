class SeatManager {
private:
    int last;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    SeatManager(int n) : last(0) {}

    int reserve() {
        if (pq.empty()) {
            return ++last;
        } else {
            int seat = pq.top();
            pq.pop();
            return seat;
        }
    }

    void unreserve(int seatNumber) {
        if (seatNumber == last) {
            --last;
        } else {
            pq.push(seatNumber);
        }
    }
};
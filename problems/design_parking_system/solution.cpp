class ParkingSystem {
public:
    int a[3];
    ParkingSystem(int big, int med, int small) {
        a[0]=big;
        a[1]=med;
        a[2]=small;
    }
    
    bool addCar(int T) {
        if(T==1){
            if(a[0]>0)
            {a[0]--;return 1;}
            else return 0;
        }else if(T==2){
            if(a[1]>0)
            {a[1]--;return 1;}
            else return 0;
        }else{
            if(a[2]>0)
            {a[2]--;return 1;}
            else return 0;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
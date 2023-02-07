class ParkingSystem {
public:
    int b;int m;int s;
    ParkingSystem(int big, int medium, int small) {
        b=big+1;
        m=medium+1;
        s=small+1;
    }
    
    bool addCar(int carType) {
        if(carType==1){
            b--;
            if(b>0){
                return true;
            }
            else{
                return false;
            }
        }
        else if(carType==2){
            m--;
            if(m>0){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            s--;
            if(s>0){
                return true;
            }
            else{
                return false;
            }
        }
        
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
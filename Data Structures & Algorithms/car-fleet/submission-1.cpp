class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cars;

        for(int i = 0;i< position.size();i++){
            int pos = position[i];
            double timeTaken = (double)(target-position[i])/speed[i];
            cars.push_back({pos, timeTaken});
        }
        sort(cars.rbegin(), cars.rend());
        int fleets = 0;
        double currFleetTime = 0;
        for(int i = 0;i< cars.size();i++){
            // int carPos = timeTaken[i].first;
            double timeTakenCurr = cars[i].second;

            if(timeTakenCurr> currFleetTime){
                fleets++;
                currFleetTime = timeTakenCurr;
            }

        }
        return fleets;
    }
};

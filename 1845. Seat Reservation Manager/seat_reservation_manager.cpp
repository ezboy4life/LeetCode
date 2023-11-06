#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class SeatManager {
private:
    vector<pair<int,bool>> seats;   /* seatnumber - isReserved */
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            seats.push_back({i, false});
        }
    }
    
    int reserve() {
        for (int i = 0; i < seats.size(); i++) {
            if (!seats[i].second) {
                seats[i].second = true;
                return seats[i].first;
            }
        }
    }
    
    void unreserve(int seatNumber) {
        seats[seatNumber - 1].second = false;
    }
};

/*
--- Testes ---
*/

int main() {
    SeatManager* sm = new SeatManager(5);
    sm->reserve();
    sm->reserve();
    sm->unreserve(2);
    sm->reserve();
    sm->reserve();
    sm->reserve();
    sm->reserve();
    sm->unreserve(5);



    system("pause");
    return 0;
}

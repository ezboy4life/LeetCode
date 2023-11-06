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
        
    }
};

/*
--- Testes ---
*/

int main() {

    system("pause");
    return 0;
}

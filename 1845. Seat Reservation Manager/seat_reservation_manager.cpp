#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> seats;
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            seats.push(i);
        }
    }
    
    int reserve() {
        int seatNumber = seats.top();
        seats.pop();
        return seatNumber;
    }
    
    void unreserve(int seatNumber) {
        seats.push(seatNumber);
    }
};

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

/*
    A solução passada que eu havia utilizado na função "reserve()" não era performática o suficiente, visto que ela iterava sobre todo o vetor
    de bancos reservados pra achar o menor valor que estava liberado. O ideal é usar a estrutura de dados min_heap, que faz com que a reserva
    dos bancos fique bem mais eficiente visto que sempre o topo da estrutura min_heap é o menor número possível
*/
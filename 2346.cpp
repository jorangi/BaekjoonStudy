#include <iostream>

using namespace std;

class Balloon {
public:
    int number;
    int move;
    Balloon* next;
    Balloon* prev;

    Balloon(int num, int m) {
        number = num;
        move = m;
        next = nullptr;
        prev = nullptr;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    Balloon* head = nullptr;
    Balloon* tail = nullptr;

    for (int i = 1; i <= n; i++) {
        int move;
        cin >> move;
        Balloon* newBalloon = new Balloon(i, move);

        if (i == 1) {
            head = tail = newBalloon;
        } else {
            tail->next = newBalloon;
            newBalloon->prev = tail;
            tail = newBalloon;
        }
    }
    tail->next = head;
    head->prev = tail;

    Balloon* cur = head;
    for (int i = 0; i < n; i++) {
        cout << cur->number << ' ';
        int moveValue = cur->move;

        if (i == n - 1) {
            delete cur;
            break;
        }

        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;

        Balloon* temp = cur;
        if (moveValue > 0) {
            cur = temp->next;
            for (int j = 1; j < moveValue; j++) cur = cur->next;
        } else {
            cur = temp->prev;
            for (int j = 1; j < -moveValue; j++) cur = cur->prev;
        }
        delete temp;
    }

    return 0;
}
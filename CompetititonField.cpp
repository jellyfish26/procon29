//
// Created by jellyfish on 18/10/17.
//
#include <bits/stdc++.h>
using namespace std;

class CompetitionField {
private:
    int field[13][13];
    pair<int, int> myselfAgent1, myselfAgent2;
    pair<int, int> enemyAgent1, enemyAgent2;
    /*
     * When start this project. Initialization field size.
     */
    int filedSizeX, filedSizeY;
public:
    bool initializationFieldSize(int x, int y) {
        if (x > 0 && x <= 12 && y > 0 && y <= 12) {
            filedSizeX = x;
            filedSizeY = y;
            cout << "[complete] Setting of filed size is completed." << endl;
            return true;
        } else {
            cout << "[filed] Could not set field size. Please type it again." << endl;
            return false;
        }
    }


};

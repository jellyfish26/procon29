//
// Created by jellyfish on 18/10/17.
//
#include <bits/stdc++.h>
using namespace std;

class CompetitionField {
private:
    int field[13][13];
    // pair<int, int> is pair<x coordinate, y coordinate>
    pair<int, int> myselfAgent1, myselfAgent2;
    pair<int, int> enemyAgent1, enemyAgent2;
    /*
     * When start this project. Initialization field size.
     */
    int filedSizeX, filedSizeY;

    void initializationAgentCoordinateSettingsDescriptions(string agent) {
        cout << "Please enter the location of " + agent + " . (x coordinate y coordinate)" << endl;
    }

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
    /*
     * Since the explanation of "line symmetry in the horizontal direction or line symmetry in the vertical direction" is ambiguous,
     * ask the agent to input all the positions.
     */
    bool initializationAganetCoordinateSettings() {
        initializationAgentCoordinateSettingsDescriptions("my first agent");
        cin >> myselfAgent1.first >> myselfAgent1.second;
        initializationAgentCoordinateSettingsDescriptions("my second agent");
        cin >> myselfAgent2.first >> myselfAgent2.second;
        initializationAgentCoordinateSettingsDescriptions("enemy first agent");
        cin >> enemyAgent1.first >> enemyAgent1.second;
        initializationAgentCoordinateSettingsDescriptions("enemy second agent");
        cin >> enemyAgent2.first >> enemyAgent2.second;
    }


};

//
// Created by jellyfish on 18/10/17.
//
#include <bits/stdc++.h>
using namespace std;

class CompetitionField {
private:
    int field[13][13];
    bool myselfField[13][13] = {false};
    bool enemyField[13][13] = {false};

    // pair<int, int> is pair<x coordinate, y coordinate>
    pair<int, int> myselfAgent1, myselfAgent2;
    pair<int, int> enemyAgent1, enemyAgent2;
    /*
     * When start this project. Initialization field size.
     */
    int fieldSizeX, fieldSizeY;

    void initializationAgentCoordinateSettingsDescriptions(const string &agent) {
        cout << "Please enter the location of " + agent + " . (x coordinate y coordinate)" << endl;
    }

public:
    void initializationFieldSize() {
        while (true) {
            cout << "Please enter the field size. (vertical length horizontal length)" << endl;
            cin >> fieldSizeX >> fieldSizeY;
            if (fieldSizeX > 0 && fieldSizeX <= 12 && fieldSizeY > 0 && fieldSizeY <= 12) {
                cout << "[complete] Setting of filed size is completed." << endl;
                return;
            } else {
                cout << "[filed] Could not set field size. Please type it again." << endl;
            }
        }
    }
    /*
     * Since the explanation of "line symmetry in the horizontal direction or line symmetry in the vertical direction" is ambiguous,
     * ask the agent to input all the positions.
     */
    void initializationAgentCoordinateSettings() {
        cout << fieldSizeX << " " << fieldSizeY << endl;
        initializationAgentCoordinateSettingsDescriptions("my first agent");
        cin >> myselfAgent1.first >> myselfAgent1.second;
        initializationAgentCoordinateSettingsDescriptions("my second agent");
        cin >> myselfAgent2.first >> myselfAgent2.second;
        initializationAgentCoordinateSettingsDescriptions("enemy first agent");
        cin >> enemyAgent1.first >> enemyAgent1.second;
        initializationAgentCoordinateSettingsDescriptions("enemy second agent");
        cin >> enemyAgent2.first >> enemyAgent2.second;
    }

    void initializationFieldTilesPointSeeings() {
        cout << "Please enter the score of the panel." << endl;
        cout << fieldSizeX << " " << fieldSizeY << endl;
        for (int x = 0; x < fieldSizeX; ++x) {
            for (int y = 0; y < fieldSizeY; ++y) {
                cin >> field[x][y];
            }
        }
    }

};

#include <bits/stdc++.h>
#include "picojson.h"
using namespace std;
int matchTrunNumbers = 40;
int vertical = -1;
int width = -1;
pair<int, int> firstMyAgentPosition;
pair<int, int> secondMyAgentPosition;
pair<int, int> firstEnemyAgentPosition;
pair<int, int> secondEnemyAgentPosition;
int panel[13][13];
bool myAgentGet[13][13];
bool myAgentSurroundGet[13][13];
bool enemyAgentGet[13][13];
bool enemyAgentSurroundGet[13][13];


int main() {
    // Get position information on panels and agents.
    ifstream openJsonFile("/home/jellyfish/CLionProjects/procon29/qr.json");
    if (!openJsonFile) return 1;
    stringstream stringStream;
    stringStream << openJsonFile.rdbuf();
    openJsonFile.close();
    string panelAndAgentPositionInformation(stringStream.str());
    cout << panelAndAgentPositionInformation << endl;

    // json parse
;    picojson::value jsonAfterParseValue;
    string errorCode; // errorCode
    picojson::parse(jsonAfterParseValue, panelAndAgentPositionInformation.begin(), panelAndAgentPositionInformation.end(), &errorCode);
    vertical = stoi(jsonAfterParseValue.get("length").get("width").to_str());
    width = stoi(jsonAfterParseValue.get("length").get("vertical").to_str());
    auto position = jsonAfterParseValue.get("position").get("firstAgentPosition");
    /*
     * x = vertical, y = width
     */
    firstMyAgentPosition = make_pair(vertical - (stoi(position.get("x").to_str())),  stoi(position.get("y").to_str()) - 1);
    position = jsonAfterParseValue.get("position").get("secondAgentPosition");
    secondMyAgentPosition = make_pair(vertical - stoi(position.get("x").to_str()), stoi(position.get("y").to_str()) - 1);
    cout << "vertical = " << vertical << endl;
    cout << "width = " <<  width << endl;
    cout << firstMyAgentPosition.first << " " << firstMyAgentPosition.second << endl;
    cout << secondMyAgentPosition.first << " " << secondMyAgentPosition.second << endl;
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < vertical; ++j) {
            panel[vertical - j - 1][width - i - 1] = stoi(jsonAfterParseValue.get("point").get(i).get(j).to_str());
        }
    }

    for (int i = 0; i < vertical; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << panel[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Please input enemy position" << endl;
    cin >> firstEnemyAgentPosition.first >> firstEnemyAgentPosition.second;
    cin >> secondEnemyAgentPosition.first >> secondEnemyAgentPosition.second;
    cout << firstEnemyAgentPosition.first << " " << firstEnemyAgentPosition.second << endl;
    cout << secondEnemyAgentPosition.first << " " << secondEnemyAgentPosition.second << endl;
    myAgentGet[firstMyAgentPosition.first][firstMyAgentPosition.second] = true;
    myAgentGet[secondMyAgentPosition.first][firstMyAgentPosition.second] = true;
    enemyAgentGet[firstEnemyAgentPosition.first][firstEnemyAgentPosition.second] = true;
    enemyAgentGet[secondEnemyAgentPosition.first][secondEnemyAgentPosition.second] = true;

    for (int i = 0; i < vertical; ++i) {
        for (int j = 0; j < width; ++j) {
            if ((i == firstEnemyAgentPosition.first && j == firstEnemyAgentPosition.second) || (i == secondEnemyAgentPosition.first && j == secondEnemyAgentPosition.second)) {
                cout << "☓ ";
            } else if ((i == firstMyAgentPosition.first && j == firstMyAgentPosition.second) || (i == secondMyAgentPosition.first && j == secondMyAgentPosition.second)) {
                cout << "○ ";
            } else {
                cout << panel[i][j] << " ";
            }
        }
        cout << endl;
    }
}



int myScoreCalclation() {
    int score = 0;
    for (int i = 0; i < vertical; ++i) {
        for (int j = 0; j < width; ++j) {
            if (myAgentGet[i][j]) score += panel[i][j];
        }
    }


}
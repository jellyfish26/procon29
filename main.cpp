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

int myScoreCalculation();
int enemyScoreCalculation();

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

    cout << "myscore = " << myScoreCalculation() << endl;
    cout << "enemyscore = " << enemyScoreCalculation() << endl;
}

void myAgentSurroundedInitalization() {
    for (int i = 0; i < vertical; ++i) {
        for (int j = 0; j < width; ++j) {
            myAgentSurroundGet[i][j] = false;
        }
    }
}

void myAgentNotSurrounded(int x, int y) {
    if (myAgentGet[x][y] || myAgentSurroundGet[x][y]) return;
    myAgentSurroundGet[x][y] = true;
    if (x > 0) myAgentNotSurrounded(x - 1, y);
    if (y > 0) myAgentNotSurrounded(x, y - 1);
    if (x < vertical - 1) myAgentNotSurrounded(x + 1, y);
    if (y < width - 1) myAgentNotSurrounded(x, y + 1);
}

int myScoreCalculation() {
    myAgentSurroundedInitalization();
    int score = 0;
    for (int i = 0; i < vertical; ++i) {
        for (int j = 0; j < width; ++j) {
            if (myAgentGet[i][j]) score += panel[i][j];
        }
    }

    for (int i = 0; i < vertical; ++i) {
        myAgentNotSurrounded(i, 0);
        myAgentNotSurrounded(i, width - 1);
    }

    for (int i = 0; i < width; ++i) {
        myAgentNotSurrounded(0, i);
        myAgentNotSurrounded(vertical - 1, i);
    }

    for (int i = 0; i < vertical; ++i) {
        for (int j = 0; j < width; ++j) {
            if (!myAgentSurroundGet[i][j] && !myAgentGet[i][j]) score += abs(panel[i][j]);
        }
    }

    return score;

}


void enemyAgentSurroundedInitalization() {
    for (int i = 0; i < vertical; ++i) {
        for (int j = 0; j < width; ++j) {
            enemyAgentSurroundGet[i][j] = false;
        }
    }
}

void enemyAgentNotSurrounded(int x, int y) {
    if (enemyAgentGet[x][y] || enemyAgentSurroundGet[x][y]) return;
    enemyAgentSurroundGet[x][y] = true;
    if (x > 0) enemyAgentNotSurrounded(x - 1, y);
    if (y > 0) enemyAgentNotSurrounded(x, y - 1);
    if (x < vertical - 1) enemyAgentNotSurrounded(x + 1, y);
    if (y < width - 1) enemyAgentNotSurrounded(x, y + 1);
}

int enemyScoreCalculation() {
    enemyAgentSurroundedInitalization();
    int score = 0;
    for (int i = 0; i < vertical; ++i) {
        for (int j = 0; j < width; ++j) {
            if (enemyAgentGet[i][j]) score += panel[i][j];
        }
    }

    for (int i = 0; i < vertical; ++i) {
        enemyAgentNotSurrounded(i, 0);
        enemyAgentNotSurrounded(i, width - 1);
    }

    for (int i = 0; i < width; ++i) {
        enemyAgentNotSurrounded(0, i);
        enemyAgentNotSurrounded(vertical - 1, i);
    }

    for (int i = 0; i < vertical; ++i) {
        for (int j = 0; j < width; ++j) {
            if (!enemyAgentSurroundGet[i][j] && !enemyAgentGet[i][j]) score += abs(panel[i][j]);
        }
    }

    return score;

}
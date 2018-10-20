#include <bits/stdc++.h>
#include "CompetititonField.cpp"
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    // Start project. Seeings Competition Filed Size.
    // The first argument is the vertical length, the second argument is the horizontal length.
    auto competitionField = CompetitionField();
    competitionField.initializationFieldSize();
    competitionField.initializationAgentCoordinateSettings();
    competitionField.initializationFieldTilesPointSeeings();
}
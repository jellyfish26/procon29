#include <bits/stdc++.h>
#include "CompetititonField.cpp"
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // Start project. Seeings Competition Filed Size.
    pair<int, int> filedSize;
    cout << "Please enter the field size. (vertical length horizontal length)" << endl;
    cin >> filedSize.first >> filedSize.second;

    // The first argument is the vertical length, the second argument is the horizontal length.
    CompetitionField().initializationFieldSize(filedSize.first, filedSize.second);
    CompetitionField().initializationAganetCoordinateSettings();

}
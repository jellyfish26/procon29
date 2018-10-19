#include <bits/stdc++.h>
#include "CompetititonField.cpp"
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // Start project. Seeings Competition Filed Size.
    pair<int, int> filedSize;
    cin >> filedSize.first >> filedSize.second;
    CompetitionField().initializationFieldSize(filedSize.first, filedSize.second);


}
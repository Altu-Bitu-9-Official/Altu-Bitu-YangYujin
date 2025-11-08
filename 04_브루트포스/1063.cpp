// 킹(구현) https://www.acmicpc.net/problem/1063

#include <iostream>
#include <string>
#include <map>
#include <utility>

//완료

using namespace std;

bool is_valid(int x, int y) {
    return x >= 1 && x <= 8 && y >= 1 && y <= 8;
}

pair<int, int> to_coords(const string& chess_pos) {
    int x = chess_pos[0] - 'A' + 1;
    int y = chess_pos[1] - '0';
    return {x, y};
}

string to_chess_pos(int x, int y) {
    string s = "";
    s += (char)('A' + x - 1);
    s += (char)('0' + y);
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string king_pos_str, stone_pos_str;
    int N;

    map<string, pair<int, int>> dir = {
    {"R",  {1,  0}}, {"L",  {-1, 0}},
    {"B",  {0, -1}}, {"T",  {0,  1}},
    {"RT", {1,  1}}, {"LT", {-1, 1}},
    {"RB", {1, -1}}, {"LB", {-1, -1}}
    };

    cin >> king_pos_str >> stone_pos_str >> N;

    pair<int, int> king_pos = to_coords(king_pos_str);
    pair<int, int> stone_pos = to_coords(stone_pos_str);

    string cmd;

    for (int i = 1; i <= N; i++) {
        cin >> cmd;

        const auto& delta = dir.at(cmd);
        int dx = delta.first;
        int dy = delta.second;

        int next_king_x = king_pos.first + dx;
        int next_king_y = king_pos.second + dy;

        if (!is_valid(next_king_x, next_king_y)) {
            continue;
        }

        if (next_king_x == stone_pos.first && next_king_y == stone_pos.second) {
            int next_stone_x = stone_pos.first + dx;
            int next_stone_y = stone_pos.second + dy;

            if (!is_valid(next_stone_x, next_stone_y)) {
                continue;
            }
            
            stone_pos.first = next_stone_x;
            stone_pos.second = next_stone_y;
        }

        king_pos.first = next_king_x;
        king_pos.second = next_king_y;
    }

    cout << to_chess_pos(king_pos.first, king_pos.second) << '\n';
    cout << to_chess_pos(stone_pos.first, stone_pos.second) << '\n';

    return 0;
}
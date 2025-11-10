#include <iostream>
#include <deque>
#include <string>
#include <vector>

//완료

using namespace std;

void get_cards(deque<int>& win_deck, deque<int>& ground) {
    while (!ground.empty()) {
        win_deck.push_front(ground.front());
        ground.pop_front();
    }
}

string game(int m, deque<int>& dodo, deque<int>& suyeon) {
    deque<int> d_ground, s_ground;
    bool is_dodo_turn = true;

    while (m--) {
        deque<int>& cur_player = is_dodo_turn ? dodo : suyeon;
        deque<int>& cur_ground = is_dodo_turn ? d_ground : s_ground;

        cur_ground.push_back(cur_player.back());
        cur_player.pop_back();

        if (dodo.empty()) return "su";
        if (suyeon.empty()) return "do";

        bool d_exists = !d_ground.empty();
        bool s_exists = !s_ground.empty();

        bool s_rings = d_exists && s_exists && (d_ground.back() + s_ground.back() == 5);
        bool d_rings = !s_rings && ((d_exists && d_ground.back() == 5) || (s_exists && s_ground.back() == 5));

        if (s_rings) {
            get_cards(suyeon, d_ground);
            get_cards(suyeon, s_ground);
        } else if (d_rings) {
            get_cards(dodo, s_ground);
            get_cards(dodo, d_ground);
        }


        is_dodo_turn = !is_dodo_turn;
    }

    if (dodo.size() > suyeon.size()) return "do";
    else if (dodo.size() < suyeon.size()) return "su";
    else return "dosu";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;

    deque<int> dodo(n), suyeon(n);
    for (int i = 0; i < n; i++) {
        cin>>dodo[i]>>suyeon[i];
    }

    cout << game(m,dodo,suyeon) << "\n";

    return 0;
}
// 包装机-queue，stack
// 首先机器中有 N 条轨道，放置了一些物品。
// 轨道下面有一个筐。当某条轨道的按钮被按下时，活塞向左推动，将轨道尽头的一件物品推落筐中。
// 当 0 号按钮被按下时，机械手将抓取筐顶部的一件物品，放到流水线上。
// 一种特殊情况是，因为筐的容量是有限的，当筐已经满了，但仍然有某条轨道的按钮被按下时，系统应强制启动 0 号键，先从筐里抓出一件物品，再将对应轨道的物品推落。
// 此外，如果轨道已经空了，再按对应的按钮不会发生任何事；
// 同样的，如果筐是空的，按 0 号按钮也不会发生任何事。现给定一系列按钮操作，请你依次列出流水线上的物品。

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N, M, Smax;
    cin >> N >> M >> Smax;
    
    vector<vector<char>> tracks(N);
    string line;
    char item;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> item;
            tracks[i].push_back(item);
        }
        reverse(tracks[i].begin(), tracks[i].end());
    }
    
    vector<char> basket;
    vector<char> conveyor;
    int command;
    
    while (true) {
        cin >> command;
        if (command == -1) break;
        
        if (command == 0) {
            if (!basket.empty()) {
				conveyor.push_back(basket.back());
				basket.erase(basket.end() - 1);   
			}
        } else {
            int trackIndex = command - 1;
            if (trackIndex >= 0 && trackIndex < N && !tracks[trackIndex].empty()) {
                if (basket.size() >= Smax) {
				    if (!basket.empty()) {
				        conveyor.push_back(basket.back());
				        basket.erase(basket.end() - 1);
				    }
				}
                basket.push_back(tracks[trackIndex].back());
                tracks[trackIndex].pop_back();
            }
        }
    }
    
    for (char c : conveyor) {
        cout << c;
    }
    cout << endl;
    
    return 0;
}


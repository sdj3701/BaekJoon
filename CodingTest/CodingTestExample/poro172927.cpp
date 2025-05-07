#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// ÇÇ·Îµµ Å×ÀÌºí
int fatigueTable[3][3] = {
    {1, 1, 1},    // ´ÙÀÌ¾Æ °î±ªÀÌ
    {5, 1, 1},    // Ã¶ °î±ªÀÌ
    {25, 5, 1}    // µ¹ °î±ªÀÌ
};

int getMineralIndex(const string& mineral) {
    if (mineral == "diamond") return 0;
    if (mineral == "iron") return 1;
    return 2; // stone
}

void DFS(vector<int>& picks, vector<string>& minerals, int& answer, int currentFatigue, int mineralIndex) {
    // ¸ğµç ±¤¹°À» Äº°Å³ª °î±ªÀÌ°¡ ¾øÀ¸¸é Á¾·á
    if (mineralIndex >= minerals.size() || (picks[0] == 0 && picks[1] == 0 && picks[2] == 0)) {
        answer = min(answer, currentFatigue);
        return;
    }

    // °¢ °î±ªÀÌ Å¸ÀÔ ½Ãµµ
    for (int i = 0; i < 3; i++) {
        if (picks[i] > 0) {
            // °î±ªÀÌ »ç¿ë
            picks[i]--;

            // ÀÌ °î±ªÀÌ·Î ÃÖ´ë 5°³ ±¤¹° Ä³±â
            int newFatigue = currentFatigue;
            for (int j = 0; j < 5 && mineralIndex + j < minerals.size(); j++) {
                int mineralType = getMineralIndex(minerals[mineralIndex + j]);
                newFatigue += fatigueTable[i][mineralType];
            }

            // ´ÙÀ½ ±¤¹° ±×·ìÀ¸·Î ÀÌµ¿ (5°³ ´ÜÀ§)
            DFS(picks, minerals, answer, newFatigue, mineralIndex + 5);

            // ¹éÆ®·¡Å·: °î±ªÀÌ ¹İÈ¯
            picks[i]++;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = INT_MAX;

    DFS(picks, minerals, answer, 0, 0);

    return answer;
}
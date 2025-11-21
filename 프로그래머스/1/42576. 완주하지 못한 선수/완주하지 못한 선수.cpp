#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    for(int i=0; i<participant.size(); i++) {
        if(m.find(participant[i]) != m.end()) {
            m[participant[i]]++;
        }
        else m[participant[i]] = 1;
    }
    
    for(int i=0; i<completion.size(); i++) {
        if(m.find(completion[i]) != m.end()) {
            m[completion[i]]--;
        }
    }
    
    map<string, int>::iterator iter;
    for(iter=m.begin(); iter!=m.end(); iter++) {
        if(iter->second != 0) {
            answer = iter->first;
            break;
        }
    }
    return answer;
}
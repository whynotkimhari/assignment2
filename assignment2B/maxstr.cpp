#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    vector<char> characters, mod3r1s, mod3r2s;
    int sum_s = 0;
    characters.reserve(s.size());

    for(int i = 0; i < s.size(); i++) {
        if((s[i] - '0') % 3 == 1) mod3r1s.push_back(s[i]);
        if((s[i] - '0') % 3 == 2) mod3r2s.push_back(s[i]);
        sum_s = sum_s + (s[i] - '0');
        characters.push_back(s[i]);
    }
    sort(characters.begin(), characters.end(), greater<char>());
    sort(mod3r1s.begin(), mod3r1s.end());
    sort(mod3r2s.begin(), mod3r2s.end());

    if(sum_s % 3 == 0) for(auto x: characters) cout << x;

    else if(sum_s % 3 == 1) {

        if(mod3r1s.size() > 0) {
            char eliminated = mod3r1s[0];
            int num_eliminated = 1;
            for(auto x: characters) {
                if(x == eliminated && num_eliminated > 0) num_eliminated--;
                else if (x != eliminated || num_eliminated == 0) cout << x;
            }
        }

        else {

            if(mod3r2s.size() > 1) {
                char eliminated1 = mod3r2s[0];
                char eliminated2 = mod3r2s[1];
                int num_eliminated = 2;
                for(auto x: characters) {
                    if(x == eliminated1 && num_eliminated > 0) {
                        num_eliminated--;
                        continue;
                    }
                    if(x == eliminated2 && num_eliminated > 0) {
                        num_eliminated--;
                        continue;
                    }
                    if (x != eliminated1 || x != eliminated2 || num_eliminated == 0) cout << x;
                }
            }
            
        }
    }

    else if(sum_s % 3 == 2) {

        if(mod3r2s.size() > 0) {
            char eliminated = mod3r2s[0];
            int num_eliminated = 1;
            for(auto x: characters) {
                if(x == eliminated && num_eliminated > 0) num_eliminated--;
                else if (x != eliminated || num_eliminated == 0) cout << x;
            }
        }
        
        else {
            if(mod3r1s.size() > 1) {
                char eliminated1 = mod3r1s[0];
                char eliminated2 = mod3r1s[1];
                int num_eliminated = 2;
                for(auto x: characters) {
                    if(x == eliminated1 && num_eliminated > 0) {
                        num_eliminated--;
                        continue;
                    }
                    if(x == eliminated2 && num_eliminated > 0) {
                        num_eliminated--;
                        continue;
                    }
                    else if (x != eliminated1 || x != eliminated2 || num_eliminated == 0) cout << x;
                }
            }
        }
    }
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    short n;
    cin >> n;
    vector<int> sections(n);
    vector<int> sections_cpy(n, 0);
    int steps = 0;
    for( short i = 0; i < n; i++ ){
        cin >> sections[i];
    }

    vector<int> sorted_sections = sections;

    sort(sorted_sections.begin(), sorted_sections.end());
    auto it = unique(sorted_sections.begin(), sorted_sections.end());
    sorted_sections.erase(it, sorted_sections.end());

    for(short j = 0; j < sorted_sections.size(); j++){

        for(short i = 0; i < n; i++){
            if(sections_cpy[i] < sorted_sections[j] && sections[i] >= sorted_sections[j]){
                while (sections_cpy[i] < sorted_sections[j] && sections[i] >= sorted_sections[j]){
                    sections_cpy[i] = sorted_sections[j];
                    i++;
                }
                steps++;
            }
            
        }
    }

    cout << steps << endl;
    return 0;
}
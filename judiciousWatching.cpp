#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>

using namespace std;


int main(){
    string T, n, m, q, a, d, l, t;

    cin >> T;
    short test_cases {static_cast<short>(stoi(T))};
    for (short i = 0; i < test_cases; i++){
        cin >> n >> m >> q;
        int num_tasks {stoi(n)};
        int num_episodes {stoi(m)};
        int num_calls {stoi(q)};

        vector<int> tasks(num_tasks);
        vector<int> tasks_limit(num_tasks);
        vector<int> episodes(num_episodes);
        vector<int> calls(num_calls);

        for (int j = 0; j < num_tasks; ++j) {
            cin >> tasks[j];
        }

        for (int k = 0; k < num_tasks; ++k) {
            cin >> tasks_limit[k];
        }

        for (int l = 0; l < num_episodes; ++l) {
            cin >> episodes[l];
        }
        

        for (int o = 0; o < num_calls; ++o) {
            cin >> calls[o];
        }

        // Create a vector of indices to sort both arrays
        vector<int> indices(num_tasks);
        for (int i = 0; i < num_tasks; ++i) {
            indices[i] = i;
        }

        // Sort indices based on the values in tasks_limit
        sort(indices.begin(), indices.end(), [&tasks_limit](int i1, int i2) {
            return tasks_limit[i1] < tasks_limit[i2];
        });

        // Create sorted arrays based on the sorted indices
        vector<int> sortedA(num_tasks), sortedB(num_tasks);
        for (int i = 0; i < num_tasks; ++i) {
            sortedA[i] = tasks_limit[indices[i]];
            sortedB[i] = tasks[indices[i]];
        }

        // Replace original arrays with sorted ones
        tasks_limit = sortedA;
        tasks = sortedB;

        // Print the sorted arrays
        cout << "Sorted tasks_limit: ";
        for (int a : tasks_limit) {
            cout << a << " ";
        }
        cout << "\nSorted tasks: ";
        for (int b : tasks) {
            cout << b << " ";
        }
        cout << endl;


        int max_episodes, time_limit, call_temp;
        // for(int call : calls){
        for(int call_index = 0; call_index < num_calls; call_index++){
            max_episodes = 0;
            time_limit = 0;
            call_temp = calls[call_index];
            cout << "Call Temp: " << call_temp << endl;

            for(int episode_id = 0; episode_id < num_episodes; episode_id++){
                cout << "Episode ID: " << episode_id << " Call Temp: " << call_temp << endl;
                 
                if(episode_id < num_tasks){
                    if((call_temp - episodes[episode_id] - tasks[episode_id]) >= 0){
                            if(time_limit + tasks[episode_id] > tasks_limit[episode_id]){
                                max_episodes += 1;
                                cout << "Episode ID0: " << episode_id << " Call: " << call_temp << endl;
                                break;
                            }
                            call_temp = call_temp - episodes[episode_id] - tasks[episode_id];
                            time_limit = time_limit + tasks[episode_id] + episodes[episode_id];
                            max_episodes += 1;
                            cout << "Episode ID1: " << episode_id << " Call: " << call_temp << endl;

                    } else {
                        if((call_temp - episodes[episode_id]) >= 0){
                            call_temp = call_temp - episodes[episode_id];
                            max_episodes += 1;
                            cout << "Episode ID2: " << episode_id << " Call: " << call_temp << endl;
                            break;
                        } else {
                            break;
                        }
                    }

                } else {
                    if((call_temp - episodes[episode_id]) >= 0){
                        call_temp = call_temp - episodes[episode_id];
                        max_episodes += 1;
                        cout << "Episode ID3: " << episode_id << " Call: " << call_temp << endl;
                    } else{
                        break;
                    }
                }

            }
            cout << max_episodes << " ";


        }
        
        cout << endl;
    }
    cout << "All is well!" << endl;
    return 0;
}
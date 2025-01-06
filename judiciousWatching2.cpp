#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
        vector<int> afford(num_tasks);
        vector<int> task_time(num_tasks);


        vector<int> episodes(num_episodes);
        vector<int> episode_time(num_episodes);

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

        int total_task_time = 0;
        int total_episode_time = 0;

        for(int i = 0; i < num_tasks; i++){
            total_task_time = total_task_time + tasks[i];
            task_time[i] = total_task_time;
            afford[i] = tasks_limit[i] - total_task_time;

            for(int j = 0; j < i; j++){
                if(afford[j] > afford[i]){
                    afford[j] = afford[i];
                }
            }
        }

        cout << "Afford List: ";
        for (int b : afford) {
            cout << b << " ";
        }
        cout << endl;

        for(int i = 0; i < num_episodes; i++){
            total_episode_time = total_episode_time + episodes[i];
            episode_time[i] = total_episode_time;
        }


        int max_episodes, call_temp, afford_limit;
        for(int call_index = 0; call_index < num_calls; call_index++){
            max_episodes = 0;

            call_temp = calls[call_index];
            
            cout << "\nCall Time: " << call_temp << endl;

            if(call_temp > task_time.back() && call_temp > tasks_limit.back()){
                afford_limit = call_temp - task_time.back();
            } else {

                for(int i = 0; i < num_tasks; i++){
                    if(call_temp <= tasks_limit[i]){
                        afford_limit = afford[i];
                        break;
                    }
                }
            }
            cout << "Afford Limit: " << afford_limit << endl;

            for(int i = 0; i < num_episodes; ++i){
                if(afford_limit >= episode_time[i]){
                    max_episodes = max_episodes + 1;
                } else {
                    break;
                }
            }

            cout << max_episodes << " ";
        }

        cout << endl;
    }

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

string compressWord(const string& word) {
    if (word.length() > 10) {
        return word[0] + to_string(word.length() - 2) + word.back();
    }
    return word;
}

int main() {
    string word;

    cout << "Enter a word: ";
    // cin >> word; // try using 
    getline(cin, word);

    int count {stoi(word)};
    string result;

    for(int i = 0; i < count; i++){
        getline(cin, word);
        result = compressWord(word);
        cout << result << endl;
    }


    return 0;
}

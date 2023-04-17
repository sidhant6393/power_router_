#include <iostream>
#include <vector>

using namespace std;

int findCurrentIndexMemberIndex(const vector<char>& oldQueue, int currentIndex, const vector<char>& newQueue) {
    // Step 1: determine the identity of the Current Index Member in the old queue
    char currentIndexMember = oldQueue[currentIndex];

    // Step 2: iterate through the new queue and find the index of the Current Index Member
    int newIndex = -1; // initialization to detect if the Current Index Member is not found
    for (int i = 0; i < newQueue.size(); i++) {
        if (newQueue[i] == currentIndexMember) {
            newIndex = i;
            break;
        }
    }

    // Step 3: if the Current Index Member is not found, find the next available member
    if (newIndex == -1) {
        for (int i = currentIndex + 1; i < oldQueue.size(); i++) {
            char member = oldQueue[i];
            bool found = false;
            for (int j = 0; j < newQueue.size(); j++) {
                if (newQueue[j] == member) {
                    newIndex = j;
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
    }

    // Step 4: return the result
    return newIndex;
}

int main() {
    // Example usage
    vector<char> oldQueue = {'A', 'B', 'C', 'D', 'E', 'F', 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'A', 'B', 'A'};
    int currentIndex = 7;
    vector<char> newQueue = {'B', 'C', 'E', 'F', 'B', 'C', 'B', 'C', 'B'};

    int newIndex = findCurrentIndexMemberIndex(oldQueue, currentIndex, newQueue);

    cout << "New index of the Current Index Member: " << newIndex << endl;

    return 0;
}

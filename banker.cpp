#include <iostream>
#include <fstream>
using namespace std;

const int n = 5; // number of processes
const int m = 3; // number of resource types
int i, j, k;
bool safeSequences[n];
int result[n];
int l = 0;

int allocMatrix[5][3];
int maxMatrix[5][3];
int available[3];

void populateArrays();
void banker();

int main()
{
    populateArrays();
    banker();

    bool safe = true;

    for (int i = 0; i < n; i++)
    {
        if (safeSequences[i] == false)
        {
            safe = false;
            cout << "The system is not in a safe state.";
            break;
        }
    }

    if (safe)
    {
        cout << "The system is in a safe state. This is the safe sequence: " << endl;

        for (i = 0; i < 4; i++)
            cout << "P" << result[i] << ", ";

        cout << "P" << result[n - 1] << endl;
    }
}

// populate arrays from data file
void populateArrays(){
    ifstream file("data.txt");

    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            file >> allocMatrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            file >> maxMatrix[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        file >> available[i];
    }

    file.close();
}

void banker() {
    // Set all sequences to initially be considered safe
    memset(safeSequences, 0, sizeof(safeSequences[0]) * n);

    // Calculate the 'need' matrix as the difference between 'maxMatrix' and 'allocMatrix'
    int need[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = maxMatrix[i][j] - allocMatrix[i][j];
        }
    }

    // Try to find safe sequences
    int l = 0; // Index for result
    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < n; i++) {
            if (!safeSequences[i]) {
                bool canAllocate = true;

                // Check if resources are available
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > available[j]) {
                        canAllocate = false;
                        break;
                    }
                }

                // If resources can be allocated, mark process as safe and release resources
                if (canAllocate) {
                    result[l++] = i;  // Add process to the safe sequence
                    for (int y = 0; y < m; y++) {
                        available[y] += allocMatrix[i][y];  // Release resources
                    }
                    safeSequences[i] = true;  // process is safe
                }
            }
        }
    }
}


// g++ producer.cpp -pthread -o producer
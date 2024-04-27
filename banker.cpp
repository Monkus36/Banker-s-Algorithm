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

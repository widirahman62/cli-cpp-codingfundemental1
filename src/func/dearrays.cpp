void dearrays() {
    string dearraysinput;
    int wordcount;
    dearraysbegin:
    cout << "Word list generator" << endl;
    cout << "Enter the number of words: ";
    cin.sync();
    getline(cin, dearraysinput);
    if(dearraysinput.length() > 0) {
        for (int dearraysi = 0; dearraysi < dearraysinput.length(); dearraysi++) {
            if (!isdigit(dearraysinput[dearraysi])) {
                cout << "Invalid input. Press ENTER to try again!" << endl;
                cin.clear();
                cin.ignore();
                cout << "\033c";
                goto dearraysbegin;
            }
        }
        wordcount = stoi(dearraysinput);
    }
    string words[wordcount];

    for (int dearraysj = 0; dearraysj < wordcount;) {
        cout << "Enter word " << dearraysj+1 << ": ";
        cin.sync();
        getline(cin, words[dearraysj]);
        if (words[dearraysj].length() > 0) {
            for (int dearraysk = 0; dearraysk < words[dearraysj].length();) {
                if (!isalpha(words[dearraysj][dearraysk])) {
                    cout << "Word can only contain letters. Press ENTER key to try again!\n";
                    cin.clear();
                    cin.ignore();
                    break;
                } else {
                    dearraysk++;
                    (dearraysk == words[dearraysj].length()) ? dearraysj++ : dearraysj;
                }
            }
        } else {
            cout << "Word cannot be empty. Please try again!" << endl;
            cin.clear();
            cin.ignore();
        }
    }
    cout << "The words you entered are: " << endl;
    for (int dearraysl = 0; dearraysl < wordcount; dearraysl++) {
        cout << words[dearraysl] << endl;
    }
    
}

struct Token {
    int key;
    string name;
};

void updateName(string* name) {
    cin.sync();
    cout << "Please enter your name: ";
    getline(cin, (*name));
    if ((*name).length() != 0) {
        for (int depointeri = 0; depointeri < (*name).length();) {
            if (isalpha((*name)[depointeri]) || (*name)[depointeri] == ' ') {
                if(depointeri == (*name).length()){
                    (*name) = (*name).substr(0, (*name).length() - 1);
                } else {
                    depointeri++;
                }
            } else {
                (*name) = "";
            }
        }
    } else {
        cout << "Invalid name input. Press ENTER key to try again!\n";
        cin.clear();
        cin.ignore();
        cout << "\033c";
        (*name) = "";
    }
}

void generateToken(int* tokenkey){
    srand(time(NULL));
    int tmp = rand() % 999999999 + 100000000;
    while(tmp == (*tokenkey) || tmp > 999999999){
        tmp = rand() % 999999999 + 100000000;
    }
    (*tokenkey) = tmp;
}

void depointer() {
    Token token = {0, ""};
    depointers:
    string depointeropts;
    cout << "Token generator program" << endl;
    cout << "Hello, this program will generate a token for you." << endl;
    if (token.name.length() == 0){
        updateName(&token.name);
        if (token.name.length() != 0) {
            generateToken(&token.key);
        }
        goto depointers;
    } else {
        cout << "Your name is registered as '" << token.name << "' with this token number\n\n" << token.key << "\n\n";
        cout << "Do you want to refresh your token? (y/n) : ";
        cin.sync();
        getline(cin, depointeropts);
        if (depointeropts[1] != '\0'){
            cout << "Invalid input. Press ENTER key to try again!\n";
            cin.clear();
            cin.ignore();
            cout << "\033c";
            goto depointers;
        } else {
            switch(depointeropts[0]){
                case 'y':
                case 'Y':
                    generateToken(&token.key);
                    cout << "Your token has been refreshed. Press ENTER key to continue!\n";
                    cin.clear();
                    cin.ignore();
                    cout << "\033c";
                    goto depointers;
                    break;
                case 'n':
                case 'N':
                    cout << "Thank you for using this program.\n";
                    break;
                default:
                    cout << "Invalid input. Press ENTER key to try again!\n";
                    cin.clear();
                    cin.ignore();
                    cout << "\033c";
                    goto depointers;
                    break;
            }
        }

    }




    





}

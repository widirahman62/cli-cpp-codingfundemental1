enum genders{Male,Female,Other};

void deoperation() {
    string personName;
    genders gender;
    int age;
    char gend;
    float bmi, weight, height;
    deoperationbegin:
    cout << "BMI calculator program" << endl;
    cout << "Hello, May I know your name?\nName : ";
    cin.sync();
    getline(cin, personName);
    if (personName.length() == 0) {
        cout << "Name cannot be empty. Please try again!" << endl;
        cin.clear();
        cin.ignore();
        cout << "\033c";
        goto deoperationbegin;
    }
    for (int deoperationi = 0; deoperationi < personName.length(); deoperationi++) {
        if (!isalpha(personName[deoperationi]) && personName[deoperationi] != ' ') {
            cout << "Name can only contain letters. Press ENTER key to try again!\n";
            cin.clear();
            cin.ignore();
            cout << "\033c";
            goto deoperationbegin;
        }
    }
    cout << "Oh Hi " << personName << ", nice to meet you!" << endl;
    cout << "This program will classify people nutritional status based on BMI (Body Mass Index) calculation." << endl;
    cout << "What gender will this program be used for?\n(Type m for male/f for female/other KEY if not sure) :" << endl;
    cin >> gend;
    switch(gend){
            case 'm':
            case 'M':
                gender = Male;
                cout << "You selected male as gender." << endl;
                break;
            case 'f':
            case 'F':
                gender = Female;
                cout << "You selected female as gender." << endl;
                break;
            default:
                gender = Other;
                cout << "You are not sure what gender will this program be used for." << endl;
                break;
        }
    deoperationweight:
    cout << "Please enter the person weight in kilograms (kg) : ";
    cin.sync();
    cin >> weight;
    while (cin.fail() || weight <= 0) {
        cout << "Weight must be a number greater than zero. Please try again!\n";
        cin.clear();
        cin.ignore();
        goto deoperationweight;
    }
    deoperationheight:
    cout << "Please enter the person height in centimeters (cm) : ";
    cin.sync();
    cin >> height;
    while (cin.fail() || height <= 0) {
        cout << "Height must be a number greater than zero. Please try again!\n";
        cin.clear();
        cin.ignore();
        goto deoperationheight;
    }
    deoperationage:
    cout << "Please enter the person age in years : ";
    cin.sync();
    cin >> age;
    while (cin.fail() || age <= 0) {
        cout << "Age must be a number greater than zero. Please try again!\n";
        cin.clear();
        cin.ignore();
        goto deoperationage;
    }
    height = height / 100;
    bmi = weight / (height * height);
    cout << "Body Mass Index = " << bmi << endl;
    cout << "BMI category : ";
    
    switch(gender){
        case Male:
            if(age < 10){
                cout << (bmi < 14 ? "Underweight" : (bmi < 17.5 ? "Normal" : (bmi < 19.2 ? "Overweight" : "Obese"))) << endl;
                break;
            } else if(age < 15){
                cout << (bmi < 15 ? "Underweight" : (bmi < 21 ? "Normal" : (bmi < 24.6 ? "Overweight" : "Obese"))) << endl;
                break;
            } else if(age < 20){
                cout << (bmi < 17.6 ? "Underweight" : (bmi < 24.9 ? "Normal" : (bmi < 28.7 ? "Overweight" : "Obese"))) << endl;
                break;
            } else {
                cout << (bmi < 18.5 ? "Underweight" : (bmi < 25 ? "Normal" : (bmi < 30 ? "Overweight" : "Obese"))) << endl;
                break;
            }
        case Female:
            if(age < 10){
                cout << (bmi < 13.7 ? "Underweight" : (bmi < 17.6 ? "Normal" : (bmi < 19.6 ? "Overweight" : "Obese"))) << endl;
                break;
            } else if(age < 15){
                cout << (bmi < 14.9 ? "Underweight" : (bmi < 21.5 ? "Normal" : (bmi < 25.7 ? "Overweight" : "Obese"))) << endl;
                break;
            } else if(age < 20){
                cout << (bmi < 17.1 ? "Underweight" : (bmi < 25 ? "Normal" : (bmi < 30 ? "Overweight" : "Obese"))) << endl;
                break;
            } else {
                cout << (bmi < 18.5 ? "Underweight" : (bmi < 25 ? "Normal" : (bmi < 30 ? "Overweight" : "Obese"))) << endl;
                break;
            }
        case Other:
            if(age < 10){
                cout << (bmi < 13.9 ? "Underweight" : (bmi < 17.6 ? "Normal" : (bmi < 19.2 ? "Overweight" : "Obese"))) << endl;
                break;
            } else if(age < 15){
                cout << (bmi < 15 ? "Underweight" : (bmi < 21.3 ? "Normal" : (bmi < 25.1 ? "Overweight" : "Obese"))) << endl;
                break;
            } else if(age < 20){
                cout << (bmi < 17.4 ? "Underweight" : (bmi < 25 ? "Normal" : (bmi < 29.4 ? "Overweight" : "Obese"))) << endl;
                break;
            } else {
                cout << (bmi < 18.5 ? "Underweight" : (bmi < 25 ? "Normal" : (bmi < 30 ? "Overweight" : "Obese"))) << endl;
                break;
            }
    }


}

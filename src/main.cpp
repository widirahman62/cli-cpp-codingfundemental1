#include "func.h"
struct Topics
{
    const char* name;
    void (*func)();
};
struct Topics topics[] = {
    {"1.\tInput/Output, Data Types, Variables,\n\tDecision, Loop, & Operators\n", deoperation},
    {"2.\tArrays\n", dearrays},
    {"3.\tStruct, Function, & Pointer\n", depointer},
    {"4.\tObject Oriented Programming & Inheritance\n", deoop},
};
//     {
//         "1. Hello World\n",
//         "2. Variables\n",
//         "3. Data Types\n",
//         "4. Operators\n",
//         "5. Input/Output\n",
//         "6. If-Else\n",
//         "7. Switch\n",
//         "8. For Loop\n",
//         "9. While Loop\n",
//         "10. Do-While Loop\n",
//         "11. Break\n",
//         "12. Continue\n",
//         "13. Arrays\n",
//         "14. Functions\n",
//         "15. Pointers\n",
//         "16. References\n",
//         "17. Classes\n",
//         "18. Objects\n",
//         "19. Inheritance\n",
//         "20. Polymorphism\n",
//         "21. Encapsulation\n",
//         "22. Abstraction\n",
//         "23. File Handling\n",
//         "24. Exception Handling\n",
//         "25. Templates\n",
//         "26. Namespaces\n",
//         "27. Preprocessor\n",
//         "28. Dynamic Memory Allocation\n",
//         "29. Multithreading\n",
//         "30. Virtual Functions\n",
//         "31. Friend Functions\n",
//         "32. Friend Classes\n",
//         "33. Operator Overloading\n",
//         "34. Function Overloading\n",
//         "35. Constructor Overloading\n",
//         "36. Destructor\n",
//         "37. Copy Constructor\n",
//         "38. Default Arguments\n",
//         "39. Recursion\n",
//         "40. Static Members\n",
//         "41. Static Member Functions\n",
//         "42. Const Member Functions\n",
//         "43. Const Objects\n",
//         "44. Const Pointers\n",
//         "45. Const References\n",
//         "46. Const Cast\n",
//         "47. Dynamic Cast\n",
//         "48. Reinterpret Cast\n",
//         "49. Static Cast\n",
//         "50. Virtual Base Class\n",
//         "51. Pure Virtual Functions\n",
//         "52. Abstract Classes\n",
//         "53. Virtual Destructors\n",
//         "54. Virtual Copy Constructor\n",
//         "55. Virtual Assignment Operator\n",
//         "56. Virtual Copy Assignment Operator\n",
//         "57. Virtual Move Constructor\n",
//         "58. Virtual Move Assignment Operator\n",
//         "59. Virtual Inheritance\n",
//         "60. Virtual Function Table\n",
//         "61. Virtual Function Pointer\n",
//         "62. Virtual Function Call\n",
//         "63. Virtual Function Overrides\n",
//         "64. Virtual Function Overloading\n",
//         "65. Virtual Function Hiding\n",
//         "66. Virtual Function Default Arguments\n",
//     };
void enterToContinue() {
    cout << "Press Enter key to continue" << endl;
    cin.sync();
    cin.ignore();
}
void callTopics(int* caseIndex){
    enterToContinue();
    cout << "\033c";
    if (topics[*caseIndex].func != NULL) {
        topics[*caseIndex].func();
    } else {
        cout << "No function assigned to this topic" << endl;
    }
}
bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}
int main() {
    cin.sync();
    int currentindex = 0;
    int viewperpage = 2;
    int maintabwidth = 5;
    begin:
    string options = "";
    cout << "\033c";
    if(options.length() == 0){
        cout << "Copyright © widirahman62\nHello C++ enthusiast!\nThis program provide you with a list of C++ program examples\nfrom basic programming lecture that I learned in college (first semester).\nPlease select the topic provided below :\n" << endl;
        for (int i = currentindex; i < currentindex+viewperpage; i++) {
            if (i < sizeof(topics)/sizeof(topics[0])) {
                int wordlength = 0;
                for (int j = 0; j < strlen(topics[i].name); j++) {
                    if (topics[i].name[j] == '\t') {
                        cout << setw(maintabwidth-wordlength);
                        wordlength = 0;
                    } else if (topics[i].name[j] == '\n'){
                        cout << endl;
                        wordlength = 0;
                    } else if (topics[i].name[j] == ' '){
                        cout << ' ';
                        wordlength = 0;
                    } else {
                        cout << topics[i].name[j];
                        wordlength++;
                    }
                }
            } else {
                break;
            }
        }
        cout << "\nEnter option(a to next/b to back/number/q to exit): ";
        cin.sync();
        getline(cin, options);
        cout << "You selected option " << options << endl;
        
    }
    if(isNumber(options) && options.length() != 0) {
        int option = stoi(options)-1;
        if (option < sizeof(topics)/sizeof(topics[0]) && option >= 0) {
            callTopics(&option);
        } else {
            cout << "Invalid option. " << endl;
        }
    } else {
        if(options[1] != '\0'){
            cout << "Invalid option. " << endl;
            enterToContinue();
            goto begin;
        }      
        switch(options[0]){
            case 'a':
            case 'A':
                if(currentindex+viewperpage < sizeof(topics)/sizeof(topics[0])){
                    currentindex += viewperpage;
                } else {
                    cout << "No more topics. " << endl;
                    enterToContinue();
                }
                goto begin;
            case 'b':
            case 'B':
                if(currentindex-viewperpage < 0){
                    cout << "No more topics. " << endl;
                    enterToContinue();
                } else {
                    currentindex -= viewperpage;
                }
                goto begin;
            case 'Q':
            case 'q':
                cout << "Thank you for using this program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid option. " << endl;
                break;
        }
    }
    enterToContinue();
    goto begin;
}


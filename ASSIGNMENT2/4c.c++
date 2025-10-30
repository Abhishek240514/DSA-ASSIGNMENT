#include<iostream>
#include<string>
using namespace std;
bool isVowel (char ch)
{
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    string result = "";
<<<<<<< HEAD
    for (int i - 0 ; i < str.length(); i++) {
        char cd = str[i];
=======
    for (char ch : str) {
>>>>>>> cb27c00 (Initial Commit)
        if (!isVowel(ch)) {
            result += ch;
        }
    }
    cout << "String after removing vowels: " << result << endl;
    
    return 0;
<<<<<<< HEAD

}
=======
}
>>>>>>> cb27c00 (Initial Commit)

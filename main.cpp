#include <iostream>
#include <string>

using namespace std;

bool Palindrome(string pali){
    if (pali.length() == 1){return true;}
    if (pali.length() == 2){if (pali[0] == pali[1]) {return true;} return false;}
    if (pali[0] == pali[pali.length()-1]){return Palindrome(pali.substr(1,pali.length()-2));}
    return false;
}

bool intPali(int x){
    string numString = to_string(x);
    return Palindrome(numString);
}

int main()
{
    int highestPali = 0;
    int highesti = 0;
    int highestj = 0;
    for (int i = 999; i > 99; i--){
        for (int j = 999; j > 99; j--){
            if (intPali(i*j)){
                if (highestPali < i*j){highestPali=i*j; highesti=i; highestj=j;}
            }
        }
    }
    cout << highestPali << " (" << highesti << " x " << highestj << ")." << endl;
    return 0;
}
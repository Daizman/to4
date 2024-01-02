#include <iostream>
#include <string>
#include <vector>
#include <cmath>


using namespace std;


void trim(string& s);
bool isnumber(string& s, char& sign);
vector<int> digitsFromString(string s);
string to4(string number);

string to4(string input) {
    trim(input);
    char sign = '\0';
    if (input == "" || !isnumber(input, sign)) {
        return "Incorrect input, giving up.";
    }

    vector<int> digits = digitsFromString(input);
    std::string result = "";
    int i = 0;

    while (i < digits.size()) {
        int remainder = 0;
        bool nonZero = false;

        for (int j = i; j < digits.size(); j++) {
            int current = remainder * 10 + digits[j];
            int quot = current / 4;
            remainder = current % 4;

            if (quot > 0 || nonZero) {
                digits[j] = quot;
                nonZero = true;
            } else {
                digits[j] = 0;
            }
        }

        result = std::to_string(remainder) + result;

        // Удаление ведущих нулей
        while (i < digits.size() && digits[i] == 0) {
            i++;
        }
    }
    result = sign == '-' && result != "" ? sign + result : result;
    return result.empty() ? "0" : result;
}

void trim(string& s) {
    int i = 0;
    while (i < s.length() && s[i] == ' ') {
        i++;
    }
    s = s.substr(i);
    i = s.length() - 1;
    while (i >= 0 && s[i] == ' ') {
        i--;
    }
    s = s.substr(0, i + 1);
}

bool isnumber(string& s, char& sign) {
    if (s.length() == 0) {
        return false;
    }
    if (s[0] == '-') {
        sign = s[0];
        s = s.substr(1);
    }
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

vector<int> digitsFromString(string s) {
    vector<int> digits;
    int i = 0;
    while (i < s.length() && s[i] == '0') {
        i++;
    }
    while(i < s.length()) {
        digits.push_back(s[i] - '0');
        i++;
    }
    return digits;
}

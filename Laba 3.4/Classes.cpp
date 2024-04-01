#include "Classes.h"

T1::T1(string id) : identifier(id) {}

T1::~T1() {}

T2::T2(string id, string val) : T1(id), value(val) {}

T2::~T2() {}

void T2::showValue() {
    cout << "Object " << identifier << " has value: " << value << endl;
}

string T2::binaryToOctal(string binaryStr) {
    while (binaryStr.length() % 3 != 0) {
        binaryStr = '0' + binaryStr;
    }

    string octalStr = "";
    for (size_t i = 0; i < binaryStr.length(); i += 3) {
        int chunk = stoi(binaryStr.substr(i, 3), nullptr, 2);
        octalStr += to_string(chunk);
    }

    return octalStr;
}

void T2::ShowOct() {
    cout << "Octal representation of value " << value << ": ";
    string octalStr = value;
    cout << binaryToOctal(octalStr) << endl;
}

T2 T2::operator+(const T2& other) {
    string newValue = value + other.value;
    return T2("result", newValue);
}

const string &T2::getValue() {
    return value;
}

T2* Factory::create(string id, string val) {
    return new T2(id, val);
}

void Factory::deleteObject(T1* obj) {
    delete obj;
    cout << "Object deleted successfully." << endl;
}

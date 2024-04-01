#pragma once
#include <string>
#include <iostream>
#include <string>
#include <bitset>

using namespace std;

class T1 {
protected:
    string identifier;
public:
    T1(string id);
    virtual ~T1();
    virtual void showValue() = 0;
    virtual const string &getValue() = 0;
};

class T2 : public T1 {
private:
    string value;

public:
    T2(string id, string val);
    ~T2();

    void showValue() override;
    const string &getValue() override;

    string binaryToOctal(string binaryStr);

    void ShowOct();

    T2 operator+(const T2& other);
};

class Factory {
public:
    static T2* create(string id, string val);
    static void deleteObject(T1* obj);
};


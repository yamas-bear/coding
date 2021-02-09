#include <string>
#include <cstddef>
#include <cstring>
#include <cstdint>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "utf8.h"
/*
https://github.com/nemtrif/utfcpp
*/
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); i++)

bool check_palindrome_en(string str)
{
    bool flg = false;
    int str_length = 0;
    str_length = str.size();
    rep(i, str_length / 2)
    {
        if (str.substr(i, 1) != str.substr(str_length - i - 1, 1))
        {
            return flg;
        }
    }
    flg = true;
    return flg;
}

bool check_palindrome_ja(char *str)
{
    cout << str << endl;
    bool flg = false;
    int str_length = 0;
    str_length = utf8::distance(str, str + strlen(str));
    vector<uint16_t> code(str_length); //文字コードを格納するための変数
    rep(i, str_length)
    {
        code[i] = utf8::next(str, str + strlen(str)); //文字コードを格納する
    }
    rep(i, str_length / 2)
    {
        if (code[i] != code[str_length - i - 1])
        {
            return flg;
        }
    }
    flg = true;
    return flg;
}

void test()
{
    // const char *str = u8"たけやぶやけた";

    if (!check_palindrome_en("a"))
    {
        cout << "-----------------------------------------" << endl;
        cout << "回文ですが、回文ではないと判定されました" << endl;
        cout << "test : a" << endl;
        cout << "-----------------------------------------" << endl;
    }
    else if (check_palindrome_en("abc"))
    {
        cout << "-----------------------------------------" << endl;
        cout << "回文ではないですが、回文だと判定されました" << endl;
        cout << "test : abc" << endl;
        cout << "-----------------------------------------" << endl;
    }
    else if (!check_palindrome_en("abcba"))
    {
        cout << "-----------------------------------------" << endl;
        cout << "回文ですが、回文ではないと判定されました" << endl;
        cout << "test : abcba" << endl;
        cout << "-----------------------------------------" << endl;
    }
    else if (check_palindrome_en("ab"))
    {
        cout << "-----------------------------------------" << endl;
        cout << "回文ではないですが、回文だと判定されました" << endl;
        cout << "test : ab" << endl;
        cout << "-----------------------------------------" << endl;
    }
    else if (!check_palindrome_en("abba"))
    {
        cout << "-----------------------------------------" << endl;
        cout << "回文ですが、回文ではないと判定されました" << endl;
        cout << "test : abba" << endl;
        cout << "-----------------------------------------" << endl;
    }
    else if (check_palindrome_en("ABC"))
    {
        cout << "-----------------------------------------" << endl;
        cout << "回文ではないですが、回文だと判定されました" << endl;
        cout << "test : ABC" << endl;
        cout << "-----------------------------------------" << endl;
    }
    else if (!check_palindrome_en("ABCBA"))
    {
        cout << "-----------------------------------------" << endl;
        cout << "回文ですが、回文ではないと判定されました" << endl;
        cout << "test : ABCBA" << endl;
        cout << "-----------------------------------------" << endl;
    }
    else if (check_palindrome_en("ABAB"))
    {
        cout << "-----------------------------------------" << endl;
        cout << "回文ではないですが、回文だと判定されました" << endl;
        cout << "test : ABAB" << endl;
        cout << "-----------------------------------------" << endl;
    }
    else if (!check_palindrome_en("ABBA"))
    {
        cout << "-----------------------------------------" << endl;
        cout << "回文ですが、回文ではないと判定されました" << endl;
        cout << "test : ABBA" << endl;
        cout << "-----------------------------------------" << endl;
    }
    else if (check_palindrome_ja(u8"たけやぶ")) //日本語はutf8にしないと扱えない
    {
        cout << "-----------------------------------------" << endl;
        cout << "回文ではないですが、回文だと判定されました" << endl;
        cout << "test : たけやぶ" << endl;
        cout << "-----------------------------------------" << endl;
    }
    else if (!check_palindrome_ja(u8"たけやぶやけた"))
    {
        cout << "-----------------------------------------" << endl;
        cout << "回文ですが、回文ではないと判定されました" << endl;
        cout << "test : たけやぶやけた" << endl;
        cout << "-----------------------------------------" << endl;
    }
    else if (check_palindrome_ja(u8"山下"))
    {
        cout << "-----------------------------------------" << endl;
        cout << "回文ではないですが、回文だと判定されました" << endl;
        cout << "test : 山下" << endl;
        cout << "-----------------------------------------" << endl;
    }
    else if (!check_palindrome_ja(u8"山下山"))
    {
        cout << "-----------------------------------------" << endl;
        cout << "回文ですが、回文ではないと判定されました" << endl;
        cout << "test : 山下山" << endl;
        cout << "-----------------------------------------" << endl;
    }
    else
    {
        cout << "正常に判定されました" << endl;
    }
}

int main()
{
    test();
    return 0;
}
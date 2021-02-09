#include <string>
#include <cstddef>
#include <stdio.h>
#include <iostream>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); i++)

bool match_takeyabu(string str)
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

void test()
{
    if (!match_takeyabu("a"))
    {
        cout << "-----------------------------------------" << endl;
        cout << "回文ですが、回文ではないと判定されました" << endl;
        cout << "test : a" << endl;
        cout << "-----------------------------------------" << endl;
    }
    else if (match_takeyabu("abc"))
    {
        cout << "-----------------------------------------" << endl;
        cout << "回文ではないですが、回文だと判定されました" << endl;
        cout << "test : abc" << endl;
        cout << "-----------------------------------------" << endl;
    }
    else if (!match_takeyabu("abcba"))
    {
        cout << "-----------------------------------------" << endl;
        cout << "回文ですが、回文ではないと判定されました" << endl;
        cout << "test : abcba" << endl;
        cout << "-----------------------------------------" << endl;
    }
    else if (match_takeyabu("ab"))
    {
        cout << "-----------------------------------------" << endl;
        cout << "回文ではないですが、回文だと判定されました" << endl;
        cout << "test : ab" << endl;
        cout << "-----------------------------------------" << endl;
    }
    else if (!match_takeyabu("abba"))
    {
        cout << "-----------------------------------------" << endl;
        cout << "回文ですが、回文ではないと判定されました" << endl;
        cout << "test : abba" << endl;
        cout << "-----------------------------------------" << endl;
    }
    else if (match_takeyabu("ABC"))
    {
        cout << "-----------------------------------------" << endl;
        cout << "回文ではないですが、回文だと判定されました" << endl;
        cout << "test : ABC" << endl;
        cout << "-----------------------------------------" << endl;
    }
    else if (!match_takeyabu("ABCBA"))
    {
        cout << "-----------------------------------------" << endl;
        cout << "回文ですが、回文ではないと判定されました" << endl;
        cout << "test : ABCBA" << endl;
        cout << "-----------------------------------------" << endl;
    }
    else if (match_takeyabu("ABAB"))
    {
        cout << "-----------------------------------------" << endl;
        cout << "回文ではないですが、回文だと判定されました" << endl;
        cout << "test : ABAB" << endl;
        cout << "-----------------------------------------" << endl;
    }
    else if (!match_takeyabu("ABBA"))
    {
        cout << "-----------------------------------------" << endl;
        cout << "回文ですが、回文ではないと判定されました" << endl;
        cout << "test : ABBA" << endl;
        cout << "-----------------------------------------" << endl;
    }
    else if (match_takeyabu("あいう"))
    {
        cout << "-----------------------------------------" << endl;
        cout << "回文ではないですが、回文だと判定されました" << endl;
        cout << "test : あいう" << endl;
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
#include <string>
#include <cstddef>
#include <stdio.h>
#include <iostream>
#include <array>
#include <vector>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); i++)

vector<vector<int>> routate_array_90degree_to_the_left(int n, vector<vector<int>> array)
{

    vector<vector<int>> after_array;
    int array_element = 1, hyp, nubmer = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            hyp = array[i][nubmer - j - 1];
            after_array[j][i] = hyp;
        }
    }
    return after_array;
}

void test()
{
    int n = 100;
    bool flg = true;
    vector<vector<int>> array, after_array;
    int array_element = 1;
    bool flg;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            array[i][j] = array_element;
            array_element++;
        }
    }

    after_array = routate_array_90degree_to_the_left(n, array);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (after_array[j][i] != array[i][n - j - 1])
            {
                cout << "処理が適切に行われていません" << endl;
                flg = false;
            }
        }
    }
    if (flg)
    {
        cout << "正常に処理が行われました" << endl;
    }
}

int main()
{
    test();
    return 0;
}
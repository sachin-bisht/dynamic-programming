#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int rows,columns,tracks;
    cin >> rows >> columns >> tracks;
    int arr[rows][columns] = {0} , row1, column1, column2;
        for(int i = 1; i <= tracks; i++)
            {
            cin >> row1 >> column1 >> column2;
            while(column1 <= column2)
                {
                arr[row1][column1] = 10909;
                column1++;
            }
        }
    int counter = 0;
    for(int i = 1; i <= rows; i++)
        {
        for(int j = 1; j <= columns; j++)
            {
            if(arr[i][j] != 10909)
                {
                counter++;
            }
        }
    }
    cout << counter;
    return 0;
}


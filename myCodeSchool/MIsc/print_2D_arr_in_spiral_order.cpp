#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////
// Perfect solution
// Directions followed Right, Down, Left, Up

void printInSpiralOrder(int arr[4][4], int col, int row)
{
    int dir = 0;
    int L, R, T, B;
    L = 0;
    R = col - 1;
    T = 0;
    B = row - 1;

    while (T <= B && L <= R)
    {
        // Move Right 
        if (dir == 0)
        {
            for (int i = L; i <= R; i++)
                cout << arr[T][i] << " ";
            T++;
        }
        // Move Down 
        else if (dir == 1)
        {
            for (int i = T; i <= B; i++)
                cout << arr[i][R] << " ";
            R--;
        }
        // Move Left 
        else if (dir == 2)
        {
            for (int i = R; i >= L; i--)
                cout << arr[B][i] << " ";
            B--;
        }
        // Move Up 
        else if (dir == 3)
        {
            for (int i = B; i >= T; i--)
                cout << arr[i][L] << " ";
            L++;
        }

        // Change dir in order 0 1 2 3 0 1 2 3 .....
        dir = (dir + 1) % 4;
    }
}

int main()
{
    int arr[4][4] = {2, 4, 6, 8,
                     5, 9, 12, 16,
                     2, 11, 5, 9,
                     3, 2, 1, 8};

    printInSpiralOrder(arr, 4, 4);

    return 0;
}

///////////////////////////////////////////////////////////
// Alternate solution

// void printInSpiralOrder(int arr[4][4], int col, int row)
// {
//     int dir = 1;
//     int total_elements = col * row;
//     int count = 0;
//     int i = 0;
//     int j = 0;
//     int till_pos_col = col - 1;
//     int till_pos_row = row - 1;
//     int till_neg_col = 0;
//     int till_neg_row = 1;
//     while (count != total_elements)
//     {
//         if (dir)
//         {
//             while (i <= till_pos_col)
//             {
//                 cout << arr[j][i] << " ";
//                 count++;
//                 i++;
//             }
//             i--;
//             j++;
//             while (j <= till_pos_row)
//             {
//                 cout << arr[j][i] << " ";
//                 count++;
//                 j++;
//             }
//             j--;
//             i--;
//             till_pos_col--;
//             till_pos_row--;
//         }
//         else
//         {
//             while (i >= till_neg_col)
//             {
//                 cout << arr[j][i] << " ";
//                 count++;
//                 i--;
//             }
//             i++;
//             j--;
//             while (j >= till_neg_row)
//             {
//                 cout << arr[j][i] << " ";
//                 count++;
//                 j--;
//             }
//             i++;
//             j++;
//             till_neg_col++;
//             till_neg_row++;
//         }
//         (dir) ? dir = 0 : dir = 1;
//     }
//     cout << "\ndone" << endl;
// }
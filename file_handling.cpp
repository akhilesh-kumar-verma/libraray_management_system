/*
 * file_handling.cpp
 *
 *  Created on: Nov 1, 2020
 *      Author: HP
 */

#include <fstream>
#include "trie.h"

void file_handling_beg(trie &dict, string file)
{
    string str[5];
    ifstream fin(file);
    while (!fin.eof())
    {
        for (int i = 0; i < 4; i++)
        {
            fin >> str[i];
        }
        dict.insert(str[0], info(str[0],str[2], str[1], str[3]));
    }
    fin.close();
}

/*
void file_handling_end(trie lib)
{
    //ofstream file("file.txt",ios::open);
    int i = 0;
    string str[4];
    ofstream file("file.txt", ios::app);
    if (!file)
    {
        cout << "\n File creation ERROR ";
        return;
    }

    char ans;

    cout << "\n Would you like to add new Books (Y/y or N/n) : ";
    cin >> ans;
    if (ans == 'n' || ans == 'N')
        return;
    file << endl;
    ans = 'y';
    while (ans == 'y' || ans == 'Y')
    {
        cout << "\n Enter name and details : " << endl;
        for (int j = 0; j < 4; j++)
        {
            cin >> str[i];
            file << str[i];
            if (j < 3)
                file << " ";
        }
        cout << "\n Want to continue??  (Y/y or N/n) : ";
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
            file << endl;
    }       //while over
    file.close();
}
 */

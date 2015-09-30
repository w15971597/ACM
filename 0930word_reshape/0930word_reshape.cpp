#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;

#define MAX 10010

char dict[MAX][MAX]= {0};
char result[MAX][MAX]= {0};
char word[MAX] = {0};

int cmp_char(const void * a, const void * b)
{
    char * m = (char *)a;
    char * n = (char *)b;
    return * m - * n;
}

int cmp_string(const void * a, const void * b)
{
    char * m = (char *)a;
    char * n = (char *)b;
    return strcmp(m, n);
}

int main()
{
    int dict_len = 0;
    // int word_len = 0;
    for (; ; )
    {
        cin >> dict[dict_len];
        strcpy(result[dict_len], dict[dict_len]);
        if (dict[dict_len][0] == '*')
            break;
        dict_len++;
    }
    // cout << n << endl;
    for (int i = 0; i < dict_len; ++i)
    {
        qsort(dict[i], strlen(dict[i]), sizeof(char), cmp_char);
    }

    for (; ; )
    {
        cin >> word;
        qsort(word, strlen(word), sizeof(char), cmp_char);
        // word_len++;
        for (int i = 0; i < dict_len; ++i)
        {
            if (cmp_string(word, dict[i]) == 0)
            {
                cout << result[i] << endl;
            }
            else
                cout << ":(" << endl;
        }

    }



    for (int i = 0; dict[i][0] != '*'; ++i)
    {
        for (int j = 0; dict[i][j] != '\0'; ++j)
        {
            cout << dict[i][j];
        }
        cout << " ";
    }
    return 0;
}

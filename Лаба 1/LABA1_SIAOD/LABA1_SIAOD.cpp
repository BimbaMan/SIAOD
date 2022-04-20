#include <iostream> // main lib
#include <windows.h>
#include <conio.h>
#include <time.h> // random

using namespace std;
int positions[600][2] = { 0 };

void Win()
{
    cout << "You won!" << endl << "Press any key to exit!";
}

bool check(int array[600][2], int x, int y)
{
    bool flag = true;
    for (int i = 0; i < 600; i++)
    {
        if ((array[i][0] == x) && (array[i][1] == y))
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int main()
{
    SetConsoleTitle(L"Console Maze");
    int r;
    int c = 15;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "Welcome!" << endl << "Game mode:" << endl;
    cout << "1 - Easy" << endl;
    cout << "2 - Normal" << endl;
    cout << "3 - Hard" << endl;
    cin >> r;
    system("cls");
    if (r == 2)
    {
        int my_hod[62] = { 2,2,2,3,3,3,3,3,2,2,3,3,0,0,0,0,3,3,2,3,3,3,2,2,2,2,2,2,1,1,1,2,2,3,3,3,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2 };
        int h = 0;
        // 1 - стенки лабиринта
        // 0 - путь
        int mas[24][20] = { {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
                            {1,0,1,0,0,1,0,1,0,0,0,1,1,1,1,0,0,0,0,1,},
                            {1,0,1,1,0,1,0,1,0,1,0,0,0,0,1,0,1,1,0,1,},
                            {1,0,0,0,0,0,0,1,0,1,1,1,1,0,1,0,0,1,0,1,},
                            {1,1,1,1,1,1,0,1,0,1,0,0,1,0,1,1,0,1,0,1,},
                            {1,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,1,},
                            {1,0,1,1,0,1,1,1,1,1,0,0,1,0,1,1,1,1,0,1,},
                            {1,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,1,},
                            {1,1,1,1,1,1,0,1,1,1,0,0,0,0,1,0,1,1,1,1,},
                            {1,1,0,0,0,1,0,0,1,1,0,1,1,1,1,0,0,0,0,1,},
                            {1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,1,1,0,1,},
                            {1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,},
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,},
                            {1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,},
                            {1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,1,0,1,},
                            {1,0,1,1,0,1,1,0,1,0,1,1,1,0,1,0,0,0,0,1,},
                            {1,0,1,0,0,0,1,0,1,0,0,0,1,1,1,1,1,1,1,1,},
                            {1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,},
                            {1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,},
                            {1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,},
                            {1,0,1,0,1,0,0,0,1,0,1,1,1,1,1,1,0,1,0,1,},
                            {1,0,1,0,1,1,1,1,1,0,0,0,1,0,1,0,0,1,0,1,},
                            {1,0,1,0,0,0,0,0,1,1,1,0,0,0,1,0,1,1,0,1,},
                            {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,} };
        int q = 0;
        int s1 = 0;
        int s2 = 1;
        mas[s1][s2] = 2;
        for (int i = 0; i < 24; i++) //переключение по строкам
        {
            for (int j = 0; j < 20; j++)// переключение по столбцам
            {
                if (mas[i][j] == 1)
                {
                    // вывести два раза символ (номер которого 176 в таблице аски) в консоль
                    cout << static_cast<char>(176);
                    cout << static_cast<char>(176);
                    positions[q][0] = j * 2;
                    positions[q][1] = i * 1;
                    q++;
                }

                if (mas[i][j] == 0)
                {
                    cout << "  ";
                }

                if (mas[i][j] == 2)
                {                  
                    cout << static_cast<char>(c);
                    cout << static_cast<char>(c);
                }

            }
            cout << endl;
        }
        bool flag = false;
        short x = 2;
        short y = 0;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
        int hero = c;
        //прячем курсор
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info;
        info.dwSize = 100;
        info.bVisible = FALSE;
        SetConsoleCursorInfo(consoleHandle, &info);
        if (my_hod[h] == 0)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
            cout << "                  ";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
            cout <<" GO UP! ";
        }

        if (my_hod[h] == 1)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
            cout << "                  ";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
            cout <<" GO LEFT! ";
        }

        if (my_hod[h] == 2)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
            cout << "                  ";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
            cout <<" GO DOWN! ";
        }

        if (my_hod[h] == 3)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
            cout << "                  ";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
            cout <<" GO RIGHT! ";
        }
        while (!flag)
        {
            char c = _getch();
            if ((c == 'w') && (check(positions, x, y - 1)) && (y != 0)) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                y -= 1;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
                h++;
            }

            if ((c == 'a') && (check(positions, x - 2, y))) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                x -= 2;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
                h++;
            }

            if ((c == 's') && (check(positions, x, y + 1))) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                y += 1;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
                h++;
            }

            if ((c == 'd') && (check(positions, x + 2, y))) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                x += 2;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
                h++;
            }

            if (x == 2 && y == 24)
            {
                Win();
                break;
            }

            if (my_hod[h] == 0)
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
                cout << "                  ";
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
                cout <<" GO UP! ";
            }

            if (my_hod[h] == 1)
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
                cout << "                  ";
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
                cout <<" GO LEFT! ";
            }

            if (my_hod[h] == 2)
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
                cout << "                  ";
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
                cout <<" GO DOWN! ";
            }

            if (my_hod[h] == 3)
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
                cout << "                  ";
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
                cout <<" GO RIGHT! ";
            }
        }
    }
    if (r == 1)
    {
        int my_hod[15] = { 2,3,3,2,2,2,3,2,2,1,1,1,2,2,2 };
        int h = 0;
        int mas[9][10] = { {1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
                           {1, 0, 0, 0, 1, 1, 0, 0, 0, 1 },
                           {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                           {1, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
                           {1, 1, 1, 0, 0, 0, 1, 0, 1, 1 },
                           {1, 0, 1, 1, 0, 1, 0, 0, 0, 1 },
                           {1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
                           {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                           {1, 0, 1, 1, 1, 1, 1, 1, 1, 1 } };
        int q = 0;
        int s1 = 0;
        int s2 = 1;
        mas[s1][s2] = 2;
        for (int i = 0; i < 9; i++) //переключение по строкам
        {
            for (int j = 0; j < 10; j++)// переключение по столбцам
            {
                if (mas[i][j] == 1)
                {
                    // вывести два раза символ (номер которого 176 в таблице аски) в консоль
                    cout << static_cast<char>(176);
                    cout << static_cast<char>(176);
                    positions[q][0] = j * 2;
                    positions[q][1] = i * 1;
                    q++;
                }

                if (mas[i][j] == 0)
                {
                    cout << "  ";
                }

                if (mas[i][j] == 2)
                {
                    cout << static_cast<char>(c);
                    cout << static_cast<char>(c);
                }

            }
            cout << endl;
        }
        bool flag = false;
        short x = 2;
        short y = 0;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
        int hero = c;
        //прячем курсор
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info;
        info.dwSize = 100;
        info.bVisible = FALSE;
        SetConsoleCursorInfo(consoleHandle, &info);
        if (my_hod[h] == 0)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
            cout << "                  ";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
            cout << " GO UP! ";
        }

        if (my_hod[h] == 1)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
            cout << "                  ";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
            cout <<" GO LEFT! ";
        }

        if (my_hod[h] == 2)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
            cout << "                  ";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
            cout <<" GO DOWN! ";
        }

        if (my_hod[h] == 3)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
            cout << "                  ";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
            cout <<" GO RIGHT! ";
        }
        while (!flag)
        {
            char c = _getch();
            if ((c == 'w') && (check(positions, x, y - 1)) && (y != 0)) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                y -= 1;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
                h++;
            }

            if ((c == 'a') && (check(positions, x - 2, y))) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                x -= 2;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
                h++;
            }

            if ((c == 's') && (check(positions, x, y + 1))) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                y += 1;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
                h++;
            }

            if ((c == 'd') && (check(positions, x + 2, y))) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                x += 2;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
                h++;
            }

            if (x == 2 && y == 9)
            {
                Win();
                break;
            }

            if (my_hod[h] == 0)
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
                cout << "                  ";
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
                cout <<" GO UP! ";
            }

            if (my_hod[h] == 1)
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
                cout << "                  ";
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
                cout << " GO LEFT! ";
            }

            if (my_hod[h] == 2)
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
                cout << "                  ";
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
                cout <<" GO DOWN! ";
            }

            if (my_hod[h] == 3)
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
                cout << "                  ";
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
                cout <<" GO RIGHT! ";
            }
        }
    }
    if (r == 3)
    {
        int my_hod[89] = { 2,2,2,3,3,3,3,3,2,2,3,3,0,0,0,0,3,3,2,3,3,3,2,2,2,3,3,3,0,0,1,0,0,3,3,3,2,3,3,3,3,3,3,3,3,2,2,1,1,2,2,3,3,2,2,2,2,2,1,1,2,2,2,2,1,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2 };
        int h = 0;
        int mas[24][48] = { {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
                            {1,0,1,0,0,1,0,1,0,0,0,1,1,1,1,0,0,0,0,1,0,0,1,1,0,1,0,1,0,1,0,0,0,0,1,0,1,1,0,1,},
                            {1,0,1,1,0,1,0,1,0,1,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,1,0,0,1,0,1,},
                            {1,0,0,0,0,0,0,1,0,1,1,1,1,0,1,0,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,0,1,0,1,1,0,1,0,1,},
                            {1,1,1,1,1,1,0,1,0,1,0,0,1,0,1,1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,1,},
                            {1,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,1,0,0,1,1,0,1,1,1,1,1,0,0,1,0,1,1,1,1,0,1,},
                            {1,0,1,1,0,1,1,1,1,1,0,0,1,0,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,1,},
                            {1,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,1,0,1,1,1,1,1,0,1,1,1,0,0,0,0,1,0,1,1,1,1,},
                            {1,1,1,1,1,1,0,1,1,1,0,0,0,0,1,0,1,1,1,1,0,1,0,1,0,1,0,0,1,1,0,1,1,1,1,0,0,0,0,1,},
                            {1,1,0,0,0,1,0,0,1,1,0,1,1,1,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,1,1,0,1,},
                            {1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,0,0,0,0,1,},
                            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,},
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,},
                            {1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0,1,},
                            {1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,1,0,1,0,0,1,1,0,1,1,0,1,0,1,1,1,0,1,0,0,0,0,1,},
                            {1,0,1,1,0,1,1,0,1,0,1,1,1,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1,0,0,0,1,1,1,1,1,1,1,1,},
                            {1,0,1,0,0,0,1,0,1,0,0,0,1,1,1,1,1,1,1,1,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,},
                            {1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,},
                            {1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,},
                            {1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,1,1,1,1,1,1,0,1,0,1,},
                            {1,0,1,0,1,0,0,0,1,0,1,1,1,1,1,0,0,1,0,1,0,0,1,0,1,1,1,1,1,0,0,0,1,0,1,0,0,1,0,1,},
                            {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,1,0,1,1,0,1,},
                            {1,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
                            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,} };
        int q = 0;
        int s1 = 0;
        int s2 = 1;
        mas[s1][s2] = 2;
        for (int i = 0; i < 24; i++) //переключение по строкам
        {
            for (int j = 0; j < 48; j++)// переключение по столбцам
            {
                if (mas[i][j] == 1)
                {
                    // вывести два раза символ (номер которого 176 в таблице аски) в консоль
                    cout << static_cast<char>(176);
                    cout << static_cast<char>(176);
                    positions[q][0] = j * 2;
                    positions[q][1] = i * 1;
                    q++;
                }

                if (mas[i][j] == 0)
                {
                    cout << "  ";
                }

                if (mas[i][j] == 2)
                {
                    cout << static_cast<char>(c);
                    cout << static_cast<char>(c);
                }
            }
            cout << endl;
        }
        bool flag = false;
        short x = 2;
        short y = 0;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
        int hero = c;
        //hide coursor
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info;
        info.dwSize = 100;
        info.bVisible = FALSE;
        SetConsoleCursorInfo(consoleHandle, &info);
        if (my_hod[h] == 0)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
            cout << "                  ";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
            cout <<" GO UP! ";
        }

        if (my_hod[h] == 1)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
            cout << "                  ";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
            cout <<" GO LEFT! ";
        }

        if (my_hod[h] == 2)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
            cout << "                  ";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
            cout <<" GO DOWN! ";
        }

        if (my_hod[h] == 3)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
            cout << "                  ";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
            cout <<" GO RIGHT! ";
        }
        while (!flag)
        {
            char c = _getch();
            if ((c == 'w') && (check(positions, x, y - 1)) && (y != 0)) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                y -= 1;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
                h++;
            }

            if ((c == 'a') && (check(positions, x - 2, y))) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                x -= 2;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
                h++;
            }

            if ((c == 's') && (check(positions, x, y + 1))) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                y += 1;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
                h++;
            }

            if ((c == 'd') && (check(positions, x + 2, y))) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                x += 2;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
                h++;
            }

            if (x == 76 && y == 24)
            {
                Win();
                break;
            }

            if (my_hod[h] == 0)
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
                cout << "                  ";
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
                cout << " GO UP! ";
            }

            if (my_hod[h] == 1)
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
                cout << "                  ";
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
                cout <<" GO LEFT! ";
            }

            if (my_hod[h] == 2)
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
                cout << "                  ";
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
                cout <<" GO DOWN! ";
            }

            if (my_hod[h] == 3)
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
                cout << "                  ";
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
                cout <<" GO RIGHT! ";
            }
        }
    }
    return 0;
}
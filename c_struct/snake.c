#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>

int i, j, height = 20, width = 20;
int gameover, score;
int x, y, fruitx, fruity, flag;

void setup()
{
    gameover = 0;
    x = height / 2;
    y = width / 2;
    srand(time(0));
    fruitx = rand() % 20;
    fruity = rand() % 20;
    score = 0;
}

void draw()
{
    clear();
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                printw("#");
            }
            else
            {
                if (i == x && j == y)
                    printw("0");
                else if (i == fruitx && j == fruity)
                    printw("*");
                else
                    printw(" ");
            }
        }
        printw("\n");
    }
    printw("score = %d\n", score);
    printw("press X to quit the game\n");
    refresh();
}

void input()
{
    int ch = getch(); // Get character input using ncurses
    if (ch != ERR) // Check if input is available
    {
        switch (ch)
        {
        case 'a':
            flag = 1;
            break;
        case 's':
            flag = 2;
            break;
        case 'd':
            flag = 3;
            break;
        case 'w':
            flag = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}

void logic()
{
    usleep(80000);
    switch (flag)
    {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x--;
        break;
    default:
        break;
    }
    if (x < 0 || x >= height || y < 0 || y >= width)
        gameover = 1;
    if (x == fruitx && y == fruity)
    {
        fruitx = rand() % 20;
        fruity = rand() % 20;
        score += 10;
    }
}

int main()
{
    initscr();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE); // Enable non-blocking input
    noecho();
    setup();

    while (!gameover)
    {
        draw();
        input();
        logic();
    }

    endwin();
    return 0;
}

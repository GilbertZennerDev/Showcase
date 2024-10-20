#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#define MAX_DIGITS 15

void draw_numpad(WINDOW *win);
void handle_input(WINDOW *win, char *number);

int main() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    WINDOW *numpad_win = newwin(10, 30, 1, 1);
    box(numpad_win, 0, 0);
    draw_numpad(numpad_win);
    wrefresh(numpad_win);

    char number[MAX_DIGITS + 1] = {0};
    handle_input(numpad_win, number);

    endwin();
    return 0;
}

void draw_numpad(WINDOW *win) {
    const char *keys[] = {
        "1", "2", "3",
        "4", "5", "6",
        "7", "8", "9",
        "*", "0", "#"
    };

    int x = 2, y = 2;
    for (int i = 0; i < 12; i++) {
        mvwprintw(win, y, x, keys[i]);
        x += 4;
        if ((i + 1) % 3 == 0) {
            x = 2;
            y += 2;
        }
    }

    mvwprintw(win, y + 2, 2, "[CALL]");
}

void handle_input(WINDOW *win, char *number) {
    int ch, index = 0;
    while ((ch = wgetch(win)) != 'q') {
        if (ch >= '0' && ch <= '9' && index < MAX_DIGITS) {
            number[index++] = ch;
            number[index] = '\0';
        } else if (ch == KEY_BACKSPACE && index > 0) {
            number[--index] = '\0';
        } else if (ch == '\n') {
            // Handle call action
            mvwprintw(win, 8, 2, "Calling %s...", number);
            wrefresh(win);
            break;
        }
        mvwprintw(win, 1, 2, "Number: %s", number);
        wrefresh(win);
    }
}
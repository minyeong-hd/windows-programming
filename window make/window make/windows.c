#include <windows.h>

void gotoxy(int x, int y) {
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, Cur);
}

int main() {
    int x = 0, y = 0;  // 출력 시작 위치
    int width = 20, height = 7;  // 사각형 크기 (세로 길이 증가)

    // 상단 가로선
    gotoxy(x, y);
    for (int i = 0; i < width; i++) putchar('_');

    // 좌우 세로선 + 중간 가로선 추가 (위치 조정)
    for (int i = 1; i < height; i++) {
        gotoxy(x, y + i);
        putchar('|');
        gotoxy(x + width - 1, y + i);
        putchar('|');

        // 중간 가로선 (두 칸 위로 조정)
        if (i == height / 2 - 1) {
            gotoxy(x + 1, y + i);
            for (int j = 1; j < width - 1; j++) putchar('_');
        }
    }

    // 하단 가로선
    gotoxy(x, y + height);
    for (int i = 0; i < width; i++) putchar('_');

    return 0;
}

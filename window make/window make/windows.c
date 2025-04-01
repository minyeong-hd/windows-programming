#include <windows.h>

void gotoxy(int x, int y) {
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, Cur);
}

int main() {
    int x = 0, y = 0;  // ��� ���� ��ġ
    int width = 20, height = 7;  // �簢�� ũ�� (���� ���� ����)

    // ��� ���μ�
    gotoxy(x, y);
    for (int i = 0; i < width; i++) putchar('_');

    // �¿� ���μ� + �߰� ���μ� �߰� (��ġ ����)
    for (int i = 1; i < height; i++) {
        gotoxy(x, y + i);
        putchar('|');
        gotoxy(x + width - 1, y + i);
        putchar('|');

        // �߰� ���μ� (�� ĭ ���� ����)
        if (i == height / 2 - 1) {
            gotoxy(x + 1, y + i);
            for (int j = 1; j < width - 1; j++) putchar('_');
        }
    }

    // �ϴ� ���μ�
    gotoxy(x, y + height);
    for (int i = 0; i < width; i++) putchar('_');

    return 0;
}

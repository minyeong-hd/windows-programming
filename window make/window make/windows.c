//#include <windows.h>
//
//void gotoxy(int x, int y) {
//    COORD Cur;
//    Cur.X = x;
//    Cur.Y = y;
//    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
//    SetConsoleCursorPosition(output, Cur);
//}
//
//int main() {
//    int x = 0, y = 0;  // ��� ���� ��ġ
//    int width = 20, height = 7;  // �簢�� ũ�� (���� ���� ����)
//
//    // ��� ���μ�
//    gotoxy(x, y);
//    for (int i = 0; i < width; i++) putchar('_');
//
//    // �¿� ���μ� + �߰� ���μ� �߰� (��ġ ����)
//    for (int i = 1; i < height; i++) {
//        gotoxy(x, y + i);
//        putchar('|');
//        gotoxy(x + width - 1, y + i);
//        putchar('|');
//
//        // �߰� ���μ� (�� ĭ ���� ����)
//        if (i == height / 2 - 1) {
//            gotoxy(x + 1, y + i);
//            for (int j = 1; j < width - 1; j++) putchar('_');
//        }
//    }
//
//    // �ϴ� ���μ�
//    gotoxy(x, y + height);
//    for (int i = 0; i < width; i++) putchar('_');
//
//    return 0;
//}
#include <stdio.h>
#include <windows.h>

// �ڽ� �Ӽ��� �����ϴ� ����ü ����
typedef struct {
    int x;           // �ڽ� X ��ġ
    int y;           // �ڽ� Y ��ġ
    int width;       // �ڽ� �ʺ�
    int height;      // �ڽ� ����
    char name[50];   // �ڽ� �̸�
    char color[10];  // ANSI ���� �ڵ�
} BoxProperties;

// �ܼ� Ŀ�� �̵� �Լ�
void gotoxy(int x, int y) {
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

// �ܼ��� Ư�� ������ �ʷϻ����� ä��� �Լ�
void fillGreenBackground(int startX, int startY, int width, int height) {
    printf("\033[42m"); // �ʷϻ� ��� ����

    for (int i = 0; i < height; i++) {
        gotoxy(startX, startY + i); // ������ ��ġ���� ����
        for (int j = 0; j < width; j++) {
            printf(" "); // �� ���� ��� (�ʷϻ� ����)
        }
    }

    printf("\033[0m"); // ���� �ʱ�ȭ (�ʷϻ� ���� �Ʒ��� ���� �� ����)
}

// �ڽ��� �׸��� �Լ�
void drawBox(BoxProperties box) {
    printf("%s", box.color); // �ڽ� ���� ����

    // ��� ���μ�
    gotoxy(box.x, box.y);
    for (int i = 0; i < box.width; i++) putchar('_');

    // �ڽ� ���� �� �¿� ���μ� �׸���
    for (int i = 1; i < box.height; i++) {
        gotoxy(box.x, box.y + i);
        putchar('|');

        // ���θ� �ڽ� �������� ä���
        printf("%s", box.color);
        for (int j = 1; j < box.width - 1; j++) putchar(' ');

        gotoxy(box.x + box.width - 1, box.y + i);
        putchar('|');

        // "�̹ο�" ��� (�߾� ����)
        if (i == box.height / 2 - 2) {
            gotoxy(box.x + (box.width / 2 - 3), box.y + i);
            printf("\033[30m�̹ο�\033[0m"); // ������ �۾��� ���
        }

        // "�̹ο�" �ؿ� ���μ� �߰� (�ڽ� ���� ����)
        if (i == box.height / 2 - 1) {
            gotoxy(box.x, box.y + i);
            printf("%s", box.color);
            for (int j = 0; j < box.width; j++) putchar('_');
        }
    }

    // �ϴ� ���μ� (���� ����)
    gotoxy(box.x, box.y + box.height);
    printf("%s", box.color);
    for (int i = 0; i < box.width; i++) putchar('_');

    printf("\033[42m"); // ��� �ʷϻ����� ����
}

int main() {
    int consoleWidth = 150;  // �ܼ� ���� ũ��
    int greenHeight = 30;    // �ʷϻ� ��� ����

    // �ܼ� ����� �ʷϻ����� ���� (���� ������ ����)
    fillGreenBackground(0, 0, consoleWidth, greenHeight);

    // �ڽ� �Ӽ� ���� (���� �ִ� �ڽ��� ���� �׷��� ��ġ�� �κ� ó��)
    BoxProperties box1 = { 10, 3, 20, 7, "Red Box", "\033[41m" };   // ������ �ڽ� (�� ��)
    BoxProperties box2 = { 15, 5, 20, 7, "Yellow Box", "\033[43m" }; // ����� �ڽ� (�� �Ʒ�)

    // �ڽ� �׸��� (���� �ִ� �ڽ��� ���� �׷��� ��ġ�� �κ� �ùٸ��� ǥ��)
    drawBox(box1);
    drawBox(box2);

    // �ʷϻ� ����� ������ �������� �� �ʱ�ȭ (�Ʒ��� ������ ��� ����)
    printf("\033[0m");

    // �ʷϻ� ���� �Ʒ���(������ ���)�� ���� ���� ���
    gotoxy(0, greenHeight + 2);

    return 0;
}

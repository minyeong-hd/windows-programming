//////#include <windows.h>
//////
//////void gotoxy(int x, int y) {
//////    COORD Cur;
//////    Cur.X = x;
//////    Cur.Y = y;
//////    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
//////    SetConsoleCursorPosition(output, Cur);
//////}
//////
//////int main() {
//////    int x = 0, y = 0;  // ��� ���� ��ġ
//////    int width = 20, height = 7;  // �簢�� ũ�� (���� ���� ����)
//////
//////    // ��� ���μ�
//////    gotoxy(x, y);
//////    for (int i = 0; i < width; i++) putchar('_');
//////
//////    // �¿� ���μ� + �߰� ���μ� �߰� (��ġ ����)
//////    for (int i = 1; i < height; i++) {
//////        gotoxy(x, y + i);
//////        putchar('|');
//////        gotoxy(x + width - 1, y + i);
//////        putchar('|');
//////
//////        // �߰� ���μ� (�� ĭ ���� ����)
//////        if (i == height / 2 - 1) {
//////            gotoxy(x + 1, y + i);
//////            for (int j = 1; j < width - 1; j++) putchar('_');
//////        }
//////    }
//////
//////    // �ϴ� ���μ�
//////    gotoxy(x, y + height);
//////    for (int i = 0; i < width; i++) putchar('_');
//////
//////    return 0;
//////}
////#include <stdio.h>
////#include <windows.h>
////
////// �ڽ� �Ӽ��� �����ϴ� ����ü ����
//////typedef struct {
////    int x;           // �ڽ� X ��ġ
////    int y;           // �ڽ� Y ��ġ
////    int width;       // �ڽ� �ʺ�
////    int height;      // �ڽ� ����
////    char name[50];   // �ڽ� �̸�
////    char color[10];  // ANSI ���� �ڵ�
////} BoxProperties;
////
////// �ܼ� Ŀ�� �̵� �Լ�
////void gotoxy(int x, int y) {
////    COORD Cur;
////    Cur.X = x;
////    Cur.Y = y;
////    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
////    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
////}
////
////// �ܼ��� Ư�� ������ �ʷϻ����� ä��� �Լ�
////void fillGreenBackground(int startX, int startY, int width, int height) {
////    printf("\033[42m"); // �ʷϻ� ��� ����
////
////    for (int i = 0; i < height; i++) {
////        gotoxy(startX, startY + i); // ������ ��ġ���� ����
////        for (int j = 0; j < width; j++) {
////            printf(" "); // �� ���� ��� (�ʷϻ� ����)
////        }
////    }
////
////    printf("\033[0m"); // ���� �ʱ�ȭ (�ʷϻ� ���� �Ʒ��� ���� �� ����)
////}
////
////// �ڽ��� �׸��� �Լ�
////void drawBox(BoxProperties box) {
////    printf("%s", box.color); // �ڽ� ���� ����
////
////    // ��� ���μ�
////    gotoxy(box.x, box.y);
////    for (int i = 0; i < box.width; i++) putchar('_');
////
////    // �ڽ� ���� �� �¿� ���μ� �׸���
////    for (int i = 1; i < box.height; i++) {
////        gotoxy(box.x, box.y + i);
////        putchar('|');
////
////        // ���θ� �ڽ� �������� ä���
////        printf("%s", box.color);
////        for (int j = 1; j < box.width - 1; j++) putchar(' ');
////
////        gotoxy(box.x + box.width - 1, box.y + i);
////        putchar('|');
////
////        // "�̹ο�" ��� (�߾� ����)
////        if (i == box.height / 2 - 2) {
////            gotoxy(box.x + (box.width / 2 - 3), box.y + i);
////            printf("\033[30m�̹ο�\033[0m"); // ������ �۾��� ���
////        }
////
////        // "�̹ο�" �ؿ� ���μ� �߰� (�ڽ� ���� ����)
////        if (i == box.height / 2 - 1) {
////            gotoxy(box.x, box.y + i);
////            printf("%s", box.color);
////            for (int j = 0; j < box.width; j++) putchar('_');
////        }
////    }
////
////    // �ϴ� ���μ� (���� ����)
////    gotoxy(box.x, box.y + box.height);
////    printf("%s", box.color);
////    for (int i = 0; i < box.width; i++) putchar('_');
////
////    printf("\033[42m"); // ��� �ʷϻ����� ����
////}
////
////int main() {
////    int consoleWidth = 150;  // �ܼ� ���� ũ��
////    int greenHeight = 30;    // �ʷϻ� ��� ����
////
////    // �ܼ� ����� �ʷϻ����� ���� (���� ������ ����)
////    fillGreenBackground(0, 0, consoleWidth, greenHeight);
////
////    // �ڽ� �Ӽ� ���� (���� �ִ� �ڽ��� ���� �׷��� ��ġ�� �κ� ó��)
////    BoxProperties box1 = { 10, 3, 20, 7, "Red Box", "\033[41m" };   // ������ �ڽ� (�� ��)
////    BoxProperties box2 = { 15, 5, 20, 7, "Yellow Box", "\033[43m" }; // ����� �ڽ� (�� �Ʒ�)
////
////    // �ڽ� �׸��� (���� �ִ� �ڽ��� ���� �׷��� ��ġ�� �κ� �ùٸ��� ǥ��)
////    drawBox(box1);
////    drawBox(box2);
////
////    // �ʷϻ� ����� ������ �������� �� �ʱ�ȭ (�Ʒ��� ������ ��� ����)
////    printf("\033[0m");
////
////    // �ʷϻ� ���� �Ʒ���(������ ���)�� ���� ���� ���
////    gotoxy(0, greenHeight + 2);
////
////    return 0;
////}
//
//#include <stdio.h>
//#include <conio.h>
//#include <windows.h>
//
//#define WIDTH 30
//#define HEIGHT 20
//
//// Ŀ���� (x, y) ��ġ�� �̵��ϴ� �Լ� (Windows API ���)
//void move_cursor(int x, int y) {
//    COORD pos = { (SHORT)x, (SHORT)y };
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}
//
//// ��ü ����� ��������� ĥ�ϴ� �Լ�
//void draw_background() {
//    for (int y = 0; y < HEIGHT; y++) {
//        move_cursor(0, y);
//        for (int x = 0; x < WIDTH; x++) {
//            printf("\033[43m \033[0m"); // ��� ���
//        }
//    }
//    fflush(stdout);
//}
//
//int main() {
//    int x = WIDTH / 2;
//    int y = HEIGHT / 2;
//
//    draw_background();
//
//    while (1) {
//        // ���ĺ� 'a' ���
//        move_cursor(x, y);
//        printf("\033[43;30ma\033[0m"); // ��� ��� + ���� ����
//        fflush(stdout);
//
//        char key = _getch();
//
//        // ���� ��ġ �����
//        move_cursor(x, y);
//        printf("\033[43m \033[0m");
//        fflush(stdout);
//
//        // ����Ű �Է� ó��
//        if (key == 'a' && x > 0) x--;
//        else if (key == 'd' && x < WIDTH - 1) x++;
//        else if (key == 'w' && y > 0) y--;
//        else if (key == 's' && y < HEIGHT - 1) y++;
//        else if (key == 'q') break;
//    }
//
//    move_cursor(0, HEIGHT + 1);
//    printf("\n\n���α׷� ����\n");
//
//    return 0;
//}

//#include <stdio.h>
//#include <conio.h>
//#include <windows.h>
//
//#define WIDTH 30
//#define HEIGHT 20
//
//void move_cursor(int x, int y) {
//    COORD pos = { (SHORT)x, (SHORT)y };
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}
//
//void draw_background() {
//    for (int y = 0; y < HEIGHT; y++) {
//        move_cursor(0, y);
//        for (int x = 0; x < WIDTH; x++) {
//            printf("\033[43m \033[0m");
//        }
//    }
//    fflush(stdout);
//}
//
//int main() {
//    int x = WIDTH / 2;
//    int y = HEIGHT / 2;
//
//    draw_background();
//
//    while (1) {
//        move_cursor(x, y);
//        printf("\033[43;30ma\033[0m");
//        fflush(stdout);
//
//        // ���� ���� �Է� ����
//        if (_kbhit()) {
//            char key = _getch();  // ��� �Է�
//
//            // �����
//            move_cursor(x, y);
//            printf("\033[43m \033[0m");
//            fflush(stdout);
//
//            // �̵� ó��
//            if (key == 'a' && x > 0) x--;
//            else if (key == 'd' && x < WIDTH - 1) x++;
//            else if (key == 'w' && y > 0) y--;
//            else if (key == 's' && y < HEIGHT - 1) y++;
//            else if (key == 'q') break;
//        }
//
//        Sleep(10); // �ʹ� CPU �� ��Ƹ԰� ��¦ ��
//    }
//
//    move_cursor(0, HEIGHT + 1);
//    printf("\n\n���α׷� ����\n");
//
//    return 0;
//}

#include <windows.h>
#include <stdio.h>

int main() {
    char letter = 'O';  // ���ĺ� 'O' ����
    POINT mousePos;     // ���콺 ��ġ
    POINT prevMousePos; // ���� ���콺 ��ġ
    int isDragging = 0;  // �巡�� ���� (0: �巡�� �� �ƴ�, 1: �巡�� ��)
    int letterX = 10;    // ���ĺ� 'O'�� �ʱ� X ��ǥ
    int letterY = 5;     // ���ĺ� 'O'�� �ʱ� Y ��ǥ

    // �ܼ� ȭ�� �ʱ�ȭ
    system("cls");

    while (1) {
        // ���콺 ��ġ ���
        GetCursorPos(&mousePos);

        // ȭ�� ���� (�巡�� ���� ���� ��ġ ����)
        // ���� ��ġ�� ���� ��� (���� 'O'�� ����� ���)
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) { letterX, letterY });
        printf(" ");  // ���� ��ġ �������� �����

        // ���ĺ� O ���
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) { letterX, letterY });
        printf("%c", letter);

        // ���콺 ���� ��ư�� Ŭ���ϸ� �巡�� ����
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
            if (!isDragging) {
                // ���콺 ���� ��ư�� ó�� Ŭ������ �� �巡�� ����
                isDragging = 1;
                prevMousePos = mousePos; // �巡�� ���� ���� ����
            }
        }
        else {
            if (isDragging) {
                // ���콺�� ������ �� �巡�� ����
                isDragging = 0;
            }
        }

        // �巡�� ���� ���� ��ġ ����
        if (isDragging) {
            // ���콺�� ������ ��ŭ ���ĺ� 'O'�� �̵�
            letterX += mousePos.x - prevMousePos.x;
            letterY += mousePos.y - prevMousePos.y;

            // ���� ���콺 ��ġ�� ���� ��ġ�� ����
            prevMousePos = mousePos;
        }

        // ���� ����: ESC Ű�� ������ ���α׷� ����
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            printf("\n���α׷� ����\n");
            break;
        }

        // ��� ��� (CPU ��� ����ȭ)
        Sleep(10);
    }

    return 0;
}

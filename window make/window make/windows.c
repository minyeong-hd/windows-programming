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
//////    int x = 0, y = 0;  // 출력 시작 위치
//////    int width = 20, height = 7;  // 사각형 크기 (세로 길이 증가)
//////
//////    // 상단 가로선
//////    gotoxy(x, y);
//////    for (int i = 0; i < width; i++) putchar('_');
//////
//////    // 좌우 세로선 + 중간 가로선 추가 (위치 조정)
//////    for (int i = 1; i < height; i++) {
//////        gotoxy(x, y + i);
//////        putchar('|');
//////        gotoxy(x + width - 1, y + i);
//////        putchar('|');
//////
//////        // 중간 가로선 (두 칸 위로 조정)
//////        if (i == height / 2 - 1) {
//////            gotoxy(x + 1, y + i);
//////            for (int j = 1; j < width - 1; j++) putchar('_');
//////        }
//////    }
//////
//////    // 하단 가로선
//////    gotoxy(x, y + height);
//////    for (int i = 0; i < width; i++) putchar('_');
//////
//////    return 0;
//////}
////#include <stdio.h>
////#include <windows.h>
////
////// 박스 속성을 관리하는 구조체 정의
//////typedef struct {
////    int x;           // 박스 X 위치
////    int y;           // 박스 Y 위치
////    int width;       // 박스 너비
////    int height;      // 박스 높이
////    char name[50];   // 박스 이름
////    char color[10];  // ANSI 색상 코드
////} BoxProperties;
////
////// 콘솔 커서 이동 함수
////void gotoxy(int x, int y) {
////    COORD Cur;
////    Cur.X = x;
////    Cur.Y = y;
////    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
////    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
////}
////
////// 콘솔의 특정 영역만 초록색으로 채우는 함수
////void fillGreenBackground(int startX, int startY, int width, int height) {
////    printf("\033[42m"); // 초록색 배경 설정
////
////    for (int i = 0; i < height; i++) {
////        gotoxy(startX, startY + i); // 지정된 위치에서 시작
////        for (int j = 0; j < width; j++) {
////            printf(" "); // 빈 공간 출력 (초록색 적용)
////        }
////    }
////
////    printf("\033[0m"); // 색상 초기화 (초록색 영역 아래는 원래 색 유지)
////}
////
////// 박스를 그리는 함수
////void drawBox(BoxProperties box) {
////    printf("%s", box.color); // 박스 색상 적용
////
////    // 상단 가로선
////    gotoxy(box.x, box.y);
////    for (int i = 0; i < box.width; i++) putchar('_');
////
////    // 박스 내부 및 좌우 세로선 그리기
////    for (int i = 1; i < box.height; i++) {
////        gotoxy(box.x, box.y + i);
////        putchar('|');
////
////        // 내부를 박스 색상으로 채우기
////        printf("%s", box.color);
////        for (int j = 1; j < box.width - 1; j++) putchar(' ');
////
////        gotoxy(box.x + box.width - 1, box.y + i);
////        putchar('|');
////
////        // "이민영" 출력 (중앙 정렬)
////        if (i == box.height / 2 - 2) {
////            gotoxy(box.x + (box.width / 2 - 3), box.y + i);
////            printf("\033[30m이민영\033[0m"); // 검은색 글씨로 출력
////        }
////
////        // "이민영" 밑에 가로선 추가 (박스 색상 유지)
////        if (i == box.height / 2 - 1) {
////            gotoxy(box.x, box.y + i);
////            printf("%s", box.color);
////            for (int j = 0; j < box.width; j++) putchar('_');
////        }
////    }
////
////    // 하단 가로선 (색상 유지)
////    gotoxy(box.x, box.y + box.height);
////    printf("%s", box.color);
////    for (int i = 0; i < box.width; i++) putchar('_');
////
////    printf("\033[42m"); // 배경 초록색으로 복구
////}
////
////int main() {
////    int consoleWidth = 150;  // 콘솔 가로 크기
////    int greenHeight = 30;    // 초록색 배경 높이
////
////    // 콘솔 배경을 초록색으로 설정 (일정 영역만 적용)
////    fillGreenBackground(0, 0, consoleWidth, greenHeight);
////
////    // 박스 속성 설정 (위에 있는 박스를 먼저 그려서 겹치는 부분 처리)
////    BoxProperties box1 = { 10, 3, 20, 7, "Red Box", "\033[41m" };   // 빨간색 박스 (더 위)
////    BoxProperties box2 = { 15, 5, 20, 7, "Yellow Box", "\033[43m" }; // 노란색 박스 (더 아래)
////
////    // 박스 그리기 (위에 있는 박스를 먼저 그려서 겹치는 부분 올바르게 표현)
////    drawBox(box1);
////    drawBox(box2);
////
////    // 초록색 배경이 끝나는 지점에서 색 초기화 (아래는 검은색 배경 유지)
////    printf("\033[0m");
////
////    // 초록색 영역 아래쪽(검은색 배경)에 종료 문구 출력
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
//// 커서를 (x, y) 위치로 이동하는 함수 (Windows API 사용)
//void move_cursor(int x, int y) {
//    COORD pos = { (SHORT)x, (SHORT)y };
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}
//
//// 전체 배경을 노란색으로 칠하는 함수
//void draw_background() {
//    for (int y = 0; y < HEIGHT; y++) {
//        move_cursor(0, y);
//        for (int x = 0; x < WIDTH; x++) {
//            printf("\033[43m \033[0m"); // 노란 배경
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
//        // 알파벳 'a' 출력
//        move_cursor(x, y);
//        printf("\033[43;30ma\033[0m"); // 노란 배경 + 검정 글자
//        fflush(stdout);
//
//        char key = _getch();
//
//        // 이전 위치 지우기
//        move_cursor(x, y);
//        printf("\033[43m \033[0m");
//        fflush(stdout);
//
//        // 방향키 입력 처리
//        if (key == 'a' && x > 0) x--;
//        else if (key == 'd' && x < WIDTH - 1) x++;
//        else if (key == 'w' && y > 0) y--;
//        else if (key == 's' && y < HEIGHT - 1) y++;
//        else if (key == 'q') break;
//    }
//
//    move_cursor(0, HEIGHT + 1);
//    printf("\n\n프로그램 종료\n");
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
//        // 엔터 없이 입력 감지
//        if (_kbhit()) {
//            char key = _getch();  // 즉시 입력
//
//            // 지우기
//            move_cursor(x, y);
//            printf("\033[43m \033[0m");
//            fflush(stdout);
//
//            // 이동 처리
//            if (key == 'a' && x > 0) x--;
//            else if (key == 'd' && x < WIDTH - 1) x++;
//            else if (key == 'w' && y > 0) y--;
//            else if (key == 's' && y < HEIGHT - 1) y++;
//            else if (key == 'q') break;
//        }
//
//        Sleep(10); // 너무 CPU 안 잡아먹게 살짝 쉼
//    }
//
//    move_cursor(0, HEIGHT + 1);
//    printf("\n\n프로그램 종료\n");
//
//    return 0;
//}

#include <windows.h>
#include <stdio.h>

int main() {
    char letter = 'O';  // 알파벳 'O' 고정
    POINT mousePos;     // 마우스 위치
    POINT prevMousePos; // 이전 마우스 위치
    int isDragging = 0;  // 드래그 상태 (0: 드래그 중 아님, 1: 드래그 중)
    int letterX = 10;    // 알파벳 'O'의 초기 X 좌표
    int letterY = 5;     // 알파벳 'O'의 초기 Y 좌표

    // 콘솔 화면 초기화
    system("cls");

    while (1) {
        // 마우스 위치 얻기
        GetCursorPos(&mousePos);

        // 화면 갱신 (드래그 중일 때만 위치 변경)
        // 이전 위치에 공백 출력 (이전 'O'를 지우는 방식)
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) { letterX, letterY });
        printf(" ");  // 이전 위치 공백으로 덮어씌움

        // 알파벳 O 출력
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) { letterX, letterY });
        printf("%c", letter);

        // 마우스 왼쪽 버튼을 클릭하면 드래그 시작
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
            if (!isDragging) {
                // 마우스 왼쪽 버튼을 처음 클릭했을 때 드래그 시작
                isDragging = 1;
                prevMousePos = mousePos; // 드래그 시작 시점 저장
            }
        }
        else {
            if (isDragging) {
                // 마우스를 놓았을 때 드래그 종료
                isDragging = 0;
            }
        }

        // 드래그 중일 때만 위치 갱신
        if (isDragging) {
            // 마우스를 움직인 만큼 알파벳 'O'를 이동
            letterX += mousePos.x - prevMousePos.x;
            letterY += mousePos.y - prevMousePos.y;

            // 이전 마우스 위치를 현재 위치로 갱신
            prevMousePos = mousePos;
        }

        // 종료 조건: ESC 키를 누르면 프로그램 종료
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            printf("\n프로그램 종료\n");
            break;
        }

        // 잠시 대기 (CPU 사용 최적화)
        Sleep(10);
    }

    return 0;
}

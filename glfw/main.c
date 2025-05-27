#include <GLFW/glfw3.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

// 각 세그먼트를 나타내는 라인 (x1, y1) ~ (x2, y2)
float segments[7][4] = {
    {0.0f, 1.0f, 1.0f, 1.0f}, // A
    {1.0f, 1.0f, 1.0f, 0.5f}, // B
    {1.0f, 0.5f, 1.0f, 0.0f}, // C
    {0.0f, 0.0f, 1.0f, 0.0f}, // D
    {0.0f, 0.5f, 0.0f, 0.0f}, // E
    {0.0f, 1.0f, 0.0f, 0.5f}, // F
    {0.0f, 0.5f, 1.0f, 0.5f}  // G
};

// 숫자별로 켜야 할 세그먼트 (A~G 순서)
int digitMap[10][7] = {
    {1,1,1,1,1,1,0}, // 0
    {0,1,1,0,0,0,0}, // 1
    {1,1,0,1,1,0,1}, // 2
    {1,1,1,1,0,0,1}, // 3
    {0,1,1,0,0,1,1}, // 4
    {1,0,1,1,0,1,1}, // 5
    {1,0,1,1,1,1,1}, // 6
    {1,1,1,0,0,0,0}, // 7
    {1,1,1,1,1,1,1}, // 8
    {1,1,1,1,0,1,1}  // 9
};

void drawCircle(float radius) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++) {
        float angle = 2 * PI * i / 360;
        glVertex2f(radius * cos(angle), radius * sin(angle));
    }
    glEnd();
}
//  메인 시계판 눈금
void drawMainTicks() {
    for (int i = 0; i < 60; i++) {
        float angle = 2 * PI * i / 60;
        float outer = 1.0f;
        float inner = (i % 5 == 0) ? 0.85f : 0.90f;

        float x1 = cos(angle) * outer;
        float y1 = sin(angle) * outer;
        float x2 = cos(angle) * inner;
        float y2 = sin(angle) * inner;

        glLineWidth(i % 5 == 0 ? 2 : 1);
        glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();
    }
}

//  작은 초침 다이얼 눈금
void drawSmallTicks() {
    for (int i = 0; i < 60; i++) {
        float angle = 2 * PI * i / 60;
        float outer = 1.0f;
        float inner = (i % 5 == 0) ? 0.85f : 0.90f;

        float x1 = cos(angle) * outer;
        float y1 = sin(angle) * outer;
        float x2 = cos(angle) * inner;
        float y2 = sin(angle) * inner;

        glLineWidth(i % 5 == 0 ? 2 : 1);
        glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();
    }
}

void drawHand(float angleDeg, float length, float width) {
    glPushMatrix();
    glRotatef(angleDeg, 0, 0, 1);
    glLineWidth(width);
    glBegin(GL_LINES);
    glVertex2f(0, 0);
    glVertex2f(0, length);
    glEnd();
    glPopMatrix();
}
void drawClockHandsWithoutSecond() {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);

    int hour = t->tm_hour % 12;
    int min = t->tm_min;
    int sec = t->tm_sec;

    // 시계방향 회전: 음수로 회전 각도
    float angleMin = -6.0f * (min + sec / 60.0f);
    float angleHour = -30.0f * ((float)hour + (float)min / 60.0f);

    glColor3f(1, 1, 1); drawHand(angleMin, 0.7f, 3.0f); // 분침 (큰침)
    glColor3f(0.5, 0.5, 1); drawHand(angleHour, 0.5f, 5.0f); // 시침 (작은침)
}


// 7세그먼트 숫자 하나 그리기
void drawDigit(int digit, float offsetX, float offsetY, float scale) {
    if (digit < 0 || digit > 9) return;

    glPushMatrix();
    glTranslatef(offsetX, offsetY, 0);
    glScalef(scale, scale, 1);

    for (int i = 0; i < 7; i++) {
        if (digitMap[digit][i]) {
            glBegin(GL_LINES);
            glVertex2f(segments[i][0], segments[i][1]);
            glVertex2f(segments[i][2], segments[i][3]);
            glEnd();
        }
    }

    glPopMatrix();
}

// ':' 문자 그리기
void drawColon(float offsetX, float offsetY, float scale) {
    glPushMatrix();
    glTranslatef(offsetX, offsetY, 0);
    glScalef(scale, scale, 1);

    glPointSize(4.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.5f, 0.75f); // 위 점
    glVertex2f(0.5f, 0.25f); // 아래 점
    glEnd();

    glPopMatrix();
}


void drawSubdialWithSecondHand() {
    // 작은 원의 중심 좌표
    float cx = -0.6f;
    float cy = 0.0f;

    glPushMatrix();
    glTranslatef(cx, cy, 0);  // 중심 이동
    glScalef(0.3f, 0.3f, 1);  // 작은 원

    // 원 테두리
    glColor3f(1, 1, 1);
    drawCircle(1.0f);
    drawSmallTicks();

    // 초침 회전
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    float angleSec = 90.0f - 6.0f * t->tm_sec;

    glColor3f(1, 0, 0); drawHand(angleSec, 0.9f, 1.0f); // 초침
    glPopMatrix();
}

void drawDigitalTime() {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);

    int h1 = t->tm_hour / 10;
    int h2 = t->tm_hour % 10;
    int m1 = t->tm_min / 10;
    int m2 = t->tm_min % 10;

    float baseX = -0.6f;  // 가로 시작 위치
    float y = -0.6f;      // 세로 위치 (아래쪽)
    float gap = 0.25f;    // 숫자 간격
    float scale = 0.15f;   // 크기 조절

    glColor3f(0.0f, 1.0f, 0.0f);  // 초록색

    drawDigit(h1, baseX + gap * 0, y, scale);
    drawDigit(h2, baseX + gap * 1, y, scale);
    drawColon(baseX + gap * 2, y, scale);
    drawDigit(m1, baseX + gap * 3, y, scale);
    drawDigit(m2, baseX + gap * 4, y, scale);
}


int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(600, 600, "Rolex-style Clock", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // 메인 루프 맨 앞
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 완전한 검정색

    // 시계 테두리 색
    glColor3f(0.8f, 0.8f, 0.9f);
    drawCircle(1.0f);

    // 눈금 색
    glColor3f(0.4f, 0.6f, 0.7f);
    drawMainTicks();

    // 바늘들 색상 (각 drawHand 전에)
    glColor3f(0.6f, 1.0f, 0.9f);
    glColor3f(0.7f, 0.6f, 1.0f);

    // 디지털 숫자
    glColor3f(1.0f, 1.0f, 0.8f); // 크림색 숫자

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.2, 1.2, -1.2, 1.2, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();

        // 큰 시계판
        glColor3f(1, 1, 1);
        drawCircle(1.0f);
        drawMainTicks();
        drawClockHandsWithoutSecond();

        // 작은 초침 다이얼
        drawSubdialWithSecondHand();
        drawDigitalTime();  // 시계 아래쪽에 디지털 숫자 출력
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

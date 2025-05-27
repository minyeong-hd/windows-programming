#include <GLFW/glfw3.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

// �� ���׸�Ʈ�� ��Ÿ���� ���� (x1, y1) ~ (x2, y2)
float segments[7][4] = {
    {0.0f, 1.0f, 1.0f, 1.0f}, // A
    {1.0f, 1.0f, 1.0f, 0.5f}, // B
    {1.0f, 0.5f, 1.0f, 0.0f}, // C
    {0.0f, 0.0f, 1.0f, 0.0f}, // D
    {0.0f, 0.5f, 0.0f, 0.0f}, // E
    {0.0f, 1.0f, 0.0f, 0.5f}, // F
    {0.0f, 0.5f, 1.0f, 0.5f}  // G
};

// ���ں��� �Ѿ� �� ���׸�Ʈ (A~G ����)
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
//  ���� �ð��� ����
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

//  ���� ��ħ ���̾� ����
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

    // �ð���� ȸ��: ������ ȸ�� ����
    float angleMin = -6.0f * (min + sec / 60.0f);
    float angleHour = -30.0f * ((float)hour + (float)min / 60.0f);

    glColor3f(1, 1, 1); drawHand(angleMin, 0.7f, 3.0f); // ��ħ (ūħ)
    glColor3f(0.5, 0.5, 1); drawHand(angleHour, 0.5f, 5.0f); // ��ħ (����ħ)
}


// 7���׸�Ʈ ���� �ϳ� �׸���
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

// ':' ���� �׸���
void drawColon(float offsetX, float offsetY, float scale) {
    glPushMatrix();
    glTranslatef(offsetX, offsetY, 0);
    glScalef(scale, scale, 1);

    glPointSize(4.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.5f, 0.75f); // �� ��
    glVertex2f(0.5f, 0.25f); // �Ʒ� ��
    glEnd();

    glPopMatrix();
}


void drawSubdialWithSecondHand() {
    // ���� ���� �߽� ��ǥ
    float cx = -0.6f;
    float cy = 0.0f;

    glPushMatrix();
    glTranslatef(cx, cy, 0);  // �߽� �̵�
    glScalef(0.3f, 0.3f, 1);  // ���� ��

    // �� �׵θ�
    glColor3f(1, 1, 1);
    drawCircle(1.0f);
    drawSmallTicks();

    // ��ħ ȸ��
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    float angleSec = 90.0f - 6.0f * t->tm_sec;

    glColor3f(1, 0, 0); drawHand(angleSec, 0.9f, 1.0f); // ��ħ
    glPopMatrix();
}

void drawDigitalTime() {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);

    int h1 = t->tm_hour / 10;
    int h2 = t->tm_hour % 10;
    int m1 = t->tm_min / 10;
    int m2 = t->tm_min % 10;

    float baseX = -0.6f;  // ���� ���� ��ġ
    float y = -0.6f;      // ���� ��ġ (�Ʒ���)
    float gap = 0.25f;    // ���� ����
    float scale = 0.15f;   // ũ�� ����

    glColor3f(0.0f, 1.0f, 0.0f);  // �ʷϻ�

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

    // ���� ���� �� ��
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // ������ ������

    // �ð� �׵θ� ��
    glColor3f(0.8f, 0.8f, 0.9f);
    drawCircle(1.0f);

    // ���� ��
    glColor3f(0.4f, 0.6f, 0.7f);
    drawMainTicks();

    // �ٴõ� ���� (�� drawHand ����)
    glColor3f(0.6f, 1.0f, 0.9f);
    glColor3f(0.7f, 0.6f, 1.0f);

    // ������ ����
    glColor3f(1.0f, 1.0f, 0.8f); // ũ���� ����

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.2, 1.2, -1.2, 1.2, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();

        // ū �ð���
        glColor3f(1, 1, 1);
        drawCircle(1.0f);
        drawMainTicks();
        drawClockHandsWithoutSecond();

        // ���� ��ħ ���̾�
        drawSubdialWithSecondHand();
        drawDigitalTime();  // �ð� �Ʒ��ʿ� ������ ���� ���
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

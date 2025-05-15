#include <GLFW/glfw3.h>
#include <math.h>

#define PI 3.14159265f

// 🔵 원 구조체 정의
typedef struct {
    float x;      // 중심 x좌표
    float y;      // 중심 y좌표
    float radius; // 반지름
} Circle;

// 🔧 원을 그리는 함수
void drawCircle(Circle c, int segments) {
    glBegin(GL_LINE_LOOP); // 선으로 원을 그림
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * PI * (float)i / (float)segments;
        float dx = c.radius * cosf(theta);
        float dy = c.radius * sinf(theta);
        glVertex2f(c.x + dx, c.y + dy);
    }
    glEnd();
}

int main(void) {
    // GLFW 초기화
    if (!glfwInit()) {
        return -1;
    }

    // 윈도우 생성
    GLFWwindow* window = glfwCreateWindow(640, 480, "원 그리기 - C + GLFW", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // OpenGL 컨텍스트 활성화
    glfwMakeContextCurrent(window);

    // 좌표계를 -1.0 ~ 1.0 로 설정
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);

    // 원 정보
    Circle myCircle = { 0.0f, 0.0f, 0.5f }; // 중심(0,0), 반지름 0.5

    // 루프
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(0.2f, 0.6f, 1.0f); // 파란색
        drawCircle(myCircle, 100);  // 100개 선분으로 근사한 원

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // 정리
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

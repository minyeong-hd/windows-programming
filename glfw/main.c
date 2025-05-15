#include <GLFW/glfw3.h>
#include <math.h>

#define PI 3.14159265358979323846
#define NUM_SEGMENTS 100

// 원 그리기 함수 (화면 중심 기준)
void drawCircle(float centerX, float centerY, float radius) {
    glBegin(GL_LINE_LOOP);  // 원의 테두리만 그림
    for (int i = 0; i < NUM_SEGMENTS; i++) {
        float angle = 2.0f * PI * i / NUM_SEGMENTS;
        float x = radius * cosf(angle);
        float y = radius * sinf(angle);
        glVertex2f(centerX + x, centerY + y);
    }
    glEnd();
}

int main(void) {
    // GLFW 초기화
    if (!glfwInit())
        return -1;

    // 창 생성
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL 원 그리기", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // OpenGL 컨텍스트 설정
    glfwMakeContextCurrent(window);

    // OpenGL 좌표계를 -1~1 사이로 사용 (기본값)
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);   // 화면 지우기
        glLoadIdentity();               // 초기화

        drawCircle(0.0f, 0.0f, 0.5f);   // 중심 (0,0), 반지름 0.5의 원

        glfwSwapBuffers(window);       // 화면에 출력
        glfwPollEvents();              // 입력 처리
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

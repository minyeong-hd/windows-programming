#include <GLFW/glfw3.h>
#include <math.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 600

// 원 그리기 함수
void DrawCircle(float centerX, float centerY, float radius, int segments) {
    glBegin(GL_TRIANGLE_FAN);  // 부채꼴로 원 그리기

    glColor3f(0.0f, 0.0f, 1.0f);  // 파란색
    glVertex2f(centerX, centerY);  // 중심점

    // 원의 점들을 그리기
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * M_PI * i / segments;
        float x = centerX + cosf(angle) * radius;
        float y = centerY + sinf(angle) * radius;
        glVertex2f(x, y);
    }

    glEnd();
}

int main(void) {
    // GLFW 초기화
    if (!glfwInit()) {
        printf("GLFW 초기화 실패!\n");
        return -1;
    }

    // 창 생성
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Circle", NULL, NULL);
    if (!window) {
        printf("윈도우 생성 실패!\n");
        glfwTerminate();
        return -1;
    }

    // OpenGL 컨텍스트를 윈도우에 연결
    glfwMakeContextCurrent(window);

    // OpenGL 기본 설정
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // 배경 흰색
    glViewport(0, 0, WIDTH, HEIGHT);

    while (!glfwWindowShouldClose(window)) {
        // 화면 지우기
        glClear(GL_COLOR_BUFFER_BIT);

        // 화면 중앙에 원 그리기 (중심: (0, 0), 반지름: 0.5, 100개의 점으로 부드럽게)
        DrawCircle(0.0f, 0.0f, 0.5f, 100);

        // 버퍼 교환
        glfwSwapBuffers(window);

        // 이벤트 처리
        glfwPollEvents();
    }

    // 리소스 해제
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

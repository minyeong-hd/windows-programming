#include <GLFW/glfw3.h>
#include <math.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 600

// �� �׸��� �Լ�
void DrawCircle(float centerX, float centerY, float radius, int segments) {
    glBegin(GL_TRIANGLE_FAN);  // ��ä�÷� �� �׸���

    glColor3f(0.0f, 0.0f, 1.0f);  // �Ķ���
    glVertex2f(centerX, centerY);  // �߽���

    // ���� ������ �׸���
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * M_PI * i / segments;
        float x = centerX + cosf(angle) * radius;
        float y = centerY + sinf(angle) * radius;
        glVertex2f(x, y);
    }

    glEnd();
}

int main(void) {
    // GLFW �ʱ�ȭ
    if (!glfwInit()) {
        printf("GLFW �ʱ�ȭ ����!\n");
        return -1;
    }

    // â ����
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Circle", NULL, NULL);
    if (!window) {
        printf("������ ���� ����!\n");
        glfwTerminate();
        return -1;
    }

    // OpenGL ���ؽ�Ʈ�� �����쿡 ����
    glfwMakeContextCurrent(window);

    // OpenGL �⺻ ����
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // ��� ���
    glViewport(0, 0, WIDTH, HEIGHT);

    while (!glfwWindowShouldClose(window)) {
        // ȭ�� �����
        glClear(GL_COLOR_BUFFER_BIT);

        // ȭ�� �߾ӿ� �� �׸��� (�߽�: (0, 0), ������: 0.5, 100���� ������ �ε巴��)
        DrawCircle(0.0f, 0.0f, 0.5f, 100);

        // ���� ��ȯ
        glfwSwapBuffers(window);

        // �̺�Ʈ ó��
        glfwPollEvents();
    }

    // ���ҽ� ����
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

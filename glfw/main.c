#include <GLFW/glfw3.h>
#include <math.h>

#define PI 3.14159265358979323846
#define NUM_SEGMENTS 100

// �� �׸��� �Լ� (ȭ�� �߽� ����)
void drawCircle(float centerX, float centerY, float radius) {
    glBegin(GL_LINE_LOOP);  // ���� �׵θ��� �׸�
    for (int i = 0; i < NUM_SEGMENTS; i++) {
        float angle = 2.0f * PI * i / NUM_SEGMENTS;
        float x = radius * cosf(angle);
        float y = radius * sinf(angle);
        glVertex2f(centerX + x, centerY + y);
    }
    glEnd();
}

int main(void) {
    // GLFW �ʱ�ȭ
    if (!glfwInit())
        return -1;

    // â ����
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL �� �׸���", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // OpenGL ���ؽ�Ʈ ����
    glfwMakeContextCurrent(window);

    // OpenGL ��ǥ�踦 -1~1 ���̷� ��� (�⺻��)
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);   // ȭ�� �����
        glLoadIdentity();               // �ʱ�ȭ

        drawCircle(0.0f, 0.0f, 0.5f);   // �߽� (0,0), ������ 0.5�� ��

        glfwSwapBuffers(window);       // ȭ�鿡 ���
        glfwPollEvents();              // �Է� ó��
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

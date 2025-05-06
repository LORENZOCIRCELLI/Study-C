#include <GLFW/glfw3.h>
#include <GL/glu.h>  // Adicionando o cabeçalho do GLU
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Variáveis globais para controle da rotação
float anguloX = 0.0f;
float anguloY = 0.0f;
double lastX = 400, lastY = 300;  // Posição inicial do cursor

void desenhar_esfera(float raio, int segmentos, int fatias) {
    for (int i = 0; i < segmentos; i++) {
        float theta1 = i * PI / segmentos;  // Latitude superior
        float theta2 = (i + 1) * PI / segmentos;  // Latitude inferior
        
        for (int j = 0; j < fatias; j++) {
            float phi1 = j * 2 * PI / fatias;  // Longitude à esquerda
            float phi2 = (j + 1) * 2 * PI / fatias;  // Longitude à direita

            // Vértices da parte superior do triângulo
            float x1 = raio * sin(theta1) * cos(phi1);
            float y1 = raio * cos(theta1);
            float z1 = raio * sin(theta1) * sin(phi1);

            // Vértices da parte inferior do triângulo
            float x2 = raio * sin(theta1) * cos(phi2);
            float y2 = raio * cos(theta1);
            float z2 = raio * sin(theta1) * sin(phi2);

            // Vértices da parte superior do próximo triângulo
            float x3 = raio * sin(theta2) * cos(phi1);
            float y3 = raio * cos(theta2);
            float z3 = raio * sin(theta2) * sin(phi1);

            // Vértices da parte inferior do próximo triângulo
            float x4 = raio * sin(theta2) * cos(phi2);
            float y4 = raio * cos(theta2);
            float z4 = raio * sin(theta2) * sin(phi2);

            // Desenhando os dois triângulos que formam uma face da esfera
            glBegin(GL_TRIANGLES);

            glColor3f(1.0f, 1.0f, 1.0f); 
            glVertex3f(x1, y1, z1);
            glVertex3f(x3, y3, z3);
            glVertex3f(x2, y2, z2);

            glColor3f(1.0f, 1.0f, 1.0f); 
            glVertex3f(x2, y2, z2);
            glVertex3f(x3, y3, z3);
            glVertex3f(x4, y4, z4);

            glEnd();
        }
    }
}

// Função de callback do mouse para controlar a rotação
void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    double deltaX = xpos - lastX;
    double deltaY = ypos - lastY;

    // Atualiza os ângulos de rotação com base no movimento do mouse
    anguloX += deltaY * 0.1f; // Controla a rotação ao redor do eixo X
    anguloY += deltaX * 0.1f; // Controla a rotação ao redor do eixo Y

    lastX = xpos;  // Atualiza a posição do mouse
    lastY = ypos;
}

int main() {
    if (!glfwInit()) {
        fprintf(stderr, "Erro ao iniciar GLFW\n");
        return -1;
    }

    GLFWwindow* janela = glfwCreateWindow(800, 600, "Esfera em OpenGL", NULL, NULL);
    if (!janela) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(janela);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Fundo preto
    glEnable(GL_DEPTH_TEST);  // Habilita o teste de profundidade

    // Definir a função de callback para capturar o movimento do mouse
    glfwSetCursorPosCallback(janela, mouse_callback);

    // Configuração da perspectiva
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();  // Reseta a matriz de projeção
    gluPerspective(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);  // Projeção perspectiva
    glMatrixMode(GL_MODELVIEW);

    while (!glfwWindowShouldClose(janela)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpa a tela

        glLoadIdentity(); // Reseta a matriz de transformação
        glTranslatef(0.0f, 0.0f, -2.5f); // Move a esfera para frente

        // Aplica as rotações com base nos movimentos do mouse
        glRotatef(anguloX, 1.0f, 0.0f, 0.0f);  // Rotaciona no eixo X
        glRotatef(anguloY, 0.0f, 1.0f, 0.0f);  // Rotaciona no eixo Y

        desenhar_esfera(1.0f, 50, 50);  // Raio 1.0, 50 segmentos, 50 fatias

        glfwSwapBuffers(janela);  // Atualiza a tela
        glfwPollEvents();         // Processa eventos (teclado, mouse)
    }

    glfwDestroyWindow(janela);
    glfwTerminate();
    return 0;
}

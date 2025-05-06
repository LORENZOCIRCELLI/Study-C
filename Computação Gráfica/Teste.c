#include <GLFW/glfw3.h>
#include <stdio.h>

float x = 0.0f, y = 0.0f;  // Posição inicial do triângulo
float velocidade = 0.01f;    // Velocidade do movimento


void desenhar_triangulo() {
    glBegin(GL_TRIANGLES);           // Início do desenho do triângulo
        glColor3f(1.0f, 0.0f, 0.0f); // Cor: vermelho
        glVertex2f(-0.5f + x, -0.5f + y);    // Vértice inferior esquerdo

        glColor3f(0.0f, 1.0f, 0.0f); // Cor: verde
        glVertex2f(0.5f + x, -0.5f + y);     // Vértice inferior direito

        glColor3f(0.0f, 0.0f, 1.0f); // Cor: azul
        glVertex2f(0.0f + x, 0.5f + y);      // Vértice superior
    glEnd();                         // Fim do desenho
}


void desenhar_eixo_x(){
    glLineWidth(1.0f);        
    glBegin(GL_LINES);

        glColor3f(1.0f,1.0f,1.0f);
        glVertex2f(-1.0f, 0.0f);
        glVertex2f(1.0f,0.0f);

        glEnd();

    

}

void desenhar_eixo_y(){
    glLineWidth(1.0f);        
    glBegin(GL_LINES);

    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.0f,1.0f);
    glVertex2f(0.0f,-1.0f);

    glEnd();

}

int main(void) {
    if (!glfwInit()) {
        fprintf(stderr, "Falha ao inicializar o GLFW\n");
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "Olá, GLFW!", NULL, NULL);
    if (!window) {
        glfwTerminate();
        fprintf(stderr, "Falha ao criar a window\n");
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {


        // Verifica as teclas pressionadas
        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
            x -= velocidade;
        }
        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
            x += velocidade;
        }
        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
            y += velocidade;
        }
        if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
            y -= velocidade;
        }
        glClear(GL_COLOR_BUFFER_BIT);

        desenhar_eixo_y();
        desenhar_eixo_x();

        desenhar_triangulo();



        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
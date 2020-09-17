#include <stdlib.h>
#include <GL/glut.h>

#define janela_altura 600
#define janela_largura 600


void keyboard(unsigned char key, int x, int y);
void resize(GLsizei w, GLsizei h);
void display(void);


int main(int argc, char** argv)
{
    glutInit(&argc, argv);  // controla se o sistema operacional tem suporte a janelas.

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // quantidade de buffer de cores e que o padrao de cores é RGB ou RGBA

    glutInitWindowSize(janela_altura, janela_largura);  // tamanho da janela

    //glutFullScreen();  // full screen

    glutInitWindowPosition(100, 100); // posicao inicial da janela

    glutCreateWindow("Casa");   /// cria a janela -nome da janela 

    glutKeyboardFunc(&keyboard);// funcao de chamar o teclado 

    glutReshapeFunc(&resize); //funcao de redimencionar a tela

    glutDisplayFunc(display);

    glutMainLoop(); //redesenhada

    return EXIT_SUCCESS;
}


void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case '\x1B':
        exit(EXIT_SUCCESS);
        break;
    }
}

void resize(GLsizei w, GLsizei h)
{

    if (h == 0) h = 1;  

    glViewport(0, 0, w, h); 

 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

   
    if (w <= h)
    {
        gluOrtho2D(0.0f, janela_altura, 0.0f, janela_largura * h / w);
    }
    else
    {
        gluOrtho2D(0.0f, janela_altura * w / h, 0.0f, janela_largura);
    }
    glMatrixMode(GL_MODELVIEW);


}

void display()
{
    glMatrixMode(GL_MODELVIEW); //coordenadas da camera
    glLoadIdentity(); //zera a matriz 
    glClearColor(0.0f, 0.8f, 1.0f, 1.0f);  // cor do fundo

    glClear(GL_COLOR_BUFFER_BIT);  // limpa a tela com a cor do fundo

    

    glBegin(GL_QUADS);
        glColor3f(0.3f, 0.9f, 0.3f);
        glVertex2i(0, 110);
        glVertex2i(0, 0);
        glVertex2i(700, 0);
        glVertex2i(700, 110);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.8f, 0.7f);
        glVertex2i(20, 100);
        glVertex2i(20, 5);
        glVertex2i(200, 5);
        glVertex2i(200, 100);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.7f, 0.2f, 0.1f);
        glVertex2i(110, 250);
        glVertex2i(220, 100);
        glVertex2i(0, 100);
        glVertex2i(220, 250);
    glEnd();


    glBegin(GL_QUADS);
        glColor3f(0.6f, 0.2f, 0.1f);
        glVertex2i(160, 50);
        glVertex2i(160, 5);
        glVertex2i(130, 5);
        glVertex2i(130, 50);
    glEnd();

    glBegin(GL_POINTS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2i(155, 25);
    glEnd();

        glEnable(GL_POINT_SMOOTH);
        glEnable(GL_BLEND);
        glBegin(GL_POINT_SMOOTH);
        glPointSize(3);
    glEnd();


    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2i(90, 30);
        glVertex2i(90, 50);
        glColor3f(0.2f, 0.7f, 1.0f);
        glVertex2i(60, 50);
        glVertex2i(60, 30);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.3f, 0.1f, 0.0f);
        glVertex2i(500, 10);
        glVertex2i(500, 120);
        glVertex2i(470, 120);
        glVertex2i(470, 10);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.3f, 0.0f);
        glVertex2i(480, 250);
        glVertex2i(520, 100);
        glVertex2i(450, 100);
    glEnd();




    glFlush(); 


}




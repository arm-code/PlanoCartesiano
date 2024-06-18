#include<GL/glut.h>
#include <cstdlib>
#include <ctime>

void init(void);
void mostrar(void);
void plano2D(void);
void drawTriangle(int x1, int x2, int h);
void drawTriangleWithGLTriangle(int x1, int x2, int h);

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	//inicializa glut
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //establece el modo de 
	glutInitWindowPosition(50, 100); // coloca la ventana de despliegue en 
	glutInitWindowSize(400, 400); //establce ancho y altura de la ventana 
	glutCreateWindow("First Program"); // título de la ventana
	init();// fija o establece los atributos
	glutDisplayFunc(mostrar); //llama a la funcion display cuando se abre la 
	glutMainLoop();//muestra todo y espera
}

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-400.0, 400.0, -400.0, 400.0);
}

void mostrar(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	plano2D();
	drawTriangle(20, 20, 250);
	glFlush();
}

void plano2D(void) {
	// Lineas  en el eje Y
	glColor3f(0.9, 0.9, 0.9);
	for (int i = -400; i <= 400; i += 20) {
		glBegin(GL_LINES);
		glVertex2i(-400, i);
		glVertex2i(400, i);
		glEnd();
	}
	// Lineas dej eje X
	glColor3f(0.9, 0.9, 0.9);
	for (int i = -400; i <= 400; i += 20) {
		glBegin(GL_LINES);
		glVertex2i(i, -400);
		glVertex2i(i, 400);
		glEnd();
	}

	// eje X negativo
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(0, 0);
	glVertex2i(-400, 0);
	glEnd();

	// eje X
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(0, 0);
	glVertex2i(400, 0);
	glEnd();


	// eje Y negativo
	glColor3f(.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex2i(0, 0);
	glVertex2i(0, -400);
	glEnd();


	// eje Y
	glColor3f(.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex2i(0, 0);
	glVertex2i(0, 400);
	glEnd();




	glFlush();

}


void drawTriangleWithGLTriangle(int x1, int y1, int h) {
	glColor3f(0.0, 1.0, 0.0); // Color verde para el triángulo
	glBegin(GL_TRIANGLES);

	// Vertice 1
	glVertex2i(x1, y1);

	// Vertice 2
	glVertex2i(x1 + h, y1);

	// Vertice 3
	glVertex2i(x1 + h / 2, y1 + h);

	glEnd();
}

void drawTriangle(int x1, int y1, int h) {

	// Formulas
	int x2 = x1 + h;
	int y2 = y1;
	int x3 = x1 + h / 2;
	int y3 = y1 + h;

	glColor3f(0.0, 1.0, 0.0);

	// Line 1
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();

	// Line 2
	glBegin(GL_LINES);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);
	glEnd();

	// Line 3
	glBegin(GL_LINES);
	glVertex2i(x3, y3);
	glVertex2i(x1, y1);
	glEnd();
}

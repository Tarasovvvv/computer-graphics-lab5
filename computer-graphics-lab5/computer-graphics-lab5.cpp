#include ".\GL\freeglut.h"
#include <cmath>
using namespace std;
/*
height - Высота конуса
dh - Изменение высоты конуса
red, green, blue  - Доли красного, зеленого, синего цветов соответственно
*/
float height = 1.0f, dh, red = 1.0f, green = 0.0f, blue = 0.0f;

/*
Метод display отрисовывает конус с текущими параметрами
	a - радиус основания конуса по оси ОХ
	b - радиус основания конуса по оси ОY
	numSegments - Количество сегментов основания конуса
	angle - угол между соседними сегментами
*/
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glBegin(GL_POLYGON);
	glColor3f(red, green, blue);
	glVertex2f(0.0f, -0.3f + height);
	int numSegments = 100;
	float a = 0.5f, b = 0.3f;
	for (int i = 0; i <= numSegments; i++) {
		float angle = 6.283185307f * i / numSegments;
		glVertex2f(a * cos(angle), b * sin(angle) - 0.3f);
	}
	glEnd();
	glutSwapBuffers();
}

/*
Метод main создает окно приложения и запускает анимацию через метод update
*/
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(830 * 1.65, 640 * 1.65);
	glutCreateWindow("Анимация для 5-ой лабораторной");
	glClearColor(0.05078125f, 0.06640625f, 0.08984375f, 1.0f);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
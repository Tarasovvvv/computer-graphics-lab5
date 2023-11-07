#include ".\GL\freeglut.h"
#include <cmath>
using namespace std;
/*
stage - Номер этап смены цвета (всего 7 этапов)
height - Высота конуса
dh - Изменение высоты конуса
red, green, blue  - Доли красного, зеленого, синего цветов соответственно
dc - Изменение доли цвета
*/
int stage = 1;
float height = 1.0f, dh, red = 1.0f, green = 0.0f, blue = 0.0f, dc = 0.01;

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
Метод update изменяет высоту и цвет конуса,
затем вызывает метод display для отрисовки результата,
после чего вызывает сам себя для продолжения анимации
*/
void update(int value)
{
	if (height >= 1.0f) dh = -0.01f;
	else if (height <= 0.0f) dh = 0.01f;
	height += dh;
	switch (stage) {
	case(1):
		red += dc;
		stage = (red < 1.0f ? 1 : 2);
		break;
	case(2):
		blue += dc;
		stage = (blue < 1.0f ? 2 : 3);
		break;
	case(3):
		red -= dc;
		stage = (red > 0.0f ? 3 : 4);
		break;
	case(4):
		green += dc;
		stage = (green < 1.0f ? 4 : 5);
		break;
	case(5):
		blue -= dc;
		stage = (blue > 0.0f ? 5 : 6);
		break;
	case(6):
		red += dc;
		stage = (red < 1.0f ? 6 : 7);
		break;
	case(7):
		green -= dc;
		stage = (green > 0.0f ? 7 : 1);
		break;
	}
	glutPostRedisplay();
	glutTimerFunc(16, update, 0);
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
	glutTimerFunc(0, update, 0);
	glutMainLoop();
	return 0;
}
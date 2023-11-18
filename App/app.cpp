#include "..\vcpkg\packages\freeglut_x64-windows\include\GL\freeglut.h"
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

/*
	stage - Номер этап смены цвета (всего 7 этапов)
	height - Высота конуса (нижняя граница экрана: -1.0f, верхняя: 1.0f)
	dh - Изменение высоты конуса
	red, green, blue  - Доли красного, зеленого, синего цветов соответственно
		(максимальное и минимальное значение доли цвета 1.0f и 0.0f соответственно)
	dc - Изменение доли цвета
*/
int stage = 1;
float height = 1.0f, dh;
float red = 1.0f, green = 0.0f, blue = 0.0f, dc = 0.01f;

/*
Метод display отрисовывает конус с текущими параметрами
	SegmentsCount - Количество сегментов основания конуса
	EllipseBaseX - координата основания конуса по оси ОХ
	EllipseBaseY - координата основания конуса по оси ОY
	EllipseRadiusX - радиус основания конуса по оси ОХ
	EllipseRadiusY - радиус основания конуса по оси ОY
	angle - угол между соседними сегментами
*/
void display()
{
	const int SegmentsCount = 100;
	const float EllipseBaseX = 0.0f;
	const float EllipseBaseY = -0.3f;
	const float EllipseRadiusX = 0.5f;
	const float EllipseRadiusY = 0.3f;

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glBegin(GL_POLYGON);
	glColor3f(red, green, blue);
	glVertex2f(EllipseBaseX, EllipseBaseY + height);
	for (size_t i = 0; i <= SegmentsCount; i++) {
		float angle = 2 * M_PI * i / SegmentsCount;
		glVertex2f(EllipseRadiusX * cos(angle), EllipseRadiusY * sin(angle) - 0.3f);
	}
	glEnd();
	glutSwapBuffers();
}

/*
Метод update изменяет высоту и цвет конуса,
затем вызывает метод display для отрисовки результата,
после чего вызывает сам себя для продолжения анимации
	MaxColorValue - максимальное значение, которое может принимать переменная цвета
	MinColorValue - минимальное значение, которое может принимать переменная цвета
	TimeBeforeUpdate - время до следующего вызова update в миллисекундах
	value - значение, передаваемое в update
*/
void update(int value)
{
	const float MaxColorValue = 1.0f;
	const float MinColorValue = 0.0f;
	const int TimeBeforeUpdate = 16;

	if (height >= 1.0f) dh = -0.01f;
	else if (height <= 0.0f) dh = 0.01f;
	height += dh;
	switch (stage) {
	case(1):
		red += dc;
		stage = (red < MaxColorValue ? 1 : 2);
		break;
	case(2):
		blue += dc;
		stage = (blue < MaxColorValue ? 2 : 3);
		break;
	case(3):
		red -= dc;
		stage = (red > MinColorValue ? 3 : 4);
		break;
	case(4):
		green += dc;
		stage = (green < MaxColorValue ? 4 : 5);
		break;
	case(5):
		blue -= dc;
		stage = (blue > MinColorValue ? 5 : 6);
		break;
	case(6):
		red += dc;
		stage = (red < MaxColorValue ? 6 : 7);
		break;
	case(7):
		green -= dc;
		stage = (green > MinColorValue ? 7 : 1);
		break;
	}
	glutPostRedisplay();
	glutTimerFunc(TimeBeforeUpdate, update, value);
}

/*
Метод main создает окно приложения и запускает анимацию через метод update
	WindowWidth - ширина окна приложения
	WindowHeight - высота окна приложения
	TimeBeforeUpdate - время до следующего вызова update в миллисекундах
	BackgroundColor - компоненты red, green, blue, alpha(непрозрачность) цвета фона
	TimerFuncValue - значение для передачи в функцию update
*/
int main(int argc, char** argv)
{
	const int WindowWidth = 1370;
	const int WindowHeight = 1056;
	const int TimerFuncValue = 0;
	const int TimeBeforeUpdate = 0;
	const double BackgroundColor[4] = { 0.05078125f, 0.06640625f, 0.08984375f, 1.0f };

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WindowWidth, WindowHeight);
	glutCreateWindow("Анимация для 5-ой лабораторной");
	glClearColor(BackgroundColor[0], BackgroundColor[1], BackgroundColor[2], BackgroundColor[3]);
	glutDisplayFunc(display);
	glutTimerFunc(TimeBeforeUpdate, update, TimerFuncValue);
	glutMainLoop();
	return 0;
}
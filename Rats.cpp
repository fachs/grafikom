#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#define SPEED 20.0

float i = 0.0, m = 0.0, n = 0.0, o = 0.0, c = 0.0;

int light = 1, day = 1, plane = 0, comet = 0, xm = 900, tikus = 0;
char ch;

void declare(char *string)
{
	while (*string)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
}

void draw_pixel(GLint cx, GLint cy)
{

	glBegin(GL_POINTS);
	glVertex2i(cx, cy);
	glEnd();
}

void plotpixels(GLint h, GLint k, GLint x, GLint y)
{
	draw_pixel(x + h, y + k);
	draw_pixel(-x + h, y + k);
	draw_pixel(x + h, -y + k);
	draw_pixel(-x + h, -y + k);
	draw_pixel(y + h, x + k);
	draw_pixel(-y + h, x + k);
	draw_pixel(y + h, -x + k);
	draw_pixel(-y + h, -x + k);
}

void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d = 1 - r, x = 0, y = r;
	while (y > x)
	{
		plotpixels(h, k, x, y);
		if (d < 0)
			d += 2 * x + 3;
		else
		{
			d += 2 * (x - y) + 5;
			--y;
		}
		++x;
	}
	plotpixels(h, k, x, y);
}

void draw_object()
{
	int l;
	if (day == 1)
	{
		//sky
		glColor3f(0.0, 0.9, 0.9);
		glBegin(GL_POLYGON);
		glVertex2f(0, 380);
		glVertex2f(0, 700);
		glVertex2f(1100, 700);
		glVertex2f(1100, 380);
		glEnd();

		//sun

		for (l = 0; l <= 35; l++)
		{
			glColor3f(1.0, 0.9, 0.0);
			draw_circle(100, 625, l);
		}
		//cloud1

		for (l = 0; l <= 20; l++)
		{
			glColor3f(1.0, 1.0, 1.0);
			draw_circle(160 + m, 625, l);
		}

		for (l = 0; l <= 35; l++)
		{
			glColor3f(1.0, 1.0, 1.0);
			draw_circle(200 + m, 625, l);
			draw_circle(225 + m, 625, l);
		}

		for (l = 0; l <= 20; l++)
		{
			glColor3f(1.0, 1.0, 1.0);
			draw_circle(265 + m, 625, l);
		}

		//cloud2

		for (l = 0; l <= 20; l++)
		{
			glColor3f(1.0, 1.0, 1.0);
			draw_circle(370 + m, 615, l);
		}

		for (l = 0; l <= 35; l++)
		{

			glColor3f(1.0, 1.0, 1.0);
			draw_circle(410 + m, 615, l);
			draw_circle(435 + m, 615, l);
			draw_circle(470 + m, 615, l);
		}

		for (l = 0; l <= 20; l++)
		{
			glColor3f(1.0, 1.0, 1.0);
			draw_circle(500 + m, 615, l);
		}

		//grass
		glColor3f(0.0, 0.9, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(0, 160);
		glVertex2f(0, 380);
		glVertex2f(1100, 380);
		glVertex2f(1100, 160);
		glEnd();
		
		glColor3f(0.0, 0.9, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(0,160);
		glVertex2f(0,250);
		glVertex2f(1100,250);
		glVertex2f(1100,160);
		glEnd();
		
		glColor3f(0.647059,0.164706,0.164706);
		glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(0,150);
		glVertex2f(1100,150);
		glVertex2f(1100,0);
		glEnd();
	}


	if (tikus == 1)
	{
//		glColor3f(0.329412, 0.329412, 0.329412); 
//	    glBegin(GL_POLYGON);
//	    glVertex2f(0.5 + i - xm, 5.0);
//	    glVertex2f(2.0 + i - xm, 12.0);
//	    glVertex2f(15.0 + i - xm, 12.0);
//	    glVertex2f(19.5 + i - xm, 5.0);
//	    glEnd();
//	
//	    glColor3f(0.90, 0.91, 0.98); 
//	    glBegin(GL_POLYGON);
//	    glVertex2f(16.9 + i - xm, 6.0);
//	    glVertex2f(16.9 + i - xm, 7.2);
//	    glVertex2f(17.9 + i - xm, 7.2);
//	    glVertex2f(17.9 + i - xm, 6.0);
//	    glEnd();
		
		glColor3f(0.329412, 0.329412, 0.329412); 
		glBegin(GL_POLYGON);
		glVertex2f(-500+i-xm,150);  //kanan atas
		glVertex2f(-600+i-xm,300); //kanan bawah
		glVertex2f(-800+i-xm,300);
		glVertex2f(-850+i-xm,150);
		glEnd();
		
//		for (l = 0; l <= 35; l++)
//		{
//			glColor3f(0.90, 0.91, 0.98); 
//			draw_circle(-450 +m, 130, l);
//		}

	}
	glFlush();
}

void idle()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);

	if (light == 0 && (i >= 0 && i <= 1150))
	{

		i += SPEED / 10;
		m += SPEED / 150;
		n -= 2;
		o += 0.2;
		c += 2;
	}

	if (light == 0 && (i >= 2600 && i <= 3000))
	{

		i += SPEED / 10;
		m += SPEED / 150;
		n -= 2;
		o += 0.2;
		c += 2;
	}

	if (light == 0)
	{
		i = i;
		m += SPEED / 150;
		n -= 2;
		o += 0.2;
		c += 2;
	}

	else
	{
		i += SPEED / 10;
		m += SPEED / 150;
		n -= 2;
		o += 0.2;
		c += 2;
	}
	if (i > 3500)
		i = 0.0;
	if (m > 1100)
		m = 0.0;
	if (o > 75)
	{
		plane = 0;
	}
	if (c > 500)
	{
		comet = 0;
	}
	glutPostRedisplay();
}

void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_UP)
		exit(0);
}

void keyboardFunc(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 't':
	case 'T':
		tikus = 1;
		i = 0;
		break;
	};
}

void main_menu(int index)
{
	switch (index)
	{
	case 1:
		if (index == 1)
		{
			plane = 1;
			o = n = 0.0;
		}
		break;

	case 2:
		if (index == 2)
		{
			comet = 1;
			c = 0.0;
		}
		break;
	}
}

void myinit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 1.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1100.0, 0.0, 700.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	draw_object();
	glFlush();
}

int main(int argc, char **argv)
{
	int c_menu;
	printf("--------------------------------------------------------------------------------");
	printf("                    WELCOME TO TIKUS LIAR GAME                                  ");
	printf("--------------------------------------------------------------------------------");
	printf("Press 't' or 'T' Tikus will be shown.\n\n");
	printf("Press LEFT MOUSE BUTTON to quit the program. \n\n\n");
	printf("Press any key and Hit ENTER.\n");
	scanf("%s", &ch);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1100.0, 700.0);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Tikus Liar");
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboardFunc);
	glutMouseFunc(mouse);
	myinit();
	c_menu = glutCreateMenu(main_menu);
	glutAddMenuEntry("Aeroplane", 1);
	glutAddMenuEntry("Comet", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}

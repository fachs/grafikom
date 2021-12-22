#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<time.h>

//void rock();
void display1();
void display2();
void display3();
void rat();
void soil();

struct timespec jmp, jmp2;

GLint a=0,b=0,c=0,d=0,e=0,f=0,g=500,h=600,x=0,i=0;
GLfloat theta=0.0;

void update(int value)
{
	a+=20.0;
	glutPostRedisplay();
	glutTimerFunc(200,update,0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	display1();

	if(a>950)

	{
		b+=20;
		display2();
	}
	if(b>250)
	{

		c+=10;
		display3();

	}

	glFlush();
	glutSwapBuffers();
}


void display1()
{
	glPushMatrix();
	glTranslated(a,75,0.0);
	rat();
	glPopMatrix();
	soil();
}

void display2()
{

	glClear(GL_COLOR_BUFFER_BIT);
//	rock();
	glPushMatrix();
	glTranslated(b,75,0.0);
	rat();
	glPopMatrix();
	soil();

}

void display3()
{
	glClear(GL_COLOR_BUFFER_BIT);
	x-=1;
//	rock();
	glPushMatrix();
	glTranslated(c,75,0.0);
//	glRotated(-15,0,0,1);
	rat();
	glPopMatrix();
	soil();

}

void soil()
{
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(1000,0);
		glVertex2f(1000,200);
		glVertex2f(0,200);
	glEnd();
	
	glColor3f(0.1f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(1000,0);
		glVertex2f(1000,150);
		glVertex2f(0,150);
	glEnd();
}

void rat()
{
	glScaled(24,24,0);
	
	glColor3f(0.329412,0.329412,0.329412); //base
	glBegin(GL_POLYGON);
		glVertex2f(0.5,5.0);
		glVertex2f(2.0,12.0);
		glVertex2f(15.0,12.0);
		glVertex2f(19.5,5.0);
	glEnd();
	
	glColor3f(0.90,0.91,0.98); //window
	glBegin(GL_POLYGON);
		glVertex2f(16.9,6.0);
		glVertex2f(16.9,7.2);
		glVertex2f(17.9,7.2);
		glVertex2f(17.9,6.0);
	glEnd();
	
}

void myinit()
{
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glColor3f(1.0,0.0,0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,999.0,0.0,799.0);
}

int main(int argc, char* argv[])

{
	int chs;
	printf("Step1: Type Any Key and Hit Enter\n");
	printf("\n******************************************************************\n\n");
	scanf("%d",&chs);
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1024.0,768.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("The Rat");
	glutDisplayFunc(display);
	myinit();
	glutTimerFunc(100,update,0);
	glutMainLoop();
	return 0;
}

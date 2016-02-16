/*game_3_1	*/
/*YusukeKato*/
/*2016.2.13	*/
/*2016.2.15	*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#define PI 3.14159265

/*���_�̈ʒu*/
static GLdouble x=0.0,y=0.0,z=0.0; 
/*���_�̌���*/
static GLdouble r=180.0; 
/*�t���O*/
static GLint fg1=0,fg2=0;
static GLint flg1=0;
static GLint flag1=0;
/* ���̍��W */
static GLfloat x1=0.0,y1=0.0,z1=0.0;
static GLfloat x2=3.0,y2=0.0,z2=3.0;
static GLfloat x3=-10.0,y3=0.0,z3=10.0;
static GLfloat x4=-10.0,y4=0.0,z4=-10.0;
static GLfloat x5=10.0,y5=0.0,z5=-10.0;

static GLint i=0,j=0;

static GLfloat dy=0.0,ddy=0.0,dt=0.01;

void scene(void)
{
	/* ���̂̐F */
  	static GLfloat red[] = { 0.8, 0.3, 0.3, 1.0 };
  	static GLfloat green[] = { 0.3, 0.8, 0.3, 1.0 };
  	static GLfloat blue[] = { 0.3, 0.3, 0.8, 1.0 };
  	static GLfloat yellow[] = { 0.8, 0.8, 0.2, 1.0 };
	static GLfloat gray[] = { 0.4, 0.4, 0.4, 1.0 };
  	static GLfloat ground[][4] = {
    	{ 0.6, 0.6, 0.6, 1.0 },
    	{ 0.3, 0.3, 0.3, 1.0 }
  	};
	/********** �O���[�̔�(�ŏ�) **********/
	for(j=0;j<3;j++)
	{
		x1=30;
		y1=0.0;
		z1=-30;
		if(j==1) y1=1.0;
		if(j==2) y1=2.0;
		for(i=0;i<240;i++)
		{
			glPushMatrix();
			glTranslated(x1, y1, z1);
  			glMaterialfv(GL_FRONT, GL_DIFFUSE, gray);
  			glutSolidCube(1.0);
			glPopMatrix();
			if(i>=0&&i<60) z1=z1+1.0;
			else if(i>=60&&i<120) x1=x1-1.0;
			else if(i>=120&&i<180) z1=z1-1.0;
			else if(i>=180&&i<240) x1=x1+1.0;
			else break;
		}
	}
	/********** �O���[�̔�(�Ō�) **********/
	
	/********** �Ԃ��� **********/
	glPushMatrix();
	glTranslated(x2, y2, z2);
  	glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
  	glutSolidCube(1.0);
	glPopMatrix();
	/****************************/
	
  	/********** �΂̔� **********/
  	glPushMatrix();
  	glTranslated(x3, y3, z3);
  	glMaterialfv(GL_FRONT, GL_DIFFUSE, green);
  	glutSolidCube(1.0);
  	glPopMatrix();
	/****************************/
	
  	/********** ���� **********/
  	glPushMatrix();
  	glTranslated(x4, y4, z4);
  	glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
  	glutSolidCube(1.0);
  	glPopMatrix();
	/****************************/
	
  	/********** ���F���� **********/
	glPushMatrix();
  	glTranslated(x5, y5, z5);
  	glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow);
  	glutSolidCube(1.0);
  	glPopMatrix();
	/******************************/
	
	/********** �n�� **********/
  	glBegin(GL_QUADS);
  	glNormal3d(0.0, 1.0, 0.0);
  	for (j = -35; j <= 35; ++j) {
    	for (i = -35; i <= 35; ++i) {
      		glMaterialfv(GL_FRONT, GL_DIFFUSE, ground[(i + j) & 1]);
      		glVertex3d((GLdouble)i,-0.5, (GLdouble)j);
      		glVertex3d((GLdouble)i,-0.5, (GLdouble)(j + 1));
      		glVertex3d((GLdouble)(i + 1),-0.5, (GLdouble)(j + 1));
      		glVertex3d((GLdouble)(i + 1),-0.5,(GLdouble)j);
    	}
 	 }
	 glEnd();
	 /*************************/
}

void display(void)
{
	/* �����̈ʒu */
	static GLfloat light0pos[] = { 0.0, 3.0, 5.0, 1.0 };
	static GLfloat light1pos[] = { 5.0, 3.0, 0.0, 1.0 };
  	/* ��ʃN���A */
  	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  	/* ���f���r���[�ϊ��s��̏����� */
  	glLoadIdentity();
  	/* ���_�̈ړ� */
  	glRotated(r, 0.0, 1.0, 0.0);
  	glTranslated(x,y,z);
	/* �����̈ʒu��ݒ� */
  	glLightfv(GL_LIGHT0, GL_POSITION, light0pos);
	glLightfv(GL_LIGHT1, GL_POSITION, light1pos);
  	/* �V�[���̕`�� */
  	scene();
  	glFlush();
}

void reshape(int w, int h)
{
  	/* �E�B���h�E�S�̂��r���[�|�[�g�ɂ��� */
  	glViewport(0, 0, w, h);
  	/* �����ϊ��s��̎w�� */
  	glMatrixMode(GL_PROJECTION);
  	/* �����ϊ��s��̏����� */
  	glLoadIdentity();
  	gluPerspective(30.0, (double)w / (double)h, 1.0, 100.0);
  	/* ���f���r���[�ϊ��s��̎w�� */
  	glMatrixMode(GL_MODELVIEW);
}

void simu(void)
{
	/***** �W�����v *****/
	y = y + dy * dt + ddy * dt * dt / 2.0;
	dy = dy + ddy * dt;
	if(y>0.0)
	{
		y=0.0;
		dy=0.0;
		ddy=0.0;
	}
	//��K��� -3.0�܂�
	if(y>-4.0&&y<-3.0) y=-3.0;
	/********************/
	/***** ��] *****/
	if(r>360) r=0;
	if(r<0) r=360;
	/****************/
	/***** ���ړ� *****/
	/* ��1 */
	if(flg1==0)
	{
		x2=x2-0.01;
		if(x2<-3) flg1=1;
	}
	if(flg1==1)
	{
		z2=z2-0.01;
		if(z2<-3) flg1=2;
	}
	if(flg1==2)
	{
		x2=x2+0.01;
		if(x2>3) flg1=3;
	}
	if(flg1==3)
	{
		z2=z2+0.01;
		if(z2>3) flg1=0;
	}
	/*******/
	/******************/
	/***** 'w''s''d''a' *****/
	//front
	if(fg2==1&&r>=0&&r<90)
	{
		 x = x - 0.1 * sin(r*(PI/180.0));
		 z = z + 0.1 * cos(r*(PI/180.0));
	}
	if(fg2==1&&r>=90&&r<180)
	{
		 x = x - 0.1 * sin(r*(PI/180.0));
		 z = z + 0.1 * cos(r*(PI/180.0));
	}
	if(fg2==1&&r>=180&&r<270)
	{
		 x = x - 0.1 * sin(r*(PI/180.0));
		 z = z + 0.1 * cos(r*(PI/180.0));
	}
	if(fg2==1&&r>=270&&r<360)
	{
		 x = x - 0.1 * sin(r*(PI/180.0));
		 z = z + 0.1 * cos(r*(PI/180.0));
	}
	//back
	if(fg2==2&&r>=0&&r<90)
	{
		 x = x + 0.1 * sin(r*(PI/180.0));
		 z = z - 0.1 * cos(r*(PI/180.0));
	}
	if(fg2==2&&r>=90&&r<180)
	{
		 x = x + 0.1 * sin(r*(PI/180.0));
		 z = z - 0.1 * cos(r*(PI/180.0));
	}
	if(fg2==2&&r>=180&&r<270)
	{
		 x = x + 0.1 * sin(r*(PI/180.0));
		 z = z - 0.1 * cos(r*(PI/180.0));
	}
	if(fg2==2&&r>=270&&r<360)
	{
		 x = x + 0.1 * sin(r*(PI/180.0));
		 z = z - 0.1 * cos(r*(PI/180.0));
	}
	if(fg2==3) r = r + 1.0;
	if(fg2==4) r = r - 1.0;
	if(fg2==5)
	{
		dy=-1.0;
		ddy=0.98;
	}
	/***********************/
	
	/********** �Փˏ��� **********/
	if(z>29) fg1=1;
	if(z<-29) fg1=2;
	if(x>29) fg1=3;
	if(x<-29) fg1=4;
	/******************************/
	switch(fg1)
	{
		case 1:
		z=29;
		break;
		case 2:
		z=-29;
		break;
		case 3:
		x=29;
		break;
		case 4:
		x=-29;
		break;
		default:
		break;
	}
	/******************************/
	if(fabs(x-x3)*fabs(x-x3)+fabs(z-z3)*fabs(z-z3)<4) flag1=1;
	if(flag1==1) y=-5.0;
	glutPostRedisplay();
	fg1=0;
	fg2=0;
}

void mouse(int button, int state, int x, int y)
{
  	switch (button) 
  	{
    	case GLUT_LEFT_BUTTON:
     		if ( state == GLUT_DOWN)
     			glutIdleFunc(simu);
     	break;
     	case GLUT_RIGHT_BUTTON:
			if ( state == GLUT_DOWN)
     		glutIdleFunc(NULL);
     	break; 
     	default:
     	break; 
  	}
}

void keyboard(unsigned char key, int x, int y)
{
  	/* ESC or q = exit */
  	if 	(key == '\033' || key == 'q') {
    	exit(0);
  	}
  	if ( key == 'w') fg2 = 1;
	if ( key == 's') fg2 = 2;
	if ( key == 'd') fg2 = 3;
	if ( key == 'a') fg2 = 4;
	if ( key == 'e') fg2 = 5;
}

void init(void)
{
  	/* �����ݒ� */
  	glClearColor(1.0, 1.0, 1.0, 0.0);
  	glEnable(GL_DEPTH_TEST);
  	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
  	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
}

int main(int argc, char *argv[])
{
  	glutInit(&argc, argv);
  	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
  	glutInitWindowSize (800, 800);
  	glutInitWindowPosition(100,0);
  	glutCreateWindow(argv[0]);
  	glutDisplayFunc(display);
  	glutReshapeFunc(reshape);
  	glutKeyboardFunc(keyboard);
  	glutMouseFunc(mouse);
  	init();
  	glutMainLoop();
  	return 0;
}
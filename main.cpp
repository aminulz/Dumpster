#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include<GL/glut.h>

#define BLACK 1, 1, 1

//make a global variable -- for tracking the anglular position of camera
double cameraAngle;

void display(){

	//clear the display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(BLACK, 0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/********************
	/ set-up camera here
	********************/
	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);

	//initialize the matrix
	glLoadIdentity();

	//now give three info
	//1. where is the camera (viewer)?
	//2. where is the camera is looking?
	//3. Which direction is the camera's UP direction?

	//instead of CONSTANT information, we will define a circular path.
//	gluLookAt(-30,-30,50,	0,0,0,	0,0,1);

	gluLookAt(.1, 0, 100,		0,0,0,		0,0,1);
	//NOTE: the camera still CONSTANTLY looks at the center


	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);


	/****************************
	/ Add your objects from here
	****************************/
	//add objects

	glColor3f(0,0,1);
	glBegin(GL_LINE_LOOP);
	{

	    glVertex3f(10,0,0);
	    glVertex3f(20,17,0);
	    glVertex3f(0,10,0);
	    glVertex3f(-10,25,0);
	    glVertex3f(-10,8,0);
	    glVertex3f(-30,0,0);
	    glVertex3f(-10,-8,0);
	    glVertex3f(-10,-25,0);
	    glVertex3f(0,-10,0);
	    glVertex3f(20,-17,0);

	}glEnd();



	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
}

void animate(){
	//codes for any changes in Camera

// camera will rotate at 0.1 radians per frame.

	//codes for any changes in Models

	//MISSING SOMETHING?
}

void init(){
	//codes for initialization


	/************************
	/ set-up projection here
	************************/
	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();

	//give PERSPECTIVE parameters
	gluPerspective(70,	1,	0.1,	10000.0);
	//field of view in the Y (vertically)
	//aspect ratio that determines the field of view in the X direction (horizontally)
	//near distance
	//far distance
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("My OpenGL Program");

	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}


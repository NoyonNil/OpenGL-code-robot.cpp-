#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>


//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;
float _a = 0.0;
float daan_pa=-4.0;
float baam_pa=-3.7;
float move_robot=-4.0;
float move_body =-4.0;

//Draws the 3D scene
int playerLife=4;


void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glRotatef(-_cameraAngle, 1.0, 0.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units

    glColor3f(1,0,0);
    glRotatef(move_body,0.0,1.0,0.0);

    glTranslatef(move_robot, 0.0, 0.0);
    glPushMatrix();
    glRotatef(90, 0.0, 1.0, 0.0);

    //glRotatef(_angle, 0.0, 0.0, 0.0);
    glPushMatrix();
    //glRotatef(_angle, 0.0, 1.0, 0.0);
    //glutSolidCube(.5);
    glutSolidSphere(0.3,20,20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,0);
    //glRotatef(_angle, 0.0, 1.0, 0.0);
    glTranslatef(0.0, -0.5, 0.0);
    glutSolidCube(.8);
    glPopMatrix();


    glPushMatrix();
    glColor3f(1,1,1);
    //glRotatef(_angle, 0.0, 1.0, 0.0);
    glTranslatef(0.4, -0.5, 0.0);
    glutSolidCube(.2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0,1,0);
    //glRotatef(_angle, 0.0, 1.0, 0.0);
    glTranslatef(0.4, -0.3, 0.0);
    glutSolidCube(.2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(1,1,1);
   // glRotatef(_angle, 0.0, 1.0, 0.0);
    glTranslatef(-0.4, -0.5, 0.0);
    glutSolidCube(.2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0,1,0);
    //glRotatef(_angle, 0.0, 1.0, 0.0);
    glTranslatef(-0.4, -0.3, 0.0);
    glutSolidCube(.2);
    glPopMatrix();


    // uporer pa
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(0.2, -1.0, 0.0);
    glutSolidCube(.3);
    glPopMatrix();


    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-0.2, -1.0, 0.0);
    glutSolidCube(.3);
    glPopMatrix();

    // nichr pa
    glRotatef(daan_pa,0.0,1.0,0.0);
    glPushMatrix();

     glPushMatrix();
    glColor3f(1,0,1);
    glTranslatef(0.2, -1.2, 0.0);
    glutSolidCube(.2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(1,0,1);
    glTranslatef(-0.2, -1.2, 0.0);
    glutSolidCube(.2);
    glPopMatrix();

    glPopMatrix();

    glRotatef(baam_pa,0.0,1.0,0.0);
    glPushMatrix();

    glPushMatrix();
    glColor3f(1,0,1);
    glTranslatef(0.2, -1.4, 0.0);
    glutSolidCube(.2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(1,0,1);
    glTranslatef(-0.2, -1.4, 0.0);
    glutSolidCube(.2);
    glPopMatrix();

    glPopMatrix();

	glPopMatrix();

	glutSwapBuffers();
}

void update(int value) {
	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	_ang_tri += 2.0f;
	if (_ang_tri > 360) {
		_ang_tri -= 360;
	}
	_a += 0.1;
	if (_a >= 6.5) {
		_a = -4.5;
	}
	daan_pa +=0.6;
	if(daan_pa>=6.5){
        daan_pa =-4.0;
	}
    baam_pa +=0.6;
    if(baam_pa>=6.5){
        baam_pa =-3.5;
    }

    move_robot +=0.5;
    if(move_robot>=6.5){
        move_robot =-4.0;
    }
    move_body +=0.3;
    if(move_body>=6.5){
        move_body = -4.0;
    }

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(900, update, 0);
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1200, 800);

	//Create the window
	glutCreateWindow("Transformations");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);

	glutTimerFunc(500, update, 0); //Add a timer

	glutMainLoop();
	return 0;
}


	/*glBegin(GL_TRIANGLES);

	//Pentagon
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(-0.5, 0.0, 0.0);

	glVertex3f(-0.5, 0.0, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.0, 0.0);

	glVertex3f(-0.5, 0.0, 0.0);
	glVertex3f(0.5, 0.0, 0.0);
	glVertex3f(0.0, 0.5, 0.0);

	glEnd();

*/

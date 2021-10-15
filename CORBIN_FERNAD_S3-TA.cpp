#include <iostream>
#include <GL/glut.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// FERNAD T. CORBIN | BSCSSE | OCTOBER 14, 2021 | S3-TA

void displayfigure();
void arrowkeyMonitor(int key, int x, int y);
void wasdMonitor(unsigned char key, int x, int y);
void mouseMonitor(int button, int state, int x, int y);
void animateString(int value);
float px, py;

GLfloat changecolour[] = {
	255,0,0,
	255,0,0,
	255,0,0
};



int main(int argc, char** argv) {
	
	glutInit(&argc, argv);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(200,50);
	glutCreateWindow("Summative 3 - Technical Assessment | FERNAD T. CORBIN");	
	glutDisplayFunc(displayfigure);
	glutKeyboardFunc(wasdMonitor);
	glutSpecialFunc(arrowkeyMonitor);
	glutMouseFunc(mouseMonitor);
	glutMainLoop();
	
	return 0;
}

void animateString(int value){
	glutTimerFunc(1000,animateString,1);
	if(value == 1){
		px += .1;
		if(px == .5){
			px -= .5;
		}
	}else{
		px -= .1;
	}
	glutPostRedisplay();
}

void mouseMonitor(int button, int state, int x, int y){
	
//	cout << button << endl;
	
	if(button == GLUT_LEFT_BUTTON){
		//DOWN mouse pressed
		if(state == GLUT_DOWN){
			cout << "Left button was clicked..." << endl;
			
		//UP mouse released
		}else if(state == GLUT_UP){
			cout << "Left button was released..." << endl;
		}				
	}else if(button == GLUT_RIGHT_BUTTON){
		//DOWN mouse pressed 
		if(state == GLUT_DOWN){
			cout << "Right button was clicked..." << endl;
			
		//UP mouse released
		}else if(state == GLUT_UP){
			animateString(1);
			cout << "Right button was released..." << endl;
		}
	}else{
		
		cout << "Middle button was clicked..." << endl;
		
	}
	
	//Window Coordinates !Cartesian Plane
//	cout << "X: "<< x << " " << "Y: "<< y << endl;
}

//ARROW KEYS
void arrowkeyMonitor(int key, int x, int y){
	//display input
	cout << key << endl;
	
	//ESC Key
	switch(key){
		case GLUT_KEY_F1:
			glClear(GL_COLOR_BUFFER_BIT);
			glEnableClientState(GL_COLOR_ARRAY);
			glColorPointer(3, GL_FLOAT, 0, changecolour);
			glDisableClientState(GL_COLOR_ARRAY);
			glFlush();
			break;
		
		case GLUT_KEY_UP: 
			
			py += .02f;
			
			break;
		
		case GLUT_KEY_LEFT:
			
			px -= .02f;
			
			break;
			
		case GLUT_KEY_DOWN:
			
			py -= .02f;
			
			break;
				
		case GLUT_KEY_RIGHT:
			
			px += .02f;
			
			break;
			
		default:
			
			px = .00f;
	}
	glutPostRedisplay();
}

//WASD KEYS
void wasdMonitor(unsigned char key, int x, int y){
	//display input
	cout << key << endl;
	
	//ESC Key
	if(key == 27){
		
		exit(0);
		
	}
	switch(key){
		
		case 'w': 
			
			py += .02f;
			
			break;
		
		case 'a':
			
			px -= .02f;
			
			break;
			
		case 's':
			
			py -= .02f;
			
			break;
				
		case 'd':
			
			px += .02f;
			
			break;
			
		default:
			
			px = .00f;
	}
	glutPostRedisplay();
}

void displayfigure(){
	
	glClear(GL_COLOR_BUFFER_BIT);
		//ear
		glBegin(GL_TRIANGLES);
			//left ear (left triangle)
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(-0.6f+px, 0.5f+py, 0.0f);
			glColor3f(0.0f, 1.0f, 1.0f);
			glVertex3f(0.0f+px, 0.5f+py, 0.0f);
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(-0.3f+px, 0.8f+py, 0.0f);
			
			//right ear (right triangle)
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(0.0f+px, 0.5f+py, 0.0f);
			glColor3f(1.0f, 1.0f, 0.0f);
			glVertex3f(0.6f+px, 0.5f+py, 0.0f);
			glColor3f(1.0f, 0.0f, 1.0f);
			glVertex3f(0.3f+px, 0.8f+py, 0.0f);
			
		glEnd();
		
		//head
		glBegin(GL_POLYGON);
		
			//main head (box head)
			glColor3f(1.0f, 1.0f, 0.0f);
			glVertex3f(-0.6f+px, 0.5f+py, 0.0f);
			glColor3f(1.0f, 1.0f, 0.0f);
			glVertex3f(0.6f+px, 0.5f+py, 0.0f);
			glColor3f(1.0f, 1.0f, 0.0f);
			glVertex3f(0.6f+px, 0.0f+py, 0.0f);
			glColor3f(1.0f, 1.0f, 0.0f);
			glVertex3f(-0.6f+px, 0.0f+py, 0.0f);
		glEnd();
		
		//eyes
		glBegin(GL_POLYGON);
		
			//left eye (left box)
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(-0.35f+px, 0.45f+py, 0.0f);
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(-0.2f+px, 0.45f+py, 0.0f);
			glColor3f(0.0f, 1.0f, 1.0f);
			glVertex3f(-0.2f+px, 0.3f+py, 0.0f);
			glColor3f(0.0f, 1.0f, 1.0f);
			glVertex3f(-0.35f+px, 0.3f+py, 0.0f);
	
		glEnd();
		
		glBegin(GL_POLYGON);
		
			//right eye (right box)
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(0.35f+px, 0.45f+py, 0.0f);
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(0.2f+px, 0.45f+py, 0.0f);
			glColor3f(0.0f, 1.0f, 1.0f);
			glVertex3f(0.2f+px, 0.3f+py, 1.0f);
			glColor3f(0.0f, 1.0f, 1.0f);
			glVertex3f(0.35f+px, 0.3f+py, 0.0f);
			
		glEnd();
		
		//nose
		glBegin(GL_TRIANGLES);
		
			//middle nose (nose triangle)
			glColor3f(1.0f, 1.0f, 1.0f);
			glVertex3f(-0.2f+px, 0.15f+py, 0.0f);
			glColor3f(1.0f, 0.0f, 1.0f);
			glVertex3f(0.2f+px, 0.15f+py, 1.0f);
			glColor3f(1.0f, 1.0f, 1.0f);
			glVertex3f(0.0f+px, 0.3f+py, 0.0f);
			
		glEnd();
		
		//mouth
		glBegin(GL_LINES);
		
			//lower line (poker line)
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(-0.2f+px, 0.05f+py, 0.0f);
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(0.2f+px, 0.05f+py, 0.0f);
			
		glEnd();
		
		//body
		glBegin(GL_POLYGON);			
			//whole body (body polygon)
			glColor3f(1.0f, 1.0f, 1.0f);
			glVertex3f(-0.2f+px, -0.9f+py, 0.0f);
			
			glColor3f(1.0f, 0.0f, 1.0f);
			glVertex3f(0.25f+px, -0.9f+py, 0.0f);
			
			glColor3f(1.0f, 1.0f, 1.0f);
			glVertex3f(0.55f+px, -0.45f+py, 1.0f);
			
			glColor3f(1.0f, 0.0f, 1.0f);
			glVertex3f(0.25f+px, 0.0f+py, 0.0f);
			
			glColor3f(1.0f, 1.0f, 1.0f);
			glVertex3f(-0.25f+px, 0.0f+py, 0.0f);
			
			glColor3f(1.0f, 0.0f, 1.0f);
			glVertex3f(-0.55f+px, -0.45f+py, 0.0f);
			
		glEnd();				
	glFlush();
}

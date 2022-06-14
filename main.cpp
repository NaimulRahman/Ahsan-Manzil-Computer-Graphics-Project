#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>>
#include<stdio.h>

# define PI           3.14159265358979323846
void night_rain();
void day();
void night();

GLfloat position = 0.0f;//cloud
GLfloat speed = 0.003f;

GLfloat position1 = 0.0f;//bird
GLfloat speed1 = 0.02f;

GLfloat position2 = 0.0f;//car1
GLfloat speed2 = 0.02f;

GLfloat position3 = 0.0f;//rain
GLfloat speed3 = 0.035f;

GLfloat position4 = 0.0f;//car2
GLfloat speed4 = 0.02f;

/*
void SpecialInput(int key, int x, int y)
{
switch(key)
{case GLUT_KEY_UP:
speed=.5;
break;
case GLUT_KEY_DOWN:
speed=.2;
break;
case GLUT_KEY_LEFT:
speed=.1;

break;
case GLUT_KEY_RIGHT:
speed=.05;
break;}
glutPostRedisplay();} */



void update(int value) {//cloud

    if(position >1.0)
        position = -1.0f;

    position+= speed; //position=position-speed;1-.1=.9

	glutPostRedisplay();


	glutTimerFunc(100, update, 0);
}

void update1(int value) {//bird

    if(position1 >1.0)
        position1 = -1.0f;

    position1+= speed1; //position=position-speed;1-.1=.9

	glutPostRedisplay();


	glutTimerFunc(100, update1, 0);
}


void update2(int value) {//bird

    if(position2 >1.0)
        position2 = -1.0f;

    position2+= speed2; //position=position-speed;1-.1=.9

	glutPostRedisplay();


	glutTimerFunc(100, update2, 0);
}

void update3(int value) {//cloud

    if(position3 <-1.0)
        position3 = -0.f;

    position3-= speed3; //position=position-speed;1-.1=.9

	glutPostRedisplay();


	glutTimerFunc(30, update3, 0);
}

void update4(int value) {
    if(position4 <-2.0)
        position4 = 2.0f;
    position4 -= speed4;
	glutPostRedisplay();
	glutTimerFunc(50, update4, 0);
}



void SpecialInput(int key, int x, int y)//bird
{
switch(key)
{case GLUT_KEY_UP:
speed=.5;
break;
case GLUT_KEY_DOWN:
     glutTimerFunc(50,update3,0);//speedy rain


break;
case GLUT_KEY_LEFT:
speed=0.002;
glutPostRedisplay();

break;


case GLUT_KEY_RIGHT:
     glutTimerFunc(100,update2,0);//car
break;
case GLUT_KEY_INSERT:
speed4=0.0;
glutPostRedisplay();

break;

case GLUT_KEY_END:
speed4=0.05;
glutPostRedisplay();

break;

}
glutPostRedisplay();
}
//sound
void sound()
{

    PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);


}

void sound1()
{

    PlaySound("b.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);


}

void sound2()
{

    PlaySound(NULL, NULL, SND_ASYNC|SND_FILENAME);


}

void handleKeypress(unsigned char key,int x,int y)
{
    switch(key){
 case 'n':

    glutDisplayFunc(night);
    sound2();
    glutPostRedisplay();

    break;

case 'd':

    glutDisplayFunc(day);
    sound1();
    glutPostRedisplay();

    break;


    case 'r':

       glutDisplayFunc(night_rain);
       sound();
    glutPostRedisplay();
    break;


    }

}

void Idle()
{
    glutPostRedisplay();
}




/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
//night_rain
void night_rain() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)


   glBegin(GL_QUADS);// sky
	glColor3ub(148,145,145);

	glVertex2f(1.0f, -0.1f);
	glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f,1.0f);
    glVertex2f(-1.0,-0.1f);
    glEnd();


   /* //STAR
    glPointSize(2.0f);
    glBegin(GL_POINTS);
    glColor3ub(255,255,255);
//-----------------------
    glVertex2f(-.95,.7);
    glVertex2f(-.9,.65);

    glVertex2f(-.8,.75);

    glVertex2f(-.7,.7);
    glVertex2f(-.6,.72);

    glVertex2f(-.5,.67);
    glVertex2f(-.4,.73);

    glVertex2f(-.3,.68);
    glVertex2f(-.2,.7);

    glVertex2f(-.1,.74);
    glVertex2f(-.9,.79);

    //-----------------

    glVertex2f(-.95,.6);
    glVertex2f(-.9,.65);

    glVertex2f(-.8,.55);

    glVertex2f(-.7,.62);
    glVertex2f(-.6,.52);

    glVertex2f(-.5,.6);
    glVertex2f(-.4,.63);

    glVertex2f(-.3,.66);
    glVertex2f(-.2,.89);

    glVertex2f(-.8,.9);
    glVertex2f(-.5,.85);

    //------------------

    glVertex2f(.95,.7);
    glVertex2f(.9,.65);

    glVertex2f(.8,.75);

    glVertex2f(.7,.7);
    glVertex2f(.6,.72);

    glVertex2f(.5,.67);
    glVertex2f(.4,.73);

    glVertex2f(.3,.68);
    glVertex2f(.2,.7);

    glVertex2f(.1,.74);
    glVertex2f(.9,.79);

    //-----------------

    glVertex2f(.95,.6);
    glVertex2f(.9,.65);

    glVertex2f(.8,.55);

    glVertex2f(.7,.62);
    glVertex2f(.6,.52);

    glVertex2f(.5,.6);
    glVertex2f(.4,.63);

    glVertex2f(.3,.66);
    glVertex2f(.2,.89);

    glVertex2f(.8,.9);
    glVertex2f(.5,.85);


    //---------------


    glVertex2f(.7,.95);
    glVertex2f(.8,.95);

    glVertex2f(.75,.82);
    glVertex2f(.65,.92);

    glVertex2f(.07,.95);
    glVertex2f(.18,.95);

    glVertex2f(.0,.92);
    glVertex2f(-.07,.92);

    glVertex2f(.0,.82);
    glVertex2f(-.07,.72);


    glVertex2f(-.7,.95);

    glVertex2f(-.8,.95);

    glVertex2f(-.75,.82);
    glVertex2f(-.65,.92);


    glEnd();
    */

	/*int i;//moon

	GLfloat x=-.4f; GLfloat y=.8f; GLfloat radius =.06f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();*/

	glPushMatrix();
    glTranslatef(position,0,0);
	int i1;// cloud

	GLfloat x1=0.4f; GLfloat y1=0.88f; GLfloat radius1 =.07f;
	int triangleAmount1 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(192,192,192);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount1;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)),
			    y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1))
			);
		}
	glEnd();

	int i2;// cloud

	GLfloat x2=0.5f; GLfloat y2=0.84f; GLfloat radius2 =.06f;
	int triangleAmount2 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(192,192,192);
		glVertex2f(x2, y2); // center of circle
		for(i2 = 0; i2 <= triangleAmount2;i2++) {
			glVertex2f(
		            x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
			);
		}
	glEnd();

		int i3;// cloud

	GLfloat x3=0.6f; GLfloat y3=0.82f; GLfloat radius3 =.06f;
	int triangleAmount3 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi3 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(192,192,192);
		glVertex2f(x3, y3); // center of circle
		for(i3 = 0; i3 <= triangleAmount3;i3++) {
			glVertex2f(
		            x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
			    y3 + (radius3 * sin(i3 * twicePi3/ triangleAmount3))
			);
		}
	glEnd();

	    int i4;//cloud

	GLfloat x4=0.3f; GLfloat y4=0.75f; GLfloat radius4 =.07f;
	int triangleAmount4 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi4 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x4, y4); // center of circle
		for(i4 = 0; i4 <= triangleAmount4;i4++) {
			glVertex2f(
		            x4 + (radius4 * cos(i4 *  twicePi4 / triangleAmount4)),
			    y4 + (radius4 * sin(i4 * twicePi4 / triangleAmount4))
			);
		}
	glEnd();

	int i5;// cloud

	GLfloat x5=0.4f; GLfloat y5=0.75f; GLfloat radius5 =.07f;
	int triangleAmount5 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi5 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x5, y5); // center of circle
		for(i5 = 0; i5 <= triangleAmount5;i5++) {
			glVertex2f(
		            x5 + (radius5 * cos(i5 *  twicePi5 / triangleAmount5)),
			    y5 + (radius5 * sin(i5 * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

		int i6;// cloud

	GLfloat x6=0.45f; GLfloat y6=0.78f; GLfloat radius6 =.06f;
	int triangleAmount6 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi6 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x6, y6); // center of circle
		for(i6 = 0; i6 <= triangleAmount6;i6++) {
			glVertex2f(
		            x6 + (radius6 * cos(i6 *  twicePi6 / triangleAmount6)),
			    y6 + (radius6 * sin(i6 * twicePi6 / triangleAmount6))
			);
		}
	glEnd();

	int i7;// cloud

	GLfloat x7=0.35f; GLfloat y7=0.81f; GLfloat radius7 =.06f;
	int triangleAmount7 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi7 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x7, y7); // center of circle
		for(i7 = 0; i7 <= triangleAmount7;i7++) {
			glVertex2f(
		            x7 + (radius7 * cos(i7 *  twicePi7 / triangleAmount7)),
			    y7 + (radius7 * sin(i7 * twicePi7 / triangleAmount7))
			);
		}
	glEnd();

		int i8;// cloud

	GLfloat x8=0.55f; GLfloat y8=0.75f; GLfloat radius8 =.07f;
	int triangleAmount8 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi8 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x8, y8); // center of circle
		for(i8 = 0; i8 <= triangleAmount8;i8++) {
			glVertex2f(
		            x8 + (radius8 * cos(i8 *  twicePi8 / triangleAmount8)),
			    y8 + (radius8 * sin(i8 * twicePi8 / triangleAmount8))
			);
		}
	glEnd();

	glTranslatef(-0.8,0,0);
	int i88;// cloud

	GLfloat x88=0.4f; GLfloat y88=0.88f; GLfloat radius88 =.07f;
	int triangleAmount88 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi88 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(192,192,192);
		glVertex2f(x88, y88); // center of circle
		for(i88 = 0; i88 <= triangleAmount88;i88++) {
			glVertex2f(
		            x88 + (radius88 * cos(i88 *  twicePi88 / triangleAmount88)),
			    y88 + (radius88 * sin(i88 * twicePi88 / triangleAmount88))
			);
		}
	glEnd();

	int i89;// cloud

	GLfloat x89=0.5f; GLfloat y89=0.84f; GLfloat radius89 =.06f;
	int triangleAmount89 = 890; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi89 = 89.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(192,192,192);
		glVertex2f(x89, y89); // center of circle
		for(i89 = 0; i89 <= triangleAmount89;i89++) {
			glVertex2f(
		            x89 + (radius89 * cos(i89 *  twicePi89 / triangleAmount89)),
			    y89 + (radius89 * sin(i89 * twicePi89 / triangleAmount89))
			);
		}
	glEnd();

		int i90;// cloud

	GLfloat x90=0.6f; GLfloat y90=0.82f; GLfloat radius90 =.06f;
	int triangleAmount90 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi90 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(192,192,192);
		glVertex2f(x90, y90); // center of circle
		for(i90 = 0; i90 <= triangleAmount90;i90++) {
			glVertex2f(
		            x90 + (radius90 * cos(i90 *  twicePi90 / triangleAmount90)),
			    y90 + (radius90 * sin(i90 * twicePi90/ triangleAmount90))
			);
		}
	glEnd();

	    int i91;//cloud

	GLfloat x91=0.3f; GLfloat y91=0.75f; GLfloat radius91 =.07f;
	int triangleAmount91 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi91 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x91, y91); // center of circle
		for(i91 = 0; i91 <= triangleAmount91;i91++) {
			glVertex2f(
		            x91 + (radius91 * cos(i91 *  twicePi91 / triangleAmount91)),
			    y91 + (radius91 * sin(i91 * twicePi91 / triangleAmount91))
			);
		}
	glEnd();

	int i92;// cloud

	GLfloat x92=0.4f; GLfloat y92=0.75f; GLfloat radius92 =.07f;
	int triangleAmount92 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi92 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x92, y92); // center of circle
		for(i92 = 0; i92 <= triangleAmount92;i92++) {
			glVertex2f(
		            x92 + (radius92 * cos(i92 *  twicePi92 / triangleAmount92)),
			    y92 + (radius92 * sin(i92 * twicePi92 / triangleAmount92))
			);
		}
	glEnd();

		int i93;// cloud

	GLfloat x93=0.45f; GLfloat y93=0.78f; GLfloat radius93 =.06f;
	int triangleAmount93 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi93 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x93, y93); // center of circle
		for(i93 = 0; i93 <= triangleAmount93;i93++) {
			glVertex2f(
		            x93 + (radius93 * cos(i93 *  twicePi93 / triangleAmount93)),
			    y93 + (radius93 * sin(i93 * twicePi93 / triangleAmount93))
			);
		}
	glEnd();

	int i94;// cloud

	GLfloat x94=0.35f; GLfloat y94=0.81f; GLfloat radius94 =.06f;
	int triangleAmount94 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi94 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x94, y94); // center of circle
		for(i94 = 0; i94 <= triangleAmount94;i94++) {
			glVertex2f(
		            x94 + (radius94 * cos(i94 *  twicePi94 / triangleAmount94)),
			    y94 + (radius94 * sin(i94 * twicePi94 / triangleAmount94))
			);
		}
	glEnd();

		int i95;// cloud

	GLfloat x95=0.55f; GLfloat y95=0.75f; GLfloat radius95 =.07f;
	int triangleAmount95 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.95f; //radius
	GLfloat twicePi95 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x95, y95); // center of circle
		for(i95 = 0; i95 <= triangleAmount95;i95++) {
			glVertex2f(
		            x95 + (radius95 * cos(i95 *  twicePi95 / triangleAmount95)),
			    y95 + (radius95 * sin(i95 * twicePi95 / triangleAmount95))
			);
		}
	glEnd();



	glPopMatrix();
	//glLoadIdentity();naimul


    glBegin(GL_QUADS);//floor
	glColor3ub(56,50,47);

	glVertex2f(1.0f, -0.1f);
	glVertex2f(1.0f, -0.26f);
    glVertex2f(-1.0f,-0.26f);
    glVertex2f(-1.0,-0.1f);
    glEnd();

    glBegin(GL_QUADS);//floor small
	glColor3ub(97,19,14);

	glVertex2f(0.76f, -0.24f);
	glVertex2f(0.76f, -0.2f);
    glVertex2f(-.76f,-0.2f);
    glVertex2f(-0.76,-0.24f);
    glEnd();

    glBegin(GL_QUADS);//field
	glColor3ub(14,28,14);

	glVertex2f(1.0f, -0.6f);
	glVertex2f(1.0f, -0.26f);
    glVertex2f(-1.0f,-0.26f);
    glVertex2f(-1.0,-0.6f);
    glEnd();


	glBegin(GL_QUADS);//body
	glColor3ub(163,53,53);

	glVertex2f(0.76f, -0.2f);
	glVertex2f(0.76f, 0.24f);
    glVertex2f(-.76f,0.24f);
    glVertex2f(-0.76,-0.2f);
    glEnd();




    glBegin(GL_QUADS);//middle line 1
	glColor3ub(1,1,1);

	glVertex2f(0.76f, -0.04f);
	glVertex2f(0.76f, -0.03f);
    glVertex2f(-0.76f, -0.03f);
    glVertex2f(-0.76,-0.04f);
    glEnd();

    glBegin(GL_LINES);// middle line 2
	glColor3ub(1,1,1);

	glVertex2f(0.76f, -0.02f);
	glVertex2f(-0.76f, -0.02f);

    glEnd();

    glBegin(GL_LINES);//line right side
	glColor3ub(1,1,1);

	glVertex2f(0.18f, -0.04f);
    glVertex2f(0.18f,-0.2f);

	glVertex2f(0.20f, -0.04f);
    glVertex2f(0.20f,-0.2f);

    glVertex2f(0.271f, -0.04f);
    glVertex2f(0.271f,-0.2f);

    glVertex2f(0.291f, -0.04f);
    glVertex2f(0.291f,-0.2f);

    glVertex2f(0.362f, -0.04f);
    glVertex2f(0.362f,-0.2f);

    glVertex2f(0.382f, -0.04f);
    glVertex2f(0.382f,-0.2f);

    glVertex2f(0.453f, -0.04f);
    glVertex2f(0.453f,-0.2f);

    glVertex2f(0.473f, -0.04f);
    glVertex2f(0.473f,-0.2f);

    glVertex2f(0.544f, -0.04f);
    glVertex2f(0.544f,-0.2f);

    glVertex2f(0.58f, -0.04f);
    glVertex2f(0.58f,-0.2f);

    //dark pillar right
    glVertex2f(0.546f, -0.04f);
    glVertex2f(0.546f,-0.2f);

    glVertex2f(0.549f, -0.04f);
    glVertex2f(0.549f,-0.2f);

    glVertex2f(0.575f, -0.04f);
    glVertex2f(0.575f,-0.2f);

    glVertex2f(0.578f, -0.04f);
    glVertex2f(0.578f,-0.2f);

    //end



    glVertex2f(0.64f, -0.04f);
    glVertex2f(0.64f,-0.2f);

    glVertex2f(0.66f, -0.04f);
    glVertex2f(0.66f,-0.2f);

    glVertex2f(0.72f, -0.04f);
    glVertex2f(0.72f,-0.2f);
    glEnd();

    glBegin(GL_LINES);//dark pillar

    glVertex2f(0.722f, -0.04f);
    glVertex2f(0.722f,-0.2f);

    glVertex2f(0.724f, -0.04f);
    glVertex2f(0.724f,-0.2f);

    glVertex2f(0.726f, -0.04f);
    glVertex2f(0.726f,-0.2f);

    glVertex2f(0.756f, -0.04f);
    glVertex2f(0.756f,-0.2f);

    glVertex2f(0.758f, -0.04f);
    glVertex2f(0.758f,-0.2f);

    glVertex2f(0.76f, -0.04f);
    glVertex2f(0.76f,-0.2f);
    glEnd();


    //line left side
    glBegin(GL_LINES);
	glColor3ub(1,1,1);

	glVertex2f(-0.18f, -0.04f);//13
    glVertex2f(-0.18f,-0.2f);

	glVertex2f(-0.20f, -0.04f);//12
    glVertex2f(-0.20f,-0.2f);

    glVertex2f(-0.271f, -0.04f);//11
    glVertex2f(-0.271f,-0.2f);

    glVertex2f(-0.291f, -0.04f);//10
    glVertex2f(-0.291f,-0.2f);

    glVertex2f(-0.362f, -0.04f);//9
    glVertex2f(-0.362f,-0.2f);

    glVertex2f(-0.382f, -0.04f);//8
    glVertex2f(-0.382f,-0.2f);

    glVertex2f(-0.453f, -0.04f);//7
    glVertex2f(-0.453f,-0.2f);

    glVertex2f(-0.473f, -0.04f);//6
    glVertex2f(-0.473f,-0.2f);

    glVertex2f(-0.544f, -0.04f);//5
    glVertex2f(-0.544f,-0.2f);

    glVertex2f(-0.58f, -0.04f);//4
    glVertex2f(-0.58f,-0.2f);



    glVertex2f(-0.64f, -0.04f);//3
    glVertex2f(-0.64f,-0.2f);

    glVertex2f(-0.66f, -0.04f);//2
    glVertex2f(-0.66f,-0.2f);

    glVertex2f(-0.72f, -0.04f);//1
    glVertex2f(-0.72f,-0.2f);


    glEnd();

    glBegin(GL_LINES);//dark pillar
    glColor3ub(1,1,1);
    glVertex2f(-0.724f, -0.04f);
    glVertex2f(-0.724f,-0.2f);

    glVertex2f(-0.726f, -0.04f);
    glVertex2f(-0.726f,-0.2f);

    glVertex2f(-0.728f, -0.04f);
    glVertex2f(-0.728f,-0.2f);

    glVertex2f(-0.756f, -0.04f);
    glVertex2f(-0.756f,-0.2f);


    glVertex2f(-0.76f, -0.04f);
    glVertex2f(-0.76f,-0.2f);

    //end
    glEnd();

    //last roof middle
    glBegin(GL_QUADS);
    glColor3ub(163,53,53);
    glVertex2f(0.549f, 0.24f);
    glVertex2f(0.549f,0.28f);

    glVertex2f(-0.549f,0.28f);
    glVertex2f(-0.549f, 0.24f);


    //end
    glEnd();






   //last roof right
    glBegin(GL_QUADS);
    glColor3ub(163,53,53);
    glVertex2f(0.74f, 0.24f);
    glVertex2f(0.74f,0.3f);

    glVertex2f(0.567f,0.3f);
    glVertex2f(0.567f, 0.24f);


    //end
    glEnd();

    //last roof left
    glBegin(GL_QUADS);
    glColor3ub(163,53,53);
    glVertex2f(-0.74f, 0.24f);
    glVertex2f(-0.74f,0.3f);

    glVertex2f(-0.567f,0.3f);
    glVertex2f(-0.567f, 0.24f);


    //end
    glEnd();

    glBegin(GL_LINES);//extra line
    glColor3ub(1,1,1);
    glVertex2f(0.549f,0.28f);
    glVertex2f(-0.549f,0.28f);

    glVertex2f(0.567f,0.3f);//right
    glVertex2f(0.74f,0.3f);

    glVertex2f(-0.567f,0.3f);//left
    glVertex2f(-0.74f,0.3f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(163,53,53);

    glVertex2f(0.567f,0.3f);//right
    glVertex2f(0.6535f,0.36f);
    glVertex2f(0.74f,0.3f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(163,53,53);

    glVertex2f(-0.567f,0.3f);//left
    glVertex2f(-0.6535f,0.36f);
    glVertex2f(-0.74f,0.3f);

    glEnd();

    glBegin(GL_LINES);//extra line
    glColor3ub(1,1,1);

    glVertex2f(0.567f,0.3f);//right
    glVertex2f(0.74f,0.3f);

    glVertex2f(0.74f,0.3f);
    glVertex2f(0.6535f,0.36f);

    glVertex2f(0.567f,0.3f);//
    glVertex2f(0.6535f,0.36f);

    glVertex2f(0.74f,0.3f);
    glVertex2f(0.567f,0.3f);//

    glEnd();

        glBegin(GL_LINES);//extra line
    glColor3ub(1,1,1);

    glVertex2f(-0.567f,0.3f);//left
    glVertex2f(-0.74f,0.3f);

    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.6535f,0.36f);

    glVertex2f(-0.567f,0.3f);//
    glVertex2f(-0.6535f,0.36f);

    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.567f,0.3f);//

    glEnd();

    glBegin(GL_LINES);//triangle line right
    glColor3ub(1,1,1);

    glVertex2f(0.61f,0.3f);//right
    glVertex2f(0.6535f,0.36f);

    glVertex2f(0.6535f,0.36f);
    glVertex2f(0.644f,0.3f);

    glVertex2f(0.696f,0.3f);
    glVertex2f(0.6535f,0.36f);

    glEnd();

    glBegin(GL_LINES);//triangle line left
    glColor3ub(1,1,1);

    glVertex2f(-0.61f,0.3f);//right
    glVertex2f(-0.6535f,0.36f);

    glVertex2f(-0.6535f,0.36f);
    glVertex2f(-0.644f,0.3f);

    glVertex2f(-0.696f,0.3f);
    glVertex2f(-0.6535f,0.36f);

    glEnd();









     int i9;// window up right 1

	GLfloat x9=0.69f; GLfloat y9=-0.08f; GLfloat radius9 =.02f;
	int triangleAmount9 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi9 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x9, y9); // center of circle
		for(i9 = 0; i9 <= triangleAmount9;i9++) {
			glVertex2f(
		            x9 + (radius9 * cos(i9 *  twicePi9 / triangleAmount9)),
			    y9 + (radius9 * sin(i9 * twicePi9 / triangleAmount9))
			);
		}
	glEnd();

	glBegin(GL_QUADS);// window right 1
	glColor3ub(228,205,57);
    glVertex2f(0.71f, -0.2f);
    glVertex2f(0.71f,-0.08f);
    glVertex2f(0.67f, -0.08f);
    glVertex2f(0.67f,-0.2f);

    glEnd();

    glBegin(GL_QUADS);// window up right 1 corner
	glColor3ub(228,205,57);
    glVertex2f(0.71f, 0.02f);
    glVertex2f(0.71f,0.15f);
    glVertex2f(0.67f, 0.15f);
    glVertex2f(0.67f,0.02f);

    glEnd();

    glBegin(GL_QUADS);// window up left 1 corner
	glColor3ub(228,205,57);
    glVertex2f(-0.71f, 0.02f);
    glVertex2f(-0.71f,0.15f);
    glVertex2f(-0.67f, 0.15f);
    glVertex2f(-0.67f,0.02f);

    glEnd();


    int i10;// window up right 2

    GLfloat x10=0.61f; GLfloat y10=-0.08f; GLfloat radius10 =.02f;
	int triangleAmount10 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi10 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x10, y10); // center of circle
		for(i10 = 0; i10 <= triangleAmount10;i10++) {
			glVertex2f(
		            x10 + (radius10 * cos(i10 *  twicePi10 / triangleAmount10)),
			    y10 + (radius10 * sin(i10 * twicePi10 / triangleAmount10))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 2
	glColor3ub(228,205,57);
    glVertex2f(0.59f, 0.02f);
    glVertex2f(0.59f, 0.15f);
    glVertex2f(0.63f, 0.15f);
    glVertex2f(0.63f,0.02f);

    glEnd();

    glBegin(GL_QUADS);// window up right corner
	glColor3ub(228,205,57);
    glVertex2f(0.59f, -0.2f);
    glVertex2f(0.59f,-0.08f);
    glVertex2f(0.63f, -0.08f);
    glVertex2f(0.63f,-0.2f);

    glEnd();


    int i11;// window up right 3

    GLfloat x11=0.508f; GLfloat y11=-0.08f; GLfloat radius11 =.02f;
	int triangleAmount11 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi11 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x11, y11); // center of circle
		for(i11 = 0; i11 <= triangleAmount11;i11++) {
			glVertex2f(
		            x11 + (radius11 * cos(i11 *  twicePi11 / triangleAmount11)),
			    y11 + (radius11 * sin(i11 * twicePi11 / triangleAmount11))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 3
	glColor3ub(228,205,57);
    glVertex2f(0.488f, -0.2f);
    glVertex2f(0.488f,-0.08f);
    glVertex2f(0.528f, -0.08f);
    glVertex2f(0.528f,-0.2f);

    glEnd();

        int i12;// window up right 4

    GLfloat x12=0.4175f; GLfloat y12=-0.08f; GLfloat radius12 =.02f;
	int triangleAmount12 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi12 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x12, y12); // center of circle
		for(i12 = 0; i12 <= triangleAmount12;i12++) {
			glVertex2f(
		            x12 + (radius12 * cos(i12 *  twicePi12 / triangleAmount12)),
			    y12 + (radius12 * sin(i12 * twicePi12 / triangleAmount12))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 4
	glColor3ub(228,205,57);
    glVertex2f(0.438f, -0.2f);
    glVertex2f(0.438f,-0.08f);
    glVertex2f(0.397f, -0.08f);
    glVertex2f(0.397f,-0.2f);

    glEnd();

            int i13;// window up right 5

    GLfloat x13=0.3265f; GLfloat y13=-0.08f; GLfloat radius13 =.02f;
	int triangleAmount13 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi13 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x13, y13); // center of circle
		for(i13 = 0; i13 <= triangleAmount13;i13++) {
			glVertex2f(
		            x13 + (radius13 * cos(i13 *  twicePi13 / triangleAmount13)),
			    y13 + (radius13 * sin(i13 * twicePi13 / triangleAmount13))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 5
	glColor3ub(228,205,57);
    glVertex2f(0.347f, -0.2f);
    glVertex2f(0.347f,-0.08f);
    glVertex2f(0.306f, -0.08f);
    glVertex2f(0.306f,-0.2f);

    glEnd();

    int i14;// window up right 6

    GLfloat x14=0.2355f; GLfloat y14=-0.08f; GLfloat radius14 =.02f;
	int triangleAmount14 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi14 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x14, y14); // center of circle
		for(i14 = 0; i14 <= triangleAmount14;i14++) {
			glVertex2f(
		            x14 + (radius14 * cos(i14 *  twicePi14 / triangleAmount14)),
			    y14 + (radius14 * sin(i14 * twicePi14 / triangleAmount14))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 6
	glColor3ub(228,205,57);
    glVertex2f(0.256f, -0.2f);
    glVertex2f(0.256f,-0.08f);
    glVertex2f(0.215f, -0.08f);
    glVertex2f(0.215f,-0.2f);

    glEnd();


    int i15;// window up left 1

	GLfloat x15=-0.69f; GLfloat y15=-0.08f; GLfloat radius15 =.02f;
	int triangleAmount15 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi15 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x15, y15); // center of circle
		for(i15 = 0; i15 <= triangleAmount15;i15++) {
			glVertex2f(
		            x15 + (radius15 * cos(i15 *  twicePi15 / triangleAmount15)),
			    y15 + (radius15 * sin(i15 * twicePi15 / triangleAmount15))
			);
		}
	glEnd();

	glBegin(GL_QUADS);// window left 1
	glColor3ub(228,205,57);
    glVertex2f(-0.71f, -0.2f);
    glVertex2f(-0.71f,-0.08f);
    glVertex2f(-0.67f, -0.08f);
    glVertex2f(-0.67f,-0.2f);

    glEnd();


    int i16;// window up left 2

    GLfloat x16=-0.61f; GLfloat y16=-0.08f; GLfloat radius16 =.02f;
	int triangleAmount16 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi16 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x16, y16); // center of circle
		for(i16 = 0; i16 <= triangleAmount16;i16++) {
			glVertex2f(
		            x16 + (radius16 * cos(i16 *  twicePi16 / triangleAmount16)),
			    y16 + (radius16 * sin(i16 * twicePi16 / triangleAmount16))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window left 2
	glColor3ub(228,205,57);
    glVertex2f(-0.59f, -0.2f);
    glVertex2f(-0.59f,-0.08f);
    glVertex2f(-0.63f, -0.08f);
    glVertex2f(-0.63f,-0.2f);

    glEnd();

        glBegin(GL_QUADS);// window left up corner
	glColor3ub(228,205,57);
    glVertex2f(-0.59f, 0.02f);
    glVertex2f(-0.59f,0.15f);
    glVertex2f(-0.63f, 0.15f);
    glVertex2f(-0.63f,0.02f);

    glEnd();

    int i17;// window up right 3

    GLfloat x17=-0.508f; GLfloat y17=-0.08f; GLfloat radius17 =.02f;
	int triangleAmount17 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi17 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x17, y17); // center of circle
		for(i17 = 0; i17 <= triangleAmount17;i17++) {
			glVertex2f(
		            x17 + (radius17 * cos(i17 *  twicePi17 / triangleAmount17)),
			    y17 + (radius17 * sin(i17 * twicePi17 / triangleAmount17))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 3
	glColor3ub(228,205,57);
    glVertex2f(-0.488f, -0.2f);
    glVertex2f(-0.488f,-0.08f);
    glVertex2f(-0.528f, -0.08f);
    glVertex2f(-0.528f,-0.2f);

    glEnd();

        int i18;// window up left 4

    GLfloat x18=-0.4175f; GLfloat y18=-0.08f; GLfloat radius18 =.02f;
	int triangleAmount18 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi18 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x18, y18); // center of circle
		for(i18 = 0; i18 <= triangleAmount18;i18++) {
			glVertex2f(
		            x18 + (radius18 * cos(i18 *  twicePi18 / triangleAmount18)),
			    y18 + (radius18 * sin(i18 * twicePi18 / triangleAmount18))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window left 4
	glColor3ub(228,205,57);
    glVertex2f(-0.438f, -0.2f);
    glVertex2f(-0.438f,-0.08f);
    glVertex2f(-0.397f, -0.08f);
    glVertex2f(-0.397f,-0.2f);

    glEnd();

    int i19;// window up left 5

    GLfloat x19=-0.3265f; GLfloat y19=-0.08f; GLfloat radius19 =.02f;
	int triangleAmount19 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi19 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x19, y19); // center of circle
		for(i19 = 0; i19 <= triangleAmount19;i19++) {
			glVertex2f(
		            x19 + (radius19 * cos(i19 *  twicePi19 / triangleAmount19)),
			    y19 + (radius19 * sin(i19 * twicePi19 / triangleAmount19))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window left 5
	glColor3ub(228,205,57);
    glVertex2f(-0.347f, -0.2f);
    glVertex2f(-0.347f,-0.08f);
    glVertex2f(-0.306f, -0.08f);
    glVertex2f(-0.306f,-0.2f);

    glEnd();

    int i20;// window up left 6

    GLfloat x20=-0.2355f; GLfloat y20=-0.08f; GLfloat radius20 =.02f;
	int triangleAmount20 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi20 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x20, y20); // center of circle
		for(i20 = 0; i20 <= triangleAmount20;i20++) {
			glVertex2f(
		            x20 + (radius20 * cos(i20 *  twicePi20 / triangleAmount20)),
			    y20 + (radius20 * sin(i20 * twicePi20 / triangleAmount20))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window left 6
	glColor3ub(228,205,57);
    glVertex2f(-0.256f, -0.2f);
    glVertex2f(-0.256f,-0.08f);
    glVertex2f(-0.215f, -0.08f);
    glVertex2f(-0.215f,-0.2f);

    glEnd();

    glBegin(GL_LINES); // right up stair 1
    glColor3ub(0,0,0);

    glVertex2f(0.472f, -0.02f);
    glVertex2f(0.472f,0.2f);

    glVertex2f(0.472f,0.2f);
    glVertex2f(0.454f,0.2f);

    glVertex2f(0.454f,0.2f);
    glVertex2f(0.454f, -0.02f);

    glVertex2f(0.454f, -0.02f);
    glVertex2f(0.472f, -0.02f);



    glEnd();

    //lower beam 1
    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(0.475f, -0.02f);
    glVertex2f(0.475f, 0.0f);

    glVertex2f(0.475f, 0.0f);
    glVertex2f(0.451f, 0.0f);

    glVertex2f(0.451f, 0.0f);
    glVertex2f(0.451f, -0.02f);

    glVertex2f(0.475f, -0.02f);
    glVertex2f(0.451f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // right up stair 2
    glColor3ub(0,0,0);

    glVertex2f(0.381f, -0.02f);
    glVertex2f(0.381f, 0.2f);

    glVertex2f(0.381f, 0.2f);
    glVertex2f(0.363f, 0.2f);

    glVertex2f(0.363f, 0.2f);
    glVertex2f(0.363f, -0.02f);

    glVertex2f(0.363f, -0.02f);
    glVertex2f(0.381f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // right beam 2
    glColor3ub(0,0,0);

    glVertex2f(0.384f, -0.02f);
    glVertex2f(0.384f, 0.0f);

    glVertex2f(0.384f, 0.0f);
    glVertex2f(0.36f, 0.00f);

    glVertex2f(0.36f, 0.0f);
    glVertex2f(0.36f,-0.02f);

    glVertex2f(0.36f,-0.02f);
    glVertex2f(0.384f, -0.02f);

    glEnd();


    glBegin(GL_LINES); // right up stair 3
    glColor3ub(0,0,0);

    glVertex2f(0.29f, -0.02f);
    glVertex2f(0.29f, 0.2f);

    glVertex2f(0.29f, 0.2f);
    glVertex2f(0.27f, 0.2f);

    glVertex2f(0.27f, 0.2f);
    glVertex2f(0.27f, -0.02f);

    glVertex2f(0.29f, -0.02f);
    glVertex2f(0.29f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // right beam 3
    glColor3ub(0,0,0);

    glVertex2f(0.293f, -0.02f);
    glVertex2f(0.293f, 0.0f);

    glVertex2f(0.293f, 0.0f);
    glVertex2f(0.269f, 0.0f);

    glVertex2f(0.269f, 0.0f);
    glVertex2f(0.269f,-0.02f);

    glVertex2f(0.269f,-0.02f);
    glVertex2f(0.293f, -0.02f);

    glEnd();



    glBegin(GL_LINES); // right up stair 4
    glColor3ub(0,0,0);

    glVertex2f(0.199f, -0.02f);
    glVertex2f(0.199f, 0.2f);

    glVertex2f(0.199f, 0.2f);
    glVertex2f(0.181f, 0.2f);

    glVertex2f(0.181f, 0.2f);
    glVertex2f(0.181f, -0.02f);

    glVertex2f(0.199f, -0.02f);
    glVertex2f(0.199f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // right beam 4
    glColor3ub(0,0,0);

    glVertex2f(0.202f, -0.02f);
    glVertex2f(0.202f, 0.0f);

    glVertex2f(0.202f, 0.0f);
    glVertex2f(0.178f, 0.0f);

    glVertex2f(0.178f, 0.0f);
    glVertex2f(0.178f, -0.02f);

    glVertex2f(0.178f, -0.02f);
    glVertex2f(0.202f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // left up stair 1
    glColor3ub(0,0,0);

    glVertex2f(-0.472f, -0.02f);
    glVertex2f(-0.472f,0.2f);

    glVertex2f(-0.472f,0.2f);
    glVertex2f(-0.454f,0.2f);

    glVertex2f(-0.454f,0.2f);
    glVertex2f(-0.454f, -0.02f);

    glVertex2f(-0.454f, -0.02f);
    glVertex2f(-0.472f, -0.02f);



    glEnd();

    //lower beam 1
    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(-0.475f, -0.02f);
    glVertex2f(-0.475f, 0.0f);

    glVertex2f(-0.475f, 0.0f);
    glVertex2f(-0.451f, 0.0f);

    glVertex2f(-0.451f, 0.0f);
    glVertex2f(-0.451f, -0.02f);

    glVertex2f(-0.475f, -0.02f);
    glVertex2f(-0.451f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // left up stair 2
    glColor3ub(0,0,0);

    glVertex2f(-0.381f, -0.02f);
    glVertex2f(-0.381f, 0.2f);

    glVertex2f(-0.381f, 0.2f);
    glVertex2f(-0.363f, 0.2f);

    glVertex2f(-0.363f, 0.2f);
    glVertex2f(-0.363f, -0.02f);

    glVertex2f(-0.363f, -0.02f);
    glVertex2f(-0.381f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // left beam 2
    glColor3ub(0,0,0);

    glVertex2f(0.384f, -0.02f);
    glVertex2f(0.384f, 0.0f);

    glVertex2f(-0.384f, 0.0f);
    glVertex2f(-0.36f, 0.00f);

    glVertex2f(-0.36f, 0.0f);
    glVertex2f(-0.36f,-0.02f);

    glVertex2f(-0.36f,-0.02f);
    glVertex2f(-0.384f, -0.02f);

    glEnd();


    glBegin(GL_LINES); // left up stair 3
    glColor3ub(0,0,0);

    glVertex2f(-0.29f, -0.02f);
    glVertex2f(-0.29f, 0.2f);

    glVertex2f(-0.29f, 0.2f);
    glVertex2f(-0.27f, 0.2f);

    glVertex2f(-0.27f, 0.2f);
    glVertex2f(-0.27f, -0.02f);

    glVertex2f(-0.29f, -0.02f);
    glVertex2f(-0.29f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // left beam 3
    glColor3ub(0,0,0);

    glVertex2f(-0.293f, -0.02f);
    glVertex2f(-0.293f, 0.0f);

    glVertex2f(-0.293f, 0.0f);
    glVertex2f(-0.269f, 0.0f);

    glVertex2f(-0.269f, 0.0f);
    glVertex2f(-0.269f,-0.02f);

    glVertex2f(-0.269f,-0.02f);
    glVertex2f(-0.293f, -0.02f);

    glEnd();



    glBegin(GL_LINES); // left up stair 4
    glColor3ub(0,0,0);

    glVertex2f(-0.199f, -0.02f);
    glVertex2f(-0.199f, 0.2f);

    glVertex2f(-0.199f, 0.2f);
    glVertex2f(-0.181f, 0.2f);

    glVertex2f(-0.181f, 0.2f);
    glVertex2f(-0.181f, -0.02f);

    glVertex2f(-0.199f, -0.02f);
    glVertex2f(-0.199f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // left beam 4
    glColor3ub(0,0,0);

    glVertex2f(-0.202f, -0.02f);
    glVertex2f(-0.202f, 0.0f);

    glVertex2f(-0.202f, 0.0f);
    glVertex2f(-0.178f, 0.0f);

    glVertex2f(-0.178f, 0.0f);
    glVertex2f(-0.178f, -0.02f);

    glVertex2f(-0.178f, -0.02f);
    glVertex2f(-0.202f, -0.02f);

    glEnd();


    glBegin(GL_QUADS);// window right 3
	glColor3ub(228,205,57);
    glVertex2f(0.488f, -0.2f);
    glVertex2f(0.488f,-0.08f);
    glVertex2f(0.528f, -0.08f);
    glVertex2f(0.528f,-0.2f);

    glEnd();

        int i21;// upstair window up right 4

    GLfloat x21=0.4175f; GLfloat y21=0.14f; GLfloat radius21 =.02f;
	int triangleAmount21 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi21 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x21, y21); // center of circle
		for(i21 = 0; i21 <= triangleAmount21;i21++) {
			glVertex2f(
		            x21 + (radius21 * cos(i21 *  twicePi21 / triangleAmount21)),
			    y21 + (radius21 * sin(i21 * twicePi21 / triangleAmount21))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 4
	glColor3ub(228,205,57);
    glVertex2f(0.438f, 0.0f);
    glVertex2f(0.438f, 0.14f);
    glVertex2f(0.397f, 0.14f);
    glVertex2f(0.397f, 0.0f);

    glEnd();


    int i22;// upstair window up right 5

    GLfloat x22=0.3265f; GLfloat y22=0.14f; GLfloat radius22 =.02f;
	int triangleAmount22 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi22 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x22, y22); // center of circle
		for(i22 = 0; i22 <= triangleAmount22;i22++) {
			glVertex2f(
		            x22 + (radius22 * cos(i22 *  twicePi22 / triangleAmount22)),
			    y22 + (radius22 * sin(i22 * twicePi22 / triangleAmount22))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 5
	glColor3ub(228,205,57);
    glVertex2f(0.347f, 0.0f);
    glVertex2f(0.347f,0.14f);
    glVertex2f(0.306f, 0.14f);
    glVertex2f(0.306f,0.0f);

    glEnd();

    int i23;// upstair window up right 6

    GLfloat x23=0.2355f; GLfloat y23=0.14f; GLfloat radius23 =.02f;
	int triangleAmount23 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi23 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x23, y23); // center of circle
		for(i23 = 0; i23 <= triangleAmount23;i23++) {
			glVertex2f(
		            x23 + (radius23 * cos(i23 *  twicePi23 / triangleAmount23)),
			    y23 + (radius23 * sin(i23 * twicePi23 / triangleAmount23))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 6
	glColor3ub(228,205,57);
    glVertex2f(0.256f,  0.0f);
    glVertex2f(0.256f, 0.14f);
    glVertex2f(0.215f, 0.14f);
    glVertex2f(0.215f, 0.0f);

    glEnd();


    int i24;// upstair window up left 4

    GLfloat x24=-0.4175f; GLfloat y24=0.14f; GLfloat radius24 =.02f;
	int triangleAmount24 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi24 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x24, y24); // center of circle
		for(i24 = 0; i24 <= triangleAmount21;i24++) {
			glVertex2f(
		            x24 + (radius24 * cos(i24 *  twicePi24 / triangleAmount24)),
			    y24 + (radius24 * sin(i24 * twicePi24 / triangleAmount24))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window left 4
	glColor3ub(228,205,57);
    glVertex2f(-0.438f, 0.0f);
    glVertex2f(-0.438f, 0.14f);
    glVertex2f(-0.397f, 0.14f);
    glVertex2f(-0.397f, 0.0f);

    glEnd();


    int i25;// upstair window up left 5

    GLfloat x25=-0.3265f; GLfloat y25=0.14f; GLfloat radius25 =.02f;
	int triangleAmount25 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi25 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x25, y25); // center of circle
		for(i25 = 0; i25 <= triangleAmount25;i25++) {
			glVertex2f(
		            x25 + (radius25 * cos(i25 *  twicePi25 / triangleAmount25)),
			    y25 + (radius25 * sin(i25 * twicePi25 / triangleAmount25))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window left 5
	glColor3ub(228,205,57);
    glVertex2f(-0.347f, 0.0f);
    glVertex2f(-0.347f,0.14f);
    glVertex2f(-0.306f, 0.14f);
    glVertex2f(-0.306f,0.0f);

    glEnd();

    int i26;// upstair window up left 6

    GLfloat x26=-0.2355f; GLfloat y26=0.14f; GLfloat radius26 =.02f;
	int triangleAmount26 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi26 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x26, y26); // center of circle
		for(i26 = 0; i26 <= triangleAmount26;i26++) {
			glVertex2f(
		            x26 + (radius26 * cos(i26 *  twicePi26 / triangleAmount26)),
			    y26 + (radius26 * sin(i26 * twicePi26 / triangleAmount26))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window left 6
	glColor3ub(228,205,57);
    glVertex2f(-0.256f,  0.0f);
    glVertex2f(-0.256f, 0.14f);
    glVertex2f(-0.215f, 0.14f);
    glVertex2f(-0.215f, 0.0f);

    glEnd();


    //middle

        int i27;// upstair window right

    GLfloat x27=0.15f; GLfloat y27=0.14f; GLfloat radius27 =.02f;
	int triangleAmount27 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi27 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x27, y27); // center of circle
		for(i27 = 0; i27 <= triangleAmount27;i27++) {
			glVertex2f(
		            x27 + (radius27 * cos(i27 *  twicePi27 / triangleAmount27)),
			    y27 + (radius27 * sin(i27 * twicePi27 / triangleAmount27))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window left 6
	glColor3ub(228,205,57);
    glVertex2f(0.17f,  0.0f);
    glVertex2f(0.17f, 0.14f);
    glVertex2f(0.13f, 0.14f);
    glVertex2f(0.13f, 0.0f);

    glEnd();

            int i28;// upstair window left

    GLfloat x28=-0.15f; GLfloat y28=0.14f; GLfloat radius28 =.02f;
	int triangleAmount28 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi28 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x28, y28); // center of circle
		for(i28 = 0; i28 <= triangleAmount28;i28++) {
			glVertex2f(
		            x28 + (radius28 * cos(i28 *  twicePi28 / triangleAmount28)),
			    y28 + (radius28 * sin(i28 * twicePi28 / triangleAmount28))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// middle
	glColor3ub(228,205,57);
    glVertex2f(-0.17f,  0.0f);
    glVertex2f(-0.17f, 0.14f);
    glVertex2f(-0.13f, 0.14f);
    glVertex2f(-0.13f, 0.0f);

    glEnd();



    glBegin(GL_LINES);// upper line
	glColor3ub(1,1,1);
    glVertex2f(0.76f, 0.2f);
	glVertex2f(0.76f, 0.24f);

	glVertex2f(0.76f, 0.24f);
	glVertex2f(-0.76f, 0.24f);

    glVertex2f(-0.76f, 0.24f);
    glVertex2f(-0.76, 0.2f);

    glVertex2f(-0.76, 0.2f);
    glVertex2f(0.76f, 0.2f);

    //some design
    glVertex2f(0.76f, 0.205f);
	glVertex2f(-0.76f, 0.205f);

	glVertex2f(0.76f, 0.21f);
	glVertex2f(-0.76f, 0.21f);

    glEnd();


    int i29;// bubles

    GLfloat x29=0.51f; GLfloat y29=0.225f; GLfloat radius29 =.008f;
	int triangleAmount29 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi29 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x29, y29); // center of circle
		for(i29 = 0; i29 <= triangleAmount29;i29++) {
			glVertex2f(
		            x29 + (radius29 * cos(i29 *  twicePi29 / triangleAmount29)),
			    y29 + (radius29 * sin(i29 * twicePi29 / triangleAmount29))
			);
		}
	glEnd();

	    int i30;// bubles

    GLfloat x30=0.49f; GLfloat y30=0.225f; GLfloat radius30 =.008f;
	int triangleAmount30 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi30 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x30, y30); // center of circle
		for(i30 = 0; i30 <= triangleAmount30;i30++) {
			glVertex2f(
		            x30 + (radius30 * cos(i30 *  twicePi30 / triangleAmount30)),
			    y30 + (radius30 * sin(i30 * twicePi30 / triangleAmount30))
			);
		}
	glEnd();

    int i31;// bubles

    GLfloat x31=0.47f; GLfloat y31=0.225f; GLfloat radius31 =.008f;
	int triangleAmount31 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi31 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x31, y31); // center of circle
		for(i31 = 0; i31 <= triangleAmount31;i31++) {
			glVertex2f(
		            x31 + (radius31 * cos(i31 *  twicePi31 / triangleAmount31)),
			    y31 + (radius31 * sin(i31 * twicePi31 / triangleAmount31))
			);
		}
	glEnd();

    int i32;// bubles

    GLfloat x32=0.42f; GLfloat y32=0.225f; GLfloat radius32 =.008f;
	int triangleAmount32 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi32 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x32, y32); // center of circle
		for(i32 = 0; i32 <= triangleAmount32;i32++) {
			glVertex2f(
		            x32 + (radius32 * cos(i32 *  twicePi32 / triangleAmount32)),
			    y32 + (radius32 * sin(i32 * twicePi32 / triangleAmount32))
			);
		}
	glEnd();

	    int i33;// bubles

    GLfloat x33=0.4f; GLfloat y33=0.225f; GLfloat radius33 =.008f;
	int triangleAmount33 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi33 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x33, y33); // center of circle
		for(i33 = 0; i33 <= triangleAmount33;i33++) {
			glVertex2f(
		            x33 + (radius33 * cos(i33 *  twicePi33 / triangleAmount33)),
			    y33 + (radius33 * sin(i33 * twicePi33 / triangleAmount33))
			);
		}
	glEnd();


    int i34;// bubles

    GLfloat x34=0.38f; GLfloat y34=0.225f; GLfloat radius34 =.008f;
	int triangleAmount34 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi34 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x34, y34); // center of circle
		for(i34 = 0; i34 <= triangleAmount34;i34++) {
			glVertex2f(
		            x34 + (radius34 * cos(i34 *  twicePi34 / triangleAmount34)),
			    y34 + (radius34 * sin(i34 * twicePi34 / triangleAmount34))
			);
		}
	glEnd();

    int i35;// bubles

    GLfloat x35=0.33f; GLfloat y35=0.225f; GLfloat radius35 =.008f;
	int triangleAmount35 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi35 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x35, y35); // center of circle
		for(i35 = 0; i35 <= triangleAmount35;i35++) {
			glVertex2f(
		            x35 + (radius35 * cos(i35 *  twicePi35 / triangleAmount35)),
			    y35 + (radius35 * sin(i35 * twicePi35 / triangleAmount35))
			);
		}
	glEnd();

	    int i36;// bubles

    GLfloat x36=0.31f; GLfloat y36=0.225f; GLfloat radius36 =.008f;
	int triangleAmount36 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi36 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x36, y36); // center of circle
		for(i36 = 0; i36 <= triangleAmount36;i36++) {
			glVertex2f(
		            x36 + (radius36 * cos(i36 *  twicePi36 / triangleAmount36)),
			    y36 + (radius36 * sin(i36 * twicePi36 / triangleAmount36))
			);
		}
	glEnd();

	    int i37;// bubles

    GLfloat x37=0.29f; GLfloat y37=0.225f; GLfloat radius37 =.008f;
	int triangleAmount37 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi37 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x37, y37); // center of circle
		for(i37 = 0; i37 <= triangleAmount37;i37++) {
			glVertex2f(
		            x37 + (radius37 * cos(i37 *  twicePi37 / triangleAmount37)),
			    y37 + (radius37 * sin(i37 * twicePi37 / triangleAmount37))
			);
		}
	glEnd();

    int i38;// bubles

    GLfloat x38=0.24f; GLfloat y38=0.225f; GLfloat radius38 =.008f;
	int triangleAmount38 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi38 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x38, y38); // center of circle
		for(i38 = 0; i38 <= triangleAmount38;i38++) {
			glVertex2f(
		            x38 + (radius38 * cos(i38 *  twicePi38 / triangleAmount38)),
			    y38 + (radius38 * sin(i38 * twicePi38 / triangleAmount38))
			);
		}
	glEnd();

    int i39;// bubles

    GLfloat x39=0.22f; GLfloat y39=0.225f; GLfloat radius39 =.008f;
	int triangleAmount39 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi39 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x39, y39); // center of circle
		for(i39 = 0; i39 <= triangleAmount39;i39++) {
			glVertex2f(
		            x39 + (radius39 * cos(i39 *  twicePi39 / triangleAmount39)),
			    y39 + (radius39 * sin(i39 * twicePi39 / triangleAmount39))
			);
		}
	glEnd();

    int i40;// bubles

    GLfloat x40=0.2f; GLfloat y40=0.225f; GLfloat radius40 =.008f;
	int triangleAmount40 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi40 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x40, y40); // center of circle
		for(i40 = 0; i40 <= triangleAmount40;i40++) {
			glVertex2f(
		            x40 + (radius40 * cos(i40 *  twicePi40 / triangleAmount40)),
			    y40 + (radius40 * sin(i40 * twicePi40 / triangleAmount40))
			);
		}
	glEnd();

    int i41;// bubles

    GLfloat x41=-0.51f; GLfloat y41=0.225f; GLfloat radius41 =.008f;
	int triangleAmount41 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi41 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x41, y41); // center of circle
		for(i41 = 0; i41 <= triangleAmount41;i41++) {
			glVertex2f(
		            x41 + (radius41 * cos(i41 *  twicePi41 / triangleAmount41)),
			    y41 + (radius41 * sin(i41 * twicePi41 / triangleAmount41))
			);
		}
	glEnd();

	    int i42;// bubles

    GLfloat x42=-0.49f; GLfloat y42=0.225f; GLfloat radius42 =.008f;
	int triangleAmount42 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi42 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x42, y42); // center of circle
		for(i42 = 0; i42 <= triangleAmount42;i42++) {
			glVertex2f(
		            x42 + (radius42 * cos(i42 *  twicePi42 / triangleAmount42)),
			    y42 + (radius42 * sin(i42 * twicePi42 / triangleAmount42))
			);
		}
	glEnd();

    int i43;// bubles

    GLfloat x43=-0.47f; GLfloat y43=0.225f; GLfloat radius43 =.008f;
	int triangleAmount43 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi43 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x43, y43); // center of circle
		for(i43 = 0; i43 <= triangleAmount43;i43++) {
			glVertex2f(
		            x43 + (radius43 * cos(i43 *  twicePi43 / triangleAmount43)),
			    y43 + (radius43 * sin(i43 * twicePi43 / triangleAmount43))
			);
		}
	glEnd();

    int i44;// bubles

    GLfloat x44=-0.42f; GLfloat y44=0.225f; GLfloat radius44 =.008f;
	int triangleAmount44 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi44 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x44, y44); // center of circle
		for(i44 = 0; i44 <= triangleAmount44;i44++) {
			glVertex2f(
		            x44 + (radius44 * cos(i44 *  twicePi44 / triangleAmount44)),
			    y44 + (radius44 * sin(i44 * twicePi44 / triangleAmount44))
			);
		}
	glEnd();

	    int i45;// bubles

    GLfloat x45=-0.4f; GLfloat y45=0.225f; GLfloat radius45 =.008f;
	int triangleAmount45 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi45 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x45, y45); // center of circle
		for(i45 = 0; i45 <= triangleAmount45;i45++) {
			glVertex2f(
		            x45 + (radius45 * cos(i45 *  twicePi45 / triangleAmount45)),
			    y45 + (radius45 * sin(i45 * twicePi45 / triangleAmount45))
			);
		}
	glEnd();


    int i46;// bubles

    GLfloat x46=-0.38f; GLfloat y46=0.225f; GLfloat radius46 =.008f;
	int triangleAmount46 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi46 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x46, y46); // center of circle
		for(i46 = 0; i46 <= triangleAmount46;i46++) {
			glVertex2f(
		            x46 + (radius46 * cos(i46 *  twicePi46 / triangleAmount46)),
			    y46 + (radius46 * sin(i46 * twicePi46 / triangleAmount46))
			);
		}
	glEnd();

    int i47;// bubles

    GLfloat x47=-0.33f; GLfloat y47=0.225f; GLfloat radius47 =.008f;
	int triangleAmount47 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi47 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x47, y47); // center of circle
		for(i47 = 0; i47 <= triangleAmount47;i47++) {
			glVertex2f(
		            x47 + (radius47 * cos(i47 *  twicePi47 / triangleAmount47)),
			    y47 + (radius47 * sin(i47 * twicePi47 / triangleAmount47))
			);
		}
	glEnd();

	    int i48;// bubles

    GLfloat x48=-0.31f; GLfloat y48=0.225f; GLfloat radius48 =.008f;
	int triangleAmount48 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi48 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x48, y48); // center of circle
		for(i48 = 0; i48 <= triangleAmount48;i48++) {
			glVertex2f(
		            x48 + (radius48 * cos(i48 *  twicePi48 / triangleAmount48)),
			    y48 + (radius48 * sin(i48 * twicePi48 / triangleAmount48))
			);
		}
	glEnd();

	    int i49;// bubles

    GLfloat x49=-0.29f; GLfloat y49=0.225f; GLfloat radius49 =.008f;
	int triangleAmount49 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi49 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x49, y49); // center of circle
		for(i49 = 0; i49 <= triangleAmount49;i49++) {
			glVertex2f(
		            x49 + (radius49 * cos(i49 *  twicePi49 / triangleAmount49)),
			    y49 + (radius49 * sin(i49 * twicePi49 / triangleAmount49))
			);
		}
	glEnd();

    int i50;// bubles

    GLfloat x50=-0.24f; GLfloat y50=0.225f; GLfloat radius50 =.008f;
	int triangleAmount50 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi50 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x50, y50); // center of circle
		for(i50 = 0; i50 <= triangleAmount50;i50++) {
			glVertex2f(
		            x50 + (radius50 * cos(i50 *  twicePi50 / triangleAmount50)),
			    y50 + (radius50 * sin(i50 * twicePi50 / triangleAmount50))
			);
		}
	glEnd();

    int i51;// bubles

    GLfloat x51=-0.22f; GLfloat y51=0.225f; GLfloat radius51 =.008f;
	int triangleAmount51 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi51 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x51, y51); // center of circle
		for(i51 = 0; i51 <= triangleAmount51;i51++) {
			glVertex2f(
		            x51 + (radius51 * cos(i51 *  twicePi51 / triangleAmount51)),
			    y51 + (radius51 * sin(i51 * twicePi51 / triangleAmount51))
			);
		}
	glEnd();

    int i52;// bubles

    GLfloat x52=-0.2f; GLfloat y52=0.225f; GLfloat radius52 =.008f;
	int triangleAmount52 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi52 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x52, y52); // center of circle
		for(i52 = 0; i52 <= triangleAmount52;i52++) {
			glVertex2f(
		            x52 + (radius52 * cos(i52 *  twicePi52 / triangleAmount52)),
			    y52 + (radius52 * sin(i52 * twicePi52 / triangleAmount52))
			);
		}
	glEnd();



    int i53;// rest door
    GLfloat x53=0.502f; GLfloat y53=0.14f; GLfloat radius53 =.02f;
    int triangleAmount53 = 100; //# of triangles used to draw circle


	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi53 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x53, y53); // center of circle
		for(i53 = 0; i53 <= triangleAmount53;i53++) {
			glVertex2f(
                x53 + (radius53 * cos(i53 *  twicePi53 / triangleAmount53)),
			    y53 + (radius53 * sin(i53 * twicePi53 / triangleAmount53))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// upstair rest 2
	glColor3ub(228,205,57);
    glVertex2f(0.482f,  0.0f);
    glVertex2f(0.482f, 0.14f);
    glVertex2f(0.522f, 0.14f);
    glVertex2f(0.522f, 0.0f);

    glEnd();

    int i54;// rest door
    GLfloat x54=-0.502f; GLfloat y54=0.14f; GLfloat radius54 =.02f;
    int triangleAmount54 = 100; //# of triangles used to draw circle


	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi54 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x54, y54); // center of circle
		for(i54 = 0; i54 <= triangleAmount54;i54++) {
			glVertex2f(
                x54 + (radius54 * cos(i54 *  twicePi54 / triangleAmount54)),
			    y54 + (radius54 * sin(i54 * twicePi54 / triangleAmount54))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// upstair rest 2
	glColor3ub(228,205,57);
    glVertex2f(-0.482f,  0.0f);
    glVertex2f(-0.482f, 0.14f);
    glVertex2f(-0.522f, 0.14f);
    glVertex2f(-0.522f, 0.0f);

    glEnd();
    //glLoadIdentity();

    glBegin(GL_LINES);// upstair right pillar
    glColor3ub(0,0,0);

    glVertex2f(0.575f, 0.2f);
    glVertex2f(0.575f, -0.02f);

    glVertex2f(0.571f, 0.2f);
    glVertex2f(0.571f, -0.02f);

    glVertex2f(0.554f, -0.02f);
    glVertex2f(0.554f,0.2f);

    glVertex2f(0.55f, -0.02f);
    glVertex2f(0.55f,0.2f);


    glEnd();

        glBegin(GL_LINES);// upstair left pillar

    glVertex2f(-0.575f, 0.2f);
    glVertex2f(-0.575f, -0.02f);

    glVertex2f(-0.571f, 0.2f);
    glVertex2f(-0.571f, -0.02f);

    glVertex2f(-0.554f, -0.02f);
    glVertex2f(-0.554f,0.2f);

    glVertex2f(-0.55f, -0.02f);
    glVertex2f(-0.55f,0.2f);


    glEnd();

    glBegin(GL_QUADS);//coloring minar
    glColor3ub(163,53,53);

    glVertex2f(0.575f, 0.24f);
    glVertex2f(0.575f, 0.34f);
    glVertex2f(0.55f,0.34f);
    glVertex2f(0.55f,0.24f);

    glEnd();

    glBegin(GL_LINES);// roof right pillar
    glColor3ub(1,1,1);

    glVertex2f(0.575f, 0.34f);
    glVertex2f(0.575f, 0.24f);

    glVertex2f(0.571f, 0.34f);
    glVertex2f(0.571f, 0.24f);

    glVertex2f(0.554f, 0.24f);
    glVertex2f(0.554f,0.34f);

    glVertex2f(0.55f, 0.24f);
    glVertex2f(0.55f,0.34f);

    glVertex2f(0.55f, 0.34f);//finishing
    glVertex2f(0.575f,0.34f);


    glEnd();

    glBegin(GL_QUADS);//color minar star
    glColor3ub(163,53,53);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);

    glEnd();

    glBegin(GL_LINES);//color minar star
    glColor3ub(1,1,1);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.562f, 0.34f);

    glEnd();








 glBegin(GL_LINES);//upstair right pillar corner
 glColor3ub(1,1,1);


    glVertex2f(0.722f, -0.02f);
    glVertex2f(0.722f,0.2f);

    glVertex2f(0.724f, -0.02f);
    glVertex2f(0.724f,0.2f);

    glVertex2f(0.726f, -0.02f);
    glVertex2f(0.726f,0.2f);

    glVertex2f(0.756f, -0.02f);
    glVertex2f(0.756f, 0.2f);

    glVertex2f(0.758f, -0.02f);
    glVertex2f(0.758f,0.2f);

    glVertex2f(0.76f, -0.02f);
    glVertex2f(0.76f, 0.2f);
    glEnd();

     glBegin(GL_LINES);//upstair right pillar corner
 glColor3ub(1,1,1);


    glVertex2f(-0.722f, -0.02f);
    glVertex2f(-0.722f,0.2f);

    glVertex2f(-0.724f, -0.02f);
    glVertex2f(-0.724f,0.2f);

    glVertex2f(-0.726f, -0.02f);
    glVertex2f(-0.726f,0.2f);

    glVertex2f(-0.756f, -0.02f);
    glVertex2f(-0.756f, 0.2f);

    glVertex2f(-0.758f, -0.02f);
    glVertex2f(-0.758f,0.2f);

    glVertex2f(-0.76f, -0.02f);
    glVertex2f(-0.76f, 0.2f);
    glEnd();



    glTranslatef(.18,0,0);//translate pillar 1
    //glScalef(.4,.4,0);


    glBegin(GL_QUADS);//coloring minar
    glColor3ub(163,53,53);

    glVertex2f(0.575f, 0.24f);
    glVertex2f(0.575f, 0.34f);
    glVertex2f(0.55f,0.34f);
    glVertex2f(0.55f,0.24f);

    glEnd();

    glBegin(GL_LINES);// roof right pillar
    glColor3ub(1,1,1);

    glVertex2f(0.575f, 0.34f);
    glVertex2f(0.575f, 0.24f);

    glVertex2f(0.571f, 0.34f);
    glVertex2f(0.571f, 0.24f);

    glVertex2f(0.554f, 0.24f);
    glVertex2f(0.554f,0.34f);

    glVertex2f(0.55f, 0.24f);
    glVertex2f(0.55f,0.34f);

    glVertex2f(0.55f, 0.34f);//finishing
    glVertex2f(0.575f,0.34f);


    glEnd();

    glBegin(GL_QUADS);//color minar star
    glColor3ub(163,53,53);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);

    glEnd();

    glBegin(GL_LINES);//color minar star
    glColor3ub(1,1,1);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.562f, 0.34f);

    glEnd();




    glLoadIdentity();


        glTranslatef(-1.31,0,0);//translate pillar 2 left
    //glScalef(.4,.4,0);


    glBegin(GL_QUADS);//coloring minar
    glColor3ub(163,53,53);

    glVertex2f(0.575f, 0.24f);
    glVertex2f(0.575f, 0.34f);
    glVertex2f(0.55f,0.34f);
    glVertex2f(0.55f,0.24f);

    glEnd();

    glBegin(GL_LINES);// roof right pillar
    glColor3ub(1,1,1);

    glVertex2f(0.575f, 0.34f);
    glVertex2f(0.575f, 0.24f);

    glVertex2f(0.571f, 0.34f);
    glVertex2f(0.571f, 0.24f);

    glVertex2f(0.554f, 0.24f);
    glVertex2f(0.554f,0.34f);

    glVertex2f(0.55f, 0.24f);
    glVertex2f(0.55f,0.34f);

    glVertex2f(0.55f, 0.34f);//finishing
    glVertex2f(0.575f,0.34f);


    glEnd();

    glBegin(GL_QUADS);//color minar star
    glColor3ub(163,53,53);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);

    glEnd();

    glBegin(GL_LINES);//color minar star
    glColor3ub(1,1,1);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.562f, 0.34f);

    glEnd();




    glLoadIdentity();


        glTranslatef(-1.122,0,0);//translate pillar 3
    //glScalef(.4,.4,0);


    glBegin(GL_QUADS);//coloring minar
    glColor3ub(163,53,53);

    glVertex2f(0.575f, 0.24f);
    glVertex2f(0.575f, 0.34f);
    glVertex2f(0.55f,0.34f);
    glVertex2f(0.55f,0.24f);

    glEnd();

    glBegin(GL_LINES);// roof right pillar
    glColor3ub(1,1,1);

    glVertex2f(0.575f, 0.34f);
    glVertex2f(0.575f, 0.24f);

    glVertex2f(0.571f, 0.34f);
    glVertex2f(0.571f, 0.24f);

    glVertex2f(0.554f, 0.24f);
    glVertex2f(0.554f,0.34f);

    glVertex2f(0.55f, 0.24f);
    glVertex2f(0.55f,0.34f);

    glVertex2f(0.55f, 0.34f);//finishing
    glVertex2f(0.575f,0.34f);


    glEnd();

    glBegin(GL_QUADS);//color minar star
    glColor3ub(163,53,53);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);

    glEnd();

    glBegin(GL_LINES);//color minar star
    glColor3ub(1,1,1);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.562f, 0.34f);

    glEnd();




    glLoadIdentity();

       int i58;// gombuj

    GLfloat x58=0.0f; GLfloat y58=0.41f; GLfloat radius58 =.08f;
	int triangleAmount58 = 30; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi58 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(163,53,53);
		glVertex2f(x58, y58); // center of circle
		for(i58 = 0; i58 <= triangleAmount58;i58++) {
			glVertex2f(
		            x58 + (radius58 * cos(i58 *  twicePi58 / triangleAmount58)),
			    y58 + (radius58 * sin(i58 * twicePi58 / triangleAmount58))
			);
		}
	glEnd();

	glBegin(GL_TRIANGLES);//overlap middle
	glColor3ub(163,53,53);
    glVertex2f(0.07f,  0.45f);
    glVertex2f(0.0, 0.55f);
    glVertex2f(-0.07f, 0.45f);


    glEnd();


    glBegin(GL_QUADS);//overlap middle
	glColor3ub(163,53,53);
    glVertex2f(0.12f,  0.0f);
    glVertex2f(0.12f, 0.28f);
    glVertex2f(-0.10f, 0.28f);
    glVertex2f(-0.10f, 0.0f);

    glEnd();

    glBegin(GL_QUADS);//pillar after minar
	glColor3ub(163,53,53);
    glVertex2f(0.12f,  0.0f);
    glVertex2f(0.12f, 0.31f);
    glVertex2f(0.093f, 0.31f);
    glVertex2f(0.093f, 0.0f);

    glEnd();

    glBegin(GL_LINES);//pillar middle right
	glColor3ub(1,1,1);
    glVertex2f(0.12f,  0.0f);
    glVertex2f(0.12f, 0.31f);
    glVertex2f(0.12f, 0.31f);
    glVertex2f(0.093f, 0.31f);
    glVertex2f(0.093f, 0.31f);
    glVertex2f(0.093f, 0.0f);
    glVertex2f(0.093f, 0.0f);
    glVertex2f(0.12f,  0.0f);



    glEnd();

    glBegin(GL_QUADS);//pillar after minar
	glColor3ub(163,53,53);
    glVertex2f(-0.12f,  0.0f);
    glVertex2f(-0.12f, 0.31f);
    glVertex2f(-0.093f, 0.31f);
    glVertex2f(-0.093f, 0.0f);

    glEnd();

    glBegin(GL_LINES);//pillar middle left
	glColor3ub(1,1,1);
    glVertex2f(-0.12f,  0.0f);
    glVertex2f(-0.12f, 0.31f);
    glVertex2f(-0.12f, 0.31f);
    glVertex2f(-0.093f, 0.31f);
    glVertex2f(-0.093f, 0.31f);
    glVertex2f(-0.093f, 0.0f);
    glVertex2f(-0.093f, 0.0f);
    glVertex2f(-0.12f,  0.0f);



    glEnd();

    glBegin(GL_POLYGON);//polygon right
	glColor3ub(163,53,53);
    glVertex2f(0.12f,  0.31f);
    glVertex2f(0.13f, 0.35f);
    glVertex2f(0.1065f, 0.38f);
    glVertex2f(0.083f, 0.35f);
    glVertex2f(0.093f, 0.31f);




    glEnd();

    glBegin(GL_LINES);//polygon lines right
	glColor3ub(1,1,1);
    glVertex2f(0.12f,  0.31f);
    glVertex2f(0.13f, 0.35f);

    glVertex2f(0.13f, 0.35f);
    glVertex2f(0.1065f, 0.38f);

    glVertex2f(0.1065f, 0.38f);
    glVertex2f(0.083f, 0.35f);

    glVertex2f(0.083f, 0.35f);
    glVertex2f(0.093f, 0.31f);

    glVertex2f(0.093f, 0.31f);
    glVertex2f(0.12f,  0.31f);





    glEnd();

        glBegin(GL_POLYGON);//polygon left
	glColor3ub(163,53,53);
    glVertex2f(-00.12f,  0.31f);
    glVertex2f(-0.13f, 0.35f);
    glVertex2f(-0.1065f, 0.38f);
    glVertex2f(-0.083f, 0.35f);
    glVertex2f(-0.093f, 0.31f);


    glEnd();

    glBegin(GL_LINES);//polygon lines left
	glColor3ub(1,1,1);
    glVertex2f(-0.12f,  0.31f);
    glVertex2f(-0.13f, 0.35f);

    glVertex2f(-0.13f, 0.35f);
    glVertex2f(-0.1065f, 0.38f);

    glVertex2f(-0.1065f, 0.38f);
    glVertex2f(-0.083f, 0.35f);

    glVertex2f(-0.083f, 0.35f);
    glVertex2f(-0.093f, 0.31f);

    glVertex2f(-0.093f, 0.31f);
    glVertex2f(-0.12f,  0.31f);


    glEnd();


    glTranslatef(-.454,0.03,0);//translate pillar middle
    //glScalef(.4,.4,0);

    glBegin(GL_QUADS);//color minar star
    glColor3ub(163,53,53);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);

    glEnd();

    glBegin(GL_LINES);//color minar star
    glColor3ub(1,1,1);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.562f, 0.34f);

    glEnd();




    glLoadIdentity();

    glTranslatef(.454,0.03,0);//translate pillar middle
    //glScalef(.4,.4,0);

    glBegin(GL_QUADS);//color minar star
    glColor3ub(163,53,53);

    glVertex2f(-0.562f, 0.34f);
    glVertex2f(-0.57f, 0.36f);
    glVertex2f(-0.562f,0.38f);
    glVertex2f(-0.554f,0.36f);

    glEnd();

    glBegin(GL_LINES);//color minar star
    glColor3ub(0,0,0);

    glVertex2f(-0.562f, 0.34f);
    glVertex2f(-0.57f, 0.36f);
    glVertex2f(-0.57f, 0.36f);
    glVertex2f(-0.562f,0.38f);
    glVertex2f(-0.562f,0.38f);
    glVertex2f(-0.554f,0.36f);
    glVertex2f(-0.554f,0.36f);
    glVertex2f(-0.562f, 0.34f);

    glEnd();




    glLoadIdentity();

    int i55;// middle

    GLfloat x55=0.0f; GLfloat y55=0.18f; GLfloat radius55 =.02f;
	int triangleAmount55 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi55 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x55, y55); // center of circle
		for(i55 = 0; i55 <= triangleAmount55;i55++) {
			glVertex2f(
		            x55 + (radius55 * cos(i55 *  twicePi55 / triangleAmount55)),
			    y55 + (radius55 * sin(i55 * twicePi55 / triangleAmount55))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// middle
	glColor3ub(228,205,57);
    glVertex2f(0.02f,  0.0f);
    glVertex2f(0.02f, 0.18f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.0f);

    glEnd();

        int i56;// middle

    GLfloat x56=0.06f; GLfloat y56=0.18f; GLfloat radius56 =.010f;
	int triangleAmount56 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi56 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x56, y56); // center of circle
		for(i56 = 0; i56 <= triangleAmount56;i56++) {
			glVertex2f(
		            x56 + (radius56 * cos(i56 *  twicePi56 / triangleAmount56)),
			    y56 + (radius56 * sin(i56 * twicePi56 / triangleAmount56))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// middle
	glColor3ub(228,205,57);
    glVertex2f(0.07f,  0.0f);
    glVertex2f(0.07f, 0.18f);
    glVertex2f(0.05f, 0.18f);
    glVertex2f(0.05f, 0.0f);

    glEnd();

            int i57;// upstair window left

    GLfloat x57=-0.06f; GLfloat y57=0.18f; GLfloat radius57 =.010f;
	int triangleAmount57 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi57 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x57, y57); // center of circle
		for(i57 = 0; i57 <= triangleAmount57;i57++) {
			glVertex2f(
		            x57 + (radius57 * cos(i57 *  twicePi57 / triangleAmount57)),
			    y57 + (radius57 * sin(i57 * twicePi57 / triangleAmount57))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// middle
	glColor3ub(228,205,57);
    glVertex2f(-0.07f,  0.0f);
    glVertex2f(-0.07f, 0.18f);
    glVertex2f(-0.05f, 0.18f);
    glVertex2f(-0.05f, 0.0f);

    glEnd();

    glBegin(GL_QUADS);//middle line
	glColor3ub(0,0,0);
    glVertex2f(0.092f,  0.26f);
    glVertex2f(0.092f, 0.27f);
    glVertex2f(-0.092f, 0.27f);
    glVertex2f(-0.092f, 0.26f);
    glEnd();


    glBegin(GL_POLYGON);//middle polygon
	glColor3ub(163,53,53);
    glVertex2f(0.08f,  0.28f);
    glVertex2f(0.08f, 0.38f);

    glVertex2f(0.05f, 0.4f);
    glVertex2f(-0.05f, 0.4f);

    glVertex2f(-0.08f, 0.38f);
    glVertex2f(-0.08f, 0.28f);
    glEnd();

    glBegin(GL_LINES);//middle polygon line
	glColor3ub(0,0,0);
    glVertex2f(0.08f,  0.28f);
    glVertex2f(0.08f, 0.38f);

    glVertex2f(0.08f, 0.38f);
    glVertex2f(0.05f, 0.4f);

    glVertex2f(0.05f, 0.4f);
    glVertex2f(-0.05f, 0.4f);

    glVertex2f(-0.05f, 0.4f);
    glVertex2f(-0.08f, 0.38f);

    glVertex2f(-0.08f, 0.38f);
    glVertex2f(-0.08f, 0.28f);

    glVertex2f(-0.08f, 0.28f);
    glVertex2f(0.08f,  0.28f);
    glEnd();






    glBegin(GL_POLYGON);//middle polygon 2
	glColor3ub(163,53,53);
    //glVertex2f(0.08f,  0.28f);
    glVertex2f(0.08f, 0.38f);
    glVertex2f(0.09f, 0.39f);

    //glVertex2f(0.09f, 0.39f);
    glVertex2f(0.05f, 0.42f);


    //glVertex2f(0.05f, 0.42f);
    glVertex2f(-0.05f, 0.42f);

    //glVertex2f(-0.05f, 0.42f);
    glVertex2f(-0.09f, 0.39f);

    //glVertex2f(-0.09f, 0.39f);
    glVertex2f(-0.08f, 0.38f);

    //glVertex2f(-0.07f, 0.39f);
   // glVertex2f(-0.08f, 0.38f);

    //glVertex2f(-0.08f, 0.38f);
    glVertex2f(-0.05f, 0.4f);

   // glVertex2f(0.05f, 0.4f);
    glVertex2f(0.08f, 0.38f);
    glEnd();


    glBegin(GL_LINES);//middle polygon 2
	glColor3ub(0,0,0);
    //glVertex2f(0.08f,  0.28f);
    glVertex2f(0.08f, 0.38f);
    glVertex2f(0.09f, 0.39f);

    glVertex2f(0.09f, 0.39f);
    glVertex2f(0.05f, 0.42f);


    glVertex2f(0.05f, 0.42f);
    glVertex2f(-0.05f, 0.42f);

    glVertex2f(-0.05f, 0.42f);
    glVertex2f(-0.09f, 0.39f);

    glVertex2f(-0.09f, 0.39f);
    glVertex2f(-0.08f, 0.38f);

    //glVertex2f(-0.07f, 0.39f);
   // glVertex2f(-0.08f, 0.38f);

    glVertex2f(-0.08f, 0.38f);
    glVertex2f(-0.05f, 0.4f);

    glVertex2f(-0.05f, 0.4f);
    glVertex2f(0.05f, 0.4f);

    glVertex2f(0.05f, 0.4f);
    glVertex2f(0.08f, 0.38f);
    glEnd();


    glBegin(GL_QUADS);//middle line
	glColor3ub(0,0,0);
    glVertex2f(0.006f,  0.54f);
    glVertex2f(0.006f, 0.58f);
    glVertex2f(-0.006f, 0.58f);
    glVertex2f(-0.006f, 0.54f);
    glEnd();



























    glBegin(GL_QUADS);// shiri
	glColor3ub(106,108,109);

	glVertex2f(0.24f, -0.26f);
	glVertex2f(0.14f, 0.0f);
    glVertex2f(-.14f, 0.0f);
    glVertex2f(-0.24,-0.26f);
    glEnd();

    glBegin(GL_LINES);// shiri
	glColor3ub(0,0,0);

	glVertex2f(0.24f, -0.26f);
	glVertex2f(0.14f, 0.0f);

	glVertex2f(0.14f, 0.0f);
    glVertex2f(-.14f, 0.0f);

    glVertex2f(-.14f, 0.0f);
    glVertex2f(-0.24,-0.26f);

    glVertex2f(-0.24,-0.26f);
    glVertex2f(0.24f, -0.26f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.144f, -0.02f);
	glVertex2f(0.144f, -0.015f);
    glVertex2f(-.144f, -0.015f);
    glVertex2f(-0.144,-0.02f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.148f, -0.045f);
	glVertex2f(0.148f, -0.04f);
    glVertex2f(-.148f, -0.04f);
    glVertex2f(-0.148,-0.045f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.162f, -0.065f);
	glVertex2f(0.162f, -0.06f);
    glVertex2f(-.162f, -0.06f);
    glVertex2f(-0.162,-0.065f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.172f, -0.085f);
	glVertex2f(0.172f, -0.08f);
    glVertex2f(-.172f, -0.08f);
    glVertex2f(-0.172,-0.085f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.182f, -0.105f);
	glVertex2f(0.182f, -0.1f);
    glVertex2f(-.182f, -0.1f);
    glVertex2f(-0.182,-0.105f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.18f, -0.115f);
	glVertex2f(0.18f, -0.12f);
    glVertex2f(-.18f, -0.12f);
    glVertex2f(-0.18,-0.115f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.19f, -0.14f);
	glVertex2f(0.19f, -0.13f);
    glVertex2f(-.19f, -0.13f);
    glVertex2f(-0.19,-0.14f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.2f, -0.16f);
	glVertex2f(0.2f, -0.15f);
    glVertex2f(-.2f, -0.15f);
    glVertex2f(-0.2,-0.16f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.21f, -0.18f);
	glVertex2f(0.21f, -0.17f);
    glVertex2f(-.21f, -0.17f);
    glVertex2f(-0.21,-0.18f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.22f, -0.2f);
	glVertex2f(0.22f, -0.19f);
    glVertex2f(-.22f, -0.19f);
    glVertex2f(-0.22,-0.2f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.225f, -0.22f);
	glVertex2f(0.225f, -0.21f);
    glVertex2f(-.225f, -0.21f);
    glVertex2f(-0.225,-0.22f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.23f, -0.24f);
	glVertex2f(0.23f, -0.23f);
    glVertex2f(-.23f, -0.23f);
    glVertex2f(-0.23,-0.24f);
    glEnd();


    //Fence-Left-1
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(-.25,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-2
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(.105,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-3
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(.46,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-4
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(.815,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-5
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(1.17,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-6
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(1.525,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-7
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(1.88,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();



    //FootWalk
    glBegin(GL_QUADS);
    glColor3ub(199,136,74);
    glVertex2f(-1,-.6);
    glVertex2f(-1,-.68);
    glVertex2f(1,-.68);
    glVertex2f(1,-.6);
    glEnd();

    glScalef(.5,.4,0);
    glTranslatef(1.6,-1.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();
glLoadIdentity();

    glScalef(.5,.4,0);
    glTranslatef(2.2,-1.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();
glLoadIdentity();


    glScalef(.5,.4,0);
    glTranslatef(-.05,-1.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();
glLoadIdentity();

    glScalef(.5,.4,0);
    glTranslatef(-0.7,-1.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();
glLoadIdentity();





            int i59;// tree

    GLfloat x59=0.4f; GLfloat y59=-0.44f; GLfloat radius59 =.024f;
	int triangleAmount59 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi59 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x59, y59); // center of circle
		for(i59 = 0; i59 <= triangleAmount59;i59++) {
			glVertex2f(
		            x59 + (radius59 * cos(i59 *  twicePi59 / triangleAmount59)),
			    y59 + (radius59 * sin(i59 * twicePi59 / triangleAmount59))
			);
		}
	glEnd();


	            int i60;//tree

    GLfloat x60=0.46f; GLfloat y60=-0.44f; GLfloat radius60 =.024f;
	int triangleAmount60 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi60 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x60, y60); // center of circle
		for(i60 = 0; i60 <= triangleAmount60;i60++) {
			glVertex2f(
		            x60 + (radius60 * cos(i60 *  twicePi60 / triangleAmount60)),
			    y60 + (radius60 * sin(i60 * twicePi60 / triangleAmount60))
			);
		}
	glEnd();

		            int i61;//tree

    GLfloat x61=0.43f; GLfloat y61=-0.42f; GLfloat radius61 =.036f;
	int triangleAmount61 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi61 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x61, y61); // center of circle
		for(i61 = 0; i61 <= triangleAmount61;i61++) {
			glVertex2f(
		            x61 + (radius61 * cos(i61 *  twicePi61 / triangleAmount61)),
			    y61 + (radius61 * sin(i61 * twicePi61 / triangleAmount61))
			);
		}
	glEnd();


		            int i62;//tree

    GLfloat x62=0.69f; GLfloat y62=-0.44f; GLfloat radius62 =.024f;
	int triangleAmount62 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi62 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x62, y62); // center of circle
		for(i62 = 0; i62 <= triangleAmount62;i62++) {
			glVertex2f(
		            x62 + (radius62 * cos(i62 *  twicePi62 / triangleAmount62)),
			    y62 + (radius62 * sin(i62 * twicePi62 / triangleAmount62))
			);
		}
	glEnd();


			            int i63;//tree

    GLfloat x63=0.76f; GLfloat y63=-0.44f; GLfloat radius63 =.024f;
	int triangleAmount63 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi63 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x63, y63); // center of circle
		for(i63 = 0; i63 <= triangleAmount63;i63++) {
			glVertex2f(
		            x63 + (radius63 * cos(i63 *  twicePi63 / triangleAmount63)),
			    y63 + (radius63 * sin(i63 * twicePi63 / triangleAmount63))
			);
		}
	glEnd();


				            int i64;//tree

    GLfloat x64=0.73f; GLfloat y64=-0.42f; GLfloat radius64 =.036f;
	int triangleAmount64 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi64 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x64, y64); // center of circle
		for(i64 = 0; i64 <= triangleAmount64;i64++) {
			glVertex2f(
		            x64 + (radius64 * cos(i64 *  twicePi64 / triangleAmount64)),
			    y64 + (radius64 * sin(i64 * twicePi64 / triangleAmount64))
			);
		}
	glEnd();


				            int i65;//tree

    GLfloat x65=-0.7f; GLfloat y65=-0.44f; GLfloat radius65 =.024f;
	int triangleAmount65 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi65 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x65, y65); // center of circle
		for(i65 = 0; i65 <= triangleAmount65;i65++) {
			glVertex2f(
		            x65 + (radius65 * cos(i65 *  twicePi65 / triangleAmount65)),
			    y65 + (radius65 * sin(i65 * twicePi65 / triangleAmount65))
			);
		}
	glEnd();

				            int i66;//tree

    GLfloat x66=-0.76f; GLfloat y66=-0.44f; GLfloat radius66 =.024f;
	int triangleAmount66 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi66 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x66, y66); // center of circle
		for(i66 = 0; i66 <= triangleAmount66;i66++) {
			glVertex2f(
		            x66 + (radius66 * cos(i66 *  twicePi66 / triangleAmount66)),
			    y66 + (radius66 * sin(i66 * twicePi66 / triangleAmount66))
			);
		}
	glEnd();


					            int i67;//tree

    GLfloat x67=-0.73f; GLfloat y67=-0.42f; GLfloat radius67 =.036f;
	int triangleAmount67 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi67 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x67, y67); // center of circle
		for(i67 = 0; i67 <= triangleAmount67;i67++) {
			glVertex2f(
		            x67 + (radius67 * cos(i67 *  twicePi67 / triangleAmount67)),
			    y67 + (radius67 * sin(i67 * twicePi67 / triangleAmount67))
			);
		}
	glEnd();


					            int i68;//tree

    GLfloat x68=-0.36f; GLfloat y68=-0.44f; GLfloat radius68 =.024f;
	int triangleAmount68 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi68 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x68, y68); // center of circle
		for(i68 = 0; i68 <= triangleAmount68;i68++) {
			glVertex2f(
		            x68 + (radius68 * cos(i68 *  twicePi68 / triangleAmount68)),
			    y68 + (radius68 * sin(i68 * twicePi68 / triangleAmount68))
			);
		}
	glEnd();


						            int i69;//tree

    GLfloat x69=-0.44f; GLfloat y69=-0.44f; GLfloat radius69 =.024f;
	int triangleAmount69 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi69 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x69, y69); // center of circle
		for(i69 = 0; i69 <= triangleAmount69;i69++) {
			glVertex2f(
		            x69 + (radius69 * cos(i69 *  twicePi69 / triangleAmount69)),
			    y69 + (radius69 * sin(i69 * twicePi69 / triangleAmount69))
			);
		}
	glEnd();

							            int i70;//tree

    GLfloat x70=-0.4f; GLfloat y70=-0.42f; GLfloat radius70 =.036f;
	int triangleAmount70 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi70 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x70, y70); // center of circle
		for(i70 = 0; i70 <= triangleAmount70;i70++) {
			glVertex2f(
		            x70 + (radius70 * cos(i70 *  twicePi70 / triangleAmount70)),
			    y70 + (radius70 * sin(i70 * twicePi70 / triangleAmount70))
			);
		}
	glEnd();

	    glBegin(GL_QUADS);
    glColor3ub(28, 26, 25);
    glVertex2f(-1,-.67);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glVertex2f(1,-.67);
    glEnd();
    //Road-Line
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(230,200,0);
    glVertex2f(-.98,-.835);
    glVertex2f(-.88,-.835);

    glVertex2f(-.83,-.835);
    glVertex2f(-.73,-.835);

    glVertex2f(-.68,-.835);
    glVertex2f(-.58,-.835);

    glVertex2f(-.53,-.835);
    glVertex2f(-.43,-.835);

    glVertex2f(-.38,-.835);
    glVertex2f(-.28,-.835);

    glVertex2f(-.23,-.835);
    glVertex2f(-.13,-.835);

    glVertex2f(-.08,-.835);
    glVertex2f(.02,-.835);

    glVertex2f(.07,-.835);
    glVertex2f(.17,-.835);

    glVertex2f(.22,-.835);
    glVertex2f(.32,-.835);

    glVertex2f(.37,-.835);
    glVertex2f(.47,-.835);

    glVertex2f(.52,-.835);
    glVertex2f(.62,-.835);

    glVertex2f(.67,-.835);
    glVertex2f(.77,-.835);

    glVertex2f(.82,-.835);
    glVertex2f(.92,-.835);

    glVertex2f(.97,-.835);
    glVertex2f(1,-.835);

    glEnd();



    glTranslatef(.735,-.099,0);
	glScalef(.6,.6,0);
    glBegin(GL_QUADS);//tree
	glColor3f(0.1f, .0f, 0.0f);

	glVertex2f(0.3f, -0.3f);
	glVertex2f(0.3f, 0.08f);
    glVertex2f(0.25f,0.08f);
    glVertex2f(0.25f,-0.3f);
    glEnd();

    glBegin(GL_TRIANGLES);
	glColor3f(0.1f, .0f, 0.0f);


	glVertex2f(0.30f,-0.3f);
    glVertex2f(0.25f,-0.3f);
    glVertex2f(0.20f,-0.38f);

    glVertex2f(0.36f,-0.38f);
    glVertex2f(0.3f,-0.3f);
    glVertex2f(0.25f,-0.3f);


    glVertex2f(0.3f, -0.3f);
    glVertex2f(0.25f, -0.3f);
    glVertex2f(0.275f,-0.40f);


    glEnd();

    glBegin(GL_QUADS);//branch
	glColor3f(0.1f, .0f, 0.0f);

	glVertex2f(0.3f, 0.08f);
	glVertex2f(0.38f, 0.3f);
	glVertex2f(0.38f, 0.3f);
    glVertex2f(0.28f,0.08f);

    glVertex2f(0.28f, 0.08f);
	glVertex2f(0.17f, 0.3f);
	glVertex2f(0.17f, 0.3f);
    glVertex2f(0.25f,0.08f);
    glEnd();

    glLoadIdentity();


    //2nd tree
    glTranslatef(-.735,-.099,0);
	glScalef(.6,.6,0);
    glBegin(GL_QUADS);//tree
	glColor3f(0.1f, .0f, 0.0f);

	glVertex2f(-0.3f, -0.3f);
	glVertex2f(-0.3f, 0.08f);
    glVertex2f(-0.25f,0.08f);
    glVertex2f(-0.25f,-0.3f);
    glEnd();

    glBegin(GL_TRIANGLES);
	glColor3f(0.1f, .0f, 0.0f);


	glVertex2f(-0.30f,-0.3f);
    glVertex2f(-0.25f,-0.3f);
    glVertex2f(-0.20f,-0.38f);

    glVertex2f(-0.36f,-0.38f);
    glVertex2f(-0.3f,-0.3f);
    glVertex2f(-0.25f,-0.3f);


    glVertex2f(-0.3f, -0.3f);
    glVertex2f(-0.25f, -0.3f);
    glVertex2f(-0.275f,-0.40f);


    glEnd();

    glBegin(GL_QUADS);//branch
	glColor3f(0.1f, .0f, 0.0f);

	glVertex2f(-0.3f, 0.08f);
	glVertex2f(-0.38f, 0.3f);
	glVertex2f(-0.38f, 0.3f);
    glVertex2f(-0.28f,0.08f);

    glVertex2f(-0.28f, 0.08f);
	glVertex2f(-0.17f, 0.3f);
	glVertex2f(-0.17f, 0.3f);
    glVertex2f(-0.25f,0.08f);
    glEnd();

    glLoadIdentity();



    int i71;//tree

    GLfloat x71=0.85f; GLfloat y71=0.02f; GLfloat radius71 =.05f;
	int triangleAmount71 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi71 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x71, y71); // center of circle
		for(i71 = 0; i71 <= triangleAmount71;i71++) {
			glVertex2f(
		            x71 + (radius71 * cos(i71 *  twicePi71 / triangleAmount71)),
			    y71 + (radius71 * sin(i71 * twicePi71 / triangleAmount71))
			);
		}
	glEnd();

	    int i72;//tree

    GLfloat x72=0.95f; GLfloat y72=0.02f; GLfloat radius72 =.05f;
	int triangleAmount72 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi72 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x72, y72); // center of circle
		for(i72 = 0; i72 <= triangleAmount72;i72++) {
			glVertex2f(
		            x72 + (radius72 * cos(i72 *  twicePi72 / triangleAmount72)),
			    y72 + (radius72 * sin(i72 * twicePi72 / triangleAmount72))
			);
		}
	glEnd();


		    int i73;//tree

    GLfloat x73=0.86f; GLfloat y73=0.084f; GLfloat radius73 =.05f;
	int triangleAmount73 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi73 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x73, y73); // center of circle
		for(i73 = 0; i73 <= triangleAmount73;i73++) {
			glVertex2f(
		            x73 + (radius73 * cos(i73 *  twicePi73 / triangleAmount73)),
			    y73 + (radius73 * sin(i73 * twicePi73 / triangleAmount73))
			);
		}
	glEnd();

			    int i74;//tree

    GLfloat x74=0.93f; GLfloat y74=0.084f; GLfloat radius74 =.05f;
	int triangleAmount74 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi74 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x74, y74); // center of circle
		for(i74 = 0; i74 <= triangleAmount74;i74++) {
			glVertex2f(
		            x74 + (radius74 * cos(i74 *  twicePi74 / triangleAmount74)),
			    y74 + (radius74 * sin(i74 * twicePi74 / triangleAmount74))
			);
		}
	glEnd();


				    int i75;//tree

    GLfloat x75=0.9f; GLfloat y75=0.06f; GLfloat radius75 =.04f;
	int triangleAmount75 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi75 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x75, y75); // center of circle
		for(i75 = 0; i75 <= triangleAmount75;i75++) {
			glVertex2f(
		            x75 + (radius75 * cos(i75 *  twicePi75 / triangleAmount75)),
			    y75 + (radius75 * sin(i75 * twicePi75 / triangleAmount75))
			);
		}
	glEnd();


	//2nd tree leaves

	int i76;//tree

    GLfloat x76=-0.85f; GLfloat y76=0.02f; GLfloat radius76 =.05f;
	int triangleAmount76 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi76 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x76, y76); // center of circle
		for(i76 = 0; i76 <= triangleAmount76;i76++) {
			glVertex2f(
		            x76 + (radius76 * cos(i76 *  twicePi76 / triangleAmount76)),
			    y76 + (radius76 * sin(i76 * twicePi76 / triangleAmount76))
			);
		}
	glEnd();

	    int i77;//tree

    GLfloat x77=-0.95f; GLfloat y77=0.02f; GLfloat radius77 =.05f;
	int triangleAmount77 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi77 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x77, y77); // center of circle
		for(i77 = 0; i77 <= triangleAmount77;i77++) {
			glVertex2f(
		            x77 + (radius77 * cos(i77 *  twicePi77 / triangleAmount77)),
			    y77 + (radius77 * sin(i77 * twicePi77 / triangleAmount77))
			);
		}
	glEnd();


		    int i80;//tree

    GLfloat x80=-0.86f; GLfloat y80=0.084f; GLfloat radius80 =.05f;
	int triangleAmount80 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi80 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x80, y80); // center of circle
		for(i80 = 0; i80 <= triangleAmount80;i80++) {
			glVertex2f(
		            x80 + (radius80 * cos(i80 *  twicePi80 / triangleAmount80)),
			    y80 + (radius80 * sin(i80 * twicePi80 / triangleAmount80))
			);
		}
	glEnd();

			    int i78;//tree

    GLfloat x78=-0.93f; GLfloat y78=0.084f; GLfloat radius78 =.05f;
	int triangleAmount78 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi78 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x78, y78); // center of circle
		for(i78 = 0; i78 <= triangleAmount78;i78++) {
			glVertex2f(
		            x78 + (radius78 * cos(i78 *  twicePi78 / triangleAmount78)),
			    y78 + (radius78 * sin(i78 * twicePi78 / triangleAmount78))
			);
		}
	glEnd();


				    int i79;//tree

    GLfloat x79=-0.9f; GLfloat y79=0.06f; GLfloat radius79 =.04f;
	int triangleAmount79 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi79 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x79, y79); // center of circle
		for(i79 = 0; i79 <= triangleAmount79;i79++) {
			glVertex2f(
		            x79 + (radius79 * cos(i79 *  twicePi79 / triangleAmount79)),
			    y79 + (radius79 * sin(i79 * twicePi79 / triangleAmount79))
			);
		}
	glEnd();

        //car starts


    glPushMatrix();
    glTranslatef(position2,0,0);
    {glTranslatef(0,-.08,0);

    glBegin(GL_QUADS);
    glColor3ub(66,135,245);
    glVertex2f(-.65,-.60);
    glVertex2f(-.65,-.68);
    glVertex2f(-.7,-.68);
    glVertex2f(-.7,-.62);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(66,135,245);
    glVertex2f(-.27,-.60);
    glVertex2f(-.27,-.68);
    glVertex2f(-.5,-.68);
    glVertex2f(-.5,-.60);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(66,135,245);
    glVertex2f(-.66,-.60);
    glVertex2f(-.66,-.68);
    glVertex2f(-.28,-.68);
    glVertex2f(-.28,-.62);
    glVertex2f(-.27,-.62);
    glVertex2f(-.28,-.60);
    glVertex2f(-.36,-.60);
    glVertex2f(-.40,-.54);
    glVertex2f(-.60,-.54);
    glVertex2f(-.62,-.62);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-.37,-.60);
    glVertex2f(-.40,-.55);
    glVertex2f(-.58,-.55);
    glVertex2f(-.62,-.60);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(-.40,-.55);
    glVertex2f(-.40,-.60);

    glVertex2f(-.58,-.55);
    glVertex2f(-.58,-.60);
    glEnd();
  //glLoadIdentity();
    }

    int i84;//car

    GLfloat x84=-0.58f; GLfloat y84=-0.68f; GLfloat radius84 =-.03f;
	int triangleAmount84 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi84 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);
		glVertex2f(x84, y84); // center of circle
		for(i84 = 0; i84 <= triangleAmount84;i84++) {
			glVertex2f(
		            x84 + (radius84 * cos(i84 *  twicePi84 / triangleAmount84)),
			    y84 + (radius84 * sin(i84 * twicePi84 / triangleAmount84))
			);
		}

		glEnd();


    int i85;//car

    GLfloat x85=-0.58f; GLfloat y85=-0.68f; GLfloat radius85 =.018f;
	int triangleAmount85 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi85 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(250, 250, 250);
		glVertex2f(x85, y85); // center of circle
		for(i85 = 0; i85 <= triangleAmount85;i85++) {
			glVertex2f(
		            x85 + (radius85 * cos(i85 *  twicePi85 / triangleAmount85)),
			    y85 + (radius85 * sin(i85 * twicePi85 / triangleAmount85))
			);
		}

		glEnd();


		int i86;//car

    GLfloat x86=-0.34f; GLfloat y86=-0.68f; GLfloat radius86 =.03f;
	int triangleAmount86 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi86 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);
		glVertex2f(x86, y86); // center of circle
		for(i86 = 0; i86 <= triangleAmount86;i86++) {
			glVertex2f(
		            x86 + (radius86 * cos(i86 *  twicePi86 / triangleAmount86)),
			    y86 + (radius86 * sin(i86 * twicePi86 / triangleAmount86))
			);
		}

		glEnd();


				int i87;//car

    GLfloat x87=-0.34f; GLfloat y87=-0.68f; GLfloat radius87 =.018f;
	int triangleAmount87 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi87 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(250, 250, 250);
		glVertex2f(x87, y87); // center of circle
		for(i87 = 0; i87 <= triangleAmount87;i87++) {
			glVertex2f(
		            x87 + (radius87 * cos(i87 *  twicePi87 / triangleAmount87)),
			    y87 + (radius87 * sin(i87 * twicePi87 / triangleAmount87))
			);
		}

		glEnd();
		//glLoadIdentity();
		glPopMatrix();

				//2nd car
    glPushMatrix();
    glTranslatef(position4,0.0f, 0.0f);
    glTranslatef(0,-.54,0);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(.04,-.24);
    glVertex2f(0.0,-.34);
    glVertex2f(0,-.42);
    glVertex2f(.4,-.42);
    glVertex2f(.4,-.24);
    glEnd();



    glBegin(GL_QUADS);
    glColor3ub(48,51,56);
    glVertex2f(.37,-.26);
    glVertex2f(.30,-.26);
    glVertex2f(.30,-.34);
    glVertex2f(.37,-.34);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(48,51,56);
    glVertex2f(.28,-.26);
    glVertex2f(.22,-.26);
    glVertex2f(.22,-.34);
    glVertex2f(.28,-.34);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(48,51,56);
    glVertex2f(.20,-.26);
    glVertex2f(.14,-.26);
    glVertex2f(.14,-.34);
    glVertex2f(.20,-.34);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(48,51,56);
    glVertex2f(.12,-.26);
    glVertex2f(.05,-.26);
    glVertex2f(.02,-.34);
    glVertex2f(.12,-.34);
    glEnd();

    glBegin(GL_QUADS);//red
    glColor3ub(224,41,25);
    glVertex2f(.22,-.38);
    glVertex2f(.22,-.40);
    glVertex2f(0.16,-.40);
    glVertex2f(0.16,-.38);
    glEnd();

    glBegin(GL_QUADS);//red
    glColor3ub(224,41,25);
    glVertex2f(.18,-.418);
    glVertex2f(.18,-.35);
    glVertex2f(0.2,-.35);
    glVertex2f(0.2,-.418);
    glEnd();
    //glLoadIdentity();

    int i96;//car2

    GLfloat x96=0.08f; GLfloat y96=-0.42f; GLfloat radius96 =.04f;
	int triangleAmount96 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi96 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x96, y96); // center of circle
		for(i96 = 0; i96 <= triangleAmount96;i96++) {
			glVertex2f(
		            x96 + (radius96 * cos(i96 *  twicePi96 / triangleAmount96)),
			    y96 + (radius96 * sin(i96 * twicePi96 / triangleAmount96))
			);
		}

		glEnd();

		    int i97;//car

    GLfloat x97=0.08f; GLfloat y97=-0.42f; GLfloat radius97 =.025f;
	int triangleAmount97 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi97 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 250, 250);
		glVertex2f(x97, y97); // center of circle
		for(i97 = 0; i97 <= triangleAmount97;i97++) {
			glVertex2f(
		            x97 + (radius97 * cos(i97 *  twicePi97 / triangleAmount97)),
			    y97 + (radius97 * sin(i97 * twicePi97 / triangleAmount97))
			);
		}

		glEnd();

		    int i98;//car

    GLfloat x98=0.3f; GLfloat y98=-0.42f; GLfloat radius98 =.04f;
	int triangleAmount98 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi98 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x98, y98); // center of circle
		for(i98 = 0; i98 <= triangleAmount98;i98++) {
			glVertex2f(
		            x98 + (radius98 * cos(i98 *  twicePi98 / triangleAmount98)),
			    y98 + (radius98 * sin(i98 * twicePi98 / triangleAmount98))
			);
		}

		glEnd();

    int i99;//car

    GLfloat x99=0.3f; GLfloat y99=-0.42f; GLfloat radius99 =.025f;
	int triangleAmount99 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi99 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 250, 250);
		glVertex2f(x99, y99); // center of circle
		for(i99 = 0; i99 <= triangleAmount99;i99++) {
			glVertex2f(
		            x99 + (radius99 * cos(i99 *  twicePi99 / triangleAmount99)),
			    y99 + (radius99 * sin(i99 * twicePi99 / triangleAmount99))
			);
		}

		glEnd();
		glLoadIdentity();
		glPopMatrix();


		//nightrainend


     glPushMatrix();
    glTranslatef(0.0f,position3, 0.0f);

    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);


    glVertex2f(0.12f,0.94f);
    glVertex2f(.14f,0.98f);


    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);



    glVertex2f(0.30f,0.96f);
    glVertex2f(.32f,1.0f);

    glVertex2f(0.33f,0.94f);
    glVertex2f(.35f,0.98f);


    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);

    glVertex2f(0.51f,0.94f);
    glVertex2f(.53f,0.98f);

    glVertex2f(0.54f,0.96f);
    glVertex2f(.56f,1.0f);


    glVertex2f(0.57f,0.94f);
    glVertex2f(.59f,0.98f);

    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);



    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.94f);
    glVertex2f(.77f,0.98f);

    glVertex2f(0.78f,0.96f);
    glVertex2f(.8f,1.0f);

    //ekhan
    glVertex2f(0.81f,0.96f);
    glVertex2f(.83f,1.0f);

    glVertex2f(0.84f,0.96f);
    glVertex2f(.86f,1.0f);

    glVertex2f(0.87f,0.96f);
    glVertex2f(.89f,1.0f);

    glVertex2f(0.9f,0.96f);
    glVertex2f(.92f,1.0f);


    glVertex2f(0.96f,0.96f);
    glVertex2f(.98f,1.0f);

    glVertex2f(0.99f,0.96f);
    glVertex2f(1.0f,1.0f);

    //ek
/*glVertex2f(0.81f,0.94f);
    glVertex2f(.83f,0.98f);

    glVertex2f(0.84f,0.94f);
    glVertex2f(.86f,0.98f);

    glVertex2f(0.87f,0.94f);
    glVertex2f(.89f,0.98f);

    glVertex2f(0.9f,0.96f);
    glVertex2f(.92f,0.98f);


    glVertex2f(0.96f,0.9f);
    glVertex2f(.98f,0.92f);

    glVertex2f(0.99f,0.9f);
    glVertex2f(1.0f,0.92f);
    */


    //---

    glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);


    glVertex2f(-0.12f,0.98f);
    glVertex2f(-.14f,0.94f);

    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);

    glVertex2f(-0.21f,1.0f);
    glVertex2f(-.23f,.96f);

   glVertex2f(-0.24f,0.98f);
    glVertex2f(-.26f,0.94f);

    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);

    glVertex2f(-0.45f,1.0f);
    glVertex2f(-.47f,0.96f);

    glVertex2f(-0.48f,0.98f);
    glVertex2f(-.50f,.94f);


    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);

    glVertex2f(-0.69f,1.0f);
    glVertex2f(-.71f,0.96f);

    glVertex2f(-0.72f,0.98f);
    glVertex2f(-.74f,.94f);

    glVertex2f(-0.75f,0.98f);
    glVertex2f(-.77f,.94f);

    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glVertex2f(-0.81f,0.98f);
    glVertex2f(-.83f,.94f);


    glVertex2f(-0.87f,0.98f);
    glVertex2f(-.89f,.94f);

    glVertex2f(-0.93f,0.98f);
    glVertex2f(-.95f,.94f);

    glVertex2f(-0.96f,0.98f);
    glVertex2f(-.98f,.94f);

    glVertex2f(-0.99f,0.98f);
    glVertex2f(-1.0f,.94f);



    glEnd();
    glLoadIdentity();
    glPopMatrix();





    //1


    glPushMatrix();
    glTranslatef(0.0f,position3, 0.0f);
    glTranslatef(0.02,-.075,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);

    glVertex2f(0.06f,0.94f);
    glVertex2f(.08f,0.98f);

    glVertex2f(0.09f,0.96f);
    glVertex2f(.11f,1.0f);


    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);


    glVertex2f(0.30f,0.96f);
    glVertex2f(.32f,1.0f);

    glVertex2f(0.33f,0.94f);
    glVertex2f(.35f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);

    glVertex2f(0.51f,0.94f);
    glVertex2f(.53f,0.98f);

    glVertex2f(0.54f,0.96f);
    glVertex2f(.56f,1.0f);


    glVertex2f(0.57f,0.94f);
    glVertex2f(.59f,0.98f);

    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);


    glVertex2f(0.78f,0.96f);
    glVertex2f(.8f,1.0f);

    glVertex2f(0.81f,0.96f);
    glVertex2f(.83f,1.0f);


    glVertex2f(0.9f,0.96f);
    glVertex2f(.92f,1.0f);

    glVertex2f(0.93f,0.96f);
    glVertex2f(.95f,1.0f);

    glVertex2f(0.96f,0.96f);
    glVertex2f(.98f,1.0f);

    glVertex2f(1.0f,0.96f);
    glVertex2f(.99f,1.0f);

    //----

    glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);



    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);

    glVertex2f(-0.21f,1.0f);
    glVertex2f(-.23f,.96f);

   glVertex2f(-0.24f,0.98f);
    glVertex2f(-.26f,0.94f);

    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);



    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);

    glVertex2f(-0.45f,1.0f);
    glVertex2f(-.47f,0.96f);

    glVertex2f(-0.48f,0.98f);
    glVertex2f(-.50f,.94f);

    glVertex2f(-0.51f,1.0f);
    glVertex2f(-.53f,0.96f);

    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);



    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);

    glVertex2f(-0.69f,1.0f);
    glVertex2f(-.71f,0.96f);

    glVertex2f(-0.72f,0.98f);
    glVertex2f(-.74f,.94f);

    glVertex2f(-0.75f,1.0f);
    glVertex2f(-.77f,0.96f);

    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);


    glVertex2f(-0.81f,0.98f);
    glVertex2f(-.83f,.94f);

    glVertex2f(-0.84f,0.98f);
    glVertex2f(-.86f,.94f);


    glVertex2f(-0.93f,0.98f);
    glVertex2f(-.95f,.94f);

    glVertex2f(-0.96f,0.98f);
    glVertex2f(-.98f,.94f);

    glVertex2f(-0.99f,0.98f);
    glVertex2f(-1.01f,.94f);


    glEnd();
    glLoadIdentity();
    glPopMatrix();




//4


    glPushMatrix();
    glTranslatef(0.0f,position3, 0.0f);
    glTranslatef(0,.16,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);


    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);




    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);



    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.96f);
    glVertex2f(.77f,1.0f);

    glVertex2f(0.78f,0.94f);
    glVertex2f(.8f,0.98f);

    glVertex2f(0.81f,0.96f);
    glVertex2f(.83f,1.0f);

    glVertex2f(0.84f,0.94f);
    glVertex2f(.86f,0.98f);

    glVertex2f(0.87f,0.96f);
    glVertex2f(.89f,1.0f);

    glVertex2f(0.9f,0.94f);
    glVertex2f(.92f,0.98f);

    glVertex2f(0.93f,0.96f);
    glVertex2f(.95f,1.0f);

    glVertex2f(0.96f,0.96f);
    glVertex2f(.98f,1.0f);

    glVertex2f(0.99f,0.96f);
    glVertex2f(1.01f,1.0f);



    //---

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);



    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);


    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);


    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);



    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glVertex2f(-0.81f,1.0f);
    glVertex2f(-.83f,.96f);

    glVertex2f(-0.84f,0.98f);
    glVertex2f(-.86f,.94f);

    glVertex2f(-0.87f,1.0f);
    glVertex2f(-.89f,.96f);

    glVertex2f(-0.9f,0.98f);
    glVertex2f(-.92f,.94f);

    glVertex2f(-0.93f,1.0f);
    glVertex2f(-.95f,.96f);

    glVertex2f(-0.96f,0.98f);
    glVertex2f(-.98f,.94f);

    glVertex2f(-0.99f,1.0f);
    glVertex2f(-1.01f,.96f);


    glEnd();
    glLoadIdentity();
    glPopMatrix();







    //8


    glPushMatrix();
    glTranslatef(0.0f,position3, 0.0f);
    glTranslatef(0.02,.38,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
        glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);


    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);




    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);



    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.96f);
    glVertex2f(.77f,1.0f);

    glVertex2f(0.78f,0.94f);
    glVertex2f(.8f,0.98f);

    glVertex2f(0.81f,0.96f);
    glVertex2f(.83f,1.0f);

    glVertex2f(0.84f,0.94f);
    glVertex2f(.86f,0.98f);

    glVertex2f(0.87f,0.96f);
    glVertex2f(.89f,1.0f);

    glVertex2f(0.9f,0.94f);
    glVertex2f(.92f,0.98f);

    glVertex2f(0.93f,0.96f);
    glVertex2f(.95f,1.0f);

    glVertex2f(0.96f,0.96f);
    glVertex2f(.98f,1.0f);

    glVertex2f(0.99f,0.96f);
    glVertex2f(1.01f,1.0f);



    //---

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);



    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);


    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);


    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);



    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glVertex2f(-0.81f,1.0f);
    glVertex2f(-.83f,.96f);

    glVertex2f(-0.84f,0.98f);
    glVertex2f(-.86f,.94f);

    glVertex2f(-0.87f,1.0f);
    glVertex2f(-.89f,.96f);

    glVertex2f(-0.9f,0.98f);
    glVertex2f(-.92f,.94f);

    glVertex2f(-0.93f,1.0f);
    glVertex2f(-.95f,.96f);

    glVertex2f(-0.96f,0.98f);
    glVertex2f(-.98f,.94f);

    glVertex2f(-0.99f,1.0f);
    glVertex2f(-1.01f,.96f);


    glEnd();
    glLoadIdentity();
    glPopMatrix();




    //12


    glPushMatrix();
    glTranslatef(0.0f,position3, 0.0f);
    glTranslatef(0.04,-.4,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);


    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);




    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);



    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.96f);
    glVertex2f(.77f,1.0f);

    glVertex2f(0.78f,0.94f);
    glVertex2f(.8f,0.98f);

    glVertex2f(0.81f,0.96f);
    glVertex2f(.83f,1.0f);

    glVertex2f(0.84f,0.94f);
    glVertex2f(.86f,0.98f);

    glVertex2f(0.87f,0.96f);
    glVertex2f(.89f,1.0f);

    glVertex2f(0.9f,0.94f);
    glVertex2f(.92f,0.98f);

    glVertex2f(0.93f,0.96f);
    glVertex2f(.95f,1.0f);

    glVertex2f(0.96f,0.96f);
    glVertex2f(.98f,1.0f);

    glVertex2f(0.99f,0.96f);
    glVertex2f(1.01f,1.0f);



    //---

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);



    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);


    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);


    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);



    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glVertex2f(-0.81f,1.0f);
    glVertex2f(-.83f,.96f);

    glVertex2f(-0.84f,0.98f);
    glVertex2f(-.86f,.94f);

    glVertex2f(-0.87f,1.0f);
    glVertex2f(-.89f,.96f);

    glVertex2f(-0.9f,0.98f);
    glVertex2f(-.92f,.94f);

    glVertex2f(-0.93f,1.0f);
    glVertex2f(-.95f,.96f);

    glVertex2f(-0.96f,0.98f);
    glVertex2f(-.98f,.94f);

    glVertex2f(-0.99f,1.0f);
    glVertex2f(-1.01f,.96f);


    glEnd();
    glLoadIdentity();
    glPopMatrix();




    //15


    glPushMatrix();
    glTranslatef(0.0f,position3, 0.0f);
    glTranslatef(0.04,-.67,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
        glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);


    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);




    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);



    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.96f);
    glVertex2f(.77f,1.0f);

    glVertex2f(0.78f,0.94f);
    glVertex2f(.8f,0.98f);

    glVertex2f(0.81f,0.96f);
    glVertex2f(.83f,1.0f);

    glVertex2f(0.84f,0.94f);
    glVertex2f(.86f,0.98f);

    glVertex2f(0.87f,0.96f);
    glVertex2f(.89f,1.0f);

    glVertex2f(0.9f,0.94f);
    glVertex2f(.92f,0.98f);

    glVertex2f(0.93f,0.96f);
    glVertex2f(.95f,1.0f);

    glVertex2f(0.96f,0.96f);
    glVertex2f(.98f,1.0f);

    glVertex2f(0.99f,0.96f);
    glVertex2f(1.01f,1.0f);



    //---

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);



    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);


    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);


    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);



    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glVertex2f(-0.81f,1.0f);
    glVertex2f(-.83f,.96f);

    glVertex2f(-0.84f,0.98f);
    glVertex2f(-.86f,.94f);

    glVertex2f(-0.87f,1.0f);
    glVertex2f(-.89f,.96f);

    glVertex2f(-0.9f,0.98f);
    glVertex2f(-.92f,.94f);

    glVertex2f(-0.93f,1.0f);
    glVertex2f(-.95f,.96f);

    glVertex2f(-0.96f,0.98f);
    glVertex2f(-.98f,.94f);

    glVertex2f(-0.99f,1.0f);
    glVertex2f(-1.01f,.96f);



    glEnd();
    glLoadIdentity();
    glPopMatrix();





    //17


    glPushMatrix();
    glTranslatef(0.0f,position3, 0.0f);
    glTranslatef(0.02,-.85,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);


    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);




    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);



    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.96f);
    glVertex2f(.77f,1.0f);

    glVertex2f(0.78f,0.94f);
    glVertex2f(.8f,0.98f);

    glVertex2f(0.81f,0.96f);
    glVertex2f(.83f,1.0f);

    glVertex2f(0.84f,0.94f);
    glVertex2f(.86f,0.98f);

    glVertex2f(0.87f,0.96f);
    glVertex2f(.89f,1.0f);

    glVertex2f(0.9f,0.94f);
    glVertex2f(.92f,0.98f);

    glVertex2f(0.93f,0.96f);
    glVertex2f(.95f,1.0f);

    glVertex2f(0.96f,0.96f);
    glVertex2f(.98f,1.0f);

    glVertex2f(0.99f,0.96f);
    glVertex2f(1.01f,1.0f);



    //---

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);



    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);


    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);


    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);



    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glVertex2f(-0.81f,1.0f);
    glVertex2f(-.83f,.96f);

    glVertex2f(-0.84f,0.98f);
    glVertex2f(-.86f,.94f);

    glVertex2f(-0.87f,1.0f);
    glVertex2f(-.89f,.96f);

    glVertex2f(-0.9f,0.98f);
    glVertex2f(-.92f,.94f);

    glVertex2f(-0.93f,1.0f);
    glVertex2f(-.95f,.96f);

    glVertex2f(-0.96f,0.98f);
    glVertex2f(-.98f,.94f);

    glVertex2f(-0.99f,1.0f);
    glVertex2f(-1.01f,.96f);

    glEnd();
    glLoadIdentity();
    glPopMatrix();



glPushMatrix();
    glTranslatef(0.0f,position3, 0.0f);
    glTranslatef(0.02,.54,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);


    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);




    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);



    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.96f);
    glVertex2f(.77f,1.0f);

    glVertex2f(0.78f,0.94f);
    glVertex2f(.8f,0.98f);

    glVertex2f(0.81f,0.96f);
    glVertex2f(.83f,1.0f);

    glVertex2f(0.84f,0.94f);
    glVertex2f(.86f,0.98f);

    glVertex2f(0.87f,0.96f);
    glVertex2f(.89f,1.0f);

    glVertex2f(0.9f,0.94f);
    glVertex2f(.92f,0.98f);

    glVertex2f(0.93f,0.96f);
    glVertex2f(.95f,1.0f);

    glVertex2f(0.96f,0.96f);
    glVertex2f(.98f,1.0f);

    glVertex2f(0.99f,0.96f);
    glVertex2f(1.01f,1.0f);



    //---

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);



    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);


    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);


    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);



    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glVertex2f(-0.81f,1.0f);
    glVertex2f(-.83f,.96f);

    glVertex2f(-0.84f,0.98f);
    glVertex2f(-.86f,.94f);

    glVertex2f(-0.87f,1.0f);
    glVertex2f(-.89f,.96f);

    glVertex2f(-0.9f,0.98f);
    glVertex2f(-.92f,.94f);

    glVertex2f(-0.93f,1.0f);
    glVertex2f(-.95f,.96f);

    glVertex2f(-0.96f,0.98f);
    glVertex2f(-.98f,.94f);

    glVertex2f(-0.99f,1.0f);
    glVertex2f(-1.01f,.96f);



    glEnd();
    glLoadIdentity();
    glPopMatrix();


    //21


    glPushMatrix();
    glTranslatef(0.0f,position3, 0.0f);
    glTranslatef(0.04,.63,0);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f,0.94f);
    glVertex2f(.02f,0.98f);

    glVertex2f(0.03f,0.96f);
    glVertex2f(.05f,1.0f);


    glVertex2f(0.15f,0.96f);
    glVertex2f(.17f,1.0f);

    glVertex2f(0.18f,0.94f);
    glVertex2f(.20f,0.98f);

    glVertex2f(0.21f,0.96f);
    glVertex2f(.23f,1.0f);

    glVertex2f(0.24f,0.94f);
    glVertex2f(.26f,0.98f);

    glVertex2f(0.27f,0.96f);
    glVertex2f(.29f,1.0f);




    glVertex2f(0.39f,0.94f);
    glVertex2f(.41f,0.98f);

    glVertex2f(0.42f,0.96f);
    glVertex2f(.44f,1.0f);

    glVertex2f(0.45f,0.94f);
    glVertex2f(.47f,0.98f);

    glVertex2f(0.48f,0.96f);
    glVertex2f(.50f,1.0f);



    glVertex2f(0.6f,0.96f);
    glVertex2f(.62f,1.0f);

    glVertex2f(0.63f,0.94f);
    glVertex2f(.65f,0.98f);

    glVertex2f(0.66f,0.96f);
    glVertex2f(.68f,1.0f);

    glVertex2f(0.69f,0.94f);
    glVertex2f(.71f,0.98f);

    glVertex2f(0.72f,0.96f);
    glVertex2f(.74f,1.0f);

    glVertex2f(0.75f,0.96f);
    glVertex2f(.77f,1.0f);

    glVertex2f(0.78f,0.94f);
    glVertex2f(.8f,0.98f);

    glVertex2f(0.81f,0.96f);
    glVertex2f(.83f,1.0f);

    glVertex2f(0.84f,0.94f);
    glVertex2f(.86f,0.98f);

    glVertex2f(0.87f,0.96f);
    glVertex2f(.89f,1.0f);

    glVertex2f(0.9f,0.94f);
    glVertex2f(.92f,0.98f);

    glVertex2f(0.93f,0.96f);
    glVertex2f(.95f,1.0f);

    glVertex2f(0.96f,0.96f);
    glVertex2f(.98f,1.0f);

    glVertex2f(0.99f,0.96f);
    glVertex2f(1.01f,1.0f);



    //---

     glVertex2f(-.01f,0.98f);
    glVertex2f(-.03f,0.94f);

    glVertex2f(-0.03f,1.0f);
    glVertex2f(-.05f,.96f);



    glVertex2f(-0.15f,1.0f);
    glVertex2f(-.17f,.96f);

    glVertex2f(-0.18f,0.98f);
    glVertex2f(-.20f,0.94f);


    glVertex2f(-0.27f,1.0f);
    glVertex2f(-.29f,.96f);


    glVertex2f(-0.30f,0.98f);
    glVertex2f(-.32f,0.94f);

    glVertex2f(-0.33f,1.0f);
    glVertex2f(-.35f,0.96f);

    glVertex2f(-0.36f,0.98f);
    glVertex2f(-.38f,.94f);

    glVertex2f(-0.39f,1.0f);
    glVertex2f(-.41f,0.96f);

    glVertex2f(-0.42f,0.98f);
    glVertex2f(-.44f,.94f);


    glVertex2f(-0.54f,0.98f);
    glVertex2f(-.56f,.94f);


    glVertex2f(-0.57f,1.0f);
    glVertex2f(-.59f,0.96f);

    glVertex2f(-0.6f,0.98f);
    glVertex2f(-.62f,.94f);

    glVertex2f(-0.63f,1.0f);
    glVertex2f(-.65f,0.96f);

    glVertex2f(-0.66f,0.98f);
    glVertex2f(-.68f,.94f);



    glVertex2f(-0.78f,0.98f);
    glVertex2f(-.8f,.94f);

    glVertex2f(-0.81f,1.0f);
    glVertex2f(-.83f,.96f);

    glVertex2f(-0.84f,0.98f);
    glVertex2f(-.86f,.94f);

    glVertex2f(-0.87f,1.0f);
    glVertex2f(-.89f,.96f);

    glVertex2f(-0.9f,0.98f);
    glVertex2f(-.92f,.94f);

    glVertex2f(-0.93f,1.0f);
    glVertex2f(-.95f,.96f);

    glVertex2f(-0.96f,0.98f);
    glVertex2f(-.98f,.94f);

    glVertex2f(-0.99f,1.0f);
    glVertex2f(-1.01f,.96f);



    glEnd();
    glLoadIdentity();
    glPopMatrix();

    //flower start
    glPushMatrix();
    glTranslatef(.5,0,0);
    glScalef(.8,.8,0);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();
    //glLoadIdentity();
    //glPopMatrix();

        int i100;//flower

    GLfloat x100=0.003f; GLfloat y100=-0.36f; GLfloat radius100 =.025f;
	int triangleAmount100 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi100 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 40, 60);
		glVertex2f(x100, y100); // center of circle
		for(i100 = 0; i100 <= triangleAmount100;i100++) {
			glVertex2f(
		            x100 + (radius100 * cos(i100 *  twicePi100 / triangleAmount100)),
			    y100 + (radius100 * sin(i100 * twicePi100 / triangleAmount100))
			);
		}

		glEnd();
		glLoadIdentity();
		glPopMatrix();


		    glPushMatrix();
    glTranslatef(-.5,0,0);
    glScalef(.8,.8,0);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();
    //glLoadIdentity();
    //glPopMatrix();

        int i101;//flower

    GLfloat x101=0.003f; GLfloat y101=-0.36f; GLfloat radius101 =.025f;
	int triangleAmount101 = 101; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi101 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 40, 60);
		glVertex2f(x101, y101); // center of circle
		for(i101 = 0; i101 <= triangleAmount101;i101++) {
			glVertex2f(
		            x101 + (radius101 * cos(i101 *  twicePi101 / triangleAmount101)),
			    y101 + (radius101 * sin(i101 * twicePi101 / triangleAmount101))
			);
		}

		glEnd();
		glLoadIdentity();
		glPopMatrix();





   //glutTimerFunc(8000,displayBack,0);

	glFlush();
}
//dayday
void day() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)


   glBegin(GL_QUADS);// sky
	glColor3ub(135,206,250);

	glVertex2f(1.0f, -0.1f);
	glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f,1.0f);
    glVertex2f(-1.0,-0.1f);
    glEnd();

	int i;//sun

	GLfloat x=-.4f; GLfloat y=.8f; GLfloat radius =.07f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(249,215,28);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glPushMatrix();
    glTranslatef(position,0,0);
	int i1;// cloud

	GLfloat x1=0.4f; GLfloat y1=0.88f; GLfloat radius1 =.07f;
	int triangleAmount1 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(192,192,192);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)),
			    y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1))
			);
		}
	glEnd();

	int i2;// cloud

	GLfloat x2=0.5f; GLfloat y2=0.84f; GLfloat radius2 =.06f;
	int triangleAmount2 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(192,192,192);
		glVertex2f(x2, y2); // center of circle
		for(i2 = 0; i2 <= triangleAmount2;i2++) {
			glVertex2f(
		            x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
			);
		}
	glEnd();

		int i3;// cloud

	GLfloat x3=0.6f; GLfloat y3=0.82f; GLfloat radius3 =.06f;
	int triangleAmount3 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi3 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(192,192,192);
		glVertex2f(x3, y3); // center of circle
		for(i3 = 0; i3 <= triangleAmount3;i3++) {
			glVertex2f(
		            x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
			    y3 + (radius3 * sin(i3 * twicePi3/ triangleAmount3))
			);
		}
	glEnd();

	    int i4;//cloud

	GLfloat x4=0.3f; GLfloat y4=0.75f; GLfloat radius4 =.07f;
	int triangleAmount4 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi4 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x4, y4); // center of circle
		for(i4 = 0; i4 <= triangleAmount4;i4++) {
			glVertex2f(
		            x4 + (radius4 * cos(i4 *  twicePi4 / triangleAmount4)),
			    y4 + (radius4 * sin(i4 * twicePi4 / triangleAmount4))
			);
		}
	glEnd();

	int i5;// cloud

	GLfloat x5=0.4f; GLfloat y5=0.75f; GLfloat radius5 =.07f;
	int triangleAmount5 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi5 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x5, y5); // center of circle
		for(i5 = 0; i5 <= triangleAmount5;i5++) {
			glVertex2f(
		            x5 + (radius5 * cos(i5 *  twicePi5 / triangleAmount5)),
			    y5 + (radius5 * sin(i5 * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

		int i6;// cloud

	GLfloat x6=0.45f; GLfloat y6=0.78f; GLfloat radius6 =.06f;
	int triangleAmount6 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi6 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x6, y6); // center of circle
		for(i6 = 0; i6 <= triangleAmount6;i6++) {
			glVertex2f(
		            x6 + (radius6 * cos(i6 *  twicePi6 / triangleAmount6)),
			    y6 + (radius6 * sin(i6 * twicePi6 / triangleAmount6))
			);
		}
	glEnd();

	int i7;// cloud

	GLfloat x7=0.35f; GLfloat y7=0.81f; GLfloat radius7 =.06f;
	int triangleAmount7 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi7 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x7, y7); // center of circle
		for(i7 = 0; i7 <= triangleAmount7;i7++) {
			glVertex2f(
		            x7 + (radius7 * cos(i7 *  twicePi7 / triangleAmount7)),
			    y7 + (radius7 * sin(i7 * twicePi7 / triangleAmount7))
			);
		}
	glEnd();

		int i8;// cloud

	GLfloat x8=0.55f; GLfloat y8=0.75f; GLfloat radius8 =.07f;
	int triangleAmount8 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi8 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x8, y8); // center of circle
		for(i8 = 0; i8 <= triangleAmount8;i8++) {
			glVertex2f(
		            x8 + (radius8 * cos(i8 *  twicePi8 / triangleAmount8)),
			    y8 + (radius8 * sin(i8 * twicePi8 / triangleAmount8))
			);
		}
	glEnd();

	glTranslatef(-0.8,0,0);
	int i88;// cloud

	GLfloat x88=0.4f; GLfloat y88=0.88f; GLfloat radius88 =.07f;
	int triangleAmount88 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi88 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(192,192,192);
		glVertex2f(x88, y88); // center of circle
		for(i88 = 0; i88 <= triangleAmount;i88++) {
			glVertex2f(
		            x88 + (radius88 * cos(i88 *  twicePi88 / triangleAmount88)),
			    y88 + (radius88 * sin(i88 * twicePi88 / triangleAmount88))
			);
		}
	glEnd();

	int i89;// cloud

	GLfloat x89=0.5f; GLfloat y89=0.84f; GLfloat radius89 =.06f;
	int triangleAmount89 = 890; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi89 = 89.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(192,192,192);
		glVertex2f(x89, y89); // center of circle
		for(i89 = 0; i89 <= triangleAmount89;i89++) {
			glVertex2f(
		            x89 + (radius89 * cos(i89 *  twicePi89 / triangleAmount89)),
			    y89 + (radius89 * sin(i89 * twicePi89 / triangleAmount89))
			);
		}
	glEnd();

		int i90;// cloud

	GLfloat x90=0.6f; GLfloat y90=0.82f; GLfloat radius90 =.06f;
	int triangleAmount90 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi90 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(192,192,192);
		glVertex2f(x90, y90); // center of circle
		for(i90 = 0; i90 <= triangleAmount90;i90++) {
			glVertex2f(
		            x90 + (radius90 * cos(i90 *  twicePi90 / triangleAmount90)),
			    y90 + (radius90 * sin(i90 * twicePi90/ triangleAmount90))
			);
		}
	glEnd();

	    int i91;//cloud

	GLfloat x91=0.3f; GLfloat y91=0.75f; GLfloat radius91 =.07f;
	int triangleAmount91 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi91 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x91, y91); // center of circle
		for(i91 = 0; i91 <= triangleAmount91;i91++) {
			glVertex2f(
		            x91 + (radius91 * cos(i91 *  twicePi91 / triangleAmount91)),
			    y91 + (radius91 * sin(i91 * twicePi91 / triangleAmount91))
			);
		}
	glEnd();

	int i92;// cloud

	GLfloat x92=0.4f; GLfloat y92=0.75f; GLfloat radius92 =.07f;
	int triangleAmount92 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi92 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x92, y92); // center of circle
		for(i92 = 0; i92 <= triangleAmount92;i92++) {
			glVertex2f(
		            x92 + (radius92 * cos(i92 *  twicePi92 / triangleAmount92)),
			    y92 + (radius92 * sin(i92 * twicePi92 / triangleAmount92))
			);
		}
	glEnd();

		int i93;// cloud

	GLfloat x93=0.45f; GLfloat y93=0.78f; GLfloat radius93 =.06f;
	int triangleAmount93 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi93 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x93, y93); // center of circle
		for(i93 = 0; i93 <= triangleAmount93;i93++) {
			glVertex2f(
		            x93 + (radius93 * cos(i93 *  twicePi93 / triangleAmount93)),
			    y93 + (radius93 * sin(i93 * twicePi93 / triangleAmount93))
			);
		}
	glEnd();

	int i94;// cloud

	GLfloat x94=0.35f; GLfloat y94=0.81f; GLfloat radius94 =.06f;
	int triangleAmount94 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi94 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x94, y94); // center of circle
		for(i94 = 0; i94 <= triangleAmount94;i94++) {
			glVertex2f(
		            x94 + (radius94 * cos(i94 *  twicePi94 / triangleAmount94)),
			    y94 + (radius94 * sin(i94 * twicePi94 / triangleAmount94))
			);
		}
	glEnd();

		int i95;// cloud

	GLfloat x95=0.55f; GLfloat y95=0.75f; GLfloat radius95 =.07f;
	int triangleAmount95 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.95f; //radius
	GLfloat twicePi95 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x95, y95); // center of circle
		for(i95 = 0; i95 <= triangleAmount95;i95++) {
			glVertex2f(
		            x95 + (radius95 * cos(i95 *  twicePi95 / triangleAmount95)),
			    y95 + (radius95 * sin(i95 * twicePi95 / triangleAmount95))
			);
		}
	glEnd();



	glPopMatrix();
	//glLoadIdentity();naimul


    glBegin(GL_QUADS);//floor
	glColor3ub(145,117,103);

	glVertex2f(1.0f, -0.1f);
	glVertex2f(1.0f, -0.26f);
    glVertex2f(-1.0f,-0.26f);
    glVertex2f(-1.0,-0.1f);
    glEnd();

    glBegin(GL_QUADS);//floor small
	glColor3ub(97,19,14);

	glVertex2f(0.76f, -0.24f);
	glVertex2f(0.76f, -0.2f);
    glVertex2f(-.76f,-0.2f);
    glVertex2f(-0.76,-0.24f);
    glEnd();

    glBegin(GL_QUADS);//field
	glColor3ub(0,100,0);

	glVertex2f(1.0f, -0.6f);
	glVertex2f(1.0f, -0.26f);
    glVertex2f(-1.0f,-0.26f);
    glVertex2f(-1.0,-0.6f);
    glEnd();


	glBegin(GL_QUADS);//body
	glColor3ub(255,99,71);

	glVertex2f(0.76f, -0.2f);
	glVertex2f(0.76f, 0.24f);
    glVertex2f(-.76f,0.24f);
    glVertex2f(-0.76,-0.2f);
    glEnd();




    glBegin(GL_QUADS);//middle line 1
	glColor3ub(1,1,1);

	glVertex2f(0.76f, -0.04f);
	glVertex2f(0.76f, -0.03f);
    glVertex2f(-0.76f, -0.03f);
    glVertex2f(-0.76,-0.04f);
    glEnd();

    glBegin(GL_LINES);// middle line 2
	glColor3ub(1,1,1);

	glVertex2f(0.76f, -0.02f);
	glVertex2f(-0.76f, -0.02f);

    glEnd();

    glBegin(GL_LINES);//line right side
	glColor3ub(1,1,1);

	glVertex2f(0.18f, -0.04f);
    glVertex2f(0.18f,-0.2f);

	glVertex2f(0.20f, -0.04f);
    glVertex2f(0.20f,-0.2f);

    glVertex2f(0.271f, -0.04f);
    glVertex2f(0.271f,-0.2f);

    glVertex2f(0.291f, -0.04f);
    glVertex2f(0.291f,-0.2f);

    glVertex2f(0.362f, -0.04f);
    glVertex2f(0.362f,-0.2f);

    glVertex2f(0.382f, -0.04f);
    glVertex2f(0.382f,-0.2f);

    glVertex2f(0.453f, -0.04f);
    glVertex2f(0.453f,-0.2f);

    glVertex2f(0.473f, -0.04f);
    glVertex2f(0.473f,-0.2f);

    glVertex2f(0.544f, -0.04f);
    glVertex2f(0.544f,-0.2f);

    glVertex2f(0.58f, -0.04f);
    glVertex2f(0.58f,-0.2f);

    //dark pillar right
    glVertex2f(0.546f, -0.04f);
    glVertex2f(0.546f,-0.2f);

    glVertex2f(0.549f, -0.04f);
    glVertex2f(0.549f,-0.2f);

    glVertex2f(0.575f, -0.04f);
    glVertex2f(0.575f,-0.2f);

    glVertex2f(0.578f, -0.04f);
    glVertex2f(0.578f,-0.2f);

    //end



    glVertex2f(0.64f, -0.04f);
    glVertex2f(0.64f,-0.2f);

    glVertex2f(0.66f, -0.04f);
    glVertex2f(0.66f,-0.2f);

    glVertex2f(0.72f, -0.04f);
    glVertex2f(0.72f,-0.2f);
    glEnd();

    glBegin(GL_LINES);//dark pillar

    glVertex2f(0.722f, -0.04f);
    glVertex2f(0.722f,-0.2f);

    glVertex2f(0.724f, -0.04f);
    glVertex2f(0.724f,-0.2f);

    glVertex2f(0.726f, -0.04f);
    glVertex2f(0.726f,-0.2f);

    glVertex2f(0.756f, -0.04f);
    glVertex2f(0.756f,-0.2f);

    glVertex2f(0.758f, -0.04f);
    glVertex2f(0.758f,-0.2f);

    glVertex2f(0.76f, -0.04f);
    glVertex2f(0.76f,-0.2f);
    glEnd();


    //line left side
    glBegin(GL_LINES);
	glColor3ub(1,1,1);

	glVertex2f(-0.18f, -0.04f);//13
    glVertex2f(-0.18f,-0.2f);

	glVertex2f(-0.20f, -0.04f);//12
    glVertex2f(-0.20f,-0.2f);

    glVertex2f(-0.271f, -0.04f);//11
    glVertex2f(-0.271f,-0.2f);

    glVertex2f(-0.291f, -0.04f);//10
    glVertex2f(-0.291f,-0.2f);

    glVertex2f(-0.362f, -0.04f);//9
    glVertex2f(-0.362f,-0.2f);

    glVertex2f(-0.382f, -0.04f);//8
    glVertex2f(-0.382f,-0.2f);

    glVertex2f(-0.453f, -0.04f);//7
    glVertex2f(-0.453f,-0.2f);

    glVertex2f(-0.473f, -0.04f);//6
    glVertex2f(-0.473f,-0.2f);

    glVertex2f(-0.544f, -0.04f);//5
    glVertex2f(-0.544f,-0.2f);

    glVertex2f(-0.58f, -0.04f);//4
    glVertex2f(-0.58f,-0.2f);



    glVertex2f(-0.64f, -0.04f);//3
    glVertex2f(-0.64f,-0.2f);

    glVertex2f(-0.66f, -0.04f);//2
    glVertex2f(-0.66f,-0.2f);

    glVertex2f(-0.72f, -0.04f);//1
    glVertex2f(-0.72f,-0.2f);


    glEnd();

    glBegin(GL_LINES);//dark pillar
    glColor3ub(1,1,1);
    glVertex2f(-0.724f, -0.04f);
    glVertex2f(-0.724f,-0.2f);

    glVertex2f(-0.726f, -0.04f);
    glVertex2f(-0.726f,-0.2f);

    glVertex2f(-0.728f, -0.04f);
    glVertex2f(-0.728f,-0.2f);

    glVertex2f(-0.756f, -0.04f);
    glVertex2f(-0.756f,-0.2f);


    glVertex2f(-0.76f, -0.04f);
    glVertex2f(-0.76f,-0.2f);

    //end
    glEnd();

    //last roof middle
    glBegin(GL_QUADS);
    glColor3ub(255,99,71);
    glVertex2f(0.549f, 0.24f);
    glVertex2f(0.549f,0.28f);

    glVertex2f(-0.549f,0.28f);
    glVertex2f(-0.549f, 0.24f);


    //end
    glEnd();






   //last roof right
    glBegin(GL_QUADS);
    glColor3ub(255,99,71);
    glVertex2f(0.74f, 0.24f);
    glVertex2f(0.74f,0.3f);

    glVertex2f(0.567f,0.3f);
    glVertex2f(0.567f, 0.24f);


    //end
    glEnd();

    //last roof left
    glBegin(GL_QUADS);
    glColor3ub(255,99,71);
    glVertex2f(-0.74f, 0.24f);
    glVertex2f(-0.74f,0.3f);

    glVertex2f(-0.567f,0.3f);
    glVertex2f(-0.567f, 0.24f);


    //end
    glEnd();

    glBegin(GL_LINES);//extra line
    glColor3ub(1,1,1);
    glVertex2f(0.549f,0.28f);
    glVertex2f(-0.549f,0.28f);

    glVertex2f(0.567f,0.3f);//right
    glVertex2f(0.74f,0.3f);

    glVertex2f(-0.567f,0.3f);//left
    glVertex2f(-0.74f,0.3f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255,99,71);

    glVertex2f(0.567f,0.3f);//right
    glVertex2f(0.6535f,0.36f);
    glVertex2f(0.74f,0.3f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255,99,71);

    glVertex2f(-0.567f,0.3f);//left
    glVertex2f(-0.6535f,0.36f);
    glVertex2f(-0.74f,0.3f);

    glEnd();

    glBegin(GL_LINES);//extra line
    glColor3ub(1,1,1);

    glVertex2f(0.567f,0.3f);//right
    glVertex2f(0.74f,0.3f);

    glVertex2f(0.74f,0.3f);
    glVertex2f(0.6535f,0.36f);

    glVertex2f(0.567f,0.3f);//
    glVertex2f(0.6535f,0.36f);

    glVertex2f(0.74f,0.3f);
    glVertex2f(0.567f,0.3f);//

    glEnd();

        glBegin(GL_LINES);//extra line
    glColor3ub(1,1,1);

    glVertex2f(-0.567f,0.3f);//left
    glVertex2f(-0.74f,0.3f);

    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.6535f,0.36f);

    glVertex2f(-0.567f,0.3f);//
    glVertex2f(-0.6535f,0.36f);

    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.567f,0.3f);//

    glEnd();

    glBegin(GL_LINES);//triangle line right
    glColor3ub(1,1,1);

    glVertex2f(0.61f,0.3f);//right
    glVertex2f(0.6535f,0.36f);

    glVertex2f(0.6535f,0.36f);
    glVertex2f(0.644f,0.3f);

    glVertex2f(0.696f,0.3f);
    glVertex2f(0.6535f,0.36f);

    glEnd();

    glBegin(GL_LINES);//triangle line left
    glColor3ub(1,1,1);

    glVertex2f(-0.61f,0.3f);//right
    glVertex2f(-0.6535f,0.36f);

    glVertex2f(-0.6535f,0.36f);
    glVertex2f(-0.644f,0.3f);

    glVertex2f(-0.696f,0.3f);
    glVertex2f(-0.6535f,0.36f);

    glEnd();









     int i9;// window up right 1

	GLfloat x9=0.69f; GLfloat y9=-0.08f; GLfloat radius9 =.02f;
	int triangleAmount9 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi9 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x9, y9); // center of circle
		for(i9 = 0; i9 <= triangleAmount9;i9++) {
			glVertex2f(
		            x9 + (radius9 * cos(i9 *  twicePi9 / triangleAmount9)),
			    y9 + (radius9 * sin(i9 * twicePi9 / triangleAmount9))
			);
		}
	glEnd();

	glBegin(GL_QUADS);// window right 1
	glColor3ub(0,0,0);
    glVertex2f(0.71f, -0.2f);
    glVertex2f(0.71f,-0.08f);
    glVertex2f(0.67f, -0.08f);
    glVertex2f(0.67f,-0.2f);

    glEnd();

    glBegin(GL_QUADS);// window up right 1 corner
	glColor3ub(0,0,0);
    glVertex2f(0.71f, 0.02f);
    glVertex2f(0.71f,0.15f);
    glVertex2f(0.67f, 0.15f);
    glVertex2f(0.67f,0.02f);

    glEnd();

    glBegin(GL_QUADS);// window up left 1 corner
	glColor3ub(0,0,0);
    glVertex2f(-0.71f, 0.02f);
    glVertex2f(-0.71f,0.15f);
    glVertex2f(-0.67f, 0.15f);
    glVertex2f(-0.67f,0.02f);

    glEnd();


    int i10;// window up right 2

    GLfloat x10=0.61f; GLfloat y10=-0.08f; GLfloat radius10 =.02f;
	int triangleAmount10 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi10 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x10, y10); // center of circle
		for(i10 = 0; i10 <= triangleAmount10;i10++) {
			glVertex2f(
		            x10 + (radius10 * cos(i10 *  twicePi10 / triangleAmount10)),
			    y10 + (radius10 * sin(i10 * twicePi10 / triangleAmount10))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 2
	glColor3ub(0,0,0);
    glVertex2f(0.59f, 0.02f);
    glVertex2f(0.59f, 0.15f);
    glVertex2f(0.63f, 0.15f);
    glVertex2f(0.63f,0.02f);

    glEnd();

    glBegin(GL_QUADS);// window up right corner
	glColor3ub(0,0,0);
    glVertex2f(0.59f, -0.2f);
    glVertex2f(0.59f,-0.08f);
    glVertex2f(0.63f, -0.08f);
    glVertex2f(0.63f,-0.2f);

    glEnd();


    int i11;// window up right 3

    GLfloat x11=0.508f; GLfloat y11=-0.08f; GLfloat radius11 =.02f;
	int triangleAmount11 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi11 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x11, y11); // center of circle
		for(i11 = 0; i11 <= triangleAmount11;i11++) {
			glVertex2f(
		            x11 + (radius11 * cos(i11 *  twicePi11 / triangleAmount11)),
			    y11 + (radius11 * sin(i11 * twicePi11 / triangleAmount11))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 3
	glColor3ub(0,0,0);
    glVertex2f(0.488f, -0.2f);
    glVertex2f(0.488f,-0.08f);
    glVertex2f(0.528f, -0.08f);
    glVertex2f(0.528f,-0.2f);

    glEnd();

        int i12;// window up right 4

    GLfloat x12=0.4175f; GLfloat y12=-0.08f; GLfloat radius12 =.02f;
	int triangleAmount12 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi12 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x12, y12); // center of circle
		for(i12 = 0; i12 <= triangleAmount12;i12++) {
			glVertex2f(
		            x12 + (radius12 * cos(i12 *  twicePi12 / triangleAmount12)),
			    y12 + (radius12 * sin(i12 * twicePi12 / triangleAmount12))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 4
	glColor3ub(0,0,0);
    glVertex2f(0.438f, -0.2f);
    glVertex2f(0.438f,-0.08f);
    glVertex2f(0.397f, -0.08f);
    glVertex2f(0.397f,-0.2f);

    glEnd();

            int i13;// window up right 5

    GLfloat x13=0.3265f; GLfloat y13=-0.08f; GLfloat radius13 =.02f;
	int triangleAmount13 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi13 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x13, y13); // center of circle
		for(i13 = 0; i13 <= triangleAmount13;i13++) {
			glVertex2f(
		            x13 + (radius13 * cos(i13 *  twicePi13 / triangleAmount13)),
			    y13 + (radius13 * sin(i13 * twicePi13 / triangleAmount13))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 5
	glColor3ub(0,0,0);
    glVertex2f(0.347f, -0.2f);
    glVertex2f(0.347f,-0.08f);
    glVertex2f(0.306f, -0.08f);
    glVertex2f(0.306f,-0.2f);

    glEnd();

    int i14;// window up right 6

    GLfloat x14=0.2355f; GLfloat y14=-0.08f; GLfloat radius14 =.02f;
	int triangleAmount14 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi14 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x14, y14); // center of circle
		for(i14 = 0; i14 <= triangleAmount14;i14++) {
			glVertex2f(
		            x14 + (radius14 * cos(i14 *  twicePi14 / triangleAmount14)),
			    y14 + (radius14 * sin(i14 * twicePi14 / triangleAmount14))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 6
	glColor3ub(0,0,0);
    glVertex2f(0.256f, -0.2f);
    glVertex2f(0.256f,-0.08f);
    glVertex2f(0.215f, -0.08f);
    glVertex2f(0.215f,-0.2f);

    glEnd();


    int i15;// window up left 1

	GLfloat x15=-0.69f; GLfloat y15=-0.08f; GLfloat radius15 =.02f;
	int triangleAmount15 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi15 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x15, y15); // center of circle
		for(i15 = 0; i15 <= triangleAmount15;i15++) {
			glVertex2f(
		            x15 + (radius15 * cos(i15 *  twicePi15 / triangleAmount15)),
			    y15 + (radius15 * sin(i15 * twicePi15 / triangleAmount15))
			);
		}
	glEnd();

	glBegin(GL_QUADS);// window left 1
	glColor3ub(0,0,0);
    glVertex2f(-0.71f, -0.2f);
    glVertex2f(-0.71f,-0.08f);
    glVertex2f(-0.67f, -0.08f);
    glVertex2f(-0.67f,-0.2f);

    glEnd();


    int i16;// window up left 2

    GLfloat x16=-0.61f; GLfloat y16=-0.08f; GLfloat radius16 =.02f;
	int triangleAmount16 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi16 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x16, y16); // center of circle
		for(i16 = 0; i16 <= triangleAmount16;i16++) {
			glVertex2f(
		            x16 + (radius16 * cos(i16 *  twicePi16 / triangleAmount16)),
			    y16 + (radius16 * sin(i16 * twicePi16 / triangleAmount16))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window left 2
	glColor3ub(0,0,0);
    glVertex2f(-0.59f, -0.2f);
    glVertex2f(-0.59f,-0.08f);
    glVertex2f(-0.63f, -0.08f);
    glVertex2f(-0.63f,-0.2f);

    glEnd();

        glBegin(GL_QUADS);// window left up corner
	glColor3ub(0,0,0);
    glVertex2f(-0.59f, 0.02f);
    glVertex2f(-0.59f,0.15f);
    glVertex2f(-0.63f, 0.15f);
    glVertex2f(-0.63f,0.02f);

    glEnd();

    int i17;// window up right 3

    GLfloat x17=-0.508f; GLfloat y17=-0.08f; GLfloat radius17 =.02f;
	int triangleAmount17 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi17 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x17, y17); // center of circle
		for(i17 = 0; i17 <= triangleAmount17;i17++) {
			glVertex2f(
		            x17 + (radius17 * cos(i17 *  twicePi17 / triangleAmount17)),
			    y17 + (radius17 * sin(i17 * twicePi17 / triangleAmount17))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 3
	glColor3ub(0,0,0);
    glVertex2f(-0.488f, -0.2f);
    glVertex2f(-0.488f,-0.08f);
    glVertex2f(-0.528f, -0.08f);
    glVertex2f(-0.528f,-0.2f);

    glEnd();

        int i18;// window up left 4

    GLfloat x18=-0.4175f; GLfloat y18=-0.08f; GLfloat radius18 =.02f;
	int triangleAmount18 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi18 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x18, y18); // center of circle
		for(i18 = 0; i18 <= triangleAmount18;i18++) {
			glVertex2f(
		            x18 + (radius18 * cos(i18 *  twicePi18 / triangleAmount18)),
			    y18 + (radius18 * sin(i18 * twicePi18 / triangleAmount18))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window left 4
	glColor3ub(0,0,0);
    glVertex2f(-0.438f, -0.2f);
    glVertex2f(-0.438f,-0.08f);
    glVertex2f(-0.397f, -0.08f);
    glVertex2f(-0.397f,-0.2f);

    glEnd();

    int i19;// window up left 5

    GLfloat x19=-0.3265f; GLfloat y19=-0.08f; GLfloat radius19 =.02f;
	int triangleAmount19 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi19 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x19, y19); // center of circle
		for(i19 = 0; i19 <= triangleAmount19;i19++) {
			glVertex2f(
		            x19 + (radius19 * cos(i19 *  twicePi19 / triangleAmount19)),
			    y19 + (radius19 * sin(i19 * twicePi19 / triangleAmount19))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window left 5
	glColor3ub(0,0,0);
    glVertex2f(-0.347f, -0.2f);
    glVertex2f(-0.347f,-0.08f);
    glVertex2f(-0.306f, -0.08f);
    glVertex2f(-0.306f,-0.2f);

    glEnd();

    int i20;// window up left 6

    GLfloat x20=-0.2355f; GLfloat y20=-0.08f; GLfloat radius20 =.02f;
	int triangleAmount20 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi20 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x20, y20); // center of circle
		for(i20 = 0; i20 <= triangleAmount20;i20++) {
			glVertex2f(
		            x20 + (radius20 * cos(i20 *  twicePi20 / triangleAmount20)),
			    y20 + (radius20 * sin(i20 * twicePi20 / triangleAmount20))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window left 6
	glColor3ub(0,0,0);
    glVertex2f(-0.256f, -0.2f);
    glVertex2f(-0.256f,-0.08f);
    glVertex2f(-0.215f, -0.08f);
    glVertex2f(-0.215f,-0.2f);

    glEnd();

    glBegin(GL_LINES); // right up stair 1
    glColor3ub(0,0,0);

    glVertex2f(0.472f, -0.02f);
    glVertex2f(0.472f,0.2f);

    glVertex2f(0.472f,0.2f);
    glVertex2f(0.454f,0.2f);

    glVertex2f(0.454f,0.2f);
    glVertex2f(0.454f, -0.02f);

    glVertex2f(0.454f, -0.02f);
    glVertex2f(0.472f, -0.02f);



    glEnd();

    //lower beam 1
    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(0.475f, -0.02f);
    glVertex2f(0.475f, 0.0f);

    glVertex2f(0.475f, 0.0f);
    glVertex2f(0.451f, 0.0f);

    glVertex2f(0.451f, 0.0f);
    glVertex2f(0.451f, -0.02f);

    glVertex2f(0.475f, -0.02f);
    glVertex2f(0.451f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // right up stair 2
    glColor3ub(0,0,0);

    glVertex2f(0.381f, -0.02f);
    glVertex2f(0.381f, 0.2f);

    glVertex2f(0.381f, 0.2f);
    glVertex2f(0.363f, 0.2f);

    glVertex2f(0.363f, 0.2f);
    glVertex2f(0.363f, -0.02f);

    glVertex2f(0.363f, -0.02f);
    glVertex2f(0.381f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // right beam 2
    glColor3ub(0,0,0);

    glVertex2f(0.384f, -0.02f);
    glVertex2f(0.384f, 0.0f);

    glVertex2f(0.384f, 0.0f);
    glVertex2f(0.36f, 0.00f);

    glVertex2f(0.36f, 0.0f);
    glVertex2f(0.36f,-0.02f);

    glVertex2f(0.36f,-0.02f);
    glVertex2f(0.384f, -0.02f);

    glEnd();


    glBegin(GL_LINES); // right up stair 3
    glColor3ub(0,0,0);

    glVertex2f(0.29f, -0.02f);
    glVertex2f(0.29f, 0.2f);

    glVertex2f(0.29f, 0.2f);
    glVertex2f(0.27f, 0.2f);

    glVertex2f(0.27f, 0.2f);
    glVertex2f(0.27f, -0.02f);

    glVertex2f(0.29f, -0.02f);
    glVertex2f(0.29f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // right beam 3
    glColor3ub(0,0,0);

    glVertex2f(0.293f, -0.02f);
    glVertex2f(0.293f, 0.0f);

    glVertex2f(0.293f, 0.0f);
    glVertex2f(0.269f, 0.0f);

    glVertex2f(0.269f, 0.0f);
    glVertex2f(0.269f,-0.02f);

    glVertex2f(0.269f,-0.02f);
    glVertex2f(0.293f, -0.02f);

    glEnd();



    glBegin(GL_LINES); // right up stair 4
    glColor3ub(0,0,0);

    glVertex2f(0.199f, -0.02f);
    glVertex2f(0.199f, 0.2f);

    glVertex2f(0.199f, 0.2f);
    glVertex2f(0.181f, 0.2f);

    glVertex2f(0.181f, 0.2f);
    glVertex2f(0.181f, -0.02f);

    glVertex2f(0.199f, -0.02f);
    glVertex2f(0.199f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // right beam 4
    glColor3ub(0,0,0);

    glVertex2f(0.202f, -0.02f);
    glVertex2f(0.202f, 0.0f);

    glVertex2f(0.202f, 0.0f);
    glVertex2f(0.178f, 0.0f);

    glVertex2f(0.178f, 0.0f);
    glVertex2f(0.178f, -0.02f);

    glVertex2f(0.178f, -0.02f);
    glVertex2f(0.202f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // left up stair 1
    glColor3ub(0,0,0);

    glVertex2f(-0.472f, -0.02f);
    glVertex2f(-0.472f,0.2f);

    glVertex2f(-0.472f,0.2f);
    glVertex2f(-0.454f,0.2f);

    glVertex2f(-0.454f,0.2f);
    glVertex2f(-0.454f, -0.02f);

    glVertex2f(-0.454f, -0.02f);
    glVertex2f(-0.472f, -0.02f);



    glEnd();

    //lower beam 1
    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(-0.475f, -0.02f);
    glVertex2f(-0.475f, 0.0f);

    glVertex2f(-0.475f, 0.0f);
    glVertex2f(-0.451f, 0.0f);

    glVertex2f(-0.451f, 0.0f);
    glVertex2f(-0.451f, -0.02f);

    glVertex2f(-0.475f, -0.02f);
    glVertex2f(-0.451f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // left up stair 2
    glColor3ub(0,0,0);

    glVertex2f(-0.381f, -0.02f);
    glVertex2f(-0.381f, 0.2f);

    glVertex2f(-0.381f, 0.2f);
    glVertex2f(-0.363f, 0.2f);

    glVertex2f(-0.363f, 0.2f);
    glVertex2f(-0.363f, -0.02f);

    glVertex2f(-0.363f, -0.02f);
    glVertex2f(-0.381f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // left beam 2
    glColor3ub(0,0,0);

    glVertex2f(0.384f, -0.02f);
    glVertex2f(0.384f, 0.0f);

    glVertex2f(-0.384f, 0.0f);
    glVertex2f(-0.36f, 0.00f);

    glVertex2f(-0.36f, 0.0f);
    glVertex2f(-0.36f,-0.02f);

    glVertex2f(-0.36f,-0.02f);
    glVertex2f(-0.384f, -0.02f);

    glEnd();


    glBegin(GL_LINES); // left up stair 3
    glColor3ub(0,0,0);

    glVertex2f(-0.29f, -0.02f);
    glVertex2f(-0.29f, 0.2f);

    glVertex2f(-0.29f, 0.2f);
    glVertex2f(-0.27f, 0.2f);

    glVertex2f(-0.27f, 0.2f);
    glVertex2f(-0.27f, -0.02f);

    glVertex2f(-0.29f, -0.02f);
    glVertex2f(-0.29f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // left beam 3
    glColor3ub(0,0,0);

    glVertex2f(-0.293f, -0.02f);
    glVertex2f(-0.293f, 0.0f);

    glVertex2f(-0.293f, 0.0f);
    glVertex2f(-0.269f, 0.0f);

    glVertex2f(-0.269f, 0.0f);
    glVertex2f(-0.269f,-0.02f);

    glVertex2f(-0.269f,-0.02f);
    glVertex2f(-0.293f, -0.02f);

    glEnd();



    glBegin(GL_LINES); // left up stair 4
    glColor3ub(0,0,0);

    glVertex2f(-0.199f, -0.02f);
    glVertex2f(-0.199f, 0.2f);

    glVertex2f(-0.199f, 0.2f);
    glVertex2f(-0.181f, 0.2f);

    glVertex2f(-0.181f, 0.2f);
    glVertex2f(-0.181f, -0.02f);

    glVertex2f(-0.199f, -0.02f);
    glVertex2f(-0.199f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // left beam 4
    glColor3ub(0,0,0);

    glVertex2f(-0.202f, -0.02f);
    glVertex2f(-0.202f, 0.0f);

    glVertex2f(-0.202f, 0.0f);
    glVertex2f(-0.178f, 0.0f);

    glVertex2f(-0.178f, 0.0f);
    glVertex2f(-0.178f, -0.02f);

    glVertex2f(-0.178f, -0.02f);
    glVertex2f(-0.202f, -0.02f);

    glEnd();


    glBegin(GL_QUADS);// window right 3
	glColor3ub(0,0,0);
    glVertex2f(0.488f, -0.2f);
    glVertex2f(0.488f,-0.08f);
    glVertex2f(0.528f, -0.08f);
    glVertex2f(0.528f,-0.2f);

    glEnd();

        int i21;// upstair window up right 4

    GLfloat x21=0.4175f; GLfloat y21=0.14f; GLfloat radius21 =.02f;
	int triangleAmount21 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi21 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x21, y21); // center of circle
		for(i21 = 0; i21 <= triangleAmount21;i21++) {
			glVertex2f(
		            x21 + (radius21 * cos(i21 *  twicePi21 / triangleAmount21)),
			    y21 + (radius21 * sin(i21 * twicePi21 / triangleAmount21))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 4
	glColor3ub(0,0,0);
    glVertex2f(0.438f, 0.0f);
    glVertex2f(0.438f, 0.14f);
    glVertex2f(0.397f, 0.14f);
    glVertex2f(0.397f, 0.0f);

    glEnd();


    int i22;// upstair window up right 5

    GLfloat x22=0.3265f; GLfloat y22=0.14f; GLfloat radius22 =.02f;
	int triangleAmount22 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi22 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x22, y22); // center of circle
		for(i22 = 0; i22 <= triangleAmount22;i22++) {
			glVertex2f(
		            x22 + (radius22 * cos(i22 *  twicePi22 / triangleAmount22)),
			    y22 + (radius22 * sin(i22 * twicePi22 / triangleAmount22))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 5
	glColor3ub(0,0,0);
    glVertex2f(0.347f, 0.0f);
    glVertex2f(0.347f,0.14f);
    glVertex2f(0.306f, 0.14f);
    glVertex2f(0.306f,0.0f);

    glEnd();

    int i23;// upstair window up right 6

    GLfloat x23=0.2355f; GLfloat y23=0.14f; GLfloat radius23 =.02f;
	int triangleAmount23 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi23 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x23, y23); // center of circle
		for(i23 = 0; i23 <= triangleAmount23;i23++) {
			glVertex2f(
		            x23 + (radius23 * cos(i23 *  twicePi23 / triangleAmount23)),
			    y23 + (radius23 * sin(i23 * twicePi23 / triangleAmount23))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 6
	glColor3ub(0,0,0);
    glVertex2f(0.256f,  0.0f);
    glVertex2f(0.256f, 0.14f);
    glVertex2f(0.215f, 0.14f);
    glVertex2f(0.215f, 0.0f);

    glEnd();


    int i24;// upstair window up left 4

    GLfloat x24=-0.4175f; GLfloat y24=0.14f; GLfloat radius24 =.02f;
	int triangleAmount24 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi24 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x24, y24); // center of circle
		for(i24 = 0; i24 <= triangleAmount21;i24++) {
			glVertex2f(
		            x24 + (radius24 * cos(i24 *  twicePi24 / triangleAmount24)),
			    y24 + (radius24 * sin(i24 * twicePi24 / triangleAmount24))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window left 4
	glColor3ub(0,0,0);
    glVertex2f(-0.438f, 0.0f);
    glVertex2f(-0.438f, 0.14f);
    glVertex2f(-0.397f, 0.14f);
    glVertex2f(-0.397f, 0.0f);

    glEnd();


    int i25;// upstair window up left 5

    GLfloat x25=-0.3265f; GLfloat y25=0.14f; GLfloat radius25 =.02f;
	int triangleAmount25 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi25 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x25, y25); // center of circle
		for(i25 = 0; i25 <= triangleAmount25;i25++) {
			glVertex2f(
		            x25 + (radius25 * cos(i25 *  twicePi25 / triangleAmount25)),
			    y25 + (radius25 * sin(i25 * twicePi25 / triangleAmount25))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window left 5
	glColor3ub(0,0,0);
    glVertex2f(-0.347f, 0.0f);
    glVertex2f(-0.347f,0.14f);
    glVertex2f(-0.306f, 0.14f);
    glVertex2f(-0.306f,0.0f);

    glEnd();

    int i26;// upstair window up left 6

    GLfloat x26=-0.2355f; GLfloat y26=0.14f; GLfloat radius26 =.02f;
	int triangleAmount26 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi26 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x26, y26); // center of circle
		for(i26 = 0; i26 <= triangleAmount26;i26++) {
			glVertex2f(
		            x26 + (radius26 * cos(i26 *  twicePi26 / triangleAmount26)),
			    y26 + (radius26 * sin(i26 * twicePi26 / triangleAmount26))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window left 6
	glColor3ub(0,0,0);
    glVertex2f(-0.256f,  0.0f);
    glVertex2f(-0.256f, 0.14f);
    glVertex2f(-0.215f, 0.14f);
    glVertex2f(-0.215f, 0.0f);

    glEnd();


    //middle

        int i27;// upstair window right

    GLfloat x27=0.15f; GLfloat y27=0.14f; GLfloat radius27 =.02f;
	int triangleAmount27 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi27 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x27, y27); // center of circle
		for(i27 = 0; i27 <= triangleAmount27;i27++) {
			glVertex2f(
		            x27 + (radius27 * cos(i27 *  twicePi27 / triangleAmount27)),
			    y27 + (radius27 * sin(i27 * twicePi27 / triangleAmount27))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window left 6
	glColor3ub(0,0,0);
    glVertex2f(0.17f,  0.0f);
    glVertex2f(0.17f, 0.14f);
    glVertex2f(0.13f, 0.14f);
    glVertex2f(0.13f, 0.0f);

    glEnd();

            int i28;// upstair window left

    GLfloat x28=-0.15f; GLfloat y28=0.14f; GLfloat radius28 =.02f;
	int triangleAmount28 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi28 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x28, y28); // center of circle
		for(i28 = 0; i28 <= triangleAmount28;i28++) {
			glVertex2f(
		            x28 + (radius28 * cos(i28 *  twicePi28 / triangleAmount28)),
			    y28 + (radius28 * sin(i28 * twicePi28 / triangleAmount28))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// middle
	glColor3ub(0,0,0);
    glVertex2f(-0.17f,  0.0f);
    glVertex2f(-0.17f, 0.14f);
    glVertex2f(-0.13f, 0.14f);
    glVertex2f(-0.13f, 0.0f);

    glEnd();



    glBegin(GL_LINES);// upper line
	glColor3ub(1,1,1);
    glVertex2f(0.76f, 0.2f);
	glVertex2f(0.76f, 0.24f);

	glVertex2f(0.76f, 0.24f);
	glVertex2f(-0.76f, 0.24f);

    glVertex2f(-0.76f, 0.24f);
    glVertex2f(-0.76, 0.2f);

    glVertex2f(-0.76, 0.2f);
    glVertex2f(0.76f, 0.2f);

    //some design
    glVertex2f(0.76f, 0.205f);
	glVertex2f(-0.76f, 0.205f);

	glVertex2f(0.76f, 0.21f);
	glVertex2f(-0.76f, 0.21f);

    glEnd();


    int i29;// bubles

    GLfloat x29=0.51f; GLfloat y29=0.225f; GLfloat radius29 =.008f;
	int triangleAmount29 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi29 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x29, y29); // center of circle
		for(i29 = 0; i29 <= triangleAmount29;i29++) {
			glVertex2f(
		            x29 + (radius29 * cos(i29 *  twicePi29 / triangleAmount29)),
			    y29 + (radius29 * sin(i29 * twicePi29 / triangleAmount29))
			);
		}
	glEnd();

	    int i30;// bubles

    GLfloat x30=0.49f; GLfloat y30=0.225f; GLfloat radius30 =.008f;
	int triangleAmount30 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi30 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x30, y30); // center of circle
		for(i30 = 0; i30 <= triangleAmount30;i30++) {
			glVertex2f(
		            x30 + (radius30 * cos(i30 *  twicePi30 / triangleAmount30)),
			    y30 + (radius30 * sin(i30 * twicePi30 / triangleAmount30))
			);
		}
	glEnd();

    int i31;// bubles

    GLfloat x31=0.47f; GLfloat y31=0.225f; GLfloat radius31 =.008f;
	int triangleAmount31 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi31 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x31, y31); // center of circle
		for(i31 = 0; i31 <= triangleAmount31;i31++) {
			glVertex2f(
		            x31 + (radius31 * cos(i31 *  twicePi31 / triangleAmount31)),
			    y31 + (radius31 * sin(i31 * twicePi31 / triangleAmount31))
			);
		}
	glEnd();

    int i32;// bubles

    GLfloat x32=0.42f; GLfloat y32=0.225f; GLfloat radius32 =.008f;
	int triangleAmount32 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi32 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x32, y32); // center of circle
		for(i32 = 0; i32 <= triangleAmount32;i32++) {
			glVertex2f(
		            x32 + (radius32 * cos(i32 *  twicePi32 / triangleAmount32)),
			    y32 + (radius32 * sin(i32 * twicePi32 / triangleAmount32))
			);
		}
	glEnd();

	    int i33;// bubles

    GLfloat x33=0.4f; GLfloat y33=0.225f; GLfloat radius33 =.008f;
	int triangleAmount33 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi33 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x33, y33); // center of circle
		for(i33 = 0; i33 <= triangleAmount33;i33++) {
			glVertex2f(
		            x33 + (radius33 * cos(i33 *  twicePi33 / triangleAmount33)),
			    y33 + (radius33 * sin(i33 * twicePi33 / triangleAmount33))
			);
		}
	glEnd();


    int i34;// bubles

    GLfloat x34=0.38f; GLfloat y34=0.225f; GLfloat radius34 =.008f;
	int triangleAmount34 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi34 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x34, y34); // center of circle
		for(i34 = 0; i34 <= triangleAmount34;i34++) {
			glVertex2f(
		            x34 + (radius34 * cos(i34 *  twicePi34 / triangleAmount34)),
			    y34 + (radius34 * sin(i34 * twicePi34 / triangleAmount34))
			);
		}
	glEnd();

    int i35;// bubles

    GLfloat x35=0.33f; GLfloat y35=0.225f; GLfloat radius35 =.008f;
	int triangleAmount35 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi35 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x35, y35); // center of circle
		for(i35 = 0; i35 <= triangleAmount35;i35++) {
			glVertex2f(
		            x35 + (radius35 * cos(i35 *  twicePi35 / triangleAmount35)),
			    y35 + (radius35 * sin(i35 * twicePi35 / triangleAmount35))
			);
		}
	glEnd();

	    int i36;// bubles

    GLfloat x36=0.31f; GLfloat y36=0.225f; GLfloat radius36 =.008f;
	int triangleAmount36 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi36 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x36, y36); // center of circle
		for(i36 = 0; i36 <= triangleAmount36;i36++) {
			glVertex2f(
		            x36 + (radius36 * cos(i36 *  twicePi36 / triangleAmount36)),
			    y36 + (radius36 * sin(i36 * twicePi36 / triangleAmount36))
			);
		}
	glEnd();

	    int i37;// bubles

    GLfloat x37=0.29f; GLfloat y37=0.225f; GLfloat radius37 =.008f;
	int triangleAmount37 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi37 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x37, y37); // center of circle
		for(i37 = 0; i37 <= triangleAmount37;i37++) {
			glVertex2f(
		            x37 + (radius37 * cos(i37 *  twicePi37 / triangleAmount37)),
			    y37 + (radius37 * sin(i37 * twicePi37 / triangleAmount37))
			);
		}
	glEnd();

    int i38;// bubles

    GLfloat x38=0.24f; GLfloat y38=0.225f; GLfloat radius38 =.008f;
	int triangleAmount38 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi38 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x38, y38); // center of circle
		for(i38 = 0; i38 <= triangleAmount38;i38++) {
			glVertex2f(
		            x38 + (radius38 * cos(i38 *  twicePi38 / triangleAmount38)),
			    y38 + (radius38 * sin(i38 * twicePi38 / triangleAmount38))
			);
		}
	glEnd();

    int i39;// bubles

    GLfloat x39=0.22f; GLfloat y39=0.225f; GLfloat radius39 =.008f;
	int triangleAmount39 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi39 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x39, y39); // center of circle
		for(i39 = 0; i39 <= triangleAmount39;i39++) {
			glVertex2f(
		            x39 + (radius39 * cos(i39 *  twicePi39 / triangleAmount39)),
			    y39 + (radius39 * sin(i39 * twicePi39 / triangleAmount39))
			);
		}
	glEnd();

    int i40;// bubles

    GLfloat x40=0.2f; GLfloat y40=0.225f; GLfloat radius40 =.008f;
	int triangleAmount40 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi40 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x40, y40); // center of circle
		for(i40 = 0; i40 <= triangleAmount40;i40++) {
			glVertex2f(
		            x40 + (radius40 * cos(i40 *  twicePi40 / triangleAmount40)),
			    y40 + (radius40 * sin(i40 * twicePi40 / triangleAmount40))
			);
		}
	glEnd();

    int i41;// bubles

    GLfloat x41=-0.51f; GLfloat y41=0.225f; GLfloat radius41 =.008f;
	int triangleAmount41 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi41 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x41, y41); // center of circle
		for(i41 = 0; i41 <= triangleAmount41;i41++) {
			glVertex2f(
		            x41 + (radius41 * cos(i41 *  twicePi41 / triangleAmount41)),
			    y41 + (radius41 * sin(i41 * twicePi41 / triangleAmount41))
			);
		}
	glEnd();

	    int i42;// bubles

    GLfloat x42=-0.49f; GLfloat y42=0.225f; GLfloat radius42 =.008f;
	int triangleAmount42 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi42 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x42, y42); // center of circle
		for(i42 = 0; i42 <= triangleAmount42;i42++) {
			glVertex2f(
		            x42 + (radius42 * cos(i42 *  twicePi42 / triangleAmount42)),
			    y42 + (radius42 * sin(i42 * twicePi42 / triangleAmount42))
			);
		}
	glEnd();

    int i43;// bubles

    GLfloat x43=-0.47f; GLfloat y43=0.225f; GLfloat radius43 =.008f;
	int triangleAmount43 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi43 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x43, y43); // center of circle
		for(i43 = 0; i43 <= triangleAmount43;i43++) {
			glVertex2f(
		            x43 + (radius43 * cos(i43 *  twicePi43 / triangleAmount43)),
			    y43 + (radius43 * sin(i43 * twicePi43 / triangleAmount43))
			);
		}
	glEnd();

    int i44;// bubles

    GLfloat x44=-0.42f; GLfloat y44=0.225f; GLfloat radius44 =.008f;
	int triangleAmount44 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi44 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x44, y44); // center of circle
		for(i44 = 0; i44 <= triangleAmount44;i44++) {
			glVertex2f(
		            x44 + (radius44 * cos(i44 *  twicePi44 / triangleAmount44)),
			    y44 + (radius44 * sin(i44 * twicePi44 / triangleAmount44))
			);
		}
	glEnd();

	    int i45;// bubles

    GLfloat x45=-0.4f; GLfloat y45=0.225f; GLfloat radius45 =.008f;
	int triangleAmount45 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi45 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x45, y45); // center of circle
		for(i45 = 0; i45 <= triangleAmount45;i45++) {
			glVertex2f(
		            x45 + (radius45 * cos(i45 *  twicePi45 / triangleAmount45)),
			    y45 + (radius45 * sin(i45 * twicePi45 / triangleAmount45))
			);
		}
	glEnd();


    int i46;// bubles

    GLfloat x46=-0.38f; GLfloat y46=0.225f; GLfloat radius46 =.008f;
	int triangleAmount46 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi46 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x46, y46); // center of circle
		for(i46 = 0; i46 <= triangleAmount46;i46++) {
			glVertex2f(
		            x46 + (radius46 * cos(i46 *  twicePi46 / triangleAmount46)),
			    y46 + (radius46 * sin(i46 * twicePi46 / triangleAmount46))
			);
		}
	glEnd();

    int i47;// bubles

    GLfloat x47=-0.33f; GLfloat y47=0.225f; GLfloat radius47 =.008f;
	int triangleAmount47 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi47 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x47, y47); // center of circle
		for(i47 = 0; i47 <= triangleAmount47;i47++) {
			glVertex2f(
		            x47 + (radius47 * cos(i47 *  twicePi47 / triangleAmount47)),
			    y47 + (radius47 * sin(i47 * twicePi47 / triangleAmount47))
			);
		}
	glEnd();

	    int i48;// bubles

    GLfloat x48=-0.31f; GLfloat y48=0.225f; GLfloat radius48 =.008f;
	int triangleAmount48 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi48 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x48, y48); // center of circle
		for(i48 = 0; i48 <= triangleAmount48;i48++) {
			glVertex2f(
		            x48 + (radius48 * cos(i48 *  twicePi48 / triangleAmount48)),
			    y48 + (radius48 * sin(i48 * twicePi48 / triangleAmount48))
			);
		}
	glEnd();

	    int i49;// bubles

    GLfloat x49=-0.29f; GLfloat y49=0.225f; GLfloat radius49 =.008f;
	int triangleAmount49 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi49 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x49, y49); // center of circle
		for(i49 = 0; i49 <= triangleAmount49;i49++) {
			glVertex2f(
		            x49 + (radius49 * cos(i49 *  twicePi49 / triangleAmount49)),
			    y49 + (radius49 * sin(i49 * twicePi49 / triangleAmount49))
			);
		}
	glEnd();

    int i50;// bubles

    GLfloat x50=-0.24f; GLfloat y50=0.225f; GLfloat radius50 =.008f;
	int triangleAmount50 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi50 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x50, y50); // center of circle
		for(i50 = 0; i50 <= triangleAmount50;i50++) {
			glVertex2f(
		            x50 + (radius50 * cos(i50 *  twicePi50 / triangleAmount50)),
			    y50 + (radius50 * sin(i50 * twicePi50 / triangleAmount50))
			);
		}
	glEnd();

    int i51;// bubles

    GLfloat x51=-0.22f; GLfloat y51=0.225f; GLfloat radius51 =.008f;
	int triangleAmount51 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi51 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x51, y51); // center of circle
		for(i51 = 0; i51 <= triangleAmount51;i51++) {
			glVertex2f(
		            x51 + (radius51 * cos(i51 *  twicePi51 / triangleAmount51)),
			    y51 + (radius51 * sin(i51 * twicePi51 / triangleAmount51))
			);
		}
	glEnd();

    int i52;// bubles

    GLfloat x52=-0.2f; GLfloat y52=0.225f; GLfloat radius52 =.008f;
	int triangleAmount52 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi52 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x52, y52); // center of circle
		for(i52 = 0; i52 <= triangleAmount52;i52++) {
			glVertex2f(
		            x52 + (radius52 * cos(i52 *  twicePi52 / triangleAmount52)),
			    y52 + (radius52 * sin(i52 * twicePi52 / triangleAmount52))
			);
		}
	glEnd();



    int i53;// rest door
    GLfloat x53=0.502f; GLfloat y53=0.14f; GLfloat radius53 =.02f;
    int triangleAmount53 = 100; //# of triangles used to draw circle


	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi53 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x53, y53); // center of circle
		for(i53 = 0; i53 <= triangleAmount53;i53++) {
			glVertex2f(
                x53 + (radius53 * cos(i53 *  twicePi53 / triangleAmount53)),
			    y53 + (radius53 * sin(i53 * twicePi53 / triangleAmount53))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// upstair rest 2
	glColor3ub(0,0,0);
    glVertex2f(0.482f,  0.0f);
    glVertex2f(0.482f, 0.14f);
    glVertex2f(0.522f, 0.14f);
    glVertex2f(0.522f, 0.0f);

    glEnd();

    int i54;// rest door
    GLfloat x54=-0.502f; GLfloat y54=0.14f; GLfloat radius54 =.02f;
    int triangleAmount54 = 100; //# of triangles used to draw circle


	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi54 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x54, y54); // center of circle
		for(i54 = 0; i54 <= triangleAmount54;i54++) {
			glVertex2f(
                x54 + (radius54 * cos(i54 *  twicePi54 / triangleAmount54)),
			    y54 + (radius54 * sin(i54 * twicePi54 / triangleAmount54))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// upstair rest 2
	glColor3ub(0,0,0);
    glVertex2f(-0.482f,  0.0f);
    glVertex2f(-0.482f, 0.14f);
    glVertex2f(-0.522f, 0.14f);
    glVertex2f(-0.522f, 0.0f);

    glEnd();

    glBegin(GL_LINES);// upstair right pillar

    glVertex2f(0.575f, 0.2f);
    glVertex2f(0.575f, -0.02f);

    glVertex2f(0.571f, 0.2f);
    glVertex2f(0.571f, -0.02f);

    glVertex2f(0.554f, -0.02f);
    glVertex2f(0.554f,0.2f);

    glVertex2f(0.55f, -0.02f);
    glVertex2f(0.55f,0.2f);


    glEnd();

        glBegin(GL_LINES);// upstair left pillar

    glVertex2f(-0.575f, 0.2f);
    glVertex2f(-0.575f, -0.02f);

    glVertex2f(-0.571f, 0.2f);
    glVertex2f(-0.571f, -0.02f);

    glVertex2f(-0.554f, -0.02f);
    glVertex2f(-0.554f,0.2f);

    glVertex2f(-0.55f, -0.02f);
    glVertex2f(-0.55f,0.2f);


    glEnd();

    glBegin(GL_QUADS);//coloring minar
    glColor3ub(255,99,71);

    glVertex2f(0.575f, 0.24f);
    glVertex2f(0.575f, 0.34f);
    glVertex2f(0.55f,0.34f);
    glVertex2f(0.55f,0.24f);

    glEnd();

    glBegin(GL_LINES);// roof right pillar
    glColor3ub(1,1,1);

    glVertex2f(0.575f, 0.34f);
    glVertex2f(0.575f, 0.24f);

    glVertex2f(0.571f, 0.34f);
    glVertex2f(0.571f, 0.24f);

    glVertex2f(0.554f, 0.24f);
    glVertex2f(0.554f,0.34f);

    glVertex2f(0.55f, 0.24f);
    glVertex2f(0.55f,0.34f);

    glVertex2f(0.55f, 0.34f);//finishing
    glVertex2f(0.575f,0.34f);


    glEnd();

    glBegin(GL_QUADS);//color minar star
    glColor3ub(255,99,71);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);

    glEnd();

    glBegin(GL_LINES);//color minar star
    glColor3ub(1,1,1);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.562f, 0.34f);

    glEnd();








 glBegin(GL_LINES);//upstair right pillar corner
 glColor3ub(1,1,1);


    glVertex2f(0.722f, -0.02f);
    glVertex2f(0.722f,0.2f);

    glVertex2f(0.724f, -0.02f);
    glVertex2f(0.724f,0.2f);

    glVertex2f(0.726f, -0.02f);
    glVertex2f(0.726f,0.2f);

    glVertex2f(0.756f, -0.02f);
    glVertex2f(0.756f, 0.2f);

    glVertex2f(0.758f, -0.02f);
    glVertex2f(0.758f,0.2f);

    glVertex2f(0.76f, -0.02f);
    glVertex2f(0.76f, 0.2f);
    glEnd();

     glBegin(GL_LINES);//upstair right pillar corner
 glColor3ub(1,1,1);


    glVertex2f(-0.722f, -0.02f);
    glVertex2f(-0.722f,0.2f);

    glVertex2f(-0.724f, -0.02f);
    glVertex2f(-0.724f,0.2f);

    glVertex2f(-0.726f, -0.02f);
    glVertex2f(-0.726f,0.2f);

    glVertex2f(-0.756f, -0.02f);
    glVertex2f(-0.756f, 0.2f);

    glVertex2f(-0.758f, -0.02f);
    glVertex2f(-0.758f,0.2f);

    glVertex2f(-0.76f, -0.02f);
    glVertex2f(-0.76f, 0.2f);
    glEnd();



    glTranslatef(.18,0,0);//translate pillar 1
    //glScalef(.4,.4,0);


    glBegin(GL_QUADS);//coloring minar
    glColor3ub(255,99,71);

    glVertex2f(0.575f, 0.24f);
    glVertex2f(0.575f, 0.34f);
    glVertex2f(0.55f,0.34f);
    glVertex2f(0.55f,0.24f);

    glEnd();

    glBegin(GL_LINES);// roof right pillar
    glColor3ub(1,1,1);

    glVertex2f(0.575f, 0.34f);
    glVertex2f(0.575f, 0.24f);

    glVertex2f(0.571f, 0.34f);
    glVertex2f(0.571f, 0.24f);

    glVertex2f(0.554f, 0.24f);
    glVertex2f(0.554f,0.34f);

    glVertex2f(0.55f, 0.24f);
    glVertex2f(0.55f,0.34f);

    glVertex2f(0.55f, 0.34f);//finishing
    glVertex2f(0.575f,0.34f);


    glEnd();

    glBegin(GL_QUADS);//color minar star
    glColor3ub(255,99,71);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);

    glEnd();

    glBegin(GL_LINES);//color minar star
    glColor3ub(1,1,1);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.562f, 0.34f);

    glEnd();




    glLoadIdentity();


        glTranslatef(-1.31,0,0);//translate pillar 2 left
    //glScalef(.4,.4,0);


    glBegin(GL_QUADS);//coloring minar
    glColor3ub(255,99,71);

    glVertex2f(0.575f, 0.24f);
    glVertex2f(0.575f, 0.34f);
    glVertex2f(0.55f,0.34f);
    glVertex2f(0.55f,0.24f);

    glEnd();

    glBegin(GL_LINES);// roof right pillar
    glColor3ub(1,1,1);

    glVertex2f(0.575f, 0.34f);
    glVertex2f(0.575f, 0.24f);

    glVertex2f(0.571f, 0.34f);
    glVertex2f(0.571f, 0.24f);

    glVertex2f(0.554f, 0.24f);
    glVertex2f(0.554f,0.34f);

    glVertex2f(0.55f, 0.24f);
    glVertex2f(0.55f,0.34f);

    glVertex2f(0.55f, 0.34f);//finishing
    glVertex2f(0.575f,0.34f);


    glEnd();

    glBegin(GL_QUADS);//color minar star
    glColor3ub(255,99,71);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);

    glEnd();

    glBegin(GL_LINES);//color minar star
    glColor3ub(1,1,1);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.562f, 0.34f);

    glEnd();




    glLoadIdentity();


        glTranslatef(-1.122,0,0);//translate pillar 3
    //glScalef(.4,.4,0);


    glBegin(GL_QUADS);//coloring minar
    glColor3ub(255,99,71);

    glVertex2f(0.575f, 0.24f);
    glVertex2f(0.575f, 0.34f);
    glVertex2f(0.55f,0.34f);
    glVertex2f(0.55f,0.24f);

    glEnd();

    glBegin(GL_LINES);// roof right pillar
    glColor3ub(1,1,1);

    glVertex2f(0.575f, 0.34f);
    glVertex2f(0.575f, 0.24f);

    glVertex2f(0.571f, 0.34f);
    glVertex2f(0.571f, 0.24f);

    glVertex2f(0.554f, 0.24f);
    glVertex2f(0.554f,0.34f);

    glVertex2f(0.55f, 0.24f);
    glVertex2f(0.55f,0.34f);

    glVertex2f(0.55f, 0.34f);//finishing
    glVertex2f(0.575f,0.34f);


    glEnd();

    glBegin(GL_QUADS);//color minar star
    glColor3ub(255,99,71);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);

    glEnd();

    glBegin(GL_LINES);//color minar star
    glColor3ub(1,1,1);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.562f, 0.34f);

    glEnd();




    glLoadIdentity();

       int i58;// gombuj

    GLfloat x58=0.0f; GLfloat y58=0.41f; GLfloat radius58 =.08f;
	int triangleAmount58 = 30; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi58 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,99,71);
		glVertex2f(x58, y58); // center of circle
		for(i58 = 0; i58 <= triangleAmount58;i58++) {
			glVertex2f(
		            x58 + (radius58 * cos(i58 *  twicePi58 / triangleAmount58)),
			    y58 + (radius58 * sin(i58 * twicePi58 / triangleAmount58))
			);
		}
	glEnd();

	glBegin(GL_TRIANGLES);//overlap middle
	glColor3ub(255,99,71);
    glVertex2f(0.07f,  0.45f);
    glVertex2f(0.0, 0.55f);
    glVertex2f(-0.07f, 0.45f);


    glEnd();


    glBegin(GL_QUADS);//overlap middle
	glColor3ub(255,99,71);
    glVertex2f(0.12f,  0.0f);
    glVertex2f(0.12f, 0.28f);
    glVertex2f(-0.10f, 0.28f);
    glVertex2f(-0.10f, 0.0f);

    glEnd();

    glBegin(GL_QUADS);//pillar after minar
	glColor3ub(255,99,71);
    glVertex2f(0.12f,  0.0f);
    glVertex2f(0.12f, 0.31f);
    glVertex2f(0.093f, 0.31f);
    glVertex2f(0.093f, 0.0f);

    glEnd();

    glBegin(GL_LINES);//pillar middle right
	glColor3ub(1,1,1);
    glVertex2f(0.12f,  0.0f);
    glVertex2f(0.12f, 0.31f);
    glVertex2f(0.12f, 0.31f);
    glVertex2f(0.093f, 0.31f);
    glVertex2f(0.093f, 0.31f);
    glVertex2f(0.093f, 0.0f);
    glVertex2f(0.093f, 0.0f);
    glVertex2f(0.12f,  0.0f);



    glEnd();

    glBegin(GL_QUADS);//pillar after minar
	glColor3ub(255,99,71);
    glVertex2f(-0.12f,  0.0f);
    glVertex2f(-0.12f, 0.31f);
    glVertex2f(-0.093f, 0.31f);
    glVertex2f(-0.093f, 0.0f);

    glEnd();

    glBegin(GL_LINES);//pillar middle left
	glColor3ub(1,1,1);
    glVertex2f(-0.12f,  0.0f);
    glVertex2f(-0.12f, 0.31f);
    glVertex2f(-0.12f, 0.31f);
    glVertex2f(-0.093f, 0.31f);
    glVertex2f(-0.093f, 0.31f);
    glVertex2f(-0.093f, 0.0f);
    glVertex2f(-0.093f, 0.0f);
    glVertex2f(-0.12f,  0.0f);



    glEnd();

    glBegin(GL_POLYGON);//polygon right
	glColor3ub(255,99,71);
    glVertex2f(0.12f,  0.31f);
    glVertex2f(0.13f, 0.35f);
    glVertex2f(0.1065f, 0.38f);
    glVertex2f(0.083f, 0.35f);
    glVertex2f(0.093f, 0.31f);




    glEnd();

    glBegin(GL_LINES);//polygon lines right
	glColor3ub(1,1,1);
    glVertex2f(0.12f,  0.31f);
    glVertex2f(0.13f, 0.35f);

    glVertex2f(0.13f, 0.35f);
    glVertex2f(0.1065f, 0.38f);

    glVertex2f(0.1065f, 0.38f);
    glVertex2f(0.083f, 0.35f);

    glVertex2f(0.083f, 0.35f);
    glVertex2f(0.093f, 0.31f);

    glVertex2f(0.093f, 0.31f);
    glVertex2f(0.12f,  0.31f);





    glEnd();

        glBegin(GL_POLYGON);//polygon left
	glColor3ub(255,99,71);
    glVertex2f(-00.12f,  0.31f);
    glVertex2f(-0.13f, 0.35f);
    glVertex2f(-0.1065f, 0.38f);
    glVertex2f(-0.083f, 0.35f);
    glVertex2f(-0.093f, 0.31f);


    glEnd();

    glBegin(GL_LINES);//polygon lines left
	glColor3ub(1,1,1);
    glVertex2f(-0.12f,  0.31f);
    glVertex2f(-0.13f, 0.35f);

    glVertex2f(-0.13f, 0.35f);
    glVertex2f(-0.1065f, 0.38f);

    glVertex2f(-0.1065f, 0.38f);
    glVertex2f(-0.083f, 0.35f);

    glVertex2f(-0.083f, 0.35f);
    glVertex2f(-0.093f, 0.31f);

    glVertex2f(-0.093f, 0.31f);
    glVertex2f(-0.12f,  0.31f);


    glEnd();


    glTranslatef(-.454,0.03,0);//translate pillar middle
    //glScalef(.4,.4,0);

    glBegin(GL_QUADS);//color minar star
    glColor3ub(255,99,71);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);

    glEnd();

    glBegin(GL_LINES);//color minar star
    glColor3ub(1,1,1);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.562f, 0.34f);

    glEnd();




    glLoadIdentity();

    glTranslatef(.454,0.03,0);//translate pillar middle
    //glScalef(.4,.4,0);

    glBegin(GL_QUADS);//color minar star
    glColor3ub(255,99,71);

    glVertex2f(-0.562f, 0.34f);
    glVertex2f(-0.57f, 0.36f);
    glVertex2f(-0.562f,0.38f);
    glVertex2f(-0.554f,0.36f);

    glEnd();

    glBegin(GL_LINES);//color minar star
    glColor3ub(0,0,0);

    glVertex2f(-0.562f, 0.34f);
    glVertex2f(-0.57f, 0.36f);
    glVertex2f(-0.57f, 0.36f);
    glVertex2f(-0.562f,0.38f);
    glVertex2f(-0.562f,0.38f);
    glVertex2f(-0.554f,0.36f);
    glVertex2f(-0.554f,0.36f);
    glVertex2f(-0.562f, 0.34f);

    glEnd();




    glLoadIdentity();

    int i55;// middle

    GLfloat x55=0.0f; GLfloat y55=0.18f; GLfloat radius55 =.02f;
	int triangleAmount55 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi55 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x55, y55); // center of circle
		for(i55 = 0; i55 <= triangleAmount55;i55++) {
			glVertex2f(
		            x55 + (radius55 * cos(i55 *  twicePi55 / triangleAmount55)),
			    y55 + (radius55 * sin(i55 * twicePi55 / triangleAmount55))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// middle
	glColor3ub(0,0,0);
    glVertex2f(0.02f,  0.0f);
    glVertex2f(0.02f, 0.18f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.0f);

    glEnd();

        int i56;// middle

    GLfloat x56=0.06f; GLfloat y56=0.18f; GLfloat radius56 =.010f;
	int triangleAmount56 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi56 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x56, y56); // center of circle
		for(i56 = 0; i56 <= triangleAmount56;i56++) {
			glVertex2f(
		            x56 + (radius56 * cos(i56 *  twicePi56 / triangleAmount56)),
			    y56 + (radius56 * sin(i56 * twicePi56 / triangleAmount56))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// middle
	glColor3ub(0,0,0);
    glVertex2f(0.07f,  0.0f);
    glVertex2f(0.07f, 0.18f);
    glVertex2f(0.05f, 0.18f);
    glVertex2f(0.05f, 0.0f);

    glEnd();

            int i57;// upstair window left

    GLfloat x57=-0.06f; GLfloat y57=0.18f; GLfloat radius57 =.010f;
	int triangleAmount57 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi57 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x57, y57); // center of circle
		for(i57 = 0; i57 <= triangleAmount57;i57++) {
			glVertex2f(
		            x57 + (radius57 * cos(i57 *  twicePi57 / triangleAmount57)),
			    y57 + (radius57 * sin(i57 * twicePi57 / triangleAmount57))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// middle
	glColor3ub(0,0,0);
    glVertex2f(-0.07f,  0.0f);
    glVertex2f(-0.07f, 0.18f);
    glVertex2f(-0.05f, 0.18f);
    glVertex2f(-0.05f, 0.0f);

    glEnd();

    glBegin(GL_QUADS);//middle line
	glColor3ub(0,0,0);
    glVertex2f(0.092f,  0.26f);
    glVertex2f(0.092f, 0.27f);
    glVertex2f(-0.092f, 0.27f);
    glVertex2f(-0.092f, 0.26f);
    glEnd();


    glBegin(GL_POLYGON);//middle polygon
	glColor3ub(255,99,71);
    glVertex2f(0.08f,  0.28f);
    glVertex2f(0.08f, 0.38f);

    glVertex2f(0.05f, 0.4f);
    glVertex2f(-0.05f, 0.4f);

    glVertex2f(-0.08f, 0.38f);
    glVertex2f(-0.08f, 0.28f);
    glEnd();

    glBegin(GL_LINES);//middle polygon line
	glColor3ub(0,0,0);
    glVertex2f(0.08f,  0.28f);
    glVertex2f(0.08f, 0.38f);

    glVertex2f(0.08f, 0.38f);
    glVertex2f(0.05f, 0.4f);

    glVertex2f(0.05f, 0.4f);
    glVertex2f(-0.05f, 0.4f);

    glVertex2f(-0.05f, 0.4f);
    glVertex2f(-0.08f, 0.38f);

    glVertex2f(-0.08f, 0.38f);
    glVertex2f(-0.08f, 0.28f);

    glVertex2f(-0.08f, 0.28f);
    glVertex2f(0.08f,  0.28f);
    glEnd();






    glBegin(GL_POLYGON);//middle polygon 2
	glColor3ub(255,99,71);
    //glVertex2f(0.08f,  0.28f);
    glVertex2f(0.08f, 0.38f);
    glVertex2f(0.09f, 0.39f);

    //glVertex2f(0.09f, 0.39f);
    glVertex2f(0.05f, 0.42f);


    //glVertex2f(0.05f, 0.42f);
    glVertex2f(-0.05f, 0.42f);

    //glVertex2f(-0.05f, 0.42f);
    glVertex2f(-0.09f, 0.39f);

    //glVertex2f(-0.09f, 0.39f);
    glVertex2f(-0.08f, 0.38f);

    //glVertex2f(-0.07f, 0.39f);
   // glVertex2f(-0.08f, 0.38f);

    //glVertex2f(-0.08f, 0.38f);
    glVertex2f(-0.05f, 0.4f);

   // glVertex2f(0.05f, 0.4f);
    glVertex2f(0.08f, 0.38f);
    glEnd();


    glBegin(GL_LINES);//middle polygon 2
	glColor3ub(0,0,0);
    //glVertex2f(0.08f,  0.28f);
    glVertex2f(0.08f, 0.38f);
    glVertex2f(0.09f, 0.39f);

    glVertex2f(0.09f, 0.39f);
    glVertex2f(0.05f, 0.42f);


    glVertex2f(0.05f, 0.42f);
    glVertex2f(-0.05f, 0.42f);

    glVertex2f(-0.05f, 0.42f);
    glVertex2f(-0.09f, 0.39f);

    glVertex2f(-0.09f, 0.39f);
    glVertex2f(-0.08f, 0.38f);

    //glVertex2f(-0.07f, 0.39f);
   // glVertex2f(-0.08f, 0.38f);

    glVertex2f(-0.08f, 0.38f);
    glVertex2f(-0.05f, 0.4f);

    glVertex2f(-0.05f, 0.4f);
    glVertex2f(0.05f, 0.4f);

    glVertex2f(0.05f, 0.4f);
    glVertex2f(0.08f, 0.38f);
    glEnd();


    glBegin(GL_QUADS);//middle line
	glColor3ub(0,0,0);
    glVertex2f(0.006f,  0.54f);
    glVertex2f(0.006f, 0.58f);
    glVertex2f(-0.006f, 0.58f);
    glVertex2f(-0.006f, 0.54f);
    glEnd();



























    glBegin(GL_QUADS);// shiri
	glColor3ub(106,108,109);

	glVertex2f(0.24f, -0.26f);
	glVertex2f(0.14f, 0.0f);
    glVertex2f(-.14f, 0.0f);
    glVertex2f(-0.24,-0.26f);
    glEnd();

    glBegin(GL_LINES);// shiri
	glColor3ub(0,0,0);

	glVertex2f(0.24f, -0.26f);
	glVertex2f(0.14f, 0.0f);

	glVertex2f(0.14f, 0.0f);
    glVertex2f(-.14f, 0.0f);

    glVertex2f(-.14f, 0.0f);
    glVertex2f(-0.24,-0.26f);

    glVertex2f(-0.24,-0.26f);
    glVertex2f(0.24f, -0.26f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.144f, -0.02f);
	glVertex2f(0.144f, -0.015f);
    glVertex2f(-.144f, -0.015f);
    glVertex2f(-0.144,-0.02f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.148f, -0.045f);
	glVertex2f(0.148f, -0.04f);
    glVertex2f(-.148f, -0.04f);
    glVertex2f(-0.148,-0.045f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.162f, -0.065f);
	glVertex2f(0.162f, -0.06f);
    glVertex2f(-.162f, -0.06f);
    glVertex2f(-0.162,-0.065f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.172f, -0.085f);
	glVertex2f(0.172f, -0.08f);
    glVertex2f(-.172f, -0.08f);
    glVertex2f(-0.172,-0.085f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.182f, -0.105f);
	glVertex2f(0.182f, -0.1f);
    glVertex2f(-.182f, -0.1f);
    glVertex2f(-0.182,-0.105f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.18f, -0.115f);
	glVertex2f(0.18f, -0.12f);
    glVertex2f(-.18f, -0.12f);
    glVertex2f(-0.18,-0.115f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.19f, -0.14f);
	glVertex2f(0.19f, -0.13f);
    glVertex2f(-.19f, -0.13f);
    glVertex2f(-0.19,-0.14f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.2f, -0.16f);
	glVertex2f(0.2f, -0.15f);
    glVertex2f(-.2f, -0.15f);
    glVertex2f(-0.2,-0.16f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.21f, -0.18f);
	glVertex2f(0.21f, -0.17f);
    glVertex2f(-.21f, -0.17f);
    glVertex2f(-0.21,-0.18f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.22f, -0.2f);
	glVertex2f(0.22f, -0.19f);
    glVertex2f(-.22f, -0.19f);
    glVertex2f(-0.22,-0.2f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.225f, -0.22f);
	glVertex2f(0.225f, -0.21f);
    glVertex2f(-.225f, -0.21f);
    glVertex2f(-0.225,-0.22f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.23f, -0.24f);
	glVertex2f(0.23f, -0.23f);
    glVertex2f(-.23f, -0.23f);
    glVertex2f(-0.23,-0.24f);
    glEnd();


    //Fence-Left-1
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(-.25,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-2
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(.105,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-3
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(.46,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-4
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(.815,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-5
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(1.17,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-6
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(1.525,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-7
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(1.88,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();



    //FootWalk
    glBegin(GL_QUADS);
    glColor3ub(199,136,74);
    glVertex2f(-1,-.6);
    glVertex2f(-1,-.68);
    glVertex2f(1,-.68);
    glVertex2f(1,-.6);
    glEnd();

    glScalef(.5,.4,0);
    glTranslatef(1.6,-1.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();
glLoadIdentity();

    glScalef(.5,.4,0);
    glTranslatef(2.2,-1.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();
glLoadIdentity();


    glScalef(.5,.4,0);
    glTranslatef(-.05,-1.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();
glLoadIdentity();

    glScalef(.5,.4,0);
    glTranslatef(-0.7,-1.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();
glLoadIdentity();





            int i59;// tree

    GLfloat x59=0.4f; GLfloat y59=-0.44f; GLfloat radius59 =.024f;
	int triangleAmount59 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi59 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(60, 149, 76);
		glVertex2f(x59, y59); // center of circle
		for(i59 = 0; i59 <= triangleAmount59;i59++) {
			glVertex2f(
		            x59 + (radius59 * cos(i59 *  twicePi59 / triangleAmount59)),
			    y59 + (radius59 * sin(i59 * twicePi59 / triangleAmount59))
			);
		}
	glEnd();


	            int i60;//tree

    GLfloat x60=0.46f; GLfloat y60=-0.44f; GLfloat radius60 =.024f;
	int triangleAmount60 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi60 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(60, 149, 76);
		glVertex2f(x60, y60); // center of circle
		for(i60 = 0; i60 <= triangleAmount60;i60++) {
			glVertex2f(
		            x60 + (radius60 * cos(i60 *  twicePi60 / triangleAmount60)),
			    y60 + (radius60 * sin(i60 * twicePi60 / triangleAmount60))
			);
		}
	glEnd();

		            int i61;//tree

    GLfloat x61=0.43f; GLfloat y61=-0.42f; GLfloat radius61 =.036f;
	int triangleAmount61 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi61 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(61, 149, 76);
		glVertex2f(x61, y61); // center of circle
		for(i61 = 0; i61 <= triangleAmount61;i61++) {
			glVertex2f(
		            x61 + (radius61 * cos(i61 *  twicePi61 / triangleAmount61)),
			    y61 + (radius61 * sin(i61 * twicePi61 / triangleAmount61))
			);
		}
	glEnd();


		            int i62;//tree

    GLfloat x62=0.69f; GLfloat y62=-0.44f; GLfloat radius62 =.024f;
	int triangleAmount62 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi62 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(62, 149, 76);
		glVertex2f(x62, y62); // center of circle
		for(i62 = 0; i62 <= triangleAmount62;i62++) {
			glVertex2f(
		            x62 + (radius62 * cos(i62 *  twicePi62 / triangleAmount62)),
			    y62 + (radius62 * sin(i62 * twicePi62 / triangleAmount62))
			);
		}
	glEnd();


			            int i63;//tree

    GLfloat x63=0.76f; GLfloat y63=-0.44f; GLfloat radius63 =.024f;
	int triangleAmount63 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi63 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(63, 149, 76);
		glVertex2f(x63, y63); // center of circle
		for(i63 = 0; i63 <= triangleAmount63;i63++) {
			glVertex2f(
		            x63 + (radius63 * cos(i63 *  twicePi63 / triangleAmount63)),
			    y63 + (radius63 * sin(i63 * twicePi63 / triangleAmount63))
			);
		}
	glEnd();


				            int i64;//tree

    GLfloat x64=0.73f; GLfloat y64=-0.42f; GLfloat radius64 =.036f;
	int triangleAmount64 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi64 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(64, 149, 76);
		glVertex2f(x64, y64); // center of circle
		for(i64 = 0; i64 <= triangleAmount64;i64++) {
			glVertex2f(
		            x64 + (radius64 * cos(i64 *  twicePi64 / triangleAmount64)),
			    y64 + (radius64 * sin(i64 * twicePi64 / triangleAmount64))
			);
		}
	glEnd();


				            int i65;//tree

    GLfloat x65=-0.7f; GLfloat y65=-0.44f; GLfloat radius65 =.024f;
	int triangleAmount65 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi65 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(65, 149, 76);
		glVertex2f(x65, y65); // center of circle
		for(i65 = 0; i65 <= triangleAmount65;i65++) {
			glVertex2f(
		            x65 + (radius65 * cos(i65 *  twicePi65 / triangleAmount65)),
			    y65 + (radius65 * sin(i65 * twicePi65 / triangleAmount65))
			);
		}
	glEnd();

				            int i66;//tree

    GLfloat x66=-0.76f; GLfloat y66=-0.44f; GLfloat radius66 =.024f;
	int triangleAmount66 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi66 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(66, 149, 76);
		glVertex2f(x66, y66); // center of circle
		for(i66 = 0; i66 <= triangleAmount66;i66++) {
			glVertex2f(
		            x66 + (radius66 * cos(i66 *  twicePi66 / triangleAmount66)),
			    y66 + (radius66 * sin(i66 * twicePi66 / triangleAmount66))
			);
		}
	glEnd();


					            int i67;//tree

    GLfloat x67=-0.73f; GLfloat y67=-0.42f; GLfloat radius67 =.036f;
	int triangleAmount67 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi67 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(67, 149, 76);
		glVertex2f(x67, y67); // center of circle
		for(i67 = 0; i67 <= triangleAmount67;i67++) {
			glVertex2f(
		            x67 + (radius67 * cos(i67 *  twicePi67 / triangleAmount67)),
			    y67 + (radius67 * sin(i67 * twicePi67 / triangleAmount67))
			);
		}
	glEnd();


					            int i68;//tree

    GLfloat x68=-0.36f; GLfloat y68=-0.44f; GLfloat radius68 =.024f;
	int triangleAmount68 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi68 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(68, 149, 76);
		glVertex2f(x68, y68); // center of circle
		for(i68 = 0; i68 <= triangleAmount68;i68++) {
			glVertex2f(
		            x68 + (radius68 * cos(i68 *  twicePi68 / triangleAmount68)),
			    y68 + (radius68 * sin(i68 * twicePi68 / triangleAmount68))
			);
		}
	glEnd();


						            int i69;//tree

    GLfloat x69=-0.44f; GLfloat y69=-0.44f; GLfloat radius69 =.024f;
	int triangleAmount69 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi69 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(69, 149, 76);
		glVertex2f(x69, y69); // center of circle
		for(i69 = 0; i69 <= triangleAmount69;i69++) {
			glVertex2f(
		            x69 + (radius69 * cos(i69 *  twicePi69 / triangleAmount69)),
			    y69 + (radius69 * sin(i69 * twicePi69 / triangleAmount69))
			);
		}
	glEnd();

							            int i70;//tree

    GLfloat x70=-0.4f; GLfloat y70=-0.42f; GLfloat radius70 =.036f;
	int triangleAmount70 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi70 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(70, 149, 76);
		glVertex2f(x70, y70); // center of circle
		for(i70 = 0; i70 <= triangleAmount70;i70++) {
			glVertex2f(
		            x70 + (radius70 * cos(i70 *  twicePi70 / triangleAmount70)),
			    y70 + (radius70 * sin(i70 * twicePi70 / triangleAmount70))
			);
		}
	glEnd();

	    glBegin(GL_QUADS);
    glColor3ub(28, 26, 25);
    glVertex2f(-1,-.67);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glVertex2f(1,-.67);
    glEnd();
    //Road-Line
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(230,200,0);
    glVertex2f(-.98,-.835);
    glVertex2f(-.88,-.835);

    glVertex2f(-.83,-.835);
    glVertex2f(-.73,-.835);

    glVertex2f(-.68,-.835);
    glVertex2f(-.58,-.835);

    glVertex2f(-.53,-.835);
    glVertex2f(-.43,-.835);

    glVertex2f(-.38,-.835);
    glVertex2f(-.28,-.835);

    glVertex2f(-.23,-.835);
    glVertex2f(-.13,-.835);

    glVertex2f(-.08,-.835);
    glVertex2f(.02,-.835);

    glVertex2f(.07,-.835);
    glVertex2f(.17,-.835);

    glVertex2f(.22,-.835);
    glVertex2f(.32,-.835);

    glVertex2f(.37,-.835);
    glVertex2f(.47,-.835);

    glVertex2f(.52,-.835);
    glVertex2f(.62,-.835);

    glVertex2f(.67,-.835);
    glVertex2f(.77,-.835);

    glVertex2f(.82,-.835);
    glVertex2f(.92,-.835);

    glVertex2f(.97,-.835);
    glVertex2f(1,-.835);

    glEnd();



    glTranslatef(.735,-.099,0);
	glScalef(.6,.6,0);
    glBegin(GL_QUADS);//tree
	glColor3f(0.1f, .0f, 0.0f);

	glVertex2f(0.3f, -0.3f);
	glVertex2f(0.3f, 0.08f);
    glVertex2f(0.25f,0.08f);
    glVertex2f(0.25f,-0.3f);
    glEnd();

    glBegin(GL_TRIANGLES);
	glColor3f(0.1f, .0f, 0.0f);


	glVertex2f(0.30f,-0.3f);
    glVertex2f(0.25f,-0.3f);
    glVertex2f(0.20f,-0.38f);

    glVertex2f(0.36f,-0.38f);
    glVertex2f(0.3f,-0.3f);
    glVertex2f(0.25f,-0.3f);


    glVertex2f(0.3f, -0.3f);
    glVertex2f(0.25f, -0.3f);
    glVertex2f(0.275f,-0.40f);


    glEnd();

    glBegin(GL_QUADS);//branch
	glColor3f(0.1f, .0f, 0.0f);

	glVertex2f(0.3f, 0.08f);
	glVertex2f(0.38f, 0.3f);
	glVertex2f(0.38f, 0.3f);
    glVertex2f(0.28f,0.08f);

    glVertex2f(0.28f, 0.08f);
	glVertex2f(0.17f, 0.3f);
	glVertex2f(0.17f, 0.3f);
    glVertex2f(0.25f,0.08f);
    glEnd();

    glLoadIdentity();


    //2nd tree
    glTranslatef(-.735,-.099,0);
	glScalef(.6,.6,0);
    glBegin(GL_QUADS);//tree
	glColor3f(0.1f, .0f, 0.0f);

	glVertex2f(-0.3f, -0.3f);
	glVertex2f(-0.3f, 0.08f);
    glVertex2f(-0.25f,0.08f);
    glVertex2f(-0.25f,-0.3f);
    glEnd();

    glBegin(GL_TRIANGLES);
	glColor3f(0.1f, .0f, 0.0f);


	glVertex2f(-0.30f,-0.3f);
    glVertex2f(-0.25f,-0.3f);
    glVertex2f(-0.20f,-0.38f);

    glVertex2f(-0.36f,-0.38f);
    glVertex2f(-0.3f,-0.3f);
    glVertex2f(-0.25f,-0.3f);


    glVertex2f(-0.3f, -0.3f);
    glVertex2f(-0.25f, -0.3f);
    glVertex2f(-0.275f,-0.40f);


    glEnd();

    glBegin(GL_QUADS);//branch
	glColor3f(0.1f, .0f, 0.0f);

	glVertex2f(-0.3f, 0.08f);
	glVertex2f(-0.38f, 0.3f);
	glVertex2f(-0.38f, 0.3f);
    glVertex2f(-0.28f,0.08f);

    glVertex2f(-0.28f, 0.08f);
	glVertex2f(-0.17f, 0.3f);
	glVertex2f(-0.17f, 0.3f);
    glVertex2f(-0.25f,0.08f);
    glEnd();

    glLoadIdentity();



    int i71;//tree

    GLfloat x71=0.85f; GLfloat y71=0.02f; GLfloat radius71 =.05f;
	int triangleAmount71 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi71 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(71, 149, 76);
		glVertex2f(x71, y71); // center of circle
		for(i71 = 0; i71 <= triangleAmount71;i71++) {
			glVertex2f(
		            x71 + (radius71 * cos(i71 *  twicePi71 / triangleAmount71)),
			    y71 + (radius71 * sin(i71 * twicePi71 / triangleAmount71))
			);
		}
	glEnd();

	    int i72;//tree

    GLfloat x72=0.95f; GLfloat y72=0.02f; GLfloat radius72 =.05f;
	int triangleAmount72 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi72 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(72, 149, 76);
		glVertex2f(x72, y72); // center of circle
		for(i72 = 0; i72 <= triangleAmount72;i72++) {
			glVertex2f(
		            x72 + (radius72 * cos(i72 *  twicePi72 / triangleAmount72)),
			    y72 + (radius72 * sin(i72 * twicePi72 / triangleAmount72))
			);
		}
	glEnd();


		    int i73;//tree

    GLfloat x73=0.86f; GLfloat y73=0.084f; GLfloat radius73 =.05f;
	int triangleAmount73 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi73 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(73, 149, 76);
		glVertex2f(x73, y73); // center of circle
		for(i73 = 0; i73 <= triangleAmount73;i73++) {
			glVertex2f(
		            x73 + (radius73 * cos(i73 *  twicePi73 / triangleAmount73)),
			    y73 + (radius73 * sin(i73 * twicePi73 / triangleAmount73))
			);
		}
	glEnd();

			    int i74;//tree

    GLfloat x74=0.93f; GLfloat y74=0.084f; GLfloat radius74 =.05f;
	int triangleAmount74 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi74 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(74, 149, 76);
		glVertex2f(x74, y74); // center of circle
		for(i74 = 0; i74 <= triangleAmount74;i74++) {
			glVertex2f(
		            x74 + (radius74 * cos(i74 *  twicePi74 / triangleAmount74)),
			    y74 + (radius74 * sin(i74 * twicePi74 / triangleAmount74))
			);
		}
	glEnd();


				    int i75;//tree

    GLfloat x75=0.9f; GLfloat y75=0.06f; GLfloat radius75 =.04f;
	int triangleAmount75 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi75 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(75, 149, 76);
		glVertex2f(x75, y75); // center of circle
		for(i75 = 0; i75 <= triangleAmount75;i75++) {
			glVertex2f(
		            x75 + (radius75 * cos(i75 *  twicePi75 / triangleAmount75)),
			    y75 + (radius75 * sin(i75 * twicePi75 / triangleAmount75))
			);
		}
	glEnd();


	//2nd tree leaves

	int i76;//tree

    GLfloat x76=-0.85f; GLfloat y76=0.02f; GLfloat radius76 =.05f;
	int triangleAmount76 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi76 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(76, 149, 76);
		glVertex2f(x76, y76); // center of circle
		for(i76 = 0; i76 <= triangleAmount76;i76++) {
			glVertex2f(
		            x76 + (radius76 * cos(i76 *  twicePi76 / triangleAmount76)),
			    y76 + (radius76 * sin(i76 * twicePi76 / triangleAmount76))
			);
		}
	glEnd();

	    int i77;//tree

    GLfloat x77=-0.95f; GLfloat y77=0.02f; GLfloat radius77 =.05f;
	int triangleAmount77 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi77 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(77, 149, 76);
		glVertex2f(x77, y77); // center of circle
		for(i77 = 0; i77 <= triangleAmount77;i77++) {
			glVertex2f(
		            x77 + (radius77 * cos(i77 *  twicePi77 / triangleAmount77)),
			    y77 + (radius77 * sin(i77 * twicePi77 / triangleAmount77))
			);
		}
	glEnd();


		    int i80;//tree

    GLfloat x80=-0.86f; GLfloat y80=0.084f; GLfloat radius80 =.05f;
	int triangleAmount80 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi80 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(80, 149, 76);
		glVertex2f(x80, y80); // center of circle
		for(i80 = 0; i80 <= triangleAmount80;i80++) {
			glVertex2f(
		            x80 + (radius80 * cos(i80 *  twicePi80 / triangleAmount80)),
			    y80 + (radius80 * sin(i80 * twicePi80 / triangleAmount80))
			);
		}
	glEnd();

			    int i78;//tree

    GLfloat x78=-0.93f; GLfloat y78=0.084f; GLfloat radius78 =.05f;
	int triangleAmount78 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi78 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(78, 149, 76);
		glVertex2f(x78, y78); // center of circle
		for(i78 = 0; i78 <= triangleAmount78;i78++) {
			glVertex2f(
		            x78 + (radius78 * cos(i78 *  twicePi78 / triangleAmount78)),
			    y78 + (radius78 * sin(i78 * twicePi78 / triangleAmount78))
			);
		}
	glEnd();


				    int i79;//tree

    GLfloat x79=-0.9f; GLfloat y79=0.06f; GLfloat radius79 =.04f;
	int triangleAmount79 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi79 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(79, 149, 76);
		glVertex2f(x79, y79); // center of circle
		for(i79 = 0; i79 <= triangleAmount79;i79++) {
			glVertex2f(
		            x79 + (radius79 * cos(i79 *  twicePi79 / triangleAmount79)),
			    y79 + (radius79 * sin(i79 * twicePi79 / triangleAmount79))
			);
		}
	glEnd();

	//bird

	glPushMatrix();
	glTranslatef(position1,0.0f, 0.0f);

    int i81;//bird

    GLfloat x81=.182f; GLfloat y81=0.801f; GLfloat radius81 =.01f;
	int triangleAmount81 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi81 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(225, 225, 208);
		glVertex2f(x81, y81); // center of circle
		for(i81 = 0; i81 <= triangleAmount81;i81++) {
			glVertex2f(
		            x81 + (radius81 * cos(i81 *  twicePi81 / triangleAmount81)),
			    y81 + (radius81 * sin(i81 * twicePi81 / triangleAmount81))
			);
		}

	//glEnd();
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(0.1f,0.8f);
    glVertex2f(0.11f,0.79f);
    glVertex2f(0.12f,0.78f);
    glVertex2f(0.16f,0.77f);
    glVertex2f(0.19f,0.79f);
    glVertex2f(0.201f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.15f,0.8f);
    glVertex2f(0.14f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.144f,0.8f);
    glVertex2f(0.12f,0.83f);
    glEnd();
	/////2nd bird////
	glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.02f,0.8f);
    glVertex2f(-0.01f,0.79f);
    glVertex2f(0.0f,0.78f);
    glVertex2f(0.04f,0.77f);
    glVertex2f(0.07f,0.79f);
    glVertex2f(0.081f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.03f,0.8f);
    glVertex2f(0.02f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.024f,0.8f);
    glVertex2f(0.0f,0.83f);
    glEnd();

				    int i82;//bird

    GLfloat x82=0.062f; GLfloat y82=0.801f; GLfloat radius82 =.01f;
	int triangleAmount82 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi82 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(225, 225, 208);
		glVertex2f(x82, y82); // center of circle
		for(i82 = 0; i82 <= triangleAmount82;i82++) {
			glVertex2f(
		            x82 + (radius82 * cos(i82 *  twicePi82 / triangleAmount82)),
			    y82 + (radius82 * sin(i82 * twicePi82 / triangleAmount82))
			);
		}
	//glEnd();
	glEnd();
	/////3rd bird/////
	glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.72f,0.8f);
    glVertex2f(-0.71f,0.79f);
    glVertex2f(-0.7f,0.78f);
    glVertex2f(-0.66f,0.77f);
    glVertex2f(-0.63f,0.79f);
    glVertex2f(-0.619f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.67f,0.8f);
    glVertex2f(-0.68f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.676f,0.8f);
    glVertex2f(-0.7f,0.83f);
    glEnd();

    int i83;//bird

    GLfloat x83=-0.638f; GLfloat y83=0.801f; GLfloat radius83 =.01f;
	int triangleAmount83 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi83 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(225, 225, 208);
		glVertex2f(x83, y83); // center of circle
		for(i83 = 0; i83 <= triangleAmount83;i83++) {
			glVertex2f(
		            x83 + (radius83 * cos(i83 *  twicePi83 / triangleAmount83)),
			    y83 + (radius83 * sin(i83 * twicePi83 / triangleAmount83))
			);
		}
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.6f,0.8f);
    glVertex2f(-0.59f,0.79f);
    glVertex2f(-0.58f,0.78f);
    glVertex2f(-0.54f,0.77f);
    glVertex2f(-0.51f,0.79f);
    glVertex2f(-0.499f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.56f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.556f,0.8f);
    glVertex2f(-0.58f,0.83f);
    glEnd();

    //glLoadIdentity();
    glPopMatrix();

        //car starts


    glPushMatrix();
    glTranslatef(position2,0,0);
    {glTranslatef(0,-.08,0);

    glBegin(GL_QUADS);
    glColor3ub(66,135,245);
    glVertex2f(-.65,-.60);
    glVertex2f(-.65,-.68);
    glVertex2f(-.7,-.68);
    glVertex2f(-.7,-.62);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(66,135,245);
    glVertex2f(-.27,-.60);
    glVertex2f(-.27,-.68);
    glVertex2f(-.5,-.68);
    glVertex2f(-.5,-.60);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(66,135,245);
    glVertex2f(-.66,-.60);
    glVertex2f(-.66,-.68);
    glVertex2f(-.28,-.68);
    glVertex2f(-.28,-.62);
    glVertex2f(-.27,-.62);
    glVertex2f(-.28,-.60);
    glVertex2f(-.36,-.60);
    glVertex2f(-.40,-.54);
    glVertex2f(-.60,-.54);
    glVertex2f(-.62,-.62);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-.37,-.60);
    glVertex2f(-.40,-.55);
    glVertex2f(-.58,-.55);
    glVertex2f(-.62,-.60);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(-.40,-.55);
    glVertex2f(-.40,-.60);

    glVertex2f(-.58,-.55);
    glVertex2f(-.58,-.60);
    glEnd();
  //glLoadIdentity();
    }

    int i84;//car

    GLfloat x84=-0.58f; GLfloat y84=-0.68f; GLfloat radius84 =-.03f;
	int triangleAmount84 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi84 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);
		glVertex2f(x84, y84); // center of circle
		for(i84 = 0; i84 <= triangleAmount84;i84++) {
			glVertex2f(
		            x84 + (radius84 * cos(i84 *  twicePi84 / triangleAmount84)),
			    y84 + (radius84 * sin(i84 * twicePi84 / triangleAmount84))
			);
		}

		glEnd();


    int i85;//car

    GLfloat x85=-0.58f; GLfloat y85=-0.68f; GLfloat radius85 =.018f;
	int triangleAmount85 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi85 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(250, 250, 250);
		glVertex2f(x85, y85); // center of circle
		for(i85 = 0; i85 <= triangleAmount85;i85++) {
			glVertex2f(
		            x85 + (radius85 * cos(i85 *  twicePi85 / triangleAmount85)),
			    y85 + (radius85 * sin(i85 * twicePi85 / triangleAmount85))
			);
		}

		glEnd();


		int i86;//car

    GLfloat x86=-0.34f; GLfloat y86=-0.68f; GLfloat radius86 =.03f;
	int triangleAmount86 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi86 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);
		glVertex2f(x86, y86); // center of circle
		for(i86 = 0; i86 <= triangleAmount86;i86++) {
			glVertex2f(
		            x86 + (radius86 * cos(i86 *  twicePi86 / triangleAmount86)),
			    y86 + (radius86 * sin(i86 * twicePi86 / triangleAmount86))
			);
		}

		glEnd();


				int i87;//car

    GLfloat x87=-0.34f; GLfloat y87=-0.68f; GLfloat radius87 =.018f;
	int triangleAmount87 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi87 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(250, 250, 250);
		glVertex2f(x87, y87); // center of circle
		for(i87 = 0; i87 <= triangleAmount87;i87++) {
			glVertex2f(
		            x87 + (radius87 * cos(i87 *  twicePi87 / triangleAmount87)),
			    y87 + (radius87 * sin(i87 * twicePi87 / triangleAmount87))
			);
		}

		glEnd();
		//glLoadIdentity();
		glPopMatrix();


		//2nd car
    glPushMatrix();
    glTranslatef(position4,0.0f, 0.0f);
    glTranslatef(0,-.54,0);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(.04,-.24);
    glVertex2f(0.0,-.34);
    glVertex2f(0,-.42);
    glVertex2f(.4,-.42);
    glVertex2f(.4,-.24);
    glEnd();



    glBegin(GL_QUADS);
    glColor3ub(48,51,56);
    glVertex2f(.37,-.26);
    glVertex2f(.30,-.26);
    glVertex2f(.30,-.34);
    glVertex2f(.37,-.34);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(48,51,56);
    glVertex2f(.28,-.26);
    glVertex2f(.22,-.26);
    glVertex2f(.22,-.34);
    glVertex2f(.28,-.34);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(48,51,56);
    glVertex2f(.20,-.26);
    glVertex2f(.14,-.26);
    glVertex2f(.14,-.34);
    glVertex2f(.20,-.34);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(48,51,56);
    glVertex2f(.12,-.26);
    glVertex2f(.05,-.26);
    glVertex2f(.02,-.34);
    glVertex2f(.12,-.34);
    glEnd();

    glBegin(GL_QUADS);//red
    glColor3ub(224,41,25);
    glVertex2f(.22,-.38);
    glVertex2f(.22,-.40);
    glVertex2f(0.16,-.40);
    glVertex2f(0.16,-.38);
    glEnd();

    glBegin(GL_QUADS);//red
    glColor3ub(224,41,25);
    glVertex2f(.18,-.418);
    glVertex2f(.18,-.35);
    glVertex2f(0.2,-.35);
    glVertex2f(0.2,-.418);
    glEnd();
    //glLoadIdentity();

    int i96;//car2

    GLfloat x96=0.08f; GLfloat y96=-0.42f; GLfloat radius96 =.04f;
	int triangleAmount96 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi96 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x96, y96); // center of circle
		for(i96 = 0; i96 <= triangleAmount96;i96++) {
			glVertex2f(
		            x96 + (radius96 * cos(i96 *  twicePi96 / triangleAmount96)),
			    y96 + (radius96 * sin(i96 * twicePi96 / triangleAmount96))
			);
		}

		glEnd();

		    int i97;//car

    GLfloat x97=0.08f; GLfloat y97=-0.42f; GLfloat radius97 =.025f;
	int triangleAmount97 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi97 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 250, 250);
		glVertex2f(x97, y97); // center of circle
		for(i97 = 0; i97 <= triangleAmount97;i97++) {
			glVertex2f(
		            x97 + (radius97 * cos(i97 *  twicePi97 / triangleAmount97)),
			    y97 + (radius97 * sin(i97 * twicePi97 / triangleAmount97))
			);
		}

		glEnd();

		    int i98;//car

    GLfloat x98=0.3f; GLfloat y98=-0.42f; GLfloat radius98 =.04f;
	int triangleAmount98 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi98 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x98, y98); // center of circle
		for(i98 = 0; i98 <= triangleAmount98;i98++) {
			glVertex2f(
		            x98 + (radius98 * cos(i98 *  twicePi98 / triangleAmount98)),
			    y98 + (radius98 * sin(i98 * twicePi98 / triangleAmount98))
			);
		}

		glEnd();

    int i99;//car

    GLfloat x99=0.3f; GLfloat y99=-0.42f; GLfloat radius99 =.025f;
	int triangleAmount99 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi99 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 250, 250);
		glVertex2f(x99, y99); // center of circle
		for(i99 = 0; i99 <= triangleAmount99;i99++) {
			glVertex2f(
		            x99 + (radius99 * cos(i99 *  twicePi99 / triangleAmount99)),
			    y99 + (radius99 * sin(i99 * twicePi99 / triangleAmount99))
			);
		}

		glEnd();
		glLoadIdentity();
		glPopMatrix();



    //flower
    glPushMatrix();
    glTranslatef(.5,0,0);
    glScalef(.8,.8,0);
    glBegin(GL_LINES);
    glColor3ub(0, 255, 0);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();
    //glLoadIdentity();
    //glPopMatrix();

        int i100;//flower

    GLfloat x100=0.003f; GLfloat y100=-0.36f; GLfloat radius100 =.025f;
	int triangleAmount100 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi100 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 40, 60);
		glVertex2f(x100, y100); // center of circle
		for(i100 = 0; i100 <= triangleAmount100;i100++) {
			glVertex2f(
		            x100 + (radius100 * cos(i100 *  twicePi100 / triangleAmount100)),
			    y100 + (radius100 * sin(i100 * twicePi100 / triangleAmount100))
			);
		}

		glEnd();
		glLoadIdentity();
		glPopMatrix();


		    glPushMatrix();
    glTranslatef(-.5,0,0);
    glScalef(.8,.8,0);
    glBegin(GL_LINES);
    glColor3ub(0, 255, 0);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();
    //glLoadIdentity();
    //glPopMatrix();

        int i101;//flower

    GLfloat x101=0.003f; GLfloat y101=-0.36f; GLfloat radius101 =.025f;
	int triangleAmount101 = 101; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi101 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 40, 60);
		glVertex2f(x101, y101); // center of circle
		for(i101 = 0; i101 <= triangleAmount101;i101++) {
			glVertex2f(
		            x101 + (radius101 * cos(i101 *  twicePi101 / triangleAmount101)),
			    y101 + (radius101 * sin(i101 * twicePi101 / triangleAmount101))
			);
		}

		glEnd();
		glLoadIdentity();
		glPopMatrix();





    //flower end







	glFlush();  // Render now
}



//dayend

//night
void night() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)


   glBegin(GL_QUADS);// sky
	glColor3ub(148,145,145);

	glVertex2f(1.0f, -0.1f);
	glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f,1.0f);
    glVertex2f(-1.0,-0.1f);
    glEnd();


    //STAR
    glPointSize(2.0f);
    glBegin(GL_POINTS);
    glColor3ub(255,255,255);
//-----------------------
    glVertex2f(-.95,.7);
    glVertex2f(-.9,.65);

    glVertex2f(-.8,.75);

    glVertex2f(-.7,.7);
    glVertex2f(-.6,.72);

    glVertex2f(-.5,.67);
    glVertex2f(-.4,.73);

    glVertex2f(-.3,.68);
    glVertex2f(-.2,.7);

    glVertex2f(-.1,.74);
    glVertex2f(-.9,.79);

    //-----------------

    glVertex2f(-.95,.6);
    glVertex2f(-.9,.65);

    glVertex2f(-.8,.55);

    glVertex2f(-.7,.62);
    glVertex2f(-.6,.52);

    glVertex2f(-.5,.6);
    glVertex2f(-.4,.63);

    glVertex2f(-.3,.66);
    glVertex2f(-.2,.89);

    glVertex2f(-.8,.9);
    glVertex2f(-.5,.85);

    //------------------

    glVertex2f(.95,.7);
    glVertex2f(.9,.65);

    glVertex2f(.8,.75);

    glVertex2f(.7,.7);
    glVertex2f(.6,.72);

    glVertex2f(.5,.67);
    glVertex2f(.4,.73);

    glVertex2f(.3,.68);
    glVertex2f(.2,.7);

    glVertex2f(.1,.74);
    glVertex2f(.9,.79);

    //-----------------

    glVertex2f(.95,.6);
    glVertex2f(.9,.65);

    glVertex2f(.8,.55);

    glVertex2f(.7,.62);
    glVertex2f(.6,.52);

    glVertex2f(.5,.6);
    glVertex2f(.4,.63);

    glVertex2f(.3,.66);
    glVertex2f(.2,.89);

    glVertex2f(.8,.9);
    glVertex2f(.5,.85);


    //---------------


    glVertex2f(.7,.95);
    glVertex2f(.8,.95);

    glVertex2f(.75,.82);
    glVertex2f(.65,.92);

    glVertex2f(.07,.95);
    glVertex2f(.18,.95);

    glVertex2f(.0,.92);
    glVertex2f(-.07,.92);

    glVertex2f(.0,.82);
    glVertex2f(-.07,.72);


    glVertex2f(-.7,.95);

    glVertex2f(-.8,.95);

    glVertex2f(-.75,.82);
    glVertex2f(-.65,.92);


    glEnd();

	int i;//moon

	GLfloat x=-.4f; GLfloat y=.8f; GLfloat radius =.06f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glPushMatrix();
    glTranslatef(position,0,0);
	int i1;// cloud

	GLfloat x1=0.4f; GLfloat y1=0.88f; GLfloat radius1 =.07f;
	int triangleAmount1 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi1 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(192,192,192);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)),
			    y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1))
			);
		}
	glEnd();

	int i2;// cloud

	GLfloat x2=0.5f; GLfloat y2=0.84f; GLfloat radius2 =.06f;
	int triangleAmount2 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi2 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(192,192,192);
		glVertex2f(x2, y2); // center of circle
		for(i2 = 0; i2 <= triangleAmount2;i2++) {
			glVertex2f(
		            x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
			);
		}
	glEnd();

		int i3;// cloud

	GLfloat x3=0.6f; GLfloat y3=0.82f; GLfloat radius3 =.06f;
	int triangleAmount3 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi3 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(192,192,192);
		glVertex2f(x3, y3); // center of circle
		for(i3 = 0; i3 <= triangleAmount3;i3++) {
			glVertex2f(
		            x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
			    y3 + (radius3 * sin(i3 * twicePi3/ triangleAmount3))
			);
		}
	glEnd();

	    int i4;//cloud

	GLfloat x4=0.3f; GLfloat y4=0.75f; GLfloat radius4 =.07f;
	int triangleAmount4 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi4 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x4, y4); // center of circle
		for(i4 = 0; i4 <= triangleAmount4;i4++) {
			glVertex2f(
		            x4 + (radius4 * cos(i4 *  twicePi4 / triangleAmount4)),
			    y4 + (radius4 * sin(i4 * twicePi4 / triangleAmount4))
			);
		}
	glEnd();

	int i5;// cloud

	GLfloat x5=0.4f; GLfloat y5=0.75f; GLfloat radius5 =.07f;
	int triangleAmount5 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi5 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x5, y5); // center of circle
		for(i5 = 0; i5 <= triangleAmount5;i5++) {
			glVertex2f(
		            x5 + (radius5 * cos(i5 *  twicePi5 / triangleAmount5)),
			    y5 + (radius5 * sin(i5 * twicePi5 / triangleAmount5))
			);
		}
	glEnd();

		int i6;// cloud

	GLfloat x6=0.45f; GLfloat y6=0.78f; GLfloat radius6 =.06f;
	int triangleAmount6 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi6 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x6, y6); // center of circle
		for(i6 = 0; i6 <= triangleAmount6;i6++) {
			glVertex2f(
		            x6 + (radius6 * cos(i6 *  twicePi6 / triangleAmount6)),
			    y6 + (radius6 * sin(i6 * twicePi6 / triangleAmount6))
			);
		}
	glEnd();

	int i7;// cloud

	GLfloat x7=0.35f; GLfloat y7=0.81f; GLfloat radius7 =.06f;
	int triangleAmount7 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi7 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x7, y7); // center of circle
		for(i7 = 0; i7 <= triangleAmount7;i7++) {
			glVertex2f(
		            x7 + (radius7 * cos(i7 *  twicePi7 / triangleAmount7)),
			    y7 + (radius7 * sin(i7 * twicePi7 / triangleAmount7))
			);
		}
	glEnd();

		int i8;// cloud

	GLfloat x8=0.55f; GLfloat y8=0.75f; GLfloat radius8 =.07f;
	int triangleAmount8 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi8 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x8, y8); // center of circle
		for(i8 = 0; i8 <= triangleAmount8;i8++) {
			glVertex2f(
		            x8 + (radius8 * cos(i8 *  twicePi8 / triangleAmount8)),
			    y8 + (radius8 * sin(i8 * twicePi8 / triangleAmount8))
			);
		}
	glEnd();

	glTranslatef(-0.8,0,0);
	int i88;// cloud

	GLfloat x88=0.4f; GLfloat y88=0.88f; GLfloat radius88 =.07f;
	int triangleAmount88 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi88 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(192,192,192);
		glVertex2f(x88, y88); // center of circle
		for(i88 = 0; i88 <= triangleAmount;i88++) {
			glVertex2f(
		            x88 + (radius88 * cos(i88 *  twicePi88 / triangleAmount88)),
			    y88 + (radius88 * sin(i88 * twicePi88 / triangleAmount88))
			);
		}
	glEnd();

	int i89;// cloud

	GLfloat x89=0.5f; GLfloat y89=0.84f; GLfloat radius89 =.06f;
	int triangleAmount89 = 890; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi89 = 89.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(192,192,192);
		glVertex2f(x89, y89); // center of circle
		for(i89 = 0; i89 <= triangleAmount89;i89++) {
			glVertex2f(
		            x89 + (radius89 * cos(i89 *  twicePi89 / triangleAmount89)),
			    y89 + (radius89 * sin(i89 * twicePi89 / triangleAmount89))
			);
		}
	glEnd();

		int i90;// cloud

	GLfloat x90=0.6f; GLfloat y90=0.82f; GLfloat radius90 =.06f;
	int triangleAmount90 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi90 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(192,192,192);
		glVertex2f(x90, y90); // center of circle
		for(i90 = 0; i90 <= triangleAmount90;i90++) {
			glVertex2f(
		            x90 + (radius90 * cos(i90 *  twicePi90 / triangleAmount90)),
			    y90 + (radius90 * sin(i90 * twicePi90/ triangleAmount90))
			);
		}
	glEnd();

	    int i91;//cloud

	GLfloat x91=0.3f; GLfloat y91=0.75f; GLfloat radius91 =.07f;
	int triangleAmount91 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi91 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x91, y91); // center of circle
		for(i91 = 0; i91 <= triangleAmount91;i91++) {
			glVertex2f(
		            x91 + (radius91 * cos(i91 *  twicePi91 / triangleAmount91)),
			    y91 + (radius91 * sin(i91 * twicePi91 / triangleAmount91))
			);
		}
	glEnd();

	int i92;// cloud

	GLfloat x92=0.4f; GLfloat y92=0.75f; GLfloat radius92 =.07f;
	int triangleAmount92 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi92 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x92, y92); // center of circle
		for(i92 = 0; i92 <= triangleAmount92;i92++) {
			glVertex2f(
		            x92 + (radius92 * cos(i92 *  twicePi92 / triangleAmount92)),
			    y92 + (radius92 * sin(i92 * twicePi92 / triangleAmount92))
			);
		}
	glEnd();

		int i93;// cloud

	GLfloat x93=0.45f; GLfloat y93=0.78f; GLfloat radius93 =.06f;
	int triangleAmount93 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi93 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x93, y93); // center of circle
		for(i93 = 0; i93 <= triangleAmount93;i93++) {
			glVertex2f(
		            x93 + (radius93 * cos(i93 *  twicePi93 / triangleAmount93)),
			    y93 + (radius93 * sin(i93 * twicePi93 / triangleAmount93))
			);
		}
	glEnd();

	int i94;// cloud

	GLfloat x94=0.35f; GLfloat y94=0.81f; GLfloat radius94 =.06f;
	int triangleAmount94 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi94 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x94, y94); // center of circle
		for(i94 = 0; i94 <= triangleAmount94;i94++) {
			glVertex2f(
		            x94 + (radius94 * cos(i94 *  twicePi94 / triangleAmount94)),
			    y94 + (radius94 * sin(i94 * twicePi94 / triangleAmount94))
			);
		}
	glEnd();

		int i95;// cloud

	GLfloat x95=0.55f; GLfloat y95=0.75f; GLfloat radius95 =.07f;
	int triangleAmount95 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.95f; //radius
	GLfloat twicePi95 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(219,210,211);
		glVertex2f(x95, y95); // center of circle
		for(i95 = 0; i95 <= triangleAmount95;i95++) {
			glVertex2f(
		            x95 + (radius95 * cos(i95 *  twicePi95 / triangleAmount95)),
			    y95 + (radius95 * sin(i95 * twicePi95 / triangleAmount95))
			);
		}
	glEnd();



	glPopMatrix();
	//glLoadIdentity();naimul


    glBegin(GL_QUADS);//floor
	glColor3ub(56,50,47);

	glVertex2f(1.0f, -0.1f);
	glVertex2f(1.0f, -0.26f);
    glVertex2f(-1.0f,-0.26f);
    glVertex2f(-1.0,-0.1f);
    glEnd();

    glBegin(GL_QUADS);//floor small
	glColor3ub(97,19,14);

	glVertex2f(0.76f, -0.24f);
	glVertex2f(0.76f, -0.2f);
    glVertex2f(-.76f,-0.2f);
    glVertex2f(-0.76,-0.24f);
    glEnd();

    glBegin(GL_QUADS);//field
	glColor3ub(14,28,14);

	glVertex2f(1.0f, -0.6f);
	glVertex2f(1.0f, -0.26f);
    glVertex2f(-1.0f,-0.26f);
    glVertex2f(-1.0,-0.6f);
    glEnd();


	glBegin(GL_QUADS);//body
	glColor3ub(163,53,53);

	glVertex2f(0.76f, -0.2f);
	glVertex2f(0.76f, 0.24f);
    glVertex2f(-.76f,0.24f);
    glVertex2f(-0.76,-0.2f);
    glEnd();




    glBegin(GL_QUADS);//middle line 1
	glColor3ub(1,1,1);

	glVertex2f(0.76f, -0.04f);
	glVertex2f(0.76f, -0.03f);
    glVertex2f(-0.76f, -0.03f);
    glVertex2f(-0.76,-0.04f);
    glEnd();

    glBegin(GL_LINES);// middle line 2
	glColor3ub(1,1,1);

	glVertex2f(0.76f, -0.02f);
	glVertex2f(-0.76f, -0.02f);

    glEnd();

    glBegin(GL_LINES);//line right side
	glColor3ub(1,1,1);

	glVertex2f(0.18f, -0.04f);
    glVertex2f(0.18f,-0.2f);

	glVertex2f(0.20f, -0.04f);
    glVertex2f(0.20f,-0.2f);

    glVertex2f(0.271f, -0.04f);
    glVertex2f(0.271f,-0.2f);

    glVertex2f(0.291f, -0.04f);
    glVertex2f(0.291f,-0.2f);

    glVertex2f(0.362f, -0.04f);
    glVertex2f(0.362f,-0.2f);

    glVertex2f(0.382f, -0.04f);
    glVertex2f(0.382f,-0.2f);

    glVertex2f(0.453f, -0.04f);
    glVertex2f(0.453f,-0.2f);

    glVertex2f(0.473f, -0.04f);
    glVertex2f(0.473f,-0.2f);

    glVertex2f(0.544f, -0.04f);
    glVertex2f(0.544f,-0.2f);

    glVertex2f(0.58f, -0.04f);
    glVertex2f(0.58f,-0.2f);

    //dark pillar right
    glVertex2f(0.546f, -0.04f);
    glVertex2f(0.546f,-0.2f);

    glVertex2f(0.549f, -0.04f);
    glVertex2f(0.549f,-0.2f);

    glVertex2f(0.575f, -0.04f);
    glVertex2f(0.575f,-0.2f);

    glVertex2f(0.578f, -0.04f);
    glVertex2f(0.578f,-0.2f);

    //end



    glVertex2f(0.64f, -0.04f);
    glVertex2f(0.64f,-0.2f);

    glVertex2f(0.66f, -0.04f);
    glVertex2f(0.66f,-0.2f);

    glVertex2f(0.72f, -0.04f);
    glVertex2f(0.72f,-0.2f);
    glEnd();

    glBegin(GL_LINES);//dark pillar

    glVertex2f(0.722f, -0.04f);
    glVertex2f(0.722f,-0.2f);

    glVertex2f(0.724f, -0.04f);
    glVertex2f(0.724f,-0.2f);

    glVertex2f(0.726f, -0.04f);
    glVertex2f(0.726f,-0.2f);

    glVertex2f(0.756f, -0.04f);
    glVertex2f(0.756f,-0.2f);

    glVertex2f(0.758f, -0.04f);
    glVertex2f(0.758f,-0.2f);

    glVertex2f(0.76f, -0.04f);
    glVertex2f(0.76f,-0.2f);
    glEnd();


    //line left side
    glBegin(GL_LINES);
	glColor3ub(1,1,1);

	glVertex2f(-0.18f, -0.04f);//13
    glVertex2f(-0.18f,-0.2f);

	glVertex2f(-0.20f, -0.04f);//12
    glVertex2f(-0.20f,-0.2f);

    glVertex2f(-0.271f, -0.04f);//11
    glVertex2f(-0.271f,-0.2f);

    glVertex2f(-0.291f, -0.04f);//10
    glVertex2f(-0.291f,-0.2f);

    glVertex2f(-0.362f, -0.04f);//9
    glVertex2f(-0.362f,-0.2f);

    glVertex2f(-0.382f, -0.04f);//8
    glVertex2f(-0.382f,-0.2f);

    glVertex2f(-0.453f, -0.04f);//7
    glVertex2f(-0.453f,-0.2f);

    glVertex2f(-0.473f, -0.04f);//6
    glVertex2f(-0.473f,-0.2f);

    glVertex2f(-0.544f, -0.04f);//5
    glVertex2f(-0.544f,-0.2f);

    glVertex2f(-0.58f, -0.04f);//4
    glVertex2f(-0.58f,-0.2f);



    glVertex2f(-0.64f, -0.04f);//3
    glVertex2f(-0.64f,-0.2f);

    glVertex2f(-0.66f, -0.04f);//2
    glVertex2f(-0.66f,-0.2f);

    glVertex2f(-0.72f, -0.04f);//1
    glVertex2f(-0.72f,-0.2f);


    glEnd();

    glBegin(GL_LINES);//dark pillar
    glColor3ub(1,1,1);
    glVertex2f(-0.724f, -0.04f);
    glVertex2f(-0.724f,-0.2f);

    glVertex2f(-0.726f, -0.04f);
    glVertex2f(-0.726f,-0.2f);

    glVertex2f(-0.728f, -0.04f);
    glVertex2f(-0.728f,-0.2f);

    glVertex2f(-0.756f, -0.04f);
    glVertex2f(-0.756f,-0.2f);


    glVertex2f(-0.76f, -0.04f);
    glVertex2f(-0.76f,-0.2f);

    //end
    glEnd();

    //last roof middle
    glBegin(GL_QUADS);
    glColor3ub(163,53,53);
    glVertex2f(0.549f, 0.24f);
    glVertex2f(0.549f,0.28f);

    glVertex2f(-0.549f,0.28f);
    glVertex2f(-0.549f, 0.24f);


    //end
    glEnd();






   //last roof right
    glBegin(GL_QUADS);
    glColor3ub(163,53,53);
    glVertex2f(0.74f, 0.24f);
    glVertex2f(0.74f,0.3f);

    glVertex2f(0.567f,0.3f);
    glVertex2f(0.567f, 0.24f);


    //end
    glEnd();

    //last roof left
    glBegin(GL_QUADS);
    glColor3ub(163,53,53);
    glVertex2f(-0.74f, 0.24f);
    glVertex2f(-0.74f,0.3f);

    glVertex2f(-0.567f,0.3f);
    glVertex2f(-0.567f, 0.24f);


    //end
    glEnd();

    glBegin(GL_LINES);//extra line
    glColor3ub(1,1,1);
    glVertex2f(0.549f,0.28f);
    glVertex2f(-0.549f,0.28f);

    glVertex2f(0.567f,0.3f);//right
    glVertex2f(0.74f,0.3f);

    glVertex2f(-0.567f,0.3f);//left
    glVertex2f(-0.74f,0.3f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(163,53,53);

    glVertex2f(0.567f,0.3f);//right
    glVertex2f(0.6535f,0.36f);
    glVertex2f(0.74f,0.3f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(163,53,53);

    glVertex2f(-0.567f,0.3f);//left
    glVertex2f(-0.6535f,0.36f);
    glVertex2f(-0.74f,0.3f);

    glEnd();

    glBegin(GL_LINES);//extra line
    glColor3ub(1,1,1);

    glVertex2f(0.567f,0.3f);//right
    glVertex2f(0.74f,0.3f);

    glVertex2f(0.74f,0.3f);
    glVertex2f(0.6535f,0.36f);

    glVertex2f(0.567f,0.3f);//
    glVertex2f(0.6535f,0.36f);

    glVertex2f(0.74f,0.3f);
    glVertex2f(0.567f,0.3f);//

    glEnd();

        glBegin(GL_LINES);//extra line
    glColor3ub(1,1,1);

    glVertex2f(-0.567f,0.3f);//left
    glVertex2f(-0.74f,0.3f);

    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.6535f,0.36f);

    glVertex2f(-0.567f,0.3f);//
    glVertex2f(-0.6535f,0.36f);

    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.567f,0.3f);//

    glEnd();

    glBegin(GL_LINES);//triangle line right
    glColor3ub(1,1,1);

    glVertex2f(0.61f,0.3f);//right
    glVertex2f(0.6535f,0.36f);

    glVertex2f(0.6535f,0.36f);
    glVertex2f(0.644f,0.3f);

    glVertex2f(0.696f,0.3f);
    glVertex2f(0.6535f,0.36f);

    glEnd();

    glBegin(GL_LINES);//triangle line left
    glColor3ub(1,1,1);

    glVertex2f(-0.61f,0.3f);//right
    glVertex2f(-0.6535f,0.36f);

    glVertex2f(-0.6535f,0.36f);
    glVertex2f(-0.644f,0.3f);

    glVertex2f(-0.696f,0.3f);
    glVertex2f(-0.6535f,0.36f);

    glEnd();









     int i9;// window up right 1

	GLfloat x9=0.69f; GLfloat y9=-0.08f; GLfloat radius9 =.02f;
	int triangleAmount9 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi9 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x9, y9); // center of circle
		for(i9 = 0; i9 <= triangleAmount9;i9++) {
			glVertex2f(
		            x9 + (radius9 * cos(i9 *  twicePi9 / triangleAmount9)),
			    y9 + (radius9 * sin(i9 * twicePi9 / triangleAmount9))
			);
		}
	glEnd();

	glBegin(GL_QUADS);// window right 1
	glColor3ub(228,205,57);
    glVertex2f(0.71f, -0.2f);
    glVertex2f(0.71f,-0.08f);
    glVertex2f(0.67f, -0.08f);
    glVertex2f(0.67f,-0.2f);

    glEnd();

    glBegin(GL_QUADS);// window up right 1 corner
	glColor3ub(228,205,57);
    glVertex2f(0.71f, 0.02f);
    glVertex2f(0.71f,0.15f);
    glVertex2f(0.67f, 0.15f);
    glVertex2f(0.67f,0.02f);

    glEnd();

    glBegin(GL_QUADS);// window up left 1 corner
	glColor3ub(228,205,57);
    glVertex2f(-0.71f, 0.02f);
    glVertex2f(-0.71f,0.15f);
    glVertex2f(-0.67f, 0.15f);
    glVertex2f(-0.67f,0.02f);

    glEnd();


    int i10;// window up right 2

    GLfloat x10=0.61f; GLfloat y10=-0.08f; GLfloat radius10 =.02f;
	int triangleAmount10 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi10 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x10, y10); // center of circle
		for(i10 = 0; i10 <= triangleAmount10;i10++) {
			glVertex2f(
		            x10 + (radius10 * cos(i10 *  twicePi10 / triangleAmount10)),
			    y10 + (radius10 * sin(i10 * twicePi10 / triangleAmount10))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 2
	glColor3ub(228,205,57);
    glVertex2f(0.59f, 0.02f);
    glVertex2f(0.59f, 0.15f);
    glVertex2f(0.63f, 0.15f);
    glVertex2f(0.63f,0.02f);

    glEnd();

    glBegin(GL_QUADS);// window up right corner
	glColor3ub(228,205,57);
    glVertex2f(0.59f, -0.2f);
    glVertex2f(0.59f,-0.08f);
    glVertex2f(0.63f, -0.08f);
    glVertex2f(0.63f,-0.2f);

    glEnd();


    int i11;// window up right 3

    GLfloat x11=0.508f; GLfloat y11=-0.08f; GLfloat radius11 =.02f;
	int triangleAmount11 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi11 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x11, y11); // center of circle
		for(i11 = 0; i11 <= triangleAmount11;i11++) {
			glVertex2f(
		            x11 + (radius11 * cos(i11 *  twicePi11 / triangleAmount11)),
			    y11 + (radius11 * sin(i11 * twicePi11 / triangleAmount11))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 3
	glColor3ub(228,205,57);
    glVertex2f(0.488f, -0.2f);
    glVertex2f(0.488f,-0.08f);
    glVertex2f(0.528f, -0.08f);
    glVertex2f(0.528f,-0.2f);

    glEnd();

        int i12;// window up right 4

    GLfloat x12=0.4175f; GLfloat y12=-0.08f; GLfloat radius12 =.02f;
	int triangleAmount12 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi12 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x12, y12); // center of circle
		for(i12 = 0; i12 <= triangleAmount12;i12++) {
			glVertex2f(
		            x12 + (radius12 * cos(i12 *  twicePi12 / triangleAmount12)),
			    y12 + (radius12 * sin(i12 * twicePi12 / triangleAmount12))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 4
	glColor3ub(228,205,57);
    glVertex2f(0.438f, -0.2f);
    glVertex2f(0.438f,-0.08f);
    glVertex2f(0.397f, -0.08f);
    glVertex2f(0.397f,-0.2f);

    glEnd();

            int i13;// window up right 5

    GLfloat x13=0.3265f; GLfloat y13=-0.08f; GLfloat radius13 =.02f;
	int triangleAmount13 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi13 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x13, y13); // center of circle
		for(i13 = 0; i13 <= triangleAmount13;i13++) {
			glVertex2f(
		            x13 + (radius13 * cos(i13 *  twicePi13 / triangleAmount13)),
			    y13 + (radius13 * sin(i13 * twicePi13 / triangleAmount13))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 5
	glColor3ub(228,205,57);
    glVertex2f(0.347f, -0.2f);
    glVertex2f(0.347f,-0.08f);
    glVertex2f(0.306f, -0.08f);
    glVertex2f(0.306f,-0.2f);

    glEnd();

    int i14;// window up right 6

    GLfloat x14=0.2355f; GLfloat y14=-0.08f; GLfloat radius14 =.02f;
	int triangleAmount14 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi14 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x14, y14); // center of circle
		for(i14 = 0; i14 <= triangleAmount14;i14++) {
			glVertex2f(
		            x14 + (radius14 * cos(i14 *  twicePi14 / triangleAmount14)),
			    y14 + (radius14 * sin(i14 * twicePi14 / triangleAmount14))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 6
	glColor3ub(228,205,57);
    glVertex2f(0.256f, -0.2f);
    glVertex2f(0.256f,-0.08f);
    glVertex2f(0.215f, -0.08f);
    glVertex2f(0.215f,-0.2f);

    glEnd();


    int i15;// window up left 1

	GLfloat x15=-0.69f; GLfloat y15=-0.08f; GLfloat radius15 =.02f;
	int triangleAmount15 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi15 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x15, y15); // center of circle
		for(i15 = 0; i15 <= triangleAmount15;i15++) {
			glVertex2f(
		            x15 + (radius15 * cos(i15 *  twicePi15 / triangleAmount15)),
			    y15 + (radius15 * sin(i15 * twicePi15 / triangleAmount15))
			);
		}
	glEnd();

	glBegin(GL_QUADS);// window left 1
	glColor3ub(228,205,57);
    glVertex2f(-0.71f, -0.2f);
    glVertex2f(-0.71f,-0.08f);
    glVertex2f(-0.67f, -0.08f);
    glVertex2f(-0.67f,-0.2f);

    glEnd();


    int i16;// window up left 2

    GLfloat x16=-0.61f; GLfloat y16=-0.08f; GLfloat radius16 =.02f;
	int triangleAmount16 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi16 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x16, y16); // center of circle
		for(i16 = 0; i16 <= triangleAmount16;i16++) {
			glVertex2f(
		            x16 + (radius16 * cos(i16 *  twicePi16 / triangleAmount16)),
			    y16 + (radius16 * sin(i16 * twicePi16 / triangleAmount16))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window left 2
	glColor3ub(228,205,57);
    glVertex2f(-0.59f, -0.2f);
    glVertex2f(-0.59f,-0.08f);
    glVertex2f(-0.63f, -0.08f);
    glVertex2f(-0.63f,-0.2f);

    glEnd();

        glBegin(GL_QUADS);// window left up corner
	glColor3ub(228,205,57);
    glVertex2f(-0.59f, 0.02f);
    glVertex2f(-0.59f,0.15f);
    glVertex2f(-0.63f, 0.15f);
    glVertex2f(-0.63f,0.02f);

    glEnd();

    int i17;// window up right 3

    GLfloat x17=-0.508f; GLfloat y17=-0.08f; GLfloat radius17 =.02f;
	int triangleAmount17 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi17 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x17, y17); // center of circle
		for(i17 = 0; i17 <= triangleAmount17;i17++) {
			glVertex2f(
		            x17 + (radius17 * cos(i17 *  twicePi17 / triangleAmount17)),
			    y17 + (radius17 * sin(i17 * twicePi17 / triangleAmount17))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 3
	glColor3ub(228,205,57);
    glVertex2f(-0.488f, -0.2f);
    glVertex2f(-0.488f,-0.08f);
    glVertex2f(-0.528f, -0.08f);
    glVertex2f(-0.528f,-0.2f);

    glEnd();

        int i18;// window up left 4

    GLfloat x18=-0.4175f; GLfloat y18=-0.08f; GLfloat radius18 =.02f;
	int triangleAmount18 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi18 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x18, y18); // center of circle
		for(i18 = 0; i18 <= triangleAmount18;i18++) {
			glVertex2f(
		            x18 + (radius18 * cos(i18 *  twicePi18 / triangleAmount18)),
			    y18 + (radius18 * sin(i18 * twicePi18 / triangleAmount18))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window left 4
	glColor3ub(228,205,57);
    glVertex2f(-0.438f, -0.2f);
    glVertex2f(-0.438f,-0.08f);
    glVertex2f(-0.397f, -0.08f);
    glVertex2f(-0.397f,-0.2f);

    glEnd();

    int i19;// window up left 5

    GLfloat x19=-0.3265f; GLfloat y19=-0.08f; GLfloat radius19 =.02f;
	int triangleAmount19 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi19 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x19, y19); // center of circle
		for(i19 = 0; i19 <= triangleAmount19;i19++) {
			glVertex2f(
		            x19 + (radius19 * cos(i19 *  twicePi19 / triangleAmount19)),
			    y19 + (radius19 * sin(i19 * twicePi19 / triangleAmount19))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window left 5
	glColor3ub(228,205,57);
    glVertex2f(-0.347f, -0.2f);
    glVertex2f(-0.347f,-0.08f);
    glVertex2f(-0.306f, -0.08f);
    glVertex2f(-0.306f,-0.2f);

    glEnd();

    int i20;// window up left 6

    GLfloat x20=-0.2355f; GLfloat y20=-0.08f; GLfloat radius20 =.02f;
	int triangleAmount20 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi20 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x20, y20); // center of circle
		for(i20 = 0; i20 <= triangleAmount20;i20++) {
			glVertex2f(
		            x20 + (radius20 * cos(i20 *  twicePi20 / triangleAmount20)),
			    y20 + (radius20 * sin(i20 * twicePi20 / triangleAmount20))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window left 6
	glColor3ub(228,205,57);
    glVertex2f(-0.256f, -0.2f);
    glVertex2f(-0.256f,-0.08f);
    glVertex2f(-0.215f, -0.08f);
    glVertex2f(-0.215f,-0.2f);

    glEnd();

    glBegin(GL_LINES); // right up stair 1
    glColor3ub(0,0,0);

    glVertex2f(0.472f, -0.02f);
    glVertex2f(0.472f,0.2f);

    glVertex2f(0.472f,0.2f);
    glVertex2f(0.454f,0.2f);

    glVertex2f(0.454f,0.2f);
    glVertex2f(0.454f, -0.02f);

    glVertex2f(0.454f, -0.02f);
    glVertex2f(0.472f, -0.02f);



    glEnd();

    //lower beam 1
    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(0.475f, -0.02f);
    glVertex2f(0.475f, 0.0f);

    glVertex2f(0.475f, 0.0f);
    glVertex2f(0.451f, 0.0f);

    glVertex2f(0.451f, 0.0f);
    glVertex2f(0.451f, -0.02f);

    glVertex2f(0.475f, -0.02f);
    glVertex2f(0.451f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // right up stair 2
    glColor3ub(0,0,0);

    glVertex2f(0.381f, -0.02f);
    glVertex2f(0.381f, 0.2f);

    glVertex2f(0.381f, 0.2f);
    glVertex2f(0.363f, 0.2f);

    glVertex2f(0.363f, 0.2f);
    glVertex2f(0.363f, -0.02f);

    glVertex2f(0.363f, -0.02f);
    glVertex2f(0.381f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // right beam 2
    glColor3ub(0,0,0);

    glVertex2f(0.384f, -0.02f);
    glVertex2f(0.384f, 0.0f);

    glVertex2f(0.384f, 0.0f);
    glVertex2f(0.36f, 0.00f);

    glVertex2f(0.36f, 0.0f);
    glVertex2f(0.36f,-0.02f);

    glVertex2f(0.36f,-0.02f);
    glVertex2f(0.384f, -0.02f);

    glEnd();


    glBegin(GL_LINES); // right up stair 3
    glColor3ub(0,0,0);

    glVertex2f(0.29f, -0.02f);
    glVertex2f(0.29f, 0.2f);

    glVertex2f(0.29f, 0.2f);
    glVertex2f(0.27f, 0.2f);

    glVertex2f(0.27f, 0.2f);
    glVertex2f(0.27f, -0.02f);

    glVertex2f(0.29f, -0.02f);
    glVertex2f(0.29f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // right beam 3
    glColor3ub(0,0,0);

    glVertex2f(0.293f, -0.02f);
    glVertex2f(0.293f, 0.0f);

    glVertex2f(0.293f, 0.0f);
    glVertex2f(0.269f, 0.0f);

    glVertex2f(0.269f, 0.0f);
    glVertex2f(0.269f,-0.02f);

    glVertex2f(0.269f,-0.02f);
    glVertex2f(0.293f, -0.02f);

    glEnd();



    glBegin(GL_LINES); // right up stair 4
    glColor3ub(0,0,0);

    glVertex2f(0.199f, -0.02f);
    glVertex2f(0.199f, 0.2f);

    glVertex2f(0.199f, 0.2f);
    glVertex2f(0.181f, 0.2f);

    glVertex2f(0.181f, 0.2f);
    glVertex2f(0.181f, -0.02f);

    glVertex2f(0.199f, -0.02f);
    glVertex2f(0.199f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // right beam 4
    glColor3ub(0,0,0);

    glVertex2f(0.202f, -0.02f);
    glVertex2f(0.202f, 0.0f);

    glVertex2f(0.202f, 0.0f);
    glVertex2f(0.178f, 0.0f);

    glVertex2f(0.178f, 0.0f);
    glVertex2f(0.178f, -0.02f);

    glVertex2f(0.178f, -0.02f);
    glVertex2f(0.202f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // left up stair 1
    glColor3ub(0,0,0);

    glVertex2f(-0.472f, -0.02f);
    glVertex2f(-0.472f,0.2f);

    glVertex2f(-0.472f,0.2f);
    glVertex2f(-0.454f,0.2f);

    glVertex2f(-0.454f,0.2f);
    glVertex2f(-0.454f, -0.02f);

    glVertex2f(-0.454f, -0.02f);
    glVertex2f(-0.472f, -0.02f);



    glEnd();

    //lower beam 1
    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(-0.475f, -0.02f);
    glVertex2f(-0.475f, 0.0f);

    glVertex2f(-0.475f, 0.0f);
    glVertex2f(-0.451f, 0.0f);

    glVertex2f(-0.451f, 0.0f);
    glVertex2f(-0.451f, -0.02f);

    glVertex2f(-0.475f, -0.02f);
    glVertex2f(-0.451f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // left up stair 2
    glColor3ub(0,0,0);

    glVertex2f(-0.381f, -0.02f);
    glVertex2f(-0.381f, 0.2f);

    glVertex2f(-0.381f, 0.2f);
    glVertex2f(-0.363f, 0.2f);

    glVertex2f(-0.363f, 0.2f);
    glVertex2f(-0.363f, -0.02f);

    glVertex2f(-0.363f, -0.02f);
    glVertex2f(-0.381f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // left beam 2
    glColor3ub(0,0,0);

    glVertex2f(0.384f, -0.02f);
    glVertex2f(0.384f, 0.0f);

    glVertex2f(-0.384f, 0.0f);
    glVertex2f(-0.36f, 0.00f);

    glVertex2f(-0.36f, 0.0f);
    glVertex2f(-0.36f,-0.02f);

    glVertex2f(-0.36f,-0.02f);
    glVertex2f(-0.384f, -0.02f);

    glEnd();


    glBegin(GL_LINES); // left up stair 3
    glColor3ub(0,0,0);

    glVertex2f(-0.29f, -0.02f);
    glVertex2f(-0.29f, 0.2f);

    glVertex2f(-0.29f, 0.2f);
    glVertex2f(-0.27f, 0.2f);

    glVertex2f(-0.27f, 0.2f);
    glVertex2f(-0.27f, -0.02f);

    glVertex2f(-0.29f, -0.02f);
    glVertex2f(-0.29f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // left beam 3
    glColor3ub(0,0,0);

    glVertex2f(-0.293f, -0.02f);
    glVertex2f(-0.293f, 0.0f);

    glVertex2f(-0.293f, 0.0f);
    glVertex2f(-0.269f, 0.0f);

    glVertex2f(-0.269f, 0.0f);
    glVertex2f(-0.269f,-0.02f);

    glVertex2f(-0.269f,-0.02f);
    glVertex2f(-0.293f, -0.02f);

    glEnd();



    glBegin(GL_LINES); // left up stair 4
    glColor3ub(0,0,0);

    glVertex2f(-0.199f, -0.02f);
    glVertex2f(-0.199f, 0.2f);

    glVertex2f(-0.199f, 0.2f);
    glVertex2f(-0.181f, 0.2f);

    glVertex2f(-0.181f, 0.2f);
    glVertex2f(-0.181f, -0.02f);

    glVertex2f(-0.199f, -0.02f);
    glVertex2f(-0.199f, -0.02f);

    glEnd();

    glBegin(GL_LINES); // left beam 4
    glColor3ub(0,0,0);

    glVertex2f(-0.202f, -0.02f);
    glVertex2f(-0.202f, 0.0f);

    glVertex2f(-0.202f, 0.0f);
    glVertex2f(-0.178f, 0.0f);

    glVertex2f(-0.178f, 0.0f);
    glVertex2f(-0.178f, -0.02f);

    glVertex2f(-0.178f, -0.02f);
    glVertex2f(-0.202f, -0.02f);

    glEnd();


    glBegin(GL_QUADS);// window right 3
	glColor3ub(228,205,57);
    glVertex2f(0.488f, -0.2f);
    glVertex2f(0.488f,-0.08f);
    glVertex2f(0.528f, -0.08f);
    glVertex2f(0.528f,-0.2f);

    glEnd();

        int i21;// upstair window up right 4

    GLfloat x21=0.4175f; GLfloat y21=0.14f; GLfloat radius21 =.02f;
	int triangleAmount21 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi21 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x21, y21); // center of circle
		for(i21 = 0; i21 <= triangleAmount21;i21++) {
			glVertex2f(
		            x21 + (radius21 * cos(i21 *  twicePi21 / triangleAmount21)),
			    y21 + (radius21 * sin(i21 * twicePi21 / triangleAmount21))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 4
	glColor3ub(228,205,57);
    glVertex2f(0.438f, 0.0f);
    glVertex2f(0.438f, 0.14f);
    glVertex2f(0.397f, 0.14f);
    glVertex2f(0.397f, 0.0f);

    glEnd();


    int i22;// upstair window up right 5

    GLfloat x22=0.3265f; GLfloat y22=0.14f; GLfloat radius22 =.02f;
	int triangleAmount22 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi22 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x22, y22); // center of circle
		for(i22 = 0; i22 <= triangleAmount22;i22++) {
			glVertex2f(
		            x22 + (radius22 * cos(i22 *  twicePi22 / triangleAmount22)),
			    y22 + (radius22 * sin(i22 * twicePi22 / triangleAmount22))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 5
	glColor3ub(228,205,57);
    glVertex2f(0.347f, 0.0f);
    glVertex2f(0.347f,0.14f);
    glVertex2f(0.306f, 0.14f);
    glVertex2f(0.306f,0.0f);

    glEnd();

    int i23;// upstair window up right 6

    GLfloat x23=0.2355f; GLfloat y23=0.14f; GLfloat radius23 =.02f;
	int triangleAmount23 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi23 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x23, y23); // center of circle
		for(i23 = 0; i23 <= triangleAmount23;i23++) {
			glVertex2f(
		            x23 + (radius23 * cos(i23 *  twicePi23 / triangleAmount23)),
			    y23 + (radius23 * sin(i23 * twicePi23 / triangleAmount23))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window right 6
	glColor3ub(228,205,57);
    glVertex2f(0.256f,  0.0f);
    glVertex2f(0.256f, 0.14f);
    glVertex2f(0.215f, 0.14f);
    glVertex2f(0.215f, 0.0f);

    glEnd();


    int i24;// upstair window up left 4

    GLfloat x24=-0.4175f; GLfloat y24=0.14f; GLfloat radius24 =.02f;
	int triangleAmount24 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi24 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x24, y24); // center of circle
		for(i24 = 0; i24 <= triangleAmount21;i24++) {
			glVertex2f(
		            x24 + (radius24 * cos(i24 *  twicePi24 / triangleAmount24)),
			    y24 + (radius24 * sin(i24 * twicePi24 / triangleAmount24))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window left 4
	glColor3ub(228,205,57);
    glVertex2f(-0.438f, 0.0f);
    glVertex2f(-0.438f, 0.14f);
    glVertex2f(-0.397f, 0.14f);
    glVertex2f(-0.397f, 0.0f);

    glEnd();


    int i25;// upstair window up left 5

    GLfloat x25=-0.3265f; GLfloat y25=0.14f; GLfloat radius25 =.02f;
	int triangleAmount25 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi25 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x25, y25); // center of circle
		for(i25 = 0; i25 <= triangleAmount25;i25++) {
			glVertex2f(
		            x25 + (radius25 * cos(i25 *  twicePi25 / triangleAmount25)),
			    y25 + (radius25 * sin(i25 * twicePi25 / triangleAmount25))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window left 5
	glColor3ub(228,205,57);
    glVertex2f(-0.347f, 0.0f);
    glVertex2f(-0.347f,0.14f);
    glVertex2f(-0.306f, 0.14f);
    glVertex2f(-0.306f,0.0f);

    glEnd();

    int i26;// upstair window up left 6

    GLfloat x26=-0.2355f; GLfloat y26=0.14f; GLfloat radius26 =.02f;
	int triangleAmount26 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi26 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x26, y26); // center of circle
		for(i26 = 0; i26 <= triangleAmount26;i26++) {
			glVertex2f(
		            x26 + (radius26 * cos(i26 *  twicePi26 / triangleAmount26)),
			    y26 + (radius26 * sin(i26 * twicePi26 / triangleAmount26))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window left 6
	glColor3ub(228,205,57);
    glVertex2f(-0.256f,  0.0f);
    glVertex2f(-0.256f, 0.14f);
    glVertex2f(-0.215f, 0.14f);
    glVertex2f(-0.215f, 0.0f);

    glEnd();


    //middle

        int i27;// upstair window right

    GLfloat x27=0.15f; GLfloat y27=0.14f; GLfloat radius27 =.02f;
	int triangleAmount27 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi27 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x27, y27); // center of circle
		for(i27 = 0; i27 <= triangleAmount27;i27++) {
			glVertex2f(
		            x27 + (radius27 * cos(i27 *  twicePi27 / triangleAmount27)),
			    y27 + (radius27 * sin(i27 * twicePi27 / triangleAmount27))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// window left 6
	glColor3ub(228,205,57);
    glVertex2f(0.17f,  0.0f);
    glVertex2f(0.17f, 0.14f);
    glVertex2f(0.13f, 0.14f);
    glVertex2f(0.13f, 0.0f);

    glEnd();

            int i28;// upstair window left

    GLfloat x28=-0.15f; GLfloat y28=0.14f; GLfloat radius28 =.02f;
	int triangleAmount28 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi28 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x28, y28); // center of circle
		for(i28 = 0; i28 <= triangleAmount28;i28++) {
			glVertex2f(
		            x28 + (radius28 * cos(i28 *  twicePi28 / triangleAmount28)),
			    y28 + (radius28 * sin(i28 * twicePi28 / triangleAmount28))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// middle
	glColor3ub(228,205,57);
    glVertex2f(-0.17f,  0.0f);
    glVertex2f(-0.17f, 0.14f);
    glVertex2f(-0.13f, 0.14f);
    glVertex2f(-0.13f, 0.0f);

    glEnd();



    glBegin(GL_LINES);// upper line
	glColor3ub(1,1,1);
    glVertex2f(0.76f, 0.2f);
	glVertex2f(0.76f, 0.24f);

	glVertex2f(0.76f, 0.24f);
	glVertex2f(-0.76f, 0.24f);

    glVertex2f(-0.76f, 0.24f);
    glVertex2f(-0.76, 0.2f);

    glVertex2f(-0.76, 0.2f);
    glVertex2f(0.76f, 0.2f);

    //some design
    glVertex2f(0.76f, 0.205f);
	glVertex2f(-0.76f, 0.205f);

	glVertex2f(0.76f, 0.21f);
	glVertex2f(-0.76f, 0.21f);

    glEnd();


    int i29;// bubles

    GLfloat x29=0.51f; GLfloat y29=0.225f; GLfloat radius29 =.008f;
	int triangleAmount29 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi29 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x29, y29); // center of circle
		for(i29 = 0; i29 <= triangleAmount29;i29++) {
			glVertex2f(
		            x29 + (radius29 * cos(i29 *  twicePi29 / triangleAmount29)),
			    y29 + (radius29 * sin(i29 * twicePi29 / triangleAmount29))
			);
		}
	glEnd();

	    int i30;// bubles

    GLfloat x30=0.49f; GLfloat y30=0.225f; GLfloat radius30 =.008f;
	int triangleAmount30 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi30 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x30, y30); // center of circle
		for(i30 = 0; i30 <= triangleAmount30;i30++) {
			glVertex2f(
		            x30 + (radius30 * cos(i30 *  twicePi30 / triangleAmount30)),
			    y30 + (radius30 * sin(i30 * twicePi30 / triangleAmount30))
			);
		}
	glEnd();

    int i31;// bubles

    GLfloat x31=0.47f; GLfloat y31=0.225f; GLfloat radius31 =.008f;
	int triangleAmount31 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi31 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x31, y31); // center of circle
		for(i31 = 0; i31 <= triangleAmount31;i31++) {
			glVertex2f(
		            x31 + (radius31 * cos(i31 *  twicePi31 / triangleAmount31)),
			    y31 + (radius31 * sin(i31 * twicePi31 / triangleAmount31))
			);
		}
	glEnd();

    int i32;// bubles

    GLfloat x32=0.42f; GLfloat y32=0.225f; GLfloat radius32 =.008f;
	int triangleAmount32 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi32 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x32, y32); // center of circle
		for(i32 = 0; i32 <= triangleAmount32;i32++) {
			glVertex2f(
		            x32 + (radius32 * cos(i32 *  twicePi32 / triangleAmount32)),
			    y32 + (radius32 * sin(i32 * twicePi32 / triangleAmount32))
			);
		}
	glEnd();

	    int i33;// bubles

    GLfloat x33=0.4f; GLfloat y33=0.225f; GLfloat radius33 =.008f;
	int triangleAmount33 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi33 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x33, y33); // center of circle
		for(i33 = 0; i33 <= triangleAmount33;i33++) {
			glVertex2f(
		            x33 + (radius33 * cos(i33 *  twicePi33 / triangleAmount33)),
			    y33 + (radius33 * sin(i33 * twicePi33 / triangleAmount33))
			);
		}
	glEnd();


    int i34;// bubles

    GLfloat x34=0.38f; GLfloat y34=0.225f; GLfloat radius34 =.008f;
	int triangleAmount34 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi34 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x34, y34); // center of circle
		for(i34 = 0; i34 <= triangleAmount34;i34++) {
			glVertex2f(
		            x34 + (radius34 * cos(i34 *  twicePi34 / triangleAmount34)),
			    y34 + (radius34 * sin(i34 * twicePi34 / triangleAmount34))
			);
		}
	glEnd();

    int i35;// bubles

    GLfloat x35=0.33f; GLfloat y35=0.225f; GLfloat radius35 =.008f;
	int triangleAmount35 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi35 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x35, y35); // center of circle
		for(i35 = 0; i35 <= triangleAmount35;i35++) {
			glVertex2f(
		            x35 + (radius35 * cos(i35 *  twicePi35 / triangleAmount35)),
			    y35 + (radius35 * sin(i35 * twicePi35 / triangleAmount35))
			);
		}
	glEnd();

	    int i36;// bubles

    GLfloat x36=0.31f; GLfloat y36=0.225f; GLfloat radius36 =.008f;
	int triangleAmount36 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi36 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x36, y36); // center of circle
		for(i36 = 0; i36 <= triangleAmount36;i36++) {
			glVertex2f(
		            x36 + (radius36 * cos(i36 *  twicePi36 / triangleAmount36)),
			    y36 + (radius36 * sin(i36 * twicePi36 / triangleAmount36))
			);
		}
	glEnd();

	    int i37;// bubles

    GLfloat x37=0.29f; GLfloat y37=0.225f; GLfloat radius37 =.008f;
	int triangleAmount37 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi37 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x37, y37); // center of circle
		for(i37 = 0; i37 <= triangleAmount37;i37++) {
			glVertex2f(
		            x37 + (radius37 * cos(i37 *  twicePi37 / triangleAmount37)),
			    y37 + (radius37 * sin(i37 * twicePi37 / triangleAmount37))
			);
		}
	glEnd();

    int i38;// bubles

    GLfloat x38=0.24f; GLfloat y38=0.225f; GLfloat radius38 =.008f;
	int triangleAmount38 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi38 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x38, y38); // center of circle
		for(i38 = 0; i38 <= triangleAmount38;i38++) {
			glVertex2f(
		            x38 + (radius38 * cos(i38 *  twicePi38 / triangleAmount38)),
			    y38 + (radius38 * sin(i38 * twicePi38 / triangleAmount38))
			);
		}
	glEnd();

    int i39;// bubles

    GLfloat x39=0.22f; GLfloat y39=0.225f; GLfloat radius39 =.008f;
	int triangleAmount39 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi39 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x39, y39); // center of circle
		for(i39 = 0; i39 <= triangleAmount39;i39++) {
			glVertex2f(
		            x39 + (radius39 * cos(i39 *  twicePi39 / triangleAmount39)),
			    y39 + (radius39 * sin(i39 * twicePi39 / triangleAmount39))
			);
		}
	glEnd();

    int i40;// bubles

    GLfloat x40=0.2f; GLfloat y40=0.225f; GLfloat radius40 =.008f;
	int triangleAmount40 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi40 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x40, y40); // center of circle
		for(i40 = 0; i40 <= triangleAmount40;i40++) {
			glVertex2f(
		            x40 + (radius40 * cos(i40 *  twicePi40 / triangleAmount40)),
			    y40 + (radius40 * sin(i40 * twicePi40 / triangleAmount40))
			);
		}
	glEnd();

    int i41;// bubles

    GLfloat x41=-0.51f; GLfloat y41=0.225f; GLfloat radius41 =.008f;
	int triangleAmount41 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi41 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x41, y41); // center of circle
		for(i41 = 0; i41 <= triangleAmount41;i41++) {
			glVertex2f(
		            x41 + (radius41 * cos(i41 *  twicePi41 / triangleAmount41)),
			    y41 + (radius41 * sin(i41 * twicePi41 / triangleAmount41))
			);
		}
	glEnd();

	    int i42;// bubles

    GLfloat x42=-0.49f; GLfloat y42=0.225f; GLfloat radius42 =.008f;
	int triangleAmount42 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi42 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x42, y42); // center of circle
		for(i42 = 0; i42 <= triangleAmount42;i42++) {
			glVertex2f(
		            x42 + (radius42 * cos(i42 *  twicePi42 / triangleAmount42)),
			    y42 + (radius42 * sin(i42 * twicePi42 / triangleAmount42))
			);
		}
	glEnd();

    int i43;// bubles

    GLfloat x43=-0.47f; GLfloat y43=0.225f; GLfloat radius43 =.008f;
	int triangleAmount43 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi43 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x43, y43); // center of circle
		for(i43 = 0; i43 <= triangleAmount43;i43++) {
			glVertex2f(
		            x43 + (radius43 * cos(i43 *  twicePi43 / triangleAmount43)),
			    y43 + (radius43 * sin(i43 * twicePi43 / triangleAmount43))
			);
		}
	glEnd();

    int i44;// bubles

    GLfloat x44=-0.42f; GLfloat y44=0.225f; GLfloat radius44 =.008f;
	int triangleAmount44 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi44 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x44, y44); // center of circle
		for(i44 = 0; i44 <= triangleAmount44;i44++) {
			glVertex2f(
		            x44 + (radius44 * cos(i44 *  twicePi44 / triangleAmount44)),
			    y44 + (radius44 * sin(i44 * twicePi44 / triangleAmount44))
			);
		}
	glEnd();

	    int i45;// bubles

    GLfloat x45=-0.4f; GLfloat y45=0.225f; GLfloat radius45 =.008f;
	int triangleAmount45 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi45 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x45, y45); // center of circle
		for(i45 = 0; i45 <= triangleAmount45;i45++) {
			glVertex2f(
		            x45 + (radius45 * cos(i45 *  twicePi45 / triangleAmount45)),
			    y45 + (radius45 * sin(i45 * twicePi45 / triangleAmount45))
			);
		}
	glEnd();


    int i46;// bubles

    GLfloat x46=-0.38f; GLfloat y46=0.225f; GLfloat radius46 =.008f;
	int triangleAmount46 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi46 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x46, y46); // center of circle
		for(i46 = 0; i46 <= triangleAmount46;i46++) {
			glVertex2f(
		            x46 + (radius46 * cos(i46 *  twicePi46 / triangleAmount46)),
			    y46 + (radius46 * sin(i46 * twicePi46 / triangleAmount46))
			);
		}
	glEnd();

    int i47;// bubles

    GLfloat x47=-0.33f; GLfloat y47=0.225f; GLfloat radius47 =.008f;
	int triangleAmount47 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi47 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x47, y47); // center of circle
		for(i47 = 0; i47 <= triangleAmount47;i47++) {
			glVertex2f(
		            x47 + (radius47 * cos(i47 *  twicePi47 / triangleAmount47)),
			    y47 + (radius47 * sin(i47 * twicePi47 / triangleAmount47))
			);
		}
	glEnd();

	    int i48;// bubles

    GLfloat x48=-0.31f; GLfloat y48=0.225f; GLfloat radius48 =.008f;
	int triangleAmount48 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi48 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x48, y48); // center of circle
		for(i48 = 0; i48 <= triangleAmount48;i48++) {
			glVertex2f(
		            x48 + (radius48 * cos(i48 *  twicePi48 / triangleAmount48)),
			    y48 + (radius48 * sin(i48 * twicePi48 / triangleAmount48))
			);
		}
	glEnd();

	    int i49;// bubles

    GLfloat x49=-0.29f; GLfloat y49=0.225f; GLfloat radius49 =.008f;
	int triangleAmount49 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi49 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x49, y49); // center of circle
		for(i49 = 0; i49 <= triangleAmount49;i49++) {
			glVertex2f(
		            x49 + (radius49 * cos(i49 *  twicePi49 / triangleAmount49)),
			    y49 + (radius49 * sin(i49 * twicePi49 / triangleAmount49))
			);
		}
	glEnd();

    int i50;// bubles

    GLfloat x50=-0.24f; GLfloat y50=0.225f; GLfloat radius50 =.008f;
	int triangleAmount50 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi50 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x50, y50); // center of circle
		for(i50 = 0; i50 <= triangleAmount50;i50++) {
			glVertex2f(
		            x50 + (radius50 * cos(i50 *  twicePi50 / triangleAmount50)),
			    y50 + (radius50 * sin(i50 * twicePi50 / triangleAmount50))
			);
		}
	glEnd();

    int i51;// bubles

    GLfloat x51=-0.22f; GLfloat y51=0.225f; GLfloat radius51 =.008f;
	int triangleAmount51 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi51 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x51, y51); // center of circle
		for(i51 = 0; i51 <= triangleAmount51;i51++) {
			glVertex2f(
		            x51 + (radius51 * cos(i51 *  twicePi51 / triangleAmount51)),
			    y51 + (radius51 * sin(i51 * twicePi51 / triangleAmount51))
			);
		}
	glEnd();

    int i52;// bubles

    GLfloat x52=-0.2f; GLfloat y52=0.225f; GLfloat radius52 =.008f;
	int triangleAmount52 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi52 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x52, y52); // center of circle
		for(i52 = 0; i52 <= triangleAmount52;i52++) {
			glVertex2f(
		            x52 + (radius52 * cos(i52 *  twicePi52 / triangleAmount52)),
			    y52 + (radius52 * sin(i52 * twicePi52 / triangleAmount52))
			);
		}
	glEnd();



    int i53;// rest door
    GLfloat x53=0.502f; GLfloat y53=0.14f; GLfloat radius53 =.02f;
    int triangleAmount53 = 100; //# of triangles used to draw circle


	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi53 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x53, y53); // center of circle
		for(i53 = 0; i53 <= triangleAmount53;i53++) {
			glVertex2f(
                x53 + (radius53 * cos(i53 *  twicePi53 / triangleAmount53)),
			    y53 + (radius53 * sin(i53 * twicePi53 / triangleAmount53))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// upstair rest 2
	glColor3ub(228,205,57);
    glVertex2f(0.482f,  0.0f);
    glVertex2f(0.482f, 0.14f);
    glVertex2f(0.522f, 0.14f);
    glVertex2f(0.522f, 0.0f);

    glEnd();

    int i54;// rest door
    GLfloat x54=-0.502f; GLfloat y54=0.14f; GLfloat radius54 =.02f;
    int triangleAmount54 = 100; //# of triangles used to draw circle


	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi54 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x54, y54); // center of circle
		for(i54 = 0; i54 <= triangleAmount54;i54++) {
			glVertex2f(
                x54 + (radius54 * cos(i54 *  twicePi54 / triangleAmount54)),
			    y54 + (radius54 * sin(i54 * twicePi54 / triangleAmount54))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// upstair rest 2
	glColor3ub(228,205,57);
    glVertex2f(-0.482f,  0.0f);
    glVertex2f(-0.482f, 0.14f);
    glVertex2f(-0.522f, 0.14f);
    glVertex2f(-0.522f, 0.0f);

    glEnd();
    //glLoadIdentity();

    glBegin(GL_LINES);// upstair right pillar
    glColor3ub(0,0,0);

    glVertex2f(0.575f, 0.2f);
    glVertex2f(0.575f, -0.02f);

    glVertex2f(0.571f, 0.2f);
    glVertex2f(0.571f, -0.02f);

    glVertex2f(0.554f, -0.02f);
    glVertex2f(0.554f,0.2f);

    glVertex2f(0.55f, -0.02f);
    glVertex2f(0.55f,0.2f);


    glEnd();

        glBegin(GL_LINES);// upstair left pillar

    glVertex2f(-0.575f, 0.2f);
    glVertex2f(-0.575f, -0.02f);

    glVertex2f(-0.571f, 0.2f);
    glVertex2f(-0.571f, -0.02f);

    glVertex2f(-0.554f, -0.02f);
    glVertex2f(-0.554f,0.2f);

    glVertex2f(-0.55f, -0.02f);
    glVertex2f(-0.55f,0.2f);


    glEnd();

    glBegin(GL_QUADS);//coloring minar
    glColor3ub(163,53,53);

    glVertex2f(0.575f, 0.24f);
    glVertex2f(0.575f, 0.34f);
    glVertex2f(0.55f,0.34f);
    glVertex2f(0.55f,0.24f);

    glEnd();

    glBegin(GL_LINES);// roof right pillar
    glColor3ub(1,1,1);

    glVertex2f(0.575f, 0.34f);
    glVertex2f(0.575f, 0.24f);

    glVertex2f(0.571f, 0.34f);
    glVertex2f(0.571f, 0.24f);

    glVertex2f(0.554f, 0.24f);
    glVertex2f(0.554f,0.34f);

    glVertex2f(0.55f, 0.24f);
    glVertex2f(0.55f,0.34f);

    glVertex2f(0.55f, 0.34f);//finishing
    glVertex2f(0.575f,0.34f);


    glEnd();

    glBegin(GL_QUADS);//color minar star
    glColor3ub(163,53,53);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);

    glEnd();

    glBegin(GL_LINES);//color minar star
    glColor3ub(1,1,1);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.562f, 0.34f);

    glEnd();








 glBegin(GL_LINES);//upstair right pillar corner
 glColor3ub(1,1,1);


    glVertex2f(0.722f, -0.02f);
    glVertex2f(0.722f,0.2f);

    glVertex2f(0.724f, -0.02f);
    glVertex2f(0.724f,0.2f);

    glVertex2f(0.726f, -0.02f);
    glVertex2f(0.726f,0.2f);

    glVertex2f(0.756f, -0.02f);
    glVertex2f(0.756f, 0.2f);

    glVertex2f(0.758f, -0.02f);
    glVertex2f(0.758f,0.2f);

    glVertex2f(0.76f, -0.02f);
    glVertex2f(0.76f, 0.2f);
    glEnd();

     glBegin(GL_LINES);//upstair right pillar corner
 glColor3ub(1,1,1);


    glVertex2f(-0.722f, -0.02f);
    glVertex2f(-0.722f,0.2f);

    glVertex2f(-0.724f, -0.02f);
    glVertex2f(-0.724f,0.2f);

    glVertex2f(-0.726f, -0.02f);
    glVertex2f(-0.726f,0.2f);

    glVertex2f(-0.756f, -0.02f);
    glVertex2f(-0.756f, 0.2f);

    glVertex2f(-0.758f, -0.02f);
    glVertex2f(-0.758f,0.2f);

    glVertex2f(-0.76f, -0.02f);
    glVertex2f(-0.76f, 0.2f);
    glEnd();



    glTranslatef(.18,0,0);//translate pillar 1
    //glScalef(.4,.4,0);


    glBegin(GL_QUADS);//coloring minar
    glColor3ub(163,53,53);

    glVertex2f(0.575f, 0.24f);
    glVertex2f(0.575f, 0.34f);
    glVertex2f(0.55f,0.34f);
    glVertex2f(0.55f,0.24f);

    glEnd();

    glBegin(GL_LINES);// roof right pillar
    glColor3ub(1,1,1);

    glVertex2f(0.575f, 0.34f);
    glVertex2f(0.575f, 0.24f);

    glVertex2f(0.571f, 0.34f);
    glVertex2f(0.571f, 0.24f);

    glVertex2f(0.554f, 0.24f);
    glVertex2f(0.554f,0.34f);

    glVertex2f(0.55f, 0.24f);
    glVertex2f(0.55f,0.34f);

    glVertex2f(0.55f, 0.34f);//finishing
    glVertex2f(0.575f,0.34f);


    glEnd();

    glBegin(GL_QUADS);//color minar star
    glColor3ub(163,53,53);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);

    glEnd();

    glBegin(GL_LINES);//color minar star
    glColor3ub(1,1,1);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.562f, 0.34f);

    glEnd();




    glLoadIdentity();


        glTranslatef(-1.31,0,0);//translate pillar 2 left
    //glScalef(.4,.4,0);


    glBegin(GL_QUADS);//coloring minar
    glColor3ub(163,53,53);

    glVertex2f(0.575f, 0.24f);
    glVertex2f(0.575f, 0.34f);
    glVertex2f(0.55f,0.34f);
    glVertex2f(0.55f,0.24f);

    glEnd();

    glBegin(GL_LINES);// roof right pillar
    glColor3ub(1,1,1);

    glVertex2f(0.575f, 0.34f);
    glVertex2f(0.575f, 0.24f);

    glVertex2f(0.571f, 0.34f);
    glVertex2f(0.571f, 0.24f);

    glVertex2f(0.554f, 0.24f);
    glVertex2f(0.554f,0.34f);

    glVertex2f(0.55f, 0.24f);
    glVertex2f(0.55f,0.34f);

    glVertex2f(0.55f, 0.34f);//finishing
    glVertex2f(0.575f,0.34f);


    glEnd();

    glBegin(GL_QUADS);//color minar star
    glColor3ub(163,53,53);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);

    glEnd();

    glBegin(GL_LINES);//color minar star
    glColor3ub(1,1,1);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.562f, 0.34f);

    glEnd();




    glLoadIdentity();


        glTranslatef(-1.122,0,0);//translate pillar 3
    //glScalef(.4,.4,0);


    glBegin(GL_QUADS);//coloring minar
    glColor3ub(163,53,53);

    glVertex2f(0.575f, 0.24f);
    glVertex2f(0.575f, 0.34f);
    glVertex2f(0.55f,0.34f);
    glVertex2f(0.55f,0.24f);

    glEnd();

    glBegin(GL_LINES);// roof right pillar
    glColor3ub(1,1,1);

    glVertex2f(0.575f, 0.34f);
    glVertex2f(0.575f, 0.24f);

    glVertex2f(0.571f, 0.34f);
    glVertex2f(0.571f, 0.24f);

    glVertex2f(0.554f, 0.24f);
    glVertex2f(0.554f,0.34f);

    glVertex2f(0.55f, 0.24f);
    glVertex2f(0.55f,0.34f);

    glVertex2f(0.55f, 0.34f);//finishing
    glVertex2f(0.575f,0.34f);


    glEnd();

    glBegin(GL_QUADS);//color minar star
    glColor3ub(163,53,53);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);

    glEnd();

    glBegin(GL_LINES);//color minar star
    glColor3ub(1,1,1);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.562f, 0.34f);

    glEnd();




    glLoadIdentity();

       int i58;// gombuj

    GLfloat x58=0.0f; GLfloat y58=0.41f; GLfloat radius58 =.08f;
	int triangleAmount58 = 30; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi58 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(163,53,53);
		glVertex2f(x58, y58); // center of circle
		for(i58 = 0; i58 <= triangleAmount58;i58++) {
			glVertex2f(
		            x58 + (radius58 * cos(i58 *  twicePi58 / triangleAmount58)),
			    y58 + (radius58 * sin(i58 * twicePi58 / triangleAmount58))
			);
		}
	glEnd();

	glBegin(GL_TRIANGLES);//overlap middle
	glColor3ub(163,53,53);
    glVertex2f(0.07f,  0.45f);
    glVertex2f(0.0, 0.55f);
    glVertex2f(-0.07f, 0.45f);


    glEnd();


    glBegin(GL_QUADS);//overlap middle
	glColor3ub(163,53,53);
    glVertex2f(0.12f,  0.0f);
    glVertex2f(0.12f, 0.28f);
    glVertex2f(-0.10f, 0.28f);
    glVertex2f(-0.10f, 0.0f);

    glEnd();

    glBegin(GL_QUADS);//pillar after minar
	glColor3ub(163,53,53);
    glVertex2f(0.12f,  0.0f);
    glVertex2f(0.12f, 0.31f);
    glVertex2f(0.093f, 0.31f);
    glVertex2f(0.093f, 0.0f);

    glEnd();

    glBegin(GL_LINES);//pillar middle right
	glColor3ub(1,1,1);
    glVertex2f(0.12f,  0.0f);
    glVertex2f(0.12f, 0.31f);
    glVertex2f(0.12f, 0.31f);
    glVertex2f(0.093f, 0.31f);
    glVertex2f(0.093f, 0.31f);
    glVertex2f(0.093f, 0.0f);
    glVertex2f(0.093f, 0.0f);
    glVertex2f(0.12f,  0.0f);



    glEnd();

    glBegin(GL_QUADS);//pillar after minar
	glColor3ub(163,53,53);
    glVertex2f(-0.12f,  0.0f);
    glVertex2f(-0.12f, 0.31f);
    glVertex2f(-0.093f, 0.31f);
    glVertex2f(-0.093f, 0.0f);

    glEnd();

    glBegin(GL_LINES);//pillar middle left
	glColor3ub(1,1,1);
    glVertex2f(-0.12f,  0.0f);
    glVertex2f(-0.12f, 0.31f);
    glVertex2f(-0.12f, 0.31f);
    glVertex2f(-0.093f, 0.31f);
    glVertex2f(-0.093f, 0.31f);
    glVertex2f(-0.093f, 0.0f);
    glVertex2f(-0.093f, 0.0f);
    glVertex2f(-0.12f,  0.0f);



    glEnd();

    glBegin(GL_POLYGON);//polygon right
	glColor3ub(163,53,53);
    glVertex2f(0.12f,  0.31f);
    glVertex2f(0.13f, 0.35f);
    glVertex2f(0.1065f, 0.38f);
    glVertex2f(0.083f, 0.35f);
    glVertex2f(0.093f, 0.31f);




    glEnd();

    glBegin(GL_LINES);//polygon lines right
	glColor3ub(1,1,1);
    glVertex2f(0.12f,  0.31f);
    glVertex2f(0.13f, 0.35f);

    glVertex2f(0.13f, 0.35f);
    glVertex2f(0.1065f, 0.38f);

    glVertex2f(0.1065f, 0.38f);
    glVertex2f(0.083f, 0.35f);

    glVertex2f(0.083f, 0.35f);
    glVertex2f(0.093f, 0.31f);

    glVertex2f(0.093f, 0.31f);
    glVertex2f(0.12f,  0.31f);





    glEnd();

        glBegin(GL_POLYGON);//polygon left
	glColor3ub(163,53,53);
    glVertex2f(-00.12f,  0.31f);
    glVertex2f(-0.13f, 0.35f);
    glVertex2f(-0.1065f, 0.38f);
    glVertex2f(-0.083f, 0.35f);
    glVertex2f(-0.093f, 0.31f);


    glEnd();

    glBegin(GL_LINES);//polygon lines left
	glColor3ub(1,1,1);
    glVertex2f(-0.12f,  0.31f);
    glVertex2f(-0.13f, 0.35f);

    glVertex2f(-0.13f, 0.35f);
    glVertex2f(-0.1065f, 0.38f);

    glVertex2f(-0.1065f, 0.38f);
    glVertex2f(-0.083f, 0.35f);

    glVertex2f(-0.083f, 0.35f);
    glVertex2f(-0.093f, 0.31f);

    glVertex2f(-0.093f, 0.31f);
    glVertex2f(-0.12f,  0.31f);


    glEnd();


    glTranslatef(-.454,0.03,0);//translate pillar middle
    //glScalef(.4,.4,0);

    glBegin(GL_QUADS);//color minar star
    glColor3ub(163,53,53);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);

    glEnd();

    glBegin(GL_LINES);//color minar star
    glColor3ub(1,1,1);

    glVertex2f(0.562f, 0.34f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.57f, 0.36f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.562f,0.38f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.554f,0.36f);
    glVertex2f(0.562f, 0.34f);

    glEnd();




    glLoadIdentity();

    glTranslatef(.454,0.03,0);//translate pillar middle
    //glScalef(.4,.4,0);

    glBegin(GL_QUADS);//color minar star
    glColor3ub(163,53,53);

    glVertex2f(-0.562f, 0.34f);
    glVertex2f(-0.57f, 0.36f);
    glVertex2f(-0.562f,0.38f);
    glVertex2f(-0.554f,0.36f);

    glEnd();

    glBegin(GL_LINES);//color minar star
    glColor3ub(0,0,0);

    glVertex2f(-0.562f, 0.34f);
    glVertex2f(-0.57f, 0.36f);
    glVertex2f(-0.57f, 0.36f);
    glVertex2f(-0.562f,0.38f);
    glVertex2f(-0.562f,0.38f);
    glVertex2f(-0.554f,0.36f);
    glVertex2f(-0.554f,0.36f);
    glVertex2f(-0.562f, 0.34f);

    glEnd();




    glLoadIdentity();

    int i55;// middle

    GLfloat x55=0.0f; GLfloat y55=0.18f; GLfloat radius55 =.02f;
	int triangleAmount55 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi55 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x55, y55); // center of circle
		for(i55 = 0; i55 <= triangleAmount55;i55++) {
			glVertex2f(
		            x55 + (radius55 * cos(i55 *  twicePi55 / triangleAmount55)),
			    y55 + (radius55 * sin(i55 * twicePi55 / triangleAmount55))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// middle
	glColor3ub(228,205,57);
    glVertex2f(0.02f,  0.0f);
    glVertex2f(0.02f, 0.18f);
    glVertex2f(-0.02f, 0.18f);
    glVertex2f(-0.02f, 0.0f);

    glEnd();

        int i56;// middle

    GLfloat x56=0.06f; GLfloat y56=0.18f; GLfloat radius56 =.010f;
	int triangleAmount56 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi56 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x56, y56); // center of circle
		for(i56 = 0; i56 <= triangleAmount56;i56++) {
			glVertex2f(
		            x56 + (radius56 * cos(i56 *  twicePi56 / triangleAmount56)),
			    y56 + (radius56 * sin(i56 * twicePi56 / triangleAmount56))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// middle
	glColor3ub(228,205,57);
    glVertex2f(0.07f,  0.0f);
    glVertex2f(0.07f, 0.18f);
    glVertex2f(0.05f, 0.18f);
    glVertex2f(0.05f, 0.0f);

    glEnd();

            int i57;// upstair window left

    GLfloat x57=-0.06f; GLfloat y57=0.18f; GLfloat radius57 =.010f;
	int triangleAmount57 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi57 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(228,205,57);
		glVertex2f(x57, y57); // center of circle
		for(i57 = 0; i57 <= triangleAmount57;i57++) {
			glVertex2f(
		            x57 + (radius57 * cos(i57 *  twicePi57 / triangleAmount57)),
			    y57 + (radius57 * sin(i57 * twicePi57 / triangleAmount57))
			);
		}
	glEnd();

    glBegin(GL_QUADS);// middle
	glColor3ub(228,205,57);
    glVertex2f(-0.07f,  0.0f);
    glVertex2f(-0.07f, 0.18f);
    glVertex2f(-0.05f, 0.18f);
    glVertex2f(-0.05f, 0.0f);

    glEnd();

    glBegin(GL_QUADS);//middle line
	glColor3ub(0,0,0);
    glVertex2f(0.092f,  0.26f);
    glVertex2f(0.092f, 0.27f);
    glVertex2f(-0.092f, 0.27f);
    glVertex2f(-0.092f, 0.26f);
    glEnd();


    glBegin(GL_POLYGON);//middle polygon
	glColor3ub(163,53,53);
    glVertex2f(0.08f,  0.28f);
    glVertex2f(0.08f, 0.38f);

    glVertex2f(0.05f, 0.4f);
    glVertex2f(-0.05f, 0.4f);

    glVertex2f(-0.08f, 0.38f);
    glVertex2f(-0.08f, 0.28f);
    glEnd();

    glBegin(GL_LINES);//middle polygon line
	glColor3ub(0,0,0);
    glVertex2f(0.08f,  0.28f);
    glVertex2f(0.08f, 0.38f);

    glVertex2f(0.08f, 0.38f);
    glVertex2f(0.05f, 0.4f);

    glVertex2f(0.05f, 0.4f);
    glVertex2f(-0.05f, 0.4f);

    glVertex2f(-0.05f, 0.4f);
    glVertex2f(-0.08f, 0.38f);

    glVertex2f(-0.08f, 0.38f);
    glVertex2f(-0.08f, 0.28f);

    glVertex2f(-0.08f, 0.28f);
    glVertex2f(0.08f,  0.28f);
    glEnd();






    glBegin(GL_POLYGON);//middle polygon 2
	glColor3ub(163,53,53);
    //glVertex2f(0.08f,  0.28f);
    glVertex2f(0.08f, 0.38f);
    glVertex2f(0.09f, 0.39f);

    //glVertex2f(0.09f, 0.39f);
    glVertex2f(0.05f, 0.42f);


    //glVertex2f(0.05f, 0.42f);
    glVertex2f(-0.05f, 0.42f);

    //glVertex2f(-0.05f, 0.42f);
    glVertex2f(-0.09f, 0.39f);

    //glVertex2f(-0.09f, 0.39f);
    glVertex2f(-0.08f, 0.38f);

    //glVertex2f(-0.07f, 0.39f);
   // glVertex2f(-0.08f, 0.38f);

    //glVertex2f(-0.08f, 0.38f);
    glVertex2f(-0.05f, 0.4f);

   // glVertex2f(0.05f, 0.4f);
    glVertex2f(0.08f, 0.38f);
    glEnd();


    glBegin(GL_LINES);//middle polygon 2
	glColor3ub(0,0,0);
    //glVertex2f(0.08f,  0.28f);
    glVertex2f(0.08f, 0.38f);
    glVertex2f(0.09f, 0.39f);

    glVertex2f(0.09f, 0.39f);
    glVertex2f(0.05f, 0.42f);


    glVertex2f(0.05f, 0.42f);
    glVertex2f(-0.05f, 0.42f);

    glVertex2f(-0.05f, 0.42f);
    glVertex2f(-0.09f, 0.39f);

    glVertex2f(-0.09f, 0.39f);
    glVertex2f(-0.08f, 0.38f);

    //glVertex2f(-0.07f, 0.39f);
   // glVertex2f(-0.08f, 0.38f);

    glVertex2f(-0.08f, 0.38f);
    glVertex2f(-0.05f, 0.4f);

    glVertex2f(-0.05f, 0.4f);
    glVertex2f(0.05f, 0.4f);

    glVertex2f(0.05f, 0.4f);
    glVertex2f(0.08f, 0.38f);
    glEnd();


    glBegin(GL_QUADS);//middle line
	glColor3ub(0,0,0);
    glVertex2f(0.006f,  0.54f);
    glVertex2f(0.006f, 0.58f);
    glVertex2f(-0.006f, 0.58f);
    glVertex2f(-0.006f, 0.54f);
    glEnd();



























    glBegin(GL_QUADS);// shiri
	glColor3ub(106,108,109);

	glVertex2f(0.24f, -0.26f);
	glVertex2f(0.14f, 0.0f);
    glVertex2f(-.14f, 0.0f);
    glVertex2f(-0.24,-0.26f);
    glEnd();

    glBegin(GL_LINES);// shiri
	glColor3ub(0,0,0);

	glVertex2f(0.24f, -0.26f);
	glVertex2f(0.14f, 0.0f);

	glVertex2f(0.14f, 0.0f);
    glVertex2f(-.14f, 0.0f);

    glVertex2f(-.14f, 0.0f);
    glVertex2f(-0.24,-0.26f);

    glVertex2f(-0.24,-0.26f);
    glVertex2f(0.24f, -0.26f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.144f, -0.02f);
	glVertex2f(0.144f, -0.015f);
    glVertex2f(-.144f, -0.015f);
    glVertex2f(-0.144,-0.02f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.148f, -0.045f);
	glVertex2f(0.148f, -0.04f);
    glVertex2f(-.148f, -0.04f);
    glVertex2f(-0.148,-0.045f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.162f, -0.065f);
	glVertex2f(0.162f, -0.06f);
    glVertex2f(-.162f, -0.06f);
    glVertex2f(-0.162,-0.065f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.172f, -0.085f);
	glVertex2f(0.172f, -0.08f);
    glVertex2f(-.172f, -0.08f);
    glVertex2f(-0.172,-0.085f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.182f, -0.105f);
	glVertex2f(0.182f, -0.1f);
    glVertex2f(-.182f, -0.1f);
    glVertex2f(-0.182,-0.105f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.18f, -0.115f);
	glVertex2f(0.18f, -0.12f);
    glVertex2f(-.18f, -0.12f);
    glVertex2f(-0.18,-0.115f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.19f, -0.14f);
	glVertex2f(0.19f, -0.13f);
    glVertex2f(-.19f, -0.13f);
    glVertex2f(-0.19,-0.14f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.2f, -0.16f);
	glVertex2f(0.2f, -0.15f);
    glVertex2f(-.2f, -0.15f);
    glVertex2f(-0.2,-0.16f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.21f, -0.18f);
	glVertex2f(0.21f, -0.17f);
    glVertex2f(-.21f, -0.17f);
    glVertex2f(-0.21,-0.18f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.22f, -0.2f);
	glVertex2f(0.22f, -0.19f);
    glVertex2f(-.22f, -0.19f);
    glVertex2f(-0.22,-0.2f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.225f, -0.22f);
	glVertex2f(0.225f, -0.21f);
    glVertex2f(-.225f, -0.21f);
    glVertex2f(-0.225,-0.22f);
    glEnd();

    glBegin(GL_QUADS);// shiri lines
	glColor3ub(0,0,0);

	glVertex2f(0.23f, -0.24f);
	glVertex2f(0.23f, -0.23f);
    glVertex2f(-.23f, -0.23f);
    glVertex2f(-0.23,-0.24f);
    glEnd();


    //Fence-Left-1
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(-.25,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-2
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(.105,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-3
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(.46,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-4
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(.815,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-5
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(1.17,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-6
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(1.525,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();

    //Fence-Left-7
    glPushMatrix();
    glScalef(.8,.7,0);
    glTranslatef(1.88,-.73,0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-1.0f,-0.1f);
    glVertex2f(-0.6f,-0.1f);

    glVertex2f(-1.0f,-0.05f);
    glVertex2f(-0.6f,-0.05f);

    glVertex2f(-1.0f,0.0f);
    glVertex2f(-0.6f,0.0f);

    glVertex2f(-1.0f,0.05f);
    glVertex2f(-0.6f,0.05f);

    glVertex2f(-1.0f,0.1f);
    glVertex2f(-0.6f,0.1f);

    glVertex2f(-0.95f,0.13f);
    glVertex2f(-0.95f,-0.12f);

    glVertex2f(-0.9f,0.13f);
    glVertex2f(-0.9f,-0.12f);

    glVertex2f(-0.85f,0.13f);
    glVertex2f(-0.85f,-0.12f);

    glVertex2f(-0.8f,0.13f);
    glVertex2f(-0.8f,-0.12f);

    glVertex2f(-0.75f,0.13f);
    glVertex2f(-0.75f,-0.12f);

    glVertex2f(-0.7f,0.13f);
    glVertex2f(-0.7f,-0.12f);

    glVertex2f(-0.65f,0.13f);
    glVertex2f(-0.65f,-0.12f);

    glEnd();
    glPopMatrix();



    //FootWalk
    glBegin(GL_QUADS);
    glColor3ub(199,136,74);
    glVertex2f(-1,-.6);
    glVertex2f(-1,-.68);
    glVertex2f(1,-.68);
    glVertex2f(1,-.6);
    glEnd();

    glScalef(.5,.4,0);
    glTranslatef(1.6,-1.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();
glLoadIdentity();

    glScalef(.5,.4,0);
    glTranslatef(2.2,-1.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();
glLoadIdentity();


    glScalef(.5,.4,0);
    glTranslatef(-.05,-1.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();
glLoadIdentity();

    glScalef(.5,.4,0);
    glTranslatef(-0.7,-1.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.72f,-0.15f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.735f,-0.17f);
    glVertex2f(-0.74f,-0.25f);
    glVertex2f(-0.775f,-0.17f);
    glVertex2f(-0.85f,-0.2f);
    glVertex2f(-0.78f,-0.15f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,-0.15f);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.72f,0.23f);
    glVertex2f(-0.72f,-0.15f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.76f,0.23f);
    glVertex2f(-0.76f,0.3f);
    glVertex2f(-0.74f,0.3f);
    glVertex2f(-0.74f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.74f,0.23f);
    glVertex2f(-0.71f,0.29f);
    glVertex2f(-0.7f,0.28f);
    glVertex2f(-0.72f,0.23f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.78f,0.23f);
    glVertex2f(-0.8f,0.28f);
    glVertex2f(-0.79f,0.29f);
    glVertex2f(-0.76f,0.23f);
    glEnd();
glLoadIdentity();





            int i59;// tree

    GLfloat x59=0.4f; GLfloat y59=-0.44f; GLfloat radius59 =.024f;
	int triangleAmount59 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi59 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x59, y59); // center of circle
		for(i59 = 0; i59 <= triangleAmount59;i59++) {
			glVertex2f(
		            x59 + (radius59 * cos(i59 *  twicePi59 / triangleAmount59)),
			    y59 + (radius59 * sin(i59 * twicePi59 / triangleAmount59))
			);
		}
	glEnd();


	            int i60;//tree

    GLfloat x60=0.46f; GLfloat y60=-0.44f; GLfloat radius60 =.024f;
	int triangleAmount60 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi60 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x60, y60); // center of circle
		for(i60 = 0; i60 <= triangleAmount60;i60++) {
			glVertex2f(
		            x60 + (radius60 * cos(i60 *  twicePi60 / triangleAmount60)),
			    y60 + (radius60 * sin(i60 * twicePi60 / triangleAmount60))
			);
		}
	glEnd();

		            int i61;//tree

    GLfloat x61=0.43f; GLfloat y61=-0.42f; GLfloat radius61 =.036f;
	int triangleAmount61 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi61 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x61, y61); // center of circle
		for(i61 = 0; i61 <= triangleAmount61;i61++) {
			glVertex2f(
		            x61 + (radius61 * cos(i61 *  twicePi61 / triangleAmount61)),
			    y61 + (radius61 * sin(i61 * twicePi61 / triangleAmount61))
			);
		}
	glEnd();


		            int i62;//tree

    GLfloat x62=0.69f; GLfloat y62=-0.44f; GLfloat radius62 =.024f;
	int triangleAmount62 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi62 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x62, y62); // center of circle
		for(i62 = 0; i62 <= triangleAmount62;i62++) {
			glVertex2f(
		            x62 + (radius62 * cos(i62 *  twicePi62 / triangleAmount62)),
			    y62 + (radius62 * sin(i62 * twicePi62 / triangleAmount62))
			);
		}
	glEnd();


			            int i63;//tree

    GLfloat x63=0.76f; GLfloat y63=-0.44f; GLfloat radius63 =.024f;
	int triangleAmount63 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi63 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x63, y63); // center of circle
		for(i63 = 0; i63 <= triangleAmount63;i63++) {
			glVertex2f(
		            x63 + (radius63 * cos(i63 *  twicePi63 / triangleAmount63)),
			    y63 + (radius63 * sin(i63 * twicePi63 / triangleAmount63))
			);
		}
	glEnd();


				            int i64;//tree

    GLfloat x64=0.73f; GLfloat y64=-0.42f; GLfloat radius64 =.036f;
	int triangleAmount64 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi64 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x64, y64); // center of circle
		for(i64 = 0; i64 <= triangleAmount64;i64++) {
			glVertex2f(
		            x64 + (radius64 * cos(i64 *  twicePi64 / triangleAmount64)),
			    y64 + (radius64 * sin(i64 * twicePi64 / triangleAmount64))
			);
		}
	glEnd();


				            int i65;//tree

    GLfloat x65=-0.7f; GLfloat y65=-0.44f; GLfloat radius65 =.024f;
	int triangleAmount65 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi65 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x65, y65); // center of circle
		for(i65 = 0; i65 <= triangleAmount65;i65++) {
			glVertex2f(
		            x65 + (radius65 * cos(i65 *  twicePi65 / triangleAmount65)),
			    y65 + (radius65 * sin(i65 * twicePi65 / triangleAmount65))
			);
		}
	glEnd();

				            int i66;//tree

    GLfloat x66=-0.76f; GLfloat y66=-0.44f; GLfloat radius66 =.024f;
	int triangleAmount66 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi66 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x66, y66); // center of circle
		for(i66 = 0; i66 <= triangleAmount66;i66++) {
			glVertex2f(
		            x66 + (radius66 * cos(i66 *  twicePi66 / triangleAmount66)),
			    y66 + (radius66 * sin(i66 * twicePi66 / triangleAmount66))
			);
		}
	glEnd();


					            int i67;//tree

    GLfloat x67=-0.73f; GLfloat y67=-0.42f; GLfloat radius67 =.036f;
	int triangleAmount67 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi67 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x67, y67); // center of circle
		for(i67 = 0; i67 <= triangleAmount67;i67++) {
			glVertex2f(
		            x67 + (radius67 * cos(i67 *  twicePi67 / triangleAmount67)),
			    y67 + (radius67 * sin(i67 * twicePi67 / triangleAmount67))
			);
		}
	glEnd();


					            int i68;//tree

    GLfloat x68=-0.36f; GLfloat y68=-0.44f; GLfloat radius68 =.024f;
	int triangleAmount68 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi68 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x68, y68); // center of circle
		for(i68 = 0; i68 <= triangleAmount68;i68++) {
			glVertex2f(
		            x68 + (radius68 * cos(i68 *  twicePi68 / triangleAmount68)),
			    y68 + (radius68 * sin(i68 * twicePi68 / triangleAmount68))
			);
		}
	glEnd();


						            int i69;//tree

    GLfloat x69=-0.44f; GLfloat y69=-0.44f; GLfloat radius69 =.024f;
	int triangleAmount69 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi69 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x69, y69); // center of circle
		for(i69 = 0; i69 <= triangleAmount69;i69++) {
			glVertex2f(
		            x69 + (radius69 * cos(i69 *  twicePi69 / triangleAmount69)),
			    y69 + (radius69 * sin(i69 * twicePi69 / triangleAmount69))
			);
		}
	glEnd();

							            int i70;//tree

    GLfloat x70=-0.4f; GLfloat y70=-0.42f; GLfloat radius70 =.036f;
	int triangleAmount70 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi70 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x70, y70); // center of circle
		for(i70 = 0; i70 <= triangleAmount70;i70++) {
			glVertex2f(
		            x70 + (radius70 * cos(i70 *  twicePi70 / triangleAmount70)),
			    y70 + (radius70 * sin(i70 * twicePi70 / triangleAmount70))
			);
		}
	glEnd();

	    glBegin(GL_QUADS);
    glColor3ub(28, 26, 25);
    glVertex2f(-1,-.67);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glVertex2f(1,-.67);
    glEnd();
    //Road-Line
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(230,200,0);
    glVertex2f(-.98,-.835);
    glVertex2f(-.88,-.835);

    glVertex2f(-.83,-.835);
    glVertex2f(-.73,-.835);

    glVertex2f(-.68,-.835);
    glVertex2f(-.58,-.835);

    glVertex2f(-.53,-.835);
    glVertex2f(-.43,-.835);

    glVertex2f(-.38,-.835);
    glVertex2f(-.28,-.835);

    glVertex2f(-.23,-.835);
    glVertex2f(-.13,-.835);

    glVertex2f(-.08,-.835);
    glVertex2f(.02,-.835);

    glVertex2f(.07,-.835);
    glVertex2f(.17,-.835);

    glVertex2f(.22,-.835);
    glVertex2f(.32,-.835);

    glVertex2f(.37,-.835);
    glVertex2f(.47,-.835);

    glVertex2f(.52,-.835);
    glVertex2f(.62,-.835);

    glVertex2f(.67,-.835);
    glVertex2f(.77,-.835);

    glVertex2f(.82,-.835);
    glVertex2f(.92,-.835);

    glVertex2f(.97,-.835);
    glVertex2f(1,-.835);

    glEnd();



    glTranslatef(.735,-.099,0);
	glScalef(.6,.6,0);
    glBegin(GL_QUADS);//tree
	glColor3f(0.1f, .0f, 0.0f);

	glVertex2f(0.3f, -0.3f);
	glVertex2f(0.3f, 0.08f);
    glVertex2f(0.25f,0.08f);
    glVertex2f(0.25f,-0.3f);
    glEnd();

    glBegin(GL_TRIANGLES);
	glColor3f(0.1f, .0f, 0.0f);


	glVertex2f(0.30f,-0.3f);
    glVertex2f(0.25f,-0.3f);
    glVertex2f(0.20f,-0.38f);

    glVertex2f(0.36f,-0.38f);
    glVertex2f(0.3f,-0.3f);
    glVertex2f(0.25f,-0.3f);


    glVertex2f(0.3f, -0.3f);
    glVertex2f(0.25f, -0.3f);
    glVertex2f(0.275f,-0.40f);


    glEnd();

    glBegin(GL_QUADS);//branch
	glColor3f(0.1f, .0f, 0.0f);

	glVertex2f(0.3f, 0.08f);
	glVertex2f(0.38f, 0.3f);
	glVertex2f(0.38f, 0.3f);
    glVertex2f(0.28f,0.08f);

    glVertex2f(0.28f, 0.08f);
	glVertex2f(0.17f, 0.3f);
	glVertex2f(0.17f, 0.3f);
    glVertex2f(0.25f,0.08f);
    glEnd();

    glLoadIdentity();


    //2nd tree
    glTranslatef(-.735,-.099,0);
	glScalef(.6,.6,0);
    glBegin(GL_QUADS);//tree
	glColor3f(0.1f, .0f, 0.0f);

	glVertex2f(-0.3f, -0.3f);
	glVertex2f(-0.3f, 0.08f);
    glVertex2f(-0.25f,0.08f);
    glVertex2f(-0.25f,-0.3f);
    glEnd();

    glBegin(GL_TRIANGLES);
	glColor3f(0.1f, .0f, 0.0f);


	glVertex2f(-0.30f,-0.3f);
    glVertex2f(-0.25f,-0.3f);
    glVertex2f(-0.20f,-0.38f);

    glVertex2f(-0.36f,-0.38f);
    glVertex2f(-0.3f,-0.3f);
    glVertex2f(-0.25f,-0.3f);


    glVertex2f(-0.3f, -0.3f);
    glVertex2f(-0.25f, -0.3f);
    glVertex2f(-0.275f,-0.40f);


    glEnd();

    glBegin(GL_QUADS);//branch
	glColor3f(0.1f, .0f, 0.0f);

	glVertex2f(-0.3f, 0.08f);
	glVertex2f(-0.38f, 0.3f);
	glVertex2f(-0.38f, 0.3f);
    glVertex2f(-0.28f,0.08f);

    glVertex2f(-0.28f, 0.08f);
	glVertex2f(-0.17f, 0.3f);
	glVertex2f(-0.17f, 0.3f);
    glVertex2f(-0.25f,0.08f);
    glEnd();

    glLoadIdentity();



    int i71;//tree

    GLfloat x71=0.85f; GLfloat y71=0.02f; GLfloat radius71 =.05f;
	int triangleAmount71 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi71 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x71, y71); // center of circle
		for(i71 = 0; i71 <= triangleAmount71;i71++) {
			glVertex2f(
		            x71 + (radius71 * cos(i71 *  twicePi71 / triangleAmount71)),
			    y71 + (radius71 * sin(i71 * twicePi71 / triangleAmount71))
			);
		}
	glEnd();

	    int i72;//tree

    GLfloat x72=0.95f; GLfloat y72=0.02f; GLfloat radius72 =.05f;
	int triangleAmount72 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi72 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x72, y72); // center of circle
		for(i72 = 0; i72 <= triangleAmount72;i72++) {
			glVertex2f(
		            x72 + (radius72 * cos(i72 *  twicePi72 / triangleAmount72)),
			    y72 + (radius72 * sin(i72 * twicePi72 / triangleAmount72))
			);
		}
	glEnd();


		    int i73;//tree

    GLfloat x73=0.86f; GLfloat y73=0.084f; GLfloat radius73 =.05f;
	int triangleAmount73 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi73 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x73, y73); // center of circle
		for(i73 = 0; i73 <= triangleAmount73;i73++) {
			glVertex2f(
		            x73 + (radius73 * cos(i73 *  twicePi73 / triangleAmount73)),
			    y73 + (radius73 * sin(i73 * twicePi73 / triangleAmount73))
			);
		}
	glEnd();

			    int i74;//tree

    GLfloat x74=0.93f; GLfloat y74=0.084f; GLfloat radius74 =.05f;
	int triangleAmount74 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi74 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x74, y74); // center of circle
		for(i74 = 0; i74 <= triangleAmount74;i74++) {
			glVertex2f(
		            x74 + (radius74 * cos(i74 *  twicePi74 / triangleAmount74)),
			    y74 + (radius74 * sin(i74 * twicePi74 / triangleAmount74))
			);
		}
	glEnd();


				    int i75;//tree

    GLfloat x75=0.9f; GLfloat y75=0.06f; GLfloat radius75 =.04f;
	int triangleAmount75 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi75 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x75, y75); // center of circle
		for(i75 = 0; i75 <= triangleAmount75;i75++) {
			glVertex2f(
		            x75 + (radius75 * cos(i75 *  twicePi75 / triangleAmount75)),
			    y75 + (radius75 * sin(i75 * twicePi75 / triangleAmount75))
			);
		}
	glEnd();


	//2nd tree leaves

	int i76;//tree

    GLfloat x76=-0.85f; GLfloat y76=0.02f; GLfloat radius76 =.05f;
	int triangleAmount76 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi76 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x76, y76); // center of circle
		for(i76 = 0; i76 <= triangleAmount76;i76++) {
			glVertex2f(
		            x76 + (radius76 * cos(i76 *  twicePi76 / triangleAmount76)),
			    y76 + (radius76 * sin(i76 * twicePi76 / triangleAmount76))
			);
		}
	glEnd();

	    int i77;//tree

    GLfloat x77=-0.95f; GLfloat y77=0.02f; GLfloat radius77 =.05f;
	int triangleAmount77 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi77 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x77, y77); // center of circle
		for(i77 = 0; i77 <= triangleAmount77;i77++) {
			glVertex2f(
		            x77 + (radius77 * cos(i77 *  twicePi77 / triangleAmount77)),
			    y77 + (radius77 * sin(i77 * twicePi77 / triangleAmount77))
			);
		}
	glEnd();


		    int i80;//tree

    GLfloat x80=-0.86f; GLfloat y80=0.084f; GLfloat radius80 =.05f;
	int triangleAmount80 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi80 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x80, y80); // center of circle
		for(i80 = 0; i80 <= triangleAmount80;i80++) {
			glVertex2f(
		            x80 + (radius80 * cos(i80 *  twicePi80 / triangleAmount80)),
			    y80 + (radius80 * sin(i80 * twicePi80 / triangleAmount80))
			);
		}
	glEnd();

			    int i78;//tree

    GLfloat x78=-0.93f; GLfloat y78=0.084f; GLfloat radius78 =.05f;
	int triangleAmount78 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi78 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x78, y78); // center of circle
		for(i78 = 0; i78 <= triangleAmount78;i78++) {
			glVertex2f(
		            x78 + (radius78 * cos(i78 *  twicePi78 / triangleAmount78)),
			    y78 + (radius78 * sin(i78 * twicePi78 / triangleAmount78))
			);
		}
	glEnd();


				    int i79;//tree

    GLfloat x79=-0.9f; GLfloat y79=0.06f; GLfloat radius79 =.04f;
	int triangleAmount79 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi79 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(17, 61, 17);
		glVertex2f(x79, y79); // center of circle
		for(i79 = 0; i79 <= triangleAmount79;i79++) {
			glVertex2f(
		            x79 + (radius79 * cos(i79 *  twicePi79 / triangleAmount79)),
			    y79 + (radius79 * sin(i79 * twicePi79 / triangleAmount79))
			);
		}
	glEnd();

        //car starts


    glPushMatrix();
    glTranslatef(position2,0,0);
    {glTranslatef(0,-.08,0);

    glBegin(GL_QUADS);
    glColor3ub(66,135,245);
    glVertex2f(-.65,-.60);
    glVertex2f(-.65,-.68);
    glVertex2f(-.7,-.68);
    glVertex2f(-.7,-.62);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(66,135,245);
    glVertex2f(-.27,-.60);
    glVertex2f(-.27,-.68);
    glVertex2f(-.5,-.68);
    glVertex2f(-.5,-.60);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(66,135,245);
    glVertex2f(-.66,-.60);
    glVertex2f(-.66,-.68);
    glVertex2f(-.28,-.68);
    glVertex2f(-.28,-.62);
    glVertex2f(-.27,-.62);
    glVertex2f(-.28,-.60);
    glVertex2f(-.36,-.60);
    glVertex2f(-.40,-.54);
    glVertex2f(-.60,-.54);
    glVertex2f(-.62,-.62);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-.37,-.60);
    glVertex2f(-.40,-.55);
    glVertex2f(-.58,-.55);
    glVertex2f(-.62,-.60);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(-.40,-.55);
    glVertex2f(-.40,-.60);

    glVertex2f(-.58,-.55);
    glVertex2f(-.58,-.60);
    glEnd();
  //glLoadIdentity();
    }

    int i84;//car

    GLfloat x84=-0.58f; GLfloat y84=-0.68f; GLfloat radius84 =-.03f;
	int triangleAmount84 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi84 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);
		glVertex2f(x84, y84); // center of circle
		for(i84 = 0; i84 <= triangleAmount84;i84++) {
			glVertex2f(
		            x84 + (radius84 * cos(i84 *  twicePi84 / triangleAmount84)),
			    y84 + (radius84 * sin(i84 * twicePi84 / triangleAmount84))
			);
		}

		glEnd();


    int i85;//car

    GLfloat x85=-0.58f; GLfloat y85=-0.68f; GLfloat radius85 =.018f;
	int triangleAmount85 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi85 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(250, 250, 250);
		glVertex2f(x85, y85); // center of circle
		for(i85 = 0; i85 <= triangleAmount85;i85++) {
			glVertex2f(
		            x85 + (radius85 * cos(i85 *  twicePi85 / triangleAmount85)),
			    y85 + (radius85 * sin(i85 * twicePi85 / triangleAmount85))
			);
		}

		glEnd();


		int i86;//car

    GLfloat x86=-0.34f; GLfloat y86=-0.68f; GLfloat radius86 =.03f;
	int triangleAmount86 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi86 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0, 0, 0);
		glVertex2f(x86, y86); // center of circle
		for(i86 = 0; i86 <= triangleAmount86;i86++) {
			glVertex2f(
		            x86 + (radius86 * cos(i86 *  twicePi86 / triangleAmount86)),
			    y86 + (radius86 * sin(i86 * twicePi86 / triangleAmount86))
			);
		}

		glEnd();


				int i87;//car

    GLfloat x87=-0.34f; GLfloat y87=-0.68f; GLfloat radius87 =.018f;
	int triangleAmount87 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi87 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(250, 250, 250);
		glVertex2f(x87, y87); // center of circle
		for(i87 = 0; i87 <= triangleAmount87;i87++) {
			glVertex2f(
		            x87 + (radius87 * cos(i87 *  twicePi87 / triangleAmount87)),
			    y87 + (radius87 * sin(i87 * twicePi87 / triangleAmount87))
			);
		}

		glEnd();
		//glLoadIdentity();
		glPopMatrix();

				//2nd car
    glPushMatrix();
    glTranslatef(position4,0.0f, 0.0f);
    glTranslatef(0,-.54,0);
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(.04,-.24);
    glVertex2f(0.0,-.34);
    glVertex2f(0,-.42);
    glVertex2f(.4,-.42);
    glVertex2f(.4,-.24);
    glEnd();



    glBegin(GL_QUADS);
    glColor3ub(48,51,56);
    glVertex2f(.37,-.26);
    glVertex2f(.30,-.26);
    glVertex2f(.30,-.34);
    glVertex2f(.37,-.34);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(48,51,56);
    glVertex2f(.28,-.26);
    glVertex2f(.22,-.26);
    glVertex2f(.22,-.34);
    glVertex2f(.28,-.34);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(48,51,56);
    glVertex2f(.20,-.26);
    glVertex2f(.14,-.26);
    glVertex2f(.14,-.34);
    glVertex2f(.20,-.34);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(48,51,56);
    glVertex2f(.12,-.26);
    glVertex2f(.05,-.26);
    glVertex2f(.02,-.34);
    glVertex2f(.12,-.34);
    glEnd();

    glBegin(GL_QUADS);//red
    glColor3ub(224,41,25);
    glVertex2f(.22,-.38);
    glVertex2f(.22,-.40);
    glVertex2f(0.16,-.40);
    glVertex2f(0.16,-.38);
    glEnd();

    glBegin(GL_QUADS);//red
    glColor3ub(224,41,25);
    glVertex2f(.18,-.418);
    glVertex2f(.18,-.35);
    glVertex2f(0.2,-.35);
    glVertex2f(0.2,-.418);
    glEnd();
    //glLoadIdentity();

    int i96;//car2

    GLfloat x96=0.08f; GLfloat y96=-0.42f; GLfloat radius96 =.04f;
	int triangleAmount96 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi96 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x96, y96); // center of circle
		for(i96 = 0; i96 <= triangleAmount96;i96++) {
			glVertex2f(
		            x96 + (radius96 * cos(i96 *  twicePi96 / triangleAmount96)),
			    y96 + (radius96 * sin(i96 * twicePi96 / triangleAmount96))
			);
		}

		glEnd();

		    int i97;//car

    GLfloat x97=0.08f; GLfloat y97=-0.42f; GLfloat radius97 =.025f;
	int triangleAmount97 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi97 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 250, 250);
		glVertex2f(x97, y97); // center of circle
		for(i97 = 0; i97 <= triangleAmount97;i97++) {
			glVertex2f(
		            x97 + (radius97 * cos(i97 *  twicePi97 / triangleAmount97)),
			    y97 + (radius97 * sin(i97 * twicePi97 / triangleAmount97))
			);
		}

		glEnd();

		    int i98;//car

    GLfloat x98=0.3f; GLfloat y98=-0.42f; GLfloat radius98 =.04f;
	int triangleAmount98 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi98 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x98, y98); // center of circle
		for(i98 = 0; i98 <= triangleAmount98;i98++) {
			glVertex2f(
		            x98 + (radius98 * cos(i98 *  twicePi98 / triangleAmount98)),
			    y98 + (radius98 * sin(i98 * twicePi98 / triangleAmount98))
			);
		}

		glEnd();

    int i99;//car

    GLfloat x99=0.3f; GLfloat y99=-0.42f; GLfloat radius99 =.025f;
	int triangleAmount99 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi99 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 250, 250);
		glVertex2f(x99, y99); // center of circle
		for(i99 = 0; i99 <= triangleAmount99;i99++) {
			glVertex2f(
		            x99 + (radius99 * cos(i99 *  twicePi99 / triangleAmount99)),
			    y99 + (radius99 * sin(i99 * twicePi99 / triangleAmount99))
			);
		}

		glEnd();
		glLoadIdentity();
		glPopMatrix();

		//flower
    glPushMatrix();
    glTranslatef(.5,0,0);
    glScalef(.8,.8,0);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();
    //glLoadIdentity();
    //glPopMatrix();

        int i100;//flower

    GLfloat x100=0.003f; GLfloat y100=-0.36f; GLfloat radius100 =.025f;
	int triangleAmount100 = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi100 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 40, 60);
		glVertex2f(x100, y100); // center of circle
		for(i100 = 0; i100 <= triangleAmount100;i100++) {
			glVertex2f(
		            x100 + (radius100 * cos(i100 *  twicePi100 / triangleAmount100)),
			    y100 + (radius100 * sin(i100 * twicePi100 / triangleAmount100))
			);
		}

		glEnd();
		glLoadIdentity();
		glPopMatrix();


		    glPushMatrix();
    glTranslatef(-.5,0,0);
    glScalef(.8,.8,0);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();
    //glLoadIdentity();
    //glPopMatrix();

        int i101;//flower

    GLfloat x101=0.003f; GLfloat y101=-0.36f; GLfloat radius101 =.025f;
	int triangleAmount101 = 101; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi101 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(237, 40, 60);
		glVertex2f(x101, y101); // center of circle
		for(i101 = 0; i101 <= triangleAmount101;i101++) {
			glVertex2f(
		            x101 + (radius101 * cos(i101 *  twicePi101 / triangleAmount101)),
			    y101 + (radius101 * sin(i101 * twicePi101 / triangleAmount101))
			);
		}

		glEnd();
		glLoadIdentity();
		glPopMatrix();








	glFlush();  // Render now
}



//nightend
void display()
{
	glutDisplayFunc(day);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

    printf("Press d =day;\n n=night;\n r=night and rain;\n up key= cloud fast;\n left key=cloud slow;\n right key= speedy car;\n down_key=speedy rain;\n insert button=ambulance off;\n end button= speedy ambulance;\n\n\n\nSubmitted by-\nRahman, Mohammad Naimul(18-36502-1)");
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("{Press d =day; n=night; r=night and rain; up key= cloud fast; left key=cloud slow; right key= speedy car; down_key=speedy rain; insert=ambulance off; end= speedy ambulance }; "); // Create a window with the given title
	glutInitWindowSize(320, 320);   // Set the window's initial width & height
	glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutIdleFunc(Idle);
	glutTimerFunc(100, update, 0);//cloud
	glutTimerFunc(100, update1, 0);//bird
	glutTimerFunc(20, update2, 0);//car1
	glutTimerFunc(50, update3, 0);//rain
	glutTimerFunc(20, update4, 0);//car2
	glutSpecialFunc(SpecialInput);// all

	glutKeyboardFunc(handleKeypress);
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}

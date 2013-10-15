#include <cstdio>
#include <cmath>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdio>

float hist[255];
int width, height, address;
void init();
void display();

int main(int argc, char *argv[])
{
	unsigned char offset;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Prac 7");
	init();
	for(int i = 0; i <= 255; i++)
		hist[i] = 0;
	FILE *fp = fopen("l.bmp", "rb+");
	if(fp){
		fseek(fp, 10, SEEK_SET);
		fread(&offset, 4, 1, fp);
		printf("Address %d", offset);
		address = offset;
		fseek(fp, 18, SEEK_SET);
		fread(&offset, 4, 1, fp);
		printf("Width %d", offset);
		width = offset;
		fseek(fp, 22, SEEK_SET);
		fread(&offset, 4, 1, fp);
		printf("Height %d", offset);
		height = offset;
		fseek(fp, address, 0);
		for(int i = 0; i <= width * height; i++ )
		{
			fread(&offset, 1, 1, fp);
			hist[offset] = hist[offset] + 1;
		}
		fclose(fp);
	}
	else{
		printf("File not opened");
	}


	glutDisplayFunc(display);
	glutMainLoop();
    return 0;
}

void init()
{
	/* Set background in window to white
	 */

	glClearColor(1, 1, 1, 0.5);
	/* Set window co-ordinate system
	 */
	glOrtho(-1.0, 6.0, -1.0, 6.0, -1.0, 1.0);
}


void display()
{
	/* Clear all pixels
	 */
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(5, 0);
	glVertex2f(0, 0);
	glVertex2f(0, 5);
	glEnd();
	glColor3f(0, 0, 1);

	for(int i = 1; i <= 255; i++)
	{
		glBegin(GL_POLYGON);
		glVertex2f((5.0/255.0) * i, 0);
		glVertex2f((5.0/255.0) * i, (5.0/ 255.0) * hist[i]);
		glVertex2f((5.0/255.0) * i+0.2, (5.0/ 255.0) * hist[i]);
		glVertex2f((5.0/255.0) * i + 0.2, 0);
		glEnd();
	}
	glFlush();
}

nikhil abhishek
cs b
roll 57

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>

int ROUND(float a)
{
	if((a-(int)(a))>=0.5)
		return ((int)(a)+1);
	else 
		return ((int)(a));
}		


void init()
{

	glClearColor (1.0 , 1.0 , 1.0 ,0.0); 
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D(0.0,1000.0,0.0,1000.0);
}

void setpixel(int x,int y)
{
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
}

void line(int x1, int y1, int x2, int y2)
{
	int steps,i;
	float xinc,yinc;
	int x=x1;
	int y=y1;
	int dx=x2-x1;
	int dy=y2-y1;

	if (abs(dx)>abs(dy))
		steps=abs(dx);	
	else
		steps=abs(dy);

	xinc=(float)dx/(float)steps;
	yinc=(float)dy/(float)steps;

	

	for(i=0;i<steps;i++)
	{
		x+=xinc;
		y+=yinc;
		glColor3f(0.0,0.0,0.0);
		setpixel(ROUND(x),ROUND(y));
	}
	glFlush();
}


void chessboard()
{
	int c=0;
	int i,j,k;
	for(i=100;i<500;i+=50)
	{
		for(j=50;j<450;j+=50)
		{
			if(c%2==0)
			{
				for(k=i;k<(i+50);k++)
				{
					line(k,j,k,j+50);
				}
			}
			c++;
		}
		c++;
	}
}
			
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);        
	glColor3f(0.0, 0.0, 0.0);	      
	
	line(100,50,100,450);
	line(100,450,500,450);
	line(100,50,500,50);
	line(500,50,500,450);
	chessboard();
}

void main(int argc , char** argv)
{
	

	glutInit(&argc,argv);					
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);           
	glutInitWindowPosition(100,100);                       
	glutInitWindowSize(1000,1000);				
	glutCreateWindow("Chess Board");		

	init();						
	glutDisplayFunc(display);				
	glutMainLoop();
}

#include &lt;GL/glut.h&gt;
#include &lt;stdio.h&gt;
int x1, y1, x2, y2;
void myInit()
{
glClearColor(0.0, 0.0, 0.0, 1.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0, 500, 0, 500);
}
void draw_pixel(int x, int y)
{
glBegin(GL_POINTS);
glVertex2i(x, y);
glEnd();
}

15CSL68 CGV Lab Manual

Dept. of CSE, BIT 12
void draw_line(int x1, int x2, int y1, int y2)
{
int dx, dy, i, e;
int incx, incy, inc1, inc2;
int x,y;
dx = x2-x1;
dy = y2-y1;
if (dx &lt; 0) dx = -dx;
if (dy &lt; 0) dy = -dy;
incx = 1;
if (x2 &lt; x1) incx = -1;
incy = 1;
if (y2 &lt; y1) incy = -1;
x = x1; y = y1;
if (dx &gt; dy)
{
draw_pixel(x, y);
e = 2 * dy-dx;
inc1 = 2*(dy-dx);
inc2 = 2*dy;
for (i=0; i&lt;dx; i++)

{

if (e &gt;= 0)
{
y += incy;e += inc1;
}
else
e += inc2;
x += incx;
draw_pixel(x, y);
}
}
else
{
draw_pixel(x, y);
e = 2*dx-dy;
inc1 = 2*(dx-dy);
inc2 = 2*dx;
for (i=0; i&lt;dy; i++)
{
if (e &gt;= 0)
{
x+= incx;
e += inc1;
}

15CSL68 CGV Lab Manual

Dept. of CSE, BIT 13
else
e += inc2;
y += incy;
draw_pixel(x, y);
}
}
}
void myDisplay()
{
glClear(GL_COLOR_BUFFER_BIT);
draw_line(x1, x2, y1, y2);
glFlush();
}
int main(int argc, char **argv)
{
printf( &quot;Enter end points of the Line (x1, y1, x2, y2)\n&quot;);
scanf(&quot;%d %d %d %d&quot;, &amp;x1, &amp;y1, &amp;x2, &amp;y2);
glutInit(&amp;argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500, 500);
glutInitWindowPosition(0, 0);
glutCreateWindow(&quot;Bresenham&#39;s Line Drawing&quot;);
myInit();
glutDisplayFunc(myDisplay);
glutMainLoop();
return 0;
}

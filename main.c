#include <windows.h>
#include <gl/gl.h>
#include <stdio.h>
#include <math.h>
#define pi 3.14159
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void EnableOpenGL(HWND hwnd, HDC*, HGLRC*);
void DisableOpenGL(HWND, HDC, HGLRC);
struct  obj3d
{
   float xo,yo, zo,d,th,ph;
};
struct obj3
{
  float x[64000],y[64000],z[64000];
  int r[20000],type,num;
  float red,green,bluo;

};
int heart (struct obj3* a)
{float z9=0,m=0.25,j=0.0025,r2;
int I=0,n=0;

    for(float ph=0;ph<180;ph+=4){
            for(float th=0,m=0;th<360;th+=4,n++){;


            a->x[I]=cos((th)*pi/180)*sin((ph+n)*(pi/180));
  a->y[I]=(sin((th)*pi/180)*sin((ph+n)*(pi/180)));
  r2=(sin((th)*pi/180)+1)*sin((-ph+n)*(pi/180));
  a->z[I]=cos((ph+n)*pi/180)*r2;
      if(th>30&&th<150)a->y[I]+=z9,z9+=j;
float g=sqrt((a->x[I]*a->x[I])+(a->y[I]*a->y[I])+(a->z[I]*a->z[I]));

  a->x[I]*=r2,a->y[I]*=r2;
  a->y[I]-=0.3;
  if(th==90)j*=-1;
// putpixel(xi+300,yi+k,co);


        // float   r=sqrt((x[I]*x[I])+(y[I]*y[I])+(z[I]*z[I]));

//y[I]=-(r*sin(th*(pi/180))/10)*sin(ph*(pi/180));
//x[I]=(r*cos(th*(pi/180))/10)*sin(ph*(pi/180));

n=n%2;
//x=x/29;
//y=y/29;
//z=z/29;

I++;

}z9=0,m=0.25,j=0.0025;}
//printf("FFFFFFFFFFFF");
for(int i=0;i<(4050);i++)
{
   a->r[i]=i-1;
}
return 4050;
}
void rot(struct obj3 o,struct obj3d o2,float *x2,float *y2,float*z2,int len)
{
    float f=cos(-o2.th*pi/180),f2=sin(-o2.th*pi/180),f3=cos(o2.ph*pi/180),f4=sin(o2.ph*pi/180);
  for(int i=0;i<len;i++)
  {

x2[i]=(((o.x[i]*f)+(o.z[i]*f2)));
z2[i]=((o.x[i]*-f2)+(o.z[i]*f));////y r
y2[i]=((o.y[i]*f3)-(z2[i]*f4));
z2[i]=((o.y[i]*f4)+(z2[i]*f3));/////x r


  }
}
void con(char*a,char*b)
{FILE *A,*B;
char data[64000];
 A=fopen(a,"r") ;
 int i=0;
 while(!feof(A))
 {
 data[i]= getc(A);
if(data[i]=='/')data[i]=' ';
i++;
 }
 fclose(A);
 B=fopen(b,"w") ;
 fwrite(data,1,i-1,B);
  fwrite('\0',1,1,B);
 fclose(B);

}
int LoadObj(int* len,struct obj3 *o,char *b)
{FILE *A;
char h[100];
A=fopen(b,"r") ;
//fseek(A,76,0);
fgets(h,100,A);fgets(h,100,A);fgets(h,100,A);fgets(h,100,A);
printf("%s",h);

int i=0;
for(;;i++){
fscanf(A,"%s",h);
if(h[0]!='v'||h[1]!='\0')break;
fscanf(A,"%f",&(o->x[i]));
fscanf(A,"%f",&o->y[i]);
fscanf(A,"%f",&o->z[i]);
o->x[i]*=1.2;
o->y[i]*=1.2;
o->z[i]*=1.2;
//printf("%f %f %f  v\n",o->x[i],o->y[i],o->z[i]);
}int r[10000];
//getchar();
len[0]=i;
while(1)
{
    fscanf(A,"%s",h);
    if(h[0]=='f')break;
}
i=0;
o->type=3;
o->num=-1;
char c=4;
for(int v;!feof(A);i++)
{ff:
fscanf(A,"%d",&o->r[i]);
//printf("%d %d \n",o->r[i],i);
//getchar();
if(o->r[i]==0)
{o->type=4;
    c=3;
  fscanf(A,"%s",h);
     //printf("%s\n",h);
    goto ff;
}
fscanf(A,"%d",&v);


if((i+1)%c==0)
{
    fscanf(A,"%s",h);
    if(h[0]=='s')
    {
        c=4;
      fscanf(A,"%s",h);
        fscanf(A,"%s",h);
        o->num=i;

       // printf("%d",i);
        i++;
        getchar();
    }
}

//printf("%d \n",o->r[i]);
//getchar();
}
fclose(A);
return i;
}

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    WNDCLASSEX wcex;
    HWND hwnd;
    HDC hDC;
    HGLRC hRC;
    MSG msg;
    BOOL bQuit = FALSE;
    float theta = 0.0f;

    /* register window class */
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_OWNDC;
    wcex.lpfnWndProc = WindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = "GLSample";
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);;


    if (!RegisterClassEx(&wcex))
        return 0;

    /* create main window */
    hwnd = CreateWindowEx(0,
                          "GLSample",
                          "OpenGL Sample",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          1920,
                          1080,
                          NULL,
                          NULL,
                          hInstance,
                          NULL);

    ShowWindow(hwnd, nCmdShow);

    /* enable OpenGL for the window */
    EnableOpenGL(hwnd, &hDC, &hRC);
    int jj=5;
    int w[100]={0},p=0;
    w[99]=1;
float x2[6400],y2[6400],z2[6400],thc=90,thd,xc=0,yc=0,zc=10,phc=0,phd,px[2],py[2];
struct obj3 *o= malloc(2*sizeof(struct obj3));
struct obj3d *o2= malloc(100*sizeof(struct obj3d));
int l[100],rth=0,rph=0,len[100];
/*o[0].xo=0;o[0].yo=10;o[0].zo=0;
o[0].red=1;o[0].green=0;o[0].bluo=0;
o[1].xo=0;o[1].yo=-10;o[1].zo=0;
o[1].red=0;o[1].green=1;o[1].bluo=0;
o[2].xo=0;o[2].yo=20;o[2].zo=10;
o[2].red=0;o[2].green=0;o[2].bluo=1;
        len[0]=   LoadObj(&l[0],&o[0],"M.sobj");
        len[1]= LoadObj(&l[1],&o[1],"s.sobj");
         len[2]= LoadObj(&l[2],&o[2],"s.sobj");*/
         for(int i=0,x=0,z=0;i<99;i++,x++)
         {//printf("%d\n",sizeof(*o));
         if(!jj%10)z++,x=0;
             len[i]=   LoadObj(&l[i],&o[0],"s.sobj");
          o2[i].xo=x;o2[i].yo=10;o2[i].zo=0;
          o[0].red=1;o[0].green=1;o[0].bluo=0;

         }len[99]=heart(&o[1]);
         o2[99].xo=0;o2[99].yo=30;o2[99].zo=0;
          o[1].red=1;o[1].green=0;o[1].bluo=0;
l[99]=4050;
//o.red[0]=1,o.red[1]=0,o.red[2]=0,o.red[3]=0,o.red[4]=1,o.red[5]=1;
//o.green[0]=0,o.green[1]=1,o.green[2]=0,o.green[3]=1,o.green[4]=0,o.green[5]=1;
//o.bluo[0]=0,o.bluo[1]=0,o.bluo[2]=1,o.bluo[3]=1,o.bluo[4]=1,o.bluo[5]=0;
    /* program main loop */
    char dir=1;
    while (!bQuit)
    {
        if(  GetKeyState('B')<-1)
      {
          thc--;

            if(thc<0)thc+=360;
      }
      if(  GetKeyState('V')<-1)
      {thc++;

         if(thc>360)thc-=360;

      }
      if(  GetKeyState('D')<-1)
      {//printf("%d",GetKeyState('D'));
          //rth++;
         xc+=cos((thc-90)*(pi/180));
           yc+=sin((thc-90)*(pi/180));
         // rth=rth%360;
      }
      if(  GetKeyState('A')<-1)
      {
        //  rth--;
          xc+=cos((thc+90)*(pi/180));
           yc+=sin((thc+90)*(pi/180));
         // rth=rth%360;
      }
      if(  GetKeyState('W')<-1)
      {
         // rph++;
           xc+=cos(thc*(pi/180))*cos(phc*(pi/180));
           yc+=sin(thc*(pi/180))*cos(phc*(pi/180));
           zc+=sin(phc*(pi/180));
         // if(rph>180)rph-=360;
      }
      if(  GetKeyState('S')<-1)
      {
         // rph--;
           xc+=cos((thc+180)*(pi/180))*cos(phc*(pi/180));
           yc+=sin((thc+180)*(pi/180))*cos(phc*(pi/180));
           zc-=sin(phc*(pi/180));
          //if(rph<-180)rph+=360;
      }
      if(  GetKeyState('U')<-1)
      {
         // rph--;
        //if(phc>-90) o.ph--;
          zc++;
      }
      if(  GetKeyState('J')<-1)
      {//if(phc<90)o.ph++;
         zc--;
      }
      if(  GetKeyState('X')<-1)
      {
       len[0]=   LoadObj(&l[0],&o[0],"s2.sobj");
       for(int i=1;i<jj;i++)l[i]=l[0],len[i]=len[0];
      }
      if(  GetKeyState('O')<-1)
      {
       p^=1;
      }
      if(  GetKeyState('Z')<-1)
      {
       len[0]=   LoadObj(&l[0],&o[0],"s.sobj");
       for(int i=1;i<jj;i++)l[i]=l[0],len[i]=len[0];
      }
      if(  GetKeyState('K')<-1)
      {
         if(phc>-90) phc--;


      }
      if(  GetKeyState('I')<-1)
      {if(phc<90)phc++;



      }
      if(  (GetKeyState(VK_UP)<-1||(o2[0].yo-o2[99].yo<0))&&dir!=2)
      {
if(p)thc=90;
dir=1;

      }
    else  if(  (GetKeyState(VK_DOWN)<-1||(o2[0].yo-o2[99].yo>0))&&dir!=1)
      {
if(p)thc=270;
dir=2;

      }
     else if( ( GetKeyState(VK_RIGHT)<-1 ||(o2[0].xo-o2[99].xo<0))&&dir!=8)
      {
if(p)thc=0;
dir=4;

      }
     else if( ( GetKeyState(VK_LEFT)<-1||(o2[0].xo-o2[99].xo>0))&&dir!=4)
      {
dir=8;
if(p)thc=180;
      }
        /* check for messages */
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {           // printf("kKKKKKKKKKKKK");
            /* OpenGL animation code goes here */

            glClearColor(0.0f, 0.5f, 1.0f, 1.5f);
            glClear(GL_COLOR_BUFFER_BIT);

            glPushMatrix();
           // glRotatef(theta, 1.0f, 1.0f, 1.0f);
px[1]=o2[0].xo;
py[1]=o2[0].yo;
int hh=0;
for(char e=0;e<100;e++){
//xc=o2[0].xo-(cos(-thc*(pi/180))*10);yc=o2[0].yo-(sin(-thc*(pi/180))*10);zc=o2[0].zo+10;
if(p)xc=o2[5].xo,yc=o2[5].yo,zc=o2[0].zo+5;

            glBegin(GL_QUADS);
            //printf("kKKKKKKKKKKKK");
            if(e<99){
px[e%2]=o2[e+1].xo;
py[e%2]=o2[e+1].yo;
o2[e+1].xo=px[(e+1)%2];
o2[e+1].yo=py[(e+1)%2];}
if(!e)
{
    if (dir==1)o2[0].yo++;
        else if(dir==2)o2[0].yo--;
        else if(dir==4)o2[0].xo++;
        else if(dir==8)o2[0].xo--;
        if(o2[0].xo==o2[99].xo&&o2[0].yo==o2[99].yo)o2[99].xo=rand()%100,o2[99].yo=rand()%100,hh=1;
}
           // if(e<49&dir)o2[50-e].xo=o2[50-(e+1)].xo,o2[50-e].yo=o2[50-(e+1)].yo,printf("%d=%d\n",50-(e),50-(e+1));
           // else            o2[1].xo=px,o2[1].yo=py;
            o2[e].d=(sqrt(pow((xc-o2[e].xo),2)+pow((yc-o2[e].yo),2)))/2;
o2[e].th=(atan2((o2[e].yo-yc)+0.001,o2[e].xo-xc))*(180/pi);
//if(o2[e].d<1)o2[e].d=0.1;
o2[e].ph=atan2((zc-o2[e].zo),o2[e].d)*(180/pi);
thd=(thc-(o2[e].th));



if(thd>180)thd-=360;
else if(thd <-180)thd+=360;
if(o2[e].th<0)o2[e].th+=360;
rot(o[w[e]],o2[e],x2,y2,z2,l[e]);
//o[e].zo--;
//if(o2[e].zo<0)o2[e].zo=rand()%200;
//printf("%f %f %f\n",o.ph,phc,o.th);
o2[e].ph+=phc;


for(int i=0,ii=0;i<len[e]-1;i++,ii=i/4){if(i==o[w[e]].num)glEnd(),glBegin(GL_LINE_LOOP),i++;
       glColor3f(o[w[e]].red*e, o[w[e]].green, o[w[e]].bluo) ;

          glVertex4f((x2[o[w[e]].r[i]-1]+((thd/12)*o2[e].d))/3.77778,(y2[o[w[e]].r[i]-1]/2)-(o2[e].ph/50*o2[e].d),z2[o[w[e]].r[i]-1]/2,o2[e].d);

}if(e==jj-1)e=98;
          glEnd();

}if(hh)jj++,hh=0;
            glPopMatrix();

            SwapBuffers(hDC);

            //theta += 1.0f;
            Sleep (50);
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL(hwnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow(hwnd);

    return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CLOSE:
            PostQuitMessage(0);
        break;

        case WM_DESTROY:
            return 0;

        case WM_KEYDOWN:
        {
            switch (wParam)
            {
                case VK_ESCAPE:
                    PostQuitMessage(0);
                break;
            }
        }
        break;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}

void EnableOpenGL(HWND hwnd, HDC* hDC, HGLRC* hRC)
{
    PIXELFORMATDESCRIPTOR pfd;

    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC(hwnd);

    /* set the pixel format for the DC */
    ZeroMemory(&pfd, sizeof(pfd));

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW |
                  PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    iFormat = ChoosePixelFormat(*hDC, &pfd);

    SetPixelFormat(*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext(*hDC);

    wglMakeCurrent(*hDC, *hRC);
}

void DisableOpenGL (HWND hwnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRC);
    ReleaseDC(hwnd, hDC);
}


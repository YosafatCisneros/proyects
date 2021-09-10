#include<stdio.h>
#include<math.h>
#include<windows.h>
#include <graphics.h>

#define CX 320
#define CY 240
#define VR 20
#define VAL 3.14159265/180
#define T 20

void f_Vista();
void Carga();
void Incidencia();
void Adyacencia();
void Accesibilidad();
void Grado();
void Aislado();
void Colgante();
void In_Fi();
void Info_Lineas();
void classg();


int mov=5, n, auxx, auxy, na=n , e, dig, sale[T], llega[T],i, j, d[T], dd[T][2], aistaldo[T], k, bucle=0, paralelas=0, v_colgantes=0, ay=0, ay2=0, eu=0, bal=0;
int lparalelas[T]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
char incidencia[T][T]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
char adyacencia[T][T]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
char accesibilidad[T][T]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


int gd=DETECT;
int gm;
char cnv='A', nv[2] = "A";
double vx=CX+215, vy=CY, val, ang, co, si, cang=0, indix=0, indiy=0, x[T]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, y[T]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
struct arccoordstype arco;

main()
{
	f_Vista();
	int opc;
	Carga();
	system("cls");
	printf("\n\n\t\t\tMATRICES");
	printf("\n\t\t\t________");
	Incidencia();
	Adyacencia();
	Accesibilidad();

	printf("\n\n\t\tInformacion de vertices");
	printf("\n\t\t*************************");
	Grado();
	Aislado();
	Colgante();
	In_Fi();
	Info_Lineas();

	printf("\n\n\t\tClasificacion de la grafica");
	printf("\n\t\t*****************************");
	classg();

	printf("\n\n ");

	na=n;



    initgraph(&gd, &gm, "C:\\TC\\BGI");

    ang=360/n;

    co= cos (cang*VAL);
    si= sin (cang*VAL);
    vx= co*215;
    vy= si*215;

    x[0]=CX-vx;
    y[0]=CY-vy;


    for ( n, i=1; n>1; n--, i++)
        {
            cang+=ang;
            co= cos (cang*VAL);
            si= sin (cang*VAL);
            vx= co*200;
            vy= si*200;

            x[i]=CX-vx;
            y[i]=CY-vy;
        }

    if (dig == 0)//no digrafica
        {
            if (paralelas == 0)//no paralela
            {
                for(i=0; i < e; i++)
                    {
                        setcolor(BLUE);
                        if(sale[i]==llega[i]){
                            setcolor(WHITE);
                            arc(x[sale[i]-1], y[sale[i]-1]+25, 90, 90, 10);}
                        else
                            line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);
                    }
            }
            else//no digrafica pero si paralelas
            {
                for(i=0; i < e; i++)
                    {

                        if(sale[i]==llega[i]){
                            setcolor(WHITE);
                            arc(x[sale[i]-1], y[sale[i]-1]+25,90,90, 10);}
                        setcolor(BLUE);
                        line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);
                    }



                for(i=0; i < e-1; i++)
                    {
                        mov=5;
                        for(j=i+1; j < e; j++)
                            {
                                if(sale[i] == sale[j] && llega[i] == llega[j])
                                    {
                                        setcolor(GREEN);
                                        line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);
                                        line(x[sale[j]-1]-mov, y[sale[j]-1]-mov, x[llega[j]-1]-mov, y[llega[j]-1]-mov);
                                        mov+=mov;
                                    }
                                else
                                    {
                                        if(sale[i] == llega[j] && sale[j] == llega[i])
                                            {
                                                setcolor(GREEN);
                                                line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);
                                                line(x[sale[j]-1]-mov, y[sale[j]-1]-mov, x[llega[j]-1]-mov, y[llega[j]-1]-mov);
                                                mov+=mov;
                                            }

                                    }
                            }
                        }


            }





        }

    else//digrafica
    {
        if (paralelas == 0)//no paralela
            {
                for(i=0; i < e; i++)
                    {
                        setcolor(BLUE);
                        if(sale[i]==llega[i]){
                            setcolor(WHITE);
                            arc(x[sale[i]-1], y[sale[i]-1]+25,90,0, 10);
                            getarccoords(&arco);
                            auxx=arco.xend;
                            auxy=arco.yend;
                            line(auxx, auxy, auxx-8, auxy+2);
                            line(auxx, auxy, auxx+3, auxy+7);}
                        else
                            {
                                indix=0;
                                indiy=0;
                                if(y[llega[i]-1] < y[sale[i]-1]-15)//llega arriba---
                                    {
                                      if(x[llega[i]-1] > x[sale[i]-1]+15)//derecha
                                        {
                                            line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);

                                            indix+=((x[llega[i]-1]+x[sale[i]-1])*.5);
                                            indiy+=((y[sale[i]-1]+y[llega[i]-1])*.5);
                                            indix=((x[llega[i]-1]+indix)*.5);
                                            indiy=((y[llega[i]-1]+indiy)*.5);

                                            setcolor(RED);
                                            int points[6]={indix-15,indiy-5,indix,indiy,indix+5,indiy+15};
                                            setfillstyle(SOLID_FILL, RED);
                                            fillpoly(3, points);
                                        }
                                      else
                                        {
                                            if(x[llega[i]-1] < x[sale[i]-1]-15)//izquierda
                                                {
                                                   line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);

                                                   indix+=((x[llega[i]-1]+x[sale[i]-1])*.5);
                                                   indiy+=((y[sale[i]-1]+y[llega[i]-1])*.5);
                                                   indix=((x[llega[i]-1]+indix)*.5);
                                                   indiy=((y[llega[i]-1]+indiy)*.5);

                                                   setcolor(RED);
                                                   int points[6]={indix-5,indiy+15,indix,indiy,indix+15,indiy-5};
                                                   setfillstyle(SOLID_FILL, RED);
                                                   fillpoly(3, points);
                                                }
                                            else//centro
                                                {
                                                    line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);

                                                    indix+=((x[llega[i]-1]+x[sale[i]-1])*.5);
                                                    indiy+=((y[sale[i]-1]+y[llega[i]-1])*.5);
                                                    indix=((x[llega[i]-1]+indix)*.5);
                                                    indiy=((y[llega[i]-1]+indiy)*.5);

                                                    setcolor(RED);
                                                    int points[6]={indix-15,indiy+8,indix,indiy,indix+15,indiy+8};
                                                    setfillstyle(SOLID_FILL, RED);
                                                    fillpoly(3, points);
                                                }
                                        }
                                    }
                                else
                                    {
                                        if(y[llega[i]-1] > y[sale[i]-1]+15)//llega abajo
                                            {
                                                if(x[llega[i]-1] > x[sale[i]-1]+15)//derecha
                                                    {
                                                        line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);

                                                        indix+=((x[llega[i]-1]+x[sale[i]-1])*.5);
                                                        indiy+=((y[sale[i]-1]+y[llega[i]-1])*.5);
                                                        indix=((x[llega[i]-1]+indix)*.5);
                                                        indiy=((y[llega[i]-1]+indiy)*.5);

                                                        setcolor(RED);
                                                        int points[6]={indix-15,indiy+5,indix,indiy,indix+5,indiy-15};
                                                        setfillstyle(SOLID_FILL, RED);
                                                        fillpoly(3, points);
                                                    }
                                                else
                                                    {
                                                        if(x[llega[i]-1] < x[sale[i]-1]-15)//izquierda
                                                            {
                                                                line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);
                                                                indix+=((x[llega[i]-1]+x[sale[i]-1])*.5);
                                                                indiy+=((y[sale[i]-1]+y[llega[i]-1])*.5);
                                                                indix=((x[llega[i]-1]+indix)*.5);
                                                                indiy=((y[llega[i]-1]+indiy)*.5);

                                                                setcolor(RED);
                                                                int points[6]={indix-5,indiy-15,indix,indiy,indix+15,indiy+5};
                                                                setfillstyle(SOLID_FILL, RED);
                                                                fillpoly(3, points);
                                                            }
                                                        else//centro
                                                            {
                                                                line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);

                                                                indix+=((x[llega[i]-1]+x[sale[i]-1])*.5);
                                                                indiy+=((y[sale[i]-1]+y[llega[i]-1])*.5);
                                                                indix=((x[llega[i]-1]+indix)*.5);
                                                                indiy=((y[llega[i]-1]+indiy)*.5);

                                                                setcolor(RED);
                                                                int points[6]={indix-15,indiy-8,indix,indiy,indix+15,indiy-8};
                                                                setfillstyle(SOLID_FILL, RED);
                                                                fillpoly(3, points);
                                                            }
                                                    }
                                            }
                                        else//llega centro
                                            {
                                                if(x[llega[i]-1] > x[sale[i]-1])//derecha
                                                    {
                                                        line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);

                                                        indix+=((x[llega[i]-1]+x[sale[i]-1])*.5);
                                                        indiy+=((y[sale[i]-1]+y[llega[i]-1])*.5);
                                                        indix=((x[llega[i]-1]+indix)*.5);
                                                        indiy=((y[llega[i]-1]+indiy)*.5);

                                                        setcolor(RED);
                                                        int points[6]={indix-8,indiy-15,indix,indiy,indix-8,indiy+15};
                                                        setfillstyle(SOLID_FILL, RED);
                                                        fillpoly(3, points);
                                                    }
                                                else//izquierda
                                                    {
                                                        line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);

                                                        indix+=((x[llega[i]-1]+x[sale[i]-1])*.5);
                                                        indiy+=((y[sale[i]-1]+y[llega[i]-1])*.5);
                                                        indix=((x[llega[i]-1]+indix)*.5);
                                                        indiy=((y[llega[i]-1]+indiy)*.5);

                                                        setcolor(RED);
                                                        int points[6]={indix+8,indiy-15,indix,indiy,indix+8,indiy+15};
                                                        setfillstyle(SOLID_FILL, RED);
                                                        fillpoly(3, points);
                                                    }
                                            }
                                    }
                            }



                    }
            }
        else//digrafica y paralelas
            {
                for(i=0; i < e; i++)
                    {
                        setcolor(BLUE);
                        if(sale[i]==llega[i]){
                            setcolor(WHITE);
                            arc(x[sale[i]-1], y[sale[i]-1]+25,90,0, 10);
                            getarccoords(&arco);
                            auxx=arco.xend;
                            auxy=arco.yend;
                            line(auxx, auxy, auxx-8, auxy+2);
                            line(auxx, auxy, auxx+3, auxy+7);}
                        else
                            {
                                indix=0;
                                indiy=0;
                                if(y[llega[i]-1] < y[sale[i]-1]-15)//llega arriba
                                    {
                                      if(x[llega[i]-1] > x[sale[i]-1]+15)//derecha
                                        {
                                            line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);

                                            indix+=((x[llega[i]-1]+x[sale[i]-1])*.5);
                                            indiy+=((y[sale[i]-1]+y[llega[i]-1])*.5);
                                            indix=((x[llega[i]-1]+indix)*.5);
                                            indiy=((y[llega[i]-1]+indiy)*.5);

                                            setcolor(RED);
                                            int points[6]={indix-15,indiy-5,indix,indiy,indix+5,indiy+15};
                                            setfillstyle(SOLID_FILL, RED);
                                            fillpoly(3, points);
                                        }
                                      else
                                        {
                                            if(x[llega[i]-1] < x[sale[i]-1]-15)//izquierda
                                                {
                                                   line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);

                                                   indix+=((x[llega[i]-1]+x[sale[i]-1])*.5);
                                                   indiy+=((y[sale[i]-1]+y[llega[i]-1])*.5);
                                                   indix=((x[llega[i]-1]+indix)*.5);
                                                   indiy=((y[llega[i]-1]+indiy)*.5);

                                                   setcolor(RED);
                                                   int points[6]={indix-5,indiy+15,indix,indiy,indix+15,indiy-5};
                                                   setfillstyle(SOLID_FILL, RED);
                                                   fillpoly(3, points);
                                                }
                                            else//centro
                                                {
                                                    line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);

                                                    indix+=((x[llega[i]-1]+x[sale[i]-1])*.5);
                                                    indiy+=((y[sale[i]-1]+y[llega[i]-1])*.5);
                                                    indix=((x[llega[i]-1]+indix)*.5);
                                                    indiy=((y[llega[i]-1]+indiy)*.5);

                                                    setcolor(RED);
                                                    int points[6]={indix-15,indiy+8,indix,indiy,indix+15,indiy+8};
                                                    setfillstyle(SOLID_FILL, RED);
                                                    fillpoly(3, points);
                                                }
                                        }
                                    }
                                else
                                    {
                                        if(y[llega[i]-1] > y[sale[i]-1]+15)//llega abajo
                                            {
                                                if(x[llega[i]-1] > x[sale[i]-1]+15)//derecha
                                                    {
                                                        line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);

                                                        indix+=((x[llega[i]-1]+x[sale[i]-1])*.5);
                                                        indiy+=((y[sale[i]-1]+y[llega[i]-1])*.5);
                                                        indix=((x[llega[i]-1]+indix)*.5);
                                                        indiy=((y[llega[i]-1]+indiy)*.5);

                                                        setcolor(RED);
                                                        int points[6]={indix-15,indiy+5,indix,indiy,indix+5,indiy-15};
                                                        setfillstyle(SOLID_FILL, RED);
                                                        fillpoly(3, points);
                                                    }
                                                else
                                                    {
                                                        if(x[llega[i]-1] < x[sale[i]-1]-15)//izquierda
                                                            {
                                                                line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);
                                                                indix+=((x[llega[i]-1]+x[sale[i]-1])*.5);
                                                                indiy+=((y[sale[i]-1]+y[llega[i]-1])*.5);
                                                                indix=((x[llega[i]-1]+indix)*.5);
                                                                indiy=((y[llega[i]-1]+indiy)*.5);

                                                                setcolor(RED);
                                                                int points[6]={indix-5,indiy-15,indix,indiy,indix+15,indiy+5};
                                                                setfillstyle(SOLID_FILL, RED);
                                                                fillpoly(3, points);
                                                            }
                                                        else//centro
                                                            {
                                                                line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);

                                                                indix+=((x[llega[i]-1]+x[sale[i]-1])*.5);
                                                                indiy+=((y[sale[i]-1]+y[llega[i]-1])*.5);
                                                                indix=((x[llega[i]-1]+indix)*.5);
                                                                indiy=((y[llega[i]-1]+indiy)*.5);

                                                                setcolor(RED);
                                                                int points[6]={indix-15,indiy-8,indix,indiy,indix+15,indiy-8};
                                                                setfillstyle(SOLID_FILL, RED);
                                                                fillpoly(3, points);
                                                            }
                                                    }
                                            }
                                        else//llega centro
                                            {
                                                if(x[llega[i]-1] > x[sale[i]-1])//derecha
                                                    {
                                                        line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);

                                                        indix+=((x[llega[i]-1]+x[sale[i]-1])*.5);
                                                        indiy+=((y[sale[i]-1]+y[llega[i]-1])*.5);
                                                        indix=((x[llega[i]-1]+indix)*.5);
                                                        indiy=((y[llega[i]-1]+indiy)*.5);

                                                        setcolor(RED);
                                                        int points[6]={indix-8,indiy-15,indix,indiy,indix-8,indiy+15};
                                                        setfillstyle(SOLID_FILL, RED);
                                                        fillpoly(3, points);
                                                    }
                                                else//izquierda
                                                    {
                                                        line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);

                                                        indix+=((x[llega[i]-1]+x[sale[i]-1])*.5);
                                                        indiy+=((y[sale[i]-1]+y[llega[i]-1])*.5);
                                                        indix=((x[llega[i]-1]+indix)*.5);
                                                        indiy=((y[llega[i]-1]+indiy)*.5);

                                                        setcolor(RED);
                                                        int points[6]={indix+8,indiy-15,indix,indiy,indix+8,indiy+15};
                                                        setfillstyle(SOLID_FILL, RED);
                                                        fillpoly(3, points);
                                                    }
                                            }
                                    }
                            }



                    }



                for(i=0; i < e-1; i++)
                    {
                        mov=5;
                        for(j=i+1; j < e; j++)
                            {
                                if(sale[i] == sale[j] && llega[i] == llega[j])
                                    {

                                        indix=0;
                                        indiy=0;
                                if(y[llega[i]-1] < y[sale[i]-1]-15)//llega arriba
                                    {
                                      if(x[llega[i]-1] > x[sale[i]-1]+15)//derecha
                                        {
                                            //1
                                            setcolor(GREEN);
                                        line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);
                                        line(x[sale[j]-1]-mov, y[sale[j]-1]-mov, x[llega[j]-1]-mov, y[llega[j]-1]-mov);
                                        mov+=mov;

                                            indix+=((x[llega[i]-1]+x[sale[i]-1])*.5);
                                            indiy+=((y[sale[i]-1]+y[llega[i]-1])*.5);
                                            indix=((x[llega[i]-1]+indix)*.5);
                                            indiy=((y[llega[i]-1]+indiy)*.5);

                                            setcolor(RED);
                                            int points[6]={indix-15,indiy-5,indix,indiy,indix+5,indiy+15};
                                            setfillstyle(SOLID_FILL, RED);
                                            fillpoly(3, points);
                                        }
                                      else
                                        {
                                            if(x[llega[i]-1] < x[sale[i]-1]-15)//izquierda
                                                {
                                                    //2
                                                   setcolor(GREEN);
                                        line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);
                                        line(x[sale[j]-1]-mov, y[sale[j]-1]-mov, x[llega[j]-1]-mov, y[llega[j]-1]-mov);
                                        mov+=mov;
                                                   indix+=((x[llega[i]-1]+x[sale[i]-1])*.5);
                                                   indiy+=((y[sale[i]-1]+y[llega[i]-1])*.5);
                                                   indix=((x[llega[i]-1]+indix)*.5);
                                                   indiy=((y[llega[i]-1]+indiy)*.5);

                                                   setcolor(RED);
                                                   int points[6]={indix-5,indiy+15,indix,indiy,indix+15,indiy-5};
                                                   setfillstyle(SOLID_FILL, RED);
                                                   fillpoly(3, points);
                                                }
                                            else//centro
                                                {
                                                    //3
                                                    setcolor(GREEN);
                                        line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);
                                        line(x[sale[j]-1]-mov, y[sale[j]-1]-mov, x[llega[j]-1]-mov, y[llega[j]-1]-mov);
                                        mov+=mov;

                                                    indix+=((x[llega[i]-1]+x[sale[i]-1])*.5);
                                                    indiy+=((y[sale[i]-1]+y[llega[i]-1])*.5);
                                                    indix=((x[llega[i]-1]+indix)*.5);
                                                    indiy=((y[llega[i]-1]+indiy)*.5);

                                                    setcolor(RED);
                                                    int points[6]={indix-15,indiy+8,indix,indiy,indix+15,indiy+8};
                                                    setfillstyle(SOLID_FILL, RED);
                                                    fillpoly(3, points);
                                                }
                                        }
                                    }
                                else
                                    {
                                        if(y[llega[i]-1] > y[sale[i]-1]+15)//llega abajo
                                            {
                                                if(x[llega[i]-1] > x[sale[i]-1]+15)//derecha
                                                    {
                                                        //4
                                                        setcolor(GREEN);
                                        line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);
                                        line(x[sale[j]-1]-mov, y[sale[j]-1]-mov, x[llega[j]-1]-mov, y[llega[j]-1]-mov);
                                        mov+=mov;
                                                        indix+=((x[llega[i]-1]+x[sale[i]-1])*.5);
                                                        indiy+=((y[sale[i]-1]+y[llega[i]-1])*.5);
                                                        indix=((x[llega[i]-1]+indix)*.5);
                                                        indiy=((y[llega[i]-1]+indiy)*.5);

                                                        setcolor(RED);
                                                        int points[6]={indix-15,indiy+5,indix,indiy,indix+5,indiy-15};
                                                        setfillstyle(SOLID_FILL, RED);
                                                        fillpoly(3, points);
                                                    }
                                                else
                                                    {
                                                        if(x[llega[i]-1] < x[sale[i]-1]-15)//izquierda
                                                            {
                                                                //5
                                                                setcolor(GREEN);
                                        line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);
                                        line(x[sale[j]-1]-mov, y[sale[j]-1]-mov, x[llega[j]-1]-mov, y[llega[j]-1]-mov);
                                        mov+=mov;

                                                                indix+=((x[llega[i]-1]+x[sale[i]-1])*.5);
                                                                indiy+=((y[sale[i]-1]+y[llega[i]-1])*.5);
                                                                indix=((x[llega[i]-1]+indix)*.5);
                                                                indiy=((y[llega[i]-1]+indiy)*.5);

                                                                setcolor(RED);
                                                                int points[6]={indix-5,indiy-15,indix,indiy,indix+15,indiy+5};
                                                                setfillstyle(SOLID_FILL, RED);
                                                                fillpoly(3, points);
                                                            }
                                                        else//centro
                                                            {
                                                                //6
                                                                setcolor(GREEN);
                                        line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);
                                        line(x[sale[j]-1]-mov, y[sale[j]-1]-mov, x[llega[j]-1]-mov, y[llega[j]-1]-mov);
                                        mov+=mov;

                                                                indix+=((x[llega[i]-1]+x[sale[i]-1])*.5);
                                                                indiy+=((y[sale[i]-1]+y[llega[i]-1])*.5);
                                                                indix=((x[llega[i]-1]+indix)*.5);
                                                                indiy=((y[llega[i]-1]+indiy)*.5);

                                                                setcolor(RED);
                                                                int points[6]={indix-15,indiy-8,indix,indiy,indix+15,indiy-8};
                                                                setfillstyle(SOLID_FILL, RED);
                                                                fillpoly(3, points);
                                                            }
                                                    }
                                            }
                                        else//llega centro
                                            {
                                                if(x[llega[i]-1] > x[sale[i]-1])//derecha
                                                    {
                                                        //7
                                                        setcolor(GREEN);
                                        line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);
                                        line(x[sale[j]-1]-mov, y[sale[j]-1]-mov, x[llega[j]-1]-mov, y[llega[j]-1]-mov);
                                        mov+=mov;
                                                        indix+=((x[llega[i]-1]+x[sale[i]-1])*.5);
                                                        indiy+=((y[sale[i]-1]+y[llega[i]-1])*.5);
                                                        indix=((x[llega[i]-1]+indix)*.5);
                                                        indiy=((y[llega[i]-1]+indiy)*.5);

                                                        setcolor(RED);
                                                        int points[6]={indix-8,indiy-15,indix,indiy,indix-8,indiy+15};
                                                        setfillstyle(SOLID_FILL, RED);
                                                        fillpoly(3, points);
                                                    }
                                                else//izquierda
                                                    {
                                                        //8
                                                        setcolor(GREEN);
                                        line(x[sale[i]-1], y[sale[i]-1], x[llega[i]-1], y[llega[i]-1]);
                                        line(x[sale[j]-1]-mov, y[sale[j]-1]-mov, x[llega[j]-1]-mov, y[llega[j]-1]-mov);
                                        mov+=mov;

                                                        indix+=((x[llega[i]-1]+x[sale[i]-1])*.5);
                                                        indiy+=((y[sale[i]-1]+y[llega[i]-1])*.5);
                                                        indix=((x[llega[i]-1]+indix)*.5);
                                                        indiy=((y[llega[i]-1]+indiy)*.5);

                                                        setcolor(RED);
                                                        int points[6]={indix+8,indiy-15,indix,indiy,indix+8,indiy+15};
                                                        setfillstyle(SOLID_FILL, RED);
                                                        fillpoly(3, points);
                                                    }
                                            }
                                    }
                                    }
                            }
                        }


            }
    }

	for ( n=na, i=0; n>0; n--, i++, cnv++)
        {
            setcolor(MAGENTA);
            circle(x[i], y[i], VR);

            setfillstyle(XHATCH_FILL, MAGENTA);
            floodfill(x[i], y[i], MAGENTA);

            setcolor(YELLOW);
            nv[0]=cnv;
            outtextxy(x[i]-4, y[i]-9, nv);

        }

    getch();
    closegraph();

}


void f_Vista()
{
	system("color B");
	printf(" _______________________________________________________________________\n");
	printf("|\t\t\t\t\t\t\t\t\t|\n|\t\tPROGRAMA DE MATRICES EN TEORIA DE GRAFICAS\t\t|");
	printf("\n|\t\t___________________________________________\t\t|\n|\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\tEquipo:\t\t\t\t\t|\n");
	printf("|\t\t\t\tOMEGA\t\t\t\t\t|\n|\t\t\t\t\t\t\t\t\t|\n|\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\tIntegrantes:\t\t\t\t\t\t|\n|\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\tCisneros Ruiz Omar Yosafat\t\t\t\t|\n|\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\tOlvera Ramirez Ricardo\t\t\t\t\t|");
    printf("\n|_______________________________________________________________________|\n\n");
	system("pause");
	system("cls");
}

void Carga()
{
	system("cls");
	printf("\n\nProporsione los siguientes datos\n");
	printf("\n\nNumero de nodos del grafo: ");
	scanf("%d",&n);
	printf("\n\nNumero de lineas: ");
	scanf("%d",&e);
	printf("\nEs digrafica?\n\nsi - 1\n\nno - 0\n\nRespuesta: ");
	scanf("%d",&dig);
	system("cls");
	for(i=0; i < e; i++)
	{
		printf("\nRelacion entre los vertices:\n\n");
		printf("Escribir los nodos con numeros (Ejemplos: A->1, B->2...)\n\n");
		printf("\nLa linea %d sale del vertice: ",i+1);
		scanf("%d", &sale[i]);
		printf("\n\nLa linea %d llega al vertice: ",i+1);
		scanf("%d", &llega[i]);
		system("cls");
	}
}


void Incidencia()
{
	printf("\n\n\t\tMatriz de Incidencia");
	printf("\n\n\t\t************************");
	for(i=0; i < e; i++)
	{
		if(dig == 0)
		{
			incidencia[sale[i]-1][i]=1;
			incidencia[llega[i]-1][i]=1;
		}
		else
		{
			incidencia[sale[i]-1][i]=1;
			incidencia[llega[i]-1][i]=-1;
			if(sale[i] == llega[i])
			{
				incidencia[sale[i]-1][i]=1;
			}
		}
	}
	//Imprimir
	if(dig == 0)
	{
		printf("\n\n\n");
		for(i=0; i < n; i++)
		{
			printf("\263   ");
			for(j=0; j < e; j++)
			{
				printf("%d   ", incidencia[i][j]);
			}
			printf("\263\n\n");
		}
	}
	else
	{
		printf("\n\n\n");

		for(i=0; i < n; i++)
		{
			printf("\263   ");
			for(j=0; j < e; j++)
			{
				if((incidencia[i][j] == -1 || sale[j] == llega[j]) && incidencia[i][j] != 0)
				{
					printf("\b");
				}
				if(sale[j] == llega[j] && incidencia[i][j] == 1)
				{
					printf("\361%d   ", incidencia[i][j]);
				}
				else
				{
					printf("%d   ", incidencia[i][j]);
				}

			}
			printf("\263\n\n");
		}
	}


}



void Adyacencia()
{
	printf("\n\n\t\tMatriz de Adyacencia");
	printf("\n\n\t\t************************");
	for(i=0; i < e; i++)
	{
		adyacencia[sale[i]-1][llega[i]-1]=1;
		if(dig == 0)
		{
			adyacencia[llega[i]-1][sale[i]-1]=1;
			if(llega[i]==sale[i])
			{
				adyacencia[llega[i]-1][sale[i]-1]=1;
			}
		}

	}
	//Imprimir

	printf("\n\n\n");
	for(i=0; i < n; i++)
	{
		printf("\263   ");
		for(j=0; j < n; j++)
		{
			printf("%d   ", adyacencia[i][j]);
		}
		printf("\263\n\n");
	}

}



void Accesibilidad()
{
	printf("\n\n\t\tMatriz de Accesibilidad");
	printf("\n\n\t\t*************************");
	char matrizaux[T][T]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	char matrizM[T][T]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for(i = 0; i < n; i++)
	{
    	for(j = 0; j < n; j++)
		{
     		matrizaux[i][j] = adyacencia[i][j];
     		accesibilidad[i][j] = adyacencia[i][j];
    	}
	}
	  //ciclo
	int cont = n-2;
	while(cont)
	{
	  // Producto para M...
	   for(i=0; i < n; i++)
	   {
	   		for(j=0; j < n;j++)
			{
	            matrizM[i][j]=0;
	      	    for(k=0; k < n; k++)
				{
					matrizM[i][j]=matrizM[i][j]+(adyacencia[i][k]*matrizaux[k][j]);
	            }
	       }
	  }
	  //Sumamos para la matriz de accesibilidad
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
	     		accesibilidad[i][j] += matrizM[i][j];
	     		matrizaux[i][j] =  matrizM[i][j];
	     	}
	    }
	   cont--;
	}//Fin del ciclo

	  //Sumar matriz de indentidad y binarizar
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
	    	if(i == j)
	     	accesibilidad[i][j] = 1;
	    	if(accesibilidad[i][j] > 1)
	     	accesibilidad[i][j] = 1;
	    }
	}

	////////////////////////////
	if(dig == 0)
	{
		for(i=0; i < n; i++)
		{
			for(j=0; j < e; j++)
			{
				d[i]+=incidencia[i][j];
			}
		}
		for(j=0; j < e; j++)
		{
			if(sale[j]==llega[j])
			{
				d[sale[j]-1]+=1;
			}
		}
		j=1;
		for(i=0; i < n; i++)
		{
			j++;
		}
	}
	else
	{
		for(i=0; i < n; i++)
		{
			for(j=0; j < e; j++)
			{
				if(incidencia[i][j] == 1)
				{
					dd[i][1]+=1;
				}
				else
				{
					if(incidencia[i][j] == -1)
					{
						dd[i][0]+=1;
					}
				}
			}
		}
		//Suma del bucle a interno
		for(j=0; j < e; j++)
		{
			if(sale[j]==llega[j])
			{
				dd[sale[j]-1][0]+=1;
			}
		}
		j=1;
		for(i=0; i < n; i++)
		{
			j++;
		}
	}
	d[T]=0;
	dd[T][2]=0;
	//////////////

	printf("\n\n\n");
	for(i=0; i < n; i++)
	{
		printf("\263   ");
		for(j=0; j < n; j++)
		{
			if(accesibilidad[i][j] == 1)
			{
				if(i==j && (d[i]==0 || dd[i][0] && dd[i][1]) )
				{
					printf("0    ", accesibilidad[i][j]);
				}
				else
				{
					printf("+    ", accesibilidad[i][j]);
				}
			}
			else
			{
				printf("%d    ", accesibilidad[i][j]);
			}
		}
		printf("\263\n\n");
	}
	//Checar si el vertice ailado seria 0 o + porque lo tengo como + ya que esta en si mismo
}


void Grado()
{
	printf("\n\n\tGrado del los vertices\n\n");
	if(dig == 0)
	{
		for(i=0; i < n; i++)
		{
			for(j=0; j < e; j++)
			{
				d[i]+=incidencia[i][j];
			}
		}
		//Suma del bucle
		for(j=0; j < e; j++)
		{
			if(sale[j]==llega[j])
			{
				d[sale[j]-1]+=1;
			}
		}
		j=1;
		for(i=0; i < n; i++)
		{
            printf("dv[%d] = %d\n",j, (d[i]/2));
			j++;
			if(d[i]%4!=0)
            {
                ay++;
                if(d[i]%2==0)
                    ay2++;
            }
		}
	}
	else
	{
		for(i=0; i < n; i++)
		{
			for(j=0; j < e; j++)
			{
				if(incidencia[i][j] == 1)
				{
					dd[i][1]+=1;
				}
				else
				{
					if(incidencia[i][j] == -1)
					{
						dd[i][0]+=1;
					}
				}
			}
		}
		//Suma del bucle a interno
		for(j=0; j < e; j++)
		{
			if(sale[j]==llega[j])
			{
				dd[sale[j]-1][0]+=1;
			}
		}
		j=1;
		for(i=0; i < n; i++)
		{
			printf("\n\nd-+[%d] = ( %d , %d)",j, dd[i][0]/2, dd[i][1]/2);// interno - dd[i][0] externo + dd[i][1]
			j++;

			if(dd[i][0]!=dd[i][1])
            {
                if(dd[i][0]>dd[i][1])
                {
                    ay++;
                }
                else
                    ay2++;
            }
		}
	}


}



void Aislado()
{
	printf("\n\n\tVertices aislados:\n");
	k=0;
	if(dig == 0)
	{
		for(i=0; i < n; i++)
		{
			if(d[i] == 0)
			{
				printf("\nVertice %d\n", i+1);
			}
			else
			{
				k+=1;
			}
		}
		if(k-n == 0)
		{
			printf("\nNo se encontraron vertices aislados");
		}
	}
	else
	{
		for(i=0; i < n; i++)
		{
			if(dd[i][0] == 0 && dd[i][1] == 0)
			{
				printf("\nVertice %d\n", i+1);
			}
			else
			{
				k+=1;
			}
		}
		if(k-n == 0)
		{
			printf("\n\nNo se encontraron vertices aislados");
		}
	}

}


void Colgante()
{
	if(dig == 0)
	{
		printf("\n\n\tVertices colgantes:\n");
		k=0;
		for(i=0; i < n; i++)
		{
			if(d[i] == 1)
			{
				printf("\nVertice %d\n", i+1);
				v_colgantes++;
			}
			else
			{
				k+=1;
			}
		}
		if(k-n == 0)
		{
			printf("\n\nNo se encontraron vertices colgantes");
		}
	}

}


void In_Fi()
{
	if(dig == 1)
	{
		printf("\n\n\tVertices iniciales:\n");
		k=0;
		for(i=0; i < n; i++)
		{
			if(dd[i][0] == 0 && dd[i][1] != 0)
			{
				printf("\nVertice %d\n", i+1);
			}
			else
			{
				k+=1;
			}
		}
		if(k-n == 0)
		{
			printf("\nNo se encontraron vertices iniciales");
		}


		printf("\n\n\tVertices terminales:\n");
		k=0;
		for(i=0; i < n; i++)
		{
			if(dd[i][0] != 0 && dd[i][1] == 0)
			{
				printf("\nVertice %d\n", i+1);
			}
			else
			{
				k+=1;
			}
		}
		if(k-n == 0)
		{
			printf("\nNo se encontraron vertices terminales");
		}
	}
}



void Info_Lineas()
{
	printf("\n\n\n\t\tInformacion de lineas");
	printf("\n\t\t****************************");
	printf("\n\n\n\tLineas paralelas:\n\n");
	int aux=0;
	if(dig == 0)
	{
		for(i=0; i < e-1; i++)
		{
			for(j=i+1; j < e; j++)
			{
				if(sale[i] == sale[j] && llega[i] == llega[j])
				{
					printf("\n\nLineas %d y %d", i+1, j+1);
					paralelas++;
					lparalelas[i]=1;
					lparalelas[j]=1;
					aux++;
				}
				else
				{
					if(sale[i] == llega[j] && sale[j] == llega[i])
					{
						printf("\nLineas %d y %d", i+1, j+1);
						paralelas++;
						lparalelas[i]=1;
						lparalelas[j]=1;
						aux++;
					}
				}
			}
		}
		if(paralelas == 0)
		{
			printf("No se encontraron lineas paralelas");
		}
	}
	else
	{
		if(dig==1)
		{
			for(i=0; i < e-1; i++)
			{
				for(j=i+1; j < e; j++)
				{
					if(sale[i] == sale[j] && llega[i] == llega[j] )
					{
						printf("\n\nLineas %d y %d", i+1, j+1);
						paralelas++;
						lparalelas[i]=1;
						lparalelas[j]=1;
						aux++;
					}
				}
			}
		}
		if(paralelas == 0)
		{
			printf("No se encontraron lineas paralelas");
		}
	}

	//Bucles
	printf("\n\n\n\tBucles:\n\n");

	for(i=0; i < e; i++)
	{
		if(sale[i]==llega[i])
		{
			printf("Linea %d\n",i+1);
			bucle++;
		}

	}
	if(bucle==0)
	{
		printf("\nNo se encontraton bucles");
	}
	//Lineas en serie
	if(dig==0)
	{
		printf("\n\n\n\tLineas en serie:");
		aux=0;

		for(i=0; i < e-1; i++)
		{
			for(j=i+1; j < e; j++)
			{
				if(sale[i] == sale[j])
				{
					if((d[sale[i]-1]/2)==2 && (d[sale[j]-1]/2)==2)
					{
						if(lparalelas[i] == 0 && lparalelas[j] == 0)
						{
							printf("\n\nLineas %d y %d\n",i+1, j+1);
							aux++;
						}
					}
				}
				else
				{
					if(sale[i] == llega[j])
					{
						if((d[sale[i]-1]/2)==2 && (d[llega[j]-1]/2)==2)
						{
							if(lparalelas[i] == 0 && lparalelas[j] == 0)
							{
								printf("\n\nLineas %d y %d\n",i+1, j+1);
								aux++;
							}
						}
					}
					else
					{
						if(llega[i] == sale[j])
						{
							if((d[llega[i]-1]/2)==2 && (d[sale[j]-1]/2)==2)
							{
								if(lparalelas[i] == 0 && lparalelas[j] == 0)
								{
									printf("\n\nLineas %d y %d\n",i+1, j+1);
									aux++;
								}
							}
						}
						else
						{
							if(llega[i] == llega[j])
							{
								if((d[llega[i]-1]/2)==2 && (d[llega[j]-1]/2)==2)
								{
									if(lparalelas[i] == 0 && lparalelas[j] == 0)
									{
										printf("\n\nLineas %d y %d\n",i+1, j+1);
										aux++;
									}
								}
							}
						}
					}
				}
			}
		}
		if(aux==0)
		{
			printf("\n\nNo se encontraron lineas en serie");
		}
	}
}

void classg()
{
	int ve_de=0, aux, simple, mismogrado=0, conectada=0;
	printf("\n\n\nLa grafica es:\n");
	//Simple o general
	if(bucle == 0 && paralelas == 0)
	{
		printf("\n\nSIMPLE");
		simple=1;
	}
	else
	{
		printf("\n\nGENERAL");
		simple=0;
	}

	//Conectada o desconectada
	aux=0;
	for(i=0; i < n; i++)
	{
		for(j=0; j < n; j++)
		{
			if(adyacencia[j][i] == 0)
			{
				aux++;
			}
		}
		if(aux == n)
		{
			ve_de++;
		}
		aux=0;
	}
	if(ve_de == 0)
	{
		printf("\n\nCONECTADA");
		conectada=1;
	}
	else
	{
		printf("\n\nDESCONECTADA");
		conectada=0;
	}

	// Regular
	//
	if(dig == 0)
	{
		aux=0;
		for(i=0; i < n-1; i++)
		{
			if(d[i]==d[i+1])
			{
				aux++;
			}
		}
		if(aux==n-1)
		{
			mismogrado=1;
		}
		else
		{
			mismogrado=0;
		}
		//
		if(simple==1 && mismogrado == 1)
		{
			printf("\n\nREGULAR");
		}
		else
		{
			printf("\n\nNO REGULAR");
		}

	}
	else
	{
		aux=0;
		for(i=0; i < n-1; i++)
		{
			if(dd[i][0]==dd[i+1][0])
			{
				aux++;
			}
		}
		for(i=0; i < n-1; i++)
		{
			if(dd[i][1]==dd[i+1][1])
			{
				aux++;
			}
		}
		if(aux==(n-1)*2)
		{
			mismogrado=1;
		}
		else
		{
			mismogrado=0;
		}
		if(mismogrado == 1)
		{
			printf("\n\nREGULAR");
		}
		else
		{
			printf("\n\nNO REGULAR");
		}
	}
	/////Completa
	aux=1;
	for(i=0; i < n; i++)
	{
		for(j=0; j < n; j++)
		{
			if(i != j)
			{
				if(adyacencia[i][j] != 1)
				{
					aux=0;
				}
			}
		}
	}
	if(dig == 0)
	{
		if(simple==1 && aux==1)
		{
			printf("\n\nCOMPLETA");
		}
		else
		{
			printf("\n\nNO ES COMPLETA");
		}
	}
	else
	{
		if(aux==1)
		{
			printf("\n\nCOMPLETA");
		}
		else
		{
			printf("\n\nNO ES COMPLETA");
		}
	}
	///Arbol
	if(dig == 0)
	{
		if(bucle == 0 && e==n-1 && conectada == 1 && v_colgantes > 0 && v_colgantes<=2)
		{
			printf("\n\nES UN ARBOL");
		}
		else
		{
			printf("\n\nNO ES UN ARBOL");
		}
	}
	///Simetrica
	if(dig == 1)
	{
		int simetria;
		if(e%2 == 0)
		{
			simetria=e/2;
			aux=0;
			for(i=0; i < e-1; i++)
			{
				for(j=i+1; j < e; j++)
				{
					if(sale[i] == llega[j] && sale[j] == llega[i])
					{
						aux++;
					}
				}
			}
			if(aux == simetria)
			{
				printf("\n\nSIMETRICA");
			}
			else
			{
				printf("\n\nANTISIMETRICA");
			}
		}
		else
		{
			printf("\n\nANTISIMETRICA");
		}
	}
	/////Balanceada
	if(dig == 1)
	{
		aux=0;
		for(i=0; i < n; i++)
		{
			if(dd[i][0] == dd[i][1])
			{
				aux++;
			}
		}
		if(aux == n)
		{
			printf("\n\nBALANCEADA");
			bal=1;
		}
		else
		{
			printf("\n\nNO BALANCEADA");
		}
	}

	//uni
	if(dig == 1)
        {
            if (ay==1 && ay2==1)
                printf("\n\nUNICURSAL");
            else
                printf("\n\nNO UNICURSAL");
        }
    else
        {
            if (ay2==2)
                printf("\n\nUNICURSAL");
            else
                printf("\n\nNO UNICURSAL");
        }
	//Euler
	if(dig == 1)
        {
            if(bal==1 && conectada==1)
                printf("\n\nEULERIANA");
            else
                printf("\n\nNO EULERIANA");
        }
    else
        {

            if (ay==0 )
            {
                printf("\n\nEULERIANA");
                eu=1;
            }
            else
                printf("\n\nNO EULERIANA");
        }

	//hermit
	/*if(dig == 1)
        {

        }
    else
        {
            if(eu==1)
            {
                printf("\n\nHERMITIANA");
            }
        }*/
}

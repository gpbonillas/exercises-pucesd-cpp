	/* *********************************************** */
	/*	Libreria para el manejo del mouse          */
	/*	Desarrollada por Raul Marmolejo            */
	/*	    www.raul.marmolejo.net                 */
	/*	  raulgerardo@marmolejo.net                */
	/*	  Probada con Turbo C++ 3.0                */
	/* *********************************************** */

#include <dos.h>
#if defined(__COMPACT__) || defined(__LARGE__) || defined(__HUGE__)

void VerMouse(void)
{
   asm{
      mov ax,0x01
      int 0x33
     }
}
void OcultarMouse(void)
{
   asm{
      mov ax,0x02
      int 0x33
     }
}


/*************************************************/
/* LA FUNCION mxpos                              */
/* Nos dice la coordenada X del rat?n.           */
/* Es necesario enviar un par?metro.             */
/*    1 => modo gr?fico.                         */
/*    8 => modo texto.                           */
/* Retorna la posici?n horizontal del rat?n.     */
/*************************************************/
union REGS reg;

int mxpos(int modo)
{
	reg.x.ax = 0x3;
	int86(0x33, &reg, &reg);
	return reg.x.cx/modo;
}


/*************************************************/
/* LA FUNCION mypos                              */
/* Nos dice la coordenada Y del rat?n.           */
/* Es necesario enviar un par?metro.             */
/*    1 => modo gr?fico.                         */
/*    8 => modo texto.                           */
/* Retorna la posici?n vertical del rat?n.       */
/*************************************************/

int mypos(int modo)
{
	reg.x.ax = 0x3;
	int86(0x33, &reg, &reg);
	return reg.x.dx/modo;
}

/*************************************************/
/* LA FUNCION mclick                             */
/* Nos dice si hay alg?n bot?n presionado.       */
/* No es necesario enviar ning?n par?metro.      */
/* Retorna: 0 => ning?n bot?n presionado.        */
/*          1 => bot?n izquierdo presionado.     */
/*          2 => bot?n derecho presionado.       */
/*************************************************/

int mclick(void)
{

	int r = 0;
	reg.x.ax = 0x5;
	reg.x.bx = 0;
	int86(0x33, &reg, &reg);
	if ((reg.x.ax) & 1) r = 1;
	else if ((reg.x.ax>>1) & 1) r = 2;
	return r;
}
void limpia(void)
{
   do{
   }while(mclick()!=0);
}
int evento(void)
{
  int ev;
 do{
 limpia();
  if(kbhit())
   {
    ev=rm3getch(0);
    }
  else
   ev=mclick();
  }while(ev==0);
 return ev;
}

void movermouse(int Mx, int My, int modo)
	/* mueve el cursor del raton*/
	{


		reg.x.ax=4;
		reg.x.cx=Mx;
		reg.x.dx=My;
		if(modo==8){
			reg.x.cx <<=3;
			reg.x.dx <<=3;
		}
		if(modo==1)reg.x.cx <<=1;
		int86(0x33,&reg,&reg);
	}

int ratondentro2(int X1, int Y1, int X2, int Y2, int MODO)
{
	return (mxpos(MODO) >= X1) && (mxpos(MODO) <=X2) && (mypos(MODO) >= Y1) && (mypos(MODO) <= Y2);
}



// Diferentes formas para el cursor del mouse
static const int marca[] ={ 5, 14
, 0xFFF0, 0xFFE0, 0xFFC0, 0xFF81, 0xFF03, 0x0607, 0x000F, 0x001F
, 0x803F, 0xC07F, 0xE0FF, 0xF1FF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF
, 0x0000, 0x0006, 0x000C, 0x0018, 0x0030, 0x0060, 0x70C0, 0x3980
, 0x1F00, 0x0E00, 0x0400, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 };

static const int gotero[]={ 0, 14
, 0xFFF1, 0xFFE0, 0xFFC0, 0xFF00, 0xFF81, 0xFF03, 0xFE27, 0xFC57
, 0xF8BF, 0xF17F, 0xE2FF, 0xC5FF, 0xDBFF, 0xC7FF, 0xFFFF, 0xFFFF
, 0x0, 0x8, 0x0, 0x0, 0x0, 0x40, 0xE0, 0x1C0
, 0x380, 0x700, 0xE00, 0x1C00, 0x5B00, 0xC7C0, 0xFF80, 0x0 };
static const  int punta[]={0, 0
, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF
, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF
, 0xFFFE, 0x87FE, 0x87FC, 0x8FF8, 0x9FF0, 0xFFE0, 0xFFC0, 0xFF80
, 0xFF00, 0xFE00, 0xFC00, 0xF800, 0xF000, 0xE000, 0xC000, 0x0 };
static const int lupa[]={ 5, 5
, 0xF0FF, 0xCF3F, 0xBFDF, 0xBFDF, 0x7BEF, 0x71EF, 0x7BEF, 0x7FEF
, 0xBFDF, 0xBFDF, 0xCF8F, 0xF007, 0xFF83, 0xFFC1, 0xFFE1, 0xFFF3
, 0x0, 0xF00, 0x2040, 0x0, 0x4420, 0x4E20, 0x4420, 0x4020
, 0x40, 0x20C0, 0xF80, 0x40, 0x20, 0x10, 0x8, 0x0 };
static const int aerosol[]={ 0, 14
, 0xFFFF, 0xFF1F, 0xFC0F, 0xFC37, 0xFC3B, 0xFC5D, 0xFE2E, 0xFF16
, 0xFF89, 0xFFC3, 0xFFE7, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF
, 0x2900, 0x5700, 0xA8C0, 0x51B0, 0xA138, 0x501C, 0xA00E, 0x4006
, 0xA000, 0x4000, 0x8000, 0x4000, 0x8000, 0x0, 0x8000, 0x0 };
static const int reloj[]={ 0, 0
, 0x0000, 0x0000, 0x0000, 0xC003, 0xE007, 0xF00F, 0xF81F, 0xFC3F
, 0xFC3F, 0xF81F, 0xF00F, 0xE007, 0xC003, 0x0000, 0x0000, 0x0000
, 0x0000, 0x7FFE, 0x0000, 0x1FF8, 0x0FF0, 0x0000, 0x0000, 0x0000
, 0x0180, 0x0340, 0x07E0, 0x0E78, 0x1818, 0x0000, 0x7FFE, 0x0000};

static const int flecha[]={ 0, 0
, 0x9FFF, 0x8FFF, 0x87FF, 0x83FF, 0x81FF, 0x80FF, 0x807F, 0x803F
, 0x801F, 0x800F, 0x80FF, 0x887F, 0x987F, 0xFC3F, 0xFC3F, 0xFE3F
, 0x0000, 0x2000, 0x3000, 0x3800, 0x3C00, 0x3E00, 0x3F00, 0x3F80
, 0x3FC0, 0x3E00, 0x3600, 0x2300, 0x0300, 0x0180, 0x0180, 0x0000};

static const  int cruz[]={ 7, 7
, 0xFFFF, 0xFE3F, 0xFE3F, 0xFE3F, 0xFE3F, 0xFE3F, 0xFE3F, 0x8000
, 0x8000, 0x8000, 0xFE3F, 0xFE3F, 0xFE3F, 0xFE3F, 0xFE3F, 0xFE3F
, 0x0000, 0x0140, 0x0140, 0x0140, 0x0140, 0x0140, 0x0140, 0x7E3F
, 0x0000, 0x7E3F, 0x0140, 0x0140, 0x0140, 0x0140, 0x0140, 0x0140};

static const int circulo[]={ 7, 0
, 0xF01F, 0xE00F, 0xC007, 0x8003, 0x0441, 0x0C61, 0x0381, 0x0381
, 0x0381, 0x0C61, 0x0441, 0x8003, 0xC007, 0xE00F, 0xF01F, 0xFFFF
, 0x0000, 0x07C0, 0x0920, 0x1110, 0x2108, 0x4004, 0x4004, 0x783C
, 0x4004, 0x4004, 0x2108, 0x1110, 0x0920, 0x07C0, 0x0000, 0x0000};

static const int mano[]={ 1, 0
, 0xF3FF, 0xE1FF, 0xE1FF, 0xE1FF, 0xE1FF, 0xE049, 0xE000, 0x8000
, 0x0000, 0x0000, 0x07FC, 0x07F8, 0x9FF9, 0x8FF1, 0xC003, 0xE007
, 0x0C00, 0x1200, 0x1200, 0x1200, 0x1200, 0x13B6, 0x1249, 0x7249
, 0x9249, 0x9001, 0x9001, 0x8001, 0x4002, 0x4002, 0x2004, 0x1FF8};

static const int martillo[]={ 0, 0
, 0x8003, 0x0001, 0x0001, 0x1831, 0x1011, 0x0001, 0x0001, 0x8003
, 0xF83F, 0xF83F, 0xF83F, 0xF83F, 0xF83F, 0xF83F, 0xF83F, 0xF83F
, 0x0000, 0x3FF8, 0x4284, 0x4104, 0x4284, 0x4444, 0x3FF8, 0x0380
, 0x0380, 0x0380, 0x0380, 0x0380, 0x0380, 0x0380, 0x0380, 0x0000};
static const int rm3[]={ 7, 15
, 0x1921, 0x6ABE, 0x6AB1, 0xBBE, 0x3BBE, 0x5BBE, 0x6BBE, 0x72A1
, 0xFEFF, 0xFEFF, 0xDEF7, 0xEEEF, 0xF01F, 0xF83F, 0xFC7F, 0xFEFF
, 0xE6DE, 0x9541, 0x954E, 0xF441, 0xC441, 0xA441, 0x9441, 0x8D5E
, 0x100, 0x100, 0x2108, 0x1110, 0xFE0, 0x7C0, 0x380, 0x100 };
static const int corazon[]={ 8, 15
, 0xFFFF, 0xFFFF, 0xC3E1, 0x81C0, 0x8080, 0x8000, 0x8000, 0x8000
, 0xC001, 0xC001, 0xE003, 0xF007, 0xF80F, 0xFC1F, 0xFE3F, 0xFF7F
, 0x0, 0x0, 0x3C1E, 0x7E3F, 0x7F7F, 0x7FFF, 0x7FFF, 0x7BEF
, 0x3DDE, 0x3EBE, 0x1F7C, 0xFF8, 0x7F0, 0x3E0, 0x1C0, 0x80 };

// Cambia la apariencia del cursor del mouse
void puntero(const int *cursor)
{
  OcultarMouse();
  struct SREGS rs;
  reg.x.ax=0x09;
  reg.x.bx=*(cursor);
  reg.x.cx=*(cursor+1);
  reg.x.dx=FP_OFF(cursor + 2);
  rs.es=FP_SEG(cursor + 2);
  int86x(0x33, &reg, &reg, &rs);
  VerMouse();
}

#else if
#error ? rm3 Recuerdas a un tal Huge ?
#endif
// C++ code
//
/*
   	Diseñar un contador de 0 a 99 utilizando 
   	dos displays de 7 segmentos y tres botones para
	controlar la cuenta.
	Debes implementar la técnica de multiplexación 
	para mostrar los dígitos
	en los displays. 
	El contador debe comenzar en 0 
	y debe ser capaz de aumentar o disminuir
	su valor en una unidad con los botones.
*/
#define A 7
#define B 8
#define C 9
#define D 10
#define E 11
#define F 12
#define G 13
#define pulsadorAumenta 4
#define pulsadorDisminuye 3
#define pulsadorReset 2


void setup()
{
  pinMode(7, OUTPUT);          // segmento A
  pinMode(8, OUTPUT);          // segmento B
  pinMode(9, OUTPUT);          // segmento C
  pinMode(10, OUTPUT);          // segmento D
  pinMode(11, OUTPUT);          // segmento E
  pinMode(12, OUTPUT);          // segmento G
  pinMode(13, OUTPUT);          // segmento F
  pinMode(4, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  digitalWrite(A5,0);
  digitalWrite(A4,0);
  
}


int numero = 0;
int primerContador = 0;
int segundoContador = 0;
int contadorNumeros = 0;

int leerReiniciar = 0;
int leerSumar = 0;
int leerRestar = 0;
int restarAnterior = 1;
int sumarAnterior = 1;
int reiniciarAnterior = 1;

  
void loop() {      
  
  int presionoTecla = teclaPrecionada();
 
  if(presionoTecla == pulsadorAumenta)
  {
  	contadorNumeros++;
   
      if(contadorNumeros > 99)
    {
      contadorNumeros = 0;
    }
  }
  else if(presionoTecla == pulsadorDisminuye)
  {
    contadorNumeros--;
    if(contadorNumeros < 0)
    {
      contadorNumeros = 99;
    }
  }
  else if(presionoTecla == pulsadorReset)
  {
     contadorNumeros = 0;
  }
  
  manejarDisplay(contadorNumeros);
  
}

//Funcion para manejar los numeros y el prendido y apagado de 
//displays

void manejarDisplay(int contadorNumeros)
{
  numerosDisplay(contadorNumeros/10);
  prenderDisplay(1,0);
  delay(50);
  numerosDisplay(contadorNumeros - 10*((int)contadorNumeros/10));
  prenderDisplay(0,1);
  delay(50);
  
}

//funcion para mostrar los numeros correspondientes

void numerosDisplay(int numero){
	borrar_display();
      
  switch (numero) {
	case 0:
      digitalWrite(A, 1); 
      digitalWrite(B, 1); 
      digitalWrite(C, 1); 
      digitalWrite(D, 1); 
      digitalWrite(E, 1); 
      digitalWrite(F, 1); 
      break;
  	case 1: 
      	digitalWrite(B, 1); 
      	digitalWrite(C, 1); 
    	break;
    case 2: 
      	digitalWrite(A, 1);
    	digitalWrite(B, 1); 
      	digitalWrite(G, 1); 
    	digitalWrite(E, 1); 
    	digitalWrite(D, 1); 
    	break;
    case 3: 
      	digitalWrite(A, 1);
    	digitalWrite(B, 1); 
      	digitalWrite(G, 1); 
    	digitalWrite(C, 1); 
    	digitalWrite(D, 1); 
    	break;
    case 4: 
      	digitalWrite(F, 1);
    	digitalWrite(B, 1); 
      	digitalWrite(G, 1); 
    	digitalWrite(C, 1); 
    	break;
    case 5: 
      	digitalWrite(A, 1);
    	digitalWrite(F, 1); 
      	digitalWrite(G, 1); 
    	digitalWrite(C, 1);
    	digitalWrite(D, 1);
    	break;
    case 6: 
      	digitalWrite(A, 1);
    	digitalWrite(F, 1); 
      	digitalWrite(G, 1); 
    	digitalWrite(C, 1);
    	digitalWrite(E, 1);
    	digitalWrite(D, 1);
    	break;
    case 7: 
      	digitalWrite(A, 1);
    	digitalWrite(B, 1); 
    	digitalWrite(C, 1);
    	break;
    case 8: 
      	digitalWrite(A, 1); 
      	digitalWrite(B, 1); 
      	digitalWrite(C, 1); 
      	digitalWrite(D, 1); 
      	digitalWrite(E, 1); 
      	digitalWrite(F, 1);
    	digitalWrite(G, 1);
    	break;
    case 9: 
      	digitalWrite(A, 1); 
      	digitalWrite(B, 1); 
      	digitalWrite(C, 1);  
      	digitalWrite(F, 1);
    	digitalWrite(G, 1);
    	break;
  	default:
    	// statements
    	break;
}
  	
}


void borrar_display(){
	
  	digitalWrite(A, 0); 
	digitalWrite(B, 0); 
	digitalWrite(C, 0); 
	digitalWrite(D, 0); 
	digitalWrite(E, 0); 
	digitalWrite(F, 0); 
	digitalWrite(G, 0); 

}

//funcion que controla el encendido de los diaplay

void prenderDisplay(int display1, int display2){
  digitalWrite(A5, display1);
  digitalWrite(A4, display2);
}

//Funcion para recrear el antirrebote
int teclaPrecionada(void)
{
  leerReiniciar = digitalRead(pulsadorReset);
  leerSumar = digitalRead(pulsadorAumenta);
  leerRestar = digitalRead(pulsadorDisminuye);
  
  if(leerSumar == 1)
  {
    sumarAnterior = 1;
  }
  
  if(leerRestar  == 1)
  {
    restarAnterior = 1;
  }
  if(leerReiniciar  == 1)
  {
    reiniciarAnterior = 1;
  }

  if(leerSumar == 0 && leerSumar != sumarAnterior)
  {
  	sumarAnterior = leerSumar;
    return pulsadorAumenta;
  }
  
  if(leerRestar == 0 && leerRestar != restarAnterior)
  {
  	restarAnterior = leerRestar;
    return pulsadorDisminuye;
  }
  
  if(leerReiniciar == 0 && leerReiniciar != sumarAnterior)
  {
  	reiniciarAnterior = leerReiniciar;
    return pulsadorReset;
  }
  
  return 0;
}

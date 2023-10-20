# Proyecto SPD
![Tinkercad](./img/Logo-tinkercad-wordmark.svg.png)


## Integrantes 
- [Brian Romeo](https://github.com/RomeoBrian/spd)
- Dylan Peralta

## Proyecto: 
### Contador con dos displays de 7 segmentos.
![Proyecto](./img/Contador.png)
### Contador y numeros primos con Swicht
![Proyecto](./img/Swicht.PNG)
### Sensor de temperatura
![Proyecto](./img/Sensor-de-Temperatura.png)

## Descripción
El funcionamiento de este proyecto es contar, descontar o resetear dependiendo de lo que desea el usuario, mostrandolo por dos display con la tecnica de multiplexación.

## Función principal
Esta Funcion se encargara de encender los display correspondientes con el dato informado.

En el primer caso obtenemos el valor del contador y lo dividimos por 10, para obtener el numero de la decena
luego prendemos el display correspondiente a la misma para mostrar el numero indicado. 
(por ejemplo si el numero indicado es 20, al dividirlo por 10, nos devolvera 2, por lo que el primer display mostrara el numero 2)

luego mediente un delay controlaremos el encendido del siguiente display.
el cual al informarle el numero, le restaremos el resultado de la cuenta anterior, multiplicado por 10, para hallar la centena
(por ejemplo si el numero indicado es 20, al dividirlo por 10, nos devolvera 2, y al multiplicarlo por 10, nos devovlera nuevamente 20,
por ende al restarle el numero dado nos devolvera 0 como numero a mostrar en el segundo display)

~~~ C (lenguaje en el que esta escrito)
void manejarDisplay(int contadorNumeros)
{
  numerosDisplay(contadorNumeros/10); 
  prenderDisplay(1,0);
  delay(50);
  numerosDisplay(contadorNumeros - 10*((int)contadorNumeros/10)); 
  prenderDisplay(0,1);
  delay(50);
}
~~~

## :robot: Link del proyecto
- [Contador con 2 display 7 segmentos](https://www.tinkercad.com/things/4o4MSXtLEbl)
- [Contador y numeros primos con Swicht](https://www.tinkercad.com/things/936vb1Llbhp)
- [Sensor de temperatura](https://www.tinkercad.com/things/2xuGhtuZf7x)
 
## Vista Esquematica 
### Vista Esquematica Contador con 2 display 7 segmentos
![Vista Esquematica Contador con 2 display 7 segmentos](./img/vista-esquematica.PNG)
### Contador y numeros primos con Swicht
![Contador y numeros primos con Swicht](./img/Vista-esquematica-Swicht.PNG)
### Sensor de temperatura
![Sensor de temperatura](./img/Circuito-Sensor-Temperatura.png)

## :tv: Armado del circuito electrico
- [Contador con 2 display 7 segmentos](https://www.youtube.com/watch?v=jq-v3suBJPo&ab_channel=DylanPeralta)
- [Contador y numeros primos con Swicht](https://www.youtube.com/watch?v=XDhogpwIkh4&ab_channel=DylanPeralta)
- [Sensor de temperatura](https://www.youtube.com/watch?v=nUNdTDXHTAg&ab_channel=DylanPeralta)
---
### Fuentes
- [Consigna](https://drive.google.com/file/d/1UTj8HBPnR7vM235m1BswtL_SMnmYe8nO/view).

- [Guia de uso display 7 segmentos](https://www.youtube.com/watch?v=_Ry7mtURGDE&list=PL7LaR6_A2-E11BQXtypHMgWrSR-XOCeyD&index=4&ab_channel=UTNFRA).

---


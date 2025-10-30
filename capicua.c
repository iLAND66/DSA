#include <stdio.h>
#include <string.h>
#include "queue.h"

int main() {
    squeue Q1;
    create(&Q1);

    char numero[] = "";
    printf("Ingrese un numero:\n");
    scanf("%s", numero);


    return 0;
}
/*
Realiza un programa que pida al usuario un número e indica si es un número capicúa o
no. Para hacerlo lee el número en una cadena, es decir, lee los dígitos como si fueran caracteres.
Almacena cada digito en una Cola estática y en una Pila estática, después quita los dígitos uno a uno de
cada TAD(pila y cola) y comparalos por igualdad. El número es capicúa si la verificación de todos los
dígitos termina coincidiendo en orden inverso. En caso contrario no es un número capicúa. Números
capicua: 13431, 07470, 7654567.

Una tienda de alimentos es atendida por una persona, la atención de los clientes se
realiza siempre conforme es su llegada.
La tienda considera 5 tipos de asuntos a atender:
1. Compra de alimentos
2. Devolución
3. Cambio
4. Dudas
5. Otros
Utiliza una cola dinámica cuyos nodos representen a los clientes que quieren ser atendidos, cada cliente
debe contar con un identificador único y con el asunto por el que va a la tienda.
Representa con un número aleatorio entre 20 y 100 la cantidad de clientes que llegarán a la tienda, que
será la cantidad de nodos de la cola dinámica.
La tienda empieza a atender a las 9:00 am y termina de atender a las 16:30 pm. La atención de un
cliente es equivalente a la acción dequeue de la cola dinámica, cada que un cliente sea atendido genera
de manera aleatoria los minutos que tardo en ser atendido, que este valor este entre 1 y 15.
La hora en que se empieza atender al primer cliente será a las 9:00 am, para cada cliente que logre ser
atendido imprime su identificador, el asunto por el que fue, la hora en que empezó a ser atendido y la
hora final en ser atendido. Para los clientes que no alcanzaron a ser atendidos solo imprime su
identificador y un mensaje que indique que no fueron atendidos, y no olvides eliminar esos nodos.
 */
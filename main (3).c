#include // Contiene un conjunto de funciones para manipular cadenas: copiar, cambiar caracteres, comparar cadenas, etc.
#include //  Esta librería te permite leer desde o enviar información de entrada y salida
#include // Contiene los prototipos de funciones de C para gestión de memoria dinámica, control de procesos y otras.

void imprime( int *tab, int fil, int col, int ultNum )// Se define la funcion imprime con sus variables tipo entero
{
    /*
    *tab  Puntero a una matriz de tipo entero.
    fil    Entero que indica el numero de filas de la matriz.
    col    Entero que indica el numero de columnas de la matriz.
    disc  Parámetro de tipo entero que indica el numero de discos usados.
    ultNum  Entero que indica el numero que esta usando el disco mas grande.
    */


    int f, c;
    int i, esp;
    // Creacion de variables tipo entero para las operaciones en la funcion imprime


    for( c=col-1; c >= 0; c-- )// Ciclo for para que va desde la primera columna hasta la ultima
    {
        for( f=0; f < fil; f++ )// Va desde la fila mas grande hasta la fila mas pequena
        {
            esp = ( ultNum - tab[col*f+c] )/2;// la operacion da al valor esp el disco mas grande - la direccion de memoria de columna * fila + columna dividido a 2


            for( i=0; i < esp; i++ )// Ciclo for para imprimir los espacios a la izquierda que representan las columnas
                printf( " " );


            for( i=0; i < tab[col*f+c]; i++ ) // para imprimir los asteriscos
                printf( "*" );


            for( i=0; i < esp; i++ )// Para imprimir los espacios a la derecha que representan las columnas
                printf( " " );

            printf( "\t" );
        };

        printf( "\n" );
        // Imprime una tabulacion y un espacio para separar las columnas
    };


};


void mueveDisco( int *tab, int fil, int col, int ultNum, int filOrig, int filDest )
{
    /*
    *tab  Puntero a una matriz de tipo entero.
    fil    Entero que indica el numero de filas de la matriz.
    col    Entero que indica el numero de columnas de la matriz.
    disc  Parámetro de tipo entero que indica el numero de discos usados.
    ultNum  Entero que indica el numero que esta usando el disco mas grande.
    filOrig  Entero que indica el numero de fila de la matriz en la cual hay que coger el numero/disco
    filDest  Entero que indica el numero de fila de la matriz en la cual hay que dejar el numero/disco.
    Poscondición:
    Se mueve el disco y se llama a la función que imprime el tablero.
    */


    int cO=col-1, cD=col-1;


// Se busca el disco que se encuentre mas arriba y por lo tanto el mas pequeño de la fila de origen.
    while( cO >= 0  &&  tab[col*filOrig+cO] == 0 )
    {
        cO--;
    };
    if( cO < 0 )
        cO = 0;

// Ahora se calcula cual es la posición libre mas arriba de la fila de destino
    while( cD >= 0  &&  tab[col*filDest+cD] == 0 )
    {
        cD--;
    };

// Se mueve el disco de la fila de origen a la de destino:
    tab[col*filDest+cD+1] = tab[col*filOrig+cO];
    tab[col*filOrig+cO] = 0;

// Se imprime el tablero:
    imprime( tab, fil, col, ultNum );
};

void hanoi( int *tab, int fil, int col, int disc, int ultNum, int O, int A, int D )
{
    /*
     *tab  Puntero a una matriz de tipo entero.
     fil    Entero que indica el numero de filas de la matriz.
     col    Entero que indica el numero de columnas de la matriz.
     disc  Parámetro de tipo entero que indica el numero de discos usados.
     ultNum  Entero que indica el numero que esta usando el disco mas grande.
     O,A,D  Tres enteros que indican la fila desde donde se ha de coger el disco y a donde se ha de traspasar. La primera vez que se llama a hanoi tienen los valores de: 0 ,1 y 2 respectivamente.
    */


    if( disc==1 )
    {
// Se borra la pantalla, se imprime la tabla y se hace una pausa que varia dependiendo del numero de discos:
        system("cls");
        mueveDisco( tab, fil, col, ultNum, O, D );
        if(col<=5) delay(4);
        else if(col<=10) delay(3);
        else if(col<=15) delay(2);
        else if(col>15) delay(1);
        // Cuando la columna es menor o igual a 5, se ejecuta mas lento, y si es mayor de

> Wilbert Bonilla:
15, se ejecuta rapido.
    }
    else // Se llama recursivamente a hanoi, hasta resolver el tablero.
    {
        hanoi( tab, fil, col, disc-1, ultNum, O, D, A );

        system("cls");
        mueveDisco( tab, fil, col, ultNum, O, D );
        if(col<=5) delay(4);
        else if(col<=10) delay(3);
        else if(col<=15) delay(2);
        else if(col>15) delay(1);

        hanoi( tab, fil, col, disc-1, ultNum, A, O, D );


    };

};

void delay(int tiempo)
{

    int c, d;
    while(tiempo >= 0)
    {
        for (c = 1; c <= 10000; c++)
            for (d = 1; d <= 10000; d++)
            {}
        tiempo--;
    }
    // Funcion delay para ejecutar operaciones para ralentizar el procesador y la funcion imprime se ejecute maas lento.

}

main()
{
    int fil=3, col, *tablero = NULL;
    int f, c, disc=1, ultNum;
    // Se crean variables para asignar la cantidad de filas y columnas, y usar las variables en el programaa


    printf( "Indique el numero de discos: " );// imprime la informacion en pantalla
    scanf( "%i", &col );// Pide el numero de discos y los asigna a la variable columna


    tablero = (int *)malloc( sizeof(int)*fil*col );// Tablero pide memoria para guardar las variables tipo entero de bytes de tipo entero, fila y columna


// Resetea las torres poniendo "los discos" en una de ellas y 0 en el resto.
    for( f=0; f < fil; f++ )
        for( c=col-1; c >= 0; c-- )
            if( f==0 )
            {
                tablero[col*f+c] = disc;
                disc+=2;
            }
            else
                tablero[col*f+c] = 0;

    ultNum = disc;

// Se imprime el tablero antes de iniciar ningún movimiento:
    system("cls");
    imprime( tablero, fil, col, ultNum );
    delay(6);


// Se llama a hanoi para comenzar "la partida":
    hanoi( tablero, fil, col, col, ultNum, 0, 1, 2 );

    //Se llama recursivamente a hanoi hasta resolver el tablero.
};
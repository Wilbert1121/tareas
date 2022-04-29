
   
#include <stdio.h>
#include <stdlib.h>
#define ANNO_ACTUAL 2022
#define LARGO_NOMBRE 50
#define LARGO_APELLIDO 50
#define LARGO_NACIONALIDAD 50
#define LARGO_OCUPACION 50
#define LARGO_ESTADO_CIVIL 30
#define LARGO_GENERO 2
#define LARGO_LUGARNACIMIENTO 50
#define LARGO_LUGARNACIMIENTO2 50


struct lugarnacimiento{
char lugarnacimiento [LARGO_LUGARNACIMIENTO + 1];
char lugarnacimiento2 [LARGO_LUGARNACIMIENTO2 + 1];
};

struct fecha{
int dia;
int mes;
int anno;
};

struct genero{
char genero [LARGO_GENERO + 1];
};

struct nacionalidad{
char nacionalidad[LARGO_NACIONALIDAD + 1];
};

struct estado_civil{
char estado_civil[LARGO_ESTADO_CIVIL + 1];
};

struct ocupacion {
char ocupacion[LARGO_OCUPACION + 1];
};

struct persona{
char nombre[LARGO_NOMBRE + 1];
char apellido[LARGO_APELLIDO + 1];
};

struct cedula {
int cedula;
struct persona p;
struct fecha fecha_nacimiento;
struct nacionalidad n;
struct ocupacion o;
struct estado_civil es;
struct genero g;
struct lugarnacimiento lu;
};


int main() {
 struct cedula c; 
  printf("Bienvenido al sistema de cedula: \n");
  printf("ingrese su nombre y apellido: \n");
    scanf("%s" ,&c.p.nombre);
    scanf("%s" ,&c.p.apellido);
  
  printf("ingrese su numero de cedula: \n");
  scanf("%d" , &c.cedula);

  

  printf("ingrese su fecha de nacimiento (dia mes año):  \n");
  scanf("%d" , &c.fecha_nacimiento.dia);
  scanf("%d" , &c.fecha_nacimiento.mes);
  scanf("%d" , &c.fecha_nacimiento.anno);

  printf("Ingrese su nacionalidad: \n");
    scanf("%s" , &c.n.nacionalidad);

  printf("ingrese su ocupacion: \n");
    scanf("%s" , &c.o.ocupacion);
 
  printf("ingrese su estado civil: \n");
  scanf("%s" , &c.es.estado_civil);
   
  printf("ingrese su genero (Solo ingrese M para Masculino y F para Femenino): \n");
  scanf("%s" , &c.g.genero);

  printf("ingrese lugar de nacimiento: \n ");
  scanf("%s", c.lu.lugarnacimiento);
  scanf("%s", c.lu.lugarnacimiento2);
  printf("\n");

  printf("\nSu información de cedula es: \n ");
  
  printf("Cedula: %d \n " , c.cedula);
  
  printf("Nombre: %s \n " , c.p.nombre);
  
  printf("Apellido: %s \n " , c.p.apellido);
  
  printf("Su edad es: %d \n " , ANNO_ACTUAL - c.fecha_nacimiento.anno);
  
  printf("Nacionalidad: %s \n " , c.n.nacionalidad);
  
  printf("Ocupación: %s \n " , c.o.ocupacion);
  
  printf("Estado Civil: %s \n " , c.es.estado_civil);
  
  printf("Genero: %s \n " , c.g.genero);
  
  printf("Lugar de Nacimiento: %s \n " , c.lu.lugarnacimiento);
  
  printf("Fecha de expiración: %d \n " , ANNO_ACTUAL + 4);
  
  };
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void login(char userF[], char passwordF[]);
FILE *clinica;


typedef struct Vacuna
{
  int id;
  float peso;
  int edad;
  char nombre[10];
  char especie[10];
  char genero[10]; 
  char raza[10];
  char vacuna[40];
}Vacuna;

typedef struct Medicamento
{
  int id;
  char nombre[40];
  int cantidad;
  float precioU;  
}Medicamento;

typedef struct MedicamentoPedido
{
  int id;
  int cantidad;
}MedicamentoPedido;

int medicamentoid[100];

typedef struct horario
{
  int id;
  char dia[10];
  char hora[10];
  int disponible;
}horario;

Medicamento registrarmed (int id);
char nombreCliente[40];
Vacuna ingresarinfo (int id);
horario horarios[100];
void cargarHorario ();
void ListarHorario ();
char user[20],password[20];
float precioTotal = 0;

int main(void) 
{
  
    printf ("BIENVENIDO A LA CLINICA VETERINARIA\n");
    printf ("\t\t\tSALUD ANIMAL\n");
    printf("Por favor digite su usuario y contraseña \n");
    printf ("Usuario: ");
    scanf("%s",user);
    printf ("Contraseña: ");
    scanf("%s",password);
    login(user,password);

  return 0;
}

void login(char userF[], char passwordF[]) 
{
  int op;
  if((strcmp(userF,"SaludAnimal")==0) &&(strcmp(passwordF,"123")==0))
  {
    Vacuna vacunas [100];
    Vacuna vacunasTemporal;
    Medicamento medicamentos [100];
    MedicamentoPedido medicamentoPedidos [100];
    int numMascota = 0;
    int numMed;
    int Nmedicamentos;
    int op;
    int j=0;
    int p=0;
  
    cargarHorario();
    

    do {
        printf("\n\t\t Menu principal \n\n");
        printf("A continuacion le presentamos nuestros servicios disponibles \n");
        printf("1.- Vacunas \n");
        printf ("2.- Listado de mascotas vacunadas\n");
        printf ("3.- Buscar mascotas en el registro\n");
        printf ("4.- Ordenar mascotas registradas\n");
        printf("5.- Servicio a domicilio \n");
        printf ("\t\t Farmacia virtual \n");
        printf ("6.-Registro de medicamentos\n");
        printf ("7.- Hacer pedido\n");
        printf ("8.- Mostrar factura\n");
        printf ("9.- Salir\n");
        printf("Ingrese una opción: \n");
        scanf("%d", &op);
        switch (op) 
        {
        case 1:
        {
          printf("\t***Registre la Información de la Mascota***\n");
          vacunas[numMascota] = ingresarinfo(numMascota);
          numMascota++;
          clinica = fopen("vacunas.txt", "w");
          printf("\n");
          
            for(int i=0; i<numMascota; i++)
            {
                fprintf(clinica,"%s %d %s %s %s %f %d %s %s"," ", vacunas[i].id, vacunas[i].nombre,vacunas[i].especie,vacunas[i].genero,vacunas[i].peso,vacunas[i].edad,vacunas[i].raza, vacunas[i].vacuna);
            }
            fclose(clinica);
            printf("\n");
          break;
        }
        case 2:
        {
          printf("\t\t**********Detalle de los Pacientes**********\n");
          printf("ID\tNOMBRE\t\tESPECIE\t\tGENERO\t\tPESO\tEDAD\t\tRAZA\tVACUNA\n");
          printf("--------------------------------------------------------\n");
          
          clinica=fopen("vacunas.txt", "r");
            j = 0;
            while(feof(clinica)==0)
            {
                fscanf(clinica,"%d",&vacunas[j].id);
                fscanf(clinica,"%s",vacunas[j].nombre);
                fscanf(clinica,"%s",vacunas[j].especie);
                fscanf(clinica,"%s",vacunas[j].genero);
                fscanf(clinica,"%f",&vacunas[j].peso);
                fscanf(clinica,"%d",&vacunas[j].edad);
                fscanf(clinica,"%s",vacunas[j].raza);
                fscanf(clinica,"%s",vacunas[j].vacuna);
                
                printf("%d   ",vacunas[j].id);
                printf("%s      ",vacunas[j].nombre);
                printf("%s      ",vacunas[j].especie);
                printf("%s      ",vacunas[j].genero);
                printf("%.2f       ",vacunas[j].peso);
                printf("%d       ",vacunas[j].edad);
                printf("%s  ",vacunas[j].raza);
                  printf("%s \n",vacunas[j].vacuna);
                  j++;
            }
          
          
          break;
        }
       case 3:
       {
          int encontrado=0;
          int parametro;
          char parametroBusqueda[10];
          printf ("Ingrese el parametro por el que desea buscar su mascota\n");
          printf ("1.- Nombre\n");
          printf ("2.- Especie\n");
          scanf ("%d",&parametro);

          printf ("Ingrese el parametro de busqueda\n");
          scanf ("%s",parametroBusqueda);    
          
          for (int i=0; i<numMascota; i++)
          {
            if(parametro == 1)
            {
              if((strcmp(vacunas[i].nombre,parametroBusqueda)==0))
              {
                printf("\t\t**********Lista de mascotas**********\n");
                printf("ID\t\tN.MASCOTA\t\tESPECIE\tEDAD\tGENERO\t\tRAZA\t\tPESO\tVACUNA\n");
                encontrado = 1;
                printf("\n%d\t\t\t%s\t\t%s\t\t %d\t\t%s\t\t%s\t\t%.2f\t\t%s\n",vacunas[i].id,vacunas[i].nombre,vacunas[i].especie,vacunas[i].edad,vacunas[i].genero,vacunas[i].raza,vacunas[i].peso, vacunas[i].vacuna);  
              }
            }
            if (parametro==2)
            {
                if((strcmp(vacunas[i].especie,parametroBusqueda)==0))
              {
                printf("\t\t**********Lista de mascotas**********\n");
                printf("ID\t\tN.MASCOTA\t\tESPECIE\tEDAD\tGENERO\t\tRAZA\t\tPESO\tVACUNA\n");
                encontrado = 1;
                printf("\n%d\t\t\t%s\t\t%s\t %d\t\t%s\t\t%s\t\t%.2f\t%s\n",vacunas[i].id,vacunas[i].nombre,vacunas[i].especie,vacunas[i].edad,vacunas[i].genero,vacunas[i].raza,vacunas[i].peso, vacunas[i].vacuna); 
              }
            }
          }          
          if(encontrado == 0) 
            {
              printf ("La mascota no se encuentra registrada en la lista");
            }
         break;
       }
       case 4:
       {
         int parametro;
         printf ("Elija el parametro por el que desea que se orden las mascotas\n");
         printf ("1.- Peso\n");
         printf ("2.- Edad\n");
         scanf ("%d",&parametro);
         printf ("ID\t \tNOMBRE\t \tESPECIE\t \tEDAD\t \tGENERO\t \tRAZA\t \tPESO\t \tVACUNA\n");
         clinica= fopen("vacunas.txt", "r");
         j = 0;
         while(feof(clinica)==0)
         {
            fscanf(clinica,"%d",&vacunas[j].id);
            fscanf(clinica,"%s",vacunas[j].nombre);
            fscanf(clinica,"%s",vacunas[j].especie);
            fscanf(clinica,"%s",vacunas[j].genero);
            fscanf(clinica,"%f",&vacunas[j].peso);
            fscanf(clinica,"%d",&vacunas[j].edad);
            fscanf(clinica,"%s",vacunas[j].raza);
            fscanf(clinica,"%s",vacunas[j].vacuna); 
            j++;

         }

        fclose(clinica);
      
         int i,k,aux;
         if (parametro==1)
         {
            for(i=0;i<j;i++)
            {
              for(k=0; k < j-1; k++)
              {
                  if(vacunas[k].peso>vacunas[k+1].peso)
                  {
                    
                    memcpy(&vacunasTemporal, &vacunas[k], sizeof(struct Vacuna));
                    memcpy(&vacunas[k], &vacunas[k+1], sizeof(struct Vacuna));
                    memcpy(&vacunas[k+1], &vacunasTemporal, sizeof(struct Vacuna));
                  }
              }
            }

         }
         else
         {
           for(i=0;i<j;i++)
            {
              for(k=0; k < j-1; k++)
              {
                  if(vacunas[k].edad>vacunas[k+1].edad)
                  {
                    memcpy(&vacunasTemporal, &vacunas[k], sizeof(struct Vacuna));
                    memcpy(&vacunas[k], &vacunas[k+1], sizeof(struct Vacuna));
                    memcpy(&vacunas[k+1], &vacunasTemporal, sizeof(struct Vacuna));
                  }
              }
            
            }
         }

         for(int i = 0; i<j; i++)
            {
              printf("\n%d\t\t%s\t%s\t %d\t\t%s\t\t%s\t\t%.2f\t%s\n",vacunas[i].id,vacunas[i].nombre,vacunas[i].especie,vacunas[i].edad,vacunas[i].genero,vacunas[i].raza,vacunas[i].peso, vacunas[i].vacuna); 
            }
        
         break;   
       }
        case 5:
        {
          printf ("ID\t  \tDIA\t \tHORA\t \tDISPONIBLE\n");
          int idhorario = 0;
            ListarHorario ();
            clinica = fopen("horario.txt", "r");
            j = 0;
            while(feof(clinica)==0)
            {
                fscanf(clinica,"%d",&horarios[j].id);
                fscanf(clinica,"%s",horarios[j].dia);
                fscanf(clinica,"%s",horarios[j].hora);
                fscanf(clinica,"%d",&horarios[j].disponible);
                j++;
            }
            fclose(clinica);
            printf ("\nElija el horario de visita  ");  
            scanf ("%d",&idhorario);
            while(horarios[idhorario].disponible == 0)
            {
                printf ("Horario no disponible\n");
                printf ("Por favor vuelva a elegir un horario\n");
                printf("\n");
                printf ("Elija el horario de visita\n");  
                scanf ("%d",&idhorario);
            }
            
            printf ("Registrado. El veterinario de turno lo atendera de %s", horarios[idhorario].hora);

            clinica = fopen("horario.txt", "w");
            for(int i=0; i<j; i++)
            {
              if(i == idhorario)
              {
                fprintf(clinica,"%s %d %s %s %d", " ", horarios[i].id, horarios[i].dia, horarios[i].hora,0);
              }
              else
              {
                fprintf(clinica,"%s %d %s %s %d", " ", horarios[i].id, horarios[i].dia, horarios[i].hora,horarios[i].disponible);
              }
            }
            fclose(clinica);
            printf("\n");
            break;
        }
        
        case 6:
        {
          printf("\n********** Registre la información del medicamento ********** \n");
              medicamentos[numMed] = registrarmed(numMed);
              numMed++;
              clinica = fopen("farmacia.txt", "w");
            
              for(int i=0; i<numMed; i++)
              {
                  fprintf(clinica,"%d %s %d %f",
                          medicamentos[i].id, medicamentos[i].nombre,medicamentos[i].cantidad,medicamentos[i].precioU);
              }
              fclose(clinica);
              printf("\n");
              break;
        }
        
        case 7:
        {
         printf("ID\t \tNOMBRRE\t \tCANTIDAD\t \tPRECIO UNITARIO\n");
            printf("-------------------------------------------------------------------------------------------------------\n");
            clinica= fopen("farmacia.txt", "r");
            
            while(feof(clinica)==0)
                {
                    fscanf(clinica,"%d",&medicamentos[p].id);
                    fscanf(clinica,"%s",medicamentos[p].nombre);
                    fscanf(clinica,"%d",&medicamentos[p].cantidad);
                    fscanf(clinica,"%f",&medicamentos[p].precioU);
                    
                    printf ("\n%d\t \t%s\t \t%d\t \t\t\t%.2f\n",medicamentos[p].id,medicamentos[p].nombre, medicamentos[p].cantidad,medicamentos[p].precioU);
                    p++;
                }
                    printf ("Ingrese el nombre del cliente: ");
                    scanf ("%s",nombreCliente);
                    printf ("Ingrese el numero de medicamentos que desea comprar: ");
                    scanf ("%d",&Nmedicamentos);
                    
                    for (int i=0; i<Nmedicamentos; i++)
                    {
                     printf ("Ingrese el Id del medicamento a comprar: ");
                     scanf ("%d",&medicamentoPedidos[i].id);
                     printf ("Ingrese la cantidad del medicamento a comprar: ");
                     scanf ("%d",&medicamentoPedidos[i].cantidad);
                    }
         break;
        }
        case 8:
        {
          printf ("NOMBRE\t \tCANTIDAD\t \tPRECIO UNITARIO\t \t\tPRECIO TOTAL\n");
          for(int i =0; i<Nmedicamentos; i++)
          {
            printf ("%s\t \t%d\t \t\t%.2f\t \t\t\t%.2f\n",medicamentos[medicamentoPedidos[i].id].nombre, medicamentos[medicamentoPedidos[i].id].cantidad,medicamentos[medicamentoPedidos[i].id].precioU, (medicamentos[medicamentoPedidos[i].id].cantidad * medicamentos[medicamentoPedidos[i].id].precioU));
            precioTotal = precioTotal+ (medicamentos[medicamentoPedidos[i].id].cantidad * medicamentos[medicamentoPedidos[i].id].precioU);
          }
          float iva = (precioTotal * 12) / 100;
          printf("\nSubtotal: ");
          printf("%f\n", precioTotal);
          printf("Iva 12%%: ");
          printf("%f\n", iva);
          printf("Total: ");
          printf("%f\n", precioTotal + iva);
          break;
        }

        case 9: 
        {
          printf ("Gracias por utilizar nuestro sistema\n");
          printf ("Vuelva pronto");
          break;
        }
        default: {
            printf("Opción incorrecta \n");
            break;
        }
        }
    } while (op != 9);
  }
  else 
  {
     printf("Usuario y contraseña incorrectos \n");
     printf ("Usuario: ");
     scanf("%s",user);
     printf ("Contraseña: ");
     scanf("%s",password);
     login(user,password);
  }


}

 Vacuna ingresarinfo(int id)
{
    Vacuna mascota;
    mascota.id=id;
    printf("\nIngrese el nombre de la mascota: ");
    scanf("%s",mascota.nombre);
    printf("\nIngrese la especie del paciente: ");
    scanf("%s",mascota.especie);
    printf ("\nIngrese el genero de la mascota: ");
    scanf ("%s",mascota.genero);
    printf("\nIngrese el peso : ");
    scanf("%f",&mascota.peso);
    printf("\nIngrese la edad : ");
    scanf("%d",&mascota.edad);
    printf("\nIngrese la raza : ");
    scanf("%s",mascota.raza);
    printf("\nIngrese la vacuna que desea que se le suministre:");
    scanf("%s",mascota.vacuna);
    return mascota;
}

Medicamento registrarmed (int id)
{
    Medicamento medicamento;
    medicamento.id=id;
    printf("\n Ingrese el nombre del medicamento: ");
    scanf("%s",medicamento.nombre);
    printf("\n Ingrese el stock :");
    scanf("%d",&medicamento.cantidad);
    printf("\n Ingrese el precio unitario :");
    scanf("%f",&medicamento.precioU);
    return medicamento;
}

void ListarHorario ()
{
  int j=0;
  int idhorario;
  char caracter;
    clinica = fopen("horario.txt", "r");
    j = 0;
    while(feof(clinica)==0)
    {
        fscanf(clinica,"%d",&horarios[j].id);
        fscanf(clinica,"%s",horarios[j].dia);
        fscanf(clinica,"%s",horarios[j].hora);
        fscanf(clinica,"%d",&horarios[j].disponible);

        printf ("\n%d\t \t%s\t \t%s\t \t\t%d\n",horarios[j].id,horarios[j].dia, horarios[j].hora,horarios[j].disponible);

        j++;
    }
}


void cargarHorario ()
{
    clinica = fopen("horario.txt", "w");        
    fprintf(clinica,"%s %d %s %s %d"," ", 0, "LUNES","9am-12pm",0);

    fprintf(clinica,"%s %d %s %s %d"," " ,1, "LUNES","12pm-5pm",0);

    fprintf(clinica,"%s %d %s %s %d"," " ,2, "MARTES","9am-12pm",0);
    
    fprintf(clinica,"%s %d %s %s %d"," " ,3, "MARTES","12pm-5pm",0);

     fprintf(clinica,"%s %d %s %s %d"," " ,4, "MIERCOLES","9am-12pm",1);

     fprintf(clinica,"%s %d %s %s %d"," " ,5, "MIERCOLES","12pm-5pm",1);

     fprintf(clinica,"%s %d %s %s %d"," " ,6, "JUEVES","9am-12pm",1);

     fprintf(clinica,"%s %d %s %s %d"," " ,7, "JUEVES","12pm-5pm",0);

     fprintf(clinica,"%s %d %s %s %d"," " ,8, "VIERNES","11am-2pm",0);

     fprintf(clinica,"%s %d %s %s %d"," " ,9, "VIERNES","2pm-7pm",1);

     fprintf(clinica,"%s %d %s %s %d"," " ,10, "SABADO","10am-1pm",0);

     fprintf(clinica,"%s %d %s %s %d"," " ,11, "SABADO","1pm-4pm",1);

    fclose(clinica);
}

#include <stdio.h>
#include <string.h>

#define NUM_ANIOS 5

struct Compania {
    char nombre[100];
    int empleadosPorAnio[NUM_ANIOS];
};

void add_employee_data(struct Compania *compania, int anio);
int find_total_employees(const struct Compania *compania, int anio);
void delete_employee_data(struct Compania *compania, int anio);
double calculate_average_employees(const struct Compania *compania);
double general_average_employees(const struct Compania *companias, int numCompanias);

int main() {
    struct Compania companias[10];
    int numCompanias;
    int indiceCompania;

    //AGREGAR COMPAÑIAS
    printf("Ingrese el numero de companias a registrar: ");
    scanf("%d", &numCompanias);

    while (getchar() != '\n');

    for (int i = 0; i < numCompanias; i++) {
        printf("\nIngrese el nombre de la compania %d: ", i + 1);
        fgets(companias[i].nombre, sizeof(companias[i].nombre), stdin);
        companias[i].nombre[strcspn(companias[i].nombre, "\n")] = '\0';

        for (int j = 0; j < NUM_ANIOS; j++) {
            printf("Ingrese la cantidad de empleados en el anio %d: ", 2018 + j);
            scanf("%d", &companias[i].empleadosPorAnio[j]);
        }
        while (getchar() != '\n');
    }

    //ACTUALIZAR EMPLEADOS
    printf("\nIngrese el numero de la compania a la que desea ACTUALIZAR la lista de empleados (1-%d): ", numCompanias);
    scanf("%d", &indiceCompania);

    if(indiceCompania >= 1 && indiceCompania <= numCompanias)
    {
        int anio;
        printf("Ingrese el anio para actualizar la lista de empleados (2018-2022): ");
        scanf("%d", &anio);
        while (getchar() != '\n');
        add_employee_data(&companias[indiceCompania - 1], anio);
    }
    else
    {
        printf("Numero de Compania no valido.\n");
    }

    //BUSCAR EMPLEADOS
    printf("\nIngrese el numero de la compania donde BUSCAR el total de empleados (1-%d): ", numCompanias);
    scanf("%d", &indiceCompania);

    if(indiceCompania >= 1 && indiceCompania <= numCompanias)
    {
        int anio;
        printf("Ingrese el anio para buscar el total de empleados (2018-2022): ");
        scanf("%d", &anio);
        while (getchar() != '\n');
        int totalEmpleados = find_total_employees(&companias[indiceCompania - 1], anio);
        printf("El total de empleados en el anio %d para la compania %s es: %d\n", anio, companias[indiceCompania - 1].nombre, totalEmpleados);
    }
    else
    {
        printf("Numero de compania no valido.\n");
    }

    //ELIMINAR EMPLEADOS
    printf("\nIngrese el Numero de la compania donde ELIMINAR la lista de empleados (1-%d): ", numCompanias);
    scanf("%d", &indiceCompania);

    if(indiceCompania >= 1 && indiceCompania <= numCompanias)
    {
        int anio;
        printf("\nIngrese el anio para eliminar la lista de empleados (2018-2022): ");
        scanf("%d", &anio);
        while (getchar() != '\n');
        delete_employee_data(&companias[indiceCompania - 1], anio);
    }
    else
    {
        printf("Numero de compania no valido.\n");
    }

    // CALCULAR PROMEDIO DE EMPLEADOS
    printf("\nIngrese el Numero de la compania para CALCULAR el promedio de empleados (1-%d): ", numCompanias);
    scanf("%d", &indiceCompania);

    if(indiceCompania >= 1 && indiceCompania <= numCompanias)
    {
        double promedio = calculate_average_employees(&companias[indiceCompania - 1]);
        printf("El promedio de empleados para la compania %s es: %.1f\n", companias[indiceCompania - 1].nombre, promedio);
    }
    else
    {
        printf("Numero de compania no valido.\n");
    }

    // CALCULAR PROMEDIO GENERAL DE EMPLEADOS
    double promedioGeneral = general_average_employees(companias, numCompanias);
    printf("\nEl promedio general de empleados para todas las companias es: %.1f\n", promedioGeneral);

    // LEER DATOS DESDE UN ARCHIVO DE TEXTO
    FILE *archivo;
    char nombreArchivo[100];

    printf("Ingrese el nombre del archivo de texto: ");
    scanf("%s", nombreArchivo);

    archivo = fopen(nombreArchivo, "r");

    if(archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    fscanf(archivo, "%d", &numCompanias);

    for(int i = 0; i < numCompanias; i++)
    {
        fscanf(archivo, "%s", companias[i].nombre);

        for(int j = 0; j < NUM_ANIOS; j++)
        {
            fscanf(archivo, "%d", &companias[i].empleadosPorAnio[j]);
        }
    }

    fclose(archivo);

    //ACTUALIZAR EMPLEADOS
    printf("\nIngrese el numero de la compania a la que desea ACTUALIZAR la lista de empleados (1-%d): ", numCompanias);
    scanf("%d", &indiceCompania);

    if(indiceCompania >= 1 && indiceCompania <= numCompanias)
    {
        int anio;
        printf("Ingrese el anio para actualizar la lista de empleados (2018-2022): ");
        scanf("%d", &anio);
        while (getchar() != '\n');
        add_employee_data(&companias[indiceCompania - 1], anio);
    }
    else
    {
        printf("Numero de Compania no valido.\n");
    }

    //BUSCAR EMPLEADOS
    printf("\nIngrese el numero de la compania donde BUSCAR el total de empleados (1-%d): ", numCompanias);
    scanf("%d", &indiceCompania);

    if(indiceCompania >= 1 && indiceCompania <= numCompanias)
    {
        int anio;
        printf("Ingrese el anio para buscar el total de empleados (2018-2022): ");
        scanf("%d", &anio);
        while (getchar() != '\n');
        int totalEmpleados = find_total_employees(&companias[indiceCompania - 1], anio);
        printf("El total de empleados en el anio %d para la compania %s es: %d\n", anio, companias[indiceCompania - 1].nombre, totalEmpleados);
    }
    else
    {
        printf("Numero de compania no valido.\n");
    }

    //ELIMINAR EMPLEADOS
    printf("\nIngrese el Numero de la compania donde ELIMINAR la lista de empleados (1-%d): ", numCompanias);
    scanf("%d", &indiceCompania);

    if(indiceCompania >= 1 && indiceCompania <= numCompanias)
    {
        int anio;
        printf("\nIngrese el anio para eliminar la lista de empleados (2018-2022): ");
        scanf("%d", &anio);
        while (getchar() != '\n');
        delete_employee_data(&companias[indiceCompania - 1], anio);
    }
    else
    {
        printf("Numero de compania no valido.\n");
    }

    // CALCULAR PROMEDIO DE EMPLEADOS
    printf("\nIngrese el Numero de la compania para CALCULAR el promedio de empleados (1-%d): ", numCompanias);
    scanf("%d", &indiceCompania);

    if(indiceCompania >= 1 && indiceCompania <= numCompanias)
    {
        double promedio = calculate_average_employees(&companias[indiceCompania - 1]);
        printf("El promedio de empleados para la compania %s es: %.1f\n", companias[indiceCompania - 1].nombre, promedio);
    }
    else
    {
        printf("Numero de compania no valido.\n");
    }

    return 0;
}

void add_employee_data(struct Compania *compania, int anio)
{
    if(anio >= 2018 && anio <= 2022)
    {
        int indice = anio - 2018;
        int cantidadEmpleados;
        printf("Ingrese la cantidad de empleados para el anio %d: ", anio);
        scanf("%d", &cantidadEmpleados);
        while (getchar() != '\n');
        compania->empleadosPorAnio[indice] = cantidadEmpleados;
        printf("Datos actualizados para el anio %d: %d empleados\n", anio, cantidadEmpleados);
    }
    else
    {
        printf("El anio debe estar en el rango 2018 - 2022.\n");
    }
}

int find_total_employees(const struct Compania *compania, int anio)
{
    if(anio >= 2018 && anio <= 2022)
    {
        int indice = anio - 2018;
        return compania->empleadosPorAnio[indice];
    }
    else
    {
        printf("El anio debe estar en el rango 2018 - 2022.\n");
        return -1;
    }
}

void delete_employee_data(struct Compania *compania, int anio)
{
    if(anio >= 2018 && anio <= 2022)
    {
        int indice = anio - 2018;
        compania->empleadosPorAnio[indice] = 0;
        printf("Datos eliminados para el anio %d.\n", anio);
    }
    else
    {
        printf("El anio debe estar en el rango 2018 - 2022.\n");
    }
}

double calculate_average_employees(const struct Compania *compania)
{
    int totalEmpleados = 0;
    for(int i = 0; i < NUM_ANIOS; i++)
    {
        totalEmpleados += compania->empleadosPorAnio[i];
    }
    return (double)totalEmpleados / NUM_ANIOS;
}

double general_average_employees(const struct Compania *companias, int numCompanias)
{
    int totalEmpleados = 0;
    int totalAnios = numCompanias * NUM_ANIOS;

    for(int i = 0; i < numCompanias; i++)
    {
        for(int j = 0; j < NUM_ANIOS; j++)
        {
            totalEmpleados += companias[i].empleadosPorAnio[j];
        }
    }

    return(double)totalEmpleados / totalAnios;
}

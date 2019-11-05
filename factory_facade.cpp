#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include "printer.cpp"


class Factory{
public:
	Object *createObject(char type) {
        switch (type)
        {
        case 'i':
            return new Impresora;
            break;
        case 'p':
            return new Plotter;
            break;
        default:
            break;
        }
	}
    CajaRegistradora *cajaObject(){
        return new CajaRegistradora;
    }
};



int main()
{
    while(1){
    
        int option, optImprimir, optCobrar,optImpresora, optPlotter,num_trab;
        char * nombre_archivo;
        float total;
        Factory * factory;
        Object * obj;
        CajaRegistradora * caja;
        factory = new Factory;

        do{
            system("clear");
            std::cout<<"\n 1 .. Imprimir\n";
            std::cout<<" 2 .. Cobrar\n";
            std::cout<<" 3 .. Salir\n";
            std::cout<<" Seleccione una opcion: ";
            std::cin>>option;        
            switch(option){
                case 1:
                    do{
                        system("clear");
                        std::cout<<"\n 1 .. Impresora\n";
                        std::cout<<" 2 .. Plotter\n";
                        std::cout<<" 3 .. Regresar\n ";
                        std::cout<<" Seleccione una opcion: ";
                        std::cin>>optImprimir;

                        switch(optImprimir){
                            case 1:
                                system("clear");
                                std::cout<<"\n 1 .. Imprimir\n";
                                std::cout<<" 2 .. Mostrar trabajos en fila\n";
                                std::cout<<" 3 .. Limpiar fila de impresión\n ";
                                std::cout<<"4 .. Regresar\n ";
                                std::cout<<" Seleccione una opcion: ";
                                std::cin>>optImpresora;

                                switch(optImpresora){
                                    case 1:
                                        std::cout<<"\nIngresa el nombre del archivo: ";
                                        std::cin>>nombre_archivo;
                                        obj=factory->createObject('i');
                                        obj->Imprime(nombre_archivo);            
                                        getchar();
                                    break;
                                    case 2:
                                        obj=factory->createObject('i');
                                        num_trab=obj->NumeroTrabajosEspera();
                                        std::cout<<"\nSe encuentran "<<num_trab<<" impresiones en la fila de la impresora\n";
                                        getchar();
                                    break;
                                    case 3:
                                        obj=factory->createObject('i');
                                        obj->LimpiaPrintingQueue();
                                        std::cout<<"\nSe limpio la fila de la impresora!!";
                                        getchar();
                                    break;
                                    case 4:
                                        optImpresora=0;
                                        optPlotter=0;
                                    break;
                                    default:
                                        
                                    break;
                                }

                                break;
                            case 2:
                                system("clear");
                                std::cout<<"\n 1 .. Imprimir\n";
                                std::cout<<" 2 .. Mostrar trabajos en fila\n";
                                std::cout<<" 3 .. Limpiar fila de impresión\n ";
                                std::cout<<"4 .. Regresar\n ";
                                std::cout<<" Seleccione una opcion: ";
                                std::cin>>optPlotter;

                                switch(optPlotter){
                                    case 1:
                                        std::cout<<"\nIngresa el nombre del archivo: ";
                                        std::cin>>nombre_archivo;
                                        obj=factory->createObject('p');
                                        obj->Imprime(nombre_archivo);            
                                        getchar();
                                    break;
                                    case 2:
                                        obj=factory->createObject('p');
                                        num_trab=obj->NumeroTrabajosEspera();
                                        std::cout<<"\nSe encuentran "<<num_trab<<" impresiones en la fila del plotter\n";
                                        getchar();
                                    break;
                                    case 3:
                                        obj=factory->createObject('p');
                                        obj->LimpiaPrintingQueue();
                                        std::cout<<"\nSe limpio la fila del plotter!!";
                                        getchar();
                                    break;
                                    case 4:
                                        optImpresora=0;
                                        optPlotter=0;
                                    break;
                                    default:
                                    break;
                                }

                                break;
                            case 3:
                                optImpresora=0;
                                optPlotter=0;
                                break;
                            default:
                                break;
                        }                        
                    }while(optImpresora==4 || optPlotter==4);                    
                    break;
                case 2:
                    do{
                        system("clear");
                        std::cout<<"\n 1 .. Abrir caja registradora\n";
                        std::cout<<" 2 .. Mostrar total\n";
                        std::cout<<" 3 .. Regresar\n ";
                        std::cout<<" Seleccione una opcion: ";
                        std::cin>>optCobrar;

                        switch(optCobrar){
                            case 1:  
                                caja=factory->cajaObject();
                                caja->AbreCajaRegistradora();
                                getchar();
                            break;
                            case 2:
                                caja=factory->cajaObject();
                                total=caja->totalAPagar();
                                std::cout<<"\n El total a pagar es de $"<<total<<" pesos!!";
                                getchar();
                            break;
                            case 3:                                
                                optImpresora=0;
                                optPlotter=0;
                            break;
                            default:
                            break;
                        }

                        break;
                    default:
                        break;
                    }while(optCobrar==3);                    
                break;
                case 3:
                    exit(1);
                break;
            }
        }while(optImprimir==3);
        
        getchar();
    }
    return 0;
}
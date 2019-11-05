#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>

class Object{
    private:
        int cola;
    public:
        virtual void Imprime(char * nombre_archivo){
            cola++;
        }
        int NumeroTrabajosEspera(){
            return cola;
        }
        void LimpiaPrintingQueue(){
            cola=0;
        }
};

class Impresora : public Object
{    
    public:
        void Imprime(char * nombre_archivo){            
            std::cout<<"\nSe agrego "<<nombre_archivo<<" a fila de la impresora! \n";
        }

};

class Plotter : public Object
{   
    public:
        void Imprime(char * nombre_archivo){
            std::cout<<"\nSe agrego "<<nombre_archivo<<" a fila del plotter! \n";
        }
};

class CajaRegistradora
{
    private:
        float total;
    public:
        void AbreCajaRegistradora(){
            std::cout<<"\nSe abrió la caja registradora! ";
        }
        float totalAPagar(){
            return total;
        }
        void EstableceMontoAPagar(float cantidad){
            total+=total;
        }
};
//Espacio usado para verificar la validez de los problemas resueltos.
//~ 
#include<iostream>
#include<iomanip>
using namespace std;

class RegistroTemperaturas{
    private:
        double* lecturas;
        int capacidad;
        int cantidad;
    public:
        RegistroTemperaturas(int cap):capacidad(cap),cantidad(0){
            lecturas=new double[capacidad];
        }
        ~RegistroTemperaturas(){
            delete[] lecturas;
            lecturas=nullptr;
        }
        void agregar(double temp){
            if(temp<-50.0||temp>60.0){
                cout<<"Temperatura invalida."<<endl;
            }
            else if(cantidad<capacidad){
                lecturas[cantidad]=temp;
                cantidad++;
            }
            else{
                cout<<"Registro lleno."<<endl;
            }
        }
        double promedio() const{
            if(cantidad==0){
                return 0.0;
            }
            double suma=0;
            for(int i=0;i<cantidad;i++){
                suma=suma+lecturas[i];
            }
            return suma/cantidad;
        }
        double maxima() const{
            if(cantidad==0){
                return 0.0;
            }
            double mayor=lecturas[0];
            for(int i=1;i<cantidad;i++){
                if(lecturas[i]>mayor){
                    mayor=lecturas[i];
                }
            }
            return mayor;
        }
        double minima() const{
            if(cantidad==0){
                return 0.0;
            }
            double menor=lecturas[0];
            for(int i=1;i<cantidad;i++){
                if(lecturas[i]<menor){
                    menor=lecturas[i];
                }
            }
            return menor;
        }
        void imprimir() const{
            cout<<fixed<<setprecision(1);
            cout<<"Temperaturas: ";
            for(int i=0;i<cantidad;i++){
                cout<<lecturas[i];
                if(i<cantidad-1){
                    cout<<" ";
                }
            }
            cout<<endl;
        }
};

void resumen(const RegistroTemperaturas& reg){
    reg.imprimir();
    cout<<fixed<<setprecision(2);
    cout<<"Promedio : "<<reg.promedio()<<endl;
    cout<<"Maxima   : "<<reg.maxima()<<endl;
    cout<<"Minima   : "<<reg.minima()<<endl;
}

int main(){
    int n;
    double temp;
    cin>>n;

    RegistroTemperaturas registro(n);

    for(int i=0;i<n;i++){
        cin>>temp;
        registro.agregar(temp);
    }

    resumen(registro);
}

/* ***************************************************************
//	Programador: Gabriel Fontanez
//	# Estudiante: 842-15-3288
//  Profesor: Elio Ramos Colon
//  Curso: COMP 4097-001
// ************************************************************** */
#include <iostream>
#include <algorithm>

using namespace std;

class Racional
{
public:
    Racional();//Base
    Racional(int numerador);
    Racional(int numerador,int denominador);
    Racional simplifica();
    Racional operator+(const Racional& f);
    Racional operator-(const Racional& f);
    Racional operator*(const Racional& f);
    Racional operator/(const Racional& f);
    friend ostream& operator<<(ostream& out,const Racional& f);  //Quiero que cout aprenda imprimir esta clase


private:
    int miNumerador;
    int miDenominador;
};

Racional::Racional()
{
    miNumerador = 0;
    miDenominador = 1;
}
Racional::Racional(int numerador)
{
    miNumerador = numerador;
    miDenominador = 1;
}
Racional::Racional(int numerador,int denominador)
{
    miNumerador = numerador;
    miDenominador = denominador;
}
Racional Racional::operator+(const Racional& f)
{
    int num = (miNumerador*f.miDenominador)+(miDenominador*f.miNumerador);
    int den = miDenominador*f.miDenominador;
    return Racional (num,den).simplifica();
}
Racional Racional::operator-(const Racional& f)
{
    int num = (miNumerador*f.miDenominador)-(miDenominador*f.miNumerador);
    int den = miDenominador*f.miDenominador;
    return Racional (num,den).simplifica();;
}
Racional Racional::operator*(const Racional& f)
{
    int num = miNumerador*f.miNumerador;
    int den = miDenominador*f.miDenominador;
    return Racional(num,den).simplifica();
}
Racional Racional::operator/(const Racional& f)
{
    int num = miNumerador*f.miDenominador;
    int den = miDenominador*f.miNumerador;
    return Racional(num,den).simplifica();
}
Racional Racional::simplifica()
{
    int gcd = __gcd(miNumerador,miDenominador);
    return Racional (miNumerador/gcd,miDenominador/gcd);
}
//Overloaded function
ostream& operator<<(ostream& out,const Racional& f)
{
    if(f.miDenominador == 1)//Si el denominador del resultado final = 1 Entonces solo demuestra el numerador
                            //Ej 2/1 = 2
    {
        out << f.miNumerador;
    }
    //Emprime ERROR al tener una de las fracciones con un denominador en 0
    else if (f.miDenominador == 0)
    {
        out << "ERROR denominador es 0";
    }
    //Si el denominador es negativo simplifica el resultado
    //Ej 1/-2 = -1/2
    else if (f.miDenominador <= 0)
    {
        out << f.miNumerador*(-1) << "/" << f.miDenominador*(-1);
    }
    else
    {
        out << f.miNumerador << "/" << f.miDenominador;
    }
}
int main()
{
    int a,b,c,d; //Numerador y Denominador de las fracciones
    unsigned int opcion; //Variable Que indica cual operacion se usara
    unsigned const int Sum = 1, Res = 2, Mul = 3, Div = 4, Sal = 5;//Opciones del menu
    //-Mensaje de Bienvenida-
    cout << "\t\t\t\t -Bienvenidos-" << endl;
    cout << "Este programa funciona como una calculadora la cual hara la suma, resta " << endl;
    cout << "multiplicacion y divicion de fracciones\n" << endl;
     do
    {
            cout << "\n    -Menu-\n" << endl;
            cout << "_________________" << endl;
            cout << "|1. Sumar       |" << endl;
            cout << "|2. Restar      |" << endl;
            cout << "|3. Multiplicar |" << endl;
            cout << "|4. Dividir     |" << endl;
            cout << "|5. Salir       |" << endl;
            cout << "|---------------|" << endl;
            cout << "Entre su opcion: ";
        // Validar la opcion introducida
        while(!(cin >> opcion))//Validacion para Letras u otro signos
        {   //Re introduce el menu en caso de un error del usuario
            cout << "Porfavor entre una opcion valida sin letras" << endl;
            cin.clear();
            cin.ignore(100,'\n');
            cout << "\n    -Menu-\n" << endl;
            cout << "_________________" << endl;
            cout << "|1. Sumar       |" << endl;
            cout << "|2. Restar      |" << endl;
            cout << "|3. Multiplicar |" << endl;
            cout << "|4. Dividir     |" << endl;
            cout << "|5. Salir       |" << endl;
            cout << "|---------------|" << endl;
            cout << "Entre su opcion: ";
        }
        if (opcion > Sal || opcion < Sum)//Validacion Para numeros no en lista (ej 9, 26, -90)
        {//Desde aqui el programa inicia el dowhile otravez
            cout << "Entre una opcion valida" << endl;
        }
        //Aqui el usuario pone los numeros que quiere sumar, restar, multiplicar o dividir,
        else if (opcion != Sal)
        {
            cout << "\nPor favor entre las 2 fracciones en orden numerador/denominador" << endl;
            cout << "/-------------------/" << endl;
            //Primera Fraccion
            cout << "Fraccion#1\nNumerador: ";
            while(!(cin >> a))//Validacion que no sea un signo
            {
                cout << "Entre un numero: ";
                cin.clear();
                cin.ignore(100,'\n');
            }
            cout << "Denominador: ";
            while(!(cin >> b))//Validacion que no sea un signo
            {
                cout << "Entre un numero: ";
                cin.clear();
                cin.ignore(100,'\n');
            }
            Racional F1(a,b);//Se ponen los numeros dentro de la clase F1
            cout << "/-------------------/" << endl;
            cout << "Fraccion#2\nNumerador: ";
            while(!(cin >> c))//Validacion que no sea un signo
            {
                cout << "Entre un numero: ";
                cin.clear();
                cin.ignore(100,'\n');
            }
            cout << "Denominador: ";
            while(!(cin >> d))//Validacion que no sea un signo
            {
                cout << "Entre un numero: ";
                cin.clear();
                cin.ignore(100,'\n');
            }
            Racional F2 (c,d);//Se ponen los numeros dentro de la clase F1
        //La opcion puesta anteriormente determina cual de las 4 operacion se usara
           switch (opcion)
            {
                case Sum://Suma de las dos fracciones
                    cout << "\nResultado: " << F1+F2 << endl;
                    break;

                case Res://Resta
                    cout << "\nResultado: " << F1-F2 << endl;
                    break;

                case Mul://Multiplicacion
                    cout << "\nResultado: " << F1*F2 << endl;
                    break;

                case Div://Divicion
                    cout << "\nResultado: " << F1/F2 << endl;
                    break;
            }
        }
    } while (opcion != Sal);
    return 0;
}

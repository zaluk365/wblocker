#include "wblocker.h"
using namespace wblocker;

int main(int argc, char const *argv[])
{
    wmain handler;
    string dominio;
    cout << "Ingresa el dominio" << endl;
    cin >> dominio;
    if (handler.domainExists(dominio, "hola.txt")){
        cout << "El dominio ingresado ya existe";
        return EXIT_FAILURE;
    }
    cout << "Archivo antes de cambiarlo:" << endl;
    handler.readFile("hola.txt");
    handler.addDomain(dominio);
    handler.writeFile("hola.txt");
    cout << "Archivo despues de cambiarlo:" << endl;
    handler.readFile("hola.txt");
    return 0;
}

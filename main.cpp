#include "wblocker.h"
using namespace wblocker;

void showMenu()
{
    cout << "1- Ingresar un dominio" << endl
         << "2- Eliminar un dominio" << endl
         << "3- Mostrar dominios existentes ";
}

int main(int argc, char const *argv[])
{
    wmain handler;
    string dominio;
    int opc;
    bool running = true;

    while (running)
    {
        showMenu();
        cin >> opc;
        if (opc == 1)
        {
            cout << "Ingresa el dominio" << endl;
            cin >> dominio;
            if (handler.domainExists(dominio))
            {
                cout << "El dominio ingresado ya existe";
                return EXIT_FAILURE;
            }
            handler.writeFile(dominio);
            system("ipconfig /flushdns");
            cout << "Se agrego la ruta " << dominio << " efectivamente" << endl;
        }

        if (opc == 2)
        {
            cout << "Ingresa el dominio a borrar" << endl;
            cin >> dominio;
            if (!handler.domainExists(dominio))
            {
                cout << "El dominio ingresado no existe";
                return EXIT_FAILURE;
            }
            handler.deleteDomain(dominio);
            system("ipconfig /flushdns");
            cout << "Se elimino la ruta " << dominio << " efectivamente" << endl;
        }

        if (opc == 3)
            handler.readFile();

        if (opc == 0)
            running = false;
    }
    return EXIT_SUCCESS;
}

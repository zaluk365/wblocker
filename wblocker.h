#ifdef _WIN32 
    #include <iostream>
    #include <fstream>
    #include <string.h>
#else
    #error Sistema operativo no compatible
#endif

#define NOT_FOUND string::npos

#define ROUTE "C:\\Windows\\System32\\drivers\\etc\\hosts"
#define TEMP "C:\\Windows\\System32\\drivers\\etc\\temp.txt" 
// "C:\\Windows\\System32\\drivers\\etc\\hosts"

using namespace std;

namespace wblocker
{
    class wmain
    {
    public:
        /**
         * @brief Lee y muestra todo el archivo hosts
         */
        void readFile();

        /**
         * @brief Escribe un dominio en el archivo hosts
         * 
         * @param domain Dominio a escribir
         */

        void writeFile(string domain);
        /**
         * @brief Verifica que un dominio exista dentro de hosts
         * 
         * @param domain Dominio a verificar
         * @return true Existe el dominio
         * @return false No existe el dominio
         */
        bool domainExists(string domain);

        /**
         * @brief Elimina un dominio de hosts
         * 
         * @param domain Dominio a eliminar
         */
        void deleteDomain(string domain);

        /**
         * @brief Elimina las lineas vacías dentro de hosts
         * 
         */
        void clearEmpty();
    };
}
#include <iostream>
#include <fstream>
#include <string.h>
#define NOT_FOUND string::npos
using namespace std;
namespace wblocker
{
    class wmain
    {
    private: 
        string dominio;
    public:
        /**
         * @brief Lee el archivo
         * 
         * @param fileRoute Ruta del archivo
         */
        void readFile(string fileRoute);
        void writeFile(string fileRoute);
        void addDomain(string domain);
        bool domainExists(string domain, string fileRoute);
    };
}
#include "wblocker.h"
using namespace std;
using namespace wblocker;

void wmain::writeFile(string domain)
{
    ofstream myfile;
    myfile.open(ROUTE, ios::app | ios::ate);
    myfile << endl << "127.0.0.1\t" << domain;
    myfile.close();
}

void wmain::readFile()
{
    string line;
    ifstream myfile(ROUTE);
    if (myfile.is_open())
    {
        cout << endl;
        while (getline(myfile, line))
        {
            if (line[0] == '#' || line.empty())
                continue;
            cout << line << endl;
        }
        cout << endl;
        myfile.close();
    }
    else
        cout << "No se pudo abrir el archivo.";
}
void wmain::deleteDomain(string dominio)
{
    string domainDeleted = dominio;
    string line;
    ifstream myfile(ROUTE);
    ofstream temp(TEMP);
    while (getline(myfile, line))
    {
        size_t found = line.find(domainDeleted);
        if (found == NOT_FOUND)
            temp << line << std::endl;
    }
    temp.close();
    myfile.close();
    //string path = ROUTE;  //hola.txt
    //const char * p = path.c_str();
    remove(ROUTE);
    rename(TEMP, ROUTE);
}

bool wmain::domainExists(string domain)
{
    string line;
    size_t found;
    bool encontrado = false;
    ifstream myfile(ROUTE);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            found = line.find(domain);
            // cout << found <<" " << NOT_FOUND << endl;
            if (found != NOT_FOUND)
                encontrado = true;
        }
        myfile.close();
    }
    else
        cout << "No se pudo abrir el archivo.";
    return encontrado;
}
void wmain::clearEmpty(){
    string line;
    ifstream myfile(ROUTE);
    ofstream temp(TEMP);
    while (getline(myfile, line))
    {
        if (!line.empty())
            temp << line << std::endl;
    }
    temp.close();
    myfile.close();
    string path = ROUTE;  //hola.txt
    const char * p = path.c_str();
    remove(p);
    rename(TEMP, p);
}
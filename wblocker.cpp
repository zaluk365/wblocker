#include "wblocker.h"
using namespace std;
using namespace wblocker;

void wmain::writeFile(string fileRoute)
{
    ofstream myfile;
    myfile.open(fileRoute, ios::app|ios::ate);
    myfile << "127.0.0.1\t" << dominio << endl;
    myfile.close();
}
void wmain::readFile(string fileRoute)
{
    string line;
    ifstream myfile(fileRoute);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            if(line[0] == '#') continue;
            cout << line << '\n';
        }
        myfile.close();
    }
    else
        cout << "Unable to open file";
}
void wmain::addDomain(string domain){
    dominio = domain;
}
bool wmain::domainExists(string domain, string fileRoute){
    
    string line;
    size_t found;
    bool encontrado = false;
    ifstream myfile(fileRoute);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            found = line.find(domain);
            // cout << found <<" " << NOT_FOUND << endl; 
            if(found != NOT_FOUND) encontrado = true;
        }
        myfile.close();
    }
    else
        cout << "Unable to open file";
    return encontrado;
}
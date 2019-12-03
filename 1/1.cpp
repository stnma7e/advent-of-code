#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
    string line;
    ifstream file ("input.txt");
    int module_mass[100];
    if (file.is_open())
    {
        for (int i = 0; i < 100; i++)
        {
            if (getline(file, line))
            {
                module_mass[i] = std::stoi(line);
            }
            else
            {
                cout << "could not read 100 masses" << endl;
                return 1;
            }
        }
        file.close();
    }

    int fuel_req = 0;
    for (int i = 0; i < 100; i++)
    {
        int mod_req = module_mass[i] / 3 - 2;
        fuel_req += mod_req;

        int add_fuel_req = mod_req;
        while (add_fuel_req > 0)
        {
            add_fuel_req = max(0, add_fuel_req / 3 - 2);
            fuel_req += add_fuel_req;
        }
    }

    cout << fuel_req << endl;

    return 0;
}

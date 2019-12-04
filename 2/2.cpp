#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main () {
    const int MAX = 1000;
    ifstream file ("input.txt");
    string contents((std::istreambuf_iterator<char>(file)),
                    std::istreambuf_iterator<char>());
    file.close();
    std::vector<int> program;

    std::stringstream ss(contents.c_str());
    string token;
    while (getline(ss, token, ','))
    {
        program.push_back(stoi(token));
    }

    program[1] = 12;
    program[2] = 2;

    for (int i = 0; i < program.size(); i++)
    {
        cout << program[i] << (i < program.size() - 1 ? "," : "");
    }
    cout << endl << endl;

    bool halt = false;
    for (int i = 0; i < program.size(); i++)
    {
        if (halt)
            break;

        int a, b, c;
        switch (program[i])
        {
            case 1: case 2:
                a = program[i+1];
                b = program[i+2];
                c = program[i+3];

                if (program[i] == 1)
                    program[c] = program[a] + program[b];
                else
                    program[c] = program[a] * program[b];
                i += 3;
                break;
            case 99:
                halt = true;
                break;
            default:
                cout << "error bad opcode " << program[i] << " at " << i << endl;
        }
    }

    for (int i = 0; i < program.size(); i++)
    {
        cout << program[i] << (i < program.size() - 1 ? "," : "");
    }
    cout << endl;

    return 0;
}

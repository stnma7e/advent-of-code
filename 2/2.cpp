#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <sstream>
#include <iterator>

int run_program(std::vector<int> &memory, int a, int b)
{
    memory[1] = a;
    memory[2] = b;

    //std::copy(memory.begin(), memory.end(), ostream_iterator<int>(cout, ","));

    bool halt = false;
    for (int i = 0; i < memory.size(); i++)
    {
        if (halt)
            break;

        int a, b, c;
        switch (memory[i])
        {
            case 1: case 2:
                a = memory[i+1];
                b = memory[i+2];
                c = memory[i+3];

                if (memory[i] == 1)
                    memory[c] = memory[a] + memory[b];
                else
                    memory[c] = memory[a] * memory[b];
                i += 3;
                break;
            case 99:
                halt = true;
                break;
            default:
                std::cout << "error bad opcode " << memory[i] << " at " << i << std::endl;
        }
    }

    return memory[0];
}

int main () {
    std::ifstream file ("input.txt");
    std::string contents((std::istreambuf_iterator<char>(file)),
                    std::istreambuf_iterator<char>());
    file.close();
    std::vector<int> program;

    std::stringstream ss(contents.c_str());
    std::string token;
    while (getline(ss, token, ','))
    {
        program.push_back(std::stoi(token));
    }

    std::vector<int> memory(program.size());
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            std::copy(program.begin(), program.end(), memory.begin());
            int x = run_program(memory, i, j);
            if (x == 19690720)
            {
                std::cout << i << " " << j << std::endl;
                return 0;
            }
        }
    }

    return 1;
}

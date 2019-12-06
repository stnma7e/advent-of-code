#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <sstream>
#include <iterator>
#include <math.h>

const int LEN_OPCODE = 2;
const int LEN_PARAMS = 10;
const int LEN_INSTR  = LEN_OPCODE + LEN_PARAMS;

struct Instruction
{
    int opcode;
    int par_mode[LEN_PARAMS];
};

Instruction convert_token(int token)
{
    Instruction inst = { .opcode = 0, .par_mode = {} };

    if (token == 0)
    {
        return inst;
    }

    int n_digits = 0;
    if (token < 0)
    {
        n_digits = floor(log10(-token)) + 1;
    }
    else
    {
        n_digits = floor(log10(token)) + 1;
    }

    int powers[LEN_INSTR] = {};
    for (int i = 0; i < n_digits; i++)
    {
        powers[i] = token % 10;
        token /= 10;
    }

    inst.opcode = powers[0];

    if (n_digits > 1)
    {
        inst.opcode += 10 * powers[1];
    }
    if (n_digits > 2)
    {
        for (int i = 2; i < n_digits; i++) // order parameters sequentially
        {
            inst.par_mode[i - 2] = powers[i];
        }
    }

    return inst;
}

int run_program(std::vector<int> &memory)
{
    bool halt = false;
    for (int i = 0; i < memory.size(); i++)
    {
        if (halt)
            break;

        Instruction inst = convert_token(memory[i]);

        int a, b, c;
        if (inst.par_mode[0])
            a = memory[i + 1];
        else
            a = memory[memory[i+1]];

        switch (inst.opcode)
        {
            case 1: case 2:
                if (inst.par_mode[1])
                    b = memory[i + 2];
                else
                    b = memory[memory[i + 2]];

                c = memory[i + 3];

                if (inst.opcode == 1)
                    memory[c] = a + b;
                else
                    memory[c] = a * b;

                i += 3;
                break;

            case 3:
                int in;
                std::cin >> in;
                memory[memory[i + 1]] = in;
                i += 1;
                break;

            case 4:
                std::cout << memory[memory[i + 1]] << std::endl;
                i += 1;
                break;

            case 5:
                if (inst.par_mode[1])
                    b = memory[i + 2];
                else
                    b = memory[memory[i + 2]];

                if (a)
                {
                    i = b;
                    i--;
                }
                else
                {
                    i += 2;
                }

                break;

            case 6:
                if (inst.par_mode[1])
                    b = memory[i + 2];
                else
                    b = memory[memory[i + 2]];

                if (!a)
                {
                    i = b;
                    i--;
                }
                else
                {
                    i += 2;
                }

                break;

            case 7:
                if (inst.par_mode[1])
                    b = memory[i + 2];
                else
                    b = memory[memory[i + 2]];

                c = memory[i + 3];

                if (a < b)
                {
                    memory[c] = 1;
                }
                else
                {
                    memory[c] = 0;
                }

                i += 3;
                break;

            case 8:
                if (inst.par_mode[1])
                    b = memory[i + 2];
                else
                    b = memory[memory[i + 2]];

                c = memory[i + 3];

                if (a == b)
                {
                    memory[c] = 1;
                }
                else
                {
                    memory[c] = 0;
                }

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

    run_program(program);

    return 1;
}

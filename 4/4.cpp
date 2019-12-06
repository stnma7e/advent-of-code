#include <iostream>

using namespace std;

bool find_pair(int *nums, int n = 6)
{
    int string = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] == nums[i+1])
        {
            string += 1;
        }
        else if(string == 2)
        {
            return true;
        }
        else
        {
            string = 1;
        }
    }

    if (string == 2)
    {
        return true;
    }

    return false;
}

int main()
{
    int count = 0;
    bool halt = false;

    for (int i = 3; i < 10; i++)
    {
        if (halt) break;
        for (int j = i; j < 10; j++)
        {
            if (halt) break;
            for (int k = j; k < 10; k++)
            {
                if (halt) break;
                for (int l = k; l < 10; l++)
                {
                    if (halt) break;
                    for (int m = l; m < 10; m++)
                    {
                        if (halt) break;
                        for (int n = m; n < 10; n++)
                        {
                            int x = i * 100000 +
                                    j * 10000  +
                                    k * 1000   +
                                    l * 100    +
                                    m * 10     +
                                    n * 1;
                            if (x < 387638)
                            {
                                continue;
                            }
                            if (x > 919123)
                            {
                                halt = true;
                                break;
                            }

                            int nums[6] = {i,j,k,l,m,n};
                            if (find_pair(nums))
                            {
                                // contains repeating digits
                                count += 1;
                                cout << x << endl;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}

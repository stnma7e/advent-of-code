#include <iostream>

using namespace std;

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

                            if (i == j ||
                                j == k ||
                                k == l ||
                                l == m ||
                                m == n)
                            {
                                // contains repeating digits
                                count += 1;
                            }

                            cout << x << endl;
                        }
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}

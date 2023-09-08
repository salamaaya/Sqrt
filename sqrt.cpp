#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
using namespace std;

double sqrt(double num, double epsilon)
{
    if (num < 0)
    {
        return numeric_limits<double>::quiet_NaN();
    }
    else if (num == 0 || num == 1)
    {
        return num;
    }
    else
    {
        double last_guess = num;
        double next_guess = (last_guess + num / last_guess) / 2;
        while (abs(last_guess - next_guess) > epsilon)
        {
            last_guess = next_guess;
            next_guess = (last_guess + num / last_guess) / 2;
        }
        return next_guess;
    }
}

int main(int argc, char *argv[])
{
    double num, epsilon;
    istringstream iss;

    if (argc < 2 || argc > 3)
    {
        cerr << "Usage: " << argv[0] << " <value> [epsilon]" << endl;
        return 1;
    }

    iss.str(argv[1]);
    if (!(iss >> num))
    {
        cerr << "Error: Value argument must be a double." << endl;
        return 1;
    }

    iss.clear();

    if (argc == 3)
    {
        iss.str(argv[2]);
        if (!(iss >> epsilon))
        {
            cerr << "Error: Epsilon argument must be a positive double." << endl;
            return 1;
        }
        if (epsilon <= 0)
        {
            cerr << "Error: Epsilon argument must be a positive double." << endl;
            return 1;
        }
    }
    else
    {
        epsilon = 0.0000001;
    }

    cout << fixed << setprecision(8) << sqrt(num, epsilon) << endl;
    return 0;
}

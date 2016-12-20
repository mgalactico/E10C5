#include <iostream>
#include <vector>

int main() {
    unsigned int numberOfValues;
    std::vector<double> values;
    std::cout << "Please enter the number of values you want to sum: " << std::endl;
    std::cin >> numberOfValues;
    std::cout << "Please enter some integers (pres '|' to stop): " << std::endl;

    //Push values into vector. cin terminates when an int is not entered
    for (double j; std::cin >> j;) {
        values.push_back(j);
    }

    if (numberOfValues <= values.size()) { //Only move forward if the # of values to add is <= than values in vector.
        //Add up values from vector
        double sum = 0.0;
        for (unsigned int i = 0; i < numberOfValues; ++i) {
            sum += values[i];
        }

        //Build nice string to showcase results.
        std::cout << "The sum of the first " << numberOfValues << " numbers ( ";
        for (unsigned int i = 0; i < numberOfValues; ++i)
            std::cout << values[i] << " ";
        std::cout << ") is " << sum << std::endl;

        //Calculate difference between adjacent #s and assign to new vector.
        std::vector<double> difs;
        double sub;
        for (unsigned int j = 0; j < (numberOfValues - 1); ++j) {
            sub = values[j] - values[j+1];
            difs.push_back(sub);
        }

        //Write out differences stored in vector
        std::cout << "The difference between adjacent number is ( ";
        for (unsigned int i = 0; i < difs.size(); ++i)
            std::cout << difs[i] << " ";
        std::cout << ")";

    } else {
        std::cout << "Can't add more values than submitted!";
        return 1;
    }

    return 0;
}
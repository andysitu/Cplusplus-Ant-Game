/*********************************************************************
* Program name: helper.hpp
* Author: Andy Situ
* Date: 4/19/2019
* Description: Helper class declaration with static functions
*   Used to get int input
**********************************************************************/

#include "Helper.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;

/*********************************************************************
 *  Gets User input for positive integers only from minValue to maxValue.
 *  Only accepts integers. No spacing, letters, etc allowed. Continues
 *  asking user for this until a valid int is given.
*********************************************************************/
int Helper::getIntInput(int minValue, int maxValue)
{
    std::string input;
    bool correctInput = false;
    int intValue;

    // Continue asking for input until input is correct
    while (!correctInput) {
        bool correctFormat = true;
        cout << "Please enter ONLY an integer between " << minValue <<
            " and " << maxValue << " (No spacing, lettrs, etc.)" << endl;
        std::getline(std::cin, input);

        // Check that each char is an int
        int inputLen = input.length();
        if (inputLen >= 1) {
            for (int i = 0; i < inputLen; i++) {
                if (!isdigit(input.at(i)))
                    correctFormat = false;
            }

            // Test that entire input is an integer
            if (correctFormat) {
                intValue = std::stoi(input);
                if (intValue >= minValue && intValue <= maxValue) {
                    correctInput = true;
                }

            }
        }
        std::cout << std::endl;
    }
    return intValue;
}
#include <iostream>
#include<unordered_map>
using namespace std;

/**
 * @brief Main function
 * @details Reads in the number of positions and their corresponding magic values.
 *          Then reads in the number of queries and outputs the position of the
 *          target magic value if it exists in the map.
 * @param None
 * @return 0 if successful
 */
int main()
{
    int numPositions, numQueries;
    cin >> numPositions;

    unordered_map<int, int> magicValueToPosition;

    // Read in the number of magic stones at each position
    for (int i = 1; i <= numPositions; ++i)
    {
        int magicValue;
        cin >> magicValue;
        magicValueToPosition[magicValue] = i;
    }

    cin >> numQueries;

    // Handle each query
    for (int i = 0; i < numQueries; ++i)
    {
        int targetMagicValue;
        cin >> targetMagicValue;

        // Check if the target magic value exists in the map
        if (magicValueToPosition.find(targetMagicValue) != magicValueToPosition.end())
        {
            cout << magicValueToPosition[targetMagicValue] << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}

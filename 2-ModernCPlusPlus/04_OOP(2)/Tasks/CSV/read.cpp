#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

void read_record()
{
    // File pointer
    std::fstream fin;

    // Open an existing file
    fin.open("reportcard.csv", std::ios::in);

    // Check if file is open
    if (!fin.is_open())
    {
        std::cout << "Error: Could not open the file." << std::endl;
        return;
    }

    // Get the roll number of which the data is required
    int rollnum, roll2, count = 0;
    std::cout << "Enter the roll number of the student to display details: ";
    std::cin >> rollnum;

    // Read the data from the file as String Vector
    std::vector<std::string> row;
    std::string line, word;

    while (getline(fin, line))
    {
        row.clear();

        // Skip empty lines
        if (line.empty())
        {
            continue;
        }

        // Used for breaking words
        std::stringstream s(line);

        // Read every column data of a row and store it in a string variable, 'word'
        while (std::getline(s, word, ','))
        {
            // Add all the column data of a row to a vector
            row.push_back(word);
        }

        // Convert string to integer for comparison
        if (!row.empty())
        {
            try
            {
                roll2 = stoi(row[0]);
            }
            catch (const std::invalid_argument &e)
            {
                // Skip this row if conversion fails
                continue;
            }
            catch (const std::out_of_range &e)
            {
                // Skip this row if the number is out of range
                continue;
            }
        }

        // Compare the roll number
        if (roll2 == rollnum)
        {
            // Print the found data
            count = 1;
            std::cout << "Details of Roll " << row[0] << " : \n";
            if (row.size() > 1)
                std::cout << "Name: " << row[1] << "\n";
            if (row.size() > 2)
                std::cout << "Maths: " << row[2] << "\n";
            if (row.size() > 3)
                std::cout << "Physics: " << row[3] << "\n";
            if (row.size() > 4)
                std::cout << "Chemistry: " << row[4] << "\n";
            if (row.size() > 5)
                std::cout << "Biology: " << row[5] << "\n";
            break;
        }
    }

    if (count == 0)
        std::cout << "Record not found\n";

    // Close the file
    fin.close();
}

int main()
{
    read_record();
    return 0;
}

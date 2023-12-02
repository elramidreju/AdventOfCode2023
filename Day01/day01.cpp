#include <string>
#include <fstream>
#include <iostream>
#include <list>

int main()
{
	//std::ifstream infile("example.txt");
	std::ifstream infile("input.txt");
	
	bool is_first_digit = { true };
	char first = { };
	char last = { };
	std::list<int> line_numbers; // Default constructor

	std::string line;

	// For every line in the file
	while (std::getline(infile, line))
	{
		// Travel each character in the line
		for (char& c : line)
		{
			// Is c a digit?
			if (isdigit(c))
			{
				// Is it the first digit in this line?
				if (is_first_digit)
				{
					first = c;
					is_first_digit = false;
				}

				// First may also be last either way, so always do:
				last = c;
			}
		}

		// Number in this line is...
		std::string num_str { first };		// First char as string
		num_str += last;					// Concatenate first with last
		unsigned short num = stoi(num_str);	// Convert to int
		
		// Provisional print
		printf("First: %c, Last: %c, Addition = %hu \n", first, last, num);

		// Add to list of line numbers
		line_numbers.push_back(num);

		// Get this ready for next iteration
		is_first_digit = true;
	}

	// Now we should have all lines processed
	// Time to add
	size_t result = { 0 };

	for (int& i : line_numbers)
	{
		result += i;
	}

	printf("Result: %llu", result);
}

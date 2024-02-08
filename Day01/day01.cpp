#include <array>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <regex>
#include <string>
#include <unordered_set>

int main()
{
	//std::ifstream infile("example_part01.txt");
	//std::ifstream infile("example_part02.txt");
	std::ifstream infile("input.txt");

	bool is_first_digit = { true };
	char first = { };
	char last = { };
	size_t line_count = { 0 };
	std::string line;
	std::string parsed;
	std::list<int> line_numbers; // Default constructor
	std::array<std::string, 9> number_texts
	{
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine"
	};
	std::map<std::string, char> number_text_to_char
	{
		{"one", '1'},
		{"two", '2'},
		{"three", '3'},
		{"four", '4'},
		{"five", '5'},
		{"six", '6'},
		{"seven", '7'},
		{"eight", '8'},
		{"nine", '9'}
	};

	// For every line in the file
	while (std::getline(infile, line))
	{
		++line_count;

		// Reset parsing string
		parsed.clear();

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

				// Additionally, we break parsing written numbers
				parsed.clear();
			}
			else // c is a letter, not a digit
			{
				// Add to parsing string
				parsed += c;

				//std::cout << parsed << "\n";

				// Check coincidence of parsed string vs text numbers
				bool any_match = { false };
				for (std::string& text : number_texts)
				{
					// If find() finds substring we can keep validating
					any_match = any_match || text.rfind(parsed, 0) != std::string::npos;
				}

				//std::cout << any_match << "\n";

				if (any_match)
				{
					// Retrieve char digit for matched text
					auto found = number_text_to_char.find(parsed); // This returns an iterator to possible find
				
					// If match was found, iterator points to map entry; points to end() otherwise
					if (found != number_text_to_char.end())
					{
						char char_found = found->second;

						// Is it the first digit in this line?
						if (is_first_digit)
						{
							first = char_found;
							is_first_digit = false;
						}

						// First may also be last either way, so always do:
						last = char_found;

						// Fully reset parsed for next character
						parsed = parsed.back();
						//parsed.clear();
					}
				}
				else
				{
					// Reset parsed for next character
					// NOTE : We keep last char, as it may be the start of a true match
					// E.g.: in "othree", keeps "o", adds "t", rejects "ot" but keeps 't' for accepting "three"
					parsed = parsed.back();
				}
			}
		}

		// Number in this line is...
		std::string num_str{ first };		// First char as string
		num_str += last;					// Concatenate first with last
		unsigned short num = stoi(num_str);	// Convert to int

		// Provisional print
		printf("%llu -> First: %c, Last: %c, Addition = %hu \n", line_count, first, last, num);

		// Add to list of line numbers
		line_numbers.push_back(num);

		// Get these ready for next iteration
		is_first_digit = true;
		parsed.clear();
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

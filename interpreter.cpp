#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>


// convert 8 booleans into a byte
unsigned char ToByte(bool b[8])
{
    unsigned char c = 0;
    for (int i=0; i < 8; ++i)
        if (b[i])
            c |= 1 << i;
    return c;
}


int main(int argc, char* argv[]) {
	std::map<char, int> vars;
	std::vector<std::string> lines;

	// Make sure there is an argument for the file
	if (argc <= 0) {
		std::cout << "Specify a file to interpret" << '\n';
		return 1;
	}

	std::ifstream file;

	// open the file specified
	file.open(argv[1]);
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			lines.push_back(line);
		}
		file.close();
	} else {
		std::cout << "Could not open file " << argv[1] << '\n';
		return 1;
	}

	// print the code for debugging purposes
	//std::cout << code << std::endl;

	// Loop through the characters in the code
	//for (char c : code) {
	//	if (c != ' ') { // Discard the character if it is a space
	//		vars[c] = c - '0';
	//	}
	//}

	int lineCounter = 1;
	for (std::string& code : lines) {
		if (code[0] != '+') {
			for (size_t i = 0; i < code.size(); i++) {
				if (code[i] == '[') {
					char currentChar = code[i + 1];
					int count = 1;
					while (currentChar != ']') {
						currentChar = code[i + count];
						if (currentChar == ']') {
							break;
						}

						std::cout << vars[currentChar];

						count++;
					}
					break;
				} else if (code[i] == '{') {
					char currentChar = code[i + 1];
					int count = 1;
					bool b[8];
					while (currentChar != '}') {
						currentChar = code[i + count];
						if (currentChar == '}') {
							break;
						}

						b[count - 1] = vars[currentChar];
						count++;
					}
					std::cout << ToByte(b);

					break;
				}else if (code[i] != ' ') {
					if (code[i + 1] == ',') {
						int newvar;
						std::cin >> newvar;

						if (newvar != 0 && newvar != 1) {
							std::cout << "Err[ln" << lineCounter << "] Exit, because input value wasn't a boolean." << std::endl;
							return 1;
						}

						vars[code[i]] = newvar;
					} else if (code[i+1] == ':') {
						int newvar;
						char val1 = code[i+2];
						char op = code[i+3];
						char val2 = code[i+4];

						if (op == '=') {
							newvar = vars[val1] == vars[val2];
						} else if (op == '!') {
							newvar = vars[val1] != vars[val2];
						}

						vars[code[i]] = newvar;

					} else if (code[i] == '!') {
						int var = !vars[code[i + 1]];
						vars[code[i + 1]] = var;
					} else {
						int newvar = code[i + 1] - '0';

						if (newvar != 0 && newvar != 1) {
							std::cout << "Err[ln" << lineCounter << "] A variable can only contain a boolean." << std::endl;
							return 1;
						}

						vars[code[i]] = newvar;
					}
					break;
				}
			}
		}

		lineCounter++;
	}

	/*for (auto const& x : vars)
	{
	    std::cout << x.first  // string (key)
	              << ':'
	              << x.second // string's value
	              << std::endl ;
	}*/

	std::cout << std::endl;
	return 0;
}

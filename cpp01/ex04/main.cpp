/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:26:28 by yogun             #+#    #+#             */
/*   Updated: 2023/03/07 19:59:17 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>


/*
	myReplace function:
	
	-The result variable is initialized to an empty string.
	-The start_pos variable is initialized to 0, indicating that we will start searching for occurrences of the substring "cat" from the beginning of the input string.
	-The pos variable is declared but not yet assigned a value.
	-The while loop starts. We search for the first occurrence of the substring "cat" in the input string, starting from the position indicated by start_pos. We store the position of the match in the pos variable. Since the match is found at position 4, pos is assigned the value 4.
	-We append the substring between start_pos and pos to the result variable. This substring is "The ", since it is the part of the input string before the match.
	-We append the replacement substring "dog" to the result variable.
	-We update start_pos to the position immediately after the match, which is 7. This will be the starting position for the next search.
	-The while loop continues. We search for the next occurrence of the substring "cat", starting from the new value of start_pos (7). We find another match at position 16, so pos is assigned the value 16.
	-We append the substring between start_pos and pos to the result variable. This substring is " sat on the mat.", since it is the part of the input string between the first match and the second match.
	-We append the replacement substring "dog" to the result variable.
	-We update start_pos to the position immediately after the second match, which is 19. This will be the starting position for the next search.
	-The while loop continues. We search for the next occurrence of the substring "cat", starting from the new value of start_pos (19). Since there are no more matches, pos is assigned the value std::string::npos, which is the special value indicating that no match was found.
	-We append the remaining substring after the last match to the result variable. This substring is ".", since it is the part of the input string after the last match.
	-The result variable now contains the
*/
class FileEditor {
public:
	// constructor that initializes the filename and strings using input parameters
    FileEditor(const std::string filename, const std::string s1, const std::string s2) : _filename(filename), _s1(s1), _s2(s2) {
		return ;
	}

	// deconstructor
	~FileEditor(void) {
		return ;
	}

	std::string myReplace(const std::string str, const std::string from, const std::string to) {
    	std::string result;
    	size_t start_pos = 0;
    	size_t pos;
		// npos is a static member constant value with the greatest possible value for an element of type size_t.
    	while ((pos = str.find(from, start_pos)) != std::string::npos) {
        	// Append the substring before the match to the result
        	result.append(str, start_pos, pos - start_pos);
        	// Append the replacement string
        	result.append(to);
        	// Update the start position for the next search
        	start_pos = pos + from.length();
    	}
    	// Append the remaining substring after the last match to the result
    	result.append(str, start_pos);
    	return result;
	}
	
    void editFile() {
        std::ifstream inputFile(_filename);
        if (!inputFile) {
            std::cerr << "Error: Unable to open input file.\n";
            return;
        }

        std::ofstream outputFile(_filename + ".replace");
        if (!outputFile) {
            std::cerr << "Error: Unable to open output file.\n";
            return;
        }

        std::string line;
        while (std::getline(inputFile, line)) {
            size_t pos = 0;
			// find and replace all occurrences of s1 with s2
			// pos is the position of the first character of the first match
			// npos is the maximum value for an element of type size_t
            while ((pos = line.find(_s1, pos)) != std::string::npos) {
                line = myReplace(line, _s1, _s2);
                pos += _s2.length();
            }
            outputFile << line << '\n';
        }

        std::cout << "File edited successfully.\n";
    }

private:
    std::string _filename;
    std::string _s1;
    std::string _s2;
};

int main(void) {
    std::string filename, s1, s2;

    std::cout << "Enter filename: ";
    std::cin >> filename;

    std::cout << "Enter string to replace: ";
    std::cin >> s1;

    std::cout << "Enter replacement string: ";
    std::cin >> s2;

    FileEditor fileEditor(filename, s1, s2);
    fileEditor.editFile();

    return 0;
}

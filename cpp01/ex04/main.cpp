/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:26:28 by yogun             #+#    #+#             */
/*   Updated: 2023/03/07 11:03:25 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

class FileEditor {
public:
	// constructor that initializes the filename and strings using input parameters
    FileEditor(const std::string& filename, const std::string& s1, const std::string& s2) : m_filename(filename), m_s1(s1), m_s2(s2) {
		return ;
	}

	// deconstructor
	~FileEditor(void) {
		return ;
	}

    void editFile() {
        std::ifstream inputFile(m_filename);
        if (!inputFile) {
            std::cerr << "Error: Unable to open input file.\n";
            return;
        }

        std::ofstream outputFile(m_filename + ".replace");
        if (!outputFile) {
            std::cerr << "Error: Unable to open output file.\n";
            return;
        }

        std::string line;
        while (std::getline(inputFile, line)) {
            size_t pos = 0;
            while ((pos = line.find(m_s1, pos)) != std::string::npos) {
                line.replace(pos, m_s1.length(), m_s2);
                pos += m_s2.length();
            }
            outputFile << line << '\n';
        }

        std::cout << "File edited successfully.\n";
    }

private:
    std::string m_filename;
    std::string m_s1;
    std::string m_s2;
};

int main() {
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

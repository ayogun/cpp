/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:07 by yogun             #+#    #+#             */
/*   Updated: 2023/04/14 17:11:09 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Trimming whitespace from the beginning of the string
static std::string& startTrim(std::string& str)
{
    str.erase(0, str.find_first_not_of(" \t\n\r"));
    return str;
}

// Trim whitespace characters from the end of a string
static std::string& endTrim(std::string& str)
{
    str.erase(str.find_last_not_of(" \t\n\r") + 1);
    return str;
}

/* 
	Trim whitespace characters from both ends of a string.
		> endTrim: Remove whitespace from the end of a string.
		> startTrim: Remove whitespace from the beginning of a string.
*/
static std::string& trim(std::string& str)
{
    return startTrim(endTrim(str));
}






/********************************************/
/*
	std::make_pair constructs a pair object with date and data as its elements. The pair is then inserted into the map. 
*/
// Set the data in the map.
void Bitcoin::setData(std::string key, float value)
{
	// Insert the date and value in the map.
	this -> data.insert(std::make_pair(key, value)); 
}
/************************************************/







// Get the data from the map.
std::map<std::string, float> Bitcoin::getData(void)
{
	return (this->data);
}

/* str: String to be split. So, it is one complete line from the txt file.
 delimiter: The delimiter is the character that separates the substrings. In our case, the delimiter is " | "
Here we split the string into a vector of strings. Each element of the vector is a substring.

From something like this: 2019-01-01 | 1000 
to this: [2019-01-01, 1000]     -> Here we have two substrings. The first substring is the date and the second substring is the value. And delimiter is " | "
 */
std::vector<std::string> Bitcoin::splitString(std::string str, char delimiter)
{
	std::vector<std::string> substringsVector;
	std::string substring = "";

	// Iterate through the string and check if the character is not equal to the delimiter.
	for (size_t i = 0; i < str.length(); i++)
	{	
		// If the character is not equal to the delimiter, add it to the substring.
		if (str[i] != delimiter)
		{
			substring += str[i];
		}
		// If the character is equal to the delimiter, add the substring to the vector and reset the substring.
		else
		{
			substringsVector.push_back(substring); // Add the substring to the vector.
			i++;
			substring = "";
		}
	}
	// Add the last substring to the vector. This is done because the last substring is not added to the vector in the for loop. In other words, we add the string after the last " | "
	substringsVector.push_back(substring);
	
	// Return the vector.
	return substringsVector;
}


// Check if the date is valid or not.
bool Bitcoin::isDateValid(int year, int month, int day)
{
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
	{
		return false;
	}
	if (month == 2 && day > 29)
	{
		return false;
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
	{
		return false;
	}
	return true;
}



// In this function what we do is we read the input file and we check if the input is valid or not. In our case, it is the file that was given to us. The file is called input.txt.
void Bitcoin::checkInputFile(std::string filePath)
{
	int i = 0;
	// Open the file. The file path is passed as an argument to the function.
	std::ifstream txt_file(filePath);

	// Check if file is open. If not, print an error message and return.
	if (!txt_file.is_open())
	{
		std::cerr << "Error : Input file(input.txt) not found!" << std::endl;
		return;
	}
	
	std::string line;
	std::vector<std::string> vectorLine;
	
	
	// While getline is able to read a line from the file, continue.
	while(std::getline(txt_file, line))
	{	
			// Skip the first line of the file. We skip the first line because it contains the column names.
			if (i != 0)
			{	
			vectorLine = this->splitString(line, '|'); // Split the line using the splitString function.
	
			// Check if the input is valid or not. If the input is not valid, print an error message and continue. The length function is used to check if the string is empty or not. The size function is used to check if the vector is empty or not.
			if (vectorLine[1].length() == 0 || vectorLine.size() < 2)
				std::cout << "Error: bad input => " << vectorLine[0] << std::endl;
			
			if (!Bitcoin::isDateValid(std::stoi(vectorLine[0].substr(0, 4)), std::stoi(vectorLine[0].substr(5, 2)), std::stoi(vectorLine[0].substr(8, 2))))
				std::cout << "Error: bad date => " << vectorLine[0] << std::endl;
				
				
			std::map<std::string, float>::iterator iterator = this->data.upper_bound(trim(vectorLine[0])); // upper_bound returns an iterator to the first element in the map that is greater than the key. Txt'den gelen tarihin map'teki tarihten küçük olduğu düğümü bulup, iterator'a atıyoruz. Eğer txt'den gelen tarih map içindeki tarihlerin hepsinden daha büyükse, iterator map'in son elemanınını gösterir. 

	
							
			// Here we compare 
			if (iterator != this->data.end() && trim(vectorLine[0]) != this->data.rbegin()->first)
			{
				
	    	    std::pair<std::string, float> ptr = *(--iterator); 	// Here we get the previous element of the iterator. The reason for that is because we want to get the lower value that is closest to the absent input.

				try
				{	
					// If the value is greater than 1000 or less than 0, print an error message. Else, print the result.
					if (std::stod(vectorLine[1]) > 1000)
						std::cout << "Error: too large a number." << std::endl;
					else if (std::stod(vectorLine[1]) < 0)
						std::cout << "Error: not a positive number." << std::endl;
					else
			        	std::cout << vectorLine[0] << " => " << vectorLine[1] << " = " << std::stod(vectorLine[1]) * ptr.second << std::endl;
				}
				catch (const std::exception &e)
				{
					(void)e;
					std::cout << "Error : Input Not A Number" << std::endl;
					continue;
				}
			}
			// If the date is the last date in the map, print the result.
			else if(trim(vectorLine[0]) ==  (this->data.rbegin()->first))
			{
				try
				{	
					// If the value is greater than 1000 or less than 0, print an error message. Else, print the result.
					if (std::stod(vectorLine[1]) > 1000)
						std::cout << "Error: too large a number." << std::endl;
					else if (std::stod(vectorLine[1]) < 0)
						std::cout << "Error: not a positive number." << std::endl;
					else
			        	std::cout << vectorLine[0] << " => " << vectorLine[1] << " = " << std::stod(vectorLine[1]) * (this->data.rbegin()->second) << std::endl;
				}
				catch (const std::exception &e)
				{
					(void)e;
					std::cout << "Error : Input Not A Number" << std::endl;
					continue;
				}
			}
			// If the date is greater than the date in the CSV file, print an error message.	
			else
				std::cout << "Error: Date is greater than the last date in the CSV file." << std::endl;
		}
		i++;
	}
	txt_file.close();
}












/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/

// Default constructor.
// Reads the data from the csv file and stores it in a map.
// If the file is not found, error message is printed and the program exits.
// This is used to check if the file was read successfully in the main function.
// If the file is not found, the program exits.
Bitcoin::Bitcoin(void)
{
	int i = 0;
	std::ifstream csv_file("./data.csv");

	// Check if file is open. If not, print an error message and return.
	if (!csv_file.is_open())
	{
		std::cerr << "Error : Database(CSV file) not found!" << std::endl;
		return;
	}
	
	std::string line;

	// While getline is able to read a line from the file, continue.
	while(std::getline(csv_file, line))
	{
		// Skip the first line of the file. We skip the first line because it contains the column names.
		if (i != 0)
		{
		
			// Find the position of the comma in the line. Find returns the position of the first occurrence of the character in the string. If the character is not found, the function returns last. Comma is used to separate the date and value in the csv file.
			size_t position = line.find(',');
	
	
			// If the comma is not found, print an error message and continue. std::string::npos is a constant static member value with the greatest possible value for an element of type size_t. 18446744073709551615UL
			//This value, when used as the value for a len (or sublen) parameter in string's member functions, means "until the end of the string".
			
			if (position == std::string::npos) // if the comma is not found
				std::cerr << "Error : In CSV file, line without comma has been found! Please check." << std::endl;
	
			/************************************************************************************/
	
			// Get the date and value from the line from the csv file from beginning to the comma position.
			std::string date = line.substr(0, position);
        	double data;	//	We use double here because the data can be a decimal number.
        	try 
			{	
				// Convert the value to a double and store it in the data variable. The substr function returns a string from the <position> to the end of the string. With the stod function, we convert the string to a double. By this way we get the bitcoin data from the line.
        	    data = std::stod(line.substr(position + 1));
        	}
			catch (std::exception &e) 
			{
				std::cerr << line << std::endl;
        	    std::cerr << "Error: could not parse value because: " << e.what() << std::endl;
        	    continue; // Continue to the next line.
        	}
			this->setData(date, data); // Set the data in the map.
			}
		i++;
	}
	// We read the file sucessfully. Now we can close the file.
	csv_file.close(); // Close the file.
}

// Destructor.
Bitcoin::~Bitcoin(void)
{
	return ;
}

// Overload the assignment operator.
Bitcoin &Bitcoin::operator=(Bitcoin const &var)
{
	this->data = var.data;
	return (*this);
}

// Copy constructor.
Bitcoin::Bitcoin(Bitcoin const &var)
{
	*this = var;
}


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
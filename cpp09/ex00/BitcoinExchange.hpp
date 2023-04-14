/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:07 by yogun             #+#    #+#             */
/*   Updated: 2023/04/14 17:07:32 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <cctype>

class Bitcoin
{
public:

	/************************ ORTHODOX CANONICAL FORM ******************************/
	// Default constructor
	Bitcoin(void);
	// Destructor
	~Bitcoin(void);
	// Assignment operator
	Bitcoin& operator=(Bitcoin const &var);
	// Copy constructor
	Bitcoin(Bitcoin const &var);
	/************************ ORTHODOX CANONICAL FORM ******************************/




	/************************ MEMBER FUCNTIONS ******************************/
	// Setter
	void setData(std::string date, float value);

	// Function to check if the file path is valid and if the file is readable.
	void checkInputFile(std::string filePath);

	// Function to get the data from the csv file.
	std::map<std::string, float> getData();		

	// Function to split a string into a vector of strings.
	std::vector<std::string> splitString(std::string str, char delimiter); 
	
	// Function to check if the date is valid.
	bool isDateValid(int year, int month, int day); 
	/************************ MEMBER FUCNTIONS ******************************/

	
private:
	// Map to store the data from the csv file. This is a vector of pairs. The first element of the pair is the date and the second element is the value.
	std::map <std::string, float> data; 
};

#endif
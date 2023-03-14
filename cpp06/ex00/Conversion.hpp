/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:14:07 by yogun             #+#    #+#             */
/*   Updated: 2023/03/14 01:38:23 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <string>

class ScalarConverter
{
    public:
        static char toChar(std::string const & str);
        static int toInt(std::string const & str);
        static float toFloat(std::string const & str);
        static double toDouble(std::string const & str);
    private:
        static bool isNonDisplayable(char c);
};

#endif

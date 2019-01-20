/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShellUIClass.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourdin <jgourdin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:56:37 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/20 17:19:31 by jgourdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELLUICLASS_HPP
# define SHELLUICLASS_HPP

# include <iostream>
# include "MonitorDisplayClass.hpp"

class ShellUI: public MonitorDisplay
{

public: 

    ShellUI(void); 
    ShellUI(ShellUI const & src); 
    ~ShellUI(void); 

	ShellUI &		operator=(ShellUI const & rhs);


private:

};

#endif

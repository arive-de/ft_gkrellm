/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModuleClass.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:04:13 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/19 15:28:26 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULECLASS_HPP
# define IMONITORMODULECLASS_HPP

# include <iostream>

class IMonitorModule {

public: 

    IMonitorModule(void); 
    IMonitorModule(IMonitorModule const & src); 
    ~IMonitorModule(void); 
    
	IMonitorModule &		operator=(IMonitorModule const & rhs);

private:

};

#endif

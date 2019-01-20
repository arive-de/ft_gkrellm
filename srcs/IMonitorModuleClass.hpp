/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModuleClass.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:04:13 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/20 16:25:19 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULECLASS_HPP
# define IMONITORMODULECLASS_HPP

# include <iostream>
# include <string>
# include <stdlib.h>
# include <mach/mach.h>
# include <mach/mach_error.h>
# include <mach-o/arch.h>
# define BUFFER_LEN 100000

class IMonitorModule {

public: 

    IMonitorModule(void); 
    virtual ~IMonitorModule(void); 

    virtual std::string     getInfos() = 0;

private:

    IMonitorModule(IMonitorModule const & src); 
	IMonitorModule &		operator=(IMonitorModule const & rhs);

};

#endif

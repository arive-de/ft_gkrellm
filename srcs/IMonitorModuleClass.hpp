/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModuleClass.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourdin <jgourdin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:04:13 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/20 17:42:18 by jgourdin         ###   ########.fr       */
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

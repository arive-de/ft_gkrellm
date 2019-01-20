/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModuleClass.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:04:13 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/20 15:36:11 by arive-de         ###   ########.fr       */
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
    IMonitorModule(IMonitorModule const & src); 
    ~IMonitorModule(void); 
    
	IMonitorModule &		operator=(IMonitorModule const & rhs);

    virtual std::string     getStdOut(std::string cmd) = 0;

    int            getFlag() const;
    bool           getStart() const;

protected:

    bool    _start;
    int     _flag;
    char            _buffer[BUFFER_LEN];
    size_t          _bufferlen;

};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorModuleClass.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourdin <jgourdin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:04:13 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/19 12:10:28 by jgourdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITORMODULECLASS_HPP
# define MONITORMODULECLASS_HPP

# include "IMonitorModuleClass.hpp"
# include "MonitorDisplayClass.hpp"
# include <iostream>
# include <sys/sysctl.h>
# include <sstream>
#include <mach/mach.h>
#include <mach/mach_error.h>
#include <mach-o/arch.h>
# define BUFFER_LEN 100000

class MonitorModule : public IMonitorModule {

public: 

    typedef MonitorModule	t;
    MonitorModule(void); 
    MonitorModule(MonitorModule const & src); 
    ~MonitorModule(void); 
    
	MonitorModule &		operator=(MonitorModule const & rhs);

    int            getFlag() const;
    bool           getStart() const;
    std::string    getHostName(void);
    std::string    getUserName(void);
    std::string    getDateTime(void);
    std::string    getOsInfos(void);
    std::string    getStdOut(std::string command);
    host_cpu_load_info_data_t getCpuInfo(void);
    mach_msg_type_number_t getCount(void);
    unsigned long  getCpuTicks(void);
	unsigned long  getUserTicks(void);
	unsigned long  getIdleTicks(void);
	unsigned long  getPrevCpuTicks(void);
	unsigned long  getPrevUserTicks(void);    
	unsigned long  getPrevIdleTicks(void);

    std::string    CPUModule(void);

protected:

    MonitorDisplay  *_display;    
    bool            _start;
    int             _flag;
    char            _buffer[BUFFER_LEN];
    size_t          _bufferlen;

    std::string     _hostname;
    std::string     _username;
    time_t          _ctt;
    std::string     _datetime;
    std::string     _osInfos;
    std::string     _cpuModule;
    std::string     _coreCount;
    std::string     _model;
    std::string     _clockSpeed;
    host_cpu_load_info_data_t _cpuinfo;
    mach_msg_type_number_t _count;
    unsigned long   _cpuTicks;
	unsigned long   _userTicks;
	unsigned long   _idleTicks;
	unsigned long   _prevCpuTicks;
	unsigned long   _prevUserTicks;    
	unsigned long   _prevIdleTicks;
    

};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorModuleClass.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourdin <jgourdin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:04:31 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/19 15:03:17 by jgourdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MonitorModuleClass.hpp"
#include <iostream>
# include <sys/sysctl.h>

MonitorModule::MonitorModule(void)
{
    this->_hostname = getStdOut("sysctl -n kern.hostname");
    this->_username = getenv("USER");
    this->_osInfos = getStdOut("sw_vers");
    this->_coreCount = "Number of core: " + getStdOut("sysctl -n machdep.cpu.core_count");
    this->_model = "Cpu model: " + getStdOut("sysctl -n machdep.cpu.brand_string");
    this->_clockSpeed = "Clock Speed: " + getStdOut("sysctl -n hw.cpufrequency");
    this->_bufferlen = BUFFER_LEN;
    this->_cpuTicks = 0;
	this->_userTicks = 0;
	this->_idleTicks = 0;
	this->_prevCpuTicks = 0;
	this->_prevUserTicks = 0;
	this->_prevIdleTicks = 0;
    return;
}

    MonitorModule::MonitorModule(MonitorModule const & src) 
{
    *this = src;
    return;
}

MonitorModule::~MonitorModule(void)
{
    return;
}

int                 MonitorModule::getFlag(void) const
{
    return this->_flag;
}

bool                 MonitorModule::getStart(void) const
{
    return this->_start;
}

std::string                MonitorModule::getHostName(void)
{
    return this->_hostname;
}

std::string                MonitorModule::getUserName(void)
{
    return this->_username;
}

std::string                 MonitorModule::getDateTime(void)
{
    this->_ctt = time(0);
    this->_datetime = asctime(localtime(&this->_ctt));
    this->_datetime = this->_datetime.substr(0, this->_datetime.size() - 1);
    return this->_datetime;
}

std::string                 MonitorModule::getOsInfos(void)
{
    return this->_osInfos;
}

host_cpu_load_info_data_t MonitorModule::getCpuInfo(void)
{
    return this->_cpuinfo;
}

mach_msg_type_number_t MonitorModule::getCount(void)
{
    return this->_count;
}

unsigned long  MonitorModule::getCpuTicks(void)
{
    return this->_cpuTicks;
}

unsigned long  MonitorModule::getUserTicks(void)
{
    return this->_userTicks;
}

unsigned long  MonitorModule::getIdleTicks(void)
{
    return this->_idleTicks;
}

unsigned long  MonitorModule::getPrevCpuTicks(void)
{
    return this->_prevCpuTicks;
}

unsigned long  MonitorModule::getPrevUserTicks(void)
{
    return this->_prevUserTicks;
}   

unsigned long  MonitorModule::getPrevIdleTicks(void)
{
    return this->_prevIdleTicks;
}


std::string                 MonitorModule::CPUModule(void)
{

    this->_count = HOST_CPU_LOAD_INFO_COUNT;
	if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, reinterpret_cast<host_info_t>(&this->_cpuinfo), &this->_count) == KERN_SUCCESS)
    {  
        this->_prevUserTicks = this->_cpuinfo.cpu_ticks[0];
		this->_prevCpuTicks = this->_cpuinfo.cpu_ticks[1];
		this->_prevIdleTicks = this->_cpuinfo.cpu_ticks[2];
    }
    
    this->_cpuModule = this->_coreCount + "\n" + this->_clockSpeed + "\n" + this->_model;
    return this->_cpuModule;
}


std::string                 MonitorModule::getStdOut(std::string cmd)
{
    std::string data;
    FILE * stream;

    cmd.append(" 2>&1");

    stream = popen(cmd.c_str(), "r");
    if (stream)
    {
        while (!feof(stream))
            if (fgets(this->_buffer, this->_bufferlen, stream) != NULL) data.append(this->_buffer);
              pclose(stream);
    }
    memset(this->_buffer, 0, sizeof(this->_buffer));
    data = data.substr(0, data.size() - 1);
    return data;
}

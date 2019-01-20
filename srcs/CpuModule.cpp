/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:25:03 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/20 15:31:20 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CpuModule.hpp"

CpuModule::CpuModule(void) {

    this->_coreCount = "Number of core: " + IMonitorModule::getStdOut("sysctl -n machdep.cpu.core_count");
    this->_model = "Cpu model: " + IMonitorModule::getStdOut("sysctl -n machdep.cpu.brand_string");
    this->_clockSpeed = "Clock Speed: " + IMonitorModule::getStdOut("sysctl -n hw.cpufrequency");
    this->_bufferlen = BUFFER_LEN;
    this->_cpuTicks = 0;
	this->_userTicks = 0;
	this->_idleTicks = 0;
	this->_prevCpuTicks = 0;
	this->_prevUserTicks = 0;
	this->_prevIdleTicks = 0;
}

CpuModule::CpuModule(CpuModule const & src) {

    *this = src;
}

CpuModule::~CpuModule(void) {


}


CpuModule & CpuModule::operator=(CpuModule const & rhs) {

    this->_coreCount = rhs._coreCount;
    this->_model = rhs._model;
    this->_clockSpeed = rhs._clockSpeed;
    // this->_bufferlen = rhs._bufferlen;
    this->_cpuinfo = rhs._cpuinfo;
    this->_count = rhs._count;
    this->_cpuTicks = rhs._cpuTicks;
	this->_userTicks = rhs._userTicks;
	this->_idleTicks = rhs._idleTicks;
	this->_prevCpuTicks = rhs._prevCpuTicks;
	this->_prevUserTicks = rhs._prevUserTicks;
	this->_prevIdleTicks = rhs._prevIdleTicks;

    return *this;
}

host_cpu_load_info_data_t CpuModule::getCpuInfo(void)
{
    return this->_cpuinfo;
}

mach_msg_type_number_t CpuModule::getCount(void)
{
    return this->_count;
}

unsigned long  CpuModule::getCpuTicks(void)
{
    return this->_cpuTicks;
}

unsigned long  CpuModule::getUserTicks(void)
{
    return this->_userTicks;
}

unsigned long  CpuModule::getIdleTicks(void)
{
    return this->_idleTicks;
}

unsigned long  CpuModule::getPrevCpuTicks(void)
{
    return this->_prevCpuTicks;
}

unsigned long  CpuModule::getPrevUserTicks(void)
{
    return this->_prevUserTicks;
}   

unsigned long  CpuModule::getPrevIdleTicks(void)
{
    return this->_prevIdleTicks;
}

std::string          CpuModule::getCpuUsage(void)
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
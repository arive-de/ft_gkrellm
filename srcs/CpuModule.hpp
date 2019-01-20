/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CpuModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:25:02 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/20 16:34:56 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_MODULE_HPP
# define CPU_MODULE_HPP

# include "IMonitorModuleClass.hpp"
# define BUFFER_LEN 1000

class CpuModule : public IMonitorModule {

public:

        CpuModule(void);
        CpuModule(CpuModule const & src);
        ~CpuModule(void);

        CpuModule & operator=(CpuModule const & rhs);

        std::string    getInfos(void);
        std::string    getStdOut(std::string cmd);
        host_cpu_load_info_data_t getCpuInfo(void);
        mach_msg_type_number_t getCount(void);
        unsigned long  getCpuTicks(void);
	unsigned long  getUserTicks(void);
	unsigned long  getIdleTicks(void);
	unsigned long  getPrevCpuTicks(void);
	unsigned long  getPrevUserTicks(void);    
	unsigned long  getPrevIdleTicks(void);

private:

        char            _buffer[BUFFER_LEN];
        size_t          _bufferlen;
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

#endif
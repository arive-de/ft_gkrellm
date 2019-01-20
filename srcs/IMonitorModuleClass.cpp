/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModuleClass.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 12:04:31 by jgourdin          #+#    #+#             */
/*   Updated: 2019/01/20 15:21:07 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorModuleClass.hpp"

IMonitorModule::IMonitorModule(void)
{
    return;
}

    IMonitorModule::IMonitorModule(IMonitorModule const & src) 
{
    *this = src;
    return;
}

IMonitorModule::~IMonitorModule(void)
{
    return;
}

int                 IMonitorModule::getFlag(void) const
{
    return this->_flag;
}

bool                 IMonitorModule::getStart(void) const
{
    return this->_start;
}


IMonitorModule &	IMonitorModule::operator=(IMonitorModule const & rhs)
{
    if (this != &rhs)
    {
        this->_start = rhs.getStart();
        this->_flag = rhs.getFlag();
    }
    return *this;
}

std::string           IMonitorModule::getStdOut(std::string cmd)
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

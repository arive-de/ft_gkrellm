/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RamModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourdin <jgourdin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:24:57 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/20 17:24:45 by jgourdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RamModule.hpp"

RamModule::RamModule(void) {

    this->_bufferlen = BUFFER_LEN;
    this->_ram += "Ram: ";
    this->_ram += getStdOut("sysctl -n hw.memsize");
    this->_ram = this->_ram.substr(0, 6);
    this->_ram += " GB";
}

RamModule::RamModule(RamModule const & src) {

    *this = src;
}

RamModule::~RamModule(void) {


}

RamModule & RamModule::operator=(RamModule const & rhs) {

    this->_ram = rhs._ram;
    return *this;
}

std::string                RamModule::getInfos(void)
{
    return this->_ram;
}

std::string           RamModule::getStdOut(std::string cmd)
{
    std::string data;
    FILE * stream;

    cmd.append(" 2>&1");

    // sysctlbyname("net.inet.ip.stats", oldp, &oldlen, newp, newlen);

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

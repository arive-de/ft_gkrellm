/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:24:56 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/20 19:21:25 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Hostname_HPP
# define Hostname_HPP

# include "IMonitorModuleClass.hpp"
# define BUFFER_LEN 1000

class HostnameModule : public IMonitorModule {

public:

        HostnameModule(void);
        HostnameModule(HostnameModule const & src);
        virtual ~HostnameModule(void);

        HostnameModule & operator=(HostnameModule const & rhs);

        std::string    getInfos(void);
        std::string    getStdOut(std::string cmd);


private:

        std::string     _hostname;
        char            _buffer[BUFFER_LEN];
        size_t          _bufferlen;
};

#endif

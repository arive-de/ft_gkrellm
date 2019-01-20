/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:24:56 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/20 15:08:08 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Hostname_HPP
# define Hostname_HPP

# include "IMonitorModuleClass.hpp"

class HostnameModule : public IMonitorModule {

public:

        HostnameModule(void);
        HostnameModule(HostnameModule const & src);
        ~HostnameModule(void);

        HostnameModule & operator=(HostnameModule const & rhs);

        std::string    getHostName(void);


private:

        std::string     _hostname;
};

#endif
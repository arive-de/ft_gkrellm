/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UsernameModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <arive-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:24:47 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/20 15:08:33 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERNAME_MODULE_HPP
# define USERNAME_MODULE_HPP

# include "IMonitorModuleClass.hpp"

class UsernameModule : public IMonitorModule {

public:

        UsernameModule(void);
        UsernameModule(UsernameModule const & src);
        ~UsernameModule(void);

        UsernameModule & operator=(UsernameModule const & rhs);

        std::string    getUserName(void);

private:

        std::string     _username;

};

#endif
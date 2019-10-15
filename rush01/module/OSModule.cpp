/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSModule.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:49:57 by aillia            #+#    #+#             */
/*   Updated: 2019/10/13 17:46:39 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OSModule.hpp"

int 	OSModule::GetOSVersionComponent(int component) {
    char cmd[64] ;
    sprintf(
            cmd,
            "sw_vers -productVersion | awk -F '.' '{print $%d}'",
            component
    ) ;
    FILE* stdoutFile = popen(cmd, "r") ;

    int answer = 0 ;
    if (stdoutFile) {
        char buff[16] ;
        char *stdout = fgets(buff, sizeof(buff), stdoutFile) ;
        if (!stdout)
            return 0;
        pclose(stdoutFile) ;
        sscanf(stdout, "%d", &answer) ;
    }
    return answer ;
}

OSModule::OSModule() {
	setOS("MacOS Hign Sierra");
	setVersion("Version " + std::to_string(GetOSVersionComponent(1)) + "." + std::to_string(GetOSVersionComponent(2)) + "." + std::to_string(GetOSVersionComponent(3)));
}

OSModule::~OSModule() {}

std::string		OSModule::getOS(void) const { return _os; }
std::string		OSModule::getVersion(void) const { return _version; }
void			OSModule::setOS(std::string input) { _os = input; }
void			OSModule::setVersion(std::string input) { _version = input; }

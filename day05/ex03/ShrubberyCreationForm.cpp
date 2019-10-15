/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:41:46 by aillia            #+#    #+#             */
/*   Updated: 2019/10/08 20:41:47 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& a) : Form(a) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::action() const {
	std::ofstream	ofs(_target + "_shrubbery");

	ofs << "                              $\n                              :$$\n                         seeee$$$Neeee\n                           R$$$F$$$$F\n                             $$$$$$\n                            @$$P*$$B\n                           z$#'  $#$b\n                           ' d   'N '\n                            @'     ?r\n                          xF .       'N\n                       .$> P54.R       `$\n                     $*   '*'$$$  uoP***~\n                      #Noo '?$N'   #oL\n                         f       o$#$$'e.\n                        $  @b    hoR$$r ^'$$b\n                     .M   ?B$E   *.B$$       .R\n                   .*     *| *.4*R         ..*\n                oo#     ooL    d#R.     P##~\n                $c    .''P#$  @   P     k\n                  R$r ''?L$$  P  'r     'N\n                    ^$ '$$$` $.....JL     'N.\n                  .$|           * P5'LR      $..\n               ..* 4*R     xr    'PFN$$   .k    '*****.\n            od#'   d#*.  '*$$P~   '?$*' '#$$$'       u'\n         e''      f   M   @F'$  ec       x$'$.     :'\n         M        >  'd       $$$$?$           .$$F`\n          'P..  .$.....$L $$.4$$. '   @#3$$   $E.\n             '**..  *   R..$$ `R$*k.  fdM$$>     *..\n               J'       *k$$$~  '*$**o$o$$P        '*oo.\n              P           #        '$$$#*o          >  '####*oooo\n           .e'            :e$$e.  F3  ^'$P  :$$s :e@$ee        s'\n         $P` M7>    $P$$k '$'?$3 @'#N      CxN$$> .$$$       .P\n      M$~   J|##   44N>$$  .d$.$d   @&      `$$$  F  .8..$$$*\n  .***     :   JM   *d$$*.$$.P  M  .P5     M          **.\n  'oo      J  .dP    ud$$od#   $oooooo$  oo$oo           ###ou\n     '####$beeeee$.'$eeP#~        ''      $$$.    e$$$o       #heeee\n        :'    ' z$r ^            o$N     ''  '   4$z>$$             '''#$$$\n       .~      F$4$B       r    F @#$.       ..   $8$$P M7                $\n     .*  $     8 $$B     .J$..  hP$$$F     .'PB$       J~##             .d~\n   .P  *$$$*   '*'       $$$    #**~      hdM$$>     <   JM.......*****\n .P     $#*k       .o#>  P' 'k   ..         '$$P      d  .JP'h\n'''hr ^        xe''  >          ''c           ee    @beeeee$.)\n      '''t$$$$F'      M        $`   R          > '$r     '     'c\n                              oooooooooo\n                              z        z\n                              z.,ze.$$$z\n";
	ofs.close();
	// std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

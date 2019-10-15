#ifndef FT_RETRO_HPP
# define FT_RETRO_HPP

#include "ncurses.h"
# include <unistd.h>
# define MAP_WIDTH 100
# define MAP_HEIGHT 55

# define BACKGROUND_MOVE 60


const char img[MAP_HEIGHT][107] = { 
"%%%%%%%%%=%%%%%%%%%%%%%@..............@@...........==......@@@@....@%%%%.......==%.....@%=%==%=====%%%%%%%",
"%%%%%%==%%%%%%%%%%%%%@@.....%%...@@......................@@@.......@%%%@................@%=%===%=++%%%%%%%",
"%%%%==%%%%%%%%%%%%%%%............@%@......@............@@@...@==%%@%%%@..................@%==%===+*%%%%%%%",
"===%%%%%%%%%%%%%%%%.................................@@%@....=%%%%@@..@%%%@.................%%==%%=::=%%%==",
"+====%%%%%%%==%%@...................................@@.....@@@.........@%%%@....*%...........@%%==%=*-:==+",
"%====%%%%%%=%@..............*@.......@..........@.......................%%%%@........@%.........@%=%===%%%",
"=%%%%%%%@......@........@...........+@%%@............@@.................@%%%%@......................@@%%%=",
"...................................%=*@%=%%@@.............@.............@%%%%@............................",
"..................................%===*%%%%%%@@......@@..........==.....%%%%%%@...........@%@.............",
".@@.......................@......@=====*%%%%%*%%@@.....................@%%%%%+@............@@....=@..@==..",
".................................@===++%*%%:-=%%%%%@..................%%%@+%%%@..........@%...............",
".....=@..........%%..............%=+====%++%@.@%%%%%%%@@...........@@%%%%%%%%%.........@@.@@..............",
"@....%@........%=%%......%.....@@%==%=====%*+=%%%%%%%%%%%%%@@@@@@%%%%%%%%%%%%@....@=%@@........=%........@",
"..............@=%%%.....=-=...@%..%%=%======%%%%%%%%%%%%%%%%%%%%%%%%@%%%%%%%@.....%=@..........@......@...",
"..............@%%@@........@@@.....%%=%==%===+%%%%%%%%%%%%%%%%%%%%%%%%%%%%%@...@@@.....@..............@...",
"..%=%....@%==%%%%@........@@........%%=%%===+*%%%%%%%%%%%%%%%%%%%%%%%%%%%%@...@@......................@...",
".......%=%%%%@@@@%%@.................@%%==%==-+%%%%%%%%%%%%%%%%%%%%%%%%%@......@@..............@..........",
"......%%@@@......@%%%@.................@%%===%*--=%====%%%%%%%%%%%%%%%@.................@........@@.......",
".......@.....@....@=%=%@.....@............@%==%=%=*+===========%%%%@......................................",
"......@%@..........@%=%%......................@%==============%@...........@.............%%%@@............",
"=@.................@%=%%@...................@@...................................@......@++%%=%@@.......@=",
"...........@%......@%%%%%....................@.................@%......................@==+==@%=%%@.......",
".......@.@@.@@....@%%%%=%@...........@.......................@@@....................%..====++%=%=%=%@@....",
"......@@@........@%%%%%%%@.....................*...........@%@...@@...................@=%====*%%*:%%%%%@@.",
"@@..@%@........@%%%%%%%%%@........................@.....@%@............@.@@...........@====%=%*%=%.@%%%%%%",
"%%==%@......@%%%%%%%%%%%@.............................%=%............=%%..............@%=%======*%%%%%%%%%",
"==%%%%%%%%%%%%%%%%%%%%%%............................@%..............=%%%.........=@....%==%===%==%%%%%%%==",
"%%%%%%%%%%%%%%%%%%%%%%%..@....................%*...==@.............@%%%@.........@......%==%==%===+%%%%%%%",
"%%%%%%%%%%%%%%%%%%%%%%........@@........@.......................@%%%%%@..................%==%===%++%%%%%%%",
"@%%%%%%%%%%%%%%%%%%%@......@..........................@@....@==%%%%@@%%%@.................%%==%==+-%%%@%%%",
"==%%%%%%%%%%%%%%%%..............................@..........%%%%%@@....@%%%@.................%%===%=--=%%==",
"==========%===%@...@@...........@.........@............................@+%%%..................@%=%%=%=:-+=",
"===========@....................@....%=@................................@%%%@.............@.......%%======",
"@@@@@@....................:-%......@*=%%@@@.......@%.......@............@%%%%@.........@%@..............@@",
"......@...........@..............%@==*%=%%%%@@..........................@%%%%@.......%=@..................",
"..............................@%@@====*%%=%%%%=@....................%..@%%%%%%@....%@@......@.............",
"................%@.....%@...@%@..@=%===+=%%==%%%%%@...@@..............@%%%%%%%@.@%@....................@@.",
".........@@............@@.@%@....@=======+@*+.@%%%%%%@...............@%%%%=%%%%%@..................@=@....",
"...@............%=%..............@%=%====%*%%@%%%%%%%%%@@.........@%%%%=%%=%%%......@......@.......@......",
"...............=%%%...............%========%=+%%%%%%%%%%%%%%%%%%%%%%%%%=%%%%%@............................",
"..............@%%%%...............@%=%========%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%@.............................",
".....@@.......@%%%.......@.........@%==%==%=++%%%%%%%%%%%%%%%%%%%%%%%%%%%%%@......--@.....................",
"........%=%%%%%%%@@..................%%=%%==+:%%%%%%%%%%%%%%%%%%%%%%%%%%%%...........................@....",
".@....@=%%%%%@..@%%%@...........@.....@%%==%%:-+%%%==%%%%%%%%%%%%%%%%%%%..................................",
".........@%@.....@@%%%@.................@%=%=%%+:-*===========+====%%@.....@%........@...........@@.......",
"....%=%%@@.........%%%%@...................@%%%====%%%%===%======%.............@..........@@....@--@......",
".....@@@...........@%%%%@.....=-@...............@@%%%%%%====@............................*%%%%@...........",
".%%%@........@.....@%%%%%............%%................%@........................@%.....%=*%%%%%@@........",
"%%@................%%%%%%@..........................@%@@.........@=....................%===*@%%%%%%%...@..",
"........%==@......@%%%%%=@................@.........@.............@..........@==......@=%===*%%%%%+%%%%%@.",
"....@...........@%%%%*%%%@......@@...........@@................=@..................@..@=====%*%%:-=%==%%@@",
"%%@...........@%%%%%%%%%@...........@@...............................@=%..............@%=%=====*%%%=%%%%%%",
"%%%%%%@@@@@%%%%%%%%%%%%%@..............................=.....@......%%%%@.......@......%=%===%==**+%%%%%%%",
"@@@@@@@@@@@@@@@@@@@@@@@@.............@@@........@..@%..............@@@@@.......%%@.....@@@@@@%%%@@@@@@@@@@"};


const char begin_img[36][107] = {
"                                                                                                          ",
"                                                                                                          ",
"                                                                                                          ",
"                                                                                                          ",
"                                                                                                          ",
"                                                                                                          ",
"                                                                                                          ",
"                                                                                                          ",
"                                                                                                          ",
"                                                                                                          ",
"                                                                                                          ",
"              ........ .. .. ..                                    .  .                                   ",
"           ....::::::::::::::-... ...                        . ....:::::......                            ",
"           ..*:###############:+* ...                       ..  .-*####@:+....                            ",
"           ...=:@#####@-+.@#####*=..                        .  . :*#####-=....                            ",
"           ....=%#####*:.++######::........ .... ..... .. . ......-*+=+*-........... .  .......           ",
"           ....+%#####:+*=######*+....-*::::*:.......:::::::::*:*-..::::**..-***:+**:***:.....            ",
"           ....+%#############::+..-+*%#######+*:.+*+############-++#####:+:=####%@#####%::...    .       ",
"           ....+%#######%%######@.%:####*+*%####+==####=%-#####++%:@#####:-%*#####:@*####@+.. . .....     ",
"           ....+%####@*-..+@######-####%:-=#####:%#####*-+=#####+-*:#####::-+#####*.+#####+:... .....     ",
"        . .....=%#####+-..+@######:#########@+:%=+#####*-+%#####+-::#####::-+####@*.+#####+:..  .....     ",
"        .. ...+:######+***@######-=+####@-+****@++=####@*+#####*:.*-#####:*++####@*+*#####*+..  .....     ",
"       ......:%###############@:+..+:=########@:=.**:@@@#@#####*+++#######*@#######.#######-*.. .....     ",
"              -+=++++++++***:...... ..+=*:::=+...@-####+-.+.####=:-+++++*-.-*+++**:.:***::-.      .       ",
"             ......      ...  .      .. ..  . ..+:######@@######:=. .. ..  .....  ... .. ....             ",
"             .........   .   ..      . ..........-*++===%===+++*... ......  ... .. .... . .....           ",
"                                                      ............                                        ",
"                                                      ............                                        ",
"                                                                                                          ",
"                                                                                                          ",
"                                                                                                          ",
"                                                                                                          ",
"                                                                                                          ",
"                                                                                                          ",
"                                                                                                          ",
"                                                                                                          " };

// void    draw_background()
// {
//     for (int i = 0; i < 54; i++) {
// 		for (int j = 0; j < 100; j++)
// 		{
// 			move(i,j);
// 			/* code */
// 			if (img[i][j] == '.')
// 			    attron (COLOR_PAIR(1));
// 			else
// 			    attron (COLOR_PAIR(2));
// 			addch(img[i][j]);
// 			// addch('%');
// 		}
// 	}
// }
#endif
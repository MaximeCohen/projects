/*
** my.h for  in /home/agor_m/tests/autocomplete
**
** Made by Maxime Agor
** Login   <agor_m@epitech.net>
**
** Started on  Sat May 23 13:28:29 2015 Maxime Agor
** Last update Sun May 24 12:52:09 2015 Maxime Agor
*/

#ifndef AUTOCOMPLETE_H_
# define AUTOCOMPLETE_H_

char	*autocomp_getname(char *line);
char	*autocomp_getpath(char *line);
char	*wordtab_getlast(char **wordtab);
int	contain_path(char *line);
char	*autocomplete_line(char *line, char *autocomp, char *);
char	*autocomplete_onefolder(char *folder, char *file);
char	*autocomplete_command(char *command, char **path);
char	*autocomplete_file(char *line);
void	free_wordtab(char **wordtab);
char	*autocomplete(t_system *sys, char *line, char *buffer);

#endif /* !AUTOCOMPLETE_H_ */

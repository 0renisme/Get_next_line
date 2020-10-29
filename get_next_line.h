/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 13:13:17 by oren              #+#    #+#             */
/*   Updated: 2020/06/24 18:02:29 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
char	*ft_strndup(char *s, int n);
char	*reset_text(int i, char *extra_char);
int		is_end(char *extra_char);
void	ft_free(char *s);
size_t	ft_strlen(char *s);
int		get_next_line(int fd, char **line);
char	*fill_dest(char *dest, char *s1, char *s2);

#endif

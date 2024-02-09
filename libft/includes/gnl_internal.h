/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:20:59 by misargsy          #+#    #+#             */
/*   Updated: 2023/12/21 15:29:56 by misargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_INTERNAL_H
# define GNL_INTERNAL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FDMAX
#  define FDMAX 24576
# endif

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

char	*gnl_strjoin(char *s1, const char *s2);
int		gnl_reader_terminator(char **buffer, char **line);
char	*gnl_reader_wrapper(int fd, char **buffer);
int		gnl_reader(int fd, char **buffer, char **line);
void	gnl_formatter(char **buffer, char **line);

#endif

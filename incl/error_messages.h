/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <mkocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:52:32 by mkocabas          #+#    #+#             */
/*   Updated: 2023/03/11 20:52:34 by mkocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H

# define ERR_ARGS			"Wrong # of arguments: ./fdf map_file"
# define ERR_MAP			"Bad formatting of the map_file"
# define ERR_LINE_W			"Bad formatting of the map_file: wrong line length"
# define ERR_READING		"Cannot read the map_file"
# define ERR_FD_OPEN		"Could not open the map_file"
# define ERR_FD_CLOSE		"Could not close the map_file"
# define ERR_FD_IS_DIR		"The file is a directory, not a map"
# define ERR_MEM			"Memory allocation failed"
# define ERR_MLX			"MLX initiation failed"
# define ERR_WIN			"Window initiation failed"
# define ERR_IMG			"Error on image initiation"

#endif

#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sleung <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/14 12:08:12 by sleung            #+#    #+#              #
#    Updated: 2017/03/15 15:05:28 by sleung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Memory
SRC_FILES = 	ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memalloc.c \
				ft_memdel.c \
				ft_realloc.c

# String
SRC_FILES +=	ft_strlen.c \
				ft_strdup.c \
				ft_strcpy.c \
				ft_strncpy.c \
				ft_strcat.c \
				ft_strncat.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strstr.c \
				ft_strnstr.c \
				ft_strcmp.c \
				ft_strncmp.c \
				ft_strnew.c \
				ft_strdel.c \
				ft_strclr.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_strsub.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_strsplit.c \
				ft_getstring.c \
				ft_countwords.c \
				ft_strtrimcopy.c \
				ft_strtrimlen.c \
				ft_stricpy.c

# Numbers
SRC_FILES +=	ft_atoi.c \
				ft_itoa.c \
				ft_intlen.c \
				ft_itoa_base.c \
				ft_itoa_unsigned.c

# Is / To
SRC_FILES +=	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_tonarrow.c

# Put
SRC_FILES +=	ft_putchar.c \
				ft_putstr.c \
				ft_putendl.c \
				ft_putnbr.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstrdel.c \
				ft_putstrcount.c

# List
SRC_FILES +=	ft_lstnew.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_lstadd.c \
				ft_lstiter.c \
				ft_lstmap.c

# get_next_line
SRC_FILES +=	get_next_line.c 

# ft_printf
SRC_FILES +=	ft_printf.c \
				ft_printf_cs.c \
				ft_printf_id.c \
				ft_printf_xo.c \
				ft_printf_pp.c \
				ft_printf_u.c \
				ft_printf_wcs.c \
				check_conv.c \
				check_flags.c \
				read_data.c \
				count_spaces.c \
				handle_sign.c \
				handle_flags.c \
				handle_sharp.c \
				handle_modifiers.c \
				handle_wildcard.c \
				handle_null.c \

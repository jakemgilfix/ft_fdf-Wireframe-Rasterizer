# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 00:18:59 by jgilfix           #+#    #+#              #
#    Updated: 2019/12/12 09:43:51 by jgilfix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS =======================================================================

NO_COL    =  \033[38;5;255m
LIME      =  \033[38;5;46m
RED       =  \033[38;5;196m
TEXT      =  \033[38;5;255m

# COMPILER & FLAGS =============================================================

CC        =  gcc

CFLAGS    =  -Wall \
		     -Werror \
		     -Wextra

ALLFLAGS  =   $(CFLAGS)

# VARIABLES ====================================================================

NAME      =  libft.a

BANNER    =  $(LIME)[$(TEXT)libft$(LIME)]\t

INCLUDES  =  ./

MEM_SRC   =  ft_memset.c \
		     ft_bzero.c \
		     ft_memcpy.c \
		     ft_memccpy.c \
		     ft_memmove.c \
		     ft_memchr.c \
		     ft_memcmp.c \
		     ft_memalloc.c \
		     ft_memdel.c

STR_SRC   =  ft_strlen.c \
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
		     ft_strsplit.c

IS_SRC    =  ft_isalpha.c \
		     ft_isdigit.c \
		     ft_isalnum.c \
		     ft_isascii.c \
		     ft_isprint.c \
			 ft_isupper.c \
			 ft_islower.c \
			 ft_iswhitespace.c

TO_SRC    =  ft_tolower.c \
		     ft_toupper.c

PUT_SRC   =  ft_putchar.c \
		     ft_putstr.c \
		     ft_putendl.c \
		     ft_putnbr.c \
		     ft_putchar_fd.c \
		     ft_putstr_fd.c \
		     ft_putendl_fd.c \
		     ft_putnbr_fd.c

MISC_SRC  =  ft_atoi.c \
		     ft_itoa.c \
			 ft_abs.c \
			 ft_int_max.c \
			 ft_int_min.c \
			 ft_sizet_min.c

LIST_SRC  =  ft_lstnew.c \
		     ft_lstdelone.c \
		     ft_lstdel.c \
		     ft_lstadd.c \
		     ft_lstiter.c \
		     ft_lstmap.c \
			 ft_lstlen.c

EXTRA_SRC =  ft_split.c \
			 ft_error.c \
		     ft_lstadd_end.c \
			 get_next_line.c

OBJ = $(patsubst %.c,%.o,$(MEM_SRC))
OBJ += $(patsubst %.c,%.o,$(STR_SRC))
OBJ += $(patsubst %.c,%.o,$(IS_SRC))
OBJ += $(patsubst %.c,%.o,$(TO_SRC))
OBJ += $(patsubst %.c,%.o,$(PUT_SRC))
OBJ += $(patsubst %.c,%.o,$(MISC_SRC))
OBJ += $(patsubst %.c,%.o,$(LIST_SRC))
OBJ += $(patsubst %.c,%.o,$(EXTRA_SRC))

# MAIN =========================================================================

all: $(NAME)

$(NAME):
	@echo "$(BANNER)$(TEXT)Making$(LIME)...$(NO_COL)"
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $(MEM_SRC)
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $(STR_SRC)
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $(IS_SRC)
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $(TO_SRC)
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $(PUT_SRC)
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $(MISC_SRC)
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $(LIST_SRC)
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $(EXTRA_SRC)
	@echo "$(BANNER)$(TEXT)Object files made$(LIME)!$(NO_COL)"
	@ar -rcs $(NAME) $(OBJ)
	@echo "$(BANNER)$(TEXT)Library made$(LIME)!$(NO_COL)"

# HOUSE KEEPING ================================================================

DEL       =  /bin/rm -rf

clean:
	@$(DEL) $(OBJ)
	@echo "$(BANNER)$(NO_COL)[$(LIME)√$(NO_COL)]	$(TEXT)Objects Deleted$(NO_COL)"

fclean: clean
	@$(DEL) $(NAME)
	@echo "$(BANNER)$(NO_COL)[$(LIME)√$(NO_COL)]	$(TEXT)Library Deleted$(NO_COL)"

re: fclean all

# CLEANING SHORTCUTS ===========================================================

cl: clean
	@echo && echo "$(RED)~> $(TEXT)Current Directory$(RED):$(NO_COL)" \
		&& ls && echo

f: fclean
	@echo && echo "$(RED)~> $(TEXT)Current Directory$(RED):$(NO_COL)" \
		&& ls && echo

# ==============================================================================

.PHONY: all clean fclean clclean re cl f

# ==============================================================================

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/07 22:25:40 by jgilfix           #+#    #+#              #
#    Updated: 2019/12/11 19:11:42 by jgilfix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


GREEN    =      \033[38;5;46m
RED      =      \033[38;5;196m
TEXT     =      \033[38;5;255m
NO_COL   =      \033[38;5;255m

# COMPILER & FLAGS =============================================================

CC       =      gcc

ALLFLAGS =      $(CFLAGS) $(FWS)

CFLAGS   =      -Wall -Werror -Wextra

FWS      =      -L libmlx -I libmlx -lmlx -framework OpenGL \
				-framework AppKit -g

FILTER	 =		2> /dev/null

# VARIABLES ====================================================================

NAME     =      fdf

BANNER   =      $(RED)[$(TEXT)$(NAME)$(RED)]\t

SRC      =  	main.c init.c input.c input2.c draw.c menu.c gfx_tools.c \
				projection.c hooks.c user_controls.c

INCLUDES =      includes

FT_DIR   =      libft

LIBFT    =      $(FT_DIR)/libft.a

SRC_DIR  =      src

OBJ_DIR  =      obj

_OBJ     =      $(SRC:.c=.o)

OBJ      =      $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))

CHECK	 =		$(NO_COL)[$(GREEN)√$(NO_COL)]	

# MAIN =========================================================================

all: $(NAME)

$(LIBFT):
	@make -C $(FT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	@echo "$(BANNER)$(TEXT)Object files made$(GREEN)!$(NO_COL)"
	@echo "$(BANNER)$(TEXT)Making $(NAME)$(GREEN)...$(NO_COL)"
	@$(CC) $(ALLFLAGS) $(OBJ) -I $(INCLUDES) -o $(NAME) -L $(FT_DIR) -lft $(FILTER)
	@echo && echo "$(RED)~> $(TEXT)Current Directory$(RED):$(NO_COL)" && \
	    ls "./" && echo

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR) 2> /dev/null || true
	@gcc $(CFLAGS) -I $(INCLUDES) -c $< -o $@

# HOUSE KEEPING ================================================================

DEL       =     /bin/rm -rf
JUNK      =     *.dSYM *.DS
CLONES    =     clone_*

clean:
	@make -C $(FT_DIR) clean
	@$(DEL) $(JUNK) $(OBJ_DIR)
	@echo "$(BANNER)$(CHECK)$(TEXT)Junk Cleared$(NO_COL)"
	@echo "$(BANNER)$(CHECK)$(TEXT)$(OBJ_DIR)/ Removed$(NO_COL)"

fclean: clean
	@make -C $(FT_DIR) fclean
	@$(DEL) $(NAME)
	@echo "$(BANNER)$(CHECK)$(TEXT)Binary Cleared$(NO_COL)"

clclean:
	@$(DEL) $(CLONES)
	@echo "$(BANNER)$(CHECK)$(TEXT)Clones Cleared$(NO_COL)"

re: fclean all

# CLEANING SHORTCUTS ===========================================================

cl: clean
	@echo && echo "$(RED)~> $(TEXT)Current Directory$(RED):$(NO_COL)" && \
	    ls "./" && echo

f: fclean
	@echo && echo "$(RED)~> $(TEXT)Current Directory$(RED):$(NO_COL)" && \
	    ls "./" && echo

# ==============================================================================

.PHONY: all clean fclean clclean re cl f

# ==============================================================================

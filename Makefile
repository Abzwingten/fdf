SHELL = /bin/zsh

NAME = fdf
SRCS_DIR = ./srcs
INCLUDES_DIR = ./includes
LIBFT_INC_DIR = ./libft/includes
OBJS_DIR = ./objs

LIB = libft.a
LIB_DIR = ./libft

SRC_FILES =	

SRCS = $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o, $(SRCS))

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLX = libmlx.a
	MLX_DIR = ./minilibx
	LDFLAGS += -lX11 -lXext -lm
endif
ifeq ($(UNAME_S),Darwin)
	UNAME_R := $(shell uname -r | cut -d. -f1)
	VER := $(shell test $(UNAME_R) -ge 17 && echo 'new' || echo 'old')
	ifeq ($(VER),new)
		MLX = libmlx.dylib
		MLX_DIR = ./minilibx_mms_20191025_beta
	endif
	ifeq ($(VER),old)
		MLX = libmlx.a
		MLX_DIR = ./minilibx_macos
		LDFLAGS += -framework OpenGL -framework AppKit
	endif
endif



CFLAGS_ERRORS = -Wall -Wextra -Werror
CFLAGS_OPTIMIZATIONS = -O2 -funroll-loops
CFLAGS_INCLUDES = -I$(INCLUDES_DIR) -I$(LIBFT_INC_DIR) -I$(LIB_DIR) -I$(MLX_DIR)
CFLAGS_DEBUG = -O0 -pg -g


CFLAGS_FINAL =	$(CFLAGS_INTERNAL) \
				$(CFLAGS_ERRORS) $(CFLAGS_OPTIMIZATIONS) \
				$(CFLAGS_DEPENDENCIES) $(CFLAGS_INCLUDES) \
				$(CFLAGS)

LDFLAGS +=	-L$(LIB_DIR) -lft -L$(MLX_DIR) -lmlx

# COLORS
DEFAULT = "\033[0;0m"
RED = "\033[0;31m"
GREEN = "\033[0;32m"
BLUE = "\033[0;34m"
CYAN = "\033[0;36m"

.PHONY: all clean clean_libs clean_self fclean fclean_libs fclean_self debug re

all:
	@echo -c $(CYAN) "Making libft" $(DEFAULT)
	@$(MAKE) -s -C $(LIB_DIR)
	@echo -c $(CYAN) "Making minilibx" $(DEFAULT)
	@$(MAKE) -s -C $(MLX_DIR)
	@cp $(MLX_DIR)/$(MLX) $(MLX)
	@mkdir -p $(OBJS_DIR)
	@echo $(CYAN) "Making fdf" $(DEFAULT)
	@$(MAKE) -s $(NAME)
	@echo $(RED) "FDF DONE" $(DEFAULT)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS_FINAL) -c -o $@ $<

$(NAME): $(OBJS) $(LIB_DIR)/$(LIB) $(MLX_DIR)/$(MLX)
	@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)


clean: clean_libs clean_self

clean_libs:
	@echo $(CYAN) "Cleaning libft" $(DEFAULT)
	@echo -n $(BLUE)
	@$(MAKE) -s -C $(LIB_DIR) clean
	@echo -n $(DEFAULT)

	@echo $(CYAN) "Cleaning minilibx" $(DEFAULT)
	@echo -n $(BLUE)
	@$(MAKE) -s -C $(MLX_DIR) clean
	@echo -n $(DEFAULT)

clean_self:
	@echo $(CYAN) "Cleaning fdf" $(DEFAULT)
	@echo -n $(GREEN)
	@if [ -d "$(OBJS_DIR)" ]; then rm -rfv $(OBJS_DIR); fi
	@echo -n $(DEFAULT)

fclean: fclean_libs fclean_self

fclean_libs: clean_libs
	@echo $(CYAN) "Purging libft" $(DEFAULT)
	@echo -n $(BLUE)
	$(MAKE) -s -C $(LIB_DIR) fclean
	@echo -n $(DEFAULT)

	@echo $(CYAN) "Purging minilibx" $(DEFAULT)
	@echo -n $(BLUE)
	$(MAKE) -s -C $(MLX_DIR) clean
	rm -rfv $(MLX)
	@echo -n $(DEFAULT)

fclean_self: clean_self
	@echo $(CYAN) "Purging fdf" $(DEFAULT)
	@echo -n $(GREEN)
	if [ -f "$(NAME)" ]; then rm -rfv $(NAME); fi
	@echo -n $(DEFAULT)


debug: clean_self
	CFLAGS="$(CFLAGS_DEBUG)" $(MAKE) all

re: fclean all
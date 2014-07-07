ASM_NAME = asm
COR_NAME = corewar

LNAME = ft

ASM_FOLD = asmm
COR_FOLD = vm

DIR = lib$(LNAME)

HDR = $(DIR)/$(DIR).a

CFLAGS = $(CFLAGS1) $(OFLAGS)

all: $(HDR) $(ASM_NAME) $(COR_NAME)

$(NAME): echo "\n"

$(CC): -Wall -Werror -Wextra

$(ASM_NAME):
		@echo "creation de la partie assembleur.."
		make -C $(ASM_FOLD)
		@mv $(ASM_FOLD)/$(ASM_NAME) $(ASM_NAME)
		@echo "\n"

$(COR_NAME):
		@echo "creation de la partie corewar.."
		make -C $(COR_FOLD)
		@mv $(COR_FOLD)/$(COR_NAME) $(COR_NAME)
		@echo "\n"

$(HDR):
		@echo "creation de la library.."
		make -C $(DIR)
		@echo "\n"

clean:
		@echo "suppression des fichiers object..."
		@make -C $(DIR) clean
		make -C $(ASM_FOLD) clean
		make -C $(COR_FOLD) clean
		@echo "\n"

fclean: clean
		@echo "suppression de l'executable..."
		@make -C $(DIR) fclean
		rm -f $(ASM_NAME) $(COR_NAME)
		@echo "\n"

re: fclean all

.PHONY: all clean fclean re

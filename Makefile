NAME=push_swap
all :
	@echo "\033[1;31m     ██╗  ██████╗  ██╗  ██╗ ███████╗ ██████╗ \033[0m"
	@echo "\033[1;31m     ██║ ██╔═══██╗ ██║ ██╔╝ ██╔════╝ ██╔══██╗\033[0m"
	@echo "\033[1;31m     ██║ ██║   ██║ █████╔╝  █████╗   ██████╔╝\033[0m"
	@echo "\033[1;31m██   ██║ ██║   ██║ ██╔═██╗  ██╔══╝   ██╔══██╗\033[0m"
	@echo "\033[1;31m╚█████╔╝ ╚██████╔╝ ██║  ██╗ ███████╗ ██║  ██║\033[0m"
	@echo "\033[1;31m ╚════╝   ╚═════╝  ╚═╝  ╚═╝ ╚══════╝ ╚═╝  ╚═╝\033[0m"
                                         
	@make -C ./Mandatory
	@make -C ./Bonus

mandatory :
	@make -C ./Mandatory

bonus : 
	@make -C ./Bonus

clean :
	@make clean -C ./Mandatory
	@make clean -C ./Bonus

fclean :
	@make fclean -C ./Bonus
	@make fclean -C ./Mandatory

re :
	@make re -C ./Mandatory

.PHONY : all mandatory bonus clean fclean re
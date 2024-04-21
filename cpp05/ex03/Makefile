NAME := intern
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -I .

SRC_DIR := .
OBJ_DIR := ./obj

SRC_FILES := main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp Intern.cpp
OBJ_FILES := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
OBJ_DIRS := $(sort $(dir $(OBJ_FILES)))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIRS) 
	$(CXX) $(CXXFLAGS) $< -c -o $@

$(OBJ_DIRS):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_FILES)
	$(CXX) $^ -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
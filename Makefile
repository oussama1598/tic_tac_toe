APP_NAME = tic_tac_toe
SRC_DIR = ./src
BIN_DIR = ./bin

# main.o:
# 	gcc $(SRC_DIR)/main.c -o main.o -c

compile: clean
	mkdir $(BIN_DIR)
	gcc -o $(BIN_DIR)/$(APP_NAME) $(SRC_DIR)/main.c

clean:
	rm $(BIN_DIR) -R 

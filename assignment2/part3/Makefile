all:	assignment2part3.c
#	gcc -c opensslex.c
#	gcc opensslex.c -lssl -lcrypto
	gcc assignment2part3.c -o assignment2part3 -lcrypto
	./assignment2part3 sha256

clean:
	$(RM) assignment2part3

# INC=/usr/local/ssl/include/
# LIB=/usr/local/ssl/lib/
# TARGET = assignment2part1
#
# all:
# 	gcc -I$(INC) -L$(LIB) -o enc $(TARGET).c -lcrypto –ldl
#
# # the compiler: gcc for C program, define as g++ for C++
# CC = gcc
#
# # compiler flags:
# #  -g    adds debugging information to the executable file
# #  -Wall turns on most, but not all, compiler warnings
# CFLAGS  = -g -Wall
#
# # the build target executable:
# TARGET = assignment2part1
#
# all: $(TARGET)
#
# $(TARGET): $(TARGET).c
# 	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
#
# clean:
# 	$(RM) $(TARGET)

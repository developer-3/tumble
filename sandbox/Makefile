sandbox:
	clang++ -std=c++11 main.cpp ./glad/src/glad.c -o main -Iinclude -L../lib -ltumble -Llib -lSDL2-2.0.0
# This only works if the tumble lib is linked first and if it is in the lib directory above the current directory
# I have no idea why

clean:
	rm -f $(OBJFILES) $(TARGET) *~

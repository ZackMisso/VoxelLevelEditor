CC=clang++
#CC=g++
CFLAGS+= -std=c++11 -Wall #-g -O0 -Wall -pedantic -I./ -I./include

#STRINGFIX = -lXext -lX11
#STRINGFIX = -lXext -lX11 #-L/usr/lib/nvidia-340-updates
GLUT2 = -framework OpenGL -framework GLUT -framework IOKit -framework CoreVideo -lglfw3
LIBS = $(GLUT2)

PROD= VoxelEditor

SRCS= $(shell ls *.cpp)
SRCS+= $(shell ls views/*.cpp)
SRCS+= $(shell ls shaderClasses/*.cpp)

OBJS= $(patsubst %.cpp, %.o, $(SRCS))

all: $(PROD)

$(OBJS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $< -o $@ #$(LIBGL) #$(LIBGLUT) $(LIBGL) $(LIBS)

$(PROD): $(OBJS)
	$(CC) -o $(PROD) $^ $(LIBS)

clean:
	rm -f $(PROD)
	rm -f *.o
	rm -f views/*.o
	rm -f shaderClasses/*.o

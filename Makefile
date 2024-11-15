CXX = g++
CXXFLAGS = -std=c++17 -Wall -g  # флаги компиляции: используем C++17 и выводим все предупреждения
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system  # флаги линковки для SFML

# Исходные файлы
SRCS = main.cpp # Добавьте сюда все свои исходные файлы

# Объектные файлы
OBJS = $(SRCS:.cpp=.o)

# Название исполняемого файла
TARGET = chess_game

# Правило для компиляции всех объектов
all: $(TARGET)

# Линковка исполняемого файла
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Правило для компиляции каждого исходного файла в объектный
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Правило для очистки объекта и исполняемого файла
clean:
	rm -f $(OBJS) $(TARGET)

# Правило для выполнения программы
run: $(TARGET)
	./$(TARGET)

# Правило для установки зависимостей SFML (если нужно, например на Ubuntu)
install:
	sudo apt-get install libsfml-dev

.PHONY: all clean run install
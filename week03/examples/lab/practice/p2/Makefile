# 编译器
CXX = g++

# 编译选项
CXXFLAGS = -c -Wall

# 目标可执行文件和路径
TARGET = build/lab3_practice

# 源文件和头文件路径
SRC_DIR = src
INC_DIR = inc
BUILD_DIR = build

# 自动获取源文件和目标文件
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC))

# 包含头文件路径
INCLUDES = -I$(INC_DIR)

# 默认目标：生成可执行文件
$(TARGET): $(OBJ)
	@mkdir -p $(BUILD_DIR)  # 确保 build 目录存在
	$(CXX) -o $@ $^         # 链接目标文件生成可执行文件

# 编译规则：将 .cpp 文件编译为目标文件并放入 build 目录
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)  # 确保 build 目录存在
	$(CXX) $(CXXFLAGS) $(INCLUDES) $< -o $@  # 编译 .cpp 文件为目标文件

# 清理规则：删除 build 目录中的所有文件
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)  # 删除整个 build 目录及其内容
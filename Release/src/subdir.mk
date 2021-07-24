################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/file_handling.cpp \
../src/info.cpp \
../src/iter.cpp \
../src/node.cpp \
../src/project.cpp \
../src/trie.cpp \
../src/vector.cpp 

OBJS += \
./src/file_handling.o \
./src/info.o \
./src/iter.o \
./src/node.o \
./src/project.o \
./src/trie.o \
./src/vector.o 

CPP_DEPS += \
./src/file_handling.d \
./src/info.d \
./src/iter.d \
./src/node.d \
./src/project.d \
./src/trie.d \
./src/vector.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



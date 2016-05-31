################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Estudiante.cpp \
../src/Preinscripciones.cpp \
../src/conjuntoEstudiantes.cpp \
../src/elZarzal.cpp \
../src/main.cpp \
../src/menu.cpp \
../src/pruebas_Estudiante.cpp \
../src/pruebas_Preinscripciones.cpp \
../src/pruebas_Titulacion.cpp \
../src/pruebas_conjuntoEstudiantes.cpp \
../src/pruebas_elZarzal.cpp \
../src/pruebas_titulaciones.cpp \
../src/titulacion.cpp \
../src/titulaciones.cpp 

OBJS += \
./src/Estudiante.o \
./src/Preinscripciones.o \
./src/conjuntoEstudiantes.o \
./src/elZarzal.o \
./src/main.o \
./src/menu.o \
./src/pruebas_Estudiante.o \
./src/pruebas_Preinscripciones.o \
./src/pruebas_Titulacion.o \
./src/pruebas_conjuntoEstudiantes.o \
./src/pruebas_elZarzal.o \
./src/pruebas_titulaciones.o \
./src/titulacion.o \
./src/titulaciones.o 

CPP_DEPS += \
./src/Estudiante.d \
./src/Preinscripciones.d \
./src/conjuntoEstudiantes.d \
./src/elZarzal.d \
./src/main.d \
./src/menu.d \
./src/pruebas_Estudiante.d \
./src/pruebas_Preinscripciones.d \
./src/pruebas_Titulacion.d \
./src/pruebas_conjuntoEstudiantes.d \
./src/pruebas_elZarzal.d \
./src/pruebas_titulaciones.d \
./src/titulacion.d \
./src/titulaciones.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


